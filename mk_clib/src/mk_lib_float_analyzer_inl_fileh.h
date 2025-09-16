#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


#include "mk_lib_float_analyzer_inl_defd.h"


#define mk_sl_cui_t_name mk_lib_float_analyzer_inl_defd_cui_all
#define mk_sl_cui_t_base_type_name mk_lib_float_analyzer_inl_defd_base_cui_all
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lib_float_analyzer_inl_defd_base_cui_all_size_bits_d
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_float_analyzer_inl_defd_cui_exponent
#define mk_sl_cui_t_base_type_name mk_lib_float_analyzer_inl_defd_base_cui_exponent
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lib_float_analyzer_inl_defd_base_cui_exponent_size_bits_d
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_float_analyzer_inl_defd_cui_exponent_size_bits_d (1 * mk_lib_float_analyzer_inl_defd_base_cui_exponent_size_bits_d)

#define mk_sl_cui_t_name mk_lib_float_analyzer_inl_defd_cui_mantissa
#define mk_sl_cui_t_base_type_name mk_lib_float_analyzer_inl_defd_base_cui_mantissa
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lib_float_analyzer_inl_defd_base_cui_mantissa_size_bits_d
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_float_analyzer_inl_defd_cui_mantissa_size_bits_d (1 * mk_lib_float_analyzer_inl_defd_base_cui_mantissa_size_bits_d)


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_float_analyzer_inl_defd_s
{
	mk_lang_types_uchar_t m_float_bytes_le[mk_lib_float_analyzer_inl_defd_bits_all / mk_lang_charbit];
	mk_lang_types_uint_t m_all_text_bin_len;
	mk_lang_types_uint_t m_all_text_hex_len;
	mk_lang_types_uint_t m_all_text_dec_len;
	mk_lang_types_uint_t m_all_text_sgn_len;
	mk_lang_types_uint_t m_sign_text_len;
	mk_lang_types_uint_t m_exponent_text_bin_len;
	mk_lang_types_uint_t m_exponent_text_hex_len;
	mk_lang_types_uint_t m_exponent_text_dec_len;
	mk_lang_types_uint_t m_exponent_text_decoded_len;
	mk_lang_types_uint_t m_exponent_text_type_len;
	mk_lang_types_uint_t m_exponent_text_implied_one_len;
	mk_lang_types_uint_t m_mantissa_text_bin_len;
	mk_lang_types_uint_t m_mantissa_text_hex_len;
	mk_lang_types_uint_t m_mantissa_text_dec_len;
	mk_lang_types_uint_t m_mantissa_text_dcd_len;
	mk_lang_types_uint_t m_value_len;
	mk_lang_types_pchar_t m_all_text_bin_buf[mk_lib_float_analyzer_inl_defd_cui_all_strlen_bin_v];
	mk_lang_types_pchar_t m_all_text_hex_buf[mk_lib_float_analyzer_inl_defd_cui_all_strlen_hex_v];
	mk_lang_types_pchar_t m_all_text_dec_buf[mk_lib_float_analyzer_inl_defd_cui_all_strlen_dec_v];
	mk_lang_types_pchar_t m_all_text_sgn_buf[1 + mk_lib_float_analyzer_inl_defd_cui_all_strlen_dec_v];
	mk_lang_types_pchar_t m_sign_text_buf[mk_lang_max(mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_sign_positive), mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_sign_negative))];
	mk_lang_types_pchar_t m_exponent_text_bin_buf[mk_lib_float_analyzer_inl_defd_cui_exponent_strlen_bin_v];
	mk_lang_types_pchar_t m_exponent_text_hex_buf[mk_lib_float_analyzer_inl_defd_cui_exponent_strlen_hex_v];
	mk_lang_types_pchar_t m_exponent_text_dec_buf[mk_lib_float_analyzer_inl_defd_cui_exponent_strlen_dec_v];
	mk_lang_types_pchar_t m_exponent_text_decoded_buf[mk_lang_max(mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_na), 1 + mk_lib_float_analyzer_inl_defd_cui_exponent_strlen_dec_v)];
	mk_lang_types_pchar_t m_exponent_text_type_buf[mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(mk_lang_max(1, mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_denormal)), mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_infinity)), mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_nan)), mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_normal)), mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_type_zero))];
	mk_lang_types_pchar_t m_exponent_text_implied_one_buf[mk_lang_max(mk_lang_max(mk_lang_max(1, mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_na)), mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_no)), mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_exponent_implied_one_yes))];
	mk_lang_types_pchar_t m_mantissa_text_bin_buf[mk_lib_float_analyzer_inl_defd_cui_mantissa_strlen_bin_v];
	mk_lang_types_pchar_t m_mantissa_text_hex_buf[mk_lib_float_analyzer_inl_defd_cui_mantissa_strlen_hex_v];
	mk_lang_types_pchar_t m_mantissa_text_dec_buf[mk_lib_float_analyzer_inl_defd_cui_mantissa_strlen_dec_v];
	mk_lang_types_pchar_t m_mantissa_text_dcd_buf[mk_lang_max(mk_lang_max(3, mk_lang_countstr(mk_lib_float_analyzer_inl_defd_text_mantissa_na)), mk_lib_float_analyzer_inl_defd_cui_mantissa_fraction_max_len_d)];
	mk_lang_types_pchar_t m_value_buf[mk_lib_float_analyzer_inl_defd_cui_value_max_len_d];
};
typedef struct mk_lib_float_analyzer_inl_defd_s mk_lib_float_analyzer_inl_defd_t;
mk_lang_typedef(mk_lib_float_analyzer_inl_defd);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_float_analyzer_inl_defd_analyze(mk_lib_float_analyzer_inl_defd_pt const analyzer) mk_lang_noexcept;


#include "mk_lib_float_analyzer_inl_defu.h"
