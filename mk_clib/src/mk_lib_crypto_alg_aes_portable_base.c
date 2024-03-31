#include "mk_lib_crypto_alg_aes_portable_base.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"

#define mk_lib_crypto_mode_base_t_name mk_lib_crypto_alg_aes_portable_base
#define mk_lib_crypto_mode_base_t_len mk_lib_crypto_alg_aes_portable_base_msg_len_m
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"


#define mk_lib_crypto_alg_aes_portable_base_sbox_len (0xff + 1)


union mk_lib_crypto_alg_aes_portable_base_aligned_sbox_u
{
	mk_lang_alignas(mk_lib_crypto_alg_aes_portable_base_sbox_len) mk_sl_cui_uint8_t m_uint8s[mk_lib_crypto_alg_aes_portable_base_sbox_len];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_aes_portable_base_aligned_sbox_u mk_lib_crypto_alg_aes_portable_base_aligned_sbox_t;

struct mk_lib_crypto_alg_aes_portable_base_sbox_s
{
	mk_lib_crypto_alg_aes_portable_base_aligned_sbox_t m_data;
};
typedef struct mk_lib_crypto_alg_aes_portable_base_sbox_s mk_lib_crypto_alg_aes_portable_base_sbox_t;
typedef mk_lib_crypto_alg_aes_portable_base_sbox_t const mk_lib_crypto_alg_aes_portable_base_sbox_ct;
typedef mk_lib_crypto_alg_aes_portable_base_sbox_t* mk_lib_crypto_alg_aes_portable_base_sbox_pt;
typedef mk_lib_crypto_alg_aes_portable_base_sbox_t const* mk_lib_crypto_alg_aes_portable_base_sbox_pct;


mk_lang_constexpr_static_inline mk_lib_crypto_alg_aes_portable_base_sbox_t const s_mk_lib_crypto_alg_aes_portable_base_sbox_enc =
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

mk_lang_constexpr_static_inline mk_lib_crypto_alg_aes_portable_base_sbox_t const s_mk_lib_crypto_alg_aes_portable_base_sbox_dec =
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


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_sub_byte_enc(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint8_to_bi_uchar(a, &uc);
	*b = s_mk_lib_crypto_alg_aes_portable_base_sbox_enc.m_data.m_uint8s[uc];
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_sub_byte_dec(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_lang_types_uchar_t uc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint8_to_bi_uchar(a, &uc);
	*b = s_mk_lib_crypto_alg_aes_portable_base_sbox_dec.m_data.m_uint8s[uc];
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_sub_bytes_enc(mk_lib_crypto_alg_aes_portable_base_msg_pct const a, mk_lib_crypto_alg_aes_portable_base_msg_pt const b) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_lib_crypto_alg_aes_portable_base_msg_len_v; ++i)
	{
		mk_lib_crypto_alg_aes_portable_base_sub_byte_enc(&a->m_data.m_uint8s[i], &b->m_data.m_uint8s[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_sub_bytes_dec(mk_lib_crypto_alg_aes_portable_base_msg_pct const a, mk_lib_crypto_alg_aes_portable_base_msg_pt const b) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_lib_crypto_alg_aes_portable_base_msg_len_v; ++i)
	{
		mk_lib_crypto_alg_aes_portable_base_sub_byte_dec(&a->m_data.m_uint8s[i], &b->m_data.m_uint8s[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_shift_rows_enc(mk_lib_crypto_alg_aes_portable_base_msg_pct const a, mk_lib_crypto_alg_aes_portable_base_msg_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = a->m_data.m_uint8s[0 * 4 + 1];
	b->m_data.m_uint8s[0 * 4 + 1] = a->m_data.m_uint8s[1 * 4 + 1];
	b->m_data.m_uint8s[1 * 4 + 1] = a->m_data.m_uint8s[2 * 4 + 1];
	b->m_data.m_uint8s[2 * 4 + 1] = a->m_data.m_uint8s[3 * 4 + 1];
	b->m_data.m_uint8s[3 * 4 + 1] = ta;

	ta = a->m_data.m_uint8s[0 * 4 + 2];
	b->m_data.m_uint8s[0 * 4 + 2] = a->m_data.m_uint8s[2 * 4 + 2];
	b->m_data.m_uint8s[2 * 4 + 2] = ta;
	ta = a->m_data.m_uint8s[1 * 4 + 2];
	b->m_data.m_uint8s[1 * 4 + 2] = a->m_data.m_uint8s[3 * 4 + 2];
	b->m_data.m_uint8s[3 * 4 + 2] = ta;

	ta = a->m_data.m_uint8s[1 * 4 + 3];
	b->m_data.m_uint8s[1 * 4 + 3] = a->m_data.m_uint8s[0 * 4 + 3];
	b->m_data.m_uint8s[0 * 4 + 3] = a->m_data.m_uint8s[3 * 4 + 3];
	b->m_data.m_uint8s[3 * 4 + 3] = a->m_data.m_uint8s[2 * 4 + 3];
	b->m_data.m_uint8s[2 * 4 + 3] = ta;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_shift_rows_dec(mk_lib_crypto_alg_aes_portable_base_msg_pct const a, mk_lib_crypto_alg_aes_portable_base_msg_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = a->m_data.m_uint8s[1 * 4 + 1];
	b->m_data.m_uint8s[1 * 4 + 1] = a->m_data.m_uint8s[0 * 4 + 1];
	b->m_data.m_uint8s[0 * 4 + 1] = a->m_data.m_uint8s[3 * 4 + 1];
	b->m_data.m_uint8s[3 * 4 + 1] = a->m_data.m_uint8s[2 * 4 + 1];
	b->m_data.m_uint8s[2 * 4 + 1] = ta;

	ta = a->m_data.m_uint8s[0 * 4 + 2];
	b->m_data.m_uint8s[0 * 4 + 2] = a->m_data.m_uint8s[2 * 4 + 2];
	b->m_data.m_uint8s[2 * 4 + 2] = ta;
	ta = a->m_data.m_uint8s[1 * 4 + 2];
	b->m_data.m_uint8s[1 * 4 + 2] = a->m_data.m_uint8s[3 * 4 + 2];
	b->m_data.m_uint8s[3 * 4 + 2] = ta;

	ta = a->m_data.m_uint8s[0 * 4 + 3];
	b->m_data.m_uint8s[0 * 4 + 3] = a->m_data.m_uint8s[1 * 4 + 3];
	b->m_data.m_uint8s[1 * 4 + 3] = a->m_data.m_uint8s[2 * 4 + 3];
	b->m_data.m_uint8s[2 * 4 + 3] = a->m_data.m_uint8s[3 * 4 + 3];
	b->m_data.m_uint8s[3 * 4 + 3] = ta;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_mul_1(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = *a;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_mul_2(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_sl_cui_uint8_t const s_cnt = mk_sl_cui_uint8_c(0x1b);

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
	mk_sl_cui_uint8_mul2_wrap_lo(&tb, &s_cnt);
	mk_sl_cui_uint8_xor3(&ta, &tb, &n);
	*b = n;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_mul_3(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = *a;
	tb = *a;
	mk_lib_crypto_alg_aes_portable_base_mul_2(&ta, &ta);
	mk_lib_crypto_alg_aes_portable_base_mul_1(&tb, &tb);
	mk_sl_cui_uint8_xor2(&ta, &tb);
	*b = ta;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_mul_4(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = *a;
	mk_lib_crypto_alg_aes_portable_base_mul_2(&ta, &ta);
	mk_lib_crypto_alg_aes_portable_base_mul_2(&ta, &ta);
	*b = ta;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_mul_8(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = *a;
	mk_lib_crypto_alg_aes_portable_base_mul_2(&ta, &ta);
	mk_lib_crypto_alg_aes_portable_base_mul_2(&ta, &ta);
	mk_lib_crypto_alg_aes_portable_base_mul_2(&ta, &ta);
	*b = ta;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_mul_9(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = *a;
	tb = *a;
	mk_lib_crypto_alg_aes_portable_base_mul_8(&ta, &ta);
	mk_lib_crypto_alg_aes_portable_base_mul_1(&tb, &tb);
	mk_sl_cui_uint8_xor2(&ta, &tb);
	*b = ta;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_mul_b(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = *a;
	tb = *a;
	tc = *a;
	mk_lib_crypto_alg_aes_portable_base_mul_8(&ta, &ta);
	mk_lib_crypto_alg_aes_portable_base_mul_2(&tb, &tb);
	mk_lib_crypto_alg_aes_portable_base_mul_1(&tc, &tc);
	mk_sl_cui_uint8_xor2(&ta, &tb);
	mk_sl_cui_uint8_xor2(&ta, &tc);
	*b = ta;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_mul_d(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = *a;
	tb = *a;
	tc = *a;
	mk_lib_crypto_alg_aes_portable_base_mul_8(&ta, &ta);
	mk_lib_crypto_alg_aes_portable_base_mul_4(&tb, &tb);
	mk_lib_crypto_alg_aes_portable_base_mul_1(&tc, &tc);
	mk_sl_cui_uint8_xor2(&ta, &tb);
	mk_sl_cui_uint8_xor2(&ta, &tc);
	*b = ta;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_mul_e(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ta = *a;
	tb = *a;
	tc = *a;
	mk_lib_crypto_alg_aes_portable_base_mul_8(&ta, &ta);
	mk_lib_crypto_alg_aes_portable_base_mul_4(&tb, &tb);
	mk_lib_crypto_alg_aes_portable_base_mul_2(&tc, &tc);
	mk_sl_cui_uint8_xor2(&ta, &tb);
	mk_sl_cui_uint8_xor2(&ta, &tc);
	*b = ta;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_mix_columns_enc(mk_lib_crypto_alg_aes_portable_base_msg_pct const a, mk_lib_crypto_alg_aes_portable_base_msg_pt const b) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tarr[4] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t td mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != 4; ++i)
	{
		tarr[0] = a->m_data.m_uint8s[i * 4 + 0];
		tarr[1] = a->m_data.m_uint8s[i * 4 + 1];
		tarr[2] = a->m_data.m_uint8s[i * 4 + 2];
		tarr[3] = a->m_data.m_uint8s[i * 4 + 3];

		mk_lib_crypto_alg_aes_portable_base_mul_2(&tarr[0], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_3(&tarr[1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_portable_base_mul_1(&tarr[2], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_1(&tarr[3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 0]);

		mk_lib_crypto_alg_aes_portable_base_mul_1(&tarr[0], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_2(&tarr[1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_portable_base_mul_3(&tarr[2], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_1(&tarr[3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 1]);

		mk_lib_crypto_alg_aes_portable_base_mul_1(&tarr[0], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_1(&tarr[1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_portable_base_mul_2(&tarr[2], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_3(&tarr[3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 2]);

		mk_lib_crypto_alg_aes_portable_base_mul_3(&tarr[0], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_1(&tarr[1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_portable_base_mul_1(&tarr[2], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_2(&tarr[3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 3]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_mix_columns_dec(mk_lib_crypto_alg_aes_portable_base_msg_pct const a, mk_lib_crypto_alg_aes_portable_base_msg_pt const b) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tarr[4] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t td mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != 4; ++i)
	{
		tarr[0] = a->m_data.m_uint8s[i * 4 + 0];
		tarr[1] = a->m_data.m_uint8s[i * 4 + 1];
		tarr[2] = a->m_data.m_uint8s[i * 4 + 2];
		tarr[3] = a->m_data.m_uint8s[i * 4 + 3];

		mk_lib_crypto_alg_aes_portable_base_mul_e(&tarr[0], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_b(&tarr[1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_portable_base_mul_d(&tarr[2], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_9(&tarr[3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 0]);

		mk_lib_crypto_alg_aes_portable_base_mul_9(&tarr[0], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_e(&tarr[1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_portable_base_mul_b(&tarr[2], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_d(&tarr[3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 1]);

		mk_lib_crypto_alg_aes_portable_base_mul_d(&tarr[0], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_9(&tarr[1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_portable_base_mul_e(&tarr[2], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_b(&tarr[3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 2]);

		mk_lib_crypto_alg_aes_portable_base_mul_b(&tarr[0], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_d(&tarr[1], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &tc);
		mk_lib_crypto_alg_aes_portable_base_mul_9(&tarr[2], &ta);
		mk_lib_crypto_alg_aes_portable_base_mul_e(&tarr[3], &tb);
		mk_sl_cui_uint8_xor3(&ta, &tb, &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &b->m_data.m_uint8s[i * 4 + 3]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_add_key2(mk_lib_crypto_alg_aes_portable_base_msg_pt const a, mk_lib_crypto_alg_aes_portable_base_msg_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(a != b);

	mk_lib_crypto_alg_aes_portable_base_xor2(&a->m_data.m_uint8s[0], &b->m_data.m_uint8s[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_add_key3(mk_lib_crypto_alg_aes_portable_base_msg_pct const a, mk_lib_crypto_alg_aes_portable_base_msg_pct const b, mk_lib_crypto_alg_aes_portable_base_msg_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);

	mk_lib_crypto_alg_aes_portable_base_xor3(&a->m_data.m_uint8s[0], &b->m_data.m_uint8s[0], &c->m_data.m_uint8s[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_rot_word(mk_lib_crypto_alg_aes_portable_base_word_pct const a, mk_lib_crypto_alg_aes_portable_base_word_pt const b) mk_lang_noexcept
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

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_sub_word(mk_lib_crypto_alg_aes_portable_base_word_pct const a, mk_lib_crypto_alg_aes_portable_base_word_pt const b) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_lib_crypto_alg_aes_portable_base_word_bytes; ++i)
	{
		mk_lib_crypto_alg_aes_portable_base_sub_byte_enc(&a->m_data.m_uint8s[i], &b->m_data.m_uint8s[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_base_xor_word(mk_lib_crypto_alg_aes_portable_base_word_pct const a, mk_sl_cui_uint8_pct const b, mk_lib_crypto_alg_aes_portable_base_word_pt const c, mk_sl_cui_uint8_pt const d) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_uint8_xor3(&a->m_data.m_uint8s[0], b, &c->m_data.m_uint8s[0]);
	c->m_data.m_uint8s[1] = a->m_data.m_uint8s[1];
	c->m_data.m_uint8s[2] = a->m_data.m_uint8s[2];
	c->m_data.m_uint8s[3] = a->m_data.m_uint8s[3];
	mk_lib_crypto_alg_aes_portable_base_mul_2(b, d);
}
