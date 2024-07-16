#include "mk_lib_win_impersonate_linked.h"

#include "mk_lang_assert.h"
#include "mk_lang_attribute.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_advapi_token.h"
#include "mk_win_base.h"
#include "mk_win_kernel_handle.h"
#include "mk_win_kernel_process.h"
#include "mk_win_kernel_thread.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_win_impersonate_linked_impl_2(mk_win_advapi_token_t const linked, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(!mk_win_advapi_token_is_null(linked));
	mk_lang_assert(did);

	//b = mk_win_advapi_token_set_thread(mk_win_base_null, linked); mk_lang_check_return(b != 0);
	b = mk_win_advapi_token_impersonate(linked); mk_lang_check_return(b != 0);
	*did = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_win_impersonate_linked_open_linked(mk_win_advapi_token_t const curr, mk_win_advapi_token_pt const linked) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_advapi_token_t lnk;
	mk_win_base_dword_t written;

	mk_lang_assert(!mk_win_advapi_token_is_null(curr));
	mk_lang_assert(linked);

	b = mk_win_advapi_token_get_info(curr, ((mk_win_base_dword_t)(mk_win_advapi_token_info_e_linkedtoken)), &lnk, ((mk_win_base_dword_t)(sizeof(lnk))), &written);
	if(b != 0 && written == ((mk_win_base_word_t)(sizeof(lnk))) && !mk_win_advapi_token_is_null(lnk))
	{
		*linked = lnk;
	}
	else
	{
		*linked = mk_win_advapi_token_get_null();
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_win_impersonate_linked_impl_1(mk_win_advapi_token_t const token, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_advapi_token_t linked;
	mk_lang_types_sint_t err_b;
	mk_win_base_bool_t b;

	mk_lang_assert(!mk_win_advapi_token_is_null(token));
	mk_lang_assert(did);

	err = mk_lib_win_impersonate_linked_open_linked(token, &linked); mk_lang_check_rereturn(err);
	if(!mk_win_advapi_token_is_null(linked))
	{
		err_b = mk_lib_win_impersonate_linked_impl_2(linked, did);
		b = mk_win_kernel_handle_close_handle(mk_win_base_handle_from(linked.m_data)); mk_lang_check_return(b != 0);
		mk_lang_check_rereturn(err_b);
	}
	else
	{
		*did = mk_lang_false;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_win_impersonate_linked_open_current(mk_win_advapi_token_pt const token, mk_lang_types_bool_pt const is_thread) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(token);
	mk_lang_assert(is_thread);

	b = mk_win_advapi_token_open_thread(mk_win_kernel_thread_get_current(), ((mk_win_base_dword_t)(mk_win_advapi_token_access_rights_e_query)), mk_lang_true, token);
	if(b == 0)
	{
		b = mk_win_advapi_token_open_process(mk_win_kernel_process_get_current(), ((mk_win_base_dword_t)(mk_win_advapi_token_access_rights_e_query)), token); mk_lang_check_return(b != 0);
		*is_thread = mk_lang_false;
	}
	else
	{
		*is_thread = mk_lang_true;
	}
	mk_lang_assert(!mk_win_advapi_token_is_null(*token));
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_win_impersonate_linked_begin(mk_lib_win_impersonate_linked_pt const impersonate_linked) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_win_advapi_token_pt tok_curr;
	mk_lang_types_bool_pt curr_is_thread;
	mk_lang_types_bool_pt did;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t err_b;
	mk_win_base_bool_t b;

	mk_lang_assert(impersonate_linked);

	tok_curr = &impersonate_linked->m_token;
	curr_is_thread = &impersonate_linked->m_is_thread;
	did = &impersonate_linked->m_did;
	err = mk_lib_win_impersonate_linked_open_current(tok_curr, curr_is_thread); mk_lang_check_rereturn(err); mk_lang_assert(!mk_win_advapi_token_is_null(*tok_curr));
	err_b = mk_lib_win_impersonate_linked_impl_1(*tok_curr, did);
	if(err_b != 0)
	{
		b = mk_win_kernel_handle_close_handle(mk_win_base_handle_from(tok_curr->m_data)); mk_lang_check_return(b != 0);
		mk_lang_check_rereturn(err_b);
	}
	return 0;
}}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_win_impersonate_linked_end(mk_lib_win_impersonate_linked_pct const impersonate_linked) mk_lang_noexcept { mk_lang_attribute_msvc_flatten
{
	mk_win_advapi_token_t token;
	mk_win_base_bool_t b;

	mk_lang_assert(impersonate_linked);
	mk_lang_assert(!mk_win_advapi_token_is_null(impersonate_linked->m_token));

	if(impersonate_linked->m_did)
	{
		if(impersonate_linked->m_is_thread)
		{
			token = impersonate_linked->m_token;
		}
		else
		{
			token = mk_win_advapi_token_get_null();
		}
		//b = mk_win_advapi_token_set_thread(mk_win_base_null, token); mk_lang_check_return(b != 0);
		b = mk_win_advapi_token_revert_to_sef(); mk_lang_check_return(b != 0);
	}
	b = mk_win_kernel_handle_close_handle(mk_win_base_handle_from(impersonate_linked->m_token.m_data)); mk_lang_check_return(b != 0);
	return 0;
}}
