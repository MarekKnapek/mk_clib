#include "mk_lang_concat.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_max.h"
#include "mk_lang_pow.h"


#define mk_sl_flt_defd_name mk_sl_flt_name
#define mk_sl_flt_defd_bits mk_sl_flt_bits
#define mk_sl_flt_defd_fraction_bits mk_sl_flt_fraction_bits
#define mk_sl_flt_defd_exponent_bits (mk_sl_flt_defd_bits - 1 - mk_sl_flt_defd_fraction_bits)
#define mk_sl_flt_defd_exponent_bias (mk_lang_pow(2, mk_sl_flt_defd_exponent_bits - 1) - 1)
#define mk_sl_flt_defd_exponent_encoded_min 0
#define mk_sl_flt_defd_exponent_encoded_max (mk_lang_pow(2, mk_sl_flt_defd_exponent_bits) - 1)
#define mk_sl_flt_defd_exponent_decoded_min ((mk_sl_flt_defd_exponent_encoded_min + 1) - mk_sl_flt_defd_exponent_bias)
#define mk_sl_flt_defd_exponent_decoded_max ((mk_sl_flt_defd_exponent_encoded_max - 1) - mk_sl_flt_defd_exponent_bias)
#define mk_sl_flt_defd_need_bits_a (1 + mk_sl_flt_defd_exponent_decoded_max)
#define mk_sl_flt_defd_need_bits_b (mk_sl_flt_defd_fraction_bits + (-mk_sl_flt_defd_exponent_decoded_min))
#define mk_sl_flt_defd_needs_symbols_10_a (((mk_sl_flt_defd_need_bits_a * 19728ul) >> 16) + 1)
#define mk_sl_flt_defd_needs_symbols_10_b ((-mk_sl_flt_defd_exponent_decoded_min) + mk_sl_flt_defd_fraction_bits)
#define mk_sl_flt_defd_needs_symbols_10 (1 + mk_lang_max(mk_sl_flt_defd_needs_symbols_10_a, mk_sl_flt_defd_needs_symbols_10_b) + 2)

#define mk_sl_flt_defd_to_string_dec_basic_len_e mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), _to_string_dec_basic_len_e)
#define mk_sl_flt_defd_to_string_dec_basic_len_t mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), _to_string_dec_basic_len_t)
#define mk_sl_flt_defd_to_string_dec_basic_len_v mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), _to_string_dec_basic_len_v)
#define mk_sl_flt_defd_to_string_dec_basic_len_n ((int)(mk_sl_flt_defd_needs_symbols_10))
#define mk_sl_flt_defd_to_string_dec_basic_n mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), _to_string_dec_basic_n)
