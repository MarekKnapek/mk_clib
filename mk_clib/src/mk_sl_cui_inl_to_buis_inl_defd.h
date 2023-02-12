#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_max.h"
#include "mk_lang_sizeof.h"


#define mk_sl_cui_inl_to_buis_inl_defd_fn mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _to_buis_), mk_lang_for_bui_tn), _), mk_lang_for_endian_name)
#define mk_sl_cui_inl_to_buis_inl_defd_bui_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_for_bui_tn), _t)
#define mk_sl_cui_inl_to_buis_inl_defd_bits_bui_t (mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_for_bui_tn), _t) * mk_lang_charbit)
#define mk_sl_cui_inl_to_buis_inl_defd_bits_cui (mk_sl_cui_inl_def_count * mk_sl_cui_inl_def_base_bits)
#define mk_sl_cui_inl_to_buis_inl_defd_count mk_lang_max(1, mk_lang_div_roundup(mk_sl_cui_inl_to_buis_inl_defd_bits_cui, mk_sl_cui_inl_to_buis_inl_defd_bits_bui_t))
#define mk_sl_cui_inl_to_buis_inl_defd_base_to_buis mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_sl_cui_inl_def_base_name, _to_buis_), mk_lang_for_bui_tn), _), mk_lang_for_endian_name)

#if mk_lang_for_endian_value == mk_lang_endian_little
#define mk_sl_cui_inl_to_buis_inl_defd_idx(x) (x)
#elif mk_lang_for_endian_value == mk_lang_endian_big
#define mk_sl_cui_inl_to_buis_inl_defd_idx(x) ((mk_sl_cui_inl_def_count - 1) - (x))
#endif
#if mk_lang_for_endian_value == mk_lang_endian_little
#define mk_sl_cui_inl_to_buis_inl_defd_idx2(x) (x * (mk_sl_cui_inl_def_base_bits / mk_sl_cui_inl_to_buis_inl_defd_bits_bui_t))
#elif mk_lang_for_endian_value == mk_lang_endian_big
#define mk_sl_cui_inl_to_buis_inl_defd_idx2(x) ((mk_sl_cui_inl_def_count * (mk_sl_cui_inl_def_base_bits / mk_lang_charbit)) - (((x) + 1) * (mk_sl_cui_inl_def_base_bits / mk_sl_cui_inl_to_buis_inl_defd_bits_bui_t)))
#endif
