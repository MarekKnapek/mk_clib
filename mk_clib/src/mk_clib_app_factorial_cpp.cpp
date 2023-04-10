#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1

#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#define mk_lang_bui_name fct
#define mk_lang_bui_type mk_lang_bi_uint_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uint_t
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_name fct
#define mk_sl_cui_base_type mk_lang_bi_uint_t
#define mk_sl_cui_base_name mk_lang_bui_fct
#define mk_sl_cui_base_bits (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#define mk_sl_cui_count mk_lang_div_roundup(525, mk_sl_cui_base_bits)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uint
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#include <stdio.h> /* printf */


#define nmin 1
#define nmax 100


struct mk_clib_app_factorial_cpp_result_s
{
	char m_chars[mk_sl_cui_fct_to_str_dec_len + 1];
	int m_len;
};
typedef struct mk_clib_app_factorial_cpp_result_s mk_clib_app_factorial_cpp_result_t;


mk_lang_nodiscard static mk_lang_constexpr mk_clib_app_factorial_cpp_result_t mk_clib_app_factorial_cpp_compute(int const n) mk_lang_noexcept
{
	mk_sl_cui_fct_t* pa1 mk_lang_constexpr_init;
	mk_sl_cui_fct_t a1 mk_lang_constexpr_init;
	mk_sl_cui_fct_t* pa2 mk_lang_constexpr_init;
	mk_sl_cui_fct_t a2 mk_lang_constexpr_init;
	mk_sl_cui_fct_t b mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	mk_sl_cui_fct_t* pa3 mk_lang_constexpr_init;
	mk_clib_app_factorial_cpp_result_t ret mk_lang_constexpr_init;

	mk_lang_assert(n >= nmin && n <= nmax);

	pa1 = &a1;
	pa2 = &a2;
	mk_sl_cui_fct_set_one(pa1);
	b = *pa1;
	for(i = 1; i != n; ++i)
	{
		mk_sl_cui_fct_inc1(&b);
		mk_sl_cui_fct_mul3_wrap_lo(pa1, &b, pa2);
		pa3 = pa1;
		pa1 = pa2;
		pa2 = pa3;
	}
	ret.m_len = mk_sl_cui_fct_to_str_dec_n(pa1, ret.m_chars, mk_sl_cui_fct_to_str_dec_len);
	mk_lang_assert(ret.m_len != 0);
	ret.m_chars[ret.m_len] = '\0';
	return ret;
}


mk_lang_jumbo int mk_clib_app_factorial_cpp(void) mk_lang_noexcept
{
	static mk_lang_constexpr auto const n = 42;
	static mk_lang_constexpr auto const fct_str = mk_clib_app_factorial_cpp_compute(n);

	int tn;

	tn = printf("%s\n", fct_str.m_chars);
	mk_lang_assert(tn >= 0);

	return 0;
}


#undef nmin
#undef nmax
