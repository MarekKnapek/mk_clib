#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_lib_crypto_hash_stream_inl_defd.h"


struct mk_lib_crypto_hash_stream_inl_defd_s
{
	mk_lib_crypto_hash_stream_inl_defd_base_t m_base;
	int m_idx;
	mk_lib_crypto_hash_stream_inl_defd_base_block_t m_block;
};
typedef struct mk_lib_crypto_hash_stream_inl_defd_s mk_lib_crypto_hash_stream_inl_defd_t;
typedef mk_lib_crypto_hash_stream_inl_defd_t const mk_lib_crypto_hash_stream_inl_defd_ct;
typedef mk_lib_crypto_hash_stream_inl_defd_t* mk_lib_crypto_hash_stream_inl_defd_pt;
typedef mk_lib_crypto_hash_stream_inl_defd_t const* mk_lib_crypto_hash_stream_inl_defd_pct;


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_stream_inl_defd_init(mk_lib_crypto_hash_stream_inl_defd_pt const hash) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_stream_inl_defd_append(mk_lib_crypto_hash_stream_inl_defd_pt const hash, mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_hash_stream_inl_defd_finish(mk_lib_crypto_hash_stream_inl_defd_pt const hash, mk_lib_crypto_hash_stream_inl_defd_base_digest_pt const digest) mk_lang_noexcept;


#include "mk_lib_crypto_hash_stream_inl_defu.h"
