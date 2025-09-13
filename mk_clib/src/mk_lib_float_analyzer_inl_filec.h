#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_encoding.h"
#include "mk_lang_endian.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_string.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


#include "mk_lib_float_analyzer_inl_defd.h"


#define mk_sl_cui_t_name mk_lib_float_analyzer_inl_defd_cui_all
#define mk_sl_cui_t_base_type_name mk_lib_float_analyzer_inl_defd_base_cui_all
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lib_float_analyzer_inl_defd_base_cui_all_size_bits_d
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_float_analyzer_inl_defd_cui_exponent
#define mk_sl_cui_t_base_type_name mk_lib_float_analyzer_inl_defd_base_cui_exponent
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lib_float_analyzer_inl_defd_base_cui_exponent_size_bits_d
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_float_analyzer_inl_defd_cui_mantissa
#define mk_sl_cui_t_base_type_name mk_lib_float_analyzer_inl_defd_base_cui_mantissa
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lib_float_analyzer_inl_defd_base_cui_mantissa_size_bits_d
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_float_analyzer_inl_defd_cui_big
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (mk_lang_roundup_div(mk_lib_float_analyzer_inl_defd_cui_big_bits_needed_d, mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uint_size_bits_d
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_float_analyzer_inl_defd_cui_big_size_bits_d ((mk_lang_roundup_div(mk_lib_float_analyzer_inl_defd_cui_big_bits_needed_d, mk_lang_bui_uint_size_bits_d)) * mk_lang_bui_uint_size_bits_d)


enum mk_lib_float_analyzer_inl_defd_kind_e
{
	mk_lib_float_analyzer_inl_defd_kind_e_normal,
	mk_lib_float_analyzer_inl_defd_kind_e_zero,
	mk_lib_float_analyzer_inl_defd_kind_e_denormal,
	mk_lib_float_analyzer_inl_defd_kind_e_infinity,
	mk_lib_float_analyzer_inl_defd_kind_e_nan,
	mk_lib_float_analyzer_inl_defd_kind_e_dummy_end
};
typedef enum mk_lib_float_analyzer_inl_defd_kind_e mk_lib_float_analyzer_inl_defd_kind_t;


#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_float_analyzer_inl_defd_k_alphabet[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
#endif


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lib_float_analyzer_inl_defd_kind_t mk_lib_float_analyzer_inl_defd_pr_analyze_get_kind(mk_lib_float_analyzer_inl_defd_pct const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_kind_t kind;
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[mk_lib_float_analyzer_inl_defd_cui_all_size_bytes_v] mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_exponent_t exponent mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_mantissa_t mantissa mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	kind = mk_lib_float_analyzer_inl_defd_kind_e_dummy_end;
	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	mk_lib_float_analyzer_inl_defd_cui_all_shl2(&all, 1);
	mk_lib_float_analyzer_inl_defd_cui_all_shr2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_mantissa);
	mk_lib_float_analyzer_inl_defd_cui_all_to_buis_uchar_le(&all, &uchars[0]);
	mk_lib_float_analyzer_inl_defd_cui_exponent_from_buis_uchar_le(&exponent, &uchars[0]);
	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	mk_lib_float_analyzer_inl_defd_cui_all_shl2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_exponent);
	mk_lib_float_analyzer_inl_defd_cui_all_shr2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_exponent);
	mk_lib_float_analyzer_inl_defd_cui_all_to_buis_uchar_le(&all, &uchars[0]);
	mk_lib_float_analyzer_inl_defd_cui_mantissa_from_buis_uchar_le(&mantissa, &uchars[0]);
	if(mk_lib_float_analyzer_inl_defd_cui_exponent_is_zero(&exponent) && mk_lib_float_analyzer_inl_defd_cui_mantissa_is_zero(&mantissa))
	{
		kind = mk_lib_float_analyzer_inl_defd_kind_e_zero;
	}
	else if(mk_lib_float_analyzer_inl_defd_cui_exponent_is_zero(&exponent) && !mk_lib_float_analyzer_inl_defd_cui_mantissa_is_zero(&mantissa))
	{
		kind = mk_lib_float_analyzer_inl_defd_kind_e_denormal;
	}
	else if(mk_lib_float_analyzer_inl_defd_cui_exponent_count_trailing_ones(&exponent) == mk_lib_float_analyzer_inl_defd_bits_exponent && mk_lib_float_analyzer_inl_defd_cui_mantissa_is_zero(&mantissa))
	{
		kind = mk_lib_float_analyzer_inl_defd_kind_e_infinity;
	}
	else if(mk_lib_float_analyzer_inl_defd_cui_exponent_count_trailing_ones(&exponent) == mk_lib_float_analyzer_inl_defd_bits_exponent && !mk_lib_float_analyzer_inl_defd_cui_mantissa_is_zero(&mantissa))
	{
		kind = mk_lib_float_analyzer_inl_defd_kind_e_nan;
	}
	else
	{
		kind = mk_lib_float_analyzer_inl_defd_kind_e_normal;
	}
	return kind;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_all_bin(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_float_analyzer_inl_defd_cui_all_size_bits_v == mk_lib_float_analyzer_inl_defd_bits_all);

	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	len = mk_lib_float_analyzer_inl_defd_cui_all_to_str_binf_n(&all, &analyzer->m_all_text_bin_buf[0], mk_lang_countof(analyzer->m_all_text_bin_buf)); mk_lang_assert(len == mk_lang_countof(analyzer->m_all_text_bin_buf));
	analyzer->m_all_text_bin_len = len;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_all_hex(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_float_analyzer_inl_defd_cui_all_size_bits_v == mk_lib_float_analyzer_inl_defd_bits_all);

	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	len = mk_lib_float_analyzer_inl_defd_cui_all_to_str_hexf_n(&all, &analyzer->m_all_text_hex_buf[0], mk_lang_countof(analyzer->m_all_text_hex_buf)); mk_lang_assert(len == mk_lang_countof(analyzer->m_all_text_hex_buf));
	analyzer->m_all_text_hex_len = len;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_all_dec(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	len = mk_lib_float_analyzer_inl_defd_cui_all_to_str_dec_n(&all, &analyzer->m_all_text_dec_buf[0], mk_lang_countof(analyzer->m_all_text_dec_buf)); mk_lang_assert(len <= mk_lang_countof(analyzer->m_all_text_dec_buf));
	analyzer->m_all_text_dec_len = len;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_all_sgn(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	if(!mk_lib_float_analyzer_inl_defd_cui_all_has_msb(&all))
	{
		len = mk_lib_float_analyzer_inl_defd_cui_all_to_str_dec_n(&all, &analyzer->m_all_text_sgn_buf[0], mk_lang_countof(analyzer->m_all_text_sgn_buf)); mk_lang_assert(len <= mk_lang_countof(analyzer->m_all_text_sgn_buf));
		analyzer->m_all_text_sgn_len = len;
	}
	else
	{
		analyzer->m_all_text_sgn_buf[0] = '-';
		mk_lib_float_analyzer_inl_defd_cui_all_not1(&all);
		mk_lib_float_analyzer_inl_defd_cui_all_inc1(&all);
		len = mk_lib_float_analyzer_inl_defd_cui_all_to_str_dec_n(&all, &analyzer->m_all_text_sgn_buf[1], mk_lang_countof(analyzer->m_all_text_sgn_buf) - 1); mk_lang_assert(len <= mk_lang_countof(analyzer->m_all_text_sgn_buf) - 1);
		len += 1;
		analyzer->m_all_text_sgn_len = len;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_sign(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	if(!mk_lib_float_analyzer_inl_defd_cui_all_has_msb(&all))
	{
		mk_lang_string_memcpy_pc_fn(&analyzer->m_sign_text_buf[0], &mk_lib_float_analyzer_inl_defd_text_sign_positive[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_sign_positive));
		len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_sign_positive);
		analyzer->m_sign_text_len = len;
	}
	else
	{
		mk_lang_string_memcpy_pc_fn(&analyzer->m_sign_text_buf[0], &mk_lib_float_analyzer_inl_defd_text_sign_negative[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_sign_negative));
		len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_sign_negative);
		analyzer->m_sign_text_len = len;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_exponent_bin(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[mk_lib_float_analyzer_inl_defd_cui_all_size_bytes_v] mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_exponent_t exponent mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	mk_lib_float_analyzer_inl_defd_cui_all_shl2(&all, 1);
	mk_lib_float_analyzer_inl_defd_cui_all_shr2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_mantissa);
	mk_lib_float_analyzer_inl_defd_cui_all_to_buis_uchar_le(&all, &uchars[0]);
	mk_lib_float_analyzer_inl_defd_cui_exponent_from_buis_uchar_le(&exponent, &uchars[0]);
	#if mk_lib_float_analyzer_inl_defd_cui_exponent_size_bits_d == mk_lib_float_analyzer_inl_defd_bits_exponent
	len = mk_lib_float_analyzer_inl_defd_cui_exponent_to_str_binf_n(&exponent, &analyzer->m_exponent_text_bin_buf[0], mk_lang_countof(analyzer->m_exponent_text_bin_buf)); mk_lang_assert(len == mk_lang_countof(analyzer->m_exponent_text_bin_buf));
	analyzer->m_exponent_text_bin_len = len;
	#else
	len = mk_lib_float_analyzer_inl_defd_cui_exponent_to_str_binf_n(&exponent, &analyzer->m_exponent_text_bin_buf[0], mk_lang_countof(analyzer->m_exponent_text_bin_buf)); mk_lang_assert(len == mk_lang_countof(analyzer->m_exponent_text_bin_buf));
	mk_lang_string_memmov_pc_fn(&analyzer->m_exponent_text_bin_buf[0], &analyzer->m_exponent_text_bin_buf[mk_lang_countof(analyzer->m_exponent_text_bin_buf) - mk_lib_float_analyzer_inl_defd_bits_exponent], mk_lib_float_analyzer_inl_defd_bits_exponent);
	analyzer->m_exponent_text_bin_len = mk_lib_float_analyzer_inl_defd_bits_exponent;
	#endif
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_exponent_hex(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[mk_lib_float_analyzer_inl_defd_cui_all_size_bytes_v] mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_exponent_t exponent mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	mk_lib_float_analyzer_inl_defd_cui_all_shl2(&all, 1);
	mk_lib_float_analyzer_inl_defd_cui_all_shr2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_mantissa);
	mk_lib_float_analyzer_inl_defd_cui_all_to_buis_uchar_le(&all, &uchars[0]);
	mk_lib_float_analyzer_inl_defd_cui_exponent_from_buis_uchar_le(&exponent, &uchars[0]);
	#if mk_lib_float_analyzer_inl_defd_cui_exponent_size_bits_d == mk_lib_float_analyzer_inl_defd_bits_exponent
	len = mk_lib_float_analyzer_inl_defd_cui_exponent_to_str_hexf_n(&exponent, &analyzer->m_exponent_text_hex_buf[0], mk_lang_countof(analyzer->m_exponent_text_hex_buf)); mk_lang_assert(len == mk_lang_countof(analyzer->m_exponent_text_hex_buf));
	analyzer->m_exponent_text_hex_len = len;
	#else
	len = mk_lib_float_analyzer_inl_defd_cui_exponent_to_str_hexf_n(&exponent, &analyzer->m_exponent_text_hex_buf[0], mk_lang_countof(analyzer->m_exponent_text_hex_buf)); mk_lang_assert(len == mk_lang_countof(analyzer->m_exponent_text_hex_buf));
	mk_lang_string_memmov_pc_fn(&analyzer->m_exponent_text_hex_buf[0], &analyzer->m_exponent_text_hex_buf[mk_lang_countof(analyzer->m_exponent_text_hex_buf) - mk_lang_roundup_div(mk_lib_float_analyzer_inl_defd_bits_exponent, 4)], mk_lang_roundup_div(mk_lib_float_analyzer_inl_defd_bits_exponent, 4));
	analyzer->m_exponent_text_hex_len = mk_lang_roundup_div(mk_lib_float_analyzer_inl_defd_bits_exponent, 4);
	#endif
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_exponent_dec(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[mk_lib_float_analyzer_inl_defd_cui_all_size_bytes_v] mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_exponent_t exponent mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	mk_lib_float_analyzer_inl_defd_cui_all_shl2(&all, 1);
	mk_lib_float_analyzer_inl_defd_cui_all_shr2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_mantissa);
	mk_lib_float_analyzer_inl_defd_cui_all_to_buis_uchar_le(&all, &uchars[0]);
	mk_lib_float_analyzer_inl_defd_cui_exponent_from_buis_uchar_le(&exponent, &uchars[0]);
	len = mk_lib_float_analyzer_inl_defd_cui_exponent_to_str_dec_n(&exponent, &analyzer->m_exponent_text_dec_buf[0], mk_lang_countof(analyzer->m_exponent_text_dec_buf)); mk_lang_assert(len <= mk_lang_countof(analyzer->m_exponent_text_dec_buf));
	analyzer->m_exponent_text_dec_len = len;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_exponent_dcd(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[mk_lib_float_analyzer_inl_defd_cui_all_size_bytes_v] mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_exponent_t exponent mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_kind_t kind mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_exponent_t exponent_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	mk_lib_float_analyzer_inl_defd_cui_all_shl2(&all, 1);
	mk_lib_float_analyzer_inl_defd_cui_all_shr2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_mantissa);
	mk_lib_float_analyzer_inl_defd_cui_all_to_buis_uchar_le(&all, &uchars[0]);
	mk_lib_float_analyzer_inl_defd_cui_exponent_from_buis_uchar_le(&exponent, &uchars[0]);
	kind = mk_lib_float_analyzer_inl_defd_pr_analyze_get_kind(analyzer);
	switch(kind)
	{
		case mk_lib_float_analyzer_inl_defd_kind_e_normal:
		{
			#if mk_lib_float_analyzer_inl_defd_bits_exponent == mk_lib_float_analyzer_inl_defd_base_cui_exponent_size_bits_d
			mk_lib_float_analyzer_inl_defd_cui_exponent_set_max(&exponent_b);
			#elif mk_lib_float_analyzer_inl_defd_bits_exponent < mk_lib_float_analyzer_inl_defd_base_cui_exponent_size_bits_d
			mk_lib_float_analyzer_inl_defd_cui_exponent_set_bit(&exponent_b, mk_lib_float_analyzer_inl_defd_bits_exponent);
			mk_lib_float_analyzer_inl_defd_cui_exponent_dec1(&exponent_b);
			#else
			#error xxxxxxxxxx
			#endif
			mk_lib_float_analyzer_inl_defd_cui_exponent_dec1(&exponent_b);
			mk_lib_float_analyzer_inl_defd_cui_exponent_shr2(&exponent_b, 1);
			mk_lib_float_analyzer_inl_defd_cui_exponent_sub2_wrap_cid_cod(&exponent, &exponent_b);
			if(!mk_lib_float_analyzer_inl_defd_cui_exponent_has_msb(&exponent))
			{
				len = mk_lib_float_analyzer_inl_defd_cui_exponent_to_str_dec_n(&exponent, &analyzer->m_exponent_text_decoded_buf[0], mk_lang_countof(analyzer->m_exponent_text_decoded_buf)); mk_lang_assert(len <= mk_lang_countof(analyzer->m_exponent_text_decoded_buf));
				analyzer->m_exponent_text_decoded_len = len;
			}
			else
			{
				analyzer->m_exponent_text_decoded_buf[0] = '-';
				mk_lib_float_analyzer_inl_defd_cui_exponent_not1(&exponent);
				mk_lib_float_analyzer_inl_defd_cui_exponent_inc1(&exponent);
				len = mk_lib_float_analyzer_inl_defd_cui_exponent_to_str_dec_n(&exponent, &analyzer->m_exponent_text_decoded_buf[1], mk_lang_countof(analyzer->m_exponent_text_decoded_buf) - 1); mk_lang_assert(len <= mk_lang_countof(analyzer->m_exponent_text_decoded_buf) - 1);
				len += 1;
				analyzer->m_exponent_text_decoded_len = len;
			}
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_zero:
		{
			mk_lang_string_memcpy_pc_fn(&analyzer->m_exponent_text_decoded_buf[0], &mk_lib_float_analyzer_inl_defd_text_exponent_na[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_na));
			len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_na);
			analyzer->m_exponent_text_decoded_len = len;
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_denormal:
		{
			#if mk_lib_float_analyzer_inl_defd_bits_exponent == mk_lib_float_analyzer_inl_defd_base_cui_exponent_size_bits_d
			mk_lib_float_analyzer_inl_defd_cui_exponent_set_max(&exponent_b);
			#elif mk_lib_float_analyzer_inl_defd_bits_exponent < mk_lib_float_analyzer_inl_defd_base_cui_exponent_size_bits_d
			mk_lib_float_analyzer_inl_defd_cui_exponent_set_bit(&exponent_b, mk_lib_float_analyzer_inl_defd_bits_exponent);
			mk_lib_float_analyzer_inl_defd_cui_exponent_dec1(&exponent_b);
			#else
			#error xxxxxxxxxx
			#endif
			mk_lib_float_analyzer_inl_defd_cui_exponent_dec1(&exponent_b);
			mk_lib_float_analyzer_inl_defd_cui_exponent_shr2(&exponent_b, 1);
			mk_lib_float_analyzer_inl_defd_cui_exponent_sub2_wrap_cid_cod(&exponent, &exponent_b);
			mk_lib_float_analyzer_inl_defd_cui_exponent_inc1(&exponent);
			if(!mk_lib_float_analyzer_inl_defd_cui_exponent_has_msb(&exponent))
			{
				len = mk_lib_float_analyzer_inl_defd_cui_exponent_to_str_dec_n(&exponent, &analyzer->m_exponent_text_decoded_buf[0], mk_lang_countof(analyzer->m_exponent_text_decoded_buf)); mk_lang_assert(len <= mk_lang_countof(analyzer->m_exponent_text_decoded_buf));
				analyzer->m_exponent_text_decoded_len = len;
			}
			else
			{
				analyzer->m_exponent_text_decoded_buf[0] = '-';
				mk_lib_float_analyzer_inl_defd_cui_exponent_not1(&exponent);
				mk_lib_float_analyzer_inl_defd_cui_exponent_inc1(&exponent);
				len = mk_lib_float_analyzer_inl_defd_cui_exponent_to_str_dec_n(&exponent, &analyzer->m_exponent_text_decoded_buf[1], mk_lang_countof(analyzer->m_exponent_text_decoded_buf) - 1); mk_lang_assert(len <= mk_lang_countof(analyzer->m_exponent_text_decoded_buf) - 1);
				len += 1;
				analyzer->m_exponent_text_decoded_len = len;
			}
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_infinity:
		{
			mk_lang_string_memcpy_pc_fn(&analyzer->m_exponent_text_decoded_buf[0], &mk_lib_float_analyzer_inl_defd_text_exponent_na[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_na));
			len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_na);
			analyzer->m_exponent_text_decoded_len = len;
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_nan:
		{
			mk_lang_string_memcpy_pc_fn(&analyzer->m_exponent_text_decoded_buf[0], &mk_lib_float_analyzer_inl_defd_text_exponent_na[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_na));
			len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_na);
			analyzer->m_exponent_text_decoded_len = len;
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_exponent_typ(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_kind_t kind mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	kind = mk_lib_float_analyzer_inl_defd_pr_analyze_get_kind(analyzer);
	switch(kind)
	{
		case mk_lib_float_analyzer_inl_defd_kind_e_normal:
		{
			mk_lang_string_memcpy_pc_fn(&analyzer->m_exponent_text_type_buf[0], &mk_lib_float_analyzer_inl_defd_text_exponent_type_normal[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_normal));
			len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_normal);
			analyzer->m_exponent_text_type_len = len;
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_zero:
		{
			mk_lang_string_memcpy_pc_fn(&analyzer->m_exponent_text_type_buf[0], &mk_lib_float_analyzer_inl_defd_text_exponent_type_zero[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_zero));
			len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_zero);
			analyzer->m_exponent_text_type_len = len;
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_denormal:
		{
			mk_lang_string_memcpy_pc_fn(&analyzer->m_exponent_text_type_buf[0], &mk_lib_float_analyzer_inl_defd_text_exponent_type_denormal[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_denormal));
			len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_denormal);
			analyzer->m_exponent_text_type_len = len;
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_infinity:
		{
			mk_lang_string_memcpy_pc_fn(&analyzer->m_exponent_text_type_buf[0], &mk_lib_float_analyzer_inl_defd_text_exponent_type_infinity[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_infinity));
			len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_infinity);
			analyzer->m_exponent_text_type_len = len;
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_nan:
		{
			mk_lang_string_memcpy_pc_fn(&analyzer->m_exponent_text_type_buf[0], &mk_lib_float_analyzer_inl_defd_text_exponent_type_nan[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_nan));
			len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_nan);
			analyzer->m_exponent_text_type_len = len;
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_exponent_one(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_kind_t kind mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	kind = mk_lib_float_analyzer_inl_defd_pr_analyze_get_kind(analyzer);
	switch(kind)
	{
		case mk_lib_float_analyzer_inl_defd_kind_e_normal:
		{
			mk_lang_string_memcpy_pc_fn(&analyzer->m_exponent_text_implied_one_buf[0], &mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_yes[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_yes));
			len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_yes);
			analyzer->m_exponent_text_implied_one_len = len;
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_zero:
		{
			mk_lang_string_memcpy_pc_fn(&analyzer->m_exponent_text_implied_one_buf[0], &mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_na[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_na));
			len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_na);
			analyzer->m_exponent_text_implied_one_len = len;
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_denormal:
		{
			mk_lang_string_memcpy_pc_fn(&analyzer->m_exponent_text_implied_one_buf[0], &mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_no[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_no));
			len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_no);
			analyzer->m_exponent_text_implied_one_len = len;
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_infinity:
		{
			mk_lang_string_memcpy_pc_fn(&analyzer->m_exponent_text_implied_one_buf[0], &mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_na[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_na));
			len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_na);
			analyzer->m_exponent_text_implied_one_len = len;
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_nan:
		{
			mk_lang_string_memcpy_pc_fn(&analyzer->m_exponent_text_implied_one_buf[0], &mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_na[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_na));
			len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_na);
			analyzer->m_exponent_text_implied_one_len = len;
		}
		break;
		case mk_lib_float_analyzer_inl_defd_kind_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_bin(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[mk_lib_float_analyzer_inl_defd_cui_all_size_bytes_v] mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_mantissa_t mantissa mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	mk_lib_float_analyzer_inl_defd_cui_all_shl2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_exponent);
	mk_lib_float_analyzer_inl_defd_cui_all_shr2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_exponent);
	mk_lib_float_analyzer_inl_defd_cui_all_to_buis_uchar_le(&all, &uchars[0]);
	mk_lib_float_analyzer_inl_defd_cui_mantissa_from_buis_uchar_le(&mantissa, &uchars[0]);
	#if mk_lib_float_analyzer_inl_defd_cui_mantissa_size_bits_d == mk_lib_float_analyzer_inl_defd_bits_mantissa
	#error todo
	#else
	len = mk_lib_float_analyzer_inl_defd_cui_mantissa_to_str_binf_n(&mantissa, &analyzer->m_mantissa_text_bin_buf[0], mk_lang_countof(analyzer->m_mantissa_text_bin_buf)); mk_lang_assert(len == mk_lang_countof(analyzer->m_mantissa_text_bin_buf));
	mk_lang_string_memmov_pc_fn(&analyzer->m_mantissa_text_bin_buf[0], &analyzer->m_mantissa_text_bin_buf[mk_lang_countof(analyzer->m_mantissa_text_bin_buf) - mk_lib_float_analyzer_inl_defd_bits_mantissa], mk_lib_float_analyzer_inl_defd_bits_mantissa);
	analyzer->m_mantissa_text_bin_len = mk_lib_float_analyzer_inl_defd_bits_mantissa;
	#endif
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_hex(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[mk_lib_float_analyzer_inl_defd_cui_all_size_bytes_v] mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_mantissa_t mantissa mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	mk_lib_float_analyzer_inl_defd_cui_all_shl2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_exponent);
	mk_lib_float_analyzer_inl_defd_cui_all_shr2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_exponent);
	mk_lib_float_analyzer_inl_defd_cui_all_to_buis_uchar_le(&all, &uchars[0]);
	mk_lib_float_analyzer_inl_defd_cui_mantissa_from_buis_uchar_le(&mantissa, &uchars[0]);
	#if mk_lib_float_analyzer_inl_defd_cui_mantissa_size_bits_d == mk_lib_float_analyzer_inl_defd_bits_mantissa
	#error todo
	#else
	len = mk_lib_float_analyzer_inl_defd_cui_mantissa_to_str_hexf_n(&mantissa, &analyzer->m_mantissa_text_hex_buf[0], mk_lang_countof(analyzer->m_mantissa_text_hex_buf)); mk_lang_assert(len == mk_lang_countof(analyzer->m_mantissa_text_hex_buf));
	mk_lang_string_memmov_pc_fn(&analyzer->m_mantissa_text_hex_buf[0], &analyzer->m_mantissa_text_hex_buf[mk_lang_countof(analyzer->m_mantissa_text_hex_buf) - mk_lang_roundup_div(mk_lib_float_analyzer_inl_defd_bits_mantissa, 4)], mk_lang_roundup_div(mk_lib_float_analyzer_inl_defd_bits_mantissa, 4));
	analyzer->m_mantissa_text_hex_len = mk_lang_roundup_div(mk_lib_float_analyzer_inl_defd_bits_mantissa, 4);
	#endif
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_dec(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[mk_lib_float_analyzer_inl_defd_cui_all_size_bytes_v] mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_mantissa_t mantissa mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	mk_lib_float_analyzer_inl_defd_cui_all_shl2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_exponent);
	mk_lib_float_analyzer_inl_defd_cui_all_shr2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_exponent);
	mk_lib_float_analyzer_inl_defd_cui_all_to_buis_uchar_le(&all, &uchars[0]);
	mk_lib_float_analyzer_inl_defd_cui_mantissa_from_buis_uchar_le(&mantissa, &uchars[0]);
	len = mk_lib_float_analyzer_inl_defd_cui_mantissa_to_str_dec_n(&mantissa, &analyzer->m_mantissa_text_dec_buf[0], mk_lang_countof(analyzer->m_mantissa_text_dec_buf)); mk_lang_assert(len <= mk_lang_countof(analyzer->m_mantissa_text_dec_buf));
	analyzer->m_mantissa_text_dec_len = len;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_dcd_y(mk_lib_float_analyzer_inl_defd_pt const analyzer, mk_lib_float_analyzer_inl_defd_kind_t const kind) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[mk_lib_float_analyzer_inl_defd_cui_all_size_bytes_v] mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_mantissa_t mantissa mk_lang_constexpr_init;
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_mantissa_base_t base mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_mantissa_base_t tc mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_mantissa_t ta mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_mantissa_t tb mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_mantissa_pt pta mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_mantissa_pt ptb mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_mantissa_pt ptc mk_lang_constexpr_init;

	mk_lang_assert(analyzer);
	mk_lang_assert(kind >= 0);
	mk_lang_assert(kind < mk_lib_float_analyzer_inl_defd_kind_e_dummy_end);

	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	mk_lib_float_analyzer_inl_defd_cui_all_shl2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_exponent);
	mk_lib_float_analyzer_inl_defd_cui_all_shr2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_exponent);
	mk_lib_float_analyzer_inl_defd_cui_all_to_buis_uchar_le(&all, &uchars[0]);
	mk_lib_float_analyzer_inl_defd_cui_mantissa_from_buis_uchar_le(&mantissa, &uchars[0]);
	ptr = &analyzer->m_mantissa_text_dcd_buf[0];
	#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
	ptr[0] = kind == mk_lib_float_analyzer_inl_defd_kind_e_normal ? mk_lib_float_analyzer_inl_defd_k_alphabet[1] : mk_lib_float_analyzer_inl_defd_k_alphabet[0]; ++ptr;
	#else
	ptr[0] = ((mk_lang_types_pchar_t)('0' + (kind == mk_lib_float_analyzer_inl_defd_kind_e_normal ? 1 : 0))); ++ptr;
	#endif
	ptr[0] = '.'; ++ptr;
	if(mk_lib_float_analyzer_inl_defd_cui_mantissa_is_zero(&mantissa))
	{
		#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
		ptr[0] = mk_lib_float_analyzer_inl_defd_k_alphabet[0];
		#else
		ptr[0] = ((mk_lang_types_pchar_t)('0' + 0));
		#endif
		len = 3;
	}
	else
	{
		pta = &ta;
		ptb = &tb;
		len = 10; mk_lib_float_analyzer_inl_defd_cui_mantissa_base_from_bi_sint(&base, &len);
		mk_lib_float_analyzer_inl_defd_cui_mantissa_shl3(&mantissa, 1 + mk_lib_float_analyzer_inl_defd_bits_exponent, &ta);
		for(;;)
		{
			mk_lib_float_analyzer_inl_defd_cui_mantissa_mul4_wrap_wi_smol(pta, &base, ptb, &tc);
			mk_lib_float_analyzer_inl_defd_cui_mantissa_base_to_bi_sint(&tc, &len);
			mk_lang_assert(len >= 0 && len <= 9);
			#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
			ptr[0] = mk_lib_float_analyzer_inl_defd_k_alphabet[len]; ++ptr;
			#else
			ptr[0] = ((mk_lang_types_pchar_t)('0' + len)); ++ptr;
			#endif
			if(mk_lib_float_analyzer_inl_defd_cui_mantissa_is_zero(ptb))
			{
				len = ((mk_lang_types_sint_t)(ptr - &analyzer->m_mantissa_text_dcd_buf[0]));
				break;
			}
			ptc = pta; pta = ptb; ptb = ptc;
		}
	}
	analyzer->m_mantissa_text_dcd_len = len;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_dcd_n(mk_lib_float_analyzer_inl_defd_pt const analyzer, mk_lib_float_analyzer_inl_defd_kind_t const kind) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(analyzer);
	mk_lang_assert(kind >= 0);
	mk_lang_assert(kind < mk_lib_float_analyzer_inl_defd_kind_e_dummy_end);

	mk_lang_string_memcpy_pc_fn(&analyzer->m_mantissa_text_dcd_buf[0], &mk_lib_float_analyzer_inl_defd_text_mantissa_na[0], mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_mantissa_na));
	len = mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_mantissa_na);
	analyzer->m_mantissa_text_dcd_len = len;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_dcd(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_kind_t kind mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	kind = mk_lib_float_analyzer_inl_defd_pr_analyze_get_kind(analyzer);
	switch(kind)
	{
		case mk_lib_float_analyzer_inl_defd_kind_e_normal  : mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_dcd_y(analyzer, kind); break;
		case mk_lib_float_analyzer_inl_defd_kind_e_zero    : mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_dcd_n(analyzer, kind); break;
		case mk_lib_float_analyzer_inl_defd_kind_e_denormal: mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_dcd_y(analyzer, kind); break;
		case mk_lib_float_analyzer_inl_defd_kind_e_infinity: mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_dcd_n(analyzer, kind); break;
		case mk_lib_float_analyzer_inl_defd_kind_e_nan     : mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_dcd_n(analyzer, kind); break;
		case mk_lib_float_analyzer_inl_defd_kind_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_float_analyzer_inl_defd_pr_decode_exponent(mk_lib_float_analyzer_inl_defd_pct const analyzer) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[mk_lib_float_analyzer_inl_defd_cui_all_size_bytes_v] mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_exponent_t exponent mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_exponent_t exponent_b mk_lang_constexpr_init;
	mk_lang_types_sint_t exponent_decoded mk_lang_constexpr_init;

	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	mk_lib_float_analyzer_inl_defd_cui_all_shl2(&all, 1);
	mk_lib_float_analyzer_inl_defd_cui_all_shr2(&all, 1 + mk_lib_float_analyzer_inl_defd_bits_mantissa);
	mk_lib_float_analyzer_inl_defd_cui_all_to_buis_uchar_le(&all, &uchars[0]);
	mk_lib_float_analyzer_inl_defd_cui_exponent_from_buis_uchar_le(&exponent, &uchars[0]);
	if(mk_lib_float_analyzer_inl_defd_cui_exponent_is_zero(&exponent))
	{
		mk_lib_float_analyzer_inl_defd_cui_exponent_inc1(&exponent);
	}
	#if mk_lib_float_analyzer_inl_defd_bits_exponent == mk_lib_float_analyzer_inl_defd_base_cui_exponent_size_bits_d
	mk_lib_float_analyzer_inl_defd_cui_exponent_set_max(&exponent_b);
	#elif mk_lib_float_analyzer_inl_defd_bits_exponent < mk_lib_float_analyzer_inl_defd_base_cui_exponent_size_bits_d
	mk_lib_float_analyzer_inl_defd_cui_exponent_set_bit(&exponent_b, mk_lib_float_analyzer_inl_defd_bits_exponent);
	mk_lib_float_analyzer_inl_defd_cui_exponent_dec1(&exponent_b);
	#else
	#error xxxxxxxxxx
	#endif
	mk_lib_float_analyzer_inl_defd_cui_exponent_dec1(&exponent_b);
	mk_lib_float_analyzer_inl_defd_cui_exponent_shr2(&exponent_b, 1);
	mk_lib_float_analyzer_inl_defd_cui_exponent_sub2_wrap_cid_cod(&exponent, &exponent_b);
	if(!mk_lib_float_analyzer_inl_defd_cui_exponent_has_msb(&exponent))
	{
		mk_lib_float_analyzer_inl_defd_cui_exponent_to_bi_sint(&exponent, &exponent_decoded);
	}
	else
	{
		mk_lib_float_analyzer_inl_defd_cui_exponent_not1(&exponent);
		mk_lib_float_analyzer_inl_defd_cui_exponent_inc1(&exponent);
		mk_lib_float_analyzer_inl_defd_cui_exponent_to_bi_sint(&exponent, &exponent_decoded);
		exponent_decoded = -exponent_decoded;
	}
	return exponent_decoded;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_float_analyzer_inl_defd_cui_big_to_str_dec_inverse_n(mk_lib_float_analyzer_inl_defd_cui_big_pct const x, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lib_float_analyzer_inl_defd_cui_big_t ta mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_big_t tb mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_big_pt pta mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_big_pt ptb mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_big_pt ptc mk_lang_constexpr_init;
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem  mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_bui_uint_t base mk_lang_constexpr_init;
	mk_lang_bui_uint_t tc mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	ta = *x;
	pta = &ta;
	ptb = &tb;
	ptr = str_buf;
	rem = str_len;
	len = 10; mk_lang_bui_uint_from_bi_sint(&base, &len);
	for(;;)
	{
		if(rem == 0)
		{
			len = 0;
			break;
		}
		mk_lib_float_analyzer_inl_defd_cui_big_mul4_wrap_wi_smol(pta, &base, ptb, &tc);
		mk_lang_bui_uint_to_bi_sint(&tc, &len);
		mk_lang_assert(len >= 0 && len <= 9);
		#if !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic
		ptr[0] = mk_lib_float_analyzer_inl_defd_k_alphabet[len]; ++ptr; --rem;
		#else
		ptr[0] = ((mk_lang_types_pchar_t)('0' + len)); ++ptr; --rem;
		#endif
		if(mk_lib_float_analyzer_inl_defd_cui_big_is_zero(ptb))
		{
			len = ((mk_lang_types_sint_t)(ptr - &str_buf[0]));
			break;
		}
		ptc = pta; pta = ptb; ptb = ptc;
	}
	return len;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_pr_analyze_value(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_all_t all mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_kind_t kind mk_lang_constexpr_init;
	mk_lang_types_bool_t implied_one mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_big_t big_a mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_sint_t len2 mk_lang_constexpr_init;
	mk_lang_types_sint_t idx mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lib_float_analyzer_inl_defd_cui_big_t big_b mk_lang_constexpr_init;
	mk_lang_types_sint_t exponent_decoded mk_lang_constexpr_init;
	mk_lang_types_sint_t shift_amount mk_lang_constexpr_init;
	mk_lang_types_sint_t partial_byte_bits mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(mk_lib_float_analyzer_inl_defd_bits_mantissa >= mk_lang_charbit);

	mk_lang_assert(analyzer);

	ptr = &analyzer->m_value_buf[0];
	rem = mk_lang_countof(analyzer->m_value_buf);
	mk_lib_float_analyzer_inl_defd_cui_all_from_buis_uchar_le(&all, &analyzer->m_float_bytes_le[0]);
	if(mk_lib_float_analyzer_inl_defd_cui_all_has_msb(&all))
	{
		ptr[0] = '-'; ptr += 1; rem -= 1;
	}
	kind = mk_lib_float_analyzer_inl_defd_pr_analyze_get_kind(analyzer);
	if(kind == mk_lib_float_analyzer_inl_defd_kind_e_zero)
	{
		ptr[0] = '0'; ptr += 1; rem -= 1;
		ptr[0] = '.'; ptr += 1; rem -= 1;
		ptr[0] = '0'; ptr += 1; rem -= 1;
		analyzer->m_value_len = mk_lang_countof(analyzer->m_value_buf) - rem;
	}
	else if(kind == mk_lib_float_analyzer_inl_defd_kind_e_infinity)
	{
		ptr[0] = 'i'; ptr += 1; rem -= 1;
		ptr[0] = 'n'; ptr += 1; rem -= 1;
		ptr[0] = 'f'; ptr += 1; rem -= 1;
		analyzer->m_value_len = mk_lang_countof(analyzer->m_value_buf) - rem;
	}
	else if(kind == mk_lib_float_analyzer_inl_defd_kind_e_nan)
	{
		ptr[0] = 'n'; ptr += 1; rem -= 1;
		ptr[0] = 'a'; ptr += 1; rem -= 1;
		ptr[0] = 'n'; ptr += 1; rem -= 1;
		analyzer->m_value_len = mk_lang_countof(analyzer->m_value_buf) - rem;
	}
	else
	{
		mk_lang_assert(kind == mk_lib_float_analyzer_inl_defd_kind_e_normal || kind == mk_lib_float_analyzer_inl_defd_kind_e_denormal);
		implied_one = kind == mk_lib_float_analyzer_inl_defd_kind_e_normal;
		if(implied_one)
		{
			mk_lib_float_analyzer_inl_defd_cui_big_set_one(&big_a);
		}
		else
		{
			mk_lib_float_analyzer_inl_defd_cui_big_set_zero(&big_a);
		}
		partial_byte_bits = mk_lib_float_analyzer_inl_defd_bits_mantissa % mk_lang_charbit;
		if(partial_byte_bits != 0)
		{
			mk_lib_float_analyzer_inl_defd_cui_big_shl2(&big_a, partial_byte_bits);
			idx = mk_lib_float_analyzer_inl_defd_bits_mantissa / mk_lang_charbit;
			tuc = analyzer->m_float_bytes_le[idx];
			tuc = tuc & ((1u << partial_byte_bits) - 1);
			mk_lib_float_analyzer_inl_defd_cui_big_from_bi_uchar(&big_b, &tuc);
			mk_lib_float_analyzer_inl_defd_cui_big_or2(&big_a, &big_b);
		}
		n = mk_lib_float_analyzer_inl_defd_bits_mantissa / mk_lang_charbit;
		for(i = 0; i != n; ++i)
		{
			idx = (n - 1) - i;
			mk_lib_float_analyzer_inl_defd_cui_big_shl2(&big_a, mk_lang_charbit);
			mk_lib_float_analyzer_inl_defd_cui_big_from_bi_uchar(&big_b, &analyzer->m_float_bytes_le[idx]);
			mk_lib_float_analyzer_inl_defd_cui_big_or2(&big_a, &big_b);
		}
		exponent_decoded = mk_lib_float_analyzer_inl_defd_pr_decode_exponent(analyzer);
		shift_amount = mk_lib_float_analyzer_inl_defd_bits_mantissa - exponent_decoded;
		if(shift_amount >= 0)
		{
			mk_lib_float_analyzer_inl_defd_cui_big_shr3(&big_a, shift_amount, &big_b);
		}
		else
		{
			shift_amount = -shift_amount;
			mk_lib_float_analyzer_inl_defd_cui_big_shl3(&big_a, shift_amount, &big_b);
		}
		mk_lang_assert(rem >= 1);
		len = mk_lib_float_analyzer_inl_defd_cui_big_to_str_dec_n(&big_b, ptr, rem); mk_lang_assert(len >= 0); mk_lang_assert(len <= rem);
		ptr += len; rem -= len;
		mk_lang_assert(rem >= 1); ptr[0] = '.'; ptr += 1; rem -= 1;
		if(exponent_decoded >= mk_lib_float_analyzer_inl_defd_bits_mantissa)
		{
			mk_lang_assert(rem >= 1); ptr[0] = '0'; ptr += 1; rem -= 1;
			len2 = 1;
		}
		else
		{
			shift_amount = (mk_lib_float_analyzer_inl_defd_cui_big_size_bits_d - mk_lib_float_analyzer_inl_defd_bits_mantissa) + exponent_decoded;
			mk_lib_float_analyzer_inl_defd_cui_big_shl3(&big_a, shift_amount, &big_b);
			mk_lang_assert(rem >= 1);
			len2 = mk_lib_float_analyzer_inl_defd_cui_big_to_str_dec_inverse_n(&big_b, ptr, rem); mk_lang_assert(len2 >= 0); mk_lang_assert(len2 <= rem);
			ptr += len2; rem -= len2;
		}
		analyzer->m_value_len = mk_lang_countof(analyzer->m_value_buf) - rem;
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_analyze(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept
{
	mk_lang_assert(analyzer);

	mk_lib_float_analyzer_inl_defd_pr_analyze_all_bin(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_all_hex(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_all_dec(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_all_sgn(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_sign(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_exponent_bin(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_exponent_hex(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_exponent_dec(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_exponent_dcd(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_exponent_typ(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_exponent_one(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_bin(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_hex(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_dec(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_mantissa_dcd(analyzer);
	mk_lib_float_analyzer_inl_defd_pr_analyze_value(analyzer);
}


#include "mk_lib_float_analyzer_inl_defu.h"
