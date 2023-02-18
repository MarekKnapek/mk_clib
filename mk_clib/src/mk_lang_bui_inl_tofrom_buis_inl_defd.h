#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_concat.h"
#include "mk_lang_div_roundup.h"


#define mk_lang_bui_inl_tofrom_buis_inl_defd_bui_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_concat(mk_lang_bui_inl_tofrom_buis_for_bui, _tn)), _t)
#define mk_lang_bui_inl_tofrom_buis_inl_defd_fn_to mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_, mk_lang_bui_inl_defd_name), _to_buis_), mk_lang_concat(mk_lang_bui_inl_tofrom_buis_for_bui, _tn)), _), mk_lang_concat(mk_lang_bui_inl_tofrom_buis_for_endian, _name))
#define mk_lang_bui_inl_tofrom_buis_inl_defd_fn_from mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_, mk_lang_bui_inl_defd_name), _from_buis_), mk_lang_concat(mk_lang_bui_inl_tofrom_buis_for_bui, _tn)), _), mk_lang_concat(mk_lang_bui_inl_tofrom_buis_for_endian, _name))
#define mk_lang_bui_inl_tofrom_buis_inl_defd_sizeof_bui_t mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_concat(mk_lang_bui_inl_tofrom_buis_for_bui, _tn)), _t)
#define mk_lang_bui_inl_tofrom_buis_inl_defd_count mk_lang_div_roundup(mk_lang_bui_inl_defd_sizeof, mk_lang_bui_inl_tofrom_buis_inl_defd_sizeof_bui_t)
#define mk_lang_bui_inl_tofrom_buis_inl_defd_idx(x) ((mk_lang_concat(mk_lang_bui_inl_tofrom_buis_for_endian, _value) == mk_lang_endian_little) ? (x) : ((mk_lang_concat(mk_lang_bui_inl_tofrom_buis_for_endian, _value) == mk_lang_endian_big) ? (((mk_lang_bui_inl_tofrom_buis_inl_defd_count) - 1) - (x)) : (mk_lang_assert(0), -1)))


#define mk_lang_bui_inl_tofrom_buis_for_bui mk_lang_forb_bui
#define mk_lang_bui_inl_tofrom_buis_for_endian mk_lang_forb_endian
