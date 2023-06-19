#include "../../src/mk_lang_cpp.h"
#include "../../src/mk_lang_inline.h"
#include "../../src/mk_lang_likely.h"
#include "../../src/mk_lang_noexcept.h"
#include "../../src/mk_lang_types.h"
#include "../../src/mk_lib_crypto_hash_stream_md2.h"
#include "../../src/mk_lib_crypto_hash_stream_md4.h"
#include "../../src/mk_lib_crypto_hash_stream_md5.h"
#include "../../src/mk_lib_crypto_hash_stream_sha0.h"
#include "../../src/mk_lib_crypto_hash_stream_sha1.h"
#include "../../src/mk_lib_crypto_hash_stream_sha2_224.h"
#include "../../src/mk_lib_crypto_hash_stream_sha2_256.h"
#include "../../src/mk_lib_crypto_hash_stream_sha2_384.h"
#include "../../src/mk_lib_crypto_hash_stream_sha2_512.h"
#include "../../src/mk_lib_crypto_hash_stream_sha2_512_224.h"
#include "../../src/mk_lib_crypto_hash_stream_sha2_512_256.h"
#include "../../src/mk_lib_crypto_hash_stream_sha3_224.h"
#include "../../src/mk_lib_crypto_hash_stream_sha3_256.h"
#include "../../src/mk_lib_crypto_hash_stream_sha3_384.h"
#include "../../src/mk_lib_crypto_hash_stream_sha3_512.h"
#include "../../src/mk_lib_crypto_xof_stream_shake_128.h"
#include "../../src/mk_lib_crypto_xof_stream_shake_256.h"
#include "../../src/mk_sl_uint8.h"


enum hash_id_e
{
	hash_id_e_md2,
	hash_id_e_md4,
	hash_id_e_md5,
	hash_id_e_sha0,
	hash_id_e_sha1,
	hash_id_e_sha2_224,
	hash_id_e_sha2_256,
	hash_id_e_sha2_384,
	hash_id_e_sha2_512,
	hash_id_e_sha2_512_224,
	hash_id_e_sha2_512_256,
	hash_id_e_sha3_224,
	hash_id_e_sha3_256,
	hash_id_e_sha3_384,
	hash_id_e_sha3_512,
	hash_id_e_shake_128,
	hash_id_e_shake_256,
	hash_id_e_dummy_end
};
typedef enum hash_id_e hash_id_t;


union hash_u
{
	mk_lib_crypto_hash_stream_md2_t m_md2;
	mk_lib_crypto_hash_stream_md4_t m_md4;
	mk_lib_crypto_hash_stream_md5_t m_md5;
	mk_lib_crypto_hash_stream_sha0_t m_sha0;
	mk_lib_crypto_hash_stream_sha1_t m_sha1;
	mk_lib_crypto_hash_stream_sha2_224_t m_sha2_224;
	mk_lib_crypto_hash_stream_sha2_256_t m_sha2_256;
	mk_lib_crypto_hash_stream_sha2_384_t m_sha2_384;
	mk_lib_crypto_hash_stream_sha2_512_t m_sha2_512;
	mk_lib_crypto_hash_stream_sha2_512_224_t m_sha2_512_224;
	mk_lib_crypto_hash_stream_sha2_512_256_t m_sha2_512_256;
	mk_lib_crypto_hash_stream_sha3_224_t m_sha3_224;
	mk_lib_crypto_hash_stream_sha3_256_t m_sha3_256;
	mk_lib_crypto_hash_stream_sha3_384_t m_sha3_384;
	mk_lib_crypto_hash_stream_sha3_512_t m_sha3_512;
	mk_lib_crypto_xof_stream_shake_128_t m_shake_128;
	mk_lib_crypto_xof_stream_shake_256_t m_shake_256;
};
typedef union hash_u hash_t;
typedef hash_t* hash_pt;


union digest_aligned16k_u
{
	mk_sl_cui_uint8_t m_uint8s[16 * 1024];
	mk_lang_types_ulllong_t m_ulllong;
};
typedef union digest_aligned16k_u digest_aligned16k_t;
typedef digest_aligned16k_t const digest_aligned16k_ct;
typedef digest_aligned16k_t* digest_aligned16k_pt;
typedef digest_aligned16k_t const* digest_aligned16k_pct;


