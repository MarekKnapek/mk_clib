#include "mk_sl_uint256.h"

#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_types.h"


#if mk_lang_charbit == 8 && mk_lang_sizeof_bi_ulllong_t == 16

#define mk_lang_bui_name mk_sl_uint256_ulllong
#define mk_lang_bui_type mk_lang_types_ulllong_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_ulllong_t
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_name uint256
#define mk_sl_cui_base_type mk_lang_types_ulllong_t
#define mk_sl_cui_base_name mk_lang_bui_mk_sl_uint256_ulllong
#define mk_sl_cui_base_bits 128
#define mk_sl_cui_count (256 / 128)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn ulllong
#include "mk_sl_cui_inl_filec.h"

#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_ulong_t == 8

#define mk_lang_bui_name mk_sl_uint256_ulong
#define mk_lang_bui_type mk_lang_types_ulong_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_ulong_t
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_name uint256
#define mk_sl_cui_base_type mk_lang_types_ulong_t
#define mk_sl_cui_base_name mk_lang_bui_mk_sl_uint256_ulong
#define mk_sl_cui_base_bits 64
#define mk_sl_cui_count (256 / 64)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn ulong
#include "mk_sl_cui_inl_filec.h"

#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_ullong_t == 8

#define mk_lang_bui_name mk_sl_uint256_ullong
#define mk_lang_bui_type mk_lang_types_ullong_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_ullong_t
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_name uint256
#define mk_sl_cui_base_type mk_lang_types_ullong_t
#define mk_sl_cui_base_name mk_lang_bui_mk_sl_uint256_ullong
#define mk_sl_cui_base_bits 64
#define mk_sl_cui_count (256 / 64)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn ullong
#include "mk_sl_cui_inl_filec.h"

#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_uint_t == 4

#define mk_lang_bui_name mk_sl_uint256_uint
#define mk_lang_bui_type mk_lang_types_uint_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uint_t
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_name uint256
#define mk_sl_cui_base_type mk_lang_types_uint_t
#define mk_sl_cui_base_name mk_lang_bui_mk_sl_uint256_uint
#define mk_sl_cui_base_bits 32
#define mk_sl_cui_count (256 / 32)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uint
#include "mk_sl_cui_inl_filec.h"

#elif mk_lang_charbit == 8 && mk_lang_sizeof_bi_ulong_t == 4

#define mk_lang_bui_name mk_sl_uint256_ulong
#define mk_lang_bui_type mk_lang_types_ulong_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_ulong_t
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_name uint256
#define mk_sl_cui_base_type mk_lang_types_ulong_t
#define mk_sl_cui_base_name mk_lang_bui_mk_sl_uint256_ulong
#define mk_sl_cui_base_bits 32
#define mk_sl_cui_count (256 / 32)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn ulong
#include "mk_sl_cui_inl_filec.h"

#endif
