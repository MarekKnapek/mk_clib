#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


#include "mk_lib_crypto_xof_stream_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_inl_defd_init(mk_lib_crypto_xof_stream_inl_defd_pt const stream) mk_lang_noexcept
{
	mk_lang_assert(stream);

	mk_lib_crypto_xof_stream_inl_defd_base_init(&stream->m_base);
	stream->m_idx = 0;
}

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_inl_defd_append_u8s(mk_lib_crypto_xof_stream_inl_defd_pt const stream, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t free mk_lang_constexpr_init;
	mk_lang_types_usize_t nblocks mk_lang_constexpr_init;
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(stream);
	mk_lang_assert(u8s || count == 0);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	ptr = u8s;
	rem = count;
	free = mk_lib_crypto_xof_stream_inl_defd_base_block_len_v - stream->m_idx;
	#if mk_lib_crypto_xof_stream_inl_defd_padding
	if(rem >= ((mk_lang_types_usize_t)(free)))
	#else
	if(rem > ((mk_lang_types_usize_t)(free)))
	#endif
	{
		if(stream->m_idx != 0)
		{
			mk_sl_cui_uint8_memcpy_fn(&stream->m_block.m_data.m_uint8s[stream->m_idx], &ptr[0], ((mk_lang_types_usize_t)(free)));
			mk_lib_crypto_xof_stream_inl_defd_base_append_blocks(&stream->m_base, &stream->m_block, 1);
			stream->m_idx = 0;
			ptr += ((mk_lang_types_usize_t)(free));
			rem -= ((mk_lang_types_usize_t)(free));
		}
		#if mk_lib_crypto_xof_stream_inl_defd_padding
		nblocks = rem / mk_lib_crypto_xof_stream_inl_defd_base_block_len_v;
		#else
		nblocks = mk_lang_roundup_div(rem, mk_lib_crypto_xof_stream_inl_defd_base_block_len_v) - 1;
		#endif
		#include "mk_lang_warning_msvc_push_c4826.h"
		if(!mk_lang_constexpr_is_constant_evaluated_test && ((mk_lang_types_uintptr_t)(ptr)) % mk_lang_alignof(mk_lib_crypto_xof_stream_inl_defd_base_block_t) == 0)
		#include "mk_lang_warning_msvc_pop.h"
		{
			#include "mk_lang_warning_clang_push_cast_align.h"
			mk_lib_crypto_xof_stream_inl_defd_base_append_blocks(&stream->m_base, ((mk_lib_crypto_xof_stream_inl_defd_base_block_pct)(ptr)), nblocks);
			#include "mk_lang_warning_clang_pop.h"
		}
		else
		{
			for(iblock = 0; iblock != nblocks; ++iblock)
			{
				mk_sl_cui_uint8_memcpy_fn(&stream->m_block.m_data.m_uint8s[0], &ptr[iblock * mk_lib_crypto_xof_stream_inl_defd_base_block_len_v], mk_lib_crypto_xof_stream_inl_defd_base_block_len_v);
				mk_lib_crypto_xof_stream_inl_defd_base_append_blocks(&stream->m_base, &stream->m_block, 1);
			}
		}
		ptr += nblocks * mk_lib_crypto_xof_stream_inl_defd_base_block_len_v;
		rem -= nblocks * mk_lib_crypto_xof_stream_inl_defd_base_block_len_v;
	}
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	#if mk_lib_crypto_xof_stream_inl_defd_padding
	mk_lang_assert(rem >= 0 && rem < mk_lib_crypto_xof_stream_inl_defd_base_block_len_v);
	#else
	mk_lang_assert(rem >= 0 && rem <= mk_lib_crypto_xof_stream_inl_defd_base_block_len_v);
	#endif
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"
	#if mk_lib_crypto_xof_stream_inl_defd_padding
	mk_lang_assert(((mk_lang_types_sint_t)(rem)) + stream->m_idx < mk_lib_crypto_xof_stream_inl_defd_base_block_len_v);
	#else
	mk_lang_assert(((mk_lang_types_sint_t)(rem)) + stream->m_idx <= mk_lib_crypto_xof_stream_inl_defd_base_block_len_v);
	#endif
	if(rem != 0)
	{
		mk_sl_cui_uint8_memcpy_fn(&stream->m_block.m_data.m_uint8s[stream->m_idx], ptr, rem);
		stream->m_idx += ((mk_lang_types_sint_t)(rem));
	}
}
#include "mk_lang_warning_msvc_pop.h"

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_inl_defd_finish(mk_lib_crypto_xof_stream_inl_defd_pt const stream) mk_lang_noexcept
{
	mk_lang_assert(stream);

	mk_lib_crypto_xof_stream_inl_defd_base_finish(&stream->m_base, &stream->m_block, stream->m_idx);
	stream->m_idx = mk_lib_crypto_xof_stream_inl_defd_base_digest_len_v;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_stream_inl_defd_squeeze_u8s(mk_lib_crypto_xof_stream_inl_defd_pt const stream, mk_sl_cui_uint8_pt const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t avail mk_lang_constexpr_init;
	mk_lang_types_usize_t to_copy mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(stream);
	mk_lang_assert(u8s || count == 0);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	ptr = u8s;
	rem = count;
	avail = mk_lib_crypto_xof_stream_inl_defd_base_digest_len_v - stream->m_idx;
	to_copy = mk_lang_min(rem, ((mk_lang_types_usize_t)(avail)));
	if(to_copy != 0)
	{
		mk_sl_cui_uint8_memcpy_fn(&ptr[0], &stream->m_digest.m_data.m_uint8s[stream->m_idx], to_copy);
	}
	stream->m_idx += ((mk_lang_types_sint_t)(to_copy));
	ptr += to_copy;
	rem -= to_copy;
	if(rem >= mk_lib_crypto_xof_stream_inl_defd_base_digest_len_v)
	{
		do
		{
			mk_lib_crypto_xof_stream_inl_defd_base_squeeze_block(&stream->m_base, &stream->m_digest);
			mk_sl_cui_uint8_memcpy_fn(&ptr[0], &stream->m_digest.m_data.m_uint8s[0], mk_lib_crypto_xof_stream_inl_defd_base_digest_len_v);
			ptr += mk_lib_crypto_xof_stream_inl_defd_base_digest_len_v;
			rem -= mk_lib_crypto_xof_stream_inl_defd_base_digest_len_v;
		}while(rem >= mk_lib_crypto_xof_stream_inl_defd_base_digest_len_v);
		stream->m_idx = mk_lib_crypto_xof_stream_inl_defd_base_digest_len_v;
	}
	if(rem != 0)
	{
		if(stream->m_idx == mk_lib_crypto_xof_stream_inl_defd_base_digest_len_v)
		{
			mk_lib_crypto_xof_stream_inl_defd_base_squeeze_block(&stream->m_base, &stream->m_digest);
			stream->m_idx = 0;
		}
		#include "mk_lang_warning_msvc_push_c4296.h"
		#include "mk_lang_warning_gcc_push_type_limits.h"
		mk_lang_assert(rem >= 1 && rem <= ((mk_lang_types_usize_t)(mk_lib_crypto_xof_stream_inl_defd_base_digest_len_v - stream->m_idx)));
		#include "mk_lang_warning_gcc_pop.h"
		#include "mk_lang_warning_msvc_pop.h"
		mk_sl_cui_uint8_memcpy_fn(&ptr[0], &stream->m_digest.m_data.m_uint8s[stream->m_idx], rem);
		stream->m_idx += ((mk_lang_types_sint_t)(rem));
	}
}


 #include "mk_lib_crypto_xof_stream_inl_defu.h"
