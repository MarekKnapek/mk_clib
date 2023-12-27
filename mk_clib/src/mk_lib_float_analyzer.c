#include "mk_lib_float_analyzer.h"

#include "mk_lang_assert.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"

#define mk_sl_flt_name flt
#define mk_sl_flt_bits 32
#define mk_sl_flt_fraction_bits 23
#include "mk_sl_flt_inl_filec.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_analyze_mts(mk_sl_cui_uint32_pct const mts, mk_lang_types_uchar_t const type, mk_lang_types_uchar_pt const mts_dcl, mk_lang_static_param(mk_lang_types_pchar_t, mts_dcd, 1 + 1 + 23)) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_lang_types_pchar_t const s_symbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint32_t base mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

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
		if(mk_sl_cui_uint32_is_zero(mts))
		{
			ptr[0] = '0';
			*mts_dcl = 3;
		}
		else
		{
			tsi = 10; mk_sl_cui_uint32_from_bi_sint(&base, &tsi);
			mk_sl_cui_uint32_shl3(mts, 1 + 8, &ta);
			for(;;)
			{
				mk_sl_cui_uint32_mul4_wrap_wi(&ta, &base, &ta, &tb);
				mk_sl_cui_uint32_to_bi_sint(&tb, &tsi);
				mk_lang_assert(tsi >= 0 && tsi <= 9);
				ptr[0] = s_symbols[tsi]; ++ptr;
				if(mk_sl_cui_uint32_is_zero(&ta))
				{
					*mts_dcl = ((mk_lang_types_sint_t)(ptr - &mts_dcd[0]));
					break;
				}
			}
		}
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_float_analyzer_analyze(mk_lib_float_analyzer_pt const float_analyzer) mk_lang_noexcept
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32a mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8a mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8b mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8c mk_lang_constexpr_init;
	mk_lang_types_bool_t exp_zero mk_lang_constexpr_init;
	mk_lang_types_bool_t exp_max mk_lang_constexpr_init;
	mk_lang_types_bool_t mts_zero mk_lang_constexpr_init;

	mk_lang_assert(float_analyzer);

	tsi = mk_sl_cui_uint32_to_str_binf_n(&float_analyzer->m_bytes, &float_analyzer->m_bin[0], mk_lang_countof(float_analyzer->m_bin)); mk_lang_assert(tsi == mk_sl_cui_uint32_strlenbin_v);
	tsi = mk_sl_cui_uint32_to_str_hexf_n(&float_analyzer->m_bytes, &float_analyzer->m_hex[0], mk_lang_countof(float_analyzer->m_hex)); mk_lang_assert(tsi == mk_sl_cui_uint32_strlenhex_v);
	tsi = mk_sl_cui_uint32_to_str_dec_n(&float_analyzer->m_bytes, &float_analyzer->m_uns_str[0], mk_lang_countof(float_analyzer->m_uns_str)); mk_lang_assert(tsi <= mk_sl_cui_uint32_strlendec_v); float_analyzer->m_uns_len = ((mk_lang_types_uchar_t)(tsi));
	mk_sl_cui_uint32_shr3(&float_analyzer->m_bytes, 32 - 1, &tu32a);
	if(!mk_sl_cui_uint32_has_lsb(&tu32a))
	{
		tsi = mk_sl_cui_uint32_to_str_dec_n(&float_analyzer->m_bytes, &float_analyzer->m_sig_str[0], mk_lang_countof(float_analyzer->m_sig_str)); mk_lang_assert(tsi <= mk_sl_cui_uint32_strlendec_v); float_analyzer->m_sig_len = ((mk_lang_types_uchar_t)(tsi));
		float_analyzer->m_val_sgn = 0;
	}
	else
	{
		float_analyzer->m_sig_str[0] = '-';
		mk_sl_cui_uint32_not2(&float_analyzer->m_bytes, &tu32a);
		mk_sl_cui_uint32_inc1(&tu32a);
		tsi = mk_sl_cui_uint32_to_str_dec_n(&tu32a, &float_analyzer->m_sig_str[1], mk_lang_countof(float_analyzer->m_sig_str) - 1); mk_lang_assert(tsi <= mk_sl_cui_uint32_strlendec_v); float_analyzer->m_sig_len = ((mk_lang_types_uchar_t)(tsi)) + 1;
		float_analyzer->m_val_sgn = 1;
	}
	mk_sl_cui_uint32_shl3(&float_analyzer->m_bytes, 1, &tu32a);
	mk_sl_cui_uint32_shr2(&tu32a, 1 + 23);
	mk_sl_cui_uint32_to_bi_uchar(&tu32a, &tuc);
	mk_sl_cui_uint8_from_bi_uchar(&tu8a, &tuc);
	tsi = mk_sl_cui_uint8_to_str_binf_n(&tu8a, &float_analyzer->m_exp_bin[0], mk_lang_countof(float_analyzer->m_exp_bin)); mk_lang_assert(tsi == mk_sl_cui_uint8_strlenbin_v);
	tsi = mk_sl_cui_uint8_to_str_hexf_n(&tu8a, &float_analyzer->m_exp_hex[0], mk_lang_countof(float_analyzer->m_exp_hex)); mk_lang_assert(tsi == mk_sl_cui_uint8_strlenhex_v);
	tsi = mk_sl_cui_uint8_to_str_dec_n(&tu8a, &float_analyzer->m_exp_dec[0], mk_lang_countof(float_analyzer->m_exp_dec)); mk_lang_assert(tsi <= mk_sl_cui_uint8_strlendec_v); float_analyzer->m_exp_len = ((mk_lang_types_uchar_t)(tsi));
	mk_sl_cui_uint8_set_max(&tu8b);
	mk_sl_cui_uint8_dec1(&tu8b);
	mk_sl_cui_uint8_shr2(&tu8b, 1);
	mk_sl_cui_uint8_sub3_wrap_cid_cod(&tu8a, &tu8b, &tu8c);
	mk_sl_cui_uint8_shr3(&tu8c, 8 - 1, &tu8b);
	mk_sl_cui_uint32_shl3(&float_analyzer->m_bytes, 1 + 8, &tu32a);
	mk_sl_cui_uint32_shr2(&tu32a, 1 + 8);
	exp_zero = mk_sl_cui_uint8_is_zero(&tu8a);
	exp_max = mk_sl_cui_uint8_is_max(&tu8a);
	mts_zero = mk_sl_cui_uint32_is_zero(&tu32a);
	if(exp_zero && mts_zero)
	{
		float_analyzer->m_type = 0;
		float_analyzer->m_one = 0;
	}
	else if(exp_zero && !mts_zero)
	{
		float_analyzer->m_type = 1;
		float_analyzer->m_one = 0;
	}
	else if(exp_max && mts_zero)
	{
		float_analyzer->m_type = 2;
		float_analyzer->m_one = 0;
	}
	else if(exp_max && !mts_zero)
	{
		float_analyzer->m_type = 3;
		float_analyzer->m_one = 0;
	}
	else
	{
		float_analyzer->m_type = 4;
		float_analyzer->m_one = 1;
	}
	if(float_analyzer->m_type == 0 || float_analyzer->m_type == 2 || float_analyzer->m_type == 3)
	{
		float_analyzer->m_exp_dcd[0] = 'n';
		float_analyzer->m_exp_dcd[1] = '/';
		float_analyzer->m_exp_dcd[2] = 'a';
		float_analyzer->m_exp_le1 = 3;
	}
	else if(float_analyzer->m_type == 1)
	{
		float_analyzer->m_exp_dcd[0] = '-';
		float_analyzer->m_exp_dcd[1] = '1';
		float_analyzer->m_exp_dcd[2] = '2';
		float_analyzer->m_exp_dcd[3] = '6';
		float_analyzer->m_exp_le1 = 4;
	}
	else
	{
		if(!mk_sl_cui_uint8_has_lsb(&tu8b))
		{
			tsi = mk_sl_cui_uint8_to_str_dec_n(&tu8c, &float_analyzer->m_exp_dcd[0], mk_lang_countof(float_analyzer->m_exp_dcd)); mk_lang_assert(tsi <= mk_sl_cui_uint8_strlendec_v); float_analyzer->m_exp_le1 = ((mk_lang_types_uchar_t)(tsi));
		}
		else
		{
			float_analyzer->m_exp_dcd[0] = '-';
			mk_sl_cui_uint8_not2(&tu8c, &tu8b);
			mk_sl_cui_uint8_inc1(&tu8b);
			tsi = mk_sl_cui_uint8_to_str_dec_n(&tu8b, &float_analyzer->m_exp_dcd[1], mk_lang_countof(float_analyzer->m_exp_dcd) - 1); mk_lang_assert(tsi <= mk_sl_cui_uint8_strlendec_v); float_analyzer->m_exp_le1 = ((mk_lang_types_uchar_t)(tsi)) + 1;
		}
	}
	mk_sl_cui_uint32_shl3(&float_analyzer->m_bytes, 1 + 8, &tu32a);
	mk_sl_cui_uint32_shr2(&tu32a, 1 + 8);
	tsi = mk_sl_cui_uint32_to_str_binf_n(&tu32a, &float_analyzer->m_mts_bin[0], mk_lang_countof(float_analyzer->m_mts_bin)); mk_lang_assert(tsi == mk_sl_cui_uint32_strlenbin_v);
	tsi = mk_sl_cui_uint32_to_str_hexf_n(&tu32a, &float_analyzer->m_mts_hex[0], mk_lang_countof(float_analyzer->m_mts_hex)); mk_lang_assert(tsi == mk_sl_cui_uint32_strlenhex_v);
	tsi = mk_sl_cui_uint32_to_str_dec_n(&tu32a, &float_analyzer->m_mts_dec[0], mk_lang_countof(float_analyzer->m_mts_dec)); mk_lang_assert(tsi >= 1 && tsi <= mk_sl_cui_uint32_strlendec_v); float_analyzer->m_mts_len = ((mk_lang_types_uchar_t)(tsi));
	mk_lib_float_analyzer_analyze_mts(&tu32a, float_analyzer->m_type, &float_analyzer->m_mts_dcl, &float_analyzer->m_mts_dcd[0]);
	tsi = mk_sl_flt_flt_to_string_dec_basic_n(&float_analyzer->m_bytes, &float_analyzer->m_val_str[0], mk_lang_countof(float_analyzer->m_val_str)); mk_lang_assert(tsi <= mk_sl_flt_flt_to_string_dec_basic_len_v); float_analyzer->m_val_len = ((mk_lang_types_uchar_t)(tsi));
}
