include(`mk_lib_net_connection_any.m')dnl
dnl
dnl
#ifndef mk_include_guard_mk_lib_net_connection_any1_c
#define mk_include_guard_mk_lib_net_connection_any1_c
#include "mk_lib_net_connection_any1.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_sl_cui_uint8.h"

mk_lib_net_connection_any_mm_per_type(`#include "$1.h"', `
')


#define mk_lib_net_connection_any1_strs_def_bufs \
mk_lib_net_connection_any_mm_per_type(`	"$1" \', `
')

#define mk_lib_net_connection_any1_strs_def_lens \
{ \
mk_lib_net_connection_any_mm_per_type(`	mk_lang_countstr("$1"), \', `
')
}

#define mk_lib_net_connection_any1_strs_def_sum(x) \
mk_lib_net_connection_any_mm_per_type(`	mk_lang_countstr("$1") * (((x) >= $2) ? 1 : 0) + \', `
')
	0

#define mk_lib_net_connection_any1_strs_def_sums \
{ \
	mk_lib_net_connection_any1_strs_def_sum(-1), \
mk_lib_net_connection_any_mm_per_type(`	mk_lib_net_connection_any1_strs_def_sum($2), \', `
')
}


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_net_connection_any1_strs_bufs[] = mk_lib_net_connection_any1_strs_def_bufs;
/*mk_lang_constexpr_static_inline mk_lang_types_uchar_t const mk_lib_net_connection_any1_strs_lens[] = mk_lib_net_connection_any1_strs_def_lens;*/
mk_lang_constexpr_static_inline mk_lang_types_sint_t  const mk_lib_net_connection_any1_strs_sums[] = mk_lib_net_connection_any1_strs_def_sums;


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_pchar_pct mk_lib_net_connection_any1_get_str_buf(mk_lib_net_connection_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t off mk_lang_constexpr_init;
	mk_lang_types_pchar_pct buf mk_lang_constexpr_init;

	mk_lang_assert(id >= 0 && id <= mk_lib_net_connection_any1_id_e_dummy_end);

	off = mk_lib_net_connection_any1_strs_sums[id]; mk_lang_assert(off >= 0 && off < mk_lang_countof(mk_lib_net_connection_any1_strs_bufs));
	buf = &mk_lib_net_connection_any1_strs_bufs[off];
	return buf;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connection_any1_get_str_len(mk_lib_net_connection_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(id >= 0 && id <= mk_lib_net_connection_any1_id_e_dummy_end);

	len =
		mk_lib_net_connection_any1_strs_sums[id + 1] -
		mk_lib_net_connection_any1_strs_sums[id + 0];
	return len;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connection_any1_bare_rw_construct(mk_lib_net_connection_any1_bare_pt const hash_stream_any1_bare, mk_lib_net_connection_any1_id_t const id, mk_lang_types_void_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(hash_stream_any1_bare);
	mk_lang_assert(id >= 0 && id <= mk_lib_net_connection_any1_id_e_dummy_end);

	switch(id)
	{
mk_lib_net_connection_any_mm_per_type(`		case mk_lib_net_connection_any1_id_e_$1: err = $1_rw_construct(hash_stream_any1_bare->m_data.m_$1, settings); mk_lang_check_rereturn(err); break;', `
')
		case mk_lib_net_connection_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connection_any1_bare_rw_destroy(mk_lib_net_connection_any1_bare_pt const hash_stream_any1_bare, mk_lib_net_connection_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(hash_stream_any1_bare);
	mk_lang_assert(id >= 0 && id <= mk_lib_net_connection_any1_id_e_dummy_end);

	switch(id)
	{
mk_lib_net_connection_any_mm_per_type(`		case mk_lib_net_connection_any1_id_e_$1: err = $1_rw_destroy(hash_stream_any1_bare->m_data.m_$1); mk_lang_check_rereturn(err); break;', `
')
		case mk_lib_net_connection_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connection_any1_ptrid_rw_construct(mk_lib_net_connection_any1_ptrid_pt const hash_stream_any1_ptrid, mk_lib_net_connection_any1_id_t const id, mk_lang_types_void_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(hash_stream_any1_ptrid);
	mk_lang_assert(id >= 0 && id <= mk_lib_net_connection_any1_id_e_dummy_end);

	hash_stream_any1_ptrid->m_id = id;
	err = mk_lib_net_connection_any1_bare_rw_construct(&hash_stream_any1_ptrid->m_ptr, id, settings); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connection_any1_ptrid_rw_destroy(mk_lib_net_connection_any1_ptrid_pt const hash_stream_any1_ptrid) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(hash_stream_any1_ptrid);

	err = mk_lib_net_connection_any1_bare_rw_destroy(&hash_stream_any1_ptrid->m_ptr, hash_stream_any1_ptrid->m_id); mk_lang_check_rereturn(err);
	return 0;
}


#endif
