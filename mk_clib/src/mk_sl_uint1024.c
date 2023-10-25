#include "mk_sl_uint1024.h"

#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"


#if mk_lang_charbit == 8 && mk_lang_sizeof_bi_ulllong_t == 16

#define mk_lang_bui_t_name mk_sl_cui_uint1024_base_helper
#define mk_lang_bui_t_base ulllong
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_t_name mk_sl_cui_uint1024
#define mk_sl_cui_t_base mk_sl_cui_uint1024_base_helper
#define mk_sl_cui_t_count (1024 / mk_sl_cui_uint1024_base_helper_sizebits_d)
#include "mk_sl_cui_inl_filec.h"

#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_ulong_t == 8

#define mk_lang_bui_t_name mk_sl_cui_uint1024_base_helper
#define mk_lang_bui_t_base ulong
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_t_name mk_sl_cui_uint1024
#define mk_sl_cui_t_base mk_sl_cui_uint1024_base_helper
#define mk_sl_cui_t_count (1024 / mk_sl_cui_uint1024_base_helper_sizebits_d)
#include "mk_sl_cui_inl_filec.h"

#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_ullong_t == 8

#define mk_lang_bui_t_name mk_sl_cui_uint1024_base_helper
#define mk_lang_bui_t_base ullong
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_t_name mk_sl_cui_uint1024
#define mk_sl_cui_t_base mk_sl_cui_uint1024_base_helper
#define mk_sl_cui_t_count (1024 / mk_sl_cui_uint1024_base_helper_sizebits_d)
#include "mk_sl_cui_inl_filec.h"

#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_uint_t == 4

#define mk_lang_bui_t_name mk_sl_cui_uint1024_base_helper
#define mk_lang_bui_t_base uint
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_t_name mk_sl_cui_uint1024
#define mk_sl_cui_t_base mk_sl_cui_uint1024_base_helper
#define mk_sl_cui_t_count (1024 / mk_sl_cui_uint1024_base_helper_sizebits_d)
#include "mk_sl_cui_inl_filec.h"

#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_ulong_t == 4

#define mk_lang_bui_t_name mk_sl_cui_uint1024_base_helper
#define mk_lang_bui_t_base ulong
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_t_name mk_sl_cui_uint1024
#define mk_sl_cui_t_base mk_sl_cui_uint1024_base_helper
#define mk_sl_cui_t_count (1024 / mk_sl_cui_uint1024_base_helper_sizebits_d)
#include "mk_sl_cui_inl_filec.h"

#endif
