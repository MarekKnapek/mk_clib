#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"


#include "mk_sl_flt_inl_defhd.h"
#include "mk_sl_flt_inl_defcd.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo int mk_sl_flt_defd_bytes_to_string_dec_basic_n(unsigned char const* const x, char* const str, int const str_len) mk_lang_noexcept
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

	mk_lang_constexpr_static char const s_minus = '-';
	mk_lang_constexpr_static char const s_dot = '.';
	mk_lang_constexpr_static char const s_symbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	mk_lang_constexpr_static char const s_nan[] = {'n', 'a', 'n'};
	mk_lang_constexpr_static char const s_inf[] = {'i', 'n', 'f'};

	mk_sl_flt_defd_cui_t cui mk_lang_constexpr_init;
	mk_sl_flt_defd_cui_t ta mk_lang_constexpr_init;
	mk_sl_flt_defd_cui_t tb mk_lang_constexpr_init;
	mk_lang_bool_t is_negative mk_lang_constexpr_init;
	int exponent_encoded mk_lang_constexpr_init;
	int exponent_decoded mk_lang_constexpr_init;
	mk_sl_flt_defd_cui_t fraction mk_lang_constexpr_init;
	flt_kind_t kind mk_lang_constexpr_init;
	int ti mk_lang_constexpr_init;
	int tn mk_lang_constexpr_init;
	flt_bigab_t bigab mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	char* pstr mk_lang_constexpr_init;
	mk_lang_bi_uint_t base mk_lang_constexpr_init;
	mk_lang_bi_uint_t rem mk_lang_constexpr_init;
	mk_sl_flt_defd_cuibb_t bigb2 mk_lang_constexpr_init;
	mk_sl_flt_defd_cuibb_t* pbb1 mk_lang_constexpr_init;
	mk_sl_flt_defd_cuibb_t* pbb2 mk_lang_constexpr_init;
	mk_sl_flt_defd_cuibb_t* pbb3 mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str);
	mk_lang_assert(str_len > 0);

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
	if(exponent_encoded == mk_sl_flt_defd_exponent_encoded_min)
	{
		if(mk_sl_flt_defd_cui_is_zero(&fraction))
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
		if(mk_sl_flt_defd_cui_is_zero(&fraction))
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
	pstr = str + ((int)(is_negative));
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
			if(((int)(pstr - str)) == str_len) mk_lang_unlikely return 0; *pstr = s_symbols[0]; ++pstr;
			if(((int)(pstr - str)) == str_len) mk_lang_unlikely return 0; *pstr = s_dot; ++pstr;
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
			if(((int)(pstr - str)) == str_len) mk_lang_unlikely return 0;
			tn = str_len - ((int)(pstr - str));
			ti = mk_sl_flt_defd_cuiba_to_str_dec_n(&bigab.m_a, pstr, tn);
			if(ti == 0) mk_lang_unlikely return 0;
			mk_lang_assert(ti > 0 && ti <= tn);
			pstr += ti;
			if(((int)(pstr - str)) == str_len) mk_lang_unlikely return 0; *pstr = s_dot; ++pstr;
		}
	}
	else if(kind == flt_kind_e_subnormal)
	{
		if(((int)(pstr - str)) == str_len) mk_lang_unlikely return 0; *pstr = s_symbols[0]; ++pstr;
		if(((int)(pstr - str)) == str_len) mk_lang_unlikely return 0; *pstr = s_dot; ++pstr;
	}
	if(kind == flt_kind_e_normal || kind == flt_kind_e_subnormal)
	{
		if(kind == flt_kind_e_subnormal)
		{
			exponent_decoded = mk_sl_flt_defd_exponent_decoded_min;
		}
		if(exponent_decoded >= mk_sl_flt_defd_fraction_bits)
		{
			if(((int)(pstr - str)) == str_len) mk_lang_unlikely return 0; *pstr = s_symbols[0]; ++pstr;
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
				if(((int)(pstr - str)) == str_len) mk_lang_unlikely return 0; *pstr = s_symbols[rem]; ++pstr;
				pbb3 = pbb1;
				pbb1 = pbb2;
				pbb2 = pbb3;
			}while(!mk_sl_flt_defd_cuibb_is_zero(pbb1));
		}
	}
	else if(kind == flt_kind_e_zero)
	{
		if(((int)(pstr - str)) == str_len) mk_lang_unlikely return 0; *pstr = s_symbols[0]; ++pstr;
		if(((int)(pstr - str)) == str_len) mk_lang_unlikely return 0; *pstr = s_dot; ++pstr;
		if(((int)(pstr - str)) == str_len) mk_lang_unlikely return 0; *pstr = s_symbols[0]; ++pstr;
	}
	else if(kind == flt_kind_e_infinity)
	{
		tn = ((int)(sizeof(s_inf) / sizeof(s_inf[0])));
		for(i = 0; i != tn; ++i)
		{
			if(((int)(pstr - str)) == str_len) mk_lang_unlikely return 0; *pstr = s_inf[i]; ++pstr;
		}
	}
	else
	{
		mk_lang_assert(kind == flt_kind_e_nan);
		tn = ((int)(sizeof(s_nan) / sizeof(s_nan[0])));
		for(i = 0; i != tn; ++i)
		{
			if(((int)(pstr - str)) == str_len) mk_lang_unlikely return 0; *pstr = s_nan[i]; ++pstr;
		}
	}
	return ((int)(pstr - str));
}

mk_lang_nodiscard mk_lang_jumbo int mk_sl_flt_defd_to_string_dec_basic_n(void const* const x, char* const str, int const str_len) mk_lang_noexcept
{
	return mk_sl_flt_defd_bytes_to_string_dec_basic_n(((unsigned char const*)(x)), str, str_len);
}

