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


#define flt_b32_len 32
#define flt_b32_exponent_len 8
#define flt_b32_fraction_len 23
#define flt_b32_exponent_bias 127

#define flt_b64_len 64
#define flt_b64_exponent_len 11
#define flt_b64_fraction_len 52
#define flt_b64_exponent_bias 1023

#define flt_len flt_b32_len
#define flt_exponent_len flt_b32_exponent_len
#define flt_fraction_len flt_b32_fraction_len
#define flt_exponent_bias flt_b32_exponent_bias
#define flt_need_bitsa (1 + flt_exponent_bias + 1)
#define flt_need_bitsb (flt_fraction_len + flt_exponent_bias)

#define mk_lang_bui_name flt
#define mk_lang_bui_type mk_lang_bi_uint_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uint_t
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_name flt
#define mk_sl_cui_base_type mk_lang_bi_uint_t
#define mk_sl_cui_base_name mk_lang_bui_flt
#define mk_sl_cui_base_bits (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#define mk_sl_cui_count mk_lang_div_roundup(32, mk_sl_cui_base_bits)
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


#include "mk_lang_max.h"

#include <string.h> /* memcpy */


static void dothis(double d)
{
	enum flt_kind
	{
		flt_kind_normal,
		flt_kind_zero,
		flt_kind_subnormal,
		flt_kind_infinity,
		flt_kind_nan
	};

	float f;
	mk_sl_cui_flt_t cui;
	mk_sl_cui_flt_t ta;
	mk_sl_cui_flt_t tb;
	mk_lang_bool_t is_negative;
	mk_sl_cui_flt_t exponent;
	mk_sl_cui_flt_t fraction;
	enum flt_kind kind;
	int ti;
	int exponent_encoded;
	int exponent_decoded;
	union u
	{
		mk_sl_cui_fltba_t biga;
		mk_sl_cui_fltbb_t bigb;
	} u;
	unsigned int uints[mk_lang_div_roundup(mk_lang_max(flt_need_bitsa, flt_need_bitsb), sizeof(unsigned int) * mk_lang_charbit)];
	int i;
	char buff[1 + mk_sl_cui_fltba_to_str_dec_len + 1];
	char* pbuff;

	f = ((float)(d));
	mk_lang_assert(sizeof(f) == sizeof(cui));

	memcpy(&cui, &f, sizeof(cui));

	mk_sl_cui_flt_shr3(&cui, flt_len - 1, &ta);
	is_negative = !mk_sl_cui_flt_is_zero(&ta);

	mk_sl_cui_flt_shr3(&cui, flt_fraction_len, &ta);
	mk_sl_cui_flt_set_mask(&tb, flt_exponent_len);
	mk_sl_cui_flt_and2(&ta, &tb);
	mk_sl_cui_flt_to_bi_sint(&ta, &exponent_encoded);
	exponent_decoded = exponent_encoded - flt_exponent_bias;
	mk_lang_assert(exponent_encoded >= 0 && exponent_encoded <= flt_exponent_bias * 2 + 1);
	mk_lang_assert(exponent_decoded >= -flt_exponent_bias && exponent_decoded <= flt_exponent_bias + 1);

	mk_sl_cui_flt_set_mask(&ta, flt_fraction_len);
	mk_sl_cui_flt_and3(&cui, &ta, &fraction);

	if(exponent_encoded == 0)
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
	else
	{
		if(exponent_encoded == flt_exponent_bias * 2 + 1)
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
	}

	mk_sl_cui_flt_set_bit(&ta, flt_fraction_len);
	mk_sl_cui_flt_or2(&ta, &fraction);
	mk_sl_cui_flt_to_buis_uint_le(&ta, &uints[0]);
	for(i = mk_lang_div_roundup(flt_len, sizeof(unsigned) * mk_lang_charbit); i != ((int)(sizeof(uints) / sizeof(uints[0]))); ++i)
	{
		uints[i] = 0u;
	}
	mk_sl_cui_fltba_from_buis_uint_le(&u.biga, &uints[0]);
	ti = exponent_decoded - flt_fraction_len;
	if(ti == 0)
	{
	}
	else if(ti < 0)
	{
		mk_sl_cui_fltba_shr2(&u.biga, -ti);
	}
	else
	{
		mk_sl_cui_fltba_shl2(&u.biga, ti);
	}
	if(is_negative)
	{
		buff[0] = '-';
	}
	pbuff = buff + ((int)(is_negative));
	ti = mk_sl_cui_fltba_to_str_dec_n(&u.biga, pbuff, ((int)(sizeof(buff) / sizeof(buff[0]) - 1 - 1)));
	mk_lang_assert(ti > 0 && ti <= ((int)(sizeof(buff) / sizeof(buff[0]) - 1 - 1)));
	pbuff[ti] = '\0';/**/
	printf("%s\n", buff);/**/
	mk_sl_cui_fltbb_from_buis_uint_le(&u.bigb, &uints[0]);
	ti = flt_need_bitsb - flt_fraction_len + exponent_decoded;
	mk_sl_cui_fltbb_shl2(&u.bigb, ti);
	/* todo repeated mul by ten, write overflow */
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
