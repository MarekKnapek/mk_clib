#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_encoding.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


#include "mk_sl_flt_inl_defhd.h"
#include "mk_sl_flt_inl_defcd.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_flt_defd_convert_to_biga(mk_sl_flt_defd_cui_pct const a, mk_sl_flt_defd_cuiba_pt const b) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_flt_defd_bui_t buff[mk_sl_flt_defd_cuiba_count] mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_lang_countof(buff);
	for(i = 0; i != n; ++i)
	{
		buff[i] = 0;
	}
	mk_sl_flt_defd_cui_to_buis_uint_le(a, &buff[0]);
	mk_sl_flt_defd_cuiba_from_buis_uint_le(b, &buff[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_flt_defd_convert_to_bigb(mk_sl_flt_defd_cui_pct const a, mk_sl_flt_defd_cuibb_pt const b) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_flt_defd_bui_t buff[mk_sl_flt_defd_cuibb_count] mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_lang_countof(buff);
	for(i = 0; i != n; ++i)
	{
		buff[i] = 0;
	}
	mk_sl_flt_defd_cui_to_buis_uint_le(a, &buff[0]);
	mk_sl_flt_defd_cuibb_from_buis_uint_le(b, &buff[0]);
}


#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_flt_defd_symbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
#endif

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_flt_defd_uchars_to_string_dec_basic_n(mk_lang_types_uchar_pct const x, mk_lang_types_pchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	enum flt_kind_e
	{
		flt_kind_e_normal,
		flt_kind_e_zero,
		flt_kind_e_subnormal,
		flt_kind_e_infinity,
		flt_kind_e_nan
	};
	typedef enum flt_kind_e flt_kind_t;

	union flt_bigab_u
	{
		mk_sl_flt_defd_cuiba_t m_a;
		mk_sl_flt_defd_cuibb_t m_b;
	};
	typedef union flt_bigab_u flt_bigab_t;

	mk_lang_constexpr_static mk_lang_types_pchar_t const s_minus = '-';
	mk_lang_constexpr_static mk_lang_types_pchar_t const s_dot = '.';
	mk_lang_constexpr_static mk_lang_types_pchar_t const s_nan[] = {'n', 'a', 'n'};
	mk_lang_constexpr_static mk_lang_types_pchar_t const s_inf[] = {'i', 'n', 'f'};

	mk_sl_flt_defd_cui_t cui mk_lang_constexpr_init;
	mk_sl_flt_defd_cui_t ta mk_lang_constexpr_init;
	mk_sl_flt_defd_cui_t tb mk_lang_constexpr_init;
	mk_lang_types_bool_t is_negative mk_lang_constexpr_init;
	mk_lang_types_sint_t exponent_encoded mk_lang_constexpr_init;
	mk_lang_types_sint_t exponent_decoded mk_lang_constexpr_init;
	mk_sl_flt_defd_cui_t fraction mk_lang_constexpr_init;
	mk_lang_types_bool_t is_fraction_zero mk_lang_constexpr_init;
	flt_kind_t kind mk_lang_constexpr_init;
	mk_lang_types_sint_t ti mk_lang_constexpr_init;
	mk_lang_types_sint_t tn mk_lang_constexpr_init;
	flt_bigab_t bigab mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_pchar_pt pstr mk_lang_constexpr_init;
	mk_lang_bi_uint_t base mk_lang_constexpr_init;
	mk_lang_bi_uint_t rem mk_lang_constexpr_init;
	mk_sl_flt_defd_cuibb_t bigb2 mk_lang_constexpr_init;
	mk_sl_flt_defd_cuibb_t* pbb1 mk_lang_constexpr_init;
	mk_sl_flt_defd_cuibb_t* pbb2 mk_lang_constexpr_init;
	mk_sl_flt_defd_cuibb_t* pbb3 mk_lang_constexpr_init;
	mk_lang_types_sint_t r mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(str_len == 0){ mk_lang_unlikely return 0; }
	mk_sl_flt_defd_cui_from_buis_uchar_le(&cui, x);
	mk_sl_flt_defd_cui_shr3(&cui, mk_sl_flt_defd_bits - 1, &ta);
	is_negative = !mk_sl_flt_defd_cui_is_zero(&ta);
	mk_sl_flt_defd_cui_shr3(&cui, mk_sl_flt_defd_fraction_bits, &ta);
	mk_sl_flt_defd_cui_set_mask(&tb, mk_sl_flt_defd_exponent_bits);
	mk_sl_flt_defd_cui_and2(&ta, &tb);
	mk_sl_flt_defd_cui_to_bi_sint(&ta, &exponent_encoded);
	mk_lang_assert(exponent_encoded >= mk_sl_flt_defd_exponent_encoded_min && exponent_encoded <= mk_sl_flt_defd_exponent_encoded_max);
	mk_sl_flt_defd_cui_set_mask(&ta, mk_sl_flt_defd_fraction_bits);
	mk_sl_flt_defd_cui_and3(&cui, &ta, &fraction);
	is_fraction_zero = mk_sl_flt_defd_cui_is_zero(&fraction);
	if(exponent_encoded == mk_sl_flt_defd_exponent_encoded_min)
	{
		if(is_fraction_zero)
		{
			kind = flt_kind_e_zero;
		}
		else
		{
			kind = flt_kind_e_subnormal;
		}
	}
	else if(exponent_encoded == mk_sl_flt_defd_exponent_encoded_max)
	{
		if(is_fraction_zero)
		{
			kind = flt_kind_e_infinity;
		}
		else
		{
			kind = flt_kind_e_nan;
		}
	}
	else
	{
		kind = flt_kind_e_normal;
	}
	if(is_negative)
	{
		str[0] = s_minus;
	}
	pstr = str + (is_negative ? 1 : 0);
	if(kind == flt_kind_e_normal)
	{
		mk_sl_flt_defd_cui_set_bit(&ta, mk_sl_flt_defd_fraction_bits);
		mk_sl_flt_defd_cui_or2(&fraction, &ta);
	}
	if(kind == flt_kind_e_normal)
	{
		exponent_decoded = exponent_encoded - mk_sl_flt_defd_exponent_bias;
		mk_lang_assert(exponent_decoded >= mk_sl_flt_defd_exponent_decoded_min && exponent_decoded <= mk_sl_flt_defd_exponent_decoded_max);
		if(exponent_decoded <= -1)
		{
			#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
			if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = ((mk_lang_types_pchar_t)('0' + 0)); ++pstr;
			#else
			if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = mk_sl_flt_defd_symbols[0]; ++pstr;
			#endif
			if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = s_dot; ++pstr;
		}
		else
		{
			mk_sl_flt_defd_convert_to_biga(&fraction, &bigab.m_a);
			ti = exponent_decoded - mk_sl_flt_defd_fraction_bits;
			if(ti == 0)
			{
			}
			else if(ti < 0)
			{
				mk_sl_flt_defd_cuiba_shr2(&bigab.m_a, -ti);
			}
			else
			{
				mk_sl_flt_defd_cuiba_shl2(&bigab.m_a, ti);
			}
			if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; }
			tn = str_len - ((mk_lang_types_sint_t)(pstr - str));
			ti = mk_sl_flt_defd_cuiba_to_str_dec_n(&bigab.m_a, pstr, tn);
			if(ti == 0){ mk_lang_unlikely return 0; }
			mk_lang_assert(ti >= 1 && ti <= tn);
			pstr += ti;
			if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = s_dot; ++pstr;
		}
	}
	else if(kind == flt_kind_e_subnormal)
	{
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = ((mk_lang_types_pchar_t)('0' + 0)); ++pstr;
		#else
		if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = mk_sl_flt_defd_symbols[0]; ++pstr;
		#endif
		if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = s_dot; ++pstr;
	}
	if(kind == flt_kind_e_normal || kind == flt_kind_e_subnormal)
	{
		if(kind == flt_kind_e_subnormal)
		{
			exponent_decoded = mk_sl_flt_defd_exponent_decoded_min;
		}
		if(exponent_decoded >= mk_sl_flt_defd_fraction_bits)
		{
			#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
			if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = ((mk_lang_types_pchar_t)('0' + 0)); ++pstr;
			#else
			if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = mk_sl_flt_defd_symbols[0]; ++pstr;
			#endif
		}
		else
		{
			mk_sl_flt_defd_convert_to_bigb(&fraction, &bigab.m_b);
			ti = mk_sl_flt_defd_has_bits_b - (mk_sl_flt_defd_fraction_bits - exponent_decoded);
			mk_sl_flt_defd_cuibb_shl2(&bigab.m_b, ti);
			base = 10u;
			pbb1 = &bigab.m_b;
			pbb2 = &bigb2;
			do
			{
				mk_sl_flt_defd_cuibb_mul4_wrap_wi_smol(pbb1, &base, pbb2, &rem);
				mk_lang_assert(rem >= 0 && rem <= 9);
				#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
				if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = ((mk_lang_types_pchar_t)('0' + rem)); ++pstr;
				#else
				if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = mk_sl_flt_defd_symbols[rem]; ++pstr;
				#endif
				pbb3 = pbb1;
				pbb1 = pbb2;
				pbb2 = pbb3;
			}while(!mk_sl_flt_defd_cuibb_is_zero(pbb1));
		}
	}
	else if(kind == flt_kind_e_zero)
	{
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = ((mk_lang_types_pchar_t)('0' + 0)); ++pstr;
		#else
		if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = mk_sl_flt_defd_symbols[0]; ++pstr;
		#endif
		if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = s_dot; ++pstr;
		#if mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic
		if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = ((mk_lang_types_pchar_t)('0' + 0)); ++pstr;
		#else
		if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = mk_sl_flt_defd_symbols[0]; ++pstr;
		#endif
	}
	else if(kind == flt_kind_e_infinity)
	{
		tn = mk_lang_countof(s_inf);
		for(i = 0; i != tn; ++i)
		{
			if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = s_inf[i]; ++pstr;
		}
	}
	else
	{
		mk_lang_assert(kind == flt_kind_e_nan);
		tn = mk_lang_countof(s_nan);
		for(i = 0; i != tn; ++i)
		{
			if(((mk_lang_types_sint_t)(pstr - str)) == str_len){ mk_lang_unlikely return 0; } pstr[0] = s_nan[i]; ++pstr;
		}
	}
	r = ((mk_lang_types_sint_t)(pstr - str));
	return r;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_flt_defd_uint8s_to_string_dec_basic_n(mk_sl_cui_uint8_pct const x, mk_lang_types_pchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_uchar_t uchars[mk_sl_flt_bits / mk_lang_charbit] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t r mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_flt_bits % mk_lang_charbit == 0);
	mk_lang_static_assert(sizeof(mk_lang_types_uchar_t) == sizeof(mk_sl_cui_uint8_t));

	mk_lang_assert(x);

	n = mk_lang_countof(uchars);
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_uchar(&x[i], &uchars[i]);
	}
	r = mk_sl_flt_defd_uchars_to_string_dec_basic_n(&uchars[0], str, str_len);
	return r;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_flt_defd_to_string_dec_basic_n(mk_lang_types_void_pct const x, mk_lang_types_pchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_sl_flt_defd_uchars_to_string_dec_basic_n(((mk_lang_types_uchar_pct)(x)), str, str_len);
}


#include "mk_sl_flt_inl_defcu.h"
#include "mk_sl_flt_inl_defhu.h"


#undef mk_sl_flt_name
#undef mk_sl_flt_bits
#undef mk_sl_flt_fraction_bits
