#include "mk_lang_concat.h"


#if !defined mk_sl_cui_n
#define mk_sl_cui_n zzzzzzzzzz2
#endif
#include "mk_sl_cui_inl_def.h"


#if !defined mk_sl_cui_inl_to_buis_be_btn && !defined mk_sl_cui_inl_to_buis_be_n
#define mk_sl_cui_inl_to_buis_be_btn uint
#define mk_sl_cui_inl_to_buis_be_n zzzzzzzzzz
#endif
#if !defined mk_sl_cui_inl_to_buis_be_n
#define mk_sl_cui_inl_to_buis_be_n mk_sl_cui_inl_to_buis_be_btn
#endif


#define mk_lang_sizeof_bui_t mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_sl_cui_btn), _t)
#define mk_lang_sizeof_to_buis_be_t mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_sl_cui_inl_to_buis_be_btn), _t)
#define mk_sl_cui_inl_to_buis_be_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_to_buis_be_btn), _t)
#define mk_sl_cui_inl_to_buis_be_fn mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_n), _to_buis_), mk_sl_cui_inl_to_buis_be_n), _be)
