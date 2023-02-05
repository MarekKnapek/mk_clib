#include "mk_lang_bi.h"
#include "mk_lang_concat.h"
#include "mk_lang_sizeof.h"


#define mk_sl_cui_inl_to_bi_inl_def_bit mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_to_bi_inl_btn), _t)
#define mk_sl_cui_inl_to_bi_inl_def_sizeof_bit mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_sl_cui_inl_to_bi_inl_btn), _t)
#define mk_sl_cui_inl_to_bi_inl_def_is_unsigned_bit mk_lang_concat(mk_lang_concat(mk_lang_bi_is_unsigned_, mk_sl_cui_inl_to_bi_inl_btn), _t)
#define mk_sl_cui_inl_to_bi_inl_def_to_unsigned_bit mk_lang_concat(mk_lang_concat(mk_lang_bi_to_unsigned_, mk_sl_cui_inl_to_bi_inl_btn), _t)
#define mk_sl_cui_inl_to_bi_inl_def_fn mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _to_bi_), mk_sl_cui_inl_to_bi_inl_btn)
