#include "mk_lib_crypto_alg_aes_256.h"

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


/* NIST FIPS PUB 197 */


#define mk_lib_crypto_alg_aes_256_nr 14
#define mk_lib_crypto_alg_aes_256_sbox_len 0x0100
#define mk_lib_crypto_alg_aes_256_key_bits 256
#define mk_lib_crypto_alg_aes_256_msg_bits 128
#define mk_lib_crypto_alg_aes_256_word_bits 32
#define mk_lib_crypto_alg_aes_256_byte_bits 8
#define mk_lib_crypto_alg_aes_256_word_bytes (mk_lib_crypto_alg_aes_256_word_bits  / mk_lib_crypto_alg_aes_256_byte_bits)
#define mk_lib_crypto_alg_aes_256_key_words (mk_lib_crypto_alg_aes_256_key_bits / mk_lib_crypto_alg_aes_256_word_bits)
#define mk_lib_crypto_alg_aes_256_msg_words (mk_lib_crypto_alg_aes_256_msg_bits / mk_lib_crypto_alg_aes_256_word_bits)


union mk_lib_crypto_alg_aes_256_aligned_sbox_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_aes_256_sbox_len];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_aes_256_aligned_sbox_u mk_lib_crypto_alg_aes_256_aligned_sbox_t;
typedef mk_lib_crypto_alg_aes_256_aligned_sbox_t const mk_lib_crypto_alg_aes_256_aligned_sbox_ct;
typedef mk_lib_crypto_alg_aes_256_aligned_sbox_t* mk_lib_crypto_alg_aes_256_aligned_sbox_pt;
typedef mk_lib_crypto_alg_aes_256_aligned_sbox_t const* mk_lib_crypto_alg_aes_256_aligned_sbox_pct;

union mk_lib_crypto_alg_aes_256_aligned_word_u
{
	mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_aes_256_word_bytes];
	mk_lang_types_ulong_t m_align;
};
typedef union mk_lib_crypto_alg_aes_256_aligned_word_u mk_lib_crypto_alg_aes_256_aligned_word_t;
typedef mk_lib_crypto_alg_aes_256_aligned_word_t const mk_lib_crypto_alg_aes_256_aligned_word_ct;
typedef mk_lib_crypto_alg_aes_256_aligned_word_t* mk_lib_crypto_alg_aes_256_aligned_word_pt;
typedef mk_lib_crypto_alg_aes_256_aligned_word_t const* mk_lib_crypto_alg_aes_256_aligned_word_pct;

struct mk_lib_crypto_alg_aes_256_sbox_s
{
	mk_lib_crypto_alg_aes_256_aligned_sbox_t m_data;
};
typedef struct mk_lib_crypto_alg_aes_256_sbox_s mk_lib_crypto_alg_aes_256_sbox_t;
typedef mk_lib_crypto_alg_aes_256_sbox_t const mk_lib_crypto_alg_aes_256_sbox_ct;
typedef mk_lib_crypto_alg_aes_256_sbox_t* mk_lib_crypto_alg_aes_256_sbox_pt;
typedef mk_lib_crypto_alg_aes_256_sbox_t const* mk_lib_crypto_alg_aes_256_sbox_pct;

struct mk_lib_crypto_alg_aes_256_word_s
{
	mk_lib_crypto_alg_aes_256_aligned_word_t m_data;
};
typedef struct mk_lib_crypto_alg_aes_256_word_s mk_lib_crypto_alg_aes_256_word_t;
typedef mk_lib_crypto_alg_aes_256_word_t const mk_lib_crypto_alg_aes_256_word_ct;
typedef mk_lib_crypto_alg_aes_256_word_t* mk_lib_crypto_alg_aes_256_word_pt;
typedef mk_lib_crypto_alg_aes_256_word_t const* mk_lib_crypto_alg_aes_256_word_pct;


