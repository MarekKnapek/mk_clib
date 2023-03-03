#include "mk_clib_app_factorial.h"

#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_sizeof.h"
#define mk_lang_bui_name fct
#define mk_lang_bui_type mk_lang_bi_uint_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uint_t
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_name fct
#define mk_sl_cui_base_type mk_lang_bi_uint_t
#define mk_sl_cui_base_name mk_lang_bui_fct
#define mk_sl_cui_base_bits (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#define mk_sl_cui_count mk_lang_div_roundup(19072, mk_sl_cui_base_bits)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uint
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#include <stdio.h> /* printf */
#include <stdlib.h> /* atoi */


#define nmin 1
#define nmax 2000
#define tostr_(x) #x
#define tostr(x) tostr_(x)


mk_lang_jumbo char const* mk_clib_app_factorial_get_exe_name(char const* const arg) mk_lang_noexcept
{
	char const* r;
	char const* p;

	r = arg;
	for(p = r; *p; ++p)
	{
		if(*p == '/' || *p == '\\')
		{
			r = p + 1;
		}
	}
	return r;
}

mk_lang_jumbo void mk_clib_app_factorial_compute_and_print(int const n) mk_lang_noexcept
{
	mk_sl_cui_fct_t* pa1;
	mk_sl_cui_fct_t a1;
	mk_sl_cui_fct_t* pa2;
	mk_sl_cui_fct_t a2;
	mk_sl_cui_fct_t b;
	int i;
	mk_sl_cui_fct_t* pa3;
	int tn;
	char buff[mk_sl_cui_fct_to_str_dec_len + 1];

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
	tn = mk_sl_cui_fct_to_str_dec_n(pa1, &buff[0], ((int)(sizeof(buff) / sizeof(*buff))) - 1);
	mk_lang_assert(tn != 0);
	buff[tn] = '\0';
	tn = printf("%s\n", &buff[0]);
	mk_lang_assert(tn >= 0);
}


#include "mk_lang_pow.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_max.h"


#define flt_b32_bits 32
#define flt_b32_fraction_bits 23

#define flt_b64_bits 64
#define flt_b64_fraction_bits 52

#define flt_bits flt_b32_bits
#define flt_fraction_bits flt_b32_fraction_bits
#define flt_exponent_bits (flt_bits - 1 - flt_fraction_bits)
#define flt_exponent_bias (mk_lang_pow(2, flt_exponent_bits - 1) - 1)
#define flt_exponent_encoded_min 0
#define flt_exponent_encoded_max (mk_lang_pow(2, flt_exponent_bits) - 1)
#define flt_exponent_decoded_min (flt_exponent_encoded_min + 1 - flt_exponent_bias)
#define flt_exponent_decoded_max (flt_exponent_encoded_max - 1 - flt_exponent_bias)
#define flt_need_bitsa (1 + flt_exponent_decoded_max)
#define flt_need_bitsb (flt_fraction_bits + (-flt_exponent_decoded_min))
#define flt_has_bitsb (mk_lang_div_roundup(flt_need_bitsb, (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)) * (mk_lang_sizeof_bi_uint_t * mk_lang_charbit))

#define mk_lang_bui_name flt
#define mk_lang_bui_type mk_lang_bi_uint_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uint_t
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_name flt
#define mk_sl_cui_base_type mk_lang_bi_uint_t
#define mk_sl_cui_base_name mk_lang_bui_flt
#define mk_sl_cui_base_bits (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#define mk_sl_cui_count mk_lang_div_roundup(flt_bits, mk_sl_cui_base_bits)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uint
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#define mk_sl_cui_name fltba
#define mk_sl_cui_base_type mk_lang_bi_uint_t
#define mk_sl_cui_base_name mk_lang_bui_flt
#define mk_sl_cui_base_bits (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#define mk_sl_cui_count mk_lang_div_roundup(flt_need_bitsa, mk_sl_cui_base_bits)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uint
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#define mk_sl_cui_name fltbb
#define mk_sl_cui_base_type mk_lang_bi_uint_t
#define mk_sl_cui_base_name mk_lang_bui_flt
#define mk_sl_cui_base_bits (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#define mk_sl_cui_count mk_lang_div_roundup(flt_need_bitsb, mk_sl_cui_base_bits)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uint
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"


#include <string.h> /* memcpy */


enum flt_kind
{
	flt_kind_normal,
	flt_kind_zero,
	flt_kind_subnormal,
	flt_kind_infinity,
	flt_kind_nan
};

union flt_bigab_u
{
	mk_sl_cui_fltba_t m_a;
	mk_sl_cui_fltbb_t m_b;
};
typedef union flt_bigab_u flt_bigab_t;