static mk_lang_inline void init(hash_pt const hash, hash_id_t const id) mk_lang_noexcept
{
	switch(id)
	{
		case hash_id_e_md2:          mk_lib_crypto_hash_stream_md2_init         (&hash->m_md2         ); break;
		case hash_id_e_md4:          mk_lib_crypto_hash_stream_md4_init         (&hash->m_md4         ); break;
		case hash_id_e_md5:          mk_lib_crypto_hash_stream_md5_init         (&hash->m_md5         ); break;
		case hash_id_e_sha0:         mk_lib_crypto_hash_stream_sha0_init        (&hash->m_sha0        ); break;
		case hash_id_e_sha1:         mk_lib_crypto_hash_stream_sha1_init        (&hash->m_sha1        ); break;
		case hash_id_e_sha2_224:     mk_lib_crypto_hash_stream_sha2_224_init    (&hash->m_sha2_224    ); break;
		case hash_id_e_sha2_256:     mk_lib_crypto_hash_stream_sha2_256_init    (&hash->m_sha2_256    ); break;
		case hash_id_e_sha2_384:     mk_lib_crypto_hash_stream_sha2_384_init    (&hash->m_sha2_384    ); break;
		case hash_id_e_sha2_512:     mk_lib_crypto_hash_stream_sha2_512_init    (&hash->m_sha2_512    ); break;
		case hash_id_e_sha2_512_224: mk_lib_crypto_hash_stream_sha2_512_224_init(&hash->m_sha2_512_224); break;
		case hash_id_e_sha2_512_256: mk_lib_crypto_hash_stream_sha2_512_256_init(&hash->m_sha2_512_256); break;
		case hash_id_e_sha3_224:     mk_lib_crypto_hash_stream_sha3_224_init    (&hash->m_sha3_224    ); break;
		case hash_id_e_sha3_256:     mk_lib_crypto_hash_stream_sha3_256_init    (&hash->m_sha3_256    ); break;
		case hash_id_e_sha3_384:     mk_lib_crypto_hash_stream_sha3_384_init    (&hash->m_sha3_384    ); break;
		case hash_id_e_sha3_512:     mk_lib_crypto_hash_stream_sha3_512_init    (&hash->m_sha3_512    ); break;
		case hash_id_e_shake_128:    mk_lib_crypto_xof_stream_shake_128_init    (&hash->m_shake_128   ); break;
		case hash_id_e_shake_256:    mk_lib_crypto_xof_stream_shake_256_init    (&hash->m_shake_256   ); break;
	}
}

static mk_lang_inline void append(hash_pt const hash, hash_id_t const id, mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const data_len) mk_lang_noexcept
{
	switch(id)
	{
		case hash_id_e_md2:          mk_lib_crypto_hash_stream_md2_append         (&hash->m_md2         , data, data_len); break;
		case hash_id_e_md4:          mk_lib_crypto_hash_stream_md4_append         (&hash->m_md4         , data, data_len); break;
		case hash_id_e_md5:          mk_lib_crypto_hash_stream_md5_append         (&hash->m_md5         , data, data_len); break;
		case hash_id_e_sha0:         mk_lib_crypto_hash_stream_sha0_append        (&hash->m_sha0        , data, data_len); break;
		case hash_id_e_sha1:         mk_lib_crypto_hash_stream_sha1_append        (&hash->m_sha1        , data, data_len); break;
		case hash_id_e_sha2_224:     mk_lib_crypto_hash_stream_sha2_224_append    (&hash->m_sha2_224    , data, data_len); break;
		case hash_id_e_sha2_256:     mk_lib_crypto_hash_stream_sha2_256_append    (&hash->m_sha2_256    , data, data_len); break;
		case hash_id_e_sha2_384:     mk_lib_crypto_hash_stream_sha2_384_append    (&hash->m_sha2_384    , data, data_len); break;
		case hash_id_e_sha2_512:     mk_lib_crypto_hash_stream_sha2_512_append    (&hash->m_sha2_512    , data, data_len); break;
		case hash_id_e_sha2_512_224: mk_lib_crypto_hash_stream_sha2_512_224_append(&hash->m_sha2_512_224, data, data_len); break;
		case hash_id_e_sha2_512_256: mk_lib_crypto_hash_stream_sha2_512_256_append(&hash->m_sha2_512_256, data, data_len); break;
		case hash_id_e_sha3_224:     mk_lib_crypto_hash_stream_sha3_224_append    (&hash->m_sha3_224    , data, data_len); break;
		case hash_id_e_sha3_256:     mk_lib_crypto_hash_stream_sha3_256_append    (&hash->m_sha3_256    , data, data_len); break;
		case hash_id_e_sha3_384:     mk_lib_crypto_hash_stream_sha3_384_append    (&hash->m_sha3_384    , data, data_len); break;
		case hash_id_e_sha3_512:     mk_lib_crypto_hash_stream_sha3_512_append    (&hash->m_sha3_512    , data, data_len); break;
		case hash_id_e_shake_128:    mk_lib_crypto_xof_stream_shake_128_append    (&hash->m_shake_128   , data, data_len); break;
		case hash_id_e_shake_256:    mk_lib_crypto_xof_stream_shake_256_append    (&hash->m_shake_256   , data, data_len); break;
	}
}

