#include "mk_win_sl_tdw.h"

#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_win_base.h"


#define mk_lang_bui_name wtdw
#define mk_lang_bui_type mk_win_base_dword_t
#define mk_lang_bui_sizeof mk_win_base_sizeof_dword_t
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_name wtdw
#define mk_sl_cui_base_type mk_win_base_dword_t
#define mk_sl_cui_base_name mk_lang_bui_wtdw
#define mk_sl_cui_base_bits (mk_win_base_sizeof_dword_t * mk_lang_charbit)
#define mk_sl_cui_count 2
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uint
#include "mk_sl_cui_inl_filec.h"


#undef mk_lang_bui_name
#undef mk_lang_bui_type
#undef mk_lang_bui_sizeof

#undef mk_sl_cui_name
#undef mk_sl_cui_base_type
#undef mk_sl_cui_base_name
#undef mk_sl_cui_base_bits
#undef mk_sl_cui_count
#undef mk_sl_cui_endian
#undef mk_sl_cui_base_is_bui
#undef mk_sl_cui_base_bui_tn
