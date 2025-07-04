include(`mk_lib_net_connection_any.m')dnl
dnl
dnl
#ifndef mk_include_guard_mk_lib_net_connection_any2_c
#define mk_include_guard_mk_lib_net_connection_any2_c
#include "mk_lib_net_connection_any2.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
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


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connection_any2_rw_construct(mk_lib_net_connection_any2_pt const hash_stream_any2, mk_lib_net_connection_any1_id_t const id, mk_lang_types_void_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(hash_stream_any2);
	mk_lang_assert(id >= 0 && id <= mk_lib_net_connection_any1_id_e_dummy_end);

	switch(id)
	{
mk_lib_net_connection_any_mm_per_type(`		case mk_lib_net_connection_any1_id_e_$1: hash_stream_any2->m_data.m_$1.m_id = id; err = $1_rw_construct(&hash_stream_any2->m_data.m_$1.m_$1, settings); mk_lang_check_rereturn(err); break;', `
')
		case mk_lib_net_connection_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connection_any2_rw_destroy(mk_lib_net_connection_any2_pt const hash_stream_any2) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(hash_stream_any2);
	mk_lang_assert(hash_stream_any2->m_data.m_id >= 0 && hash_stream_any2->m_data.m_id <= mk_lib_net_connection_any1_id_e_dummy_end);

	switch(hash_stream_any2->m_data.m_id)
	{
mk_lib_net_connection_any_mm_per_type(`		case mk_lib_net_connection_any1_id_e_$1: err = $1_rw_destroy(&hash_stream_any2->m_data.m_$1.m_$1); mk_lang_check_rereturn(err); break;', `
')
		case mk_lib_net_connection_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}


#endif