static mk_lang_inline void finish(hash_pt const hash, hash_id_t const id, int const xof_len, digest_aligned16k_pt const digest) mk_lang_noexcept
{
	switch(id)
	{
		case hash_id_e_md2:          mk_lib_crypto_hash_stream_md2_finish         (&hash->m_md2         ,          ((mk_lib_crypto_hash_block_md2_digest_pt         )(digest))); break;
		case hash_id_e_md4:          mk_lib_crypto_hash_stream_md4_finish         (&hash->m_md4         ,          ((mk_lib_crypto_hash_block_md4_digest_pt         )(digest))); break;
		case hash_id_e_md5:          mk_lib_crypto_hash_stream_md5_finish         (&hash->m_md5         ,          ((mk_lib_crypto_hash_block_md5_digest_pt         )(digest))); break;
		case hash_id_e_sha0:         mk_lib_crypto_hash_stream_sha0_finish        (&hash->m_sha0        ,          ((mk_lib_crypto_hash_block_sha0_digest_pt        )(digest))); break;
		case hash_id_e_sha1:         mk_lib_crypto_hash_stream_sha1_finish        (&hash->m_sha1        ,          ((mk_lib_crypto_hash_block_sha1_digest_pt        )(digest))); break;
		case hash_id_e_sha2_224:     mk_lib_crypto_hash_stream_sha2_224_finish    (&hash->m_sha2_224    ,          ((mk_lib_crypto_hash_block_sha2_224_digest_pt    )(digest))); break;
		case hash_id_e_sha2_256:     mk_lib_crypto_hash_stream_sha2_256_finish    (&hash->m_sha2_256    ,          ((mk_lib_crypto_hash_block_sha2_256_digest_pt    )(digest))); break;
		case hash_id_e_sha2_384:     mk_lib_crypto_hash_stream_sha2_384_finish    (&hash->m_sha2_384    ,          ((mk_lib_crypto_hash_block_sha2_384_digest_pt    )(digest))); break;
		case hash_id_e_sha2_512:     mk_lib_crypto_hash_stream_sha2_512_finish    (&hash->m_sha2_512    ,          ((mk_lib_crypto_hash_block_sha2_512_digest_pt    )(digest))); break;
		case hash_id_e_sha2_512_224: mk_lib_crypto_hash_stream_sha2_512_224_finish(&hash->m_sha2_512_224,          ((mk_lib_crypto_hash_block_sha2_512_224_digest_pt)(digest))); break;
		case hash_id_e_sha2_512_256: mk_lib_crypto_hash_stream_sha2_512_256_finish(&hash->m_sha2_512_256,          ((mk_lib_crypto_hash_block_sha2_512_256_digest_pt)(digest))); break;
		case hash_id_e_sha3_224:     mk_lib_crypto_hash_stream_sha3_224_finish    (&hash->m_sha3_224    ,          ((mk_lib_crypto_hash_block_sha3_224_digest_pt    )(digest))); break;
		case hash_id_e_sha3_256:     mk_lib_crypto_hash_stream_sha3_256_finish    (&hash->m_sha3_256    ,          ((mk_lib_crypto_hash_block_sha3_256_digest_pt    )(digest))); break;
		case hash_id_e_sha3_384:     mk_lib_crypto_hash_stream_sha3_384_finish    (&hash->m_sha3_384    ,          ((mk_lib_crypto_hash_block_sha3_384_digest_pt    )(digest))); break;
		case hash_id_e_sha3_512:     mk_lib_crypto_hash_stream_sha3_512_finish    (&hash->m_sha3_512    ,          ((mk_lib_crypto_hash_block_sha3_512_digest_pt    )(digest))); break;
		case hash_id_e_shake_128:    mk_lib_crypto_xof_stream_shake_128_finish    (&hash->m_shake_128   , xof_len, ((mk_lib_crypto_xof_block_shake_128_digest_pt    )(digest))); break;
		case hash_id_e_shake_256:    mk_lib_crypto_xof_stream_shake_256_finish    (&hash->m_shake_256   , xof_len, ((mk_lib_crypto_xof_block_shake_256_digest_pt    )(digest))); break;
	}
}

