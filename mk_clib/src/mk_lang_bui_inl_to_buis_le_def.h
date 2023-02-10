#include "mk_lang_concat.h"


#if !defined mk_lang_bui_n
#define mk_lang_bui_n zzzzzzzzzz2
#endif
#include "mk_lang_bui_inl_def.h"


#if !defined mk_lang_bui_inl_to_buis_le_btn && !defined mk_lang_bui_inl_to_buis_le_n
#define mk_lang_bui_inl_to_buis_le_btn uint
#define mk_lang_bui_inl_to_buis_le_n zzzzzzzzzz
#endif
#if !defined mk_lang_bui_inl_to_buis_le_n
#define mk_lang_bui_inl_to_buis_le_n mk_lang_bui_inl_to_buis_le_btn
#endif


#define mk_lang_sizeof_bui_t mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_bui_btn), _t)
#define mk_lang_sizeof_to_buis_le_t mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_bui_inl_to_buis_le_btn), _t)
#define mk_lang_bui_inl_to_buis_le_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_bui_inl_to_buis_le_btn), _t)
#define mk_lang_bui_inl_to_buis_le_fn mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_, mk_lang_bui_n), _to_buis_), mk_lang_bui_inl_to_buis_le_n), _le)
