#ifndef mk_include_guard_mk_lib_crypto_xof_kt128_c
#define mk_include_guard_mk_lib_crypto_xof_kt128_c
#include "mk_lib_crypto_xof_kt128.h"

/* https://keccak.team/files/TurboSHAKE.pdf */
/* https://www.rfc-editor.org/rfc/rfc9861.txt */
/* https://datatracker.ietf.org/doc/html/rfc9861 */

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_configuration.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_roundup.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_block_sha3_base.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"
#include "mk_sl_uint_more.h"


enum mk_lib_crypto_xof_kt128_inner_digest_len_e{ mk_lib_crypto_xof_kt128_inner_digest_len_v = 32 }; typedef enum mk_lib_crypto_xof_kt128_inner_digest_len_e mk_lib_crypto_xof_kt128_inner_digest_len_t;
enum mk_lib_crypto_xof_kt128_mix_count_e{ mk_lib_crypto_xof_kt128_mix_count_v = ((mk_lang_types_sint_t)(mk_lib_crypto_xof_kt128_block_len_v)) / ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v)) }; typedef enum mk_lib_crypto_xof_kt128_mix_count_e mk_lib_crypto_xof_kt128_mix_count_t;


union mk_lib_crypto_xof_kt128_filling_data_u
{
	mk_sl_cui_uint8_t m_uint8s[8];
	mk_sl_cui_uint64_t m_align;
};
typedef union mk_lib_crypto_xof_kt128_filling_data_u mk_lib_crypto_xof_kt128_filling_data_t;
struct mk_lib_crypto_xof_kt128_filling_s
{
	mk_lib_crypto_xof_kt128_filling_data_t m_data;
};
typedef struct mk_lib_crypto_xof_kt128_filling_s mk_lib_crypto_xof_kt128_filling_t;

union mk_lib_crypto_xof_kt128_digest_data_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_xof_kt128_inner_digest_len_v];
	mk_sl_cui_uint64_t m_align;
};
typedef union mk_lib_crypto_xof_kt128_digest_data_u mk_lib_crypto_xof_kt128_digest_data_t;
struct mk_lib_crypto_xof_kt128_digest_s
{
	mk_lib_crypto_xof_kt128_digest_data_t m_data;
};
typedef struct mk_lib_crypto_xof_kt128_digest_s mk_lib_crypto_xof_kt128_digest_t;


