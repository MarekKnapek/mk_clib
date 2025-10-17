#ifndef mk_include_guard_mk_sl_string_c
#define mk_include_guard_mk_sl_string_c
#include "mk_sl_string.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_sl_mallocator.h"


#define mk_sl_vector_t_name mk_sl_string
#define mk_sl_vector_t_element_type mk_lang_types_pchar_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocator
#define mk_sl_vector_t_element_eq mk_lang_types_pchar_eq
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_string_rw_add_and_remove_null_terminator(mk_sl_string_pt const string) mk_lang_noexcept
{
	mk_lang_types_pchar_t nul;
	mk_lang_types_sint_t err;

	mk_lang_assert(string);

	nul = '\0';
	err = mk_sl_string_rw_push_back_copy_single(string, &nul); mk_lang_check_rereturn(err);
	err = mk_sl_string_rw_pop_back_single(string); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_string_ro_cmp_null_terminated(mk_sl_string_pct const a, mk_sl_string_pct const b, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lang_types_pchar_pct bufa;
	mk_lang_types_pchar_pct bufb;
	mk_lang_types_usize_t lena;
	mk_lang_types_usize_t lenb;
	mk_lang_types_sint_t r;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(cmp);
	mk_lang_assert(mk_sl_string_ro_data(a));
	mk_lang_assert(mk_sl_string_ro_data(b));
	mk_lang_assert(mk_sl_string_ro_data(a)[mk_sl_string_ro_size(a)] == '\0');
	mk_lang_assert(mk_sl_string_ro_data(b)[mk_sl_string_ro_size(b)] == '\0');

	if(a != b)
	{
		bufa = mk_sl_string_ro_data(a);
		bufb = mk_sl_string_ro_data(b);
		lena = mk_sl_string_ro_size(a);
		lenb = mk_sl_string_ro_size(b);
		r = mk_lang_string_memcmp_pc_fn(bufa, bufb, mk_lang_min(lena, lenb) + 1);
	}
	else
	{
		r = 0;
	}
	*cmp = r;
	return 0;
}


#endif