mk_lang_constexpr_static_inline mk_lib_crypto_alg_aes_256_sbox_t const s_mk_lib_crypto_alg_aes_256_sbox =
{{{
	mk_sl_cui_uint8_c(0x63), mk_sl_cui_uint8_c(0x7c), mk_sl_cui_uint8_c(0x77), mk_sl_cui_uint8_c(0x7b), mk_sl_cui_uint8_c(0xf2), mk_sl_cui_uint8_c(0x6b), mk_sl_cui_uint8_c(0x6f), mk_sl_cui_uint8_c(0xc5), mk_sl_cui_uint8_c(0x30), mk_sl_cui_uint8_c(0x01), mk_sl_cui_uint8_c(0x67), mk_sl_cui_uint8_c(0x2b), mk_sl_cui_uint8_c(0xfe), mk_sl_cui_uint8_c(0xd7), mk_sl_cui_uint8_c(0xab), mk_sl_cui_uint8_c(0x76),
	mk_sl_cui_uint8_c(0xca), mk_sl_cui_uint8_c(0x82), mk_sl_cui_uint8_c(0xc9), mk_sl_cui_uint8_c(0x7d), mk_sl_cui_uint8_c(0xfa), mk_sl_cui_uint8_c(0x59), mk_sl_cui_uint8_c(0x47), mk_sl_cui_uint8_c(0xf0), mk_sl_cui_uint8_c(0xad), mk_sl_cui_uint8_c(0xd4), mk_sl_cui_uint8_c(0xa2), mk_sl_cui_uint8_c(0xaf), mk_sl_cui_uint8_c(0x9c), mk_sl_cui_uint8_c(0xa4), mk_sl_cui_uint8_c(0x72), mk_sl_cui_uint8_c(0xc0),
	mk_sl_cui_uint8_c(0xb7), mk_sl_cui_uint8_c(0xfd), mk_sl_cui_uint8_c(0x93), mk_sl_cui_uint8_c(0x26), mk_sl_cui_uint8_c(0x36), mk_sl_cui_uint8_c(0x3f), mk_sl_cui_uint8_c(0xf7), mk_sl_cui_uint8_c(0xcc), mk_sl_cui_uint8_c(0x34), mk_sl_cui_uint8_c(0xa5), mk_sl_cui_uint8_c(0xe5), mk_sl_cui_uint8_c(0xf1), mk_sl_cui_uint8_c(0x71), mk_sl_cui_uint8_c(0xd8), mk_sl_cui_uint8_c(0x31), mk_sl_cui_uint8_c(0x15),
	mk_sl_cui_uint8_c(0x04), mk_sl_cui_uint8_c(0xc7), mk_sl_cui_uint8_c(0x23), mk_sl_cui_uint8_c(0xc3), mk_sl_cui_uint8_c(0x18), mk_sl_cui_uint8_c(0x96), mk_sl_cui_uint8_c(0x05), mk_sl_cui_uint8_c(0x9a), mk_sl_cui_uint8_c(0x07), mk_sl_cui_uint8_c(0x12), mk_sl_cui_uint8_c(0x80), mk_sl_cui_uint8_c(0xe2), mk_sl_cui_uint8_c(0xeb), mk_sl_cui_uint8_c(0x27), mk_sl_cui_uint8_c(0xb2), mk_sl_cui_uint8_c(0x75),
	mk_sl_cui_uint8_c(0x09), mk_sl_cui_uint8_c(0x83), mk_sl_cui_uint8_c(0x2c), mk_sl_cui_uint8_c(0x1a), mk_sl_cui_uint8_c(0x1b), mk_sl_cui_uint8_c(0x6e), mk_sl_cui_uint8_c(0x5a), mk_sl_cui_uint8_c(0xa0), mk_sl_cui_uint8_c(0x52), mk_sl_cui_uint8_c(0x3b), mk_sl_cui_uint8_c(0xd6), mk_sl_cui_uint8_c(0xb3), mk_sl_cui_uint8_c(0x29), mk_sl_cui_uint8_c(0xe3), mk_sl_cui_uint8_c(0x2f), mk_sl_cui_uint8_c(0x84),
	mk_sl_cui_uint8_c(0x53), mk_sl_cui_uint8_c(0xd1), mk_sl_cui_uint8_c(0x00), mk_sl_cui_uint8_c(0xed), mk_sl_cui_uint8_c(0x20), mk_sl_cui_uint8_c(0xfc), mk_sl_cui_uint8_c(0xb1), mk_sl_cui_uint8_c(0x5b), mk_sl_cui_uint8_c(0x6a), mk_sl_cui_uint8_c(0xcb), mk_sl_cui_uint8_c(0xbe), mk_sl_cui_uint8_c(0x39), mk_sl_cui_uint8_c(0x4a), mk_sl_cui_uint8_c(0x4c), mk_sl_cui_uint8_c(0x58), mk_sl_cui_uint8_c(0xcf),
	mk_sl_cui_uint8_c(0xd0), mk_sl_cui_uint8_c(0xef), mk_sl_cui_uint8_c(0xaa), mk_sl_cui_uint8_c(0xfb), mk_sl_cui_uint8_c(0x43), mk_sl_cui_uint8_c(0x4d), mk_sl_cui_uint8_c(0x33), mk_sl_cui_uint8_c(0x85), mk_sl_cui_uint8_c(0x45), mk_sl_cui_uint8_c(0xf9), mk_sl_cui_uint8_c(0x02), mk_sl_cui_uint8_c(0x7f), mk_sl_cui_uint8_c(0x50), mk_sl_cui_uint8_c(0x3c), mk_sl_cui_uint8_c(0x9f), mk_sl_cui_uint8_c(0xa8),
	mk_sl_cui_uint8_c(0x51), mk_sl_cui_uint8_c(0xa3), mk_sl_cui_uint8_c(0x40), mk_sl_cui_uint8_c(0x8f), mk_sl_cui_uint8_c(0x92), mk_sl_cui_uint8_c(0x9d), mk_sl_cui_uint8_c(0x38), mk_sl_cui_uint8_c(0xf5), mk_sl_cui_uint8_c(0xbc), mk_sl_cui_uint8_c(0xb6), mk_sl_cui_uint8_c(0xda), mk_sl_cui_uint8_c(0x21), mk_sl_cui_uint8_c(0x10), mk_sl_cui_uint8_c(0xff), mk_sl_cui_uint8_c(0xf3), mk_sl_cui_uint8_c(0xd2),
	mk_sl_cui_uint8_c(0xcd), mk_sl_cui_uint8_c(0x0c), mk_sl_cui_uint8_c(0x13), mk_sl_cui_uint8_c(0xec), mk_sl_cui_uint8_c(0x5f), mk_sl_cui_uint8_c(0x97), mk_sl_cui_uint8_c(0x44), mk_sl_cui_uint8_c(0x17), mk_sl_cui_uint8_c(0xc4), mk_sl_cui_uint8_c(0xa7), mk_sl_cui_uint8_c(0x7e), mk_sl_cui_uint8_c(0x3d), mk_sl_cui_uint8_c(0x64), mk_sl_cui_uint8_c(0x5d), mk_sl_cui_uint8_c(0x19), mk_sl_cui_uint8_c(0x73),
	mk_sl_cui_uint8_c(0x60), mk_sl_cui_uint8_c(0x81), mk_sl_cui_uint8_c(0x4f), mk_sl_cui_uint8_c(0xdc), mk_sl_cui_uint8_c(0x22), mk_sl_cui_uint8_c(0x2a), mk_sl_cui_uint8_c(0x90), mk_sl_cui_uint8_c(0x88), mk_sl_cui_uint8_c(0x46), mk_sl_cui_uint8_c(0xee), mk_sl_cui_uint8_c(0xb8), mk_sl_cui_uint8_c(0x14), mk_sl_cui_uint8_c(0xde), mk_sl_cui_uint8_c(0x5e), mk_sl_cui_uint8_c(0x0b), mk_sl_cui_uint8_c(0xdb),
	mk_sl_cui_uint8_c(0xe0), mk_sl_cui_uint8_c(0x32), mk_sl_cui_uint8_c(0x3a), mk_sl_cui_uint8_c(0x0a), mk_sl_cui_uint8_c(0x49), mk_sl_cui_uint8_c(0x06), mk_sl_cui_uint8_c(0x24), mk_sl_cui_uint8_c(0x5c), mk_sl_cui_uint8_c(0xc2), mk_sl_cui_uint8_c(0xd3), mk_sl_cui_uint8_c(0xac), mk_sl_cui_uint8_c(0x62), mk_sl_cui_uint8_c(0x91), mk_sl_cui_uint8_c(0x95), mk_sl_cui_uint8_c(0xe4), mk_sl_cui_uint8_c(0x79),
	mk_sl_cui_uint8_c(0xe7), mk_sl_cui_uint8_c(0xc8), mk_sl_cui_uint8_c(0x37), mk_sl_cui_uint8_c(0x6d), mk_sl_cui_uint8_c(0x8d), mk_sl_cui_uint8_c(0xd5), mk_sl_cui_uint8_c(0x4e), mk_sl_cui_uint8_c(0xa9), mk_sl_cui_uint8_c(0x6c), mk_sl_cui_uint8_c(0x56), mk_sl_cui_uint8_c(0xf4), mk_sl_cui_uint8_c(0xea), mk_sl_cui_uint8_c(0x65), mk_sl_cui_uint8_c(0x7a), mk_sl_cui_uint8_c(0xae), mk_sl_cui_uint8_c(0x08),
	mk_sl_cui_uint8_c(0xba), mk_sl_cui_uint8_c(0x78), mk_sl_cui_uint8_c(0x25), mk_sl_cui_uint8_c(0x2e), mk_sl_cui_uint8_c(0x1c), mk_sl_cui_uint8_c(0xa6), mk_sl_cui_uint8_c(0xb4), mk_sl_cui_uint8_c(0xc6), mk_sl_cui_uint8_c(0xe8), mk_sl_cui_uint8_c(0xdd), mk_sl_cui_uint8_c(0x74), mk_sl_cui_uint8_c(0x1f), mk_sl_cui_uint8_c(0x4b), mk_sl_cui_uint8_c(0xbd), mk_sl_cui_uint8_c(0x8b), mk_sl_cui_uint8_c(0x8a),
	mk_sl_cui_uint8_c(0x70), mk_sl_cui_uint8_c(0x3e), mk_sl_cui_uint8_c(0xb5), mk_sl_cui_uint8_c(0x66), mk_sl_cui_uint8_c(0x48), mk_sl_cui_uint8_c(0x03), mk_sl_cui_uint8_c(0xf6), mk_sl_cui_uint8_c(0x0e), mk_sl_cui_uint8_c(0x61), mk_sl_cui_uint8_c(0x35), mk_sl_cui_uint8_c(0x57), mk_sl_cui_uint8_c(0xb9), mk_sl_cui_uint8_c(0x86), mk_sl_cui_uint8_c(0xc1), mk_sl_cui_uint8_c(0x1d), mk_sl_cui_uint8_c(0x9e),
	mk_sl_cui_uint8_c(0xe1), mk_sl_cui_uint8_c(0xf8), mk_sl_cui_uint8_c(0x98), mk_sl_cui_uint8_c(0x11), mk_sl_cui_uint8_c(0x69), mk_sl_cui_uint8_c(0xd9), mk_sl_cui_uint8_c(0x8e), mk_sl_cui_uint8_c(0x94), mk_sl_cui_uint8_c(0x9b), mk_sl_cui_uint8_c(0x1e), mk_sl_cui_uint8_c(0x87), mk_sl_cui_uint8_c(0xe9), mk_sl_cui_uint8_c(0xce), mk_sl_cui_uint8_c(0x55), mk_sl_cui_uint8_c(0x28), mk_sl_cui_uint8_c(0xdf),
	mk_sl_cui_uint8_c(0x8c), mk_sl_cui_uint8_c(0xa1), mk_sl_cui_uint8_c(0x89), mk_sl_cui_uint8_c(0x0d), mk_sl_cui_uint8_c(0xbf), mk_sl_cui_uint8_c(0xe6), mk_sl_cui_uint8_c(0x42), mk_sl_cui_uint8_c(0x68), mk_sl_cui_uint8_c(0x41), mk_sl_cui_uint8_c(0x99), mk_sl_cui_uint8_c(0x2d), mk_sl_cui_uint8_c(0x0f), mk_sl_cui_uint8_c(0xb0), mk_sl_cui_uint8_c(0x54), mk_sl_cui_uint8_c(0xbb), mk_sl_cui_uint8_c(0x16),
}}};

