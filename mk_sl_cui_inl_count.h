#include "mk_sl_cui_inl_count_default.h"
#include "mk_lang_endian.h"


#define mk_sl_cui_inl_endian mk_lang_endian_little
#include "mk_sl_cui_inl_endian.h"

#define mk_sl_cui_inl_endian mk_lang_endian_big
#include "mk_sl_cui_inl_endian.h"


#undef mk_sl_cui_inl_count_default


#undef mk_sl_cui_inl_count
