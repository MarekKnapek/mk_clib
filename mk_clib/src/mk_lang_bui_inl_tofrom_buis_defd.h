#include "mk_lang_bi.h"
#include "mk_lang_concat.h"
#include "mk_lang_div_roundup.h"


#define mk_lang_bui_inl_tofrom_buis_defd_bui_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_forb_bui_tn), _t)
#define mk_lang_bui_inl_tofrom_buis_defd_fn_to mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_, mk_lang_bui_inl_defd_name), _to_buis_), mk_lang_forb_bui_tn), _), mk_lang_forb_endian_name)
#define mk_lang_bui_inl_tofrom_buis_defd_fn_from mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_, mk_lang_bui_inl_defd_name), _from_buis_), mk_lang_forb_bui_tn), _), mk_lang_forb_endian_name)
#define mk_lang_bui_inl_tofrom_buis_defd_sizeof_bui_t mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_forb_bui_tn), _t)
#define mk_lang_bui_inl_tofrom_buis_defd_count mk_lang_div_roundup(mk_lang_bui_inl_defd_sizeof, mk_lang_bui_inl_tofrom_buis_defd_sizeof_bui_t)
#if mk_lang_forb_endian_value == mk_lang_endian_little
#define mk_lang_bui_inl_tofrom_buis_defd_idx(x) (x)
#else mk_lang_forb_endian_value == mk_lang_endian_big
#define mk_lang_bui_inl_tofrom_buis_defd_idx(x) (x)
#endif
