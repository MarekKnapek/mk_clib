#include "mk_sl_uint8.h"

#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#if mk_lang_charbit == 8 && mk_lang_sizeof_bi_uchar_t == 1

#define mk_lang_bui_t_name mk_sl_cui_uint8_base_helper
#define mk_lang_bui_t_base uchar
#define mk_lang_bui_t_inline 1
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_t_name mk_sl_cui_uint8
#define mk_sl_cui_t_base mk_sl_cui_uint8_base_helper
#define mk_sl_cui_t_count (8 / mk_sl_cui_uint8_base_helper_sizebits_d)
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"

#endif
