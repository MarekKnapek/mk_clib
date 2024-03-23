#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_crash.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"
#include "mk_lib_crypto_alg_aes_base.h"


/* NIST FIPS PUB 197 */


#include "mk_lib_crypto_alg_aes_inl_defd.h"


#define mk_lib_crypto_alg_aes_inl_filec_sbox_len 0x0100
#define mk_lib_crypto_alg_aes_inl_filec_word_bits 32
#define mk_lib_crypto_alg_aes_inl_filec_word_bytes (mk_lib_crypto_alg_aes_inl_filec_word_bits  / mk_lang_charbit)
#define mk_lib_crypto_alg_aes_inl_filec_key_words (mk_lib_crypto_alg_aes_inl_defd_key_bits / mk_lib_crypto_alg_aes_inl_filec_word_bits)
#define mk_lib_crypto_alg_aes_inl_filec_msg_words (mk_lib_crypto_alg_aes_base_msg_bits / mk_lib_crypto_alg_aes_inl_filec_word_bits)


mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_c_schedule_encrypt(mk_lib_crypto_alg_aes_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	int iblock mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_base_msg_t state mk_lang_constexpr_init;
	int ir mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_lib_crypto_alg_aes_inl_defd_key_t) >= mk_lib_crypto_alg_aes_inl_defd_key_len_v);
	mk_lang_static_assert(sizeof(mk_lib_crypto_alg_aes_base_msg_t) == mk_lib_crypto_alg_aes_base_msg_len_v);

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		state = input[iblock];
		mk_lib_crypto_alg_aes_base_add_key2(&state, &schedule->m_data.m_msgs[0]);
		for(ir = 0; ir != mk_lib_crypto_alg_aes_inl_defd_nr - 1; ++ir)
		{
			mk_lib_crypto_alg_aes_base_sub_bytes(&state, &state);
			mk_lib_crypto_alg_aes_base_shift_rows(&state, &state);
			mk_lib_crypto_alg_aes_base_mix_columns(&state, &state);
			mk_lib_crypto_alg_aes_base_add_key2(&state, &schedule->m_data.m_msgs[ir + 1]);
		}
		mk_lib_crypto_alg_aes_base_sub_bytes(&state, &state);
		mk_lib_crypto_alg_aes_base_shift_rows(&state, &state);
		mk_lib_crypto_alg_aes_base_add_key2(&state, &schedule->m_data.m_msgs[mk_lib_crypto_alg_aes_inl_defd_nr]);
		output[iblock] = state;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_c_schedule_decrypt(mk_lib_crypto_alg_aes_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	int iblock mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_base_msg_t state mk_lang_constexpr_init;
	int ir mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_lib_crypto_alg_aes_inl_defd_key_t) >= mk_lib_crypto_alg_aes_inl_defd_key_len_v);
	mk_lang_static_assert(sizeof(mk_lib_crypto_alg_aes_base_msg_t) == mk_lib_crypto_alg_aes_base_msg_len_v);

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		state = input[iblock];
		mk_lib_crypto_alg_aes_base_add_key2(&state, &schedule->m_data.m_msgs[mk_lib_crypto_alg_aes_inl_defd_nr]);
		for(ir = 0; ir != mk_lib_crypto_alg_aes_inl_defd_nr - 1; ++ir)
		{
			mk_lib_crypto_alg_aes_base_inv_shift_rows(&state, &state);
			mk_lib_crypto_alg_aes_base_inv_sub_bytes(&state, &state);
			mk_lib_crypto_alg_aes_base_add_key2(&state, &schedule->m_data.m_msgs[mk_lib_crypto_alg_aes_inl_defd_nr - (ir + 1)]);
			mk_lib_crypto_alg_aes_base_inv_mix_columns(&state, &state);
		}
		mk_lib_crypto_alg_aes_base_inv_shift_rows(&state, &state);
		mk_lib_crypto_alg_aes_base_inv_sub_bytes(&state, &state);
		mk_lib_crypto_alg_aes_base_add_key2(&state, &schedule->m_data.m_msgs[0]);
		output[iblock] = state;
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_c_expand(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	#define get_outer(x) ((x) / mk_lib_crypto_alg_aes_base_msg_len_v)
	#define get_inner(x) ((x) % mk_lib_crypto_alg_aes_base_msg_len_v)

	mk_sl_cui_uint8_t rcon mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	int j mk_lang_constexpr_init;
	int idx_prev mk_lang_constexpr_init;
	int idx_curr mk_lang_constexpr_init;
	int idx_oldd mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_base_word_t tmp mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	mk_sl_cui_uint8_set_one(&rcon);
	for(i = 0; i != mk_lib_crypto_alg_aes_inl_defd_key_len_v; ++i){ schedule->m_data.m_msgs[get_outer(i)].m_data.m_uint8s[get_inner(i)] = key->m_data.m_uint8s[i]; }
	for(i = mk_lib_crypto_alg_aes_inl_filec_key_words; i != (mk_lib_crypto_alg_aes_inl_defd_nr + 1) * mk_lib_crypto_alg_aes_base_msg_words; ++i)
	{
		idx_prev = (i - 1) * mk_lib_crypto_alg_aes_inl_filec_word_bytes;
		for(j = 0; j != mk_lib_crypto_alg_aes_inl_filec_word_bytes; ++j){ tmp.m_data.m_uint8s[j] = schedule->m_data.m_msgs[get_outer(idx_prev + j)].m_data.m_uint8s[get_inner(idx_prev + j)]; }
		if(i % mk_lib_crypto_alg_aes_inl_filec_key_words == 0)
		{
			mk_lib_crypto_alg_aes_base_rot_word(&tmp, &tmp);
			mk_lib_crypto_alg_aes_base_sub_word(&tmp, &tmp);
			mk_lib_crypto_alg_aes_base_xor_word(&tmp, &rcon, &tmp, &rcon);
		}
		#if mk_lib_crypto_alg_aes_inl_filec_key_words > 6
		else if(i % mk_lib_crypto_alg_aes_inl_filec_key_words == 4)
		{
			mk_lib_crypto_alg_aes_base_sub_word(&tmp, &tmp);
		}
		#endif
		idx_curr = i * mk_lib_crypto_alg_aes_inl_filec_word_bytes;
		idx_oldd = (i - mk_lib_crypto_alg_aes_inl_filec_key_words) * mk_lib_crypto_alg_aes_inl_filec_word_bytes;
		for(j = 0; j != mk_lib_crypto_alg_aes_inl_filec_word_bytes; ++j)
		{
			mk_sl_cui_uint8_xor3(&tmp.m_data.m_uint8s[j], &schedule->m_data.m_msgs[get_outer(idx_oldd + j)].m_data.m_uint8s[get_inner(idx_oldd + j)], &schedule->m_data.m_msgs[get_outer(idx_curr + j)].m_data.m_uint8s[get_inner(idx_curr + j)]);
		}
	}

	#undef get_outer
	#undef get_inner
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_c_expand_enc(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_inl_defd_c_expand(key, schedule);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_c_expand_dec(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_inl_defd_c_expand(key, schedule);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_c_encrypt(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_inl_defd_schedule_t schedule mk_lang_constexpr_init;

	mk_lib_crypto_alg_aes_inl_defd_c_expand_enc(key, &schedule);
	mk_lib_crypto_alg_aes_inl_defd_c_schedule_encrypt(&schedule, input, output, 1);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_c_decrypt(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_inl_defd_schedule_t schedule mk_lang_constexpr_init;

	mk_lib_crypto_alg_aes_inl_defd_c_expand_dec(key, &schedule);
	mk_lib_crypto_alg_aes_inl_defd_c_schedule_decrypt(&schedule, input, output, 1);
}


#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1))


#include <emmintrin.h> /* _mm_castpd_si128 _mm_castsi128_pd _mm_load_si128 _mm_loadu_si128 _mm_shuffle_epi32 _mm_slli_si128 _mm_store_si128 _mm_storeu_si128 _mm_xor_si128 */
#include <wmmintrin.h> /* _mm_aesdec_si128 _mm_aesdeclast_si128 _mm_aesenc_si128 _mm_aesenclast_si128 _mm_aesimc_si128 _mm_aeskeygenassist_si128 */


static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_schedule_encrypt(mk_lib_crypto_alg_aes_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	int iblock;
	int i;
	__m128i v;
	__m128i ta;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_inl_defd_schedule_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_base_msg_t) >= sizeof(__m128i));

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		i = 0;
		v = _mm_load_si128(((__m128i const*)(&input[iblock])));
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_xor_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_aesenc_si128(v, ta);
		#if mk_lib_crypto_alg_aes_t_key_bits >= 192
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_aesenc_si128(v, ta);
		#if mk_lib_crypto_alg_aes_t_key_bits == 256
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_aesenc_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_aesenc_si128(v, ta);
		#endif
		#endif
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i++]))); v = _mm_aesenclast_si128(v, ta);
		_mm_store_si128(((__m128i*)(&output[iblock])), v);
	}
}

