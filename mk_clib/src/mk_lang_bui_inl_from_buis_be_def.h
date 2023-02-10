#include "mk_lang_concat.h"


#if !defined mk_lang_bui_n
#define mk_lang_bui_n zzzzzzzzzz2
#endif
#include "mk_lang_bui_inl_def.h"


#if !defined mk_lang_bui_inl_from_buis_be_btn && !defined mk_lang_bui_inl_from_buis_be_n
#define mk_lang_bui_inl_from_buis_be_btn uint
#define mk_lang_bui_inl_from_buis_be_n zzzzzzzzzz
#endif
#if !defined mk_lang_bui_inl_from_buis_be_n
#define mk_lang_bui_inl_from_buis_be_n mk_lang_bui_inl_from_buis_be_btn
#endif


#define mk_lang_sizeof_bui_t mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_bui_btn), _t)
#define mk_lang_sizeof_from_buis_be_t mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_bui_inl_from_buis_be_btn), _t)
#define mk_lang_bui_inl_from_buis_be_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_bui_inl_from_buis_be_btn), _t)
#define mk_lang_bui_inl_from_buis_be_fn mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_, mk_lang_bui_n), _from_buis_), mk_lang_bui_inl_from_buis_be_n), _be)
