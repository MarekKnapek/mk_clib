#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint_strict.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


/* NIST SP 800-38D */


#include "mk_lib_crypto_mode_gcm_be_inl_defd.h"


#define mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_name mk_lang_concat(mk_lib_crypto_mode_gcm_be_inl_defd_prefix, _memcpyu8)
#define mk_lang_memcpy_t_name mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_name
#define mk_lang_memcpy_t_type mk_sl_cui_uint8_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"
#define mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn mk_lang_concat(mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_name, _fn)

#define mk_lib_crypto_mode_gcm_be_inl_filec_memset_name mk_lang_concat(mk_lib_crypto_mode_gcm_be_inl_defd_prefix, _memsetu8)
#define mk_lang_memset_t_name mk_lib_crypto_mode_gcm_be_inl_filec_memset_name
#define mk_lang_memset_t_type mk_sl_cui_uint8_t
#include "mk_lang_memset_inl_fileh.h"
#include "mk_lang_memset_inl_filec.h"
#define mk_lib_crypto_mode_gcm_be_inl_filec_memset_fn mk_lang_concat(mk_lib_crypto_mode_gcm_be_inl_filec_memset_name, _fn)

#define mk_lib_crypto_mode_gcm_be_inl_filec_xor_name mk_lang_concat(mk_lib_crypto_mode_gcm_be_inl_defd_prefix, _xor)
#define mk_lib_crypto_mode_base_t_name mk_lib_crypto_mode_gcm_be_inl_filec_xor_name
#define mk_lib_crypto_mode_base_t_len 16
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"
#define mk_lib_crypto_mode_gcm_be_inl_filec_xor2 mk_lang_concat(mk_lib_crypto_mode_gcm_be_inl_filec_xor_name, _xor2)
#define mk_lib_crypto_mode_gcm_be_inl_filec_xor3 mk_lang_concat(mk_lib_crypto_mode_gcm_be_inl_filec_xor_name, _xor3)


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_init(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_lib_crypto_mode_gcm_be_inl_defd_key_pct const key) mk_lang_noexcept
{
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;
	mk_lib_crypto_mode_gcm_be_inl_defd_alg_msg_t msg0 mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_ghash_block_t gblock mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_crypto_mode_gcm_be_inl_defd_alg_msg_len_v == 16);

	mk_lang_assert(gcm_be);
	mk_lang_assert(key);

	mk_lib_crypto_mode_gcm_be_inl_defd_ctr_expand_enc(&key->m_data, &gcm_be->m_schedule.m_data);
	mk_sl_cui_uint8_set_zero(&tu8);
	mk_lib_crypto_mode_gcm_be_inl_filec_memset_fn(&msg0.m_data.m_uint8s[0], &tu8, 16);
	mk_lib_crypto_mode_gcm_be_inl_defd_alg_schedule_encrypt(&gcm_be->m_schedule.m_data, &msg0, &msg0, 1);
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lib_crypto_hash_block_ghash_init(&gcm_be->m_ghash, ((mk_lib_crypto_hash_block_ghash_block_pct)(&msg0)));
	}
	else
	{
		mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&gblock.m_data.m_uint8s[0], &msg0.m_data.m_uint8s[0], 16);
		mk_lib_crypto_hash_block_ghash_init(&gcm_be->m_ghash, &gblock);
	}
	mk_sl_cui_uint64_set_zero(&gcm_be->m_aad_len);
	mk_sl_cui_uint64_set_zero(&gcm_be->m_ct_len);
	#if mk_lib_crypto_mode_gcm_be_debug
	gcm_be->m_iv_finished = mk_lang_false;
	#endif
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_finish(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_sl_cui_uint8_pct const ct, mk_lang_types_usize_t const len, mk_lib_crypto_mode_gcm_be_inl_defd_msg_pt const tag) mk_lang_noexcept
{
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64a mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64b mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_ghash_digest_t digest mk_lang_constexpr_init;

	mk_lang_assert(gcm_be);
	mk_lang_assert(ct || len == 0);
	mk_lang_assert(len >= 0 && len < 16);
	mk_lang_assert(tag);
	#if mk_lib_crypto_mode_gcm_be_debug
	mk_lang_assert(gcm_be->m_iv_finished);
	mk_lang_assert(gcm_be->m_aad_finished);
	mk_lang_assert(!gcm_be->m_pt_finished);
	#endif

	mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&gcm_be->m_gblock.m_data.m_uint8s[0], &ct[0], len);
	if(len != 0)
	{
		mk_sl_cui_uint8_set_zero(&tu8);
		mk_lib_crypto_mode_gcm_be_inl_filec_memset_fn(&gcm_be->m_gblock.m_data.m_uint8s[len], &tu8, 16 - len);
		mk_lib_crypto_hash_block_ghash_append_blocks(&gcm_be->m_ghash, &gcm_be->m_gblock, 1);
	}
	mk_sl_cui_uint64_from_bi_usize(&tu64a, &len);
	mk_sl_cui_uint64_shl2(&tu64a, 3);
	mk_sl_cui_uint64_shl2(&gcm_be->m_ct_len, 4 + 3);
	mk_lang_assert(((mk_sl_cui_uint64_add3_wrap_cid_cod(&gcm_be->m_ct_len, &tu64a, &tu64b), mk_sl_cui_uint64_ge(&tu64b, &gcm_be->m_ct_len))));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&gcm_be->m_ct_len, &tu64a);
	mk_sl_cui_uint64_shl2(&gcm_be->m_aad_len, 3);
	mk_sl_uint_strict_64_to_8_be(&gcm_be->m_aad_len, &gcm_be->m_gblock.m_data.m_uint8s[0]);
	mk_sl_uint_strict_64_to_8_be(&gcm_be->m_ct_len, &gcm_be->m_gblock.m_data.m_uint8s[8]);
	mk_lib_crypto_hash_block_ghash_append_blocks(&gcm_be->m_ghash, &gcm_be->m_gblock, 1);
	mk_lib_crypto_hash_block_ghash_finish(&gcm_be->m_ghash, &digest);
	mk_lib_crypto_mode_gcm_be_inl_filec_xor3(&digest.m_data.m_uint8s[0], &gcm_be->m_ctr_0_ct.m_data.m_uint8s[0], &tag->m_data.m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_crypt(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_lib_crypto_mode_gcm_be_inl_defd_msg_pct const ct, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64a mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64b mk_lang_constexpr_init;

	mk_lang_assert(gcm_be);
	mk_lang_assert(ct || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / 16);
	#if mk_lib_crypto_mode_gcm_be_debug
	mk_lang_assert(gcm_be->m_iv_finished);
	mk_lang_assert(gcm_be->m_aad_finished);
	mk_lang_assert(!gcm_be->m_pt_finished);
	#endif

	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lib_crypto_hash_block_ghash_append_blocks(&gcm_be->m_ghash, ((mk_lib_crypto_hash_block_ghash_block_pt)(ct)), nblocks);
	}
	else
	{
		n = nblocks;
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&gcm_be->m_gblock.m_data.m_uint8s[0], &ct[i].m_data.m_data.m_uint8s[0], 16);
			mk_lib_crypto_hash_block_ghash_append_blocks(&gcm_be->m_ghash, &gcm_be->m_gblock, 1);
		}
	}
	mk_sl_cui_uint64_from_bi_usize(&tu64a, &nblocks);
	mk_lang_assert(((mk_sl_cui_uint64_add3_wrap_cid_cod(&gcm_be->m_ct_len, &tu64a, &tu64b), mk_sl_cui_uint64_ge(&tu64b, &gcm_be->m_ct_len)) && (mk_sl_cui_uint64_shr2(&tu64b, 64 - 4 - 3), mk_sl_cui_uint64_is_zero(&tu64b))));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&gcm_be->m_ct_len, &tu64a);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_finish_enc(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_sl_cui_uint8_pct const input, mk_sl_cui_uint8_pt const output, mk_lang_types_usize_t const len, mk_lib_crypto_mode_gcm_be_inl_defd_msg_pt const tag) mk_lang_noexcept
{
	mk_lib_crypto_mode_gcm_be_inl_defd_msg_t msg mk_lang_constexpr_init;

	mk_lang_assert(gcm_be);
	mk_lang_assert(input || len == 0);
	mk_lang_assert(output || len == 0);
	mk_lang_assert(len >= 0 && len < 16);
	mk_lang_assert(tag);
	#if mk_lib_crypto_mode_gcm_be_debug
	mk_lang_assert(gcm_be->m_iv_finished);
	mk_lang_assert(gcm_be->m_aad_finished);
	mk_lang_assert(!gcm_be->m_pt_finished);
	#endif

	if(len != 0)
	{
		if(!mk_lang_constexpr_is_constant_evaluated_test)
		{
			mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&gcm_be->m_gblock.m_data.m_uint8s[0], &input[0], len);
			mk_lib_crypto_mode_gcm_be_inl_defd_ctr_schedule_encrypt(&gcm_be->m_ctr, &gcm_be->m_schedule.m_data, ((mk_lib_crypto_mode_gcm_be_inl_defd_alg_msg_pct)(&gcm_be->m_gblock)), ((mk_lib_crypto_mode_gcm_be_inl_defd_alg_msg_pt)(&gcm_be->m_gblock)), 1);
			mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&output[0], &gcm_be->m_gblock.m_data.m_uint8s[0], len);
		}
		else
		{
			mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&msg.m_data.m_data.m_uint8s[0], &input[0], len);
			mk_lib_crypto_mode_gcm_be_inl_defd_ctr_schedule_encrypt(&gcm_be->m_ctr, &gcm_be->m_schedule.m_data, &msg.m_data, &msg.m_data, 1);
			mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&output[0], &msg.m_data.m_data.m_uint8s[0], len);
		}
	}
	mk_lib_crypto_mode_gcm_be_inl_defd_finish(gcm_be, output, len, tag);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_finish_dec(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_sl_cui_uint8_pct const input, mk_sl_cui_uint8_pt const output, mk_lang_types_usize_t const len, mk_lib_crypto_mode_gcm_be_inl_defd_msg_pt const tag) mk_lang_noexcept
{
	mk_lib_crypto_mode_gcm_be_inl_defd_msg_t msg mk_lang_constexpr_init;

	mk_lang_assert(gcm_be);
	mk_lang_assert(input || len == 0);
	mk_lang_assert(output || len == 0);
	mk_lang_assert(len >= 0 && len < 16);
	mk_lang_assert(tag);
	#if mk_lib_crypto_mode_gcm_be_debug
	mk_lang_assert(gcm_be->m_iv_finished);
	mk_lang_assert(gcm_be->m_aad_finished);
	mk_lang_assert(!gcm_be->m_pt_finished);
	#endif

	mk_lib_crypto_mode_gcm_be_inl_defd_finish(gcm_be, input, len, tag);
	if(len != 0)
	{
		if(!mk_lang_constexpr_is_constant_evaluated_test)
		{
			mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&gcm_be->m_gblock.m_data.m_uint8s[0], &input[0], len);
			mk_lib_crypto_mode_gcm_be_inl_defd_ctr_schedule_decrypt(&gcm_be->m_ctr, &gcm_be->m_schedule.m_data, ((mk_lib_crypto_mode_gcm_be_inl_defd_alg_msg_pct)(&gcm_be->m_gblock)), ((mk_lib_crypto_mode_gcm_be_inl_defd_alg_msg_pt)(&gcm_be->m_gblock)), 1);
			mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&output[0], &gcm_be->m_gblock.m_data.m_uint8s[0], len);
		}
		else
		{
			mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&msg.m_data.m_data.m_uint8s[0], &input[0], len);
			mk_lib_crypto_mode_gcm_be_inl_defd_ctr_schedule_decrypt(&gcm_be->m_ctr, &gcm_be->m_schedule.m_data, &msg.m_data, &msg.m_data, 1);
			mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&output[0], &msg.m_data.m_data.m_uint8s[0], len);
		}
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_encrypt(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_lib_crypto_mode_gcm_be_inl_defd_msg_pct const input, mk_lib_crypto_mode_gcm_be_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(gcm_be);
	mk_lang_assert(input || nblocks == 0);
	mk_lang_assert(output || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / 16);
	#if mk_lib_crypto_mode_gcm_be_debug
	mk_lang_assert(gcm_be->m_iv_finished);
	mk_lang_assert(gcm_be->m_aad_finished);
	mk_lang_assert(!gcm_be->m_pt_finished);
	#endif

	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lib_crypto_mode_gcm_be_inl_defd_ctr_schedule_encrypt(&gcm_be->m_ctr, &gcm_be->m_schedule.m_data, &input->m_data, &output->m_data, nblocks);
	}
	else
	{
		n = nblocks;
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_mode_gcm_be_inl_defd_ctr_schedule_encrypt(&gcm_be->m_ctr, &gcm_be->m_schedule.m_data, &input[i].m_data, &output[i].m_data, 1); /* todo */
		}
	}
	mk_lib_crypto_mode_gcm_be_inl_defd_crypt(gcm_be, output, nblocks);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_decrypt(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_lib_crypto_mode_gcm_be_inl_defd_msg_pct const input, mk_lib_crypto_mode_gcm_be_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(gcm_be);
	mk_lang_assert(input || nblocks == 0);
	mk_lang_assert(output || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / 16);
	#if mk_lib_crypto_mode_gcm_be_debug
	mk_lang_assert(gcm_be->m_iv_finished);
	mk_lang_assert(gcm_be->m_aad_finished);
	mk_lang_assert(!gcm_be->m_pt_finished);
	#endif

	mk_lib_crypto_mode_gcm_be_inl_defd_crypt(gcm_be, output, nblocks);
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lib_crypto_mode_gcm_be_inl_defd_ctr_schedule_decrypt(&gcm_be->m_ctr, &gcm_be->m_schedule.m_data, &input->m_data, &output->m_data, nblocks);
	}
	else
	{
		n = nblocks;
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_mode_gcm_be_inl_defd_ctr_schedule_decrypt(&gcm_be->m_ctr, &gcm_be->m_schedule.m_data, &input[i].m_data, &output[i].m_data, 1); /* todo */
		}
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_aad_append(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_sl_cui_uint8_pct const aad, mk_lang_types_usize_t const len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t idx mk_lang_constexpr_init;
	mk_lang_types_bool_t align mk_lang_constexpr_init;
	mk_lang_types_usize_t avail mk_lang_constexpr_init;
	mk_lang_types_usize_t copy mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64a mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64b mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(gcm_be);
	mk_lang_assert(aad || len == 0);
	mk_lang_assert(len >= 0);
	#if mk_lib_crypto_mode_gcm_be_debug
	mk_lang_assert(gcm_be->m_iv_finished);
	mk_lang_assert(!gcm_be->m_aad_finished);
	#endif

	ptr = aad;
	rem = len;
	if(!mk_sl_cui_uint64_is_zero(&gcm_be->m_aad_len))
	{
		mk_sl_cui_uint64_to_bi_usize(&gcm_be->m_aad_len, &idx);
		idx = idx % 16;
		align = idx != 0;
	}
	else
	{
		align = mk_lang_false;
	}
	if(align)
	{
		avail = 16 - idx;
		copy = mk_lang_min(avail, rem);
		mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&gcm_be->m_gblock.m_data.m_uint8s[idx], ptr, copy);
		ptr += copy;
		rem -= copy;
		mk_sl_cui_uint64_from_bi_usize(&tu64a, &copy);
		mk_lang_assert(((mk_sl_cui_uint64_add3_wrap_cid_cod(&gcm_be->m_aad_len, &tu64a, &tu64b), mk_sl_cui_uint64_ge(&tu64b, &gcm_be->m_aad_len)) && (mk_sl_cui_uint64_shr2(&tu64b, 64 - 3), mk_sl_cui_uint64_is_zero(&tu64b))));
		mk_sl_cui_uint64_add2_wrap_cid_cod(&gcm_be->m_aad_len, &tu64a);
		if(copy == avail)
		{
			mk_lib_crypto_hash_block_ghash_append_blocks(&gcm_be->m_ghash, &gcm_be->m_gblock, 1);
		}
	}
	n = rem / 16;
	if(!mk_lang_constexpr_is_constant_evaluated_test && ((mk_lang_types_uintptr_t)(ptr)) % 16 == 0)
	{
		mk_lib_crypto_hash_block_ghash_append_blocks(&gcm_be->m_ghash, ((mk_lib_crypto_hash_block_ghash_block_pct)(ptr)), n);
	}
	else
	{
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&gcm_be->m_gblock.m_data.m_uint8s[0], &ptr[i * 16], 16);
			mk_lib_crypto_hash_block_ghash_append_blocks(&gcm_be->m_ghash, &gcm_be->m_gblock, 1);
		}
	}
	ptr += n * 16;
	rem -= n * 16;
	copy = n * 16;
	mk_sl_cui_uint64_from_bi_usize(&tu64a, &copy);
	mk_lang_assert(((mk_sl_cui_uint64_add3_wrap_cid_cod(&gcm_be->m_aad_len, &tu64a, &tu64b), mk_sl_cui_uint64_ge(&tu64b, &gcm_be->m_aad_len)) && (mk_sl_cui_uint64_shr2(&tu64b, 64 - 3), mk_sl_cui_uint64_is_zero(&tu64b))));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&gcm_be->m_aad_len, &tu64a);
	copy = rem % 16;
	mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&gcm_be->m_gblock.m_data.m_uint8s[0], ptr, copy);
	ptr += copy;
	rem -= copy;
	mk_sl_cui_uint64_from_bi_usize(&tu64a, &copy);
	mk_lang_assert(((mk_sl_cui_uint64_add3_wrap_cid_cod(&gcm_be->m_aad_len, &tu64a, &tu64b), mk_sl_cui_uint64_ge(&tu64b, &gcm_be->m_aad_len)) && (mk_sl_cui_uint64_shr2(&tu64b, 64 - 3), mk_sl_cui_uint64_is_zero(&tu64b))));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&gcm_be->m_aad_len, &tu64a);
	mk_lang_assert(ptr == aad + len);
	mk_lang_assert(rem == 0);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_aad_finish(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be) mk_lang_noexcept
{
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_lang_types_ulong_t avail mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;

	mk_lang_assert(gcm_be);
	#if mk_lib_crypto_mode_gcm_be_debug
	mk_lang_assert(gcm_be->m_iv_finished);
	mk_lang_assert(!gcm_be->m_aad_finished);
	#endif

	mk_sl_cui_uint64_to_bi_ulong(&gcm_be->m_aad_len, &tul);
	tul = tul % 16;
	if(tul != 0)
	{
		avail = 16 - tul;
		mk_sl_cui_uint8_set_zero(&tu8);
		mk_lib_crypto_mode_gcm_be_inl_filec_memset_fn(&gcm_be->m_gblock.m_data.m_uint8s[tul], &tu8, avail);
		mk_lib_crypto_hash_block_ghash_append_blocks(&gcm_be->m_ghash, &gcm_be->m_gblock, 1);
	}
	#if mk_lib_crypto_mode_gcm_be_debug
	gcm_be->m_aad_finished = mk_lang_true;
	gcm_be->m_pt_finished = mk_lang_false;
	#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_iv_append(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_sl_cui_uint8_pct const iv, mk_lang_types_usize_t const len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t idx mk_lang_constexpr_init;
	mk_lang_types_bool_t align mk_lang_constexpr_init;
	mk_lang_types_usize_t avail mk_lang_constexpr_init;
	mk_lang_types_usize_t copy mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64a mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64b mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(gcm_be);
	mk_lang_assert(iv || len == 0);
	mk_lang_assert(len >= 0);
	#if mk_lib_crypto_mode_gcm_be_debug
	mk_lang_assert(!gcm_be->m_iv_finished);
	#endif

	ptr = iv;
	rem = len;
	if(!mk_sl_cui_uint64_is_zero(&gcm_be->m_aad_len))
	{
		mk_sl_cui_uint64_to_bi_usize(&gcm_be->m_aad_len, &idx);
		idx = idx % 16;
		align = idx != 0;
	}
	else
	{
		align = mk_lang_false;
	}
	if(align)
	{
		avail = 16 - idx;
		copy = mk_lang_min(avail, rem);
		mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&gcm_be->m_gblock.m_data.m_uint8s[idx], ptr, copy);
		ptr += copy;
		rem -= copy;
		mk_sl_cui_uint64_from_bi_usize(&tu64a, &copy);
		mk_lang_assert(((mk_sl_cui_uint64_add3_wrap_cid_cod(&gcm_be->m_aad_len, &tu64a, &tu64b), mk_sl_cui_uint64_ge(&tu64b, &gcm_be->m_aad_len)) && (mk_sl_cui_uint64_shr2(&tu64b, 64 - 3), mk_sl_cui_uint64_is_zero(&tu64b))));
		mk_sl_cui_uint64_add2_wrap_cid_cod(&gcm_be->m_aad_len, &tu64a);
		if(copy == avail)
		{
			mk_lib_crypto_hash_block_ghash_append_blocks(&gcm_be->m_ghash, &gcm_be->m_gblock, 1);
		}
	}
	n = rem / 16;
	if(!mk_lang_constexpr_is_constant_evaluated_test && ((mk_lang_types_uintptr_t)(ptr)) % 16 == 0)
	{
		mk_lib_crypto_hash_block_ghash_append_blocks(&gcm_be->m_ghash, ((mk_lib_crypto_hash_block_ghash_block_pct)(ptr)), n);
	}
	else
	{
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&gcm_be->m_gblock.m_data.m_uint8s[0], &ptr[i * 16], 16);
			mk_lib_crypto_hash_block_ghash_append_blocks(&gcm_be->m_ghash, &gcm_be->m_gblock, 1);
		}
	}
	ptr += n * 16;
	rem -= n * 16;
	copy = n * 16;
	mk_sl_cui_uint64_from_bi_usize(&tu64a, &copy);
	mk_lang_assert(((mk_sl_cui_uint64_add3_wrap_cid_cod(&gcm_be->m_aad_len, &tu64a, &tu64b), mk_sl_cui_uint64_ge(&tu64b, &gcm_be->m_aad_len)) && (mk_sl_cui_uint64_shr2(&tu64b, 64 - 3), mk_sl_cui_uint64_is_zero(&tu64b))));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&gcm_be->m_aad_len, &tu64a);
	copy = rem % 16;
	mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&gcm_be->m_gblock.m_data.m_uint8s[0], ptr, copy);
	ptr += copy;
	rem -= copy;
	mk_sl_cui_uint64_from_bi_usize(&tu64a, &copy);
	mk_lang_assert(((mk_sl_cui_uint64_add3_wrap_cid_cod(&gcm_be->m_aad_len, &tu64a, &tu64b), mk_sl_cui_uint64_ge(&tu64b, &gcm_be->m_aad_len)) && (mk_sl_cui_uint64_shr2(&tu64b, 64 - 3), mk_sl_cui_uint64_is_zero(&tu64b))));
	mk_sl_cui_uint64_add2_wrap_cid_cod(&gcm_be->m_aad_len, &tu64a);
	mk_lang_assert(ptr == iv + len);
	mk_lang_assert(rem == 0);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_iv_finish(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be) mk_lang_noexcept
{
	mk_sl_cui_uint64_t tu64a mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32a mk_lang_constexpr_init;
	mk_lib_crypto_mode_gcm_be_inl_defd_ctr_iv_pct piv mk_lang_constexpr_init;
	mk_lib_crypto_mode_gcm_be_inl_defd_ctr_iv_t iv mk_lang_constexpr_init;
	mk_lang_types_ulong_t avail mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_ghash_digest_pt pdigest mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_ghash_digest_t digest mk_lang_constexpr_init;
	mk_lib_crypto_mode_gcm_be_inl_defd_msg_t msg mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(mk_lib_crypto_mode_gcm_be_inl_defd_ctr_iv_len_v == 16);
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_hash_block_ghash_digest_t) >= 16);
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_mode_gcm_be_inl_defd_ctr_iv_t) >= 16);
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_hash_block_ghash_digest_t) >= 16);
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_mode_gcm_be_inl_defd_alg_msg_t) >= 16);

	mk_lang_assert(gcm_be);
	#if mk_lib_crypto_mode_gcm_be_debug
	mk_lang_assert(!gcm_be->m_iv_finished);
	#endif

	mk_sl_cui_uint64_shr3(&gcm_be->m_aad_len, 32, &tu64a);
	mk_sl_cui_uint64_to_bi_ulong(&gcm_be->m_aad_len, &tul);
	if(mk_sl_cui_uint64_is_zero(&tu64a) && tul == 96 / mk_lang_charbit)
	{
		tul = 1; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
		mk_sl_uint_strict_32_to_8_be(&tu32a, &gcm_be->m_gblock.m_data.m_uint8s[96 / mk_lang_charbit]);
		if(!mk_lang_constexpr_is_constant_evaluated_test)
		{
			piv = ((mk_lib_crypto_mode_gcm_be_inl_defd_ctr_iv_pct)(&gcm_be->m_gblock));
		}
		else
		{
			mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&iv.m_data.m_uint8s[0], &gcm_be->m_gblock.m_data.m_uint8s[0], 16);
			piv = &iv;
		}
	}
	else
	{
		mk_sl_cui_uint64_to_bi_ulong(&gcm_be->m_aad_len, &tul);
		tul = tul % 16;
		if(tul != 0)
		{
			avail = 16 - tul;
			mk_sl_cui_uint8_set_zero(&tu8);
			mk_lib_crypto_mode_gcm_be_inl_filec_memset_fn(&gcm_be->m_gblock.m_data.m_uint8s[tul], &tu8, avail);
			mk_lib_crypto_hash_block_ghash_append_blocks(&gcm_be->m_ghash, &gcm_be->m_gblock, 1);
		}
		mk_sl_cui_uint8_set_zero(&tu8);
		mk_lib_crypto_mode_gcm_be_inl_filec_memset_fn(&gcm_be->m_gblock.m_data.m_uint8s[0], &tu8, 8);
		mk_sl_cui_uint64_shl2(&gcm_be->m_aad_len, 3);
		mk_sl_uint_strict_64_to_8_be(&gcm_be->m_aad_len, &gcm_be->m_gblock.m_data.m_uint8s[8]);
		mk_lib_crypto_hash_block_ghash_append_blocks(&gcm_be->m_ghash, &gcm_be->m_gblock, 1);
		if(!mk_lang_constexpr_is_constant_evaluated_test)
		{
			pdigest = ((mk_lib_crypto_hash_block_ghash_digest_pt)(&gcm_be->m_gblock));
		}
		else
		{
			pdigest = &digest;
		}
		mk_lib_crypto_hash_block_ghash_finish(&gcm_be->m_ghash, pdigest);
		if(!mk_lang_constexpr_is_constant_evaluated_test)
		{
			piv = ((mk_lib_crypto_mode_gcm_be_inl_defd_ctr_iv_pct)(pdigest));
		}
		else
		{
			mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&iv.m_data.m_uint8s[0], &digest.m_data.m_uint8s[0], 16);
			piv = &iv;
		}
	}
	mk_lib_crypto_mode_gcm_be_inl_defd_ctr_init(&gcm_be->m_ctr, piv);
	mk_lib_crypto_mode_gcm_be_inl_defd_ctr_increment(&gcm_be->m_ctr.m_iv);
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lib_crypto_mode_gcm_be_inl_defd_alg_schedule_encrypt(&gcm_be->m_schedule.m_data, ((mk_lib_crypto_mode_gcm_be_inl_defd_alg_msg_pt)(piv)), &gcm_be->m_ctr_0_ct, 1);
	}
	else
	{
		mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&gcm_be->m_ctr_0_ct.m_data.m_uint8s[0], &piv->m_data.m_uint8s[0], 16);
		mk_lib_crypto_mode_gcm_be_inl_defd_alg_schedule_encrypt(&gcm_be->m_schedule.m_data, &gcm_be->m_ctr_0_ct, &gcm_be->m_ctr_0_ct, 1);
	}
	mk_sl_cui_uint8_set_zero(&tu8);
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lib_crypto_mode_gcm_be_inl_filec_memset_fn(&gcm_be->m_gblock.m_data.m_uint8s[0], &tu8, 16);
		mk_lib_crypto_mode_gcm_be_inl_defd_alg_schedule_encrypt(&gcm_be->m_schedule.m_data, ((mk_lib_crypto_mode_gcm_be_inl_defd_alg_msg_pct)(&gcm_be->m_gblock)), ((mk_lib_crypto_mode_gcm_be_inl_defd_alg_msg_pt)(&gcm_be->m_gblock)), 1);
	}
	else
	{
		mk_lib_crypto_mode_gcm_be_inl_filec_memset_fn(&msg.m_data.m_data.m_uint8s[0], &tu8, 16);
		mk_lib_crypto_mode_gcm_be_inl_defd_alg_schedule_encrypt(&gcm_be->m_schedule.m_data, &msg.m_data, &msg.m_data, 1);
		mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn(&gcm_be->m_gblock.m_data.m_uint8s[0], &msg.m_data.m_data.m_uint8s[0], 16);
	}
	mk_lib_crypto_hash_block_ghash_init(&gcm_be->m_ghash, &gcm_be->m_gblock);
	mk_sl_cui_uint64_set_zero(&gcm_be->m_aad_len);
	#if mk_lib_crypto_mode_gcm_be_debug
	gcm_be->m_iv_finished = mk_lang_true;
	gcm_be->m_aad_finished = mk_lang_false;
	#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_expand_enc(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_lib_crypto_mode_gcm_be_inl_defd_key_pct const key) mk_lang_noexcept
{
	mk_lang_assert(gcm_be);
	mk_lang_assert(key);

	mk_lib_crypto_mode_gcm_be_inl_defd_init(gcm_be, key);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_inl_defd_expand_dec(mk_lib_crypto_mode_gcm_be_inl_defd_pt const gcm_be, mk_lib_crypto_mode_gcm_be_inl_defd_key_pct const key) mk_lang_noexcept
{
	mk_lang_assert(gcm_be);
	mk_lang_assert(key);

	mk_lib_crypto_mode_gcm_be_inl_defd_init(gcm_be, key);
}


#undef mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_name
#undef mk_lib_crypto_mode_gcm_be_inl_filec_memcpy_fn

#undef mk_lib_crypto_mode_gcm_be_inl_filec_memset_name
#undef mk_lib_crypto_mode_gcm_be_inl_filec_memset_fn

#undef mk_lib_crypto_mode_gcm_be_inl_filec_xor_name
#undef mk_lib_crypto_mode_gcm_be_inl_filec_xor2
#undef mk_lib_crypto_mode_gcm_be_inl_filec_xor3


#include "mk_lib_crypto_mode_gcm_be_inl_defu.h"


#undef mk_lib_crypto_mode_gcm_be_t_name
#undef mk_lib_crypto_mode_gcm_be_t_alg
