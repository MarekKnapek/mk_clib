#ifndef mk_include_guard_mk_lib_crypto_hash_stream_any1_c
#define mk_include_guard_mk_lib_crypto_hash_stream_any1_c
#include "mk_lib_crypto_hash_stream_any1.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"

#include "mk_lib_crypto_hash_stream_md2.h"
#include "mk_lib_crypto_hash_stream_md4.h"
#include "mk_lib_crypto_hash_stream_md5.h"
#include "mk_lib_crypto_hash_stream_sha0.h"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_lib_crypto_hash_stream_sha2_224.h"
#include "mk_lib_crypto_hash_stream_sha2_256.h"
#include "mk_lib_crypto_hash_stream_sha2_384.h"
#include "mk_lib_crypto_hash_stream_sha2_512.h"
#include "mk_lib_crypto_hash_stream_sha2_512_224.h"
#include "mk_lib_crypto_hash_stream_sha2_512_256.h"
#include "mk_lib_crypto_hash_stream_sha3_224.h"
#include "mk_lib_crypto_hash_stream_sha3_256.h"
#include "mk_lib_crypto_hash_stream_sha3_384.h"
#include "mk_lib_crypto_hash_stream_sha3_512.h"


union mk_lib_crypto_hash_stream_any1_digest_data_u
{
	mk_lib_crypto_hash_stream_md2_digest_t m_md2;
	mk_lib_crypto_hash_stream_md4_digest_t m_md4;
	mk_lib_crypto_hash_stream_md5_digest_t m_md5;
	mk_lib_crypto_hash_stream_sha0_digest_t m_sha0;
	mk_lib_crypto_hash_stream_sha1_digest_t m_sha1;
	mk_lib_crypto_hash_stream_sha2_224_digest_t m_sha2_224;
	mk_lib_crypto_hash_stream_sha2_256_digest_t m_sha2_256;
	mk_lib_crypto_hash_stream_sha2_384_digest_t m_sha2_384;
	mk_lib_crypto_hash_stream_sha2_512_224_digest_t m_sha2_512_224;
	mk_lib_crypto_hash_stream_sha2_512_256_digest_t m_sha2_512_256;
	mk_lib_crypto_hash_stream_sha2_512_digest_t m_sha2_512;
	mk_lib_crypto_hash_stream_sha3_224_digest_t m_sha3_224;
	mk_lib_crypto_hash_stream_sha3_256_digest_t m_sha3_256;
	mk_lib_crypto_hash_stream_sha3_384_digest_t m_sha3_384;
	mk_lib_crypto_hash_stream_sha3_512_digest_t m_sha3_512;
};
typedef union mk_lib_crypto_hash_stream_any1_digest_data_u mk_lib_crypto_hash_stream_any1_digest_data_t;
struct mk_lib_crypto_hash_stream_any1_digest_s
{
	mk_lib_crypto_hash_stream_any1_digest_data_t m_data;
};
typedef struct mk_lib_crypto_hash_stream_any1_digest_s mk_lib_crypto_hash_stream_any1_digest_t;
mk_lang_typedef(mk_lib_crypto_hash_stream_any1_digest);


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_hash_stream_any1_digest_len(mk_lib_crypto_hash_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t res mk_lang_constexpr_init;

	mk_lang_assert(((mk_lang_types_sint_t)(id)) >= 0 && ((mk_lang_types_sint_t)(id)) <= ((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_any1_id_e_dummy_end)));

	mk_lang_clobber(&res);
	switch(id)
	{
		case mk_lib_crypto_hash_stream_any1_id_e_md2         : res = mk_lib_crypto_hash_stream_md2_digest_len_v;          break;
		case mk_lib_crypto_hash_stream_any1_id_e_md4         : res = mk_lib_crypto_hash_stream_md4_digest_len_v;          break;
		case mk_lib_crypto_hash_stream_any1_id_e_md5         : res = mk_lib_crypto_hash_stream_md5_digest_len_v;          break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha0        : res = mk_lib_crypto_hash_stream_sha0_digest_len_v;         break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha1        : res = mk_lib_crypto_hash_stream_sha1_digest_len_v;         break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_224    : res = mk_lib_crypto_hash_stream_sha2_224_digest_len_v;     break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_256    : res = mk_lib_crypto_hash_stream_sha2_256_digest_len_v;     break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_384    : res = mk_lib_crypto_hash_stream_sha2_384_digest_len_v;     break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_512    : res = mk_lib_crypto_hash_stream_sha2_512_digest_len_v;     break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_512_224: res = mk_lib_crypto_hash_stream_sha2_512_224_digest_len_v; break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_512_256: res = mk_lib_crypto_hash_stream_sha2_512_256_digest_len_v; break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_224    : res = mk_lib_crypto_hash_stream_sha3_224_digest_len_v;     break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_256    : res = mk_lib_crypto_hash_stream_sha3_256_digest_len_v;     break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_384    : res = mk_lib_crypto_hash_stream_sha3_384_digest_len_v;     break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_512    : res = mk_lib_crypto_hash_stream_sha3_512_digest_len_v;     break;
		case mk_lib_crypto_hash_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return res;
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any1_bare_init(mk_lib_crypto_hash_stream_any1_bare_pt const hash_stream_any1_bare, mk_lib_crypto_hash_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(hash_stream_any1_bare);
	mk_lang_assert(((mk_lang_types_sint_t)(id)) >= 0 && ((mk_lang_types_sint_t)(id)) <= ((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_any1_id_e_dummy_end)));

	switch(id)
	{
		case mk_lib_crypto_hash_stream_any1_id_e_md2         : mk_lib_crypto_hash_stream_md2_init         (hash_stream_any1_bare->m_data.m_md2         ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_md4         : mk_lib_crypto_hash_stream_md4_init         (hash_stream_any1_bare->m_data.m_md4         ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_md5         : mk_lib_crypto_hash_stream_md5_init         (hash_stream_any1_bare->m_data.m_md5         ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha0        : mk_lib_crypto_hash_stream_sha0_init        (hash_stream_any1_bare->m_data.m_sha0        ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha1        : mk_lib_crypto_hash_stream_sha1_init        (hash_stream_any1_bare->m_data.m_sha1        ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_224    : mk_lib_crypto_hash_stream_sha2_224_init    (hash_stream_any1_bare->m_data.m_sha2_224    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_256    : mk_lib_crypto_hash_stream_sha2_256_init    (hash_stream_any1_bare->m_data.m_sha2_256    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_384    : mk_lib_crypto_hash_stream_sha2_384_init    (hash_stream_any1_bare->m_data.m_sha2_384    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_512    : mk_lib_crypto_hash_stream_sha2_512_init    (hash_stream_any1_bare->m_data.m_sha2_512    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_512_224: mk_lib_crypto_hash_stream_sha2_512_224_init(hash_stream_any1_bare->m_data.m_sha2_512_224); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_512_256: mk_lib_crypto_hash_stream_sha2_512_256_init(hash_stream_any1_bare->m_data.m_sha2_512_256); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_224    : mk_lib_crypto_hash_stream_sha3_224_init    (hash_stream_any1_bare->m_data.m_sha3_224    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_256    : mk_lib_crypto_hash_stream_sha3_256_init    (hash_stream_any1_bare->m_data.m_sha3_256    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_384    : mk_lib_crypto_hash_stream_sha3_384_init    (hash_stream_any1_bare->m_data.m_sha3_384    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_512    : mk_lib_crypto_hash_stream_sha3_512_init    (hash_stream_any1_bare->m_data.m_sha3_512    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any1_bare_append_u8s(mk_lib_crypto_hash_stream_any1_bare_pt const hash_stream_any1_bare, mk_lib_crypto_hash_stream_any1_id_t const id, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_assert(hash_stream_any1_bare);
	mk_lang_assert(((mk_lang_types_sint_t)(id)) >= 0 && ((mk_lang_types_sint_t)(id)) <= ((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_any1_id_e_dummy_end)));

	switch(id)
	{
		case mk_lib_crypto_hash_stream_any1_id_e_md2         : mk_lib_crypto_hash_stream_md2_append_u8s         (hash_stream_any1_bare->m_data.m_md2         , u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_md4         : mk_lib_crypto_hash_stream_md4_append_u8s         (hash_stream_any1_bare->m_data.m_md4         , u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_md5         : mk_lib_crypto_hash_stream_md5_append_u8s         (hash_stream_any1_bare->m_data.m_md5         , u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha0        : mk_lib_crypto_hash_stream_sha0_append_u8s        (hash_stream_any1_bare->m_data.m_sha0        , u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha1        : mk_lib_crypto_hash_stream_sha1_append_u8s        (hash_stream_any1_bare->m_data.m_sha1        , u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_224    : mk_lib_crypto_hash_stream_sha2_224_append_u8s    (hash_stream_any1_bare->m_data.m_sha2_224    , u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_256    : mk_lib_crypto_hash_stream_sha2_256_append_u8s    (hash_stream_any1_bare->m_data.m_sha2_256    , u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_384    : mk_lib_crypto_hash_stream_sha2_384_append_u8s    (hash_stream_any1_bare->m_data.m_sha2_384    , u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_512    : mk_lib_crypto_hash_stream_sha2_512_append_u8s    (hash_stream_any1_bare->m_data.m_sha2_512    , u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_512_224: mk_lib_crypto_hash_stream_sha2_512_224_append_u8s(hash_stream_any1_bare->m_data.m_sha2_512_224, u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_512_256: mk_lib_crypto_hash_stream_sha2_512_256_append_u8s(hash_stream_any1_bare->m_data.m_sha2_512_256, u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_224    : mk_lib_crypto_hash_stream_sha3_224_append_u8s    (hash_stream_any1_bare->m_data.m_sha3_224    , u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_256    : mk_lib_crypto_hash_stream_sha3_256_append_u8s    (hash_stream_any1_bare->m_data.m_sha3_256    , u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_384    : mk_lib_crypto_hash_stream_sha3_384_append_u8s    (hash_stream_any1_bare->m_data.m_sha3_384    , u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_512    : mk_lib_crypto_hash_stream_sha3_512_append_u8s    (hash_stream_any1_bare->m_data.m_sha3_512    , u8s, count); break;
		case mk_lib_crypto_hash_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any1_bare_finish(mk_lib_crypto_hash_stream_any1_bare_pt const hash_stream_any1_bare, mk_lib_crypto_hash_stream_any1_id_t const id, mk_sl_cui_uint8_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_stream_any1_digest_t dgst mk_lang_constexpr_init;

	mk_lang_assert(hash_stream_any1_bare);
	mk_lang_assert(((mk_lang_types_sint_t)(id)) >= 0 && ((mk_lang_types_sint_t)(id)) <= ((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_any1_id_e_dummy_end)));

	switch(id)
	{
		case mk_lib_crypto_hash_stream_any1_id_e_md2         : mk_lib_crypto_hash_stream_md2_finish         (hash_stream_any1_bare->m_data.m_md2         , &dgst.m_data.m_md2         ); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_md2.m_data.m_uint8s[0],          mk_lib_crypto_hash_stream_md2_digest_len_v         ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_md4         : mk_lib_crypto_hash_stream_md4_finish         (hash_stream_any1_bare->m_data.m_md4         , &dgst.m_data.m_md4         ); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_md4.m_data.m_uint8s[0],          mk_lib_crypto_hash_stream_md4_digest_len_v         ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_md5         : mk_lib_crypto_hash_stream_md5_finish         (hash_stream_any1_bare->m_data.m_md5         , &dgst.m_data.m_md5         ); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_md5.m_data.m_uint8s[0],          mk_lib_crypto_hash_stream_md5_digest_len_v         ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha0        : mk_lib_crypto_hash_stream_sha0_finish        (hash_stream_any1_bare->m_data.m_sha0        , &dgst.m_data.m_sha0        ); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_sha0.m_data.m_uint8s[0],         mk_lib_crypto_hash_stream_sha0_digest_len_v        ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha1        : mk_lib_crypto_hash_stream_sha1_finish        (hash_stream_any1_bare->m_data.m_sha1        , &dgst.m_data.m_sha1        ); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_sha1.m_data.m_uint8s[0],         mk_lib_crypto_hash_stream_sha1_digest_len_v        ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_224    : mk_lib_crypto_hash_stream_sha2_224_finish    (hash_stream_any1_bare->m_data.m_sha2_224    , &dgst.m_data.m_sha2_224    ); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_sha2_224.m_data.m_uint8s[0],     mk_lib_crypto_hash_stream_sha2_224_digest_len_v    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_256    : mk_lib_crypto_hash_stream_sha2_256_finish    (hash_stream_any1_bare->m_data.m_sha2_256    , &dgst.m_data.m_sha2_256    ); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_sha2_256.m_data.m_uint8s[0],     mk_lib_crypto_hash_stream_sha2_256_digest_len_v    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_384    : mk_lib_crypto_hash_stream_sha2_384_finish    (hash_stream_any1_bare->m_data.m_sha2_384    , &dgst.m_data.m_sha2_384    ); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_sha2_384.m_data.m_uint8s[0],     mk_lib_crypto_hash_stream_sha2_384_digest_len_v    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_512    : mk_lib_crypto_hash_stream_sha2_512_finish    (hash_stream_any1_bare->m_data.m_sha2_512    , &dgst.m_data.m_sha2_512    ); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_sha2_512.m_data.m_uint8s[0],     mk_lib_crypto_hash_stream_sha2_512_digest_len_v    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_512_224: mk_lib_crypto_hash_stream_sha2_512_224_finish(hash_stream_any1_bare->m_data.m_sha2_512_224, &dgst.m_data.m_sha2_512_224); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_sha2_512_224.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha2_512_224_digest_len_v); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha2_512_256: mk_lib_crypto_hash_stream_sha2_512_256_finish(hash_stream_any1_bare->m_data.m_sha2_512_256, &dgst.m_data.m_sha2_512_256); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_sha2_512_256.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha2_512_256_digest_len_v); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_224    : mk_lib_crypto_hash_stream_sha3_224_finish    (hash_stream_any1_bare->m_data.m_sha3_224    , &dgst.m_data.m_sha3_224    ); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_sha3_224.m_data.m_uint8s[0],     mk_lib_crypto_hash_stream_sha3_224_digest_len_v    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_256    : mk_lib_crypto_hash_stream_sha3_256_finish    (hash_stream_any1_bare->m_data.m_sha3_256    , &dgst.m_data.m_sha3_256    ); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_sha3_256.m_data.m_uint8s[0],     mk_lib_crypto_hash_stream_sha3_256_digest_len_v    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_384    : mk_lib_crypto_hash_stream_sha3_384_finish    (hash_stream_any1_bare->m_data.m_sha3_384    , &dgst.m_data.m_sha3_384    ); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_sha3_384.m_data.m_uint8s[0],     mk_lib_crypto_hash_stream_sha3_384_digest_len_v    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_sha3_512    : mk_lib_crypto_hash_stream_sha3_512_finish    (hash_stream_any1_bare->m_data.m_sha3_512    , &dgst.m_data.m_sha3_512    ); mk_sl_cui_uint8_memcpy_fn(&digest[0], &dgst.m_data.m_sha3_512.m_data.m_uint8s[0],     mk_lib_crypto_hash_stream_sha3_512_digest_len_v    ); break;
		case mk_lib_crypto_hash_stream_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any1_ptrid_init(mk_lib_crypto_hash_stream_any1_ptrid_pt const hash_stream_any1_ptrid, mk_lib_crypto_hash_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(hash_stream_any1_ptrid);
	mk_lang_assert(((mk_lang_types_sint_t)(id)) >= 0 && ((mk_lang_types_sint_t)(id)) <= ((mk_lang_types_sint_t)(mk_lib_crypto_hash_stream_any1_id_e_dummy_end)));

	hash_stream_any1_ptrid->m_id = id;
	mk_lib_crypto_hash_stream_any1_bare_init(&hash_stream_any1_ptrid->m_ptr, id);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any1_ptrid_append_u8s(mk_lib_crypto_hash_stream_any1_ptrid_pt const hash_stream_any1_ptrid, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_assert(hash_stream_any1_ptrid);

	mk_lib_crypto_hash_stream_any1_bare_append_u8s(&hash_stream_any1_ptrid->m_ptr, hash_stream_any1_ptrid->m_id, u8s, count);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_stream_any1_ptrid_finish(mk_lib_crypto_hash_stream_any1_ptrid_pt const hash_stream_any1_ptrid, mk_sl_cui_uint8_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(hash_stream_any1_ptrid);

	mk_lib_crypto_hash_stream_any1_bare_finish(&hash_stream_any1_ptrid->m_ptr, hash_stream_any1_ptrid->m_id, digest);
}


#endif