static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_schedule_decrypt(mk_lib_crypto_alg_aes_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	int iblock;
	int i;
	__m128i v;
	__m128i ta;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_inl_defd_schedule_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_base_msg_t) >= sizeof(__m128i));

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		i = mk_lib_crypto_alg_aes_t_nr;
		v = _mm_load_si128(((__m128i const*)(&input[iblock])));
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_xor_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_aesdec_si128(v, ta);
		#if mk_lib_crypto_alg_aes_t_key_bits >= 192
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_aesdec_si128(v, ta);
		#if mk_lib_crypto_alg_aes_t_key_bits == 256
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_aesdec_si128(v, ta);
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_aesdec_si128(v, ta);
		#endif
		#endif
		ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[i--]))); v = _mm_aesdeclast_si128(v, ta);
		_mm_store_si128(((__m128i*)(&output[iblock])), v);
	}
}

static mk_lang_inline __m128i mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_a(__m128i const a, __m128i const b) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;

	ta = a;
	tb = b;
	tb = _mm_shuffle_epi32(tb, 0xff);
	tc = _mm_slli_si128(ta, 0x04);
	ta = _mm_xor_si128(ta, tc);
	tc = _mm_slli_si128(tc, 0x04);
	ta = _mm_xor_si128(ta, tc);
	tc = _mm_slli_si128(tc, 0x04);
	ta = _mm_xor_si128(ta, tc);
	ta = _mm_xor_si128(ta, tb);
	return ta;
}