static mk_lang_inline void copy(hash_id_t const id, int const xof_len, digest_aligned16k_pct const aligned_digest, mk_lang_types_uchar_pt const digest, mk_lang_types_sint_pt const ret_len) mk_lang_noexcept
{
	int n;
	int i;

	switch(id)
	{
		case hash_id_e_md2:          n = mk_lib_crypto_hash_block_md2_digest_len         ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_md4:          n = mk_lib_crypto_hash_block_md4_digest_len         ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_md5:          n = mk_lib_crypto_hash_block_md5_digest_len         ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_sha0:         n = mk_lib_crypto_hash_block_sha0_digest_len        ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_sha1:         n = mk_lib_crypto_hash_block_sha1_digest_len        ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_sha2_224:     n = mk_lib_crypto_hash_block_sha2_224_digest_len    ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_sha2_256:     n = mk_lib_crypto_hash_block_sha2_256_digest_len    ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_sha2_384:     n = mk_lib_crypto_hash_block_sha2_384_digest_len    ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_sha2_512:     n = mk_lib_crypto_hash_block_sha2_512_digest_len    ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_sha2_512_224: n = mk_lib_crypto_hash_block_sha2_512_224_digest_len; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_sha2_512_256: n = mk_lib_crypto_hash_block_sha2_512_256_digest_len; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_sha3_224:     n = mk_lib_crypto_hash_block_sha3_224_digest_len    ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_sha3_256:     n = mk_lib_crypto_hash_block_sha3_256_digest_len    ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_sha3_384:     n = mk_lib_crypto_hash_block_sha3_384_digest_len    ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_sha3_512:     n = mk_lib_crypto_hash_block_sha3_512_digest_len    ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_shake_128:    n = xof_len                                         ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
		case hash_id_e_shake_256:    n = xof_len                                         ; for(i = 0; i != n; ++i){ mk_sl_cui_uint8_to_bi_uchar(&aligned_digest->m_uint8s[i], &digest[i]); } *ret_len = n; break;
	}
}


#define check(x) if(!(x)){ mk_lang_unlikely return 0; }


mk_lang_extern_c int mkch(int const hash_id, int const xof_len, mk_lang_types_uchar_pct data, int const data_len, mk_lang_types_uchar_pt const digest, int const digest_len, mk_lang_types_sint_pt const ret_len) mk_lang_noexcept
{
	hash_id_t id;
	hash_t hash;
	digest_aligned16k_t aligned_digest;

	check(hash_id >= hash_id_e_md2);
	check(hash_id <= hash_id_e_shake_256);
	check(xof_len >= 1);
	check(xof_len <= 16 * 1024);
	check(data || data_len == 0);
	check(data_len >= 0);
	check(data_len <= 1 * 1024 * 1024);
	check(digest);
	check(digest_len >= 16 * 1024);
	check(ret_len);

	*ret_len = 0;
	id = ((hash_id_t)(hash_id));
	init(&hash, id);
	append(&hash, id, data, data_len);
	finish(&hash, id, xof_len, &aligned_digest);
	copy(id, xof_len, &aligned_digest, digest, ret_len);
	return 1;
}


#undef check
