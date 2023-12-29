#include "mk_lib_double_analyzer.h"

#include "mk_lang_assert.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint64.h"

#define mk_sl_flt_name dbl
#define mk_sl_flt_bits 64
#define mk_sl_flt_fraction_bits 52
#include "mk_sl_flt_inl_filec.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_double_analyzer_analyze_mts(mk_sl_cui_uint64_pct const mts, mk_lang_types_uchar_t const type, mk_lang_types_uchar_pt const mts_dcl, mk_lang_static_param(mk_lang_types_pchar_t, mts_dcd, 1 + 1 + 52)) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_lang_types_pchar_t const s_symbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint64_t base mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;

	mk_lang_assert(mts);
	mk_lang_assert(mts_dcl);
	mk_lang_assert(mts_dcd);

	ptr = &mts_dcd[0];
	if(type == 0 || type == 2 || type == 3)
	{
		ptr[0] = 'n'; ++ptr;
		ptr[0] = '/'; ++ptr;
		ptr[0] = 'a'; ++ptr;
		*mts_dcl = 3;
	}
	else
	{
		ptr[0] = type == 4 ? '1' : '0'; ++ptr;
		ptr[0] = '.'; ++ptr;
		if(mk_sl_cui_uint64_is_zero(mts))
		{
			ptr[0] = '0';
			*mts_dcl = 3;
		}
		else
		{
			tsi = 10; mk_sl_cui_uint64_from_bi_sint(&base, &tsi);
			mk_sl_cui_uint64_shl3(mts, 1 + 11, &ta);
			for(;;)
			{
				mk_sl_cui_uint64_mul4_wrap_wi(&ta, &base, &ta, &tb);
				mk_sl_cui_uint64_to_bi_sint(&tb, &tsi);
				mk_lang_assert(tsi >= 0 && tsi <= 9);
				ptr[0] = s_symbols[tsi]; ++ptr;
				if(mk_sl_cui_uint64_is_zero(&ta))
				{
					*mts_dcl = ((mk_lang_types_sint_t)(ptr - &mts_dcd[0]));
					break;
				}
			}
		}
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_double_analyzer_analyze(mk_lib_double_analyzer_pt const double_analyzer) mk_lang_noexcept
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64a mk_lang_constexpr_init;
	mk_lang_types_ushort_t tus mk_lang_constexpr_init;
	mk_sl_cui_uint16_t tu16a mk_lang_constexpr_init;
	mk_sl_cui_uint16_t tu16b mk_lang_constexpr_init;
	mk_sl_cui_uint16_t tu16c mk_lang_constexpr_init;
	mk_sl_cui_uint16_t tu16x mk_lang_constexpr_init;
	mk_lang_types_bool_t exp_zero mk_lang_constexpr_init;
	mk_lang_types_bool_t exp_max mk_lang_constexpr_init;
	mk_lang_types_bool_t mts_zero mk_lang_constexpr_init;

	mk_lang_assert(double_analyzer);

	tsi = mk_sl_cui_uint64_to_str_binf_n(&double_analyzer->m_bytes, &double_analyzer->m_bin[0], mk_lang_countof(double_analyzer->m_bin)); mk_lang_assert(tsi == mk_sl_cui_uint64_strlenbin_v);
	tsi = mk_sl_cui_uint64_to_str_hexf_n(&double_analyzer->m_bytes, &double_analyzer->m_hex[0], mk_lang_countof(double_analyzer->m_hex)); mk_lang_assert(tsi == mk_sl_cui_uint64_strlenhex_v);
	tsi = mk_sl_cui_uint64_to_str_dec_n(&double_analyzer->m_bytes, &double_analyzer->m_uns_str[0], mk_lang_countof(double_analyzer->m_uns_str)); mk_lang_assert(tsi <= mk_sl_cui_uint64_strlendec_v); double_analyzer->m_uns_len = ((mk_lang_types_uchar_t)(tsi));
	mk_sl_cui_uint64_shr3(&double_analyzer->m_bytes, 64 - 1, &tu64a);
	if(!mk_sl_cui_uint64_has_lsb(&tu64a))
	{
		tsi = mk_sl_cui_uint64_to_str_dec_n(&double_analyzer->m_bytes, &double_analyzer->m_sig_str[0], mk_lang_countof(double_analyzer->m_sig_str)); mk_lang_assert(tsi <= mk_sl_cui_uint64_strlendec_v); double_analyzer->m_sig_len = ((mk_lang_types_uchar_t)(tsi));
		double_analyzer->m_val_sgn = 0;
	}
	else
	{
		double_analyzer->m_sig_str[0] = '-';
		mk_sl_cui_uint64_not2(&double_analyzer->m_bytes, &tu64a);
		mk_sl_cui_uint64_inc1(&tu64a);
		tsi = mk_sl_cui_uint64_to_str_dec_n(&tu64a, &double_analyzer->m_sig_str[1], mk_lang_countof(double_analyzer->m_sig_str) - 1); mk_lang_assert(tsi <= mk_sl_cui_uint64_strlendec_v); double_analyzer->m_sig_len = ((mk_lang_types_uchar_t)(tsi)) + 1;
		double_analyzer->m_val_sgn = 1;
	}
	mk_sl_cui_uint64_shl3(&double_analyzer->m_bytes, 1, &tu64a);
	mk_sl_cui_uint64_shr2(&tu64a, 1 + 52);
	mk_sl_cui_uint64_to_bi_ushort(&tu64a, &tus);
	mk_sl_cui_uint16_from_bi_ushort(&tu16a, &tus);
	tsi = mk_sl_cui_uint16_to_str_binf_n(&tu16a, &double_analyzer->m_exp_bin[0], mk_lang_countof(double_analyzer->m_exp_bin)); mk_lang_assert(tsi == mk_sl_cui_uint16_strlenbin_v);
	tsi = mk_sl_cui_uint16_to_str_hexf_n(&tu16a, &double_analyzer->m_exp_hex[0], mk_lang_countof(double_analyzer->m_exp_hex)); mk_lang_assert(tsi == mk_sl_cui_uint16_strlenhex_v);
	tsi = mk_sl_cui_uint16_to_str_dec_n(&tu16a, &double_analyzer->m_exp_dec[0], mk_lang_countof(double_analyzer->m_exp_dec)); mk_lang_assert(tsi <= mk_sl_cui_uint16_strlendec_v); double_analyzer->m_exp_len = ((mk_lang_types_uchar_t)(tsi));
	mk_sl_cui_uint16_set_mask(&tu16b, 11);
	mk_sl_cui_uint16_dec1(&tu16b);
	mk_sl_cui_uint16_shr2(&tu16b, 1);
	mk_sl_cui_uint16_sub3_wrap_cid_cod(&tu16a, &tu16b, &tu16c);
	mk_sl_cui_uint16_shr3(&tu16c, 11 - 1, &tu16b);
	mk_sl_cui_uint64_shl3(&double_analyzer->m_bytes, 1 + 11, &tu64a);
	mk_sl_cui_uint64_shr2(&tu64a, 1 + 11);
	mk_sl_cui_uint16_set_mask(&tu16x, 11);
	exp_zero = mk_sl_cui_uint16_is_zero(&tu16a);
	exp_max = mk_sl_cui_uint16_eq(&tu16a, &tu16x);
	mts_zero = mk_sl_cui_uint64_is_zero(&tu64a);
	if(exp_zero && mts_zero)
	{
		double_analyzer->m_type = 0;
		double_analyzer->m_one = 0;
	}
	else if(exp_zero && !mts_zero)
	{
		double_analyzer->m_type = 1;
		double_analyzer->m_one = 0;
	}
	else if(exp_max && mts_zero)
	{
		double_analyzer->m_type = 2;
		double_analyzer->m_one = 0;
	}
	else if(exp_max && !mts_zero)
	{
		double_analyzer->m_type = 3;
		double_analyzer->m_one = 0;
	}
	else
	{
		double_analyzer->m_type = 4;
		double_analyzer->m_one = 1;
	}
	if(double_analyzer->m_type == 0 || double_analyzer->m_type == 2 || double_analyzer->m_type == 3)
	{
		double_analyzer->m_exp_dcd[0] = 'n';
		double_analyzer->m_exp_dcd[1] = '/';
		double_analyzer->m_exp_dcd[2] = 'a';
		double_analyzer->m_exp_le1 = 3;
	}
	else if(double_analyzer->m_type == 1)
	{
		double_analyzer->m_exp_dcd[0] = '-';
		double_analyzer->m_exp_dcd[1] = '1';
		double_analyzer->m_exp_dcd[2] = '0';
		double_analyzer->m_exp_dcd[3] = '2';
		double_analyzer->m_exp_dcd[4] = '2';
		double_analyzer->m_exp_le1 = 5;
	}
	else
	{
		if(!mk_sl_cui_uint16_has_lsb(&tu16b))
		{
			tsi = mk_sl_cui_uint16_to_str_dec_n(&tu16c, &double_analyzer->m_exp_dcd[0], mk_lang_countof(double_analyzer->m_exp_dcd)); mk_lang_assert(tsi <= mk_sl_cui_uint16_strlendec_v); double_analyzer->m_exp_le1 = ((mk_lang_types_uchar_t)(tsi));
		}
		else
		{
			double_analyzer->m_exp_dcd[0] = '-';
			mk_sl_cui_uint16_not2(&tu16c, &tu16b);
			mk_sl_cui_uint16_inc1(&tu16b);
			tsi = mk_sl_cui_uint16_to_str_dec_n(&tu16b, &double_analyzer->m_exp_dcd[1], mk_lang_countof(double_analyzer->m_exp_dcd) - 1); mk_lang_assert(tsi <= mk_sl_cui_uint16_strlendec_v); double_analyzer->m_exp_le1 = ((mk_lang_types_uchar_t)(tsi)) + 1;
		}
	}
	mk_sl_cui_uint64_shl3(&double_analyzer->m_bytes, 1 + 11, &tu64a);
	mk_sl_cui_uint64_shr2(&tu64a, 1 + 11);
	tsi = mk_sl_cui_uint64_to_str_binf_n(&tu64a, &double_analyzer->m_mts_bin[0], mk_lang_countof(double_analyzer->m_mts_bin)); mk_lang_assert(tsi == mk_sl_cui_uint64_strlenbin_v);
	tsi = mk_sl_cui_uint64_to_str_hexf_n(&tu64a, &double_analyzer->m_mts_hex[0], mk_lang_countof(double_analyzer->m_mts_hex)); mk_lang_assert(tsi == mk_sl_cui_uint64_strlenhex_v);
	tsi = mk_sl_cui_uint64_to_str_dec_n(&tu64a, &double_analyzer->m_mts_dec[0], mk_lang_countof(double_analyzer->m_mts_dec)); mk_lang_assert(tsi >= 1 && tsi <= mk_sl_cui_uint64_strlendec_v); double_analyzer->m_mts_len = ((mk_lang_types_uchar_t)(tsi));
	mk_lib_double_analyzer_analyze_mts(&tu64a, double_analyzer->m_type, &double_analyzer->m_mts_dcl, &double_analyzer->m_mts_dcd[0]);
	tsi = mk_sl_flt_dbl_to_string_dec_basic_n(&double_analyzer->m_bytes, &double_analyzer->m_val_str[0], mk_lang_countof(double_analyzer->m_val_str)); mk_lang_assert(tsi <= mk_sl_flt_dbl_to_string_dec_basic_len_v); double_analyzer->m_val_len_lo = ((mk_lang_types_uchar_t)(tsi >> 0)); double_analyzer->m_val_len_hi = ((mk_lang_types_uchar_t)(tsi >> 8));
}
