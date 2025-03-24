#ifndef mk_include_guard_mk_lib_crypto_xof_stream_any1_c
#define mk_include_guard_mk_lib_crypto_xof_stream_any1_c
#include "mk_lib_crypto_xof_stream_any1.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"

#include "mk_lib_crypto_xof_stream_shake_128.h"
#include "mk_lib_crypto_xof_stream_shake_256.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_bare_init(mk_lib_crypto_xof_stream_any1_bare_pt const xof_stream_any1_bare, mk_lib_crypto_xof_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(xof_stream_any1_bare);
	mk_lang_assert(((mk_lang_types_sint_t)(id)) >= 0 && ((mk_lang_types_sint_t)(id)) <= ((mk_lang_types_sint_t)(mk_lib_crypto_xof_stream_any1_id_e_dummy_end)));

	switch(id)
	{
		case mk_lib_crypto_xof_stream_any1_id_e_shake_128: mk_lib_crypto_xof_stream_shake_128_init(xof_stream_any1_bare->m_data.m_shake_128); break;
		case mk_lib_crypto_xof_stream_any1_id_e_shake_256: mk_lib_crypto_xof_stream_shake_256_init(xof_stream_any1_bare->m_data.m_shake_256); break;
		case mk_lib_crypto_xof_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_bare_append_u8s(mk_lib_crypto_xof_stream_any1_bare_pt const xof_stream_any1_bare, mk_lib_crypto_xof_stream_any1_id_t const id, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_assert(xof_stream_any1_bare);
	mk_lang_assert(((mk_lang_types_sint_t)(id)) >= 0 && ((mk_lang_types_sint_t)(id)) <= ((mk_lang_types_sint_t)(mk_lib_crypto_xof_stream_any1_id_e_dummy_end)));

	switch(id)
	{
		case mk_lib_crypto_xof_stream_any1_id_e_shake_128: mk_lib_crypto_xof_stream_shake_128_append_u8s(xof_stream_any1_bare->m_data.m_shake_128, u8s, count); break;
		case mk_lib_crypto_xof_stream_any1_id_e_shake_256: mk_lib_crypto_xof_stream_shake_256_append_u8s(xof_stream_any1_bare->m_data.m_shake_256, u8s, count); break;
		case mk_lib_crypto_xof_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_bare_finish(mk_lib_crypto_xof_stream_any1_bare_pt const xof_stream_any1_bare, mk_lib_crypto_xof_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(xof_stream_any1_bare);
	mk_lang_assert(((mk_lang_types_sint_t)(id)) >= 0 && ((mk_lang_types_sint_t)(id)) <= ((mk_lang_types_sint_t)(mk_lib_crypto_xof_stream_any1_id_e_dummy_end)));

	switch(id)
	{
		case mk_lib_crypto_xof_stream_any1_id_e_shake_128: mk_lib_crypto_xof_stream_shake_128_finish(xof_stream_any1_bare->m_data.m_shake_128); break;
		case mk_lib_crypto_xof_stream_any1_id_e_shake_256: mk_lib_crypto_xof_stream_shake_256_finish(xof_stream_any1_bare->m_data.m_shake_256); break;
		case mk_lib_crypto_xof_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_bare_squeeze_u8s(mk_lib_crypto_xof_stream_any1_bare_pt const xof_stream_any1_bare, mk_lib_crypto_xof_stream_any1_id_t const id, mk_sl_cui_uint8_pt const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_assert(xof_stream_any1_bare);
	mk_lang_assert(((mk_lang_types_sint_t)(id)) >= 0 && ((mk_lang_types_sint_t)(id)) <= ((mk_lang_types_sint_t)(mk_lib_crypto_xof_stream_any1_id_e_dummy_end)));

	switch(id)
	{
		case mk_lib_crypto_xof_stream_any1_id_e_shake_128: mk_lib_crypto_xof_stream_shake_128_squeeze_u8s(xof_stream_any1_bare->m_data.m_shake_128, u8s, count); break;
		case mk_lib_crypto_xof_stream_any1_id_e_shake_256: mk_lib_crypto_xof_stream_shake_256_squeeze_u8s(xof_stream_any1_bare->m_data.m_shake_256, u8s, count); break;
		case mk_lib_crypto_xof_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_ptrid_init(mk_lib_crypto_xof_stream_any1_ptrid_pt const hash_stream_any1_ptrid, mk_lib_crypto_xof_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(hash_stream_any1_ptrid);
	mk_lang_assert(((mk_lang_types_sint_t)(id)) >= 0 && ((mk_lang_types_sint_t)(id)) <= ((mk_lang_types_sint_t)(mk_lib_crypto_xof_stream_any1_id_e_dummy_end)));

	hash_stream_any1_ptrid->m_id = id;
	mk_lib_crypto_xof_stream_any1_bare_init(&hash_stream_any1_ptrid->m_ptr, id);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_ptrid_append_u8s(mk_lib_crypto_xof_stream_any1_ptrid_pt const hash_stream_any1_ptrid, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_assert(hash_stream_any1_ptrid);

	mk_lib_crypto_xof_stream_any1_bare_append_u8s(&hash_stream_any1_ptrid->m_ptr, hash_stream_any1_ptrid->m_id, u8s, count);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_ptrid_finish(mk_lib_crypto_xof_stream_any1_ptrid_pt const hash_stream_any1_ptrid) mk_lang_noexcept
{
	mk_lang_assert(hash_stream_any1_ptrid);

	mk_lib_crypto_xof_stream_any1_bare_finish(&hash_stream_any1_ptrid->m_ptr, hash_stream_any1_ptrid->m_id);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_any1_ptrid_squeeze_u8s(mk_lib_crypto_xof_stream_any1_ptrid_pt const hash_stream_any1_ptrid, mk_sl_cui_uint8_pt const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_assert(hash_stream_any1_ptrid);

	mk_lib_crypto_xof_stream_any1_bare_squeeze_u8s(&hash_stream_any1_ptrid->m_ptr, hash_stream_any1_ptrid->m_id, u8s, count);
}


#endif
