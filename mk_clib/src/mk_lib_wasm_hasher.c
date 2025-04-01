#ifndef mk_include_guard_mk_lib_wasm_hasher_c
#define mk_include_guard_mk_lib_wasm_hasher_c
#include "mk_lib_wasm_hasher.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_any1.h"
#include "mk_lib_crypto_hash_stream_any2.h"
#include "mk_lib_crypto_xof_stream_any1.h"
#include "mk_lib_crypto_xof_stream_any2.h"
#include "mk_sl_cui_uint8.h"


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
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake2s_128,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake2s_160,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake2s_224,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake2s_256,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake2b_256,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake2b_384,
	mk_lib_wasm_hasher_type_hash + mk_lib_crypto_hash_stream_any1_id_e_blake2b_512,
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


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_buffer_buf(mk_lib_wasm_hasher_pt const hasher) mk_lang_noexcept
{
	mk_lang_types_uintptr_t addr;

	mk_lang_assert(hasher);

	addr = mk_lang_roundup_align(&hasher->m_buffer.m_data.m_uint8s[0], mk_lib_wasm_hasher_buffer_algn);
	return addr;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_buffer_len(mk_lib_wasm_hasher_pt const hasher) mk_lang_noexcept
{
	mk_lang_types_uintptr_t len;

	mk_lang_assert(hasher);

	((mk_lang_types_void_t)(hasher));
	len = mk_lib_wasm_hasher_buffer_size;
	return len;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_alg_count(mk_lib_wasm_hasher_pt const hasher) mk_lang_noexcept
{
	mk_lang_types_uintptr_t count;

	mk_lang_static_assert(mk_lang_countof(mk_lib_wasm_hasher_k_order) <= ((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_any1_id_e_dummy_end)) + ((mk_lang_types_sint_t)(mk_lib_crypto_xof_stream_any1_id_e_dummy_end)));

	mk_lang_assert(hasher);

	((mk_lang_types_void_t)(hasher));
	count = mk_lang_countof(mk_lib_wasm_hasher_k_order);
	return count;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_default_alg(mk_lib_wasm_hasher_pt const hasher) mk_lang_noexcept
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
	idx = i;
	return idx;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_alg_str_buf(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const idx) mk_lang_noexcept
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
	mk_lang_clobber(&str_buf);
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
		mk_lang_assert(mk_lang_false);
	}
	buf = ((mk_lang_types_uintptr_t)(str_buf));
	return buf;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_alg_str_len(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const idx) mk_lang_noexcept
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
	mk_lang_clobber(&str_len);
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
		mk_lang_assert(mk_lang_false);
	}
	len = ((mk_lang_types_uintptr_t)(str_len));
	return len;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_get_digest_len(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const idx) mk_lang_noexcept
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
	mk_lang_clobber(&digest_len);
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
		mk_lang_assert(mk_lang_false);
	}
	len = ((mk_lang_types_uintptr_t)(digest_len));
	return len;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_init(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t id;
	mk_lib_crypto_hash_stream_any1_id_t id_hash;
	mk_lib_crypto_xof_stream_any1_id_t id_xof;

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
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_append(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const count) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct u8s;

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
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_uintptr_t mk_lib_wasm_hasher_finish(mk_lib_wasm_hasher_pt const hasher, mk_lang_types_uintptr_t const xof_len) mk_lang_noexcept
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


#endif