mk_lang_nodiscard mk_lang_jumbo int mk_sl_flt_defd_from_string_dec_n(void* const x, char const* const str, int const str_len) mk_lang_noexcept
{
	mk_lang_constexpr_static char const s_minus = '-';
	mk_lang_constexpr_static char const s_plus = '+';
	mk_lang_constexpr_static char const s_symbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	char const* ptr;
	int rem;
	char e;
	mk_lang_bool_t is_negative;
	int i;
	mk_sl_flt_defd_cuiba_t biga;
	mk_sl_flt_defd_bui_t smola;
	mk_sl_flt_defd_cuiba_t biga2;
	mk_sl_flt_defd_bui_t smolb;
	mk_lang_bool_t cf;
	int clz;
	int tn;
	mk_sl_flt_defd_cui_t num;
	unsigned int ui;
	int exponent_decoded;
	int exponent_encoded;
	mk_sl_flt_defd_cui_t ta;

	mk_lang_assert(x);
	mk_lang_assert(str);
	mk_lang_assert(str_len > 0);

	ptr = str;
	rem = str_len;
	e = *ptr;
	if(e == s_minus)
	{
		++ptr;
		--rem;
		if(rem == 0)
		{
			return 0;
		}
		is_negative = mk_lang_true;
	}
	else if(e == s_plus)
	{
		++ptr;
		--rem;
		if(rem == 0)
		{
			return 0;
		}
		is_negative = mk_lang_false;
	}
	else
	{
		is_negative = mk_lang_false;
	}
	e = *ptr;
	++ptr;
	--rem;
	for(i = 0; i != ((int)(sizeof(s_symbols) / sizeof(s_symbols[0]))); ++i)
	{
		if(e == s_symbols[i])
		{
			break;
		}
	}
	if(i == ((int)(sizeof(s_symbols) / sizeof(s_symbols[0]))))
	{
		return 0;
	}
	mk_sl_flt_defd_cuiba_from_bi_sint(&biga, &i);
	while(rem != 0)
	{
		e = *ptr;
		++ptr;
		--rem;
		for(i = 0; i != ((int)(sizeof(s_symbols) / sizeof(s_symbols[0]))); ++i)
		{
			if(e == s_symbols[i])
			{
				break;
			}
		}
		if(i == ((int)(sizeof(s_symbols) / sizeof(s_symbols[0]))))
		{
			break;
		}
		smola = ((mk_sl_flt_defd_bui_t)(10));
		mk_sl_flt_defd_cuiba_mul4_wrap_wi_smol(&biga, &smola, &biga2, &smolb);
		if(smolb != 0)
		{
			break;
		}
		smolb = ((mk_sl_flt_defd_bui_t)(i));
		mk_sl_flt_defd_cuiba_add3_wrap_cid_coe_smol(&biga2, &smolb, &biga, &cf);
		if(cf)
		{
			biga = biga2;
			break;
		}
	};
	if(mk_sl_flt_defd_cuiba_is_zero(&biga))
	{
		mk_sl_flt_defd_cui_set_zero(&num);
	}
	else
	{
		clz = mk_sl_flt_defd_cuiba_count_leading_zeros(&biga);
		tn = mk_sl_flt_defd_has_bits_a - mk_sl_flt_defd_fraction_bits - 1 - clz;
		if(tn > 0)
		{
			mk_sl_flt_defd_cuiba_shr2(&biga, tn - 1);
			mk_sl_flt_defd_convert_to_num(&biga, &num);
			mk_sl_flt_defd_cui_to_bi_uint(&num, &ui);
			if((ui & 0x1u) == 0x1u)
			{
				mk_sl_flt_defd_cui_inc1(&num);
			}
			mk_sl_flt_defd_cui_shr2(&num, 1);
		}
		else if(tn < 0)
		{
			mk_sl_flt_defd_cuiba_shl2(&biga, -tn);
			mk_sl_flt_defd_convert_to_num(&biga, &num);
		}
		else
		{
			mk_sl_flt_defd_convert_to_num(&biga, &num);
		}
		mk_sl_flt_defd_cui_set_mask(&ta, mk_sl_flt_defd_fraction_bits);
		mk_sl_flt_defd_cui_and2(&num, &ta);
		exponent_decoded = mk_sl_flt_defd_fraction_bits + tn;
		exponent_encoded = exponent_decoded + mk_sl_flt_defd_exponent_bias;
		mk_lang_assert(exponent_decoded >= mk_sl_flt_defd_exponent_decoded_min && exponent_decoded <= mk_sl_flt_defd_exponent_decoded_max);
		mk_lang_assert(exponent_encoded >= mk_sl_flt_defd_exponent_encoded_min && exponent_encoded <= mk_sl_flt_defd_exponent_encoded_max);
		mk_sl_flt_defd_cui_from_bi_sint(&ta, &exponent_encoded);
		mk_sl_flt_defd_cui_shl2(&ta, mk_sl_flt_defd_fraction_bits);
		mk_sl_flt_defd_cui_or2(&num, &ta);
	}
	if(is_negative)
	{
		mk_sl_flt_defd_cui_set_bit(&ta, mk_sl_flt_defd_bits - 1);
		mk_sl_flt_defd_cui_or2(&num, &ta);
	}
	mk_sl_flt_defd_cui_to_buis_uchar_le(&num, ((unsigned char*)(x)));
	mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
	return str_len - rem;
}


#include "mk_sl_flt_inl_defcu.h"
#include "mk_sl_flt_inl_defhu.h"


#undef mk_sl_flt_name
#undef mk_sl_flt_bits
#undef mk_sl_flt_fraction_bits
