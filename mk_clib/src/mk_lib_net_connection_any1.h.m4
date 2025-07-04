include(`mk_lib_net_connection_any.m')dnl
dnl
dnl
#ifndef mk_include_guard_mk_lib_net_connection_any1_h
#define mk_include_guard_mk_lib_net_connection_any1_h

#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


mk_lib_net_connection_any_mm_per_type(`mk_lang_forward($1);', `
')


enum mk_lib_net_connection_any1_id_e
{
mk_lib_net_connection_any_mm_per_type(`	mk_lib_net_connection_any1_id_e_$1,', `
')
	mk_lib_net_connection_any1_id_e_dummy_end
};
typedef enum mk_lib_net_connection_any1_id_e mk_lib_net_connection_any1_id_t;


union mk_lib_net_connection_any1_bare_data_u
{
mk_lib_net_connection_any_mm_per_type(`	$1_pt m_$1;', `
')
};
typedef union mk_lib_net_connection_any1_bare_data_u mk_lib_net_connection_any1_bare_data_t;
struct mk_lib_net_connection_any1_bare_s
{
	mk_lib_net_connection_any1_bare_data_t m_data;
};
typedef struct mk_lib_net_connection_any1_bare_s mk_lib_net_connection_any1_bare_t;
mk_lang_typedef(mk_lib_net_connection_any1_bare);


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_connection_any1_ptrid_s
{
	mk_lib_net_connection_any1_id_t m_id;
	mk_lib_net_connection_any1_bare_t m_ptr;
};
typedef struct mk_lib_net_connection_any1_ptrid_s mk_lib_net_connection_any1_ptrid_t;
mk_lang_typedef(mk_lib_net_connection_any1_ptrid);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_pchar_pct mk_lib_net_connection_any1_get_str_buf(mk_lib_net_connection_any1_id_t const id) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connection_any1_get_str_len(mk_lib_net_connection_any1_id_t const id) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connection_any1_bare_rw_construct(mk_lib_net_connection_any1_bare_pt const hash_stream_any1_bare, mk_lib_net_connection_any1_id_t const id, mk_lang_types_void_pct const settings) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connection_any1_bare_rw_destroy(mk_lib_net_connection_any1_bare_pt const hash_stream_any1_bare, mk_lib_net_connection_any1_id_t const id) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connection_any1_ptrid_rw_construct(mk_lib_net_connection_any1_ptrid_pt const hash_stream_any1_ptrid, mk_lib_net_connection_any1_id_t const id, mk_lang_types_void_pct const settings) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connection_any1_ptrid_rw_destroy(mk_lib_net_connection_any1_ptrid_pt const hash_stream_any1_ptrid) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_net_connection_any1.c"
#endif
#endif
