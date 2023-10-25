#include "mk_sl_uint16.h"

#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#if mk_lang_charbit == 8 && mk_lang_sizeof_bi_ushort_t == 2

#define mk_lang_bui_t_name mk_sl_cui_uint16_base_helper
#define mk_lang_bui_t_base ushort
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_t_name mk_sl_cui_uint16
#define mk_sl_cui_t_base mk_sl_cui_uint16_base_helper
#define mk_sl_cui_t_count (16 / mk_sl_cui_uint16_base_helper_sizebits_d)
#include "mk_sl_cui_inl_filec.h"

#endif
