#include "mk_lib_crypto_alg_aes_192.h"

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


/* NIST FIPS PUB 197 */


#define mk_lib_crypto_alg_aes_192_nr 12
#define mk_lib_crypto_alg_aes_192_sbox_len 0x0100
#define mk_lib_crypto_alg_aes_192_key_bits 192
#define mk_lib_crypto_alg_aes_192_msg_bits 128
#define mk_lib_crypto_alg_aes_192_word_bits 32
#define mk_lib_crypto_alg_aes_192_byte_bits 8
#define mk_lib_crypto_alg_aes_192_word_bytes (mk_lib_crypto_alg_aes_192_word_bits  / mk_lib_crypto_alg_aes_192_byte_bits)
#define mk_lib_crypto_alg_aes_192_key_words (mk_lib_crypto_alg_aes_192_key_bits / mk_lib_crypto_alg_aes_192_word_bits)
#define mk_lib_crypto_alg_aes_192_msg_words (mk_lib_crypto_alg_aes_192_msg_bits / mk_lib_crypto_alg_aes_192_word_bits)


union mk_lib_crypto_alg_aes_192_aligned_sbox_u
{
	mk_lang_types_uchar_t m_uchars[mk_lib_crypto_alg_aes_192_sbox_len];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_aes_192_aligned_sbox_u mk_lib_crypto_alg_aes_192_aligned_sbox_t;
typedef mk_lib_crypto_alg_aes_192_aligned_sbox_t const mk_lib_crypto_alg_aes_192_aligned_sbox_ct;
typedef mk_lib_crypto_alg_aes_192_aligned_sbox_t* mk_lib_crypto_alg_aes_192_aligned_sbox_pt;
typedef mk_lib_crypto_alg_aes_192_aligned_sbox_t const* mk_lib_crypto_alg_aes_192_aligned_sbox_pct;

union mk_lib_crypto_alg_aes_192_aligned_word_u
{
	mk_lang_types_uchar_t m_uchars[mk_lib_crypto_alg_aes_192_word_bytes];
	mk_lang_types_ulong_t m_align;
};
typedef union mk_lib_crypto_alg_aes_192_aligned_word_u mk_lib_crypto_alg_aes_192_aligned_word_t;
typedef mk_lib_crypto_alg_aes_192_aligned_word_t const mk_lib_crypto_alg_aes_192_aligned_word_ct;
typedef mk_lib_crypto_alg_aes_192_aligned_word_t* mk_lib_crypto_alg_aes_192_aligned_word_pt;
typedef mk_lib_crypto_alg_aes_192_aligned_word_t const* mk_lib_crypto_alg_aes_192_aligned_word_pct;

struct mk_lib_crypto_alg_aes_192_sbox_s
{
	mk_lib_crypto_alg_aes_192_aligned_sbox_t m_data;
};
typedef struct mk_lib_crypto_alg_aes_192_sbox_s mk_lib_crypto_alg_aes_192_sbox_t;
typedef mk_lib_crypto_alg_aes_192_sbox_t const mk_lib_crypto_alg_aes_192_sbox_ct;
typedef mk_lib_crypto_alg_aes_192_sbox_t* mk_lib_crypto_alg_aes_192_sbox_pt;
typedef mk_lib_crypto_alg_aes_192_sbox_t const* mk_lib_crypto_alg_aes_192_sbox_pct;

struct mk_lib_crypto_alg_aes_192_word_s
{
	mk_lib_crypto_alg_aes_192_aligned_word_t m_data;
};
typedef struct mk_lib_crypto_alg_aes_192_word_s mk_lib_crypto_alg_aes_192_word_t;
typedef mk_lib_crypto_alg_aes_192_word_t const mk_lib_crypto_alg_aes_192_word_ct;
typedef mk_lib_crypto_alg_aes_192_word_t* mk_lib_crypto_alg_aes_192_word_pt;
typedef mk_lib_crypto_alg_aes_192_word_t const* mk_lib_crypto_alg_aes_192_word_pct;


mk_lang_constexpr_static_inline mk_lib_crypto_alg_aes_192_sbox_t const s_mk_lib_crypto_alg_aes_192_sbox =
{{{
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16,
}}};

mk_lang_constexpr_static_inline mk_lib_crypto_alg_aes_192_sbox_t const s_mk_lib_crypto_alg_aes_192_inv_sbox =
{{{
	0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
	0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
	0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
	0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
	0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
	0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
	0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
	0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
	0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
	0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
	0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
	0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
	0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
	0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
	0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
	0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d,
}}};


mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_sub_byte(mk_lang_types_uchar_pt const byte) mk_lang_noexcept
{
	mk_lang_assert(byte);

	*byte = s_mk_lib_crypto_alg_aes_192_sbox.m_data.m_uchars[*byte];
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_sub_bytes(mk_lib_crypto_alg_aes_192_msg_pt const state) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(state);

	for(i = 0; i != mk_lib_crypto_alg_aes_192_msg_len_v; ++i)
	{
		mk_lib_crypto_alg_aes_192_sub_byte(&state->m_data.m_uchars[i]);
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_inv_sub_byte(mk_lang_types_uchar_pt const byte) mk_lang_noexcept
{
	mk_lang_assert(byte);

	*byte = s_mk_lib_crypto_alg_aes_192_inv_sbox.m_data.m_uchars[*byte];
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_inv_sub_bytes(mk_lib_crypto_alg_aes_192_msg_pt const state) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(state);

	for(i = 0; i != mk_lib_crypto_alg_aes_192_msg_len_v; ++i)
	{
		mk_lib_crypto_alg_aes_192_inv_sub_byte(&state->m_data.m_uchars[i]);
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_shift_rows(mk_lib_crypto_alg_aes_192_msg_pt const state) mk_lang_noexcept
{
	mk_lang_types_uchar_t ta mk_lang_constexpr_init;
	mk_lang_types_uchar_t tb mk_lang_constexpr_init;

	mk_lang_assert(state);

	ta = state->m_data.m_uchars[0 * 4 + 1];
	state->m_data.m_uchars[0 * 4 + 1] = state->m_data.m_uchars[1 * 4 + 1];
	state->m_data.m_uchars[1 * 4 + 1] = state->m_data.m_uchars[2 * 4 + 1];
	state->m_data.m_uchars[2 * 4 + 1] = state->m_data.m_uchars[3 * 4 + 1];
	state->m_data.m_uchars[3 * 4 + 1] = ta;

	ta = state->m_data.m_uchars[0 * 4 + 2];
	tb = state->m_data.m_uchars[1 * 4 + 2];
	state->m_data.m_uchars[0 * 4 + 2] = state->m_data.m_uchars[2 * 4 + 2];
	state->m_data.m_uchars[1 * 4 + 2] = state->m_data.m_uchars[3 * 4 + 2];
	state->m_data.m_uchars[2 * 4 + 2] = ta;
	state->m_data.m_uchars[3 * 4 + 2] = tb;

	ta = state->m_data.m_uchars[1 * 4 + 3];
	state->m_data.m_uchars[1 * 4 + 3] = state->m_data.m_uchars[0 * 4 + 3];
	state->m_data.m_uchars[0 * 4 + 3] = state->m_data.m_uchars[3 * 4 + 3];
	state->m_data.m_uchars[3 * 4 + 3] = state->m_data.m_uchars[2 * 4 + 3];
	state->m_data.m_uchars[2 * 4 + 3] = ta;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_inv_shift_rows(mk_lib_crypto_alg_aes_192_msg_pt const state) mk_lang_noexcept
{
	mk_lang_types_uchar_t ta mk_lang_constexpr_init;
	mk_lang_types_uchar_t tb mk_lang_constexpr_init;

	mk_lang_assert(state);

	ta = state->m_data.m_uchars[1 * 4 + 1];
	state->m_data.m_uchars[1 * 4 + 1] = state->m_data.m_uchars[0 * 4 + 1];
	state->m_data.m_uchars[0 * 4 + 1] = state->m_data.m_uchars[3 * 4 + 1];
	state->m_data.m_uchars[3 * 4 + 1] = state->m_data.m_uchars[2 * 4 + 1];
	state->m_data.m_uchars[2 * 4 + 1] = ta;

	ta = state->m_data.m_uchars[0 * 4 + 2];
	tb = state->m_data.m_uchars[1 * 4 + 2];
	state->m_data.m_uchars[0 * 4 + 2] = state->m_data.m_uchars[2 * 4 + 2];
	state->m_data.m_uchars[1 * 4 + 2] = state->m_data.m_uchars[3 * 4 + 2];
	state->m_data.m_uchars[2 * 4 + 2] = ta;
	state->m_data.m_uchars[3 * 4 + 2] = tb;

	ta = state->m_data.m_uchars[0 * 4 + 3];
	state->m_data.m_uchars[0 * 4 + 3] = state->m_data.m_uchars[1 * 4 + 3];
	state->m_data.m_uchars[1 * 4 + 3] = state->m_data.m_uchars[2 * 4 + 3];
	state->m_data.m_uchars[2 * 4 + 3] = state->m_data.m_uchars[3 * 4 + 3];
	state->m_data.m_uchars[3 * 4 + 3] = ta;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_uchar_t mk_lib_crypto_alg_aes_192_mul_1(mk_lang_types_uchar_t const x) mk_lang_noexcept
{
	return x;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_uchar_t mk_lib_crypto_alg_aes_192_mul_2(mk_lang_types_uchar_t const x) mk_lang_noexcept
{
	return
	((mk_lang_types_uchar_t)(
		((mk_lang_types_uchar_t)(x << 1))
		^
		((mk_lang_types_uchar_t)(
			((mk_lang_types_uchar_t)(
				((mk_lang_types_uchar_t)(x >> 7))
				&
				((mk_lang_types_uchar_t)(0x01))
			))
			*
			((mk_lang_types_uchar_t)(0x1b))
		))
	));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_uchar_t mk_lib_crypto_alg_aes_192_mul_3(mk_lang_types_uchar_t const x) mk_lang_noexcept
{
	return ((mk_lang_types_uchar_t)(mk_lib_crypto_alg_aes_192_mul_2(x) ^ mk_lib_crypto_alg_aes_192_mul_1(x)));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_uchar_t mk_lib_crypto_alg_aes_192_mul_4(mk_lang_types_uchar_t const x) mk_lang_noexcept
{
	return mk_lib_crypto_alg_aes_192_mul_2(mk_lib_crypto_alg_aes_192_mul_2(x));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_uchar_t mk_lib_crypto_alg_aes_192_mul_8(mk_lang_types_uchar_t const x) mk_lang_noexcept
{
	return mk_lib_crypto_alg_aes_192_mul_2(mk_lib_crypto_alg_aes_192_mul_2(mk_lib_crypto_alg_aes_192_mul_2(x)));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_uchar_t mk_lib_crypto_alg_aes_192_mul_9(mk_lang_types_uchar_t const x) mk_lang_noexcept
{
	return ((mk_lang_types_uchar_t)(mk_lib_crypto_alg_aes_192_mul_8(x) ^ mk_lib_crypto_alg_aes_192_mul_1(x)));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_uchar_t mk_lib_crypto_alg_aes_192_mul_b(mk_lang_types_uchar_t const x) mk_lang_noexcept
{
	return ((mk_lang_types_uchar_t)(mk_lib_crypto_alg_aes_192_mul_8(x) ^ mk_lib_crypto_alg_aes_192_mul_2(x) ^ mk_lib_crypto_alg_aes_192_mul_1(x)));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_uchar_t mk_lib_crypto_alg_aes_192_mul_d(mk_lang_types_uchar_t const x) mk_lang_noexcept
{
	return ((mk_lang_types_uchar_t)(mk_lib_crypto_alg_aes_192_mul_8(x) ^ mk_lib_crypto_alg_aes_192_mul_4(x) ^ mk_lib_crypto_alg_aes_192_mul_1(x)));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_uchar_t mk_lib_crypto_alg_aes_192_mul_e(mk_lang_types_uchar_t const x) mk_lang_noexcept
{
	return ((mk_lang_types_uchar_t)(mk_lib_crypto_alg_aes_192_mul_8(x) ^ mk_lib_crypto_alg_aes_192_mul_4(x) ^ mk_lib_crypto_alg_aes_192_mul_2(x)));
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_mix_columns(mk_lib_crypto_alg_aes_192_msg_pt const state) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_192_msg_t orig mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(state);

	orig = *state;
	for(i = 0; i != 4; ++i)
	{
		state->m_data.m_uchars[i * 4 + 0] = ((mk_lang_types_uchar_t)(mk_lib_crypto_alg_aes_192_mul_2(orig.m_data.m_uchars[i * 4 + 0]) ^ mk_lib_crypto_alg_aes_192_mul_3(orig.m_data.m_uchars[i * 4 + 1]) ^ mk_lib_crypto_alg_aes_192_mul_1(orig.m_data.m_uchars[i * 4 + 2]) ^ mk_lib_crypto_alg_aes_192_mul_1(orig.m_data.m_uchars[i * 4 + 3])));
		state->m_data.m_uchars[i * 4 + 1] = ((mk_lang_types_uchar_t)(mk_lib_crypto_alg_aes_192_mul_1(orig.m_data.m_uchars[i * 4 + 0]) ^ mk_lib_crypto_alg_aes_192_mul_2(orig.m_data.m_uchars[i * 4 + 1]) ^ mk_lib_crypto_alg_aes_192_mul_3(orig.m_data.m_uchars[i * 4 + 2]) ^ mk_lib_crypto_alg_aes_192_mul_1(orig.m_data.m_uchars[i * 4 + 3])));
		state->m_data.m_uchars[i * 4 + 2] = ((mk_lang_types_uchar_t)(mk_lib_crypto_alg_aes_192_mul_1(orig.m_data.m_uchars[i * 4 + 0]) ^ mk_lib_crypto_alg_aes_192_mul_1(orig.m_data.m_uchars[i * 4 + 1]) ^ mk_lib_crypto_alg_aes_192_mul_2(orig.m_data.m_uchars[i * 4 + 2]) ^ mk_lib_crypto_alg_aes_192_mul_3(orig.m_data.m_uchars[i * 4 + 3])));
		state->m_data.m_uchars[i * 4 + 3] = ((mk_lang_types_uchar_t)(mk_lib_crypto_alg_aes_192_mul_3(orig.m_data.m_uchars[i * 4 + 0]) ^ mk_lib_crypto_alg_aes_192_mul_1(orig.m_data.m_uchars[i * 4 + 1]) ^ mk_lib_crypto_alg_aes_192_mul_1(orig.m_data.m_uchars[i * 4 + 2]) ^ mk_lib_crypto_alg_aes_192_mul_2(orig.m_data.m_uchars[i * 4 + 3])));
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_inv_mix_columns(mk_lib_crypto_alg_aes_192_msg_pt const state) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_192_msg_t orig mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(state);

	orig = *state;
	for(i = 0; i != 4; ++i)
	{
		state->m_data.m_uchars[i * 4 + 0] = ((mk_lang_types_uchar_t)(mk_lib_crypto_alg_aes_192_mul_e(orig.m_data.m_uchars[i * 4 + 0]) ^ mk_lib_crypto_alg_aes_192_mul_b(orig.m_data.m_uchars[i * 4 + 1]) ^ mk_lib_crypto_alg_aes_192_mul_d(orig.m_data.m_uchars[i * 4 + 2]) ^ mk_lib_crypto_alg_aes_192_mul_9(orig.m_data.m_uchars[i * 4 + 3])));
		state->m_data.m_uchars[i * 4 + 1] = ((mk_lang_types_uchar_t)(mk_lib_crypto_alg_aes_192_mul_9(orig.m_data.m_uchars[i * 4 + 0]) ^ mk_lib_crypto_alg_aes_192_mul_e(orig.m_data.m_uchars[i * 4 + 1]) ^ mk_lib_crypto_alg_aes_192_mul_b(orig.m_data.m_uchars[i * 4 + 2]) ^ mk_lib_crypto_alg_aes_192_mul_d(orig.m_data.m_uchars[i * 4 + 3])));
		state->m_data.m_uchars[i * 4 + 2] = ((mk_lang_types_uchar_t)(mk_lib_crypto_alg_aes_192_mul_d(orig.m_data.m_uchars[i * 4 + 0]) ^ mk_lib_crypto_alg_aes_192_mul_9(orig.m_data.m_uchars[i * 4 + 1]) ^ mk_lib_crypto_alg_aes_192_mul_e(orig.m_data.m_uchars[i * 4 + 2]) ^ mk_lib_crypto_alg_aes_192_mul_b(orig.m_data.m_uchars[i * 4 + 3])));
		state->m_data.m_uchars[i * 4 + 3] = ((mk_lang_types_uchar_t)(mk_lib_crypto_alg_aes_192_mul_b(orig.m_data.m_uchars[i * 4 + 0]) ^ mk_lib_crypto_alg_aes_192_mul_d(orig.m_data.m_uchars[i * 4 + 1]) ^ mk_lib_crypto_alg_aes_192_mul_9(orig.m_data.m_uchars[i * 4 + 2]) ^ mk_lib_crypto_alg_aes_192_mul_e(orig.m_data.m_uchars[i * 4 + 3])));
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_add_key(mk_lib_crypto_alg_aes_192_msg_pt const state, mk_lib_crypto_alg_aes_192_msg_pct const key) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(state);
	mk_lang_assert(key);
	mk_lang_assert(state != key);

	for(i = 0; i != mk_lib_crypto_alg_aes_192_msg_len_v; ++i)
	{
		state->m_data.m_uchars[i] ^= key->m_data.m_uchars[i];
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_rot_word(mk_lib_crypto_alg_aes_192_word_pt const w) mk_lang_noexcept
{
	mk_lang_types_uchar_t ta mk_lang_constexpr_init;

	mk_lang_assert(w);

	ta = w->m_data.m_uchars[0];
	w->m_data.m_uchars[0] = w->m_data.m_uchars[1];
	w->m_data.m_uchars[1] = w->m_data.m_uchars[2];
	w->m_data.m_uchars[2] = w->m_data.m_uchars[3];
	w->m_data.m_uchars[3] = ta;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_sub_word(mk_lib_crypto_alg_aes_192_word_pt const w) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(w);

	for(i = 0; i != mk_lib_crypto_alg_aes_192_word_bytes; ++i)
	{
		mk_lib_crypto_alg_aes_192_sub_byte(&w->m_data.m_uchars[i]);
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_xor_word(mk_lib_crypto_alg_aes_192_word_pt const w, mk_lang_types_uchar_pt const rcon) mk_lang_noexcept
{
	mk_lang_assert(w);
	mk_lang_assert(rcon);

	w->m_data.m_uchars[0] ^= *rcon;
	*rcon = mk_lib_crypto_alg_aes_192_mul_2(*rcon);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_generate_keys(mk_lib_crypto_alg_aes_192_key_pct const key, mk_lib_crypto_alg_aes_192_msg_pt const keys) mk_lang_noexcept
{
	#define get_outer(x) ((x) / mk_lib_crypto_alg_aes_192_msg_len_m)
	#define get_inner(x) ((x) % mk_lib_crypto_alg_aes_192_msg_len_m)

	mk_lang_types_uchar_t rcon mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	int j mk_lang_constexpr_init;
	int idx_prev mk_lang_constexpr_init;
	int idx_curr mk_lang_constexpr_init;
	int idx_oldd mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_192_word_t tmp mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(keys);

	rcon = 1;
	for(i = 0; i != mk_lib_crypto_alg_aes_192_key_len_m; ++i){ keys[get_outer(i)].m_data.m_uchars[get_inner(i)] = key->m_data.m_uchars[i]; }
	for(i = mk_lib_crypto_alg_aes_192_key_words; i != (mk_lib_crypto_alg_aes_192_nr + 1) * mk_lib_crypto_alg_aes_192_msg_words; ++i)
	{
		idx_prev = (i - 1) * mk_lib_crypto_alg_aes_192_word_bytes;
		for(j = 0; j != mk_lib_crypto_alg_aes_192_word_bytes; ++j){ tmp.m_data.m_uchars[j] = keys[get_outer(idx_prev + j)].m_data.m_uchars[get_inner(idx_prev + j)]; }
		if(i % mk_lib_crypto_alg_aes_192_key_words == 0)
		{
			mk_lib_crypto_alg_aes_192_rot_word(&tmp);
			mk_lib_crypto_alg_aes_192_sub_word(&tmp);
			mk_lib_crypto_alg_aes_192_xor_word(&tmp, &rcon);
		}
		else if(mk_lib_crypto_alg_aes_192_key_words > 6 && i % mk_lib_crypto_alg_aes_192_key_words == 4)
		{
			mk_lib_crypto_alg_aes_192_sub_word(&tmp);
		}
		idx_curr = i * mk_lib_crypto_alg_aes_192_word_bytes;
		idx_oldd = (i - mk_lib_crypto_alg_aes_192_key_words) * mk_lib_crypto_alg_aes_192_word_bytes;
		for(j = 0; j != mk_lib_crypto_alg_aes_192_word_bytes; ++j){ keys[get_outer(idx_curr + j)].m_data.m_uchars[get_inner(idx_curr + j)] = ((mk_lang_types_uchar_t)(tmp.m_data.m_uchars[j] ^ keys[get_outer(idx_oldd + j)].m_data.m_uchars[get_inner(idx_oldd + j)])); }
	}

	#undef get_outer
	#undef get_inner
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_c_encrypt(mk_lib_crypto_alg_aes_192_key_pct const key, mk_lib_crypto_alg_aes_192_msg_pct const input, mk_lib_crypto_alg_aes_192_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_192_msg_t state mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_192_msg_t keys[mk_lib_crypto_alg_aes_192_nr + 1] mk_lang_constexpr_init;
	int ir mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_lib_crypto_alg_aes_192_key_t) >= mk_lib_crypto_alg_aes_192_key_len_v);
	mk_lang_static_assert(sizeof(mk_lib_crypto_alg_aes_192_msg_t) == mk_lib_crypto_alg_aes_192_msg_len_v);

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	state = *input;
	mk_lib_crypto_alg_aes_192_generate_keys(key, keys);
	mk_lib_crypto_alg_aes_192_add_key(&state, &keys[0]);
	for(ir = 0; ir != mk_lib_crypto_alg_aes_192_nr - 1; ++ir)
	{
		mk_lib_crypto_alg_aes_192_sub_bytes(&state);
		mk_lib_crypto_alg_aes_192_shift_rows(&state);
		mk_lib_crypto_alg_aes_192_mix_columns(&state);
		mk_lib_crypto_alg_aes_192_add_key(&state, &keys[ir + 1]);
	}
	mk_lib_crypto_alg_aes_192_sub_bytes(&state);
	mk_lib_crypto_alg_aes_192_shift_rows(&state);
	mk_lib_crypto_alg_aes_192_add_key(&state, &keys[mk_lib_crypto_alg_aes_192_nr]);
	*output = state;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_192_c_decrypt(mk_lib_crypto_alg_aes_192_key_pct const key, mk_lib_crypto_alg_aes_192_msg_pct const input, mk_lib_crypto_alg_aes_192_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_192_msg_t state mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_192_msg_t keys[mk_lib_crypto_alg_aes_192_nr + 1] mk_lang_constexpr_init;
	int ir mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_lib_crypto_alg_aes_192_key_t) >= mk_lib_crypto_alg_aes_192_key_len_v);
	mk_lang_static_assert(sizeof(mk_lib_crypto_alg_aes_192_msg_t) == mk_lib_crypto_alg_aes_192_msg_len_v);

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	state = *input;
	mk_lib_crypto_alg_aes_192_generate_keys(key, keys);
	mk_lib_crypto_alg_aes_192_add_key(&state, &keys[mk_lib_crypto_alg_aes_192_nr]);
	for(ir = 0; ir != mk_lib_crypto_alg_aes_192_nr - 1; ++ir)
	{
		mk_lib_crypto_alg_aes_192_inv_shift_rows(&state);
		mk_lib_crypto_alg_aes_192_inv_sub_bytes(&state);
		mk_lib_crypto_alg_aes_192_add_key(&state, &keys[mk_lib_crypto_alg_aes_192_nr - (ir + 1)]);
		mk_lib_crypto_alg_aes_192_inv_mix_columns(&state);
	}
	mk_lib_crypto_alg_aes_192_inv_shift_rows(&state);
	mk_lib_crypto_alg_aes_192_inv_sub_bytes(&state);
	mk_lib_crypto_alg_aes_192_add_key(&state, &keys[0]);
	*output = state;
}


#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1))


#include <emmintrin.h> /* _mm_castpd_si128 _mm_castsi128_pd _mm_load_si128 _mm_loadu_si128 _mm_shuffle_epi32 _mm_slli_si128 _mm_store_si128 _mm_storeu_si128 _mm_xor_si128 */
#include <wmmintrin.h> /* _mm_aesdec_si128 _mm_aesdeclast_si128 _mm_aesenc_si128 _mm_aesenclast_si128 _mm_aesimc_si128 _mm_aeskeygenassist_si128 */


#if mk_lang_alignof_bi_ulllong_t >= 16
#define mk_lib_crypto_alg_aes_192_msvc_aes_ni_load_m128i(src) _mm_load_si128(((__m128i const*)(src)))
#define mk_lib_crypto_alg_aes_192_msvc_aes_ni_store_m128i(dst, src) _mm_store_si128(((__m128i*)(dst)), src)
#else
#define mk_lib_crypto_alg_aes_192_msvc_aes_ni_load_m128i(src) _mm_loadu_si128(((__m128i const*)(src)))
#define mk_lib_crypto_alg_aes_192_msvc_aes_ni_store_m128i(dst, src) _mm_storeu_si128(((__m128i*)(dst)), src)
#endif


union mk_lib_crypto_alg_aes_192_msvc_aes_ni_aligned_schedule_u
{
	__m128i m_keys[mk_lib_crypto_alg_aes_192_nr + 1];
	mk_lang_types_uchar_t m_uchars[(mk_lib_crypto_alg_aes_192_nr + 1) * mk_lib_crypto_alg_aes_192_msg_len_m];
};
typedef union mk_lib_crypto_alg_aes_192_msvc_aes_ni_aligned_schedule_u mk_lib_crypto_alg_aes_192_msvc_aes_ni_aligned_schedule_t;
typedef mk_lib_crypto_alg_aes_192_msvc_aes_ni_aligned_schedule_t const mk_lib_crypto_alg_aes_192_msvc_aes_ni_aligned_schedule_ct;
typedef mk_lib_crypto_alg_aes_192_msvc_aes_ni_aligned_schedule_t* mk_lib_crypto_alg_aes_192_msvc_aes_ni_aligned_schedule_pt;
typedef mk_lib_crypto_alg_aes_192_msvc_aes_ni_aligned_schedule_t const* mk_lib_crypto_alg_aes_192_msvc_aes_ni_aligned_schedule_pct;

struct mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_s
{
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_aligned_schedule_t m_data;
};
typedef struct mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_s mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_t;
typedef mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_t const mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_ct;
typedef mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_t* mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_pt;
typedef mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_t const* mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_pct;


static mk_lang_inline void mk_lib_crypto_alg_aes_192_msvc_aes_ni_key_assist(__m128i* const ta, __m128i* const tb, __m128i* const tc) mk_lang_noexcept
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

static mk_lang_inline void mk_lib_crypto_alg_aes_192_msvc_aes_ni_key_expand_enc(mk_lib_crypto_alg_aes_192_key_pct const key, mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_pt const schedule)
{
	__m128i ta;
	__m128i tb;
	__m128i tc;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	ta = mk_lib_crypto_alg_aes_192_msvc_aes_ni_load_m128i(&key->m_data.m_uchars[0]);
	tb = mk_lib_crypto_alg_aes_192_msvc_aes_ni_load_m128i(&key->m_data.m_uchars[16]);
	schedule->m_data.m_keys[0] = ta;
	schedule->m_data.m_keys[1] = tb;
	tc = _mm_aeskeygenassist_si128(tb, 0x01);
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_key_assist(&ta, &tc, &tb);
	schedule->m_data.m_keys[1] = _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(schedule->m_data.m_keys[1]), _mm_castsi128_pd(ta), 0));
	schedule->m_data.m_keys[2] = _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(ta), _mm_castsi128_pd(tb), 1));
	tc = _mm_aeskeygenassist_si128(tb, 0x02);
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_key_assist(&ta, &tc, &tb);
	schedule->m_data.m_keys[3] = ta;
	schedule->m_data.m_keys[4] = tb;
	tc = _mm_aeskeygenassist_si128(tb, 0x04);
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_key_assist(&ta, &tc, &tb);
	schedule->m_data.m_keys[4] = _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(schedule->m_data.m_keys[4]), _mm_castsi128_pd(ta), 0));
	schedule->m_data.m_keys[5] = _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(ta), _mm_castsi128_pd(tb), 1));
	tc = _mm_aeskeygenassist_si128(tb, 0x08);
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_key_assist(&ta, &tc, &tb);
	schedule->m_data.m_keys[6] = ta;
	schedule->m_data.m_keys[7] = tb;
	tc = _mm_aeskeygenassist_si128(tb, 0x10);
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_key_assist(&ta, &tc, &tb);
	schedule->m_data.m_keys[7] = _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(schedule->m_data.m_keys[7]), _mm_castsi128_pd(ta), 0));
	schedule->m_data.m_keys[8] = _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(ta), _mm_castsi128_pd(tb), 1));
	tc = _mm_aeskeygenassist_si128(tb, 0x20);
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_key_assist(&ta, &tc, &tb);
	schedule->m_data.m_keys[9] = ta;
	schedule->m_data.m_keys[10] = tb;
	tc = _mm_aeskeygenassist_si128(tb, 0x40);
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_key_assist(&ta, &tc, &tb);
	schedule->m_data.m_keys[10] = _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(schedule->m_data.m_keys[10]), _mm_castsi128_pd(ta), 0));
	schedule->m_data.m_keys[11] = _mm_castpd_si128(_mm_shuffle_pd(_mm_castsi128_pd(ta), _mm_castsi128_pd(tb), 1));
	tc = _mm_aeskeygenassist_si128(tb, 0x80);
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_key_assist(&ta, &tc, &tb);
	schedule->m_data.m_keys[12] = ta;
}

static mk_lang_inline void mk_lib_crypto_alg_aes_192_msvc_aes_ni_key_expand_dec(mk_lib_crypto_alg_aes_192_key_pct const key, mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_pt const schedule)
{
	mk_lang_assert(key);
	mk_lang_assert(schedule);

	mk_lib_crypto_alg_aes_192_msvc_aes_ni_key_expand_enc(key, schedule);
	schedule->m_data.m_keys[ 1] = _mm_aesimc_si128(schedule->m_data.m_keys[ 1]);
	schedule->m_data.m_keys[ 2] = _mm_aesimc_si128(schedule->m_data.m_keys[ 2]);
	schedule->m_data.m_keys[ 3] = _mm_aesimc_si128(schedule->m_data.m_keys[ 3]);
	schedule->m_data.m_keys[ 4] = _mm_aesimc_si128(schedule->m_data.m_keys[ 4]);
	schedule->m_data.m_keys[ 5] = _mm_aesimc_si128(schedule->m_data.m_keys[ 5]);
	schedule->m_data.m_keys[ 6] = _mm_aesimc_si128(schedule->m_data.m_keys[ 6]);
	schedule->m_data.m_keys[ 7] = _mm_aesimc_si128(schedule->m_data.m_keys[ 7]);
	schedule->m_data.m_keys[ 8] = _mm_aesimc_si128(schedule->m_data.m_keys[ 8]);
	schedule->m_data.m_keys[ 9] = _mm_aesimc_si128(schedule->m_data.m_keys[ 9]);
	schedule->m_data.m_keys[10] = _mm_aesimc_si128(schedule->m_data.m_keys[10]);
	schedule->m_data.m_keys[11] = _mm_aesimc_si128(schedule->m_data.m_keys[11]);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_192_msvc_aes_ni_encrypt_with_schedule(mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_pct const schedule, mk_lib_crypto_alg_aes_192_msg_pct const input, mk_lib_crypto_alg_aes_192_msg_pt const output) mk_lang_noexcept
{
	__m128i v;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	v = mk_lib_crypto_alg_aes_192_msvc_aes_ni_load_m128i(input);
	v = _mm_xor_si128(v, schedule->m_data.m_keys[0]);
	v = _mm_aesenc_si128(v, schedule->m_data.m_keys[ 1]);
	v = _mm_aesenc_si128(v, schedule->m_data.m_keys[ 2]);
	v = _mm_aesenc_si128(v, schedule->m_data.m_keys[ 3]);
	v = _mm_aesenc_si128(v, schedule->m_data.m_keys[ 4]);
	v = _mm_aesenc_si128(v, schedule->m_data.m_keys[ 5]);
	v = _mm_aesenc_si128(v, schedule->m_data.m_keys[ 6]);
	v = _mm_aesenc_si128(v, schedule->m_data.m_keys[ 7]);
	v = _mm_aesenc_si128(v, schedule->m_data.m_keys[ 8]);
	v = _mm_aesenc_si128(v, schedule->m_data.m_keys[ 9]);
	v = _mm_aesenc_si128(v, schedule->m_data.m_keys[10]);
	v = _mm_aesenc_si128(v, schedule->m_data.m_keys[11]);
	v = _mm_aesenclast_si128(v, schedule->m_data.m_keys[12]);
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_store_m128i(output, v);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_192_msvc_aes_ni_decrypt_with_schedule(mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_pct const schedule, mk_lib_crypto_alg_aes_192_msg_pct const input, mk_lib_crypto_alg_aes_192_msg_pt const output) mk_lang_noexcept
{
	__m128i v;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	v = mk_lib_crypto_alg_aes_192_msvc_aes_ni_load_m128i(input);
	v = _mm_xor_si128(v, schedule->m_data.m_keys[12]);
	v = _mm_aesdec_si128(v, schedule->m_data.m_keys[11]);
	v = _mm_aesdec_si128(v, schedule->m_data.m_keys[10]);
	v = _mm_aesdec_si128(v, schedule->m_data.m_keys[ 9]);
	v = _mm_aesdec_si128(v, schedule->m_data.m_keys[ 8]);
	v = _mm_aesdec_si128(v, schedule->m_data.m_keys[ 7]);
	v = _mm_aesdec_si128(v, schedule->m_data.m_keys[ 6]);
	v = _mm_aesdec_si128(v, schedule->m_data.m_keys[ 5]);
	v = _mm_aesdec_si128(v, schedule->m_data.m_keys[ 4]);
	v = _mm_aesdec_si128(v, schedule->m_data.m_keys[ 3]);
	v = _mm_aesdec_si128(v, schedule->m_data.m_keys[ 2]);
	v = _mm_aesdec_si128(v, schedule->m_data.m_keys[ 1]);
	v = _mm_aesdeclast_si128(v, schedule->m_data.m_keys[0]);
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_store_m128i(output, v);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_192_msvc_aes_ni_encrypt(mk_lib_crypto_alg_aes_192_key_pct const key, mk_lib_crypto_alg_aes_192_msg_pct const input, mk_lib_crypto_alg_aes_192_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_t schedule;

	mk_lib_crypto_alg_aes_192_msvc_aes_ni_key_expand_enc(key, &schedule);
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_encrypt_with_schedule(&schedule, input, output);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_192_msvc_aes_ni_decrypt(mk_lib_crypto_alg_aes_192_key_pct const key, mk_lib_crypto_alg_aes_192_msg_pct const input, mk_lib_crypto_alg_aes_192_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_schedule_t schedule;

	mk_lib_crypto_alg_aes_192_msvc_aes_ni_key_expand_dec(key, &schedule);
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_decrypt_with_schedule(&schedule, input, output);
}


#endif


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_192_portable_encrypt(mk_lib_crypto_alg_aes_192_key_pct const key, mk_lib_crypto_alg_aes_192_msg_pct const input, mk_lib_crypto_alg_aes_192_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_192_c_encrypt(key, input, output);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_192_portable_decrypt(mk_lib_crypto_alg_aes_192_key_pct const key, mk_lib_crypto_alg_aes_192_msg_pct const input, mk_lib_crypto_alg_aes_192_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_192_c_decrypt(key, input, output);
}


mk_lang_jumbo void mk_lib_crypto_alg_aes_192_accelerated_encrypt(mk_lib_crypto_alg_aes_192_key_pct const key, mk_lib_crypto_alg_aes_192_msg_pct const input, mk_lib_crypto_alg_aes_192_msg_pt const output) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1))
	mk_lang_assert(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni());
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_encrypt(key, input, output);
	#else
	((void)(key));
	((void)(input));
	((void)(output));
	mk_lang_crash();
	#endif
}

mk_lang_jumbo void mk_lib_crypto_alg_aes_192_accelerated_decrypt(mk_lib_crypto_alg_aes_192_key_pct const key, mk_lib_crypto_alg_aes_192_msg_pct const input, mk_lib_crypto_alg_aes_192_msg_pt const output) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1))
	mk_lang_assert(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni());
	mk_lib_crypto_alg_aes_192_msvc_aes_ni_decrypt(key, input, output);
	#else
	((void)(key));
	((void)(input));
	((void)(output));
	mk_lang_crash();
	#endif
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_192_encrypt(mk_lib_crypto_alg_aes_192_key_pct const key, mk_lib_crypto_alg_aes_192_msg_pct const input, mk_lib_crypto_alg_aes_192_msg_pt const output) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1))
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#endif
	{
		mk_lib_crypto_alg_aes_192_accelerated_encrypt(key, input, output);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_aes_192_portable_encrypt(key, input, output);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_192_decrypt(mk_lib_crypto_alg_aes_192_key_pct const key, mk_lib_crypto_alg_aes_192_msg_pct const input, mk_lib_crypto_alg_aes_192_msg_pt const output) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1))
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#endif
	{
		mk_lib_crypto_alg_aes_192_accelerated_decrypt(key, input, output);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_aes_192_portable_decrypt(key, input, output);
	}
}
