#ifndef mk_include_guard_mk_lib_wasm_hasher_c
#define mk_include_guard_mk_lib_wasm_hasher_c
#include "mk_lib_wasm_hasher.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_roundup.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_any1.h"
#include "mk_lib_crypto_hash_stream_any2.h"
#include "mk_lib_crypto_xof_stream_any1.h"
#include "mk_lib_crypto_xof_stream_any2.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_speedometer.h"


enum mk_lib_wasm_hasher_fnc_id_e
{
	mk_lib_wasm_hasher_fnc_id_e_get_buffer_buf,
	mk_lib_wasm_hasher_fnc_id_e_get_buffer_len,
	mk_lib_wasm_hasher_fnc_id_e_get_message_buf,
	mk_lib_wasm_hasher_fnc_id_e_get_message_len,
	mk_lib_wasm_hasher_fnc_id_e_get_alg_count,
	mk_lib_wasm_hasher_fnc_id_e_get_default_alg,
	mk_lib_wasm_hasher_fnc_id_e_get_alg_str_buf,
	mk_lib_wasm_hasher_fnc_id_e_get_alg_str_len,
	mk_lib_wasm_hasher_fnc_id_e_get_alg_key_buf,
	mk_lib_wasm_hasher_fnc_id_e_get_alg_key_len,
	mk_lib_wasm_hasher_fnc_id_e_get_digest_len,
	mk_lib_wasm_hasher_fnc_id_e_init,
	mk_lib_wasm_hasher_fnc_id_e_append,
	mk_lib_wasm_hasher_fnc_id_e_finish,
	mk_lib_wasm_hasher_fnc_id_e_dummy_end
};
typedef enum mk_lib_wasm_hasher_fnc_id_e mk_lib_wasm_hasher_fnc_id_t;


#define mk_lib_wasm_hasher_type_hash 1000
#define mk_lib_wasm_hasher_type_xof  2000
#define mk_lib_wasm_hasher_type_end  3000
mk_lang_constexpr_static_inline mk_lang_types_sint_t const mk_lib_wasm_hasher_k_order[] =
{
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_md2,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_md4,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_md5,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_sha0,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_sha1,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_sha2_224,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_sha2_256,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_sha2_512_224,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_sha2_512_256,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_sha2_384,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_sha2_512,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_sha3_224,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_sha3_256,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_sha3_384,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_sha3_512,
	mk_lib_wasm_hasher_type_xof  + mk_lib_crypto_xof_stream_any1_id_e_shake_128,
	mk_lib_wasm_hasher_type_xof  + mk_lib_crypto_xof_stream_any1_id_e_shake_256,
	mk_lib_wasm_hasher_type_xof  + mk_lib_crypto_xof_stream_any1_id_e_turbo_shake_128,
	mk_lib_wasm_hasher_type_xof  + mk_lib_crypto_xof_stream_any1_id_e_turbo_shake_256,
	mk_lib_wasm_hasher_type_xof  + mk_lib_crypto_xof_stream_any1_id_e_kt128,
	mk_lib_wasm_hasher_type_xof  + mk_lib_crypto_xof_stream_any1_id_e_kt256,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake2s_128,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake2s_160,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake2s_224,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake2s_256,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake2b_256,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake2b_384,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake2b_512,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake3,
	mk_lib_wasm_hasher_type_xof  + mk_lib_crypto_xof_stream_any1_id_e_blake3,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_tiger_128,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_tiger_160,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_tiger_192,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_tiger2_128,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_tiger2_160,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_tiger2_192,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_whirlpool,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_streebog_256,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_streebog_512,
};


mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_buffer_buf(mk_lib_wasm_hasher_pt const hasher) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(hasher);

	addr = mk_lang_roundup_align(&hasher->m_buffer.m_data.m_uint8s[0], mk_lib_wasm_hasher_buffer_algn);
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_buffer_len(mk_lib_wasm_hasher_pt const hasher) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(hasher);

	((mk_lang_types_void_t)(hasher));
	len = mk_lib_wasm_hasher_buffer_size;
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_message_buf(mk_lib_wasm_hasher_pt const hasher) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(hasher);

	addr = ((mk_lang_types_uintptr_t)(&hasher->m_message.m_data.m_pchars[0]));
	return addr;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_message_len(mk_lib_wasm_hasher_pt const hasher) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(hasher);

	len = ((mk_lang_types_uintptr_t)(hasher->m_message.m_len));
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_alg_count(mk_lib_wasm_hasher_pt const hasher) mk_lang_noexcept
{
	mk_lang_types_uintptr_t count;

	mk_lang_static_assert(mk_lang_countof(mk_lib_wasm_hasher_k_order) <= ((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_any1_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_xof_stream_any1_id_e_dummy_end)));

	mk_lang_assert(hasher);

	((mk_lang_types_void_t)(hasher));
	count = mk_lang_countof(mk_lib_wasm_hasher_k_order);
	return count;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_default_alg(mk_lib_wasm_hasher_pt const hasher) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t id;
	mk_lang_types_uintptr_t idx;

	mk_lang_assert(hasher);

	((mk_lang_types_void_t)(hasher));
	n = mk_lang_countof(mk_lib_wasm_hasher_k_order);
	for(i = 0; i != n; ++i)
	{
		id = mk_lib_wasm_hasher_k_order[i];
		if(id == mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_sha2_512)
		{
			break;
		}
	}
	mk_lang_assert(i != n);
	idx = ((mk_lang_types_uintptr_t)(i));
	return idx;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_alg_str_buf(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t id;
	mk_lang_types_pchar_pct str_buf;
	mk_lib_crypto_hash_stream_any1_id_t id_hash;
	mk_lib_crypto_xof_stream_any1_id_t id_xof;
	mk_lang_types_uintptr_t buf;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(hasher);
	mk_lang_assert(idx >= 0 && idx < mk_lang_countof(mk_lib_wasm_hasher_k_order));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(hasher));
	#include "mk_lang_warning_clang_push_uninitialized_const_pointer.h"
	mk_lang_clobber(&str_buf);
	#include "mk_lang_warning_clang_pop.h"
	id = mk_lib_wasm_hasher_k_order[idx];
	if(id >= mk_lib_wasm_hasher_type_hash && id < mk_lib_wasm_hasher_type_xof)
	{
		id_hash = ((mk_lib_crypto_hash_stream_any1_id_t)(id - mk_lib_wasm_hasher_type_hash));
		str_buf = mk_lib_crypto_hash_stream_any1_get_str_buf(id_hash);
	}
	else if(id >= mk_lib_wasm_hasher_type_xof && id < mk_lib_wasm_hasher_type_end)
	{
		id_xof = ((mk_lib_crypto_xof_stream_any1_id_t)(id - mk_lib_wasm_hasher_type_xof));
		str_buf = mk_lib_crypto_xof_stream_any1_get_str_buf(id_xof);
	}
	else
	{
		str_buf = mk_lang_null;
		mk_lang_assert(mk_lang_false);
	}
	buf = ((mk_lang_types_uintptr_t)(str_buf));
	return buf;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_alg_str_len(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t str_len;
	mk_lang_types_sint_t id;
	mk_lib_crypto_hash_stream_any1_id_t id_hash;
	mk_lib_crypto_xof_stream_any1_id_t id_xof;
	mk_lang_types_uintptr_t len;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(hasher);
	mk_lang_assert(idx >= 0 && idx < mk_lang_countof(mk_lib_wasm_hasher_k_order));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(hasher));
	#include "mk_lang_warning_clang_push_uninitialized_const_pointer.h"
	mk_lang_clobber(&str_len);
	#include "mk_lang_warning_clang_pop.h"
	id = mk_lib_wasm_hasher_k_order[idx];
	if(id >= mk_lib_wasm_hasher_type_hash && id < mk_lib_wasm_hasher_type_xof)
	{
		id_hash = ((mk_lib_crypto_hash_stream_any1_id_t)(id - mk_lib_wasm_hasher_type_hash));
		str_len = mk_lib_crypto_hash_stream_any1_get_str_len(id_hash);
	}
	else if(id >= mk_lib_wasm_hasher_type_xof && id < mk_lib_wasm_hasher_type_end)
	{
		id_xof = ((mk_lib_crypto_xof_stream_any1_id_t)(id - mk_lib_wasm_hasher_type_xof));
		str_len = mk_lib_crypto_xof_stream_any1_get_str_len(id_xof);
	}
	else
	{
		str_len = 0;
		mk_lang_assert(mk_lang_false);
	}
	len = ((mk_lang_types_uintptr_t)(str_len));
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_alg_key_buf(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t id;
	mk_lang_types_pchar_pct key_buf;
	mk_lib_crypto_hash_stream_any1_id_t id_hash;
	mk_lib_crypto_xof_stream_any1_id_t id_xof;
	mk_lang_types_uintptr_t buf;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(hasher);
	mk_lang_assert(idx >= 0 && idx < mk_lang_countof(mk_lib_wasm_hasher_k_order));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(hasher));
	#include "mk_lang_warning_clang_push_uninitialized_const_pointer.h"
	mk_lang_clobber(&key_buf);
	#include "mk_lang_warning_clang_pop.h"
	id = mk_lib_wasm_hasher_k_order[idx];
	if(id >= mk_lib_wasm_hasher_type_hash && id < mk_lib_wasm_hasher_type_xof)
	{
		id_hash = ((mk_lib_crypto_hash_stream_any1_id_t)(id - mk_lib_wasm_hasher_type_hash));
		key_buf = mk_lib_crypto_hash_stream_any1_get_key_buf(id_hash);
	}
	else if(id >= mk_lib_wasm_hasher_type_xof && id < mk_lib_wasm_hasher_type_end)
	{
		id_xof = ((mk_lib_crypto_xof_stream_any1_id_t)(id - mk_lib_wasm_hasher_type_xof));
		key_buf = mk_lib_crypto_xof_stream_any1_get_key_buf(id_xof);
	}
	else
	{
		key_buf = mk_lang_null;
		mk_lang_assert(mk_lang_false);
	}
	buf = ((mk_lang_types_uintptr_t)(key_buf));
	return buf;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_alg_key_len(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t key_len;
	mk_lang_types_sint_t id;
	mk_lib_crypto_hash_stream_any1_id_t id_hash;
	mk_lib_crypto_xof_stream_any1_id_t id_xof;
	mk_lang_types_uintptr_t len;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(hasher);
	mk_lang_assert(idx >= 0 && idx < mk_lang_countof(mk_lib_wasm_hasher_k_order));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(hasher));
	#include "mk_lang_warning_clang_push_uninitialized_const_pointer.h"
	mk_lang_clobber(&key_len);
	#include "mk_lang_warning_clang_pop.h"
	id = mk_lib_wasm_hasher_k_order[idx];
	if(id >= mk_lib_wasm_hasher_type_hash && id < mk_lib_wasm_hasher_type_xof)
	{
		id_hash = ((mk_lib_crypto_hash_stream_any1_id_t)(id - mk_lib_wasm_hasher_type_hash));
		key_len = mk_lib_crypto_hash_stream_any1_get_key_len(id_hash);
	}
	else if(id >= mk_lib_wasm_hasher_type_xof && id < mk_lib_wasm_hasher_type_end)
	{
		id_xof = ((mk_lib_crypto_xof_stream_any1_id_t)(id - mk_lib_wasm_hasher_type_xof));
		key_len = mk_lib_crypto_xof_stream_any1_get_key_len(id_xof);
	}
	else
	{
		key_len = 0;
		mk_lang_assert(mk_lang_false);
	}
	len = ((mk_lang_types_uintptr_t)(key_len));
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_digest_len(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t digest_len;
	mk_lang_types_sint_t id;
	mk_lib_crypto_hash_stream_any1_id_t id_hash;
	mk_lib_crypto_xof_stream_any1_id_t id_xof;
	mk_lang_types_uintptr_t len;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(hasher);
	mk_lang_assert(idx >= 0 && idx < mk_lang_countof(mk_lib_wasm_hasher_k_order));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(hasher));
	#include "mk_lang_warning_clang_push_uninitialized_const_pointer.h"
	mk_lang_clobber(&digest_len);
	#include "mk_lang_warning_clang_pop.h"
	id = mk_lib_wasm_hasher_k_order[idx];
	if(id >= mk_lib_wasm_hasher_type_hash && id < mk_lib_wasm_hasher_type_xof)
	{
		id_hash = ((mk_lib_crypto_hash_stream_any1_id_t)(id - mk_lib_wasm_hasher_type_hash));
		digest_len = mk_lib_crypto_hash_stream_any1_get_digest_len(id_hash);
	}
	else if(id >= mk_lib_wasm_hasher_type_xof && id < mk_lib_wasm_hasher_type_end)
	{
		id_xof = ((mk_lib_crypto_xof_stream_any1_id_t)(id - mk_lib_wasm_hasher_type_xof));
		((mk_lang_types_void_t)(id_xof));
		digest_len = 0;
	}
	else
	{
		digest_len = 0;
		mk_lang_assert(mk_lang_false);
	}
	len = ((mk_lang_types_uintptr_t)(digest_len));
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_hasher_init(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t id;
	mk_lib_crypto_hash_stream_any1_id_t id_hash;
	mk_lib_crypto_xof_stream_any1_id_t id_xof;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(hasher);
	mk_lang_assert(idx >= 0 && idx < mk_lang_countof(mk_lib_wasm_hasher_k_order));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	id = mk_lib_wasm_hasher_k_order[idx];
	if(id >= mk_lib_wasm_hasher_type_hash && id < mk_lib_wasm_hasher_type_xof)
	{
		id_hash = ((mk_lib_crypto_hash_stream_any1_id_t)(id - mk_lib_wasm_hasher_type_hash));
		hasher->m_is_xofer = mk_lang_false;
		mk_lib_crypto_hash_stream_any2_init(&hasher->m_worker.m_data.m_hasher, id_hash);
	}
	else if(id >= mk_lib_wasm_hasher_type_xof && id < mk_lib_wasm_hasher_type_end)
	{
		id_xof = ((mk_lib_crypto_xof_stream_any1_id_t)(id - mk_lib_wasm_hasher_type_xof));
		hasher->m_is_xofer = mk_lang_true;
		mk_lib_crypto_xof_stream_any2_init(&hasher->m_worker.m_data.m_xofer, id_xof);
	}
	else
	{
		mk_lang_assert(mk_lang_false);
	}
	err = mk_sl_speedometer_rw_construct(&hasher->m_speedometer); mk_lang_check_rereturn(err);
	hasher->m_message.m_len = 0;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_hasher_append(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const count) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct u8s;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t reported;
	mk_lang_types_sint_t len;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(hasher);
	mk_lang_assert(count >= 0 && count < mk_lib_wasm_hasher_buffer_size);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	u8s = ((mk_sl_cui_uint8_pct)(mk_lib_wasm_hasher_get_buffer_buf(hasher)));
	if(!hasher->m_is_xofer)
	{
		mk_lib_crypto_hash_stream_any2_append_u8s(&hasher->m_worker.m_data.m_hasher, u8s, count);
	}
	else
	{
		mk_lib_crypto_xof_stream_any2_append_u8s(&hasher->m_worker.m_data.m_xofer, u8s, count);
	}
	mk_lang_assert(count <= ((mk_lang_types_uintptr_t)(mk_lang_limits_sint_max)));
	err = mk_sl_speedometer_rw_append(&hasher->m_speedometer, ((mk_lang_types_sint_t)(count))); mk_lang_check_rereturn(err);
	err = mk_sl_speedometer_rw_report(&hasher->m_speedometer, &hasher->m_message.m_data.m_pchars[128], mk_lang_countof(hasher->m_message.m_data.m_pchars) - 128, &reported, &len); mk_lang_check_rereturn(err);
	if(reported)
	{
		mk_lang_string_memcpy_pc_fn(&hasher->m_message.m_data.m_pchars[0], &hasher->m_message.m_data.m_pchars[128], len);
		hasher->m_message.m_len = len;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_uintptr_t mk_lib_wasm_hasher_finish(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const xof_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt u8s;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(hasher);
	mk_lang_assert(xof_len >= 0 && xof_len < mk_lib_wasm_hasher_buffer_size);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	u8s = ((mk_sl_cui_uint8_pt)(mk_lib_wasm_hasher_get_buffer_buf(hasher)));
	if(!hasher->m_is_xofer)
	{
		mk_lib_crypto_hash_stream_any2_finish(&hasher->m_worker.m_data.m_hasher, u8s);
	}
	else
	{
		mk_lib_crypto_xof_stream_any2_finish(&hasher->m_worker.m_data.m_xofer);
		mk_lib_crypto_xof_stream_any2_squeeze_u8s(&hasher->m_worker.m_data.m_xofer, u8s, xof_len);
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_main(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const fnc, mk_lang_types_uintptr_t const arg) mk_lang_noexcept
{
	mk_lang_types_uintptr_t res;

	mk_lang_assert(hasher);

	res = ((mk_lang_types_uintptr_t)(((mk_lang_types_sintptr_t)(-1))));
	switch(fnc)
	{
		case mk_lib_wasm_hasher_fnc_id_e_get_buffer_buf : res = mk_lib_wasm_hasher_get_buffer_buf (hasher); break;
		case mk_lib_wasm_hasher_fnc_id_e_get_buffer_len : res = mk_lib_wasm_hasher_get_buffer_len (hasher); break;
		case mk_lib_wasm_hasher_fnc_id_e_get_message_buf: res = mk_lib_wasm_hasher_get_message_buf(hasher); break;
		case mk_lib_wasm_hasher_fnc_id_e_get_message_len: res = mk_lib_wasm_hasher_get_message_len(hasher); break;
		case mk_lib_wasm_hasher_fnc_id_e_get_alg_count  : res = mk_lib_wasm_hasher_get_alg_count  (hasher); break;
		case mk_lib_wasm_hasher_fnc_id_e_get_default_alg: res = mk_lib_wasm_hasher_get_default_alg(hasher); break;
		case mk_lib_wasm_hasher_fnc_id_e_get_alg_str_buf: res = mk_lib_wasm_hasher_get_alg_str_buf(hasher, arg); break;
		case mk_lib_wasm_hasher_fnc_id_e_get_alg_str_len: res = mk_lib_wasm_hasher_get_alg_str_len(hasher, arg); break;
		case mk_lib_wasm_hasher_fnc_id_e_get_alg_key_buf: res = mk_lib_wasm_hasher_get_alg_key_buf(hasher, arg); break;
		case mk_lib_wasm_hasher_fnc_id_e_get_alg_key_len: res = mk_lib_wasm_hasher_get_alg_key_len(hasher, arg); break;
		case mk_lib_wasm_hasher_fnc_id_e_get_digest_len : res = mk_lib_wasm_hasher_get_digest_len (hasher, arg); break;
		case mk_lib_wasm_hasher_fnc_id_e_init           : res = mk_lib_wasm_hasher_init           (hasher, arg); break;
		case mk_lib_wasm_hasher_fnc_id_e_append         : res = mk_lib_wasm_hasher_append         (hasher, arg); break;
		case mk_lib_wasm_hasher_fnc_id_e_finish         : res = mk_lib_wasm_hasher_finish         (hasher, arg); break;
		case mk_lib_wasm_hasher_fnc_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return res;
}


#endif
