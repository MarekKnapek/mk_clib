#include "mk_lang_concat.h"


#if !defined mk_lang_bui_n
#define mk_lang_bui_n zzzzzzzzzz2
#endif
#include "mk_lang_bui_inl_def.h"


#if !defined mk_lang_bui_inl_to_bi_btn && !defined mk_lang_bui_inl_to_bi_n
#define mk_lang_bui_inl_to_bi_btn uint
#define mk_lang_bui_inl_to_bi_n zzzzzzzzzz
#endif
#if !defined mk_lang_bui_inl_to_bi_n
#define mk_lang_bui_inl_to_bi_n mk_lang_bui_inl_to_bi_btn
#endif


#define mk_lang_bui_inl_to_bi_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_bui_inl_to_bi_btn), _t)
#define mk_lang_bui_inl_to_bi_fn mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_, mk_lang_bui_n), _to_bi_), mk_lang_bui_inl_to_bi_n)
