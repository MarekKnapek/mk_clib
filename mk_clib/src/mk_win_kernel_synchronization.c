#include "mk_win_kernel_synchronization.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_advapi_types.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"
#include "mk_win_unicode_api.h"


mk_lang_extern_c mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateEventA(mk_win_advapi_base_security_attributes_lpct, mk_win_base_bool_t, mk_win_base_bool_t, mk_win_base_pchar_lpct) mk_lang_noexcept;

mk_lang_extern_c mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateEventW(mk_win_advapi_base_security_attributes_lpct, mk_win_base_bool_t, mk_win_base_bool_t, mk_win_base_wchar_lpct) mk_lang_noexcept;

mk_lang_extern_c mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall WaitForSingleObject(mk_win_base_handle_t, mk_win_base_dword_t) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall WaitForMultipleObjects(mk_win_base_dword_t, mk_win_base_handle_lpct, mk_win_base_bool_t, mk_win_base_dword_t) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetOverlappedResult(mk_win_base_handle_t, mk_win_kernel_files_overlapped_lpct, mk_win_base_dword_lpt, mk_win_base_bool_t) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ResetEvent(mk_win_base_handle_t) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetEvent(mk_win_base_handle_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_synchronization_a_create_event(mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_bool_t const initial_state, mk_win_base_pchar_lpct const name) mk_lang_noexcept
{
	mk_win_base_handle_t event;

	event = CreateEventA(security_attributes, manual_reset, initial_state, name);
	return event;
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_synchronization_w_create_event(mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_bool_t const initial_state, mk_win_base_wchar_lpct const name) mk_lang_noexcept
{
	mk_win_base_handle_t event;

	event = CreateEventW(security_attributes, manual_reset, initial_state, name);
	return event;
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_synchronization_t_create_event(mk_win_advapi_base_security_attributes_lpct const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_bool_t const initial_state, mk_win_tstring_tchar_lpct const name) mk_lang_noexcept
{
#if mk_win_unicode_api == mk_win_unicode_api_oold
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc == mk_win_tstring_enc_ansi
	return mk_win_kernel_synchronization_a_create_event(security_attributes, manual_reset, initial_state, name);
#elif mk_win_unicode_api == mk_win_unicode_api_ansi && mk_win_tstring_enc != mk_win_tstring_enc_ansi
	return mk_win_kernel_synchronization_a_create_event(security_attributes, manual_reset, initial_state, mk_win_tstring_tstr_to_ansi_zt_nofail(name).m_str);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc == mk_win_tstring_enc_wide
	return mk_win_kernel_synchronization_w_create_event(security_attributes, manual_reset, initial_state, name);
#elif mk_win_unicode_api == mk_win_unicode_api_wide && mk_win_tstring_enc != mk_win_tstring_enc_wide
	return mk_win_kernel_synchronization_w_create_event(security_attributes, manual_reset, initial_state, mk_win_tstring_tstr_to_wide_zt_nofail(name).m_str);
#elif mk_win_unicode_api == mk_win_unicode_api_both
	if(!mk_win_unicode_api_is_wide())
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_ansi
			return mk_win_kernel_synchronization_a_create_event(security_attributes, manual_reset, initial_state, name);
		#else
			return mk_win_kernel_synchronization_a_create_event(security_attributes, manual_reset, initial_state, mk_win_tstring_tstr_to_ansi_zt_nofail(name).m_str);
		#endif
	}
	else
	{
		#if mk_win_tstring_enc == mk_win_tstring_enc_wide
			return mk_win_kernel_synchronization_w_create_event(security_attributes, manual_reset, initial_state, mk_win_tstring_tstr_to_wide_zt_nofail(name).m_str);
		#else
			return mk_win_kernel_synchronization_w_create_event(security_attributes, manual_reset, initial_state, mk_win_tstring_tstr_to_wide_zt_nofail(name).m_str);
		#endif
	}
#endif
}


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_synchronization_wait_for_single_object(mk_win_base_handle_t const handle, mk_win_base_dword_t const timeout_ms) mk_lang_noexcept
{
	mk_win_base_dword_t waited;

	waited = WaitForSingleObject(handle, timeout_ms);
	return waited;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_synchronization_wait_for_multiple_objects(mk_win_base_dword_t const count, mk_win_base_handle_lpct const handles, mk_win_base_bool_t const wait_all, mk_win_base_dword_t timeout_ms) mk_lang_noexcept
{
	mk_win_base_dword_t waited;

	waited = WaitForMultipleObjects(count, handles, wait_all, timeout_ms);
	return waited;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_synchronization_get_overlapped_result(mk_win_base_handle_t const file, mk_win_kernel_files_overlapped_lpct const overlapped, mk_win_base_dword_lpt const bytes_transfered, mk_win_base_bool_t const wait) mk_lang_noexcept
{
	mk_win_base_bool_t got;

	got = GetOverlappedResult(file, overlapped, bytes_transfered, wait);
	return got;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_synchronization_reset_event(mk_win_base_handle_t const event) mk_lang_noexcept
{
	mk_win_base_bool_t reseted;

	reseted = ResetEvent(event);
	return reseted;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_synchronization_set_event(mk_win_base_handle_t const event) mk_lang_noexcept
{
	mk_win_base_bool_t set;

	set = SetEvent(event);
	return set;
}
