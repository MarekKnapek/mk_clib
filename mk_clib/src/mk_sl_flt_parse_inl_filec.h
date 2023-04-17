#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_overlap.h"
#include "mk_lang_range.h"
#include "mk_lang_restrict.h"
#include "mk_lang_static_assert.h"


#include "mk_sl_flt_parse_inl_defcd.h"


#define arr_len(x) ((int)(sizeof(x) / sizeof(x[0])))


mk_lang_constexpr static mk_lang_inline void mk_sl_flt_parse_inl_defcd_generate_zero(mk_lang_bool_t const is_negative, unsigned char* const x) mk_lang_noexcept
{
	mk_sl_flt_parse_inl_defcd_cui_t cui1 mk_lang_constexpr_init;

	mk_lang_assert(x);

	if(!is_negative)
	{
		mk_sl_flt_parse_inl_defcd_cui_set_zero(&cui1);
	}
	else
	{
		mk_sl_flt_parse_inl_defcd_cui_set_bit(&cui1, mk_sl_flt_parse_inl_defcd_bits - 1);
	}
	mk_sl_flt_parse_inl_defcd_cui_to_buis_uchar_le(&cui1, x);
}

mk_lang_constexpr static mk_lang_inline void mk_sl_flt_parse_inl_defcd_generate_inf(mk_lang_bool_t const is_negative, unsigned char* const x) mk_lang_noexcept
{
	mk_sl_flt_parse_inl_defcd_cui_t cui mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_sl_flt_parse_inl_defcd_cui_set_mask(&cui, mk_sl_flt_parse_inl_defcd_exponent_bits + (is_negative ? 1 : 0));
	mk_sl_flt_parse_inl_defcd_cui_shl2(&cui, mk_sl_flt_parse_inl_defcd_fraction_bits);
	mk_sl_flt_parse_inl_defcd_cui_to_buis_uchar_le(&cui, x);
}

mk_lang_constexpr static mk_lang_inline void mk_sl_flt_parse_inl_defcd_generate_nan(unsigned char* const x) mk_lang_noexcept
{
	mk_sl_flt_parse_inl_defcd_cui_t cui mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_sl_flt_parse_inl_defcd_cui_set_max(&cui);
	mk_sl_flt_parse_inl_defcd_cui_to_buis_uchar_le(&cui, x);
}

