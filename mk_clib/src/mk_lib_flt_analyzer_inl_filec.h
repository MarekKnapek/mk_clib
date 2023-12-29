#include "mk_lang_assert.h"
#include "mk_lang_countof.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"


#include "mk_lib_flt_analyzer_inl_defd.h"


#define mk_lib_flt_analyzer_inl_filec_flt_name mk_lang_concat(mk_lib_flt_analyzer_inl_defd_prefix, _fltbase)
#define mk_sl_flt_name mk_lib_flt_analyzer_inl_filec_flt_name
#define mk_sl_flt_bits mk_lib_flt_analyzer_inl_defd_flt_bits
#define mk_sl_flt_fraction_bits mk_lib_flt_analyzer_inl_defd_flt_frac
#include "mk_sl_flt_inl_filec.h"
#undef mk_sl_flt_name
#undef mk_sl_flt_bits
#undef mk_sl_flt_fraction_bits
#define mk_lib_flt_analyzer_inl_filec_flt_to_string_dec_basic_n mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_lib_flt_analyzer_inl_filec_flt_name), _to_string_dec_basic_n)
#define mk_lib_flt_analyzer_inl_filec_flt_to_string_dec_basic_len_v mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_lib_flt_analyzer_inl_filec_flt_name), _to_string_dec_basic_len_v)


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_flt_analyzer_inl_defd_analyze_mts(mk_lib_flt_analyzer_inl_defd_uint_pct const mts, mk_lang_types_uchar_t const type, mk_lib_flt_analyzer_inl_defd_lent_pt const mts_dcl, mk_lang_static_param(mk_lang_types_pchar_t, mts_dcd, 1 + 1 + mk_lib_flt_analyzer_inl_defd_flt_frac)) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_lang_types_pchar_t const s_symbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lib_flt_analyzer_inl_defd_uint_t base mk_lang_constexpr_init;
	mk_lib_flt_analyzer_inl_defd_uint_t ta mk_lang_constexpr_init;
	mk_lib_flt_analyzer_inl_defd_uint_t tb mk_lang_constexpr_init;

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
		ptr[0] = type == 4 ? s_symbols[1] : s_symbols[0]; ++ptr;
		ptr[0] = '.'; ++ptr;
		if(mk_lib_flt_analyzer_inl_defd_uint_is_zero(mts))
		{
			ptr[0] = s_symbols[0];
			*mts_dcl = 3;
		}
		else
		{
			tsi = 10; mk_lib_flt_analyzer_inl_defd_uint_from_bi_sint(&base, &tsi);
			mk_lib_flt_analyzer_inl_defd_uint_shl3(mts, 1 + mk_lib_flt_analyzer_inl_defd_flt_expb, &ta);
			for(;;)
			{
				mk_lib_flt_analyzer_inl_defd_uint_mul4_wrap_wi(&ta, &base, &ta, &tb);
				mk_lib_flt_analyzer_inl_defd_uint_to_bi_sint(&tb, &tsi);
				mk_lang_assert(tsi >= 0 && tsi <= 9);
				ptr[0] = s_symbols[tsi]; ++ptr;
				if(mk_lib_flt_analyzer_inl_defd_uint_is_zero(&ta))
				{
					*mts_dcl = ((mk_lib_flt_analyzer_inl_defd_lent_t)(((mk_lang_types_sint_t)(ptr - &mts_dcd[0]))));
					break;
				}
			}
		}
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_flt_analyzer_inl_defd_analyze(mk_lib_flt_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lib_flt_analyzer_inl_defd_uint_t tui mk_lang_constexpr_init;
	mk_lang_types_uint_t tuis[mk_lang_div_roundup(sizeof(mk_lib_flt_analyzer_inl_defd_uint_t), sizeof(mk_lang_types_uint_t))] mk_lang_constexpr_init;
	mk_lib_flt_analyzer_inl_defd_expuint_t teuia mk_lang_constexpr_init;
	mk_lib_flt_analyzer_inl_defd_expuint_t teuib mk_lang_constexpr_init;
	mk_lib_flt_analyzer_inl_defd_expuint_t teuic mk_lang_constexpr_init;
	mk_lib_flt_analyzer_inl_defd_expuint_t teuix mk_lang_constexpr_init;
	mk_lang_types_bool_t exp_zero mk_lang_constexpr_init;
	mk_lang_types_bool_t exp_max mk_lang_constexpr_init;
	mk_lang_types_bool_t mts_zero mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	tsi = mk_lib_flt_analyzer_inl_defd_uint_to_str_binf_n(&analyzer->m_bytes, &analyzer->m_bin[0], mk_lang_countof(analyzer->m_bin)); mk_lang_assert(tsi == mk_lib_flt_analyzer_inl_defd_uint_strlenbin_v);
	tsi = mk_lib_flt_analyzer_inl_defd_uint_to_str_hexf_n(&analyzer->m_bytes, &analyzer->m_hex[0], mk_lang_countof(analyzer->m_hex)); mk_lang_assert(tsi == mk_lib_flt_analyzer_inl_defd_uint_strlenhex_v);
	tsi = mk_lib_flt_analyzer_inl_defd_uint_to_str_dec_n(&analyzer->m_bytes, &analyzer->m_uns_str[0], mk_lang_countof(analyzer->m_uns_str)); mk_lang_assert(tsi <= mk_lib_flt_analyzer_inl_defd_uint_strlendec_v); analyzer->m_uns_len = ((mk_lib_flt_analyzer_inl_defd_lent_t)(tsi));
	mk_lib_flt_analyzer_inl_defd_uint_shr3(&analyzer->m_bytes, mk_lib_flt_analyzer_inl_defd_flt_bits - 1, &tui);
	if(!mk_lib_flt_analyzer_inl_defd_uint_has_lsb(&tui))
	{
		tsi = mk_lib_flt_analyzer_inl_defd_uint_to_str_dec_n(&analyzer->m_bytes, &analyzer->m_sig_str[0], mk_lang_countof(analyzer->m_sig_str)); mk_lang_assert(tsi <= mk_lib_flt_analyzer_inl_defd_uint_strlendec_v); analyzer->m_sig_len = ((mk_lib_flt_analyzer_inl_defd_lent_t)(tsi));
		analyzer->m_val_sgn = 0;
	}
	else
	{
		analyzer->m_sig_str[0] = '-';
		mk_lib_flt_analyzer_inl_defd_uint_not2(&analyzer->m_bytes, &tui);
		mk_lib_flt_analyzer_inl_defd_uint_inc1(&tui);
		tsi = mk_lib_flt_analyzer_inl_defd_uint_to_str_dec_n(&tui, &analyzer->m_sig_str[1], mk_lang_countof(analyzer->m_sig_str) - 1); mk_lang_assert(tsi <= mk_lib_flt_analyzer_inl_defd_uint_strlendec_v); analyzer->m_sig_len = ((mk_lib_flt_analyzer_inl_defd_lent_t)(tsi)) + 1;
		analyzer->m_val_sgn = 1;
	}
	mk_lib_flt_analyzer_inl_defd_uint_shl3(&analyzer->m_bytes, 1, &tui);
	mk_lib_flt_analyzer_inl_defd_uint_shr2(&tui, 1 + mk_lib_flt_analyzer_inl_defd_flt_frac);
	mk_lib_flt_analyzer_inl_defd_uint_to_buis_uint_le(&tui, &tuis[0]);
	mk_lib_flt_analyzer_inl_defd_expuint_from_buis_uint_le(&teuia, &tuis[0]);
	tsi = mk_lib_flt_analyzer_inl_defd_expuint_to_str_binf_n(&teuia, &analyzer->m_exp_bin[0], mk_lang_countof(analyzer->m_exp_bin)); mk_lang_assert(tsi == mk_lib_flt_analyzer_inl_defd_expuint_strlenbin_v);
	tsi = mk_lib_flt_analyzer_inl_defd_expuint_to_str_hexf_n(&teuia, &analyzer->m_exp_hex[0], mk_lang_countof(analyzer->m_exp_hex)); mk_lang_assert(tsi == mk_lib_flt_analyzer_inl_defd_expuint_strlenhex_v);
	tsi = mk_lib_flt_analyzer_inl_defd_expuint_to_str_dec_n(&teuia, &analyzer->m_exp_dec[0], mk_lang_countof(analyzer->m_exp_dec)); mk_lang_assert(tsi <= mk_lib_flt_analyzer_inl_defd_expuint_strlendec_v); analyzer->m_exp_len = ((mk_lang_types_uchar_t)(tsi));
	mk_lib_flt_analyzer_inl_defd_expuint_set_mask(&teuib, mk_lib_flt_analyzer_inl_defd_flt_expb);
	mk_lib_flt_analyzer_inl_defd_expuint_dec1(&teuib);
	mk_lib_flt_analyzer_inl_defd_expuint_shr2(&teuib, 1);
	mk_lib_flt_analyzer_inl_defd_expuint_sub3_wrap_cid_cod(&teuia, &teuib, &teuic);
	mk_lib_flt_analyzer_inl_defd_expuint_shr3(&teuic, mk_lib_flt_analyzer_inl_defd_flt_expb - 1, &teuib);
	mk_lib_flt_analyzer_inl_defd_uint_shl3(&analyzer->m_bytes, 1 + mk_lib_flt_analyzer_inl_defd_flt_expb, &tui);
	mk_lib_flt_analyzer_inl_defd_uint_shr2(&tui, 1 + mk_lib_flt_analyzer_inl_defd_flt_expb);
	mk_lib_flt_analyzer_inl_defd_expuint_set_mask(&teuix, mk_lib_flt_analyzer_inl_defd_flt_expb);
	exp_zero = mk_lib_flt_analyzer_inl_defd_expuint_is_zero(&teuia);
	exp_max = mk_lib_flt_analyzer_inl_defd_expuint_eq(&teuia, &teuix);
	mts_zero = mk_lib_flt_analyzer_inl_defd_uint_is_zero(&tui);
	if(exp_zero && mts_zero)
	{
		analyzer->m_type = 0;
		analyzer->m_one = 0;
	}
	else if(exp_zero && !mts_zero)
	{
		analyzer->m_type = 1;
		analyzer->m_one = 0;
	}
	else if(exp_max && mts_zero)
	{
		analyzer->m_type = 2;
		analyzer->m_one = 0;
	}
	else if(exp_max && !mts_zero)
	{
		analyzer->m_type = 3;
		analyzer->m_one = 0;
	}
	else
	{
		analyzer->m_type = 4;
		analyzer->m_one = 1;
	}
	if(analyzer->m_type == 0 || analyzer->m_type == 2 || analyzer->m_type == 3)
	{
		analyzer->m_exp_dcd[0] = 'n';
		analyzer->m_exp_dcd[1] = '/';
		analyzer->m_exp_dcd[2] = 'a';
		analyzer->m_exp_le1 = 3;
	}
	else if(analyzer->m_type == 1)
	{
		mk_lib_flt_analyzer_inl_defd_expuint_shr2(&teuix, 1);
		mk_lib_flt_analyzer_inl_defd_expuint_dec1(&teuix);
		analyzer->m_exp_dcd[0] = '-';
		tsi = mk_lib_flt_analyzer_inl_defd_expuint_to_str_dec_n(&teuix, &analyzer->m_exp_dcd[1], mk_lang_countof(analyzer->m_exp_dcd) - 1);
		analyzer->m_exp_le1 = ((mk_lib_flt_analyzer_inl_defd_lent_t)(tsi)) + 1;
	}
	else
	{
		if(!mk_lib_flt_analyzer_inl_defd_expuint_has_lsb(&teuib))
		{
			tsi = mk_lib_flt_analyzer_inl_defd_expuint_to_str_dec_n(&teuic, &analyzer->m_exp_dcd[0], mk_lang_countof(analyzer->m_exp_dcd)); mk_lang_assert(tsi <= mk_lib_flt_analyzer_inl_defd_expuint_strlendec_v); analyzer->m_exp_le1 = ((mk_lang_types_uchar_t)(tsi));
		}
		else
		{
			analyzer->m_exp_dcd[0] = '-';
			mk_lib_flt_analyzer_inl_defd_expuint_not2(&teuic, &teuib);
			mk_lib_flt_analyzer_inl_defd_expuint_inc1(&teuib);
			tsi = mk_lib_flt_analyzer_inl_defd_expuint_to_str_dec_n(&teuib, &analyzer->m_exp_dcd[1], mk_lang_countof(analyzer->m_exp_dcd) - 1); mk_lang_assert(tsi <= mk_lib_flt_analyzer_inl_defd_expuint_strlendec_v); analyzer->m_exp_le1 = ((mk_lang_types_uchar_t)(tsi)) + 1;
		}
	}
	mk_lib_flt_analyzer_inl_defd_uint_shl3(&analyzer->m_bytes, 1 + mk_lib_flt_analyzer_inl_defd_flt_expb, &tui);
	mk_lib_flt_analyzer_inl_defd_uint_shr2(&tui, 1 + mk_lib_flt_analyzer_inl_defd_flt_expb);
	tsi = mk_lib_flt_analyzer_inl_defd_uint_to_str_binf_n(&tui, &analyzer->m_mts_bin[0], mk_lang_countof(analyzer->m_mts_bin)); mk_lang_assert(tsi == mk_lib_flt_analyzer_inl_defd_uint_strlenbin_v);
	tsi = mk_lib_flt_analyzer_inl_defd_uint_to_str_hexf_n(&tui, &analyzer->m_mts_hex[0], mk_lang_countof(analyzer->m_mts_hex)); mk_lang_assert(tsi == mk_lib_flt_analyzer_inl_defd_uint_strlenhex_v);
	tsi = mk_lib_flt_analyzer_inl_defd_uint_to_str_dec_n(&tui, &analyzer->m_mts_dec[0], mk_lang_countof(analyzer->m_mts_dec)); mk_lang_assert(tsi >= 1 && tsi <= mk_lib_flt_analyzer_inl_defd_uint_strlendec_v); analyzer->m_mts_len = ((mk_lang_types_uchar_t)(tsi));
	mk_lib_flt_analyzer_inl_defd_analyze_mts(&tui, analyzer->m_type, &analyzer->m_mts_dcl, &analyzer->m_mts_dcd[0]);
	tsi = mk_lib_flt_analyzer_inl_filec_flt_to_string_dec_basic_n(&analyzer->m_bytes, &analyzer->m_val_str[0], mk_lang_countof(analyzer->m_val_str)); mk_lang_assert(tsi <= mk_lib_flt_analyzer_inl_filec_flt_to_string_dec_basic_len_v); analyzer->m_val_len = ((mk_lib_flt_analyzer_inl_defd_mtslent_t)(tsi));
}


#undef mk_lib_flt_analyzer_t_name
#undef mk_lib_flt_analyzer_t_flt_bits
#undef mk_lib_flt_analyzer_t_flt_frac
#undef mk_lib_flt_analyzer_t_uint
#undef mk_lib_flt_analyzer_t_lent
#undef mk_lib_flt_analyzer_t_expuint
#undef mk_lib_flt_analyzer_t_mtsuint
#undef mk_lib_flt_analyzer_t_mtslent