mk_lang_constexpr_static_inline mk_lib_crypto_xof_kt128_filling_t const mk_lib_crypto_xof_kt128_k_filling = {{{ mk_sl_cui_uint8_c(0x03), mk_sl_cui_uint8_c(0x00), mk_sl_cui_uint8_c(0x00), mk_sl_cui_uint8_c(0x00), mk_sl_cui_uint8_c(0x00), mk_sl_cui_uint8_c(0x00), mk_sl_cui_uint8_c(0x00), mk_sl_cui_uint8_c(0x00) }}};


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_mix_block(mk_lib_crypto_hash_block_sha3_base_pt const state, mk_lib_crypto_xof_kt128_block_pct const block) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;

	mk_lang_static_assert((((mk_lang_types_sint_t)(mk_lib_crypto_xof_kt128_block_len_v)) % ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v))) == 0);

	mk_lang_assert(state);
	mk_lang_assert(block);

	n = mk_lib_crypto_xof_kt128_mix_count_v;
	for(i = 0; i != n; ++i)
	{
		mk_sl_uint_convert_64_8_le_to_big(&ta, &block->m_data.m_uint8s[i * mk_sl_cui_uint64_size_bytes_v]);
		mk_sl_cui_uint64_xor2(&state->m_data.m_uint64s[i], &ta);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_process_block(mk_lib_crypto_hash_block_sha3_base_pt const state, mk_lib_crypto_xof_kt128_block_pct const block) mk_lang_noexcept
{
	mk_lang_assert(state);
	mk_lang_assert(block);

	mk_lib_crypto_xof_kt128_mix_block(state, block);
	mk_lib_crypto_hash_block_sha3_base_f_turbo(state);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_digest_block(mk_lib_crypto_hash_block_sha3_base_pt const state, mk_lib_crypto_xof_kt128_block_pt const block, mk_lang_types_sint_t const rem, mk_lang_types_uchar_t const domain) mk_lang_noexcept
{
	mk_lang_types_sint_t idx mk_lang_constexpr_init;
	mk_lang_types_sint_t rest mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;

	mk_lang_assert(state);
	mk_lang_assert(block);
	mk_lang_assert(rem >= 0);
	mk_lang_assert(rem <= mk_lib_crypto_xof_kt128_block_len_v);
	mk_lang_assert(domain == 0x06 || domain == 0x07 || domain == 0x0b);

	idx = mk_lib_crypto_xof_kt128_block_len_v - rem;
	mk_sl_cui_uint8_from_bi_uchar(&block->m_data.m_uint8s[idx], &domain);
	rest = mk_lib_crypto_xof_kt128_block_len_v - idx - 1;
	mk_sl_cui_uint8_memclr_fn(&block->m_data.m_uint8s[idx + 1], ((mk_lang_types_usize_t)(rest)));
	tuc = 0x80; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc);
	mk_sl_cui_uint8_or2(&block->m_data.m_uint8s[mk_lib_crypto_xof_kt128_block_len_v - 1], &tu8);
	mk_lib_crypto_xof_kt128_process_block(state, block);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_init(mk_lib_crypto_xof_kt128_pt const kt128) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_charbit == 8);

	mk_lang_assert(kt128);

	mk_lib_crypto_hash_block_sha3_base_init(&kt128->m_inner_state);
	mk_lib_crypto_hash_block_sha3_base_init(&kt128->m_outer_state);
	mk_sl_cui_uint8_mem_mark_new(&kt128->m_inner_block.m_data.m_uint8s[0], mk_lang_countof(kt128->m_inner_block.m_data.m_uint8s));
	mk_sl_cui_uint8_mem_mark_new(&kt128->m_outer_block.m_data.m_uint8s[0], mk_lib_crypto_xof_kt128_block_len_v);
	mk_sl_cui_uint64_set_zero(&kt128->m_len_blocks);
	mk_sl_cui_uint64_set_zero(&kt128->m_len_c);
	kt128->m_inner_rem = mk_lang_countof(kt128->m_inner_block.m_data.m_uint8s);
	kt128->m_outer_rem = mk_lib_crypto_xof_kt128_block_len_v;
	kt128->m_8k_rem = 8 * 1024;
	kt128->m_phase = mk_lib_crypto_xof_kt128_s_phase_e_s_zero;
	#if mk_lang_configuration_is_debug
	kt128->m_customization = mk_lang_false;
	kt128->m_finished = mk_lang_false;
	#endif
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_outer_append_s0(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count, mk_lang_types_usize_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t to_copy_si mk_lang_constexpr_init;
	mk_lang_types_usize_t to_copy_us mk_lang_constexpr_init;
	mk_lang_types_sint_t outer_idx mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(kt128);
	mk_lang_assert(u8s || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(consumed);
	mk_lang_assert(kt128->m_phase == mk_lib_crypto_xof_kt128_s_phase_e_s_zero);
	#include "mk_lang_warning_msvc_pop.h"

	ptr = u8s;
	rem = count;
	do
	{
		to_copy_si = mk_lang_min(kt128->m_outer_rem, kt128->m_8k_rem); to_copy_us = ((mk_lang_types_usize_t)(to_copy_si));
		to_copy_us = mk_lang_min(to_copy_us, rem); to_copy_si = ((mk_lang_types_sint_t)(to_copy_us));
		outer_idx = mk_lib_crypto_xof_kt128_block_len_v - kt128->m_outer_rem;
		mk_sl_cui_uint8_memcpy_fn(&kt128->m_outer_block.m_data.m_uint8s[0] + outer_idx, ptr, to_copy_us);
		ptr += to_copy_us;
		rem -= to_copy_us;
		kt128->m_8k_rem -= to_copy_si;
		kt128->m_outer_rem -= to_copy_si;
		if(kt128->m_outer_rem == 0)
		{
			kt128->m_outer_rem = mk_lib_crypto_xof_kt128_block_len_v;
			mk_lib_crypto_xof_kt128_process_block(&kt128->m_outer_state, &kt128->m_outer_block);
		}
	}while(to_copy_si != 0);
	*consumed = count - rem;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_outer_append_sn(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t to_copy_si mk_lang_constexpr_init;
	mk_lang_types_usize_t to_copy_us mk_lang_constexpr_init;
	mk_lang_types_sint_t outer_idx mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(kt128);
	mk_lang_assert(u8s || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(kt128->m_phase == mk_lib_crypto_xof_kt128_s_phase_e_s_n);
	#include "mk_lang_warning_msvc_pop.h"

	ptr = u8s;
	rem = count;
	do
	{
		to_copy_si = kt128->m_outer_rem; to_copy_us = ((mk_lang_types_usize_t)(to_copy_si));
		to_copy_us = mk_lang_min(to_copy_us, rem); to_copy_si = ((mk_lang_types_sint_t)(to_copy_us));
		outer_idx = mk_lib_crypto_xof_kt128_block_len_v - kt128->m_outer_rem;
		mk_sl_cui_uint8_memcpy_fn(&kt128->m_outer_block.m_data.m_uint8s[0] + outer_idx, ptr, to_copy_us);
		ptr += to_copy_us;
		rem -= to_copy_us;
		kt128->m_outer_rem -= to_copy_si;
		if(kt128->m_outer_rem == 0)
		{
			kt128->m_outer_rem = mk_lib_crypto_xof_kt128_block_len_v;
			mk_lib_crypto_xof_kt128_process_block(&kt128->m_outer_state, &kt128->m_outer_block);
		}
	}while(rem != 0);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_append_page_zero(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count, mk_lang_types_usize_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t eaten mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct filling_ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t filling_len mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(kt128);
	mk_lang_assert(u8s || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(consumed);
	#include "mk_lang_warning_msvc_pop.h"

	ptr = u8s;
	rem = count;
	if(kt128->m_phase == mk_lib_crypto_xof_kt128_s_phase_e_s_zero)
	{
		#include "mk_lang_warning_msvc_push_c4296.h"
		mk_lib_crypto_xof_kt128_prrw_outer_append_s0(kt128, ptr, rem, &eaten); mk_lang_assert(eaten >= 0); mk_lang_assert(eaten <= rem); ptr += eaten; rem -= eaten;
		#include "mk_lang_warning_msvc_pop.h"
		if(kt128->m_8k_rem == 0 && rem != 0)
		{
			kt128->m_8k_rem = 8 * 1024;
			mk_lang_assert(kt128->m_outer_rem == mk_lib_crypto_xof_kt128_block_len_v - (8 * 1024) % mk_lib_crypto_xof_kt128_block_len_v);
			kt128->m_phase = mk_lib_crypto_xof_kt128_s_phase_e_s_n;
			mk_sl_cui_uint64_inc1(&kt128->m_len_blocks);
			filling_ptr = &mk_lib_crypto_xof_kt128_k_filling.m_data.m_uint8s[0];
			filling_len = mk_lang_countof(mk_lib_crypto_xof_kt128_k_filling.m_data.m_uint8s);
			mk_lib_crypto_xof_kt128_prrw_outer_append_sn(kt128, filling_ptr, filling_len);
		}
	}
	*consumed = count - rem;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_inner_append(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count, mk_lang_types_usize_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t to_copy_si mk_lang_constexpr_init;
	mk_lang_types_usize_t to_copy_us mk_lang_constexpr_init;
	mk_lang_types_sint_t inner_idx mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(kt128);
	mk_lang_assert(u8s || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(consumed);
	mk_lang_assert(kt128->m_phase == mk_lib_crypto_xof_kt128_s_phase_e_s_n);
	#include "mk_lang_warning_msvc_pop.h"

	ptr = u8s;
	rem = count;
	do
	{
		to_copy_si = mk_lang_min(kt128->m_inner_rem, kt128->m_8k_rem); to_copy_us = ((mk_lang_types_usize_t)(to_copy_si));
		to_copy_us = mk_lang_min(to_copy_us, rem); to_copy_si = ((mk_lang_types_sint_t)(to_copy_us));
		inner_idx = mk_lang_countof(kt128->m_inner_block.m_data.m_uint8s) - kt128->m_inner_rem;
		mk_sl_cui_uint8_memcpy_fn(&kt128->m_inner_block.m_data.m_uint8s[0] + inner_idx, ptr, to_copy_us);
		ptr += to_copy_us;
		rem -= to_copy_us;
		kt128->m_8k_rem -= to_copy_si;
		kt128->m_inner_rem -= to_copy_si;
		if(kt128->m_inner_rem == 0)
		{
			kt128->m_inner_rem = mk_lang_countof(kt128->m_inner_block.m_data.m_uint8s);
			mk_lib_crypto_xof_kt128_process_block(&kt128->m_inner_state, &kt128->m_inner_block);
		}
	}while(to_copy_si != 0);
	*consumed = count - rem;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_hash_inner_and_append_to_outer(mk_lib_crypto_xof_kt128_pt const kt128) mk_lang_noexcept
{
	mk_lib_crypto_xof_kt128_digest_t digest mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_xof_kt128_inner_digest_len_v)) % ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v)) == 0);

	mk_lang_assert(kt128);

	mk_lib_crypto_xof_kt128_digest_block(&kt128->m_inner_state, &kt128->m_inner_block, kt128->m_inner_rem, 0x0b);
	mk_sl_uint_convert_64_8_le_to_sml_multi(&kt128->m_inner_state.m_data.m_uint64s[0], &digest.m_data.m_uint8s[0], ((mk_lang_types_sint_t)(mk_lib_crypto_xof_kt128_inner_digest_len_v)) / ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v)));
	mk_lib_crypto_xof_kt128_prrw_outer_append_sn(kt128, &digest.m_data.m_uint8s[0], mk_lib_crypto_xof_kt128_inner_digest_len_v);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_inner_full(mk_lib_crypto_xof_kt128_pt const kt128, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(kt128);
	mk_lang_assert(count >= 0);
	mk_lang_assert(kt128->m_phase == mk_lib_crypto_xof_kt128_s_phase_e_s_n);
	#include "mk_lang_warning_msvc_pop.h"

	if(count != 0 && kt128->m_8k_rem == 0)
	{
		kt128->m_8k_rem = 8 * 1024;
		mk_lang_assert(kt128->m_inner_rem == mk_lang_countof(kt128->m_inner_block.m_data.m_uint8s) - (8 * 1024) % mk_lang_countof(kt128->m_inner_block.m_data.m_uint8s));
		mk_sl_cui_uint64_inc1(&kt128->m_len_blocks);
		mk_lang_assert(!mk_sl_cui_uint64_is_zero(&kt128->m_len_blocks)); /* use bigger variable */
		mk_lib_crypto_xof_kt128_prrw_hash_inner_and_append_to_outer(kt128);
		mk_lib_crypto_hash_block_sha3_base_init(&kt128->m_inner_state);
		kt128->m_inner_rem = mk_lang_countof(kt128->m_inner_block.m_data.m_uint8s);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_append_page_n(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t consumed mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(kt128);
	mk_lang_assert(u8s || count == 0);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	ptr = u8s;
	rem = count;
	if(kt128->m_phase == mk_lib_crypto_xof_kt128_s_phase_e_s_n)
	{
		do
		{
			#include "mk_lang_warning_msvc_push_c4296.h"
			mk_lib_crypto_xof_kt128_prrw_inner_append(kt128, ptr, rem, &consumed); mk_lang_assert(consumed >= 0); mk_lang_assert(consumed <= rem); ptr += consumed; rem -= consumed;
			mk_lib_crypto_xof_kt128_prrw_inner_full(kt128, rem);
			#include "mk_lang_warning_msvc_pop.h"
		}while(rem != 0);
	}
	mk_lang_assert(rem == 0);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_append_message_u8s_impl(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t consumed mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(kt128);
	mk_lang_assert(u8s || count == 0);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	ptr = u8s;
	rem = count;
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lib_crypto_xof_kt128_prrw_append_page_zero(kt128, ptr, rem, &consumed); mk_lang_assert(consumed >= 0); mk_lang_assert(consumed <= rem); ptr += consumed; rem -= consumed;
	mk_lib_crypto_xof_kt128_prrw_append_page_n   (kt128, ptr, rem           );
	#include "mk_lang_warning_msvc_pop.h"
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_append_message_u8s(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(kt128);
	mk_lang_assert(u8s || count == 0);
	mk_lang_assert(count >= 0);
	#if mk_lang_configuration_is_debug
	mk_lang_assert(!kt128->m_customization);
	mk_lang_assert(!kt128->m_finished);
	#endif
	#include "mk_lang_warning_msvc_pop.h"

	mk_lib_crypto_xof_kt128_prrw_append_message_u8s_impl(kt128, u8s, count);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_append_customization_u8s(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint64_t len mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(kt128);
	mk_lang_assert(u8s || count == 0);
	mk_lang_assert(count >= 0);
	#if mk_lang_configuration_is_debug
	mk_lang_assert(!kt128->m_finished);
	#endif
	#include "mk_lang_warning_msvc_pop.h"

	#if mk_lang_configuration_is_debug
	kt128->m_customization = mk_lang_true;
	#endif
	ptr = u8s;
	rem = count;
	mk_sl_cui_uint64_from_bi_usize(&len, &rem);
	mk_lang_assert(!mk_sl_cui_uint64_would_overflow_add_cc(&kt128->m_len_c, &len)); /* use bigger variable */
	mk_sl_cui_uint64_add2_wrap_cid_cod(&kt128->m_len_c, &len);
	mk_lib_crypto_xof_kt128_prrw_append_message_u8s_impl(kt128, ptr, rem);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_append_len_c(mk_lib_crypto_xof_kt128_pt const kt128) mk_lang_noexcept
{
	mk_lang_types_uchar_t len_c_uchars[mk_sl_cui_uint64_size_bytes_v + 1];
	mk_lang_types_sint_t zeros mk_lang_constexpr_init;
	mk_lang_types_sint_t non_zeros mk_lang_constexpr_init;
	mk_lang_types_sint_t trailing_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_t len_c_uint8s[mk_lang_countof(len_c_uchars)];
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;

	mk_lang_assert(kt128);

	mk_sl_cui_uint64_to_buis_uchar_be(&kt128->m_len_c, &len_c_uchars[0]);
	zeros = mk_sl_cui_uint64_count_leading_zeros(&kt128->m_len_c);
	non_zeros = mk_sl_cui_uint64_size_bits_v - zeros;
	trailing_len = mk_lang_roundup_div(non_zeros, mk_lang_charbit);
	mk_lang_assert(trailing_len >= 0);
	mk_lang_assert(trailing_len <= mk_sl_cui_uint64_size_bytes_v);
	len_c_uchars[mk_lang_countof(len_c_uchars) - 1] = ((mk_lang_types_uchar_t)(trailing_len));
	mk_sl_cui_uint8_from_bi_uchar_many(&len_c_uint8s[0], &len_c_uchars[0], mk_lang_countof(len_c_uchars));

	ptr = &len_c_uint8s[0] + mk_lang_countof(len_c_uint8s) - trailing_len - 1;
	rem = ((mk_lang_types_usize_t)(trailing_len)) + 1;
	mk_lib_crypto_xof_kt128_prrw_append_message_u8s_impl(kt128, ptr, rem);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_append_len_blocks(mk_lib_crypto_xof_kt128_pt const kt128) mk_lang_noexcept
{
	mk_lang_types_uchar_t len_c_uchars[mk_sl_cui_uint64_size_bytes_v + 1];
	mk_lang_types_sint_t zeros mk_lang_constexpr_init;
	mk_lang_types_sint_t non_zeros mk_lang_constexpr_init;
	mk_lang_types_sint_t trailing_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_t len_c_uint8s[mk_lang_countof(len_c_uchars)];
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;

	mk_lang_assert(kt128);
	mk_lang_assert(kt128->m_phase == mk_lib_crypto_xof_kt128_s_phase_e_s_n);

	mk_sl_cui_uint64_to_buis_uchar_be(&kt128->m_len_blocks, &len_c_uchars[0]);
	zeros = mk_sl_cui_uint64_count_leading_zeros(&kt128->m_len_blocks);
	non_zeros = mk_sl_cui_uint64_size_bits_v - zeros;
	trailing_len = mk_lang_roundup_div(non_zeros, mk_lang_charbit);
	trailing_len = mk_lang_max(trailing_len, 1);
	mk_lang_assert(trailing_len >= 1);
	mk_lang_assert(trailing_len <= mk_sl_cui_uint64_size_bytes_v);
	len_c_uchars[mk_lang_countof(len_c_uchars) - 1] = ((mk_lang_types_uchar_t)(trailing_len));
	mk_sl_cui_uint8_from_bi_uchar_many(&len_c_uint8s[0], &len_c_uchars[0], mk_lang_countof(len_c_uchars));

	ptr = &len_c_uint8s[0] + mk_lang_countof(len_c_uint8s) - trailing_len - 1;
	rem = ((mk_lang_types_usize_t)(trailing_len)) + 1;
	mk_lib_crypto_xof_kt128_prrw_outer_append_sn(kt128, ptr, rem);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_append_ffff(mk_lib_crypto_xof_kt128_pt const kt128) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ffff[2] mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;

	mk_lang_assert(kt128);
	mk_lang_assert(kt128->m_phase == mk_lib_crypto_xof_kt128_s_phase_e_s_n);

	mk_sl_cui_uint8_set_max(&ffff[0]);
	mk_sl_cui_uint8_set_max(&ffff[1]);
	ptr = &ffff[0];
	rem = 2;
	mk_lib_crypto_xof_kt128_prrw_outer_append_sn(kt128, ptr, rem);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_finish(mk_lib_crypto_xof_kt128_pt const kt128) mk_lang_noexcept
{
	mk_lang_types_uchar_t domain mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_xof_kt128_block_len_v)) % ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v)) == 0);

	mk_lang_assert(kt128);

	#if mk_lang_configuration_is_debug
	kt128->m_finished = mk_lang_true;
	#endif
	mk_lib_crypto_xof_kt128_prrw_append_len_c(kt128);
	if(kt128->m_phase == mk_lib_crypto_xof_kt128_s_phase_e_s_zero)
	{
		domain = 0x07;
	}
	else
	{
		domain = 0x06;
		mk_lib_crypto_xof_kt128_prrw_hash_inner_and_append_to_outer(kt128);
		mk_lib_crypto_xof_kt128_prrw_append_len_blocks(kt128);
		mk_lib_crypto_xof_kt128_prrw_append_ffff(kt128);
	}
	mk_lib_crypto_xof_kt128_digest_block(&kt128->m_outer_state, &kt128->m_outer_block, kt128->m_outer_rem, domain);
	mk_sl_uint_convert_64_8_le_to_sml_multi(&kt128->m_outer_state.m_data.m_uint64s[0], &kt128->m_outer_block.m_data.m_uint8s[0], ((mk_lang_types_sint_t)(mk_lib_crypto_xof_kt128_block_len_v)) / ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v)));
	kt128->m_outer_rem = mk_lib_crypto_xof_kt128_block_len_v;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_prrw_squeeze_u8s(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pt const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t avail mk_lang_constexpr_init;
	mk_lang_types_usize_t to_copy mk_lang_constexpr_init;
	mk_lang_types_sint_t idx mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_xof_kt128_block_len_v)) % ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v)) == 0);

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(kt128);
	mk_lang_assert(u8s || count == 0);
	mk_lang_assert(count >= 0);
	#if mk_lang_configuration_is_debug
	mk_lang_assert(kt128->m_finished);
	#endif
	#include "mk_lang_warning_msvc_pop.h"

	ptr = u8s;
	rem = count;
	avail = ((mk_lang_types_usize_t)(kt128->m_outer_rem));
	to_copy = mk_lang_min(avail, rem);
	idx = mk_lib_crypto_xof_kt128_block_len_v - kt128->m_outer_rem;
	mk_sl_cui_uint8_memcpy_fn(ptr, &kt128->m_outer_block.m_data.m_uint8s[0] + idx, to_copy);
	kt128->m_outer_rem -= ((mk_lang_types_sint_t)(to_copy));
	ptr += to_copy;
	rem -= to_copy;
	n = rem / mk_lib_crypto_xof_kt128_block_len_v;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_hash_block_sha3_base_f_turbo(&kt128->m_outer_state);
		mk_sl_uint_convert_64_8_le_to_sml_multi(&kt128->m_outer_state.m_data.m_uint64s[0], &ptr[0], ((mk_lang_types_sint_t)(mk_lib_crypto_xof_kt128_block_len_v)) / ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v)));
		ptr += mk_lib_crypto_xof_kt128_block_len_v;
		rem -= mk_lib_crypto_xof_kt128_block_len_v;
	}
	if(rem != 0)
	{
		mk_lang_assert(rem < mk_lib_crypto_xof_kt128_block_len_v);
		mk_lang_assert(kt128->m_outer_rem == 0);
		mk_lib_crypto_hash_block_sha3_base_f_turbo(&kt128->m_outer_state);
		mk_sl_uint_convert_64_8_le_to_sml_multi(&kt128->m_outer_state.m_data.m_uint64s[0], &kt128->m_outer_block.m_data.m_uint8s[0], ((mk_lang_types_sint_t)(mk_lib_crypto_xof_kt128_block_len_v)) / ((mk_lang_types_sint_t)(mk_sl_cui_uint64_size_bytes_v)));
		kt128->m_outer_rem = mk_lib_crypto_xof_kt128_block_len_v;
		avail = ((mk_lang_types_usize_t)(kt128->m_outer_rem));
		to_copy = mk_lang_min(avail, rem);
		idx = mk_lib_crypto_xof_kt128_block_len_v - kt128->m_outer_rem;
		mk_sl_cui_uint8_memcpy_fn(ptr, &kt128->m_outer_block.m_data.m_uint8s[0] + idx, to_copy);
		kt128->m_outer_rem -= ((mk_lang_types_sint_t)(to_copy));
		ptr += to_copy;
		rem -= to_copy;
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_kt128_init(mk_lib_crypto_xof_kt128_pt const kt128) mk_lang_noexcept
{
	mk_lib_crypto_xof_kt128_prrw_init(kt128);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_kt128_append_message_u8s(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lib_crypto_xof_kt128_prrw_append_message_u8s(kt128, u8s, count);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_kt128_append_customization_u8s(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pct const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lib_crypto_xof_kt128_prrw_append_customization_u8s(kt128, u8s, count);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_kt128_finish(mk_lib_crypto_xof_kt128_pt const kt128) mk_lang_noexcept
{
	mk_lib_crypto_xof_kt128_prrw_finish(kt128);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_xof_kt128_squeeze_u8s(mk_lib_crypto_xof_kt128_pt const kt128, mk_sl_cui_uint8_pt const u8s, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lib_crypto_xof_kt128_prrw_squeeze_u8s(kt128, u8s, count);
}


#endif
