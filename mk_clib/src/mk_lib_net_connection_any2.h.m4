include(`mk_lib_net_connection_any.m')dnl
dnl
dnl
#ifndef mk_include_guard_mk_lib_net_connection_any2_h
#define mk_include_guard_mk_lib_net_connection_any2_h

#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_net_connection_any1.h"
#include "mk_sl_cui_uint8.h"

mk_lib_net_connection_any_mm_per_type(`#include "$1.h"', `
')


#include "mk_lang_warning_msvc_push_c4820.h"
mk_lib_net_connection_any_mm_per_type(`struct mk_lib_net_connection_any2_$1_s{ mk_lib_net_connection_any1_id_t m_id; $1_t m_$1; }; typedef struct mk_lib_net_connection_any2_$1_s mk_lib_net_connection_any2_$1_t; mk_lang_typedef(mk_lib_net_connection_any2_$1);', `
')
#include "mk_lang_warning_msvc_pop.h"


union mk_lib_net_connection_any2_data_u
{
	mk_lib_net_connection_any1_id_t m_id;
mk_lib_net_connection_any_mm_per_type(`	mk_lib_net_connection_any2_$1_t m_$1;', `
')
};
typedef union mk_lib_net_connection_any2_data_u mk_lib_net_connection_any2_data_t;
struct mk_lib_net_connection_any2_s
{
	mk_lib_net_connection_any2_data_t m_data;
};
typedef struct mk_lib_net_connection_any2_s mk_lib_net_connection_any2_t;
mk_lang_typedef(mk_lib_net_connection_any2);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connection_any2_rw_construct(mk_lib_net_connection_any2_pt const hash_stream_any2, mk_lib_net_connection_any1_id_t const id, mk_lang_types_void_pct const settings) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connection_any2_rw_destroy(mk_lib_net_connection_any2_pt const hash_stream_any2) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_net_connection_any2.c"
#endif
#endif
