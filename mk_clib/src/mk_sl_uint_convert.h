#ifndef mk_include_guard_mk_sl_uint_convert_h
#define mk_include_guard_mk_sl_uint_convert_h


#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_sl_cui_uint128.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"


#define mk_sl_uint_convert_t_name mk_sl_uint_convert_16_8_le
#define mk_sl_uint_convert_t_big_tn mk_sl_cui_uint16
#define mk_sl_uint_convert_t_sml_tn mk_sl_cui_uint8
#define mk_sl_uint_convert_t_endian mk_lang_endian_little
#include "mk_sl_uint_convert_inl_fileh.h"
#include "mk_sl_uint_convert_inl_fileu.h"

#define mk_sl_uint_convert_t_name mk_sl_uint_convert_16_8_be
#define mk_sl_uint_convert_t_big_tn mk_sl_cui_uint16
#define mk_sl_uint_convert_t_sml_tn mk_sl_cui_uint8
#define mk_sl_uint_convert_t_endian mk_lang_endian_big
#include "mk_sl_uint_convert_inl_fileh.h"
#include "mk_sl_uint_convert_inl_fileu.h"

#define mk_sl_uint_convert_t_name mk_sl_uint_convert_32_8_le
#define mk_sl_uint_convert_t_big_tn mk_sl_cui_uint32
#define mk_sl_uint_convert_t_sml_tn mk_sl_cui_uint8
#define mk_sl_uint_convert_t_endian mk_lang_endian_little
#include "mk_sl_uint_convert_inl_fileh.h"
#include "mk_sl_uint_convert_inl_fileu.h"

#define mk_sl_uint_convert_t_name mk_sl_uint_convert_32_8_be
#define mk_sl_uint_convert_t_big_tn mk_sl_cui_uint32
#define mk_sl_uint_convert_t_sml_tn mk_sl_cui_uint8
#define mk_sl_uint_convert_t_endian mk_lang_endian_big
#include "mk_sl_uint_convert_inl_fileh.h"
#include "mk_sl_uint_convert_inl_fileu.h"

#define mk_sl_uint_convert_t_name mk_sl_uint_convert_64_8_le
#define mk_sl_uint_convert_t_big_tn mk_sl_cui_uint64
#define mk_sl_uint_convert_t_sml_tn mk_sl_cui_uint8
#define mk_sl_uint_convert_t_endian mk_lang_endian_little
#include "mk_sl_uint_convert_inl_fileh.h"
#include "mk_sl_uint_convert_inl_fileu.h"

#define mk_sl_uint_convert_t_name mk_sl_uint_convert_64_8_be
#define mk_sl_uint_convert_t_big_tn mk_sl_cui_uint64
#define mk_sl_uint_convert_t_sml_tn mk_sl_cui_uint8
#define mk_sl_uint_convert_t_endian mk_lang_endian_big
#include "mk_sl_uint_convert_inl_fileh.h"
#include "mk_sl_uint_convert_inl_fileu.h"

#define mk_sl_uint_convert_t_name mk_sl_uint_convert_128_8_le
#define mk_sl_uint_convert_t_big_tn mk_sl_cui_uint128
#define mk_sl_uint_convert_t_sml_tn mk_sl_cui_uint8
#define mk_sl_uint_convert_t_endian mk_lang_endian_little
#include "mk_sl_uint_convert_inl_fileh.h"
#include "mk_sl_uint_convert_inl_fileu.h"

#define mk_sl_uint_convert_t_name mk_sl_uint_convert_128_8_be
#define mk_sl_uint_convert_t_big_tn mk_sl_cui_uint128
#define mk_sl_uint_convert_t_sml_tn mk_sl_cui_uint8
#define mk_sl_uint_convert_t_endian mk_lang_endian_big
#include "mk_sl_uint_convert_inl_fileh.h"
#include "mk_sl_uint_convert_inl_fileu.h"

#define mk_sl_uint_convert_t_name mk_sl_uint_convert_64_32_le
#define mk_sl_uint_convert_t_big_tn mk_sl_cui_uint64
#define mk_sl_uint_convert_t_sml_tn mk_sl_cui_uint32
#define mk_sl_uint_convert_t_endian mk_lang_endian_little
#include "mk_sl_uint_convert_inl_fileh.h"
#include "mk_sl_uint_convert_inl_fileu.h"

#define mk_sl_uint_convert_t_name mk_sl_uint_convert_64_32_be
#define mk_sl_uint_convert_t_big_tn mk_sl_cui_uint64
#define mk_sl_uint_convert_t_sml_tn mk_sl_cui_uint32
#define mk_sl_uint_convert_t_endian mk_lang_endian_big
#include "mk_sl_uint_convert_inl_fileh.h"
#include "mk_sl_uint_convert_inl_fileu.h"

#define mk_sl_uint_convert_t_name mk_sl_uint_convert_128_64_le
#define mk_sl_uint_convert_t_big_tn mk_sl_cui_uint128
#define mk_sl_uint_convert_t_sml_tn mk_sl_cui_uint64
#define mk_sl_uint_convert_t_endian mk_lang_endian_little
#include "mk_sl_uint_convert_inl_fileh.h"
#include "mk_sl_uint_convert_inl_fileu.h"

#define mk_sl_uint_convert_t_name mk_sl_uint_convert_128_64_be
#define mk_sl_uint_convert_t_big_tn mk_sl_cui_uint128
#define mk_sl_uint_convert_t_sml_tn mk_sl_cui_uint64
#define mk_sl_uint_convert_t_endian mk_lang_endian_big
#include "mk_sl_uint_convert_inl_fileh.h"
#include "mk_sl_uint_convert_inl_fileu.h"


#if mk_lang_jumbo_have == 1
#include "mk_sl_uint_convert.c"
#endif
#endif