static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_b(__m128i* const ta, __m128i* const tb, __m128i* const tc) mk_lang_noexcept
{
	__m128i td;

	mk_lang_assert(ta);
	mk_lang_assert(tb);
	mk_lang_assert(tc);

	*tb = _mm_shuffle_epi32(*tb, 0x55);
	td = _mm_slli_si128(*ta, 0x04);
	*ta = _mm_xor_si128(*ta ,td);
	td = _mm_slli_si128(td, 0x04);
	*ta = _mm_xor_si128(*ta, td);
	td = _mm_slli_si128(td, 0x04);
	*ta = _mm_xor_si128(*ta, td);
	*ta = _mm_xor_si128(*ta, *tb);
	*tb = _mm_shuffle_epi32(*ta, 0xff);
	td = _mm_slli_si128(*tc, 0x04);
	*tc = _mm_xor_si128(*tc, td);
	*tc = _mm_xor_si128(*tc, *tb);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_ca(__m128i* const ta, __m128i* const tb) mk_lang_noexcept
{
	__m128i tc;

	mk_lang_assert(ta);
	mk_lang_assert(tb);

	*tb = _mm_shuffle_epi32(*tb, 0xff);
	tc = _mm_slli_si128(*ta, 0x04);
	*ta = _mm_xor_si128(*ta, tc);
	tc = _mm_slli_si128(tc, 0x04);
	*ta = _mm_xor_si128(*ta, tc);
	tc = _mm_slli_si128(tc, 0x04);
	*ta = _mm_xor_si128(*ta, tc);
	*ta = _mm_xor_si128(*ta, *tb);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_cb(__m128i* const ta, __m128i* const tb) mk_lang_noexcept
{
	__m128i tc;
	__m128i td;

	mk_lang_assert(ta);
	mk_lang_assert(tb);

	tc = _mm_aeskeygenassist_si128(*ta, 0x00);
	td = _mm_shuffle_epi32(tc, 0xaa);
	tc = _mm_slli_si128(*tb, 0x04);
	*tb = _mm_xor_si128(*tb, tc);
	tc = _mm_slli_si128(tc, 0x04);
	*tb = _mm_xor_si128(*tb, tc);
	tc = _mm_slli_si128(tc, 0x04);
	*tb = _mm_xor_si128(*tb, tc);
	*tb = _mm_xor_si128(*tb, td);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_expand_enc_a(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_inl_defd_key_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_inl_defd_schedule_t) >= sizeof(__m128i));

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	ta = _mm_loadu_si128(((__m128i const*)(&key->m_data.m_uint8s[0])));
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[0])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x01); ta = mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_a(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 1])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x02); ta = mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_a(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 2])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x04); ta = mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_a(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 3])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x08); ta = mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_a(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 4])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x10); ta = mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_a(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 5])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x20); ta = mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_a(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 6])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x40); ta = mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_a(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 7])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x80); ta = mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_a(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 8])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x1b); ta = mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_a(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 9])), ta);
	tb = _mm_aeskeygenassist_si128(ta, 0x36); ta = mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_a(ta, tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[10])), ta);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_expand_enc_b(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	union word_u
	{
		unsigned char m_uchars[16];
		__m128i m_i128;
	};
	typedef union word_u word_t;

	int i;
	word_t w;
	__m128i ta;
	__m128i tb;
	__m128i tc;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_inl_defd_schedule_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_base_msg_t) >= sizeof(__m128i));

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	for(i = 0; i !=  8; ++i){ mk_sl_cui_uint8_to_bi_uchar(&key->m_data.m_uint8s[16 + i], &w.m_uchars[i]); }
	for(i = 8; i != 16; ++i){ w.m_uchars[i] = 0; }
	ta = _mm_loadu_si128(((__m128i const*)(&key->m_data.m_uint8s[0])));
	tb = _mm_loadu_si128(((__m128i const*)(&w.m_uchars[0])));
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[0])), ta);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[1])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x01);
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_b(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[1])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(_mm_loadu_si128(((__m128i const*)(&schedule->m_data.m_msgs[1])))), _mm_castsi128_pd(ta), 0)));
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[2])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(ta), _mm_castsi128_pd(tb), 1)));
	tc = _mm_aeskeygenassist_si128(tb, 0x02);
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_b(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[3])), ta);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[4])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x04);
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_b(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[4])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(_mm_loadu_si128(((__m128i const*)(&schedule->m_data.m_msgs[4])))), _mm_castsi128_pd(ta), 0)));
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[5])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(ta), _mm_castsi128_pd(tb), 1)));
	tc = _mm_aeskeygenassist_si128(tb, 0x08);
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_b(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[6])), ta);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[7])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x10);
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_b(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[7])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(_mm_loadu_si128(((__m128i const*)(&schedule->m_data.m_msgs[7])))), _mm_castsi128_pd(ta), 0)));
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[8])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(ta), _mm_castsi128_pd(tb), 1)));
	tc = _mm_aeskeygenassist_si128(tb, 0x20);
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_b(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[9])), ta);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[10])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x40);
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_b(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[10])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(_mm_loadu_si128(((__m128i const*)(&schedule->m_data.m_msgs[10])))), _mm_castsi128_pd(ta), 0)));
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[11])), _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(ta), _mm_castsi128_pd(tb), 1)));
	tc = _mm_aeskeygenassist_si128(tb, 0x80);
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_b(&ta, &tc, &tb);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[12])), ta);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_expand_enc_c(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	__m128i ta;
	__m128i tb;
	__m128i tc;

	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_inl_defd_schedule_t) >= sizeof(__m128i));
	mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_alg_aes_base_msg_t) >= sizeof(__m128i));

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	ta = _mm_load_si128(((__m128i const*)(&key->m_data.m_uint8s[ 0])));
	tb = _mm_load_si128(((__m128i const*)(&key->m_data.m_uint8s[16])));
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[0])), ta);
	_mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[1])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x01); mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_ca(&ta, &tc); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 2])), ta); mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_cb(&ta, &tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 3])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x02); mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_ca(&ta, &tc); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 4])), ta); mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_cb(&ta, &tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 5])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x04); mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_ca(&ta, &tc); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 6])), ta); mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_cb(&ta, &tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 7])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x08); mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_ca(&ta, &tc); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 8])), ta); mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_cb(&ta, &tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[ 9])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x10); mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_ca(&ta, &tc); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[10])), ta); mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_cb(&ta, &tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[11])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x20); mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_ca(&ta, &tc); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[12])), ta); mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_cb(&ta, &tb); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[13])), tb);
	tc = _mm_aeskeygenassist_si128(tb, 0x40); mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_assist_ca(&ta, &tc); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[14])), ta);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_expand_enc(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
#if mk_lib_crypto_alg_aes_t_key_bits == 128
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_expand_enc_a(key, schedule);
#elif mk_lib_crypto_alg_aes_t_key_bits == 192
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_expand_enc_b(key, schedule);
#elif mk_lib_crypto_alg_aes_t_key_bits == 256
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_expand_enc_c(key, schedule);
#else
	mk_lang_assert(0);
#endif
}