mk_lang_constexpr static mk_lang_inline void mk_sl_flt_parse_inl_defcd_generate_number(mk_sl_flt_parse_inl_defcd_cui_t* const cui1, mk_lang_bool_t const is_negative, int const exponent_encoded, unsigned char* const x) mk_lang_noexcept
{
	mk_sl_flt_parse_inl_defcd_cui_t cui2 mk_lang_constexpr_init;

	mk_lang_assert(cui1);
	mk_lang_assert(exponent_encoded >= mk_sl_flt_parse_inl_defcd_exponent_encoded_min && exponent_encoded <= mk_sl_flt_parse_inl_defcd_exponent_encoded_max);
	mk_lang_assert(x);

	mk_sl_flt_parse_inl_defcd_cui_set_mask(&cui2, mk_sl_flt_parse_inl_defcd_fraction_bits);
	mk_sl_flt_parse_inl_defcd_cui_and2(cui1, &cui2);
	mk_sl_flt_parse_inl_defcd_cui_from_bi_sint(&cui2, &exponent_encoded);
	mk_sl_flt_parse_inl_defcd_cui_shl2(&cui2, mk_sl_flt_parse_inl_defcd_fraction_bits);
	mk_sl_flt_parse_inl_defcd_cui_or2(cui1, &cui2);
	if(is_negative)
	{
		mk_sl_flt_parse_inl_defcd_cui_set_bit(&cui2, mk_sl_flt_parse_inl_defcd_cui_has_bits - 1);
		mk_sl_flt_parse_inl_defcd_cui_or2(cui1, &cui2);
	}
	mk_sl_flt_parse_inl_defcd_cui_to_buis_uchar_le(cui1, x);
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline int mk_sl_flt_parse_inl_defcd_char_to_digit(char const e) mk_lang_noexcept
{
	mk_lang_constexpr_static char const s_symbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	mk_lang_constexpr_static int const s_symbols_len = arr_len(s_symbols);

	int i mk_lang_constexpr_init;

	for(i = 0; i != s_symbols_len; ++i)
	{
		if(e == s_symbols[i])
		{
			return i;
		}
	}
	return -1;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_bool_t mk_sl_flt_parse_inl_defcd_all_of(char const* const mk_lang_restrict a, char const* const mk_lang_restrict b, int const len) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(len >= 0);
	mk_lang_assert(!mk_lang_overlap_pchar(a, len, b, len));

	for(i = 0; i != len; ++i)
	{
		if(a[i] != b[i])
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_bool_t mk_sl_flt_parse_inl_defcd_get_plus_minus(char const** const str, int* const str_len) mk_lang_noexcept
{
	mk_lang_constexpr_static char const s_plus = '+';
	mk_lang_constexpr_static char const s_minus = '-';

	char const* ptr mk_lang_constexpr_init;
	int rem mk_lang_constexpr_init;
	char e mk_lang_constexpr_init;
	mk_lang_bool_t is_negative mk_lang_constexpr_init;

	mk_lang_assert(str);
	mk_lang_assert(str_len);

	ptr = *str;
	rem = *str_len;
	mk_lang_assert(rem > 0);
	e = *ptr;
	++ptr;
	--rem;
	if(e == s_plus)
	{
		is_negative = mk_lang_false;
	}
	else if(e == s_minus)
	{
		is_negative = mk_lang_true;
	}
	else
	{
		is_negative = mk_lang_false;
		--ptr;
		++rem;
	}
	*str = ptr;
	*str_len = rem;
	return is_negative;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_bool_t mk_sl_flt_parse_inl_defcd_get_inf(char const** const str, int* const str_len, mk_lang_bool_t const is_negative, unsigned char* const x) mk_lang_noexcept
{
	mk_lang_constexpr_static char const s_inf[] = {'i', 'n', 'f'};
	mk_lang_constexpr_static int const s_inf_len = arr_len(s_inf);

	char const* ptr mk_lang_constexpr_init;
	int rem mk_lang_constexpr_init;

	mk_lang_assert(str);
	mk_lang_assert(str_len);
	mk_lang_assert(x);

	ptr = *str;
	rem = *str_len;
	mk_lang_assert(rem > 0);
	if(rem >= s_inf_len && mk_sl_flt_parse_inl_defcd_all_of(ptr, s_inf, s_inf_len))
	{
		ptr += s_inf_len;
		rem -= s_inf_len;
		*str = ptr;
		*str_len = rem;
		mk_sl_flt_parse_inl_defcd_generate_inf(is_negative, x);
		return mk_lang_true;
	}
	return mk_lang_false;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_bool_t mk_sl_flt_parse_inl_defcd_get_nan(char const** const str, int* const str_len, unsigned char* const x) mk_lang_noexcept
{
	mk_lang_constexpr_static char const s_nan[] = {'n', 'a', 'n'};
	mk_lang_constexpr_static int const s_nan_len = arr_len(s_nan);

	char const* ptr mk_lang_constexpr_init;
	int rem mk_lang_constexpr_init;

	mk_lang_assert(str);
	mk_lang_assert(str_len);
	mk_lang_assert(x);

	ptr = *str;
	rem = *str_len;
	mk_lang_assert(rem > 0);
	if(rem >= s_nan_len && mk_sl_flt_parse_inl_defcd_all_of(ptr, s_nan, s_nan_len))
	{
		ptr += s_nan_len;
		rem -= s_nan_len;
		*str = ptr;
		*str_len = rem;
		mk_sl_flt_parse_inl_defcd_generate_nan(x);
		return mk_lang_true;
	}
	return mk_lang_false;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_bool_t mk_sl_flt_parse_inl_defcd_get_leading_zeros(char const** const str, int* const str_len) mk_lang_noexcept
{
	mk_lang_constexpr_static char const s_zero = '0';

	char const* ptr mk_lang_constexpr_init;
	int rem mk_lang_constexpr_init;
	char e mk_lang_constexpr_init;
	mk_lang_bool_t have_something mk_lang_constexpr_init;

	ptr = *str;
	rem = *str_len;
	mk_lang_assert(rem > 0);
	e = *ptr;
	++ptr;
	--rem;
	have_something = e == s_zero;
	while(e == s_zero && rem != 0)
	{
		e = *ptr;
		++ptr;
		--rem;
	}
	ptr -= ((e != s_zero) ? 1 : 0);
	rem += ((e != s_zero) ? 1 : 0);
	*str = ptr;
	*str_len = rem;
	return have_something;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_flt_parse_inl_defcd_result_t mk_sl_flt_parse_inl_defcd_get_big_int(char const** const str, int* const str_len, mk_sl_flt_parse_inl_defcd_big_t* const big) mk_lang_noexcept
{
	char const* ptr mk_lang_constexpr_init;
	int rem mk_lang_constexpr_init;
	char e mk_lang_constexpr_init;
	int si mk_lang_constexpr_init;
	mk_sl_flt_parse_inl_defcd_bui_t bui1 mk_lang_constexpr_init;
	int count mk_lang_constexpr_init;
	unsigned ui mk_lang_constexpr_init;
	mk_sl_flt_parse_inl_defcd_bui_t bui2 mk_lang_constexpr_init;
	mk_sl_flt_parse_inl_defcd_bui_t bui3 mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_flt_parse_inl_defcd_bui_sizebits >= 32);
	mk_lang_assert(str);
	mk_lang_assert(str_len);
	mk_lang_assert(big);

	ptr = *str;
	rem = *str_len;
	mk_lang_assert(rem >= 0);
	if(rem == 0)
	{
		mk_lang_assert(((int)(ptr - *str)) == (*str_len - rem));
		return mk_sl_flt_parse_inl_defcd_result_e_invalid;
	}
	e = *ptr;
	si = mk_sl_flt_parse_inl_defcd_char_to_digit(e);
	if(si == -1)
	{
		mk_lang_assert(((int)(ptr - *str)) == (*str_len - rem));
		return mk_sl_flt_parse_inl_defcd_result_e_invalid;
	}
	++ptr;
	--rem;
	mk_sl_flt_parse_inl_defcd_bui_from_bi_sint(&bui1, &si);
	count = 1;
	mk_sl_flt_parse_inl_defcd_big_set_zero(big);
	for(;;)
	{
		if(rem == 0)
		{
			break;
		}
		e = *ptr;
		si = mk_sl_flt_parse_inl_defcd_char_to_digit(e);
		if(si == -1)
		{
			break;
		}
		mk_lang_assert(((int)(ptr - *str)) == (*str_len - rem));
		if(*str_len - rem - 1 >= mk_sl_flt_parse_inl_defcd_max_nz_digits_pre_dot)
		{
			mk_lang_assert(((int)(ptr - *str)) == (*str_len - rem));
			*str = ptr;
			*str_len = rem;
			return mk_sl_flt_parse_inl_defcd_result_e_out_of_range;
		}
		++ptr;
		--rem;
		mk_lang_assert(((int)(ptr - *str)) == (*str_len - rem));
		ui = 10u;
		mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui2, &ui);
		mk_lang_assert(!mk_sl_flt_parse_inl_defcd_bui_would_overflow_mul(&bui1, &bui2));
		mk_sl_flt_parse_inl_defcd_bui_mul2_wrap_lo(&bui1, &bui2);
		mk_sl_flt_parse_inl_defcd_bui_from_bi_sint(&bui2, &si);
		mk_lang_assert(!mk_sl_flt_parse_inl_defcd_bui_would_overflow_add_cc(&bui1, &bui2));
		mk_sl_flt_parse_inl_defcd_bui_add2_wrap_cid_cod(&bui1, &bui2);
		++count;
		if(count == 9)
		{
			ui = 1000u;
			mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui2, &ui);
			mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui3, &ui);
			mk_lang_assert(!mk_sl_flt_parse_inl_defcd_bui_would_overflow_mul(&bui2, &bui3));
			mk_sl_flt_parse_inl_defcd_bui_mul2_wrap_lo(&bui2, &bui3);
			mk_lang_assert(!mk_sl_flt_parse_inl_defcd_bui_would_overflow_mul(&bui2, &bui3));
			mk_sl_flt_parse_inl_defcd_bui_mul2_wrap_lo(&bui2, &bui3);
			mk_sl_flt_parse_inl_defcd_big_mul2_wrap_lo_smol(big, &bui2); /* todo assert no overflow */
			mk_sl_flt_parse_inl_defcd_big_add2_wrap_cid_cod_smol(big, &bui1); /* todo assert no overflow */
			mk_sl_flt_parse_inl_defcd_bui_set_zero(&bui1);
			count = 0;
		}
	}
	if(count != 0)
	{
		ui = 10u;
		mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui2, &ui);
		mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui3, &ui);
		for(si = 1; si != count; ++si)
		{
			mk_sl_flt_parse_inl_defcd_bui_mul2_wrap_lo(&bui2, &bui3);
		}
		mk_sl_flt_parse_inl_defcd_big_mul2_wrap_lo_smol(big, &bui2); /* todo assert no overflow */
		mk_sl_flt_parse_inl_defcd_big_add2_wrap_cid_cod_smol(big, &bui1); /* todo assert no overflow */
	}
	mk_lang_assert(((int)(ptr - *str)) == (*str_len - rem));
	*str = ptr;
	*str_len = rem;
	return mk_sl_flt_parse_inl_defcd_result_e_ok;
}


mk_lang_constexpr mk_lang_jumbo void mk_sl_flt_parse_inl_defcd_uchars_from_string_dec_n(unsigned char* const x, char const* const str, int const str_len, int* const consummed, mk_sl_flt_parse_inl_defcd_result_t* const result) mk_lang_noexcept
{
	mk_lang_constexpr_static char const s_dot = '.';

	char const* ptr mk_lang_constexpr_init;
	int rem mk_lang_constexpr_init;
	mk_lang_bool_t is_negative mk_lang_constexpr_init;
	mk_lang_bool_t have_something mk_lang_constexpr_init;
	mk_sl_flt_parse_inl_defcd_big_t big1 mk_lang_constexpr_init;
#if 0
	char e mk_lang_constexpr_init;
	int si mk_lang_constexpr_init;
	mk_sl_flt_parse_inl_defcd_bui_t bui1 mk_lang_constexpr_init;
	mk_sl_flt_parse_inl_defcd_cui_t cui2 mk_lang_constexpr_init;
	unsigned ui mk_lang_constexpr_init;
	mk_sl_flt_parse_inl_defcd_bui_t bui2 mk_lang_constexpr_init;
	mk_sl_flt_parse_inl_defcd_bui_t bui3 mk_lang_constexpr_init;
	/*mk_sl_flt_parse_inl_defcd_cui_t cui1 mk_lang_constexpr_init;*/
	int dot_pos mk_lang_constexpr_init;
	int exponent_decoded mk_lang_constexpr_init;
	mk_sl_flt_parse_inl_defcd_big_t big2 mk_lang_constexpr_init;
	mk_lang_bool_t tail_bits mk_lang_constexpr_init;
	mk_lang_bool_t round_bit mk_lang_constexpr_init;
	mk_lang_bool_t even_bit mk_lang_constexpr_init;
	int exponent_encoded mk_lang_constexpr_init;
#endif
	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(consummed);
	mk_lang_assert(result);
	mk_lang_assert(mk_lang_range_is_valid_ptr_int_pchar(str, str_len));

	ptr = str;
	rem = str_len;
	if(rem == 0)
	{
		mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
		*consummed = str_len - rem;
		*result = mk_sl_flt_parse_inl_defcd_result_e_invalid;
		return;
	}
	is_negative = mk_sl_flt_parse_inl_defcd_get_plus_minus(&ptr, &rem);
	if(rem == 0)
	{
		mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
		*consummed = str_len - rem;
		*result = mk_sl_flt_parse_inl_defcd_result_e_invalid;
		return;
	}
	if(mk_sl_flt_parse_inl_defcd_get_inf(&ptr, &rem, is_negative, x))
	{
		mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
		*consummed = str_len - rem;
		*result = mk_sl_flt_parse_inl_defcd_result_e_ok;
		return;
	}
	if(mk_sl_flt_parse_inl_defcd_get_nan(&ptr, &rem, x))
	{
		mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
		*consummed = str_len - rem;
		*result = mk_sl_flt_parse_inl_defcd_result_e_ok;
		return;
	}
	mk_lang_assert(rem > 0);
	have_something = mk_sl_flt_parse_inl_defcd_get_leading_zeros(&ptr, &rem);
	switch(mk_sl_flt_parse_inl_defcd_get_big_int(&ptr, &rem, &big1))
	{
		case mk_sl_flt_parse_inl_defcd_result_e_ok:
		{
			/* intentionally left blank */
		}
		break;
		case mk_sl_flt_parse_inl_defcd_result_e_invalid:
		{
			if(have_something)
			{
				mk_sl_flt_parse_inl_defcd_generate_zero(is_negative, x);
				mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
				*consummed = str_len - rem;
				*result = mk_sl_flt_parse_inl_defcd_result_e_ok;
				return;
			}
			else
			{
				mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
				*consummed = str_len - rem;
				*result = mk_sl_flt_parse_inl_defcd_result_e_invalid;
				return;
			}
		}
		break;
		case mk_sl_flt_parse_inl_defcd_result_e_out_of_range:
		{
			mk_sl_flt_parse_inl_defcd_generate_inf(is_negative, x);
			mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
			*consummed = str_len - rem;
			*result = mk_sl_flt_parse_inl_defcd_result_e_out_of_range;
			return;
		}
		break;
	}
	/* if no dot */
	{
		int si mk_lang_constexpr_init;
		mk_sl_flt_parse_inl_defcd_cui_t cui1 mk_lang_constexpr_init;
		int exponent_decoded mk_lang_constexpr_init;
		mk_sl_flt_parse_inl_defcd_big_t big2 mk_lang_constexpr_init;
		mk_lang_bool_t tail_bits mk_lang_constexpr_init;
		unsigned ui mk_lang_constexpr_init;
		mk_lang_bool_t round_bit mk_lang_constexpr_init;
		mk_lang_bool_t even_bit mk_lang_constexpr_init;
		mk_sl_flt_parse_inl_defcd_cui_t cui2;
		int exponent_encoded;

		si = mk_sl_flt_parse_inl_defcd_big_count_leading_zeros(&big1);
		mk_lang_assert(si != mk_sl_flt_parse_inl_defcd_big_has_bits);
		mk_lang_assert(si != 0);
		si -= (mk_sl_flt_parse_inl_defcd_big_has_bits - mk_sl_flt_parse_inl_defcd_fraction_bits - 1);
		if(si > 0)
		{
			mk_lang_assert(si <= mk_sl_flt_parse_inl_defcd_fraction_bits);
			mk_sl_flt_parse_inl_defcd_big_shl2(&big1, si);
			mk_sl_flt_parse_inl_defcd_big_to_cui(&big1, &cui1);
			exponent_decoded = (mk_sl_flt_parse_inl_defcd_fraction_bits - si);
		}
		else if(si == 0)
		{
			mk_sl_flt_parse_inl_defcd_big_to_cui(&big1, &cui1);
			exponent_decoded = mk_sl_flt_parse_inl_defcd_fraction_bits;
		}
		else
		{
			si = -si;
			exponent_decoded = (mk_sl_flt_parse_inl_defcd_fraction_bits + si);
			mk_sl_flt_parse_inl_defcd_big_set_mask(&big2, si - 1);
			mk_sl_flt_parse_inl_defcd_big_and2(&big2, &big1);
			tail_bits = !mk_sl_flt_parse_inl_defcd_big_is_zero(&big2);
			mk_sl_flt_parse_inl_defcd_big_shr2(&big1, si - 1);
			mk_sl_flt_parse_inl_defcd_big_to_cui(&big1, &cui1);
			mk_sl_flt_parse_inl_defcd_cui_to_bi_uint(&cui1, &ui);
			round_bit = (ui & 0x01u) != 0x00u;
			mk_sl_flt_parse_inl_defcd_cui_shr2(&cui1, 1);
			mk_sl_flt_parse_inl_defcd_cui_to_bi_uint(&cui1, &ui);
			even_bit = (ui & 0x01u) != 0x00u;
			if(round_bit && (even_bit || tail_bits))
			{
				mk_sl_flt_parse_inl_defcd_cui_inc1(&cui1);
				mk_sl_flt_parse_inl_defcd_cui_set_bit(&cui2, mk_sl_flt_parse_inl_defcd_fraction_bits + 1);
				if(mk_sl_flt_parse_inl_defcd_cui_eq(&cui1, &cui2))
				{
					mk_sl_flt_parse_inl_defcd_cui_set_zero(&cui1);
					++exponent_decoded;
				}
			}
		}
		exponent_encoded = exponent_decoded + mk_sl_flt_parse_inl_defcd_exponent_bias;
		if(exponent_encoded >= mk_sl_flt_parse_inl_defcd_exponent_encoded_max)
		{
			mk_sl_flt_parse_inl_defcd_generate_inf(is_negative, x);
			mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
			*consummed = str_len - rem;
			*result = mk_sl_flt_parse_inl_defcd_result_e_out_of_range;
			return;
		}
		mk_lang_assert(exponent_decoded >= mk_sl_flt_parse_inl_defcd_exponent_decoded_min && exponent_decoded <= mk_sl_flt_parse_inl_defcd_exponent_decoded_max);
		mk_lang_assert(exponent_encoded >= mk_sl_flt_parse_inl_defcd_exponent_encoded_min && exponent_encoded <= mk_sl_flt_parse_inl_defcd_exponent_encoded_max);
		mk_sl_flt_parse_inl_defcd_generate_number(&cui1, is_negative, exponent_encoded, x);
		mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
		*consummed = str_len - rem;
		*result = mk_sl_flt_parse_inl_defcd_result_e_ok;
		return;
	}
	mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
	*consummed = str_len - rem;
	*result = mk_sl_flt_parse_inl_defcd_result_e_invalid;
	return;
#if 0
	/**/
	if(rem != 0)
	{
		e = *ptr;
		++ptr;
		--rem;
		si = mk_sl_flt_parse_inl_defcd_char_to_digit(e);
	}
	if(rem == 0 || si == s_symbols_len)
	{
		if(have_something)
		{
			mk_sl_flt_parse_inl_defcd_generate_zero(x, is_negative);
			mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
			*consummed = str_len - rem;
			*result = mk_sl_flt_parse_inl_defcd_result_e_ok;
			return;
		}
		else
		{
			mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
			*consummed = str_len - rem;
			*result = mk_sl_flt_parse_inl_defcd_result_e_invalid;
			return;
		}
	}
	/**/
	/**/
	mk_sl_flt_parse_inl_defcd_bui_from_bi_sint(&bui1, &i);
	have_something = mk_lang_true;
	first_nz = str_len - rem - 1;
	count = 1;
	mk_sl_flt_parse_inl_defcd_big_set_zero(&big1);
	for(;;)
	{
		if(rem == 0)
		{
			break;
		}
		e = *ptr;
		++ptr;
		--rem;
		i = mk_sl_flt_parse_inl_defcd_char_to_digit(e);
		if(i == s_symbols_len)
		{
			--ptr;
			++rem;
			break;
		}
		if(str_len - rem - 1 - first_nz >= mk_sl_flt_parse_inl_defcd_max_nz_digits_pre_dot)
		{
			mk_sl_flt_parse_inl_defcd_generate_inf(is_negative, x);
			mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
			return str_len - rem;
		}
		ui = 10u;
		mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui2, &ui);
		mk_sl_flt_parse_inl_defcd_bui_mul2_wrap_lo(&bui1, &bui2);
		mk_sl_flt_parse_inl_defcd_bui_from_bi_sint(&bui2, &i);
		mk_sl_flt_parse_inl_defcd_bui_add2_wrap_cid_cod(&bui1, &bui2);
		++count;
		if(count == 9)
		{
			ui = 1000u;
			mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui2, &ui);
			mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui3, &ui);
			mk_sl_flt_parse_inl_defcd_bui_mul2_wrap_lo(&bui2, &bui3);
			mk_sl_flt_parse_inl_defcd_bui_mul2_wrap_lo(&bui2, &bui3);
			mk_sl_flt_parse_inl_defcd_big_mul2_wrap_lo_smol(&big1, &bui2);
			mk_sl_flt_parse_inl_defcd_big_add2_wrap_cid_cod_smol(&big1, &bui1);
			mk_sl_flt_parse_inl_defcd_bui_set_zero(&bui1);
			count = 0;
		}
	};
	if(count != 0)
	{
		ui = 10u;
		mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui2, &ui);
		mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui3, &ui);
		for(i = 1; i != count; ++i)
		{
			mk_sl_flt_parse_inl_defcd_bui_mul2_wrap_lo(&bui2, &bui3);
		}
		mk_sl_flt_parse_inl_defcd_big_mul2_wrap_lo_smol(&big1, &bui2);
		mk_sl_flt_parse_inl_defcd_big_add2_wrap_cid_cod_smol(&big1, &bui1);
	}

	if(e == s_dot)
	{
		dot_pos = str_len - rem;
	}
	else
	{
		dot_pos = 0;
	}
	/*mk_sl_flt_parse_inl_defcd_bui_set_zero(&bui1);
	for(;;)
	{
		if(rem == 0)
		{
			break;
		}
		e = *ptr;
		++ptr;
		--rem;
		i = mk_sl_flt_parse_inl_defcd_char_to_digit(e);
		if(i == s_symbols_len)
		{
			--ptr;
			++rem;
			break;
		}
		ui = 10u;
		mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui2, &ui);
		mk_sl_flt_parse_inl_defcd_bui_mul2_wrap_lo(&bui1, &bui2);
		mk_sl_flt_parse_inl_defcd_bui_from_bi_sint(&bui2, &i);
		mk_sl_flt_parse_inl_defcd_bui_add2_wrap_cid_cod(&bui1, &bui2);
		++count;
		if(count == 9)
		{
			ui = 1000u;
			mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui2, &ui);
			mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui3, &ui);
			mk_sl_flt_parse_inl_defcd_bui_mul2_wrap_lo(&bui2, &bui3);
			mk_sl_flt_parse_inl_defcd_bui_mul2_wrap_lo(&bui2, &bui3);
			mk_sl_flt_parse_inl_defcd_big_mul2_wrap_lo_smol(&big1, &bui2);
			mk_sl_flt_parse_inl_defcd_big_add2_wrap_cid_cod_smol(&big1, &bui1);
			mk_sl_flt_parse_inl_defcd_bui_set_zero(&bui1);
			count = 0;
			si = mk_sl_flt_parse_inl_defcd_big_count_leading_zeros(&big1);
			if(si < mk_sl_flt_parse_inl_defcd_big_has_bits - mk_sl_flt_parse_inl_defcd_big_needs_bits)
			{
				break;
				// todo tail bits
			}
		}
	};
	if(count != 0)
	{
		ui = 10u;
		mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui2, &ui);
		mk_sl_flt_parse_inl_defcd_bui_from_bi_uint(&bui3, &ui);
		for(i = 1; i != count; ++i)
		{
			mk_sl_flt_parse_inl_defcd_bui_mul2_wrap_lo(&bui2, &bui3);
		}
		mk_sl_flt_parse_inl_defcd_big_mul2_wrap_lo_smol(&big1, &bui2);
		mk_sl_flt_parse_inl_defcd_big_add2_wrap_cid_cod_smol(&big1, &bui1);
	}*/

	si = mk_sl_flt_parse_inl_defcd_big_count_leading_zeros(&big1);
	mk_lang_assert(si != mk_sl_flt_parse_inl_defcd_big_has_bits);
	mk_lang_assert(si != 0);
	si -= (mk_sl_flt_parse_inl_defcd_big_has_bits - mk_sl_flt_parse_inl_defcd_fraction_bits - 1);
	if(si > 0)
	{
		mk_lang_assert(si <= mk_sl_flt_parse_inl_defcd_fraction_bits);
		mk_sl_flt_parse_inl_defcd_big_shl2(&big1, si);
		mk_sl_flt_parse_inl_defcd_big_to_cui(&big1, &cui1);
		exponent_decoded = (mk_sl_flt_parse_inl_defcd_fraction_bits - si);
	}
	else if(si == 0)
	{
		mk_sl_flt_parse_inl_defcd_big_to_cui(&big1, &cui1);
		exponent_decoded = mk_sl_flt_parse_inl_defcd_fraction_bits;
	}
	else
	{
		si = -si;
		exponent_decoded = (mk_sl_flt_parse_inl_defcd_fraction_bits + si);
		mk_sl_flt_parse_inl_defcd_big_set_mask(&big2, si - 1);
		mk_sl_flt_parse_inl_defcd_big_and2(&big2, &big1);
		tail_bits = !mk_sl_flt_parse_inl_defcd_big_is_zero(&big2);
		mk_sl_flt_parse_inl_defcd_big_shr2(&big1, si - 1);
		mk_sl_flt_parse_inl_defcd_big_to_cui(&big1, &cui1);
		mk_sl_flt_parse_inl_defcd_cui_to_bi_uint(&cui1, &ui);
		round_bit = (ui & 0x01u) != 0x00u;
		mk_sl_flt_parse_inl_defcd_cui_shr2(&cui1, 1);
		mk_sl_flt_parse_inl_defcd_cui_to_bi_uint(&cui1, &ui);
		even_bit = (ui & 0x01u) != 0x00u;
		if(round_bit && (even_bit || tail_bits))
		{
			mk_sl_flt_parse_inl_defcd_cui_inc1(&cui1);
			mk_sl_flt_parse_inl_defcd_cui_set_bit(&cui2, mk_sl_flt_parse_inl_defcd_fraction_bits + 1);
			if(mk_sl_flt_parse_inl_defcd_cui_eq(&cui1, &cui2))
			{
				mk_sl_flt_parse_inl_defcd_cui_set_zero(&cui1);
				++exponent_decoded;
			}
		}
	}
	exponent_encoded = exponent_decoded + mk_sl_flt_parse_inl_defcd_exponent_bias;
	if(exponent_encoded >= mk_sl_flt_parse_inl_defcd_exponent_encoded_max)
	{
		mk_sl_flt_parse_inl_defcd_generate_inf(is_negative, x);
		mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
		return str_len - rem;
	}
	mk_lang_assert(exponent_decoded >= mk_sl_flt_parse_inl_defcd_exponent_decoded_min && exponent_decoded <= mk_sl_flt_parse_inl_defcd_exponent_decoded_max);
	mk_lang_assert(exponent_encoded >= mk_sl_flt_parse_inl_defcd_exponent_encoded_min && exponent_encoded <= mk_sl_flt_parse_inl_defcd_exponent_encoded_max);
	mk_sl_flt_parse_inl_defcd_generate_number(x, &cui1, is_negative, exponent_encoded);
	mk_lang_assert(((int)(ptr - str)) == (str_len - rem));
	return str_len - rem;
#endif
}

mk_lang_jumbo void mk_sl_flt_parse_inl_defcd_void_from_string_dec_n(void* const x, char const* const str, int const str_len, int* const consummed, mk_sl_flt_parse_inl_defcd_result_t* const result) mk_lang_noexcept
{
	mk_sl_flt_parse_inl_defcd_uchars_from_string_dec_n(((unsigned char*)(x)), str, str_len, consummed, result);
}


#undef arr_len


#include "mk_sl_flt_parse_inl_defcu.h"


#undef mk_sl_flt_name
#undef mk_sl_flt_bits
#undef mk_sl_flt_fraction_bits
