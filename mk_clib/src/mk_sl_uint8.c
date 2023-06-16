#include "mk_sl_uint8.h"

#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_types.h"


#if mk_lang_charbit == 8 && mk_lang_sizeof_bi_uchar_t == 1

#define mk_lang_bui_name mk_sl_uint8_uchar
#define mk_lang_bui_type mk_lang_types_uchar_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uchar_t
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_name uint8
#define mk_sl_cui_base_type mk_lang_types_uchar_t
#define mk_sl_cui_base_name mk_lang_bui_mk_sl_uint8_uchar
#define mk_sl_cui_base_bits 8
#define mk_sl_cui_count (8 / 8)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uchar
#include "mk_sl_cui_inl_filec.h"

#endif
