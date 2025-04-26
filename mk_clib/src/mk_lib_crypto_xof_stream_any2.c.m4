include(`mk_lib_crypto_xof_stream_any.m')dnl
dnl
dnl
#ifndef mk_include_guard_mk_lib_crypto_xof_stream_any2_c
#define mk_include_guard_mk_lib_crypto_xof_stream_any2_c
#include "mk_lib_crypto_xof_stream_any2.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_xof_stream_any1.h"
#include "mk_sl_cui_uint8.h"

mk_lib_crypto_xof_stream_any_mm_per_xof(`#include "mk_lib_crypto_xof_stream_$1.h"', `
')


union mk_lib_crypto_xof_stream_any2_digest_data_u
{
mk_lib_crypto_xof_stream_any_mm_per_xof(`	mk_lib_crypto_xof_stream_$1_digest_t m_$1;', `
')
};
typedef union mk_lib_crypto_xof_stream_any2_digest_data_u mk_lib_crypto_xof_stream_any2_digest_data_t;
struct mk_lib_crypto_xof_stream_any2_digest_s
{
	mk_lib_crypto_xof_stream_any2_digest_data_t m_data;
};
typedef struct mk_lib_crypto_xof_stream_any2_digest_s mk_lib_crypto_xof_stream_any2_digest_t;
mk_lang_typedef(mk_lib_crypto_xof_stream_any2_digest);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any2_init(mk_lib_crypto_xof_stream_any2_pt const xof_stream_any2, mk_lib_crypto_xof_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(xof_stream_any2);
	mk_lang_assert(id >= 0 && id <= mk_lib_crypto_xof_stream_any1_id_e_dummy_end);

	switch(id)
	{
mk_lib_crypto_xof_stream_any_mm_per_xof(`		case mk_lib_crypto_xof_stream_any1_id_e_$1: xof_stream_any2->m_data.m_$1.m_id = id; mk_lib_crypto_xof_stream_$1_init(&xof_stream_any2->m_data.m_$1.m_$1); break;', `
')
		case mk_lib_crypto_xof_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any2_append_u8s(mk_lib_crypto_xof_stream_any2_pt const xof_stream_any2, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_assert(xof_stream_any2);
	mk_lang_assert(xof_stream_any2->m_data.m_id >= 0 && xof_stream_any2->m_data.m_id <= mk_lib_crypto_xof_stream_any1_id_e_dummy_end);

	switch(xof_stream_any2->m_data.m_id)
	{
mk_lib_crypto_xof_stream_any_mm_per_xof(`		case mk_lib_crypto_xof_stream_any1_id_e_$1: mk_lib_crypto_xof_stream_$1_append_u8s(&xof_stream_any2->m_data.m_$1.m_$1, u8s, count); break;', `
')
		case mk_lib_crypto_xof_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any2_finish(mk_lib_crypto_xof_stream_any2_pt const xof_stream_any2) mk_lang_noexcept
{
	mk_lang_assert(xof_stream_any2);
	mk_lang_assert(xof_stream_any2->m_data.m_id >= 0 && xof_stream_any2->m_data.m_id <= mk_lib_crypto_xof_stream_any1_id_e_dummy_end);

	switch(xof_stream_any2->m_data.m_id)
	{
mk_lib_crypto_xof_stream_any_mm_per_xof(`		case mk_lib_crypto_xof_stream_any1_id_e_$1: mk_lib_crypto_xof_stream_$1_finish(&xof_stream_any2->m_data.m_$1.m_$1); break;', `
')
		case mk_lib_crypto_xof_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any2_squeeze_u8s(mk_lib_crypto_xof_stream_any2_pt const xof_stream_any2, mk_sl_cui_uint8_pt const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(xof_stream_any2);
	mk_lang_assert(xof_stream_any2->m_data.m_id >= 0 && xof_stream_any2->m_data.m_id <= mk_lib_crypto_xof_stream_any1_id_e_dummy_end);
	mk_lang_assert(u8s);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	switch(xof_stream_any2->m_data.m_id)
	{
mk_lib_crypto_xof_stream_any_mm_per_xof(`		case mk_lib_crypto_xof_stream_any1_id_e_$1: mk_lib_crypto_xof_stream_$1_squeeze_u8s(&xof_stream_any2->m_data.m_$1.m_$1, u8s, count); break;', `
')
		case mk_lib_crypto_xof_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}


#endif
