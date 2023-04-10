#include "mk_lang_concat.h"
#include "mk_lang_endian.h"


#define mk_sl_cui_convert_inl_defd_a_name mk_sl_cui_convert_a_name
#define mk_sl_cui_convert_inl_defd_a_base_type mk_sl_cui_convert_a_base_type
#define mk_sl_cui_convert_inl_defd_a_base_name mk_sl_cui_convert_a_base_name
#define mk_sl_cui_convert_inl_defd_a_base_bits mk_sl_cui_convert_a_base_bits
#define mk_sl_cui_convert_inl_defd_a_count mk_sl_cui_convert_a_count
#define mk_sl_cui_convert_inl_defd_a_endian mk_sl_cui_convert_a_endian
#define mk_sl_cui_convert_inl_defd_a_base_is_bui mk_sl_cui_convert_a_base_is_bui
#define mk_sl_cui_convert_inl_defd_a_base_bui_tn mk_sl_cui_convert_a_base_bui_tn
#define mk_sl_cui_convert_inl_defd_a_t mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_convert_a_name), _t)
#define mk_sl_cui_convert_inl_defd_a_base_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_convert_inl_defd_a_base_bui_tn), _t)
#if mk_sl_cui_convert_inl_defd_a_endian == mk_lang_endian_little
#define mk_sl_cui_convert_inl_defd_a_idx(x) (x)
#elif mk_sl_cui_convert_inl_defd_a_endian == mk_lang_endian_big
#define mk_sl_cui_convert_inl_defd_a_idx(x) ((mk_sl_cui_convert_inl_defd_a_count - 1) - (x))
#endif

#define mk_sl_cui_convert_inl_defd_b_name mk_sl_cui_convert_b_name
#define mk_sl_cui_convert_inl_defd_b_base_type mk_sl_cui_convert_b_base_type
#define mk_sl_cui_convert_inl_defd_b_base_name mk_sl_cui_convert_b_base_name
#define mk_sl_cui_convert_inl_defd_b_base_bits mk_sl_cui_convert_b_base_bits
#define mk_sl_cui_convert_inl_defd_b_count mk_sl_cui_convert_b_count
#define mk_sl_cui_convert_inl_defd_b_endian mk_sl_cui_convert_b_endian
#define mk_sl_cui_convert_inl_defd_b_base_is_bui mk_sl_cui_convert_b_base_is_bui
#define mk_sl_cui_convert_inl_defd_b_base_bui_tn mk_sl_cui_convert_b_base_bui_tn
#define mk_sl_cui_convert_inl_defd_b_t mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_convert_b_name), _t)
#define mk_sl_cui_convert_inl_defd_b_base_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_convert_inl_defd_b_base_bui_tn), _t)
#if mk_sl_cui_convert_inl_defd_b_endian == mk_lang_endian_little
#define mk_sl_cui_convert_inl_defd_b_idx(x) (x)
#elif mk_sl_cui_convert_inl_defd_b_endian == mk_lang_endian_big
#define mk_sl_cui_convert_inl_defd_b_idx(x) ((mk_sl_cui_convert_inl_defd_b_count - 1) - (x))
#endif

#define mk_sl_cui_convert_inl_defd_fn_a_to_b mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_sl_cui_convert_, mk_sl_cui_convert_a_name), _to_), mk_sl_cui_convert_b_name)