static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_expand_dec(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	int i;
	__m128i ta;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	i = 0;
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_expand_enc(key, schedule);
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[++i]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[i])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[++i]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[i])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[++i]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[i])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[++i]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[i])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[++i]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[i])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[++i]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[i])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[++i]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[i])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[++i]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[i])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[++i]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[i])), _mm_aesimc_si128(ta));
	#if mk_lib_crypto_alg_aes_t_key_bits >= 192
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[++i]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[i])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[++i]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[i])), _mm_aesimc_si128(ta));
	#if mk_lib_crypto_alg_aes_t_key_bits == 256
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[++i]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[i])), _mm_aesimc_si128(ta));
	ta = _mm_load_si128(((__m128i const*)(&schedule->m_data.m_msgs[++i]))); _mm_store_si128(((__m128i*)(&schedule->m_data.m_msgs[i])), _mm_aesimc_si128(ta));
	#endif
	#endif
}

static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_encrypt(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_inl_defd_schedule_t schedule;

	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_expand_enc(key, &schedule);
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_schedule_encrypt(&schedule, input, output, 1);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_decrypt(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_inl_defd_schedule_t schedule;

	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_expand_dec(key, &schedule);
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_schedule_decrypt(&schedule, input, output, 1);
}


#endif


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_portable_schedule_encrypt(mk_lib_crypto_alg_aes_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_inl_defd_c_schedule_encrypt(schedule, input, output, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_portable_schedule_decrypt(mk_lib_crypto_alg_aes_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_inl_defd_c_schedule_decrypt(schedule, input, output, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_portable_expand_enc(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_inl_defd_c_expand_enc(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_portable_expand_dec(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_inl_defd_c_expand_dec(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_portable_encrypt(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_inl_defd_c_encrypt(key, input, output);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_portable_decrypt(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_inl_defd_c_decrypt(key, input, output);
}


mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_accelerated_schedule_encrypt(mk_lib_crypto_alg_aes_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
	mk_lang_assert(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni());
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_schedule_encrypt(schedule, input, output, nblocks);
	#else
	((void)(schedule));
	((void)(input));
	((void)(output));
	((void)(nblocks));
	mk_lang_crash();
	#endif
}

mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_accelerated_schedule_decrypt(mk_lib_crypto_alg_aes_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
	mk_lang_assert(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni());
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_schedule_decrypt(schedule, input, output, nblocks);
	#else
	((void)(schedule));
	((void)(input));
	((void)(output));
	((void)(nblocks));
	mk_lang_crash();
	#endif
}

mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_accelerated_expand_enc(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
	mk_lang_assert(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni());
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_expand_enc(key, schedule);
	#else
	((void)(key));
	((void)(schedule));
	mk_lang_crash();
	#endif
}

mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_accelerated_expand_dec(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
	mk_lang_assert(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni());
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_expand_dec(key, schedule);
	#else
	((void)(key));
	((void)(schedule));
	mk_lang_crash();
	#endif
}

mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_accelerated_encrypt(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
	mk_lang_assert(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni());
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_encrypt(key, input, output);
	#else
	((void)(key));
	((void)(input));
	((void)(output));
	mk_lang_crash();
	#endif
}

mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_accelerated_decrypt(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
	mk_lang_assert(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni());
	mk_lib_crypto_alg_aes_inl_defd_msvc_aes_ni_decrypt(key, input, output);
	#else
	((void)(key));
	((void)(input));
	((void)(output));
	mk_lang_crash();
	#endif
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_schedule_encrypt(mk_lib_crypto_alg_aes_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#endif
	{
		mk_lib_crypto_alg_aes_inl_defd_accelerated_schedule_encrypt(schedule, input, output, nblocks);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_aes_inl_defd_portable_schedule_encrypt(schedule, input, output, nblocks);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_schedule_decrypt(mk_lib_crypto_alg_aes_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#endif
	{
		mk_lib_crypto_alg_aes_inl_defd_accelerated_schedule_decrypt(schedule, input, output, nblocks);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_aes_inl_defd_portable_schedule_decrypt(schedule, input, output, nblocks);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_expand_enc(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#endif
	{
		mk_lib_crypto_alg_aes_inl_defd_accelerated_expand_enc(key, schedule);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_aes_inl_defd_portable_expand_enc(key, schedule);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_expand_dec(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#endif
	{
		mk_lib_crypto_alg_aes_inl_defd_accelerated_expand_dec(key, schedule);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_aes_inl_defd_portable_expand_dec(key, schedule);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_encrypt(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#endif
	{
		mk_lib_crypto_alg_aes_inl_defd_accelerated_encrypt(key, input, output);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_aes_inl_defd_portable_encrypt(key, input, output);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_inl_defd_decrypt(mk_lib_crypto_alg_aes_inl_defd_key_pct const key, mk_lib_crypto_alg_aes_base_msg_pct const input, mk_lib_crypto_alg_aes_base_msg_pt const output) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (mk_lang_msvc_full_ver >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#endif
	{
		mk_lib_crypto_alg_aes_inl_defd_accelerated_decrypt(key, input, output);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_aes_inl_defd_portable_decrypt(key, input, output);
	}
}


#include "mk_lib_crypto_alg_aes_inl_defu.h"


#undef mk_lib_crypto_alg_aes_t_name
#undef mk_lib_crypto_alg_aes_t_key_bits
#undef mk_lib_crypto_alg_aes_t_nr