mk_lang_constexpr_static_inline mk_lib_crypto_alg_aes_256_sbox_t const s_mk_lib_crypto_alg_aes_256_inv_sbox =
{{{
	mk_sl_cui_uint8_c(0x52), mk_sl_cui_uint8_c(0x09), mk_sl_cui_uint8_c(0x6a), mk_sl_cui_uint8_c(0xd5), mk_sl_cui_uint8_c(0x30), mk_sl_cui_uint8_c(0x36), mk_sl_cui_uint8_c(0xa5), mk_sl_cui_uint8_c(0x38), mk_sl_cui_uint8_c(0xbf), mk_sl_cui_uint8_c(0x40), mk_sl_cui_uint8_c(0xa3), mk_sl_cui_uint8_c(0x9e), mk_sl_cui_uint8_c(0x81), mk_sl_cui_uint8_c(0xf3), mk_sl_cui_uint8_c(0xd7), mk_sl_cui_uint8_c(0xfb),
	mk_sl_cui_uint8_c(0x7c), mk_sl_cui_uint8_c(0xe3), mk_sl_cui_uint8_c(0x39), mk_sl_cui_uint8_c(0x82), mk_sl_cui_uint8_c(0x9b), mk_sl_cui_uint8_c(0x2f), mk_sl_cui_uint8_c(0xff), mk_sl_cui_uint8_c(0x87), mk_sl_cui_uint8_c(0x34), mk_sl_cui_uint8_c(0x8e), mk_sl_cui_uint8_c(0x43), mk_sl_cui_uint8_c(0x44), mk_sl_cui_uint8_c(0xc4), mk_sl_cui_uint8_c(0xde), mk_sl_cui_uint8_c(0xe9), mk_sl_cui_uint8_c(0xcb),
	mk_sl_cui_uint8_c(0x54), mk_sl_cui_uint8_c(0x7b), mk_sl_cui_uint8_c(0x94), mk_sl_cui_uint8_c(0x32), mk_sl_cui_uint8_c(0xa6), mk_sl_cui_uint8_c(0xc2), mk_sl_cui_uint8_c(0x23), mk_sl_cui_uint8_c(0x3d), mk_sl_cui_uint8_c(0xee), mk_sl_cui_uint8_c(0x4c), mk_sl_cui_uint8_c(0x95), mk_sl_cui_uint8_c(0x0b), mk_sl_cui_uint8_c(0x42), mk_sl_cui_uint8_c(0xfa), mk_sl_cui_uint8_c(0xc3), mk_sl_cui_uint8_c(0x4e),
	mk_sl_cui_uint8_c(0x08), mk_sl_cui_uint8_c(0x2e), mk_sl_cui_uint8_c(0xa1), mk_sl_cui_uint8_c(0x66), mk_sl_cui_uint8_c(0x28), mk_sl_cui_uint8_c(0xd9), mk_sl_cui_uint8_c(0x24), mk_sl_cui_uint8_c(0xb2), mk_sl_cui_uint8_c(0x76), mk_sl_cui_uint8_c(0x5b), mk_sl_cui_uint8_c(0xa2), mk_sl_cui_uint8_c(0x49), mk_sl_cui_uint8_c(0x6d), mk_sl_cui_uint8_c(0x8b), mk_sl_cui_uint8_c(0xd1), mk_sl_cui_uint8_c(0x25),
	mk_sl_cui_uint8_c(0x72), mk_sl_cui_uint8_c(0xf8), mk_sl_cui_uint8_c(0xf6), mk_sl_cui_uint8_c(0x64), mk_sl_cui_uint8_c(0x86), mk_sl_cui_uint8_c(0x68), mk_sl_cui_uint8_c(0x98), mk_sl_cui_uint8_c(0x16), mk_sl_cui_uint8_c(0xd4), mk_sl_cui_uint8_c(0xa4), mk_sl_cui_uint8_c(0x5c), mk_sl_cui_uint8_c(0xcc), mk_sl_cui_uint8_c(0x5d), mk_sl_cui_uint8_c(0x65), mk_sl_cui_uint8_c(0xb6), mk_sl_cui_uint8_c(0x92),
	mk_sl_cui_uint8_c(0x6c), mk_sl_cui_uint8_c(0x70), mk_sl_cui_uint8_c(0x48), mk_sl_cui_uint8_c(0x50), mk_sl_cui_uint8_c(0xfd), mk_sl_cui_uint8_c(0xed), mk_sl_cui_uint8_c(0xb9), mk_sl_cui_uint8_c(0xda), mk_sl_cui_uint8_c(0x5e), mk_sl_cui_uint8_c(0x15), mk_sl_cui_uint8_c(0x46), mk_sl_cui_uint8_c(0x57), mk_sl_cui_uint8_c(0xa7), mk_sl_cui_uint8_c(0x8d), mk_sl_cui_uint8_c(0x9d), mk_sl_cui_uint8_c(0x84),
	mk_sl_cui_uint8_c(0x90), mk_sl_cui_uint8_c(0xd8), mk_sl_cui_uint8_c(0xab), mk_sl_cui_uint8_c(0x00), mk_sl_cui_uint8_c(0x8c), mk_sl_cui_uint8_c(0xbc), mk_sl_cui_uint8_c(0xd3), mk_sl_cui_uint8_c(0x0a), mk_sl_cui_uint8_c(0xf7), mk_sl_cui_uint8_c(0xe4), mk_sl_cui_uint8_c(0x58), mk_sl_cui_uint8_c(0x05), mk_sl_cui_uint8_c(0xb8), mk_sl_cui_uint8_c(0xb3), mk_sl_cui_uint8_c(0x45), mk_sl_cui_uint8_c(0x06),
	mk_sl_cui_uint8_c(0xd0), mk_sl_cui_uint8_c(0x2c), mk_sl_cui_uint8_c(0x1e), mk_sl_cui_uint8_c(0x8f), mk_sl_cui_uint8_c(0xca), mk_sl_cui_uint8_c(0x3f), mk_sl_cui_uint8_c(0x0f), mk_sl_cui_uint8_c(0x02), mk_sl_cui_uint8_c(0xc1), mk_sl_cui_uint8_c(0xaf), mk_sl_cui_uint8_c(0xbd), mk_sl_cui_uint8_c(0x03), mk_sl_cui_uint8_c(0x01), mk_sl_cui_uint8_c(0x13), mk_sl_cui_uint8_c(0x8a), mk_sl_cui_uint8_c(0x6b),
	mk_sl_cui_uint8_c(0x3a), mk_sl_cui_uint8_c(0x91), mk_sl_cui_uint8_c(0x11), mk_sl_cui_uint8_c(0x41), mk_sl_cui_uint8_c(0x4f), mk_sl_cui_uint8_c(0x67), mk_sl_cui_uint8_c(0xdc), mk_sl_cui_uint8_c(0xea), mk_sl_cui_uint8_c(0x97), mk_sl_cui_uint8_c(0xf2), mk_sl_cui_uint8_c(0xcf), mk_sl_cui_uint8_c(0xce), mk_sl_cui_uint8_c(0xf0), mk_sl_cui_uint8_c(0xb4), mk_sl_cui_uint8_c(0xe6), mk_sl_cui_uint8_c(0x73),
	mk_sl_cui_uint8_c(0x96), mk_sl_cui_uint8_c(0xac), mk_sl_cui_uint8_c(0x74), mk_sl_cui_uint8_c(0x22), mk_sl_cui_uint8_c(0xe7), mk_sl_cui_uint8_c(0xad), mk_sl_cui_uint8_c(0x35), mk_sl_cui_uint8_c(0x85), mk_sl_cui_uint8_c(0xe2), mk_sl_cui_uint8_c(0xf9), mk_sl_cui_uint8_c(0x37), mk_sl_cui_uint8_c(0xe8), mk_sl_cui_uint8_c(0x1c), mk_sl_cui_uint8_c(0x75), mk_sl_cui_uint8_c(0xdf), mk_sl_cui_uint8_c(0x6e),
	mk_sl_cui_uint8_c(0x47), mk_sl_cui_uint8_c(0xf1), mk_sl_cui_uint8_c(0x1a), mk_sl_cui_uint8_c(0x71), mk_sl_cui_uint8_c(0x1d), mk_sl_cui_uint8_c(0x29), mk_sl_cui_uint8_c(0xc5), mk_sl_cui_uint8_c(0x89), mk_sl_cui_uint8_c(0x6f), mk_sl_cui_uint8_c(0xb7), mk_sl_cui_uint8_c(0x62), mk_sl_cui_uint8_c(0x0e), mk_sl_cui_uint8_c(0xaa), mk_sl_cui_uint8_c(0x18), mk_sl_cui_uint8_c(0xbe), mk_sl_cui_uint8_c(0x1b),
	mk_sl_cui_uint8_c(0xfc), mk_sl_cui_uint8_c(0x56), mk_sl_cui_uint8_c(0x3e), mk_sl_cui_uint8_c(0x4b), mk_sl_cui_uint8_c(0xc6), mk_sl_cui_uint8_c(0xd2), mk_sl_cui_uint8_c(0x79), mk_sl_cui_uint8_c(0x20), mk_sl_cui_uint8_c(0x9a), mk_sl_cui_uint8_c(0xdb), mk_sl_cui_uint8_c(0xc0), mk_sl_cui_uint8_c(0xfe), mk_sl_cui_uint8_c(0x78), mk_sl_cui_uint8_c(0xcd), mk_sl_cui_uint8_c(0x5a), mk_sl_cui_uint8_c(0xf4),
	mk_sl_cui_uint8_c(0x1f), mk_sl_cui_uint8_c(0xdd), mk_sl_cui_uint8_c(0xa8), mk_sl_cui_uint8_c(0x33), mk_sl_cui_uint8_c(0x88), mk_sl_cui_uint8_c(0x07), mk_sl_cui_uint8_c(0xc7), mk_sl_cui_uint8_c(0x31), mk_sl_cui_uint8_c(0xb1), mk_sl_cui_uint8_c(0x12), mk_sl_cui_uint8_c(0x10), mk_sl_cui_uint8_c(0x59), mk_sl_cui_uint8_c(0x27), mk_sl_cui_uint8_c(0x80), mk_sl_cui_uint8_c(0xec), mk_sl_cui_uint8_c(0x5f),
	mk_sl_cui_uint8_c(0x60), mk_sl_cui_uint8_c(0x51), mk_sl_cui_uint8_c(0x7f), mk_sl_cui_uint8_c(0xa9), mk_sl_cui_uint8_c(0x19), mk_sl_cui_uint8_c(0xb5), mk_sl_cui_uint8_c(0x4a), mk_sl_cui_uint8_c(0x0d), mk_sl_cui_uint8_c(0x2d), mk_sl_cui_uint8_c(0xe5), mk_sl_cui_uint8_c(0x7a), mk_sl_cui_uint8_c(0x9f), mk_sl_cui_uint8_c(0x93), mk_sl_cui_uint8_c(0xc9), mk_sl_cui_uint8_c(0x9c), mk_sl_cui_uint8_c(0xef),
	mk_sl_cui_uint8_c(0xa0), mk_sl_cui_uint8_c(0xe0), mk_sl_cui_uint8_c(0x3b), mk_sl_cui_uint8_c(0x4d), mk_sl_cui_uint8_c(0xae), mk_sl_cui_uint8_c(0x2a), mk_sl_cui_uint8_c(0xf5), mk_sl_cui_uint8_c(0xb0), mk_sl_cui_uint8_c(0xc8), mk_sl_cui_uint8_c(0xeb), mk_sl_cui_uint8_c(0xbb), mk_sl_cui_uint8_c(0x3c), mk_sl_cui_uint8_c(0x83), mk_sl_cui_uint8_c(0x53), mk_sl_cui_uint8_c(0x99), mk_sl_cui_uint8_c(0x61),
	mk_sl_cui_uint8_c(0x17), mk_sl_cui_uint8_c(0x2b), mk_sl_cui_uint8_c(0x04), mk_sl_cui_uint8_c(0x7e), mk_sl_cui_uint8_c(0xba), mk_sl_cui_uint8_c(0x77), mk_sl_cui_uint8_c(0xd6), mk_sl_cui_uint8_c(0x26), mk_sl_cui_uint8_c(0xe1), mk_sl_cui_uint8_c(0x69), mk_sl_cui_uint8_c(0x14), mk_sl_cui_uint8_c(0x63), mk_sl_cui_uint8_c(0x55), mk_sl_cui_uint8_c(0x21), mk_sl_cui_uint8_c(0x0c), mk_sl_cui_uint8_c(0x7d),
}}};


mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_sub_byte(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint8_to_bi_uchar(a, &uc);
	*b = s_mk_lib_crypto_alg_aes_256_sbox.m_data.m_uint8s[uc];
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_inv_sub_byte(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint8_to_bi_uchar(a, &uc);
	*b = s_mk_lib_crypto_alg_aes_256_inv_sbox.m_data.m_uint8s[uc];
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_sub_bytes(mk_lib_crypto_alg_aes_256_msg_pct const a, mk_lib_crypto_alg_aes_256_msg_pt const b) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i)
	{
		mk_lib_crypto_alg_aes_256_sub_byte(&a->m_data.m_uint8s[i], &b->m_data.m_uint8s[i]);
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_inv_sub_bytes(mk_lib_crypto_alg_aes_256_msg_pct const a, mk_lib_crypto_alg_aes_256_msg_pt const b) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i)
	{
		mk_lib_crypto_alg_aes_256_inv_sub_byte(&a->m_data.m_uint8s[i], &b->m_data.m_uint8s[i]);
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_shift_rows(mk_lib_crypto_alg_aes_256_msg_pct const a, mk_lib_crypto_alg_aes_256_msg_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = a->m_data.m_uint8s[0 * 4 + 1];
	b->m_data.m_uint8s[0 * 4 + 1] = a->m_data.m_uint8s[1 * 4 + 1];
	b->m_data.m_uint8s[1 * 4 + 1] = a->m_data.m_uint8s[2 * 4 + 1];
	b->m_data.m_uint8s[2 * 4 + 1] = a->m_data.m_uint8s[3 * 4 + 1];
	b->m_data.m_uint8s[3 * 4 + 1] = ta;

	ta = a->m_data.m_uint8s[0 * 4 + 2];
	tb = a->m_data.m_uint8s[1 * 4 + 2];
	b->m_data.m_uint8s[0 * 4 + 2] = a->m_data.m_uint8s[2 * 4 + 2];
	b->m_data.m_uint8s[1 * 4 + 2] = a->m_data.m_uint8s[3 * 4 + 2];
	b->m_data.m_uint8s[2 * 4 + 2] = ta;
	b->m_data.m_uint8s[3 * 4 + 2] = tb;

	ta = a->m_data.m_uint8s[1 * 4 + 3];
	b->m_data.m_uint8s[1 * 4 + 3] = a->m_data.m_uint8s[0 * 4 + 3];
	b->m_data.m_uint8s[0 * 4 + 3] = a->m_data.m_uint8s[3 * 4 + 3];
	b->m_data.m_uint8s[3 * 4 + 3] = a->m_data.m_uint8s[2 * 4 + 3];
	b->m_data.m_uint8s[2 * 4 + 3] = ta;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_inv_shift_rows(mk_lib_crypto_alg_aes_256_msg_pct const a, mk_lib_crypto_alg_aes_256_msg_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = a->m_data.m_uint8s[1 * 4 + 1];
	b->m_data.m_uint8s[1 * 4 + 1] = a->m_data.m_uint8s[0 * 4 + 1];
	b->m_data.m_uint8s[0 * 4 + 1] = a->m_data.m_uint8s[3 * 4 + 1];
	b->m_data.m_uint8s[3 * 4 + 1] = a->m_data.m_uint8s[2 * 4 + 1];
	b->m_data.m_uint8s[2 * 4 + 1] = ta;

	ta = a->m_data.m_uint8s[0 * 4 + 2];
	tb = a->m_data.m_uint8s[1 * 4 + 2];
	b->m_data.m_uint8s[0 * 4 + 2] = a->m_data.m_uint8s[2 * 4 + 2];
	b->m_data.m_uint8s[1 * 4 + 2] = a->m_data.m_uint8s[3 * 4 + 2];
	b->m_data.m_uint8s[2 * 4 + 2] = ta;
	b->m_data.m_uint8s[3 * 4 + 2] = tb;

	ta = a->m_data.m_uint8s[0 * 4 + 3];
	b->m_data.m_uint8s[0 * 4 + 3] = a->m_data.m_uint8s[1 * 4 + 3];
	b->m_data.m_uint8s[1 * 4 + 3] = a->m_data.m_uint8s[2 * 4 + 3];
	b->m_data.m_uint8s[2 * 4 + 3] = a->m_data.m_uint8s[3 * 4 + 3];
	b->m_data.m_uint8s[3 * 4 + 3] = ta;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_mul_1(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = *a;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_mul_2(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_lang_types_uchar_t const s_cnt = 0x1b;

	mk_sl_cui_uint8_t n mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = *a;
	mk_sl_cui_uint8_shl3(&n, 1, &ta);
	mk_sl_cui_uint8_shr3(&n, 7, &tb);
	mk_sl_cui_uint8_set_one(&tc);
	mk_sl_cui_uint8_and2(&tb, &tc);
	mk_sl_cui_uint8_from_bi_uchar(&tc, &s_cnt);
	mk_sl_cui_uint8_mul2_wrap_lo(&tb, &tc);
	mk_sl_cui_uint8_xor3(&ta, &tb, &n);
	*b = n;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_mul_3(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = *a;
	tb = *a;
	mk_lib_crypto_alg_aes_256_mul_2(&ta, &ta);
	mk_lib_crypto_alg_aes_256_mul_1(&tb, &tb);
	mk_sl_cui_uint8_xor2(&ta, &tb);
	*b = ta;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_mul_4(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = *a;
	mk_lib_crypto_alg_aes_256_mul_2(&ta, &ta);
	mk_lib_crypto_alg_aes_256_mul_2(&ta, &ta);
	*b = ta;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_mul_8(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = *a;
	mk_lib_crypto_alg_aes_256_mul_2(&ta, &ta);
	mk_lib_crypto_alg_aes_256_mul_2(&ta, &ta);
	mk_lib_crypto_alg_aes_256_mul_2(&ta, &ta);
	*b = ta;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_mul_9(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = *a;
	tb = *a;
	mk_lib_crypto_alg_aes_256_mul_8(&ta, &ta);
	mk_lib_crypto_alg_aes_256_mul_1(&tb, &tb);
	mk_sl_cui_uint8_xor2(&ta, &tb);
	*b = ta;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_mul_b(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = *a;
	tb = *a;
	tc = *a;
	mk_lib_crypto_alg_aes_256_mul_8(&ta, &ta);
	mk_lib_crypto_alg_aes_256_mul_2(&tb, &tb);
	mk_lib_crypto_alg_aes_256_mul_1(&tc, &tc);
	mk_sl_cui_uint8_xor2(&ta, &tb);
	mk_sl_cui_uint8_xor2(&ta, &tc);
	*b = ta;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_mul_d(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = *a;
	tb = *a;
	tc = *a;
	mk_lib_crypto_alg_aes_256_mul_8(&ta, &ta);
	mk_lib_crypto_alg_aes_256_mul_4(&tb, &tb);
	mk_lib_crypto_alg_aes_256_mul_1(&tc, &tc);
	mk_sl_cui_uint8_xor2(&ta, &tb);
	mk_sl_cui_uint8_xor2(&ta, &tc);
	*b = ta;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_mul_e(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = *a;
	tb = *a;
	tc = *a;
	mk_lib_crypto_alg_aes_256_mul_8(&ta, &ta);
	mk_lib_crypto_alg_aes_256_mul_4(&tb, &tb);
	mk_lib_crypto_alg_aes_256_mul_2(&tc, &tc);
	mk_sl_cui_uint8_xor2(&ta, &tb);
	mk_sl_cui_uint8_xor2(&ta, &tc);
	*b = ta;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_mix_columns(mk_lib_crypto_alg_aes_256_msg_pct const a, mk_lib_crypto_alg_aes_256_msg_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_256_msg_t orig mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t td mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	orig = *a;
	for(i = 0; i != 4; ++i)
	{
		mk_lib_crypto_alg_aes_256_mul_2(&orig.m_data.m_uint8s[i * 4 + 0], &ta);
		mk_lib_crypto_alg_aes_256_mul_3(&orig.m_data.m_uint8s[i * 4 + 1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_256_mul_1(&orig.m_data.m_uint8s[i * 4 + 2], &ta);
		mk_lib_crypto_alg_aes_256_mul_1(&orig.m_data.m_uint8s[i * 4 + 3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 0]);
		mk_lib_crypto_alg_aes_256_mul_1(&orig.m_data.m_uint8s[i * 4 + 0], &ta);
		mk_lib_crypto_alg_aes_256_mul_2(&orig.m_data.m_uint8s[i * 4 + 1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_256_mul_3(&orig.m_data.m_uint8s[i * 4 + 2], &ta);
		mk_lib_crypto_alg_aes_256_mul_1(&orig.m_data.m_uint8s[i * 4 + 3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 1]);
		mk_lib_crypto_alg_aes_256_mul_1(&orig.m_data.m_uint8s[i * 4 + 0], &ta);
		mk_lib_crypto_alg_aes_256_mul_1(&orig.m_data.m_uint8s[i * 4 + 1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_256_mul_2(&orig.m_data.m_uint8s[i * 4 + 2], &ta);
		mk_lib_crypto_alg_aes_256_mul_3(&orig.m_data.m_uint8s[i * 4 + 3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 2]);
		mk_lib_crypto_alg_aes_256_mul_3(&orig.m_data.m_uint8s[i * 4 + 0], &ta);
		mk_lib_crypto_alg_aes_256_mul_1(&orig.m_data.m_uint8s[i * 4 + 1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_256_mul_1(&orig.m_data.m_uint8s[i * 4 + 2], &ta);
		mk_lib_crypto_alg_aes_256_mul_2(&orig.m_data.m_uint8s[i * 4 + 3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 3]);
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_inv_mix_columns(mk_lib_crypto_alg_aes_256_msg_pct const a, mk_lib_crypto_alg_aes_256_msg_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_256_msg_t orig mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t td mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	orig = *a;
	for(i = 0; i != 4; ++i)
	{
		mk_lib_crypto_alg_aes_256_mul_e(&orig.m_data.m_uint8s[i * 4 + 0], &ta);
		mk_lib_crypto_alg_aes_256_mul_b(&orig.m_data.m_uint8s[i * 4 + 1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_256_mul_d(&orig.m_data.m_uint8s[i * 4 + 2], &ta);
		mk_lib_crypto_alg_aes_256_mul_9(&orig.m_data.m_uint8s[i * 4 + 3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 0]);
		mk_lib_crypto_alg_aes_256_mul_9(&orig.m_data.m_uint8s[i * 4 + 0], &ta);
		mk_lib_crypto_alg_aes_256_mul_e(&orig.m_data.m_uint8s[i * 4 + 1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_256_mul_b(&orig.m_data.m_uint8s[i * 4 + 2], &ta);
		mk_lib_crypto_alg_aes_256_mul_d(&orig.m_data.m_uint8s[i * 4 + 3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 1]);
		mk_lib_crypto_alg_aes_256_mul_d(&orig.m_data.m_uint8s[i * 4 + 0], &ta);
		mk_lib_crypto_alg_aes_256_mul_9(&orig.m_data.m_uint8s[i * 4 + 1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_256_mul_e(&orig.m_data.m_uint8s[i * 4 + 2], &ta);
		mk_lib_crypto_alg_aes_256_mul_b(&orig.m_data.m_uint8s[i * 4 + 3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 2]);
		mk_lib_crypto_alg_aes_256_mul_b(&orig.m_data.m_uint8s[i * 4 + 0], &ta);
		mk_lib_crypto_alg_aes_256_mul_d(&orig.m_data.m_uint8s[i * 4 + 1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_256_mul_9(&orig.m_data.m_uint8s[i * 4 + 2], &ta);
		mk_lib_crypto_alg_aes_256_mul_e(&orig.m_data.m_uint8s[i * 4 + 3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 3]);
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_add_key(mk_lib_crypto_alg_aes_256_msg_pct const a, mk_lib_crypto_alg_aes_256_msg_pct const b, mk_lib_crypto_alg_aes_256_msg_pt const c) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);

	for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor3(&a->m_data.m_uint8s[i], &b->m_data.m_uint8s[i], &c->m_data.m_uint8s[i]);
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_rot_word(mk_lib_crypto_alg_aes_256_word_pct const a, mk_lib_crypto_alg_aes_256_word_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = a->m_data.m_uint8s[0];
	b->m_data.m_uint8s[0] = a->m_data.m_uint8s[1];
	b->m_data.m_uint8s[1] = a->m_data.m_uint8s[2];
	b->m_data.m_uint8s[2] = a->m_data.m_uint8s[3];
	b->m_data.m_uint8s[3] = ta;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_sub_word(mk_lib_crypto_alg_aes_256_word_pct const a, mk_lib_crypto_alg_aes_256_word_pt const b) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_lib_crypto_alg_aes_256_word_bytes; ++i)
	{
		mk_lib_crypto_alg_aes_256_sub_byte(&a->m_data.m_uint8s[i], &b->m_data.m_uint8s[i]);
	}
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_xor_word(mk_lib_crypto_alg_aes_256_word_pct const a, mk_sl_cui_uint8_pct const b, mk_lib_crypto_alg_aes_256_word_pt const c, mk_sl_cui_uint8_pt const d) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_uint8_xor3(&a->m_data.m_uint8s[0], b, &c->m_data.m_uint8s[0]);
	c->m_data.m_uint8s[1] = a->m_data.m_uint8s[1];
	c->m_data.m_uint8s[2] = a->m_data.m_uint8s[2];
	c->m_data.m_uint8s[3] = a->m_data.m_uint8s[3];
	mk_lib_crypto_alg_aes_256_mul_2(b, d);
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_generate_keys(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pt const keys) mk_lang_noexcept
{
	#define get_outer(x) ((x) / mk_lib_crypto_alg_aes_256_msg_len_m)
	#define get_inner(x) ((x) % mk_lib_crypto_alg_aes_256_msg_len_m)

	mk_sl_cui_uint8_t rcon mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	int j mk_lang_constexpr_init;
	int idx_prev mk_lang_constexpr_init;
	int idx_curr mk_lang_constexpr_init;
	int idx_oldd mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_256_word_t tmp mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(keys);

	mk_sl_cui_uint8_set_one(&rcon);
	for(i = 0; i != mk_lib_crypto_alg_aes_256_key_len_m; ++i){ keys[get_outer(i)].m_data.m_uint8s[get_inner(i)] = key->m_data.m_uint8s[i]; }
	for(i = mk_lib_crypto_alg_aes_256_key_words; i != (mk_lib_crypto_alg_aes_256_nr + 1) * mk_lib_crypto_alg_aes_256_msg_words; ++i)
	{
		idx_prev = (i - 1) * mk_lib_crypto_alg_aes_256_word_bytes;
		for(j = 0; j != mk_lib_crypto_alg_aes_256_word_bytes; ++j){ tmp.m_data.m_uint8s[j] = keys[get_outer(idx_prev + j)].m_data.m_uint8s[get_inner(idx_prev + j)]; }
		if(i % mk_lib_crypto_alg_aes_256_key_words == 0)
		{
			mk_lib_crypto_alg_aes_256_rot_word(&tmp, &tmp);
			mk_lib_crypto_alg_aes_256_sub_word(&tmp, &tmp);
			mk_lib_crypto_alg_aes_256_xor_word(&tmp, &rcon, &tmp, &rcon);
		}
		else if(mk_lib_crypto_alg_aes_256_key_words > 6 && i % mk_lib_crypto_alg_aes_256_key_words == 4)
		{
			mk_lib_crypto_alg_aes_256_sub_word(&tmp, &tmp);
		}
		idx_curr = i * mk_lib_crypto_alg_aes_256_word_bytes;
		idx_oldd = (i - mk_lib_crypto_alg_aes_256_key_words) * mk_lib_crypto_alg_aes_256_word_bytes;
		for(j = 0; j != mk_lib_crypto_alg_aes_256_word_bytes; ++j)
		{
			mk_sl_cui_uint8_xor3(&tmp.m_data.m_uint8s[j], &keys[get_outer(idx_oldd + j)].m_data.m_uint8s[get_inner(idx_oldd + j)], &keys[get_outer(idx_curr + j)].m_data.m_uint8s[get_inner(idx_curr + j)]);
		}
	}

	#undef get_outer
	#undef get_inner
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_c_encrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_256_msg_t state mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_256_msg_t keys[mk_lib_crypto_alg_aes_256_nr + 1] mk_lang_constexpr_init;
	int ir mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_lib_crypto_alg_aes_256_key_t) >= mk_lib_crypto_alg_aes_256_key_len_v);
	mk_lang_static_assert(sizeof(mk_lib_crypto_alg_aes_256_msg_t) == mk_lib_crypto_alg_aes_256_msg_len_v);

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	state = *input;
	mk_lib_crypto_alg_aes_256_generate_keys(key, &keys[0]);
	mk_lib_crypto_alg_aes_256_add_key(&state, &keys[0], &state);
	for(ir = 0; ir != mk_lib_crypto_alg_aes_256_nr - 1; ++ir)
	{
		mk_lib_crypto_alg_aes_256_sub_bytes(&state, &state);
		mk_lib_crypto_alg_aes_256_shift_rows(&state, &state);
		mk_lib_crypto_alg_aes_256_mix_columns(&state, &state);
		mk_lib_crypto_alg_aes_256_add_key(&state, &keys[ir + 1], &state);
	}
	mk_lib_crypto_alg_aes_256_sub_bytes(&state, &state);
	mk_lib_crypto_alg_aes_256_shift_rows(&state, &state);
	mk_lib_crypto_alg_aes_256_add_key(&state, &keys[mk_lib_crypto_alg_aes_256_nr], &state);
	*output = state;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_crypto_alg_aes_256_c_decrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_256_msg_t state mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_256_msg_t keys[mk_lib_crypto_alg_aes_256_nr + 1] mk_lang_constexpr_init;
	int ir mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_lib_crypto_alg_aes_256_key_t) >= mk_lib_crypto_alg_aes_256_key_len_v);
	mk_lang_static_assert(sizeof(mk_lib_crypto_alg_aes_256_msg_t) == mk_lib_crypto_alg_aes_256_msg_len_v);

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	state = *input;
	mk_lib_crypto_alg_aes_256_generate_keys(key, keys);
	mk_lib_crypto_alg_aes_256_add_key(&state, &keys[mk_lib_crypto_alg_aes_256_nr], &state);
	for(ir = 0; ir != mk_lib_crypto_alg_aes_256_nr - 1; ++ir)
	{
		mk_lib_crypto_alg_aes_256_inv_shift_rows(&state, &state);
		mk_lib_crypto_alg_aes_256_inv_sub_bytes(&state, &state);
		mk_lib_crypto_alg_aes_256_add_key(&state, &keys[mk_lib_crypto_alg_aes_256_nr - (ir + 1)], &state);
		mk_lib_crypto_alg_aes_256_inv_mix_columns(&state, &state);
	}
	mk_lib_crypto_alg_aes_256_inv_shift_rows(&state, &state);
	mk_lib_crypto_alg_aes_256_inv_sub_bytes(&state, &state);
	mk_lib_crypto_alg_aes_256_add_key(&state, &keys[0], &state);
	*output = state;
}


#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1))


#include <emmintrin.h> /* _mm_castpd_si128 _mm_castsi128_pd _mm_load_si128 _mm_loadu_si128 _mm_shuffle_epi32 _mm_slli_si128 _mm_store_si128 _mm_storeu_si128 _mm_xor_si128 */
#include <wmmintrin.h> /* _mm_aesdec_si128 _mm_aesdeclast_si128 _mm_aesenc_si128 _mm_aesenclast_si128 _mm_aesimc_si128 _mm_aeskeygenassist_si128 */


#if mk_lang_alignof_bi_ulllong_t >= 16
#define mk_lib_crypto_alg_aes_256_msvc_aes_ni_load_m128i(src) _mm_load_si128(((__m128i const*)(src)))
#define mk_lib_crypto_alg_aes_256_msvc_aes_ni_store_m128i(dst, src) _mm_store_si128(((__m128i*)(dst)), src)
#else
#define mk_lib_crypto_alg_aes_256_msvc_aes_ni_load_m128i(src) _mm_loadu_si128(((__m128i const*)(src)))
#define mk_lib_crypto_alg_aes_256_msvc_aes_ni_store_m128i(dst, src) _mm_storeu_si128(((__m128i*)(dst)), src)
#endif


union mk_lib_crypto_alg_aes_256_msvc_aes_ni_aligned_schedule_u
{
	__m128i m_keys[mk_lib_crypto_alg_aes_256_nr + 1];
	mk_lang_types_uchar_t m_uchars[(mk_lib_crypto_alg_aes_256_nr + 1) * mk_lib_crypto_alg_aes_256_msg_len_m];
};
typedef union mk_lib_crypto_alg_aes_256_msvc_aes_ni_aligned_schedule_u mk_lib_crypto_alg_aes_256_msvc_aes_ni_aligned_schedule_t;
typedef mk_lib_crypto_alg_aes_256_msvc_aes_ni_aligned_schedule_t const mk_lib_crypto_alg_aes_256_msvc_aes_ni_aligned_schedule_ct;
typedef mk_lib_crypto_alg_aes_256_msvc_aes_ni_aligned_schedule_t* mk_lib_crypto_alg_aes_256_msvc_aes_ni_aligned_schedule_pt;
typedef mk_lib_crypto_alg_aes_256_msvc_aes_ni_aligned_schedule_t const* mk_lib_crypto_alg_aes_256_msvc_aes_ni_aligned_schedule_pct;

struct mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_s
{
	mk_lib_crypto_alg_aes_256_msvc_aes_ni_aligned_schedule_t m_data;
};
typedef struct mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_s mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_t;
typedef mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_t const mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_ct;
typedef mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_t* mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_pt;
typedef mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_t const* mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_pct;


static mk_lang_inline void mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_a(__m128i* const ta, __m128i* const tb) mk_lang_noexcept
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

static mk_lang_inline void mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_b(__m128i* const ta, __m128i* const tb) mk_lang_noexcept
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

static mk_lang_inline void mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_expand_enc(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_pt const schedule)
{
	__m128i ta;
	__m128i tb;
	__m128i tc;

	ta = mk_lib_crypto_alg_aes_256_msvc_aes_ni_load_m128i(&key->m_data.m_uint8s[ 0]);
	tb = mk_lib_crypto_alg_aes_256_msvc_aes_ni_load_m128i(&key->m_data.m_uint8s[16]);
	schedule->m_data.m_keys[0] = ta;
	schedule->m_data.m_keys[1] = tb;
	tc = _mm_aeskeygenassist_si128(tb, 0x01); mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_a(&ta, &tc); schedule->m_data.m_keys[ 2] = ta; mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_b(&ta, &tb); schedule->m_data.m_keys[ 3] = tb;
	tc = _mm_aeskeygenassist_si128(tb, 0x02); mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_a(&ta, &tc); schedule->m_data.m_keys[ 4] = ta; mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_b(&ta, &tb); schedule->m_data.m_keys[ 5] = tb;
	tc = _mm_aeskeygenassist_si128(tb, 0x04); mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_a(&ta, &tc); schedule->m_data.m_keys[ 6] = ta; mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_b(&ta, &tb); schedule->m_data.m_keys[ 7] = tb;
	tc = _mm_aeskeygenassist_si128(tb, 0x08); mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_a(&ta, &tc); schedule->m_data.m_keys[ 8] = ta; mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_b(&ta, &tb); schedule->m_data.m_keys[ 9] = tb;
	tc = _mm_aeskeygenassist_si128(tb, 0x10); mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_a(&ta, &tc); schedule->m_data.m_keys[10] = ta; mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_b(&ta, &tb); schedule->m_data.m_keys[11] = tb;
	tc = _mm_aeskeygenassist_si128(tb, 0x20); mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_a(&ta, &tc); schedule->m_data.m_keys[12] = ta; mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_b(&ta, &tb); schedule->m_data.m_keys[13] = tb;
	tc = _mm_aeskeygenassist_si128(tb, 0x40); mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_assist_a(&ta, &tc); schedule->m_data.m_keys[14] = ta;
}

static mk_lang_inline void mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_expand_dec(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_pt const schedule)
{
	mk_lang_assert(key);
	mk_lang_assert(schedule);

	mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_expand_enc(key, schedule);
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
	schedule->m_data.m_keys[12] = _mm_aesimc_si128(schedule->m_data.m_keys[12]);
	schedule->m_data.m_keys[13] = _mm_aesimc_si128(schedule->m_data.m_keys[13]);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_256_msvc_aes_ni_encrypt_with_schedule(mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_pct const schedule, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept
{
	__m128i v;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	v = mk_lib_crypto_alg_aes_256_msvc_aes_ni_load_m128i(input);
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
	v = _mm_aesenc_si128(v, schedule->m_data.m_keys[12]);
	v = _mm_aesenc_si128(v, schedule->m_data.m_keys[13]);
	v = _mm_aesenclast_si128(v, schedule->m_data.m_keys[14]);
	mk_lib_crypto_alg_aes_256_msvc_aes_ni_store_m128i(output, v);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_256_msvc_aes_ni_decrypt_with_schedule(mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_pct const schedule, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept
{
	__m128i v;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	v = mk_lib_crypto_alg_aes_256_msvc_aes_ni_load_m128i(input);
	v = _mm_xor_si128(v, schedule->m_data.m_keys[14]);
	v = _mm_aesdec_si128(v, schedule->m_data.m_keys[13]);
	v = _mm_aesdec_si128(v, schedule->m_data.m_keys[12]);
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
	mk_lib_crypto_alg_aes_256_msvc_aes_ni_store_m128i(output, v);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_256_msvc_aes_ni_encrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_t schedule;

	mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_expand_enc(key, &schedule);
	mk_lib_crypto_alg_aes_256_msvc_aes_ni_encrypt_with_schedule(&schedule, input, output);
}

static mk_lang_inline void mk_lib_crypto_alg_aes_256_msvc_aes_ni_decrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_256_msvc_aes_ni_schedule_t schedule;

	mk_lib_crypto_alg_aes_256_msvc_aes_ni_key_expand_dec(key, &schedule);
	mk_lib_crypto_alg_aes_256_msvc_aes_ni_decrypt_with_schedule(&schedule, input, output);
}


#endif


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_256_portable_encrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_256_c_encrypt(key, input, output);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_256_portable_decrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_256_c_decrypt(key, input, output);
}


mk_lang_jumbo void mk_lib_crypto_alg_aes_256_accelerated_encrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1))
	mk_lang_assert(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni());
	mk_lib_crypto_alg_aes_256_msvc_aes_ni_encrypt(key, input, output);
	#else
	((void)(key));
	((void)(input));
	((void)(output));
	mk_lang_crash();
	#endif
}

mk_lang_jumbo void mk_lib_crypto_alg_aes_256_accelerated_decrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1))
	mk_lang_assert(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni());
	mk_lib_crypto_alg_aes_256_msvc_aes_ni_decrypt(key, input, output);
	#else
	((void)(key));
	((void)(input));
	((void)(output));
	mk_lang_crash();
	#endif
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_256_encrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1))
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#endif
	{
		mk_lib_crypto_alg_aes_256_accelerated_encrypt(key, input, output);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_aes_256_portable_encrypt(key, input, output);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_alg_aes_256_decrypt(mk_lib_crypto_alg_aes_256_key_pct const key, mk_lib_crypto_alg_aes_256_msg_pct const input, mk_lib_crypto_alg_aes_256_msg_pt const output) mk_lang_noexcept
{
	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1))
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_sse2() && mk_lang_cpuid_has_aes_ni())
	#endif
	{
		mk_lib_crypto_alg_aes_256_accelerated_decrypt(key, input, output);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_aes_256_portable_decrypt(key, input, output);
	}
}