static void dothis(double d)
{
	static char const s_symbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	float f;
	mk_sl_cui_flt_t cui;
	mk_sl_cui_flt_t ta;
	mk_sl_cui_flt_t tb;
	mk_lang_bool_t is_negative;
	int exponent_encoded;
	int exponent_decoded;
	mk_sl_cui_flt_t fraction;
	enum flt_kind kind;
	int ti;
	int tn;
	flt_bigab_t bigab;
	mk_lang_bi_uint_t uints[mk_lang_div_roundup(mk_lang_max(flt_need_bitsa, flt_need_bitsb), mk_lang_sizeof_bi_uint_t * mk_lang_charbit)];
	int i;
	char buff[mk_sl_cui_fltba_to_str_dec_len + 2 + 1];
	char* pbuff;
	mk_lang_bi_uint_t base;
	mk_lang_bi_uint_t rem;
	mk_sl_cui_fltbb_t bigb2;
	mk_sl_cui_fltbb_t* pbb1;
	mk_sl_cui_fltbb_t* pbb2;
	mk_sl_cui_fltbb_t* pbb3;

	f = ((float)(d));
	mk_lang_assert(sizeof(f) == sizeof(cui));
	memcpy(&cui, &f, sizeof(cui));

	mk_sl_cui_flt_shr3(&cui, flt_bits - 1, &ta);
	is_negative = !mk_sl_cui_flt_is_zero(&ta);

	mk_sl_cui_flt_shr3(&cui, flt_fraction_bits, &ta);
	mk_sl_cui_flt_set_mask(&tb, flt_exponent_bits);
	mk_sl_cui_flt_and2(&ta, &tb);
	mk_sl_cui_flt_to_bi_sint(&ta, &exponent_encoded);
	exponent_decoded = exponent_encoded - flt_exponent_bias;
	mk_lang_assert(exponent_encoded >= flt_exponent_encoded_min && exponent_encoded <= flt_exponent_encoded_max);
	mk_lang_assert(exponent_decoded >= flt_exponent_decoded_min && exponent_decoded <= flt_exponent_decoded_max);

	mk_sl_cui_flt_set_mask(&ta, flt_fraction_bits);
	mk_sl_cui_flt_and3(&cui, &ta, &fraction);

	if(exponent_encoded == flt_exponent_encoded_min)
	{
		if(mk_sl_cui_flt_is_zero(&fraction))
		{
			kind = flt_kind_zero;
		}
		else
		{
			kind = flt_kind_subnormal;
		}
	}
	else if(exponent_encoded == flt_exponent_encoded_max)
	{
		if(mk_sl_cui_flt_is_zero(&fraction))
		{
			kind = flt_kind_infinity;
		}
		else
		{
			kind = flt_kind_nan;
		}
	}
	else
	{
		kind = flt_kind_normal;
	}

	if(is_negative)
	{
		buff[0] = '-';
	}
	pbuff = buff + ((int)(is_negative));
	if(kind == flt_kind_normal)
	{
		mk_sl_cui_flt_set_bit(&ta, flt_fraction_bits);
		mk_sl_cui_flt_or2(&fraction, &ta);
	}
	if(kind == flt_kind_normal)
	{
		mk_sl_cui_flt_to_buis_uint_le(&fraction, &uints[0]);
		for(i = mk_lang_div_roundup(flt_bits, mk_lang_sizeof_bi_uint_t * mk_lang_charbit); i != ((int)(sizeof(uints) / sizeof(uints[0]))); ++i)
		{
			uints[i] = 0u;
		}
		mk_sl_cui_fltba_from_buis_uint_le(&bigab.m_a, &uints[0]);
		ti = exponent_decoded - flt_fraction_bits;
		if(ti == 0)
		{
		}
		else if(ti < 0)
		{
			mk_sl_cui_fltba_shr2(&bigab.m_a, -ti);
		}
		else
		{
			mk_sl_cui_fltba_shl2(&bigab.m_a, ti);
		}
		tn = ((int)(sizeof(buff) / sizeof(buff[0]))) - ((int)(pbuff - buff)) - 1;
		ti = mk_sl_cui_fltba_to_str_dec_n(&bigab.m_a, pbuff, tn);
		mk_lang_assert(ti > 0 && ti <= tn);
		pbuff += ti;
		*pbuff = '.';
		++pbuff;
	}
	else if(kind == flt_kind_subnormal)
	{
		*pbuff = '0';
		++pbuff;
		*pbuff = '.';
		++pbuff;
	}
	if(kind == flt_kind_normal || kind == flt_kind_subnormal)
	{
		if(kind == flt_kind_subnormal)
		{
			exponent_decoded = -126;
		}
		if(exponent_decoded >= flt_fraction_bits)
		{
			*pbuff = '0';
			++pbuff;
		}
		else
		{
			mk_sl_cui_fltbb_from_buis_uint_le(&bigab.m_b, &uints[0]);
			ti = flt_has_bitsb - (flt_fraction_bits - exponent_decoded);
			mk_sl_cui_fltbb_shl2(&bigab.m_b, ti);
			base = 10u;
			pbb1 = &bigab.m_b;
			pbb2 = &bigb2;
			do
			{
				mk_sl_cui_fltbb_mul4_wrap_wi_smol(pbb1, &base, pbb2, &rem);
				*pbuff = s_symbols[rem];
				++pbuff;
				pbb3 = pbb1;
				pbb1 = pbb2;
				pbb2 = pbb3;
			}while(!mk_sl_cui_fltbb_is_zero(pbb1));
		}
	}
	*pbuff = '\0';
	printf("%s\n", buff);
}


mk_lang_jumbo int mk_clib_app_factorial(int const argc, char const* const* const argv) mk_lang_noexcept
{
	int tn;
	double n;

	if(argc < 1)
	{
		return 1;
	}
	else if(argc != 2)
	{
		tn = printf("Example usage: %s 5\n", mk_clib_app_factorial_get_exe_name(argv[0]));
		mk_lang_assert(tn >= 0);
		return 0;
	}
	else
	{
		n = atof(argv[1]);
		dothis(n);
		return 0;
	}
}


#undef nmin
#undef nmax
#undef tostr_
#undef tostr
