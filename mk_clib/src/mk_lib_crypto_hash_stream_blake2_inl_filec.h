#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_sl_uint8.h"


#include "mk_lib_crypto_hash_stream_blake2_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_stream_blake2_inl_defd_init(mk_lib_crypto_hash_stream_blake2_inl_defd_pt const hash, int const digest_len, mk_lang_types_uchar_pct const key, int const key_len) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(hash);

	mk_lib_crypto_hash_stream_blake2_inl_defd_base_init(&hash->m_base, digest_len, key_len, 1, 1, 0, 0, 0, 0, 0, mk_lang_null, 0, mk_lang_null, 0);
	hash->m_idx = 0;
	if(key_len != 0)
	{
		for(i = 0; i != key_len; ++i){ mk_sl_cui_uint8_from_bi_uchar(&hash->m_block.m_uint8s[i],&key[i]); }
		for(i = key_len; i != mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len; ++i){ mk_sl_cui_uint8_set_zero(&hash->m_block.m_uint8s[i]); }
		hash->m_idx = mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len;
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_stream_blake2_inl_defd_append_u8(mk_lib_crypto_hash_stream_blake2_inl_defd_pt const hash, mk_sl_cui_uint8_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	int free mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	mk_lang_types_usize_t blocks mk_lang_constexpr_init;
	mk_lang_types_usize_t j mk_lang_constexpr_init;

	mk_lang_assert(hash);
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	ptr = data;
	rem = size;
	free = mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len - hash->m_idx;
	if(rem > ((mk_lang_types_usize_t)(free)))
	{
		if(hash->m_idx != 0)
		{
			for(i = 0; i != free; ++i){ hash->m_block.m_uint8s[hash->m_idx + i] = ptr[i]; }
			ptr += free;
			rem -= free;
			hash->m_idx = 0;
			mk_lib_crypto_hash_stream_blake2_inl_defd_base_append_blocks(&hash->m_base, &hash->m_block, 1);
		}
		blocks = mk_lang_div_roundup(rem, mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len) - 1;
		if(!mk_lang_constexpr_is_constant_evaluated_test && ((((mk_lang_types_uintptr_t)(ptr)) % mk_lang_alignof(mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_t)) == 0))
		{
			mk_lib_crypto_hash_stream_blake2_inl_defd_base_append_blocks(&hash->m_base, ((mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_pct)(ptr)), blocks);
		}
		else
		{
			for(j = 0; j != blocks; ++j)
			{
				for(i = 0; i != mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len; ++i){ hash->m_block.m_uint8s[i] = ptr[j * mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len + i]; }
				mk_lib_crypto_hash_stream_blake2_inl_defd_base_append_blocks(&hash->m_base, &hash->m_block, 1);
			}
		}
		ptr += blocks * mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len;
		rem -= blocks * mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len;
	}
	mk_lang_assert(rem >= 0 && rem <= mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len);
	mk_lang_assert(((int)(rem)) + hash->m_idx <= mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len);
	for(i = 0; i != ((int)(rem)); ++i){ hash->m_block.m_uint8s[hash->m_idx + i] = ptr[i]; }
	hash->m_idx += ((int)(rem));
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_stream_blake2_inl_defd_append(mk_lib_crypto_hash_stream_blake2_inl_defd_pt const hash, mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t j mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_usize_t m mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_t block mk_lang_constexpr_init;

	mk_lang_assert(hash);
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lib_crypto_hash_stream_blake2_inl_defd_append_u8(hash, ((mk_sl_cui_uint8_pct)(data)), size);
	}
	else
	{
		n = size / mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len;
		for(j = 0; j != n; ++j)
		{
			for(i = 0; i != mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len; ++i){ mk_sl_cui_uint8_from_bi_uchar(&block.m_uint8s[i], &data[j * mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len + i]); }
			mk_lib_crypto_hash_stream_blake2_inl_defd_append_u8(hash, &block.m_uint8s[0], mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len);
		}
		m = size - n * mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len;
		if(m != 0)
		{
			for(i = 0; i != m; ++i){ mk_sl_cui_uint8_from_bi_uchar(&block.m_uint8s[i], &data[n * mk_lib_crypto_hash_stream_blake2_inl_defd_base_block_len + i]); }
			mk_lib_crypto_hash_stream_blake2_inl_defd_append_u8(hash, &block.m_uint8s[0], m);
		}
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_stream_blake2_inl_defd_finish(mk_lib_crypto_hash_stream_blake2_inl_defd_pt const hash, mk_lib_crypto_hash_stream_blake2_inl_defd_base_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(hash);
	mk_lang_assert(digest);

	mk_lib_crypto_hash_stream_blake2_inl_defd_base_finish(&hash->m_base, &hash->m_block, hash->m_idx, digest);
}


#include "mk_lib_crypto_hash_stream_blake2_inl_defu.h"


#undef mk_is_constant_evaluated
#undef mk_is_constant_evaluated_test


#undef mk_lib_crypto_hash_stream_blake2_t_name
