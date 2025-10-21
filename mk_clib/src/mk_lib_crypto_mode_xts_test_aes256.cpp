#ifndef mk_include_guard_mk_lib_crypto_mode_xts_test_aes256_cpp
#define mk_include_guard_mk_lib_crypto_mode_xts_test_aes256_cpp


#if defined mk_lang_jumbo_want
#undef mk_lang_jumbo_want
#endif
#define mk_lang_jumbo_want 2


#include "mk_lang_warning_msvc_push_c4514.h"


#include "mk_lib_crypto_mode_xts_test_aes256.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr_array_u8.hpp"
#include "mk_lib_crypto_mode_xts.h"
#include "mk_sl_cui_uint8.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t iv_lit_len, mk_lang_types_usize_t msg_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_mode_xts_test_aes256_aes_256_encrypt_from_str_lit(mk_lang_types_pchar_t const(&key_lit)[key_lit_len], mk_lang_types_pchar_t const(&iv_lit)[iv_lit_len], mk_lang_types_pchar_t const(&msg_lit)[msg_lit_len]) mk_lang_noexcept
{
	mk_lang_types_sint_t half_key_len_bytes mk_lang_constexpr_init;
	mk_lang_types_sint_t half_key_len_hex mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_aes_256_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_aes_256_iv_t iv mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_aes_256_alg_t alg mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_aes_256_msg_t msgs[(msg_lit_len - 1) / (((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)))] mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (msg_lit_len - 1) / 2> ret mk_lang_constexpr_init;

	mk_lang_static_assert(iv_lit_len == ((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_iv_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)) + 1);
	mk_lang_static_assert(key_lit_len == ((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_key_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)) + 1);
	mk_lang_static_assert(msg_lit_len >= 1);
	mk_lang_static_assert((msg_lit_len - 1) % (((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))) == 0);

	mk_lang_assert(key_lit);
	mk_lang_assert(iv_lit);
	mk_lang_assert(msg_lit);

	half_key_len_bytes = ((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_key_len_v)) / ((mk_lang_types_sint_t)(2));
	half_key_len_hex = half_key_len_bytes * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v));
	len = mk_sl_cui_uint8_from_str_hex_many_n(&key.m_pri.m_data.m_base.m_data.m_uint8s[0], half_key_len_bytes, &key_lit[0 * half_key_len_hex], half_key_len_hex); mk_lang_assert(len == half_key_len_hex);
	len = mk_sl_cui_uint8_from_str_hex_many_n(&key.m_sec.m_data.m_base.m_data.m_uint8s[0], half_key_len_bytes, &key_lit[1 * half_key_len_hex], half_key_len_hex); mk_lang_assert(len == half_key_len_hex);
	mk_lib_cpp_constexpr_array_u8_from_hex_lit(iv.m_data.m_base.m_data.m_uint8s, iv_lit);
	mk_lib_crypto_mode_xts_aes_256_rw_set_key_enc(&alg, &key);
	mk_lib_crypto_mode_xts_aes_256_rw_set_iv(&alg, &iv);
	n = mk_lang_countof(msgs);
	for(i = 0; i != n; ++i)
	{
		len = mk_sl_cui_uint8_from_str_hex_many_n(&msgs[i].m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_xts_aes_256_msg_len_v, &msg_lit[i * (((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)))], ((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))); mk_lang_assert(len == ((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)));
	}
	mk_lib_crypto_mode_xts_aes_256_rw_encrypt(&alg, &msgs[0], &msgs[0], ((mk_lang_types_usize_t)(n)));
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_memcpy_fn(ret.data() + i * mk_lib_crypto_mode_xts_aes_256_msg_len_v, &msgs[i].m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_xts_aes_256_msg_len_v);
	}
	return ret;
}

template<mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t iv_lit_len, mk_lang_types_usize_t msg_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_mode_xts_test_aes256_aes_256_decrypt_from_str_lit(mk_lang_types_pchar_t const(&key_lit)[key_lit_len], mk_lang_types_pchar_t const(&iv_lit)[iv_lit_len], mk_lang_types_pchar_t const(&msg_lit)[msg_lit_len]) mk_lang_noexcept
{
	mk_lang_types_sint_t half_key_len_bytes mk_lang_constexpr_init;
	mk_lang_types_sint_t half_key_len_hex mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_aes_256_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_aes_256_iv_t iv mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_aes_256_alg_t alg mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_aes_256_msg_t msgs[(msg_lit_len - 1) / (((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)))] mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (msg_lit_len - 1) / 2> ret mk_lang_constexpr_init;

	mk_lang_static_assert(iv_lit_len == ((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_iv_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)) + 1);
	mk_lang_static_assert(key_lit_len == ((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_key_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)) + 1);
	mk_lang_static_assert(msg_lit_len >= 1);
	mk_lang_static_assert((msg_lit_len - 1) % (((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))) == 0);

	mk_lang_assert(key_lit);
	mk_lang_assert(iv_lit);
	mk_lang_assert(msg_lit);

	half_key_len_bytes = ((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_key_len_v)) / ((mk_lang_types_sint_t)(2));
	half_key_len_hex = half_key_len_bytes * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v));
	len = mk_sl_cui_uint8_from_str_hex_many_n(&key.m_pri.m_data.m_base.m_data.m_uint8s[0], half_key_len_bytes, &key_lit[0 * half_key_len_hex], half_key_len_hex); mk_lang_assert(len == half_key_len_hex);
	len = mk_sl_cui_uint8_from_str_hex_many_n(&key.m_sec.m_data.m_base.m_data.m_uint8s[0], half_key_len_bytes, &key_lit[1 * half_key_len_hex], half_key_len_hex); mk_lang_assert(len == half_key_len_hex);
	mk_lib_cpp_constexpr_array_u8_from_hex_lit(iv.m_data.m_base.m_data.m_uint8s, iv_lit);
	mk_lib_crypto_mode_xts_aes_256_rw_set_key_dec(&alg, &key);
	mk_lib_crypto_mode_xts_aes_256_rw_set_iv(&alg, &iv);
	n = mk_lang_countof(msgs);
	for(i = 0; i != n; ++i)
	{
		len = mk_sl_cui_uint8_from_str_hex_many_n(&msgs[i].m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_xts_aes_256_msg_len_v, &msg_lit[i * (((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)))], ((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))); mk_lang_assert(len == ((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)));
	}
	mk_lib_crypto_mode_xts_aes_256_rw_decrypt(&alg, &msgs[0], &msgs[0], ((mk_lang_types_usize_t)(n)));
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_memcpy_fn(ret.data() + i * mk_lib_crypto_mode_xts_aes_256_msg_len_v, &msgs[i].m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_xts_aes_256_msg_len_v);
	}
	return ret;
}

#endif


mk_lang_extern_force_c mk_lang_types_void_t mk_lib_crypto_mode_xts_test_aes256(mk_lang_types_void_t) mk_lang_noexcept
{
	#define key_1 "2718281828459045235360287471352662497757247093699959574966967627""3141592653589793238462643383279502884197169399375105820974944592"
	#define key_2 "2718281828459045235360287471352662497757247093699959574966967627""3141592653589793238462643383279502884197169399375105820974944592"
	#define key_3 "2718281828459045235360287471352662497757247093699959574966967627""3141592653589793238462643383279502884197169399375105820974944592"
	#define key_4 "2718281828459045235360287471352662497757247093699959574966967627""3141592653589793238462643383279502884197169399375105820974944592"
	#define key_5 "2718281828459045235360287471352662497757247093699959574966967627""3141592653589793238462643383279502884197169399375105820974944592"

	#define iv_1 "ff000000000000000000000000000000"
	#define iv_2 "ffff0000000000000000000000000000"
	#define iv_3 "ffffff00000000000000000000000000"
	#define iv_4 "ffffffff000000000000000000000000"
	#define iv_5 "ffffffffff0000000000000000000000"

	#define msg_1 "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f""202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f""404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f""606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f""808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9f""a0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebf""c0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedf""e0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff""000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f""202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f""404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f""606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f""808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9f""a0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebf""c0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedf""e0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
	#define msg_2 "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f""202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f""404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f""606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f""808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9f""a0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebf""c0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedf""e0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff""000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f""202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f""404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f""606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f""808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9f""a0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebf""c0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedf""e0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
	#define msg_3 "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f""202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f""404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f""606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f""808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9f""a0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebf""c0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedf""e0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff""000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f""202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f""404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f""606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f""808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9f""a0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebf""c0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedf""e0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
	#define msg_4 "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f""202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f""404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f""606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f""808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9f""a0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebf""c0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedf""e0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff""000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f""202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f""404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f""606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f""808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9f""a0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebf""c0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedf""e0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"
	#define msg_5 "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f""202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f""404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f""606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f""808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9f""a0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebf""c0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedf""e0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff""000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f""202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f""404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f""606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f""808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9f""a0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebf""c0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedf""e0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"

	#define out_1 "1c3b3a102f770386e4836c99e370cf9bea00803f5e482357a4ae12d414a3e63b""5d31e276f8fe4a8d66b317f9ac683f44680a86ac35adfc3345befecb4bb188fd""5776926c49a3095eb108fd1098baec70aaa66999a72a82f27d848b21d4a741b0""c5cd4d5fff9dac89aeba122961d03a757123e9870f8acf1000020887891429ca""2a3e7a7d7df7b10355165c8b9a6d0a7de8b062c4500dc4cd120c0f7418dae3d0""b5781c34803fa75421c790dfe1de1834f280d7667b327f6c8cd7557e12ac3a0f""93ec05c52e0493ef31a12d3d9260f79a289d6a379bc70c50841473d1a8cc81ec""583e9645e07b8d9670655ba5bbcfecc6dc3966380ad8fecb17b6ba02469a020a""84e18e8f84252070c13e9f1f289be54fbc481457778f616015e1327a02b140f1""505eb309326d68378f8374595c849d84f4c333ec4423885143cb47bd71c5edae""9be69a2ffeceb1bec9de244fbe15992b11b77c040f12bd8f6a975a44a0f90c29""a9abc3d4d893927284c58754cce294529f8614dcd2aba991925fedc4ae74ffac""6e333b93eb4aff0479da9a410e4450e0dd7ae4c6e2910900575da401fc07059f""645e8b7e9bfdef33943054ff84011493c27b3429eaedb4ed5376441a77ed4385""1ad77f16f541dfd269d50d6a5f14fb0aab1cbb4c1550be97f7ab4066193c4caa""773dad38014bd2092fa755c824bb5e54c4f36ffda9fcea70b9c6e693e148c151"
	#define out_2 "77a31251618a15e6b92d1d66dffe7b50b50bad552305ba0217a610688eff7e11""e1d0225438e093242d6db274fde801d4cae06f2092c728b2478559df58e837c2""469ee4a4fa794e4bbc7f39bc026e3cb72c33b0888f25b4acf56a2a9804f1ce6d""3d6e1dc6ca181d4b546179d55544aa7760c40d06741539c7e3cd9d2f6650b201""3fd0eeb8c2b8e3d8d240ccae2d4c98320a7442e1c8d75a42d6e6cfa4c2eca179""8d158c7aecdf82490f24bb9b38e108bcda12c3faf9a21141c3613b58367f922a""aa26cd22f23d708dae699ad7cb40a8ad0b6e2784973dcb605684c08b8d6998c6""9aac049921871ebb65301a4619ca80ecb485a31d744223ce8ddc2394828d6a80""470c092f5ba413c3378fa6054255c6f9df4495862bbb3287681f931b687c888a""bf844dfc8fc28331e579928cd12bd2390ae123cf03818d14dedde5c0c24c8ab0""18bfca75ca096f2d531f3d1619e785f1ada437cab92e980558b3dce1474afb75""bfedbf8ff54cb2618e0244c9ac0d3c66fb51598cd2db11f9be39791abe447c63""094f7c453b7ff87cb5bb36b7c79efb0872d17058b83b15ab0866ad8a58656c5a""7e20dbdf308b2461d97c0ec0024a2715055249cf3b478ddd4740de654f75ca68""6e0d7345c69ed50cdc2a8b332b1f8824108ac937eb050585608ee734097fc090""54fbff89eeaeea791f4a7ab1f9868294a4f9e27b42af8100cb9d59cef9645803"
	#define out_3 "e387aaa58ba483afa7e8eb469778317ecf4cf573aa9d4eac23f2cdf914e4e200""a8b490e42ee646802dc6ee2b471b278195d60918ececb44bf79966f83faba049""9298ebc699c0c8634715a320bb4f075d622e74c8c932004f25b41e361025b5a8""7815391f6108fc4afa6a05d9303c6ba68a128a55705d415985832fdeaae6c8e1""9110e84d1b1f199a2692119edc96132658f09da7c623efcec712537a3d94c0bf""5d7e352ec94ae5797fdb377dc1551150721adf15bd26a8efc2fcaad56881fa9e""62462c28f30ae1ceaca93c345cf243b73f542e2074a705bd2643bb9f7cc79bb6""e7091ea6e232df0f9ad0d6cf502327876d82207abf2115cdacf6d5a48f6c1879""a65b115f0f8b3cb3c59d15dd8c769bc014795a1837f3901b5845eb491adfefe0""97b1fa30a12fc1f65ba22905031539971a10f2f36c321bb51331cdefb39e3964""c7ef079994f5b69b2edd83a71ef549971ee93f44eac3938fcdd61d01fa71799d""a3a8091c4c48aa9ed263ff0749df95d44fef6a0bb578ec69456aa5408ae32c7a""f08ad7ba8921287e3bbee31b767be06a0e705c864a769137df28292283ea81a2""480241b44d9921cdbec1bc28dc1fda114bd8e5217ac9d8ebafa720e9da4f9ace""231cc949e5b96fe76ffc21063fddc83a6b8679c00d35e09576a875305bed5f36""ed242c8900dd1fa965bc950dfce09b132263a1eef52dd6888c309f5a7d712826"
	#define out_4 "bf53d2dade78e822a4d949a9bc6766b01b06a8ef70d26748c6a7fc36d80ae4c5""520f7c4ab0ac8544424fa405162fef5a6b7f229498063618d39f0003cb5fb8d1""c86b643497da1ff945c8d3bedeca4f479702a7a735f043ddb1d6aaade3c4a0ac""7ca7f3fa5279bef56f82cd7a2f38672e824814e10700300a055e1630b8f1cb0e""919f5e942010a416e2bf48cb46993d3cb6a51c19bacf864785a00bc2ecff15d3""50875b246ed53e68be6f55bd7e05cfc2b2ed6432198a6444b6d8c247fab941f5""69768b5c429366f1d3f00f0345b96123d56204c01c63b22ce78baf116e525ed9""0fdea39fa469494d3866c31e05f295ff21fea8d4e6e13d67e47ce722e9698a1c""1048d68ebcde76b86fcf976eab8aa9790268b7068e017a8b9b749409514f1053""027fd16c3786ea1bac5f15cb79711ee2abe82f5cf8b13ae73030ef5b9e4457e7""5d1304f988d62dd6fc4b94ed38ba831da4b7634971b6cd8ec325d9c61c00f1df""73627ed3745a5e8489f3a95c69639c32cd6e1d537a85f75cc844726e8a72fc00""77ad22000f1d5078f6b866318c668f1ad03d5a5fced5219f2eabbd0aa5c0f460""d183f04404a0d6f469558e81fab24a167905ab4c7878502ad3e38fdbe62a4155""6cec37325759533ce8f25f367c87bb5578d667ae93f9e2fd99bcbc5f2fbba88c""f6516139420fcff3b7361d86322c4bd84c82f335abb152c4a93411373aaa8220"
	#define out_5 "64497e5a831e4a932c09be3e5393376daa599548b816031d224bbf50a818ed23""50eae7e96087c8a0db51ad290bd00c1ac1620857635bf246c176ab463be30b80""8da548081ac847b158e1264be25bb0910bbc92647108089415d45fab1b3d2604""e8a8eff1ae4020cfa39936b66827b23f371b92200be90251e6d73c5f86de5fd4""a950781933d79a28272b782a2ec313efdfcc0628f43d744c2dc2ff3dcb66999b""50c7ca895b0c64791eeaa5f29499fb1c026f84ce5b5c72ba1083cddb5ce45434""631665c333b60b11593fb253c5179a2c8db813782a004856a1653011e93fb6d8""76c18366dd8683f53412c0c180f9c848592d593f8609ca736317d356e13e2bff""3a9f59cd9aeb19cd482593d8c46128bb32423b37a9adfb482b99453fbe25a41b""f6feb4aa0bef5ed24bf73c762978025482c13115e4015aac992e5613a3b5c2f6""85b84795cb6e9b2656d8c88157e52c42f978d8634c43d06fea928f2822e465aa""6576e9bf419384506cc3ce3c54ac1a6f67dc66f3b30191e698380bc999b05abc""e19dc0c6dcc2dd001ec535ba18deb2df1a101023108318c75dc98611a09dc48a""0acdec676fabdf222f07e026f059b672b56e5cbc8e1d21bbd867dd9272120546""81d70ea737134cdfce93b6f82ae22423274e58a0821cc5502e2d0ab4585e94de""6975be5e0b4efce51cd3e70c25a1fbbbd609d273ad5b0d59631c531f6a0a57b9"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_out_computed_1 = mk_lib_crypto_mode_xts_test_aes256_aes_256_encrypt_from_str_lit(key_1, iv_1, msg_1);
	mk_lang_constexpr_static auto const s_out_computed_2 = mk_lib_crypto_mode_xts_test_aes256_aes_256_encrypt_from_str_lit(key_2, iv_2, msg_2);
	mk_lang_constexpr_static auto const s_out_computed_3 = mk_lib_crypto_mode_xts_test_aes256_aes_256_encrypt_from_str_lit(key_3, iv_3, msg_3);
	mk_lang_constexpr_static auto const s_out_computed_4 = mk_lib_crypto_mode_xts_test_aes256_aes_256_encrypt_from_str_lit(key_4, iv_4, msg_4);
	mk_lang_constexpr_static auto const s_out_computed_5 = mk_lib_crypto_mode_xts_test_aes256_aes_256_encrypt_from_str_lit(key_5, iv_5, msg_5);

	mk_lang_constexpr_static auto const s_msg_computed_1 = mk_lib_crypto_mode_xts_test_aes256_aes_256_decrypt_from_str_lit(key_1, iv_1, out_1);
	mk_lang_constexpr_static auto const s_msg_computed_2 = mk_lib_crypto_mode_xts_test_aes256_aes_256_decrypt_from_str_lit(key_2, iv_2, out_2);
	mk_lang_constexpr_static auto const s_msg_computed_3 = mk_lib_crypto_mode_xts_test_aes256_aes_256_decrypt_from_str_lit(key_3, iv_3, out_3);
	mk_lang_constexpr_static auto const s_msg_computed_4 = mk_lib_crypto_mode_xts_test_aes256_aes_256_decrypt_from_str_lit(key_4, iv_4, out_4);
	mk_lang_constexpr_static auto const s_msg_computed_5 = mk_lib_crypto_mode_xts_test_aes256_aes_256_decrypt_from_str_lit(key_5, iv_5, out_5);

	mk_lang_constexpr_static auto const s_out_precomputed_1 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(out_1);
	mk_lang_constexpr_static auto const s_out_precomputed_2 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(out_2);
	mk_lang_constexpr_static auto const s_out_precomputed_3 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(out_3);
	mk_lang_constexpr_static auto const s_out_precomputed_4 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(out_4);
	mk_lang_constexpr_static auto const s_out_precomputed_5 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(out_5);

	mk_lang_constexpr_static auto const s_msg_precomputed_1 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(msg_1);
	mk_lang_constexpr_static auto const s_msg_precomputed_2 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(msg_2);
	mk_lang_constexpr_static auto const s_msg_precomputed_3 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(msg_3);
	mk_lang_constexpr_static auto const s_msg_precomputed_4 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(msg_4);
	mk_lang_constexpr_static auto const s_msg_precomputed_5 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(msg_5);

	mk_lang_static_assert(s_out_computed_1 == s_out_precomputed_1);
	mk_lang_static_assert(s_out_computed_2 == s_out_precomputed_2);
	mk_lang_static_assert(s_out_computed_3 == s_out_precomputed_3);
	mk_lang_static_assert(s_out_computed_4 == s_out_precomputed_4);
	mk_lang_static_assert(s_out_computed_5 == s_out_precomputed_5);

	mk_lang_static_assert(s_msg_computed_1 == s_msg_precomputed_1);
	mk_lang_static_assert(s_msg_computed_2 == s_msg_precomputed_2);
	mk_lang_static_assert(s_msg_computed_3 == s_msg_precomputed_3);
	mk_lang_static_assert(s_msg_computed_4 == s_msg_precomputed_4);
	mk_lang_static_assert(s_msg_computed_5 == s_msg_precomputed_5);

	#endif

	mk_lang_types_pchar_pct const keys[] =
	{
		key_1,
		key_2,
		key_3,
		key_4,
		key_5,
	};

	mk_lang_types_sint_t const keys_lens[] =
	{
		mk_lang_countstr(key_1),
		mk_lang_countstr(key_2),
		mk_lang_countstr(key_3),
		mk_lang_countstr(key_4),
		mk_lang_countstr(key_5),
	};

	mk_lang_types_pchar_pct const ivs[] =
	{
		iv_1,
		iv_2,
		iv_3,
		iv_4,
		iv_5,
	};

	mk_lang_types_sint_t const ivs_lens[] =
	{
		mk_lang_countstr(iv_1),
		mk_lang_countstr(iv_2),
		mk_lang_countstr(iv_3),
		mk_lang_countstr(iv_4),
		mk_lang_countstr(iv_5),
	};

	mk_lang_types_pchar_pct const msgs[] =
	{
		msg_1,
		msg_2,
		msg_3,
		msg_4,
		msg_5,
	};

	mk_lang_types_sint_t const msgs_lens[] =
	{
		mk_lang_countstr(msg_1),
		mk_lang_countstr(msg_2),
		mk_lang_countstr(msg_3),
		mk_lang_countstr(msg_4),
		mk_lang_countstr(msg_5),
	};

	mk_lang_types_pchar_pct const outs[] =
	{
		out_1,
		out_2,
		out_3,
		out_4,
		out_5,
	};

	mk_lang_types_sint_t const outs_lens[] =
	{
		mk_lang_countstr(out_1),
		mk_lang_countstr(out_2),
		mk_lang_countstr(out_3),
		mk_lang_countstr(out_4),
		mk_lang_countstr(out_5),
	};

	mk_lang_types_sint_t half_key_len_bytes mk_lang_constexpr_init;
	mk_lang_types_sint_t half_key_len_hex mk_lang_constexpr_init;
	mk_lang_types_sint_t iv_len_bytes mk_lang_constexpr_init;
	mk_lang_types_sint_t iv_len_hex mk_lang_constexpr_init;
	mk_lang_types_sint_t msg_len_bytes mk_lang_constexpr_init;
	mk_lang_types_sint_t msg_len_hex mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_aes_256_iv_t iv mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_aes_256_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_aes_256_alg_t alg mk_lang_constexpr_init;
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_aes_256_msg_t msg[32] mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_aes_256_msg_t out mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(ivs) == mk_lang_countof(ivs_lens));
	mk_lang_static_assert(mk_lang_countof(ivs) == mk_lang_countof(keys));
	mk_lang_static_assert(mk_lang_countof(ivs) == mk_lang_countof(keys_lens));
	mk_lang_static_assert(mk_lang_countof(ivs) == mk_lang_countof(msgs));
	mk_lang_static_assert(mk_lang_countof(ivs) == mk_lang_countof(msgs_lens));
	mk_lang_static_assert(mk_lang_countof(ivs) == mk_lang_countof(keys));
	mk_lang_static_assert(mk_lang_countof(ivs) == mk_lang_countof(outs_lens));

	half_key_len_bytes = ((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_key_len_v)) / ((mk_lang_types_sint_t)(2));
	half_key_len_hex = half_key_len_bytes * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v));
	iv_len_bytes = ((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_iv_len_v));
	iv_len_hex = iv_len_bytes * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v));
	msg_len_bytes = ((mk_lang_types_sint_t)(mk_lib_crypto_mode_xts_aes_256_msg_len_v));
	msg_len_hex = msg_len_bytes * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v));
	n = mk_lang_countof(ivs);
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(keys_lens[i] == 2 * half_key_len_hex);
		mk_lang_assert(ivs_lens[i] == iv_len_hex);
		mk_lang_assert(msgs_lens[i] % msg_len_hex == 0);
		mk_lang_assert(outs_lens[i] % msg_len_hex == 0);
		mk_lang_assert(msgs_lens[i] == outs_lens[i]);
		mk_lang_assert(mk_lang_countof(msg) >= msgs_lens[i] / msg_len_hex);
		len = mk_sl_cui_uint8_from_str_hex_many_n(&key.m_pri.m_data.m_base.m_data.m_uint8s[0], half_key_len_bytes, &keys[i][0 * half_key_len_hex], half_key_len_hex); mk_lang_assert(len == half_key_len_hex);
		len = mk_sl_cui_uint8_from_str_hex_many_n(&key.m_sec.m_data.m_base.m_data.m_uint8s[0], half_key_len_bytes, &keys[i][1 * half_key_len_hex], half_key_len_hex); mk_lang_assert(len == half_key_len_hex);
		len = mk_sl_cui_uint8_from_str_hex_many_n(&iv.m_data.m_base.m_data.m_uint8s[0], iv_len_bytes, &ivs[i][0], iv_len_hex); mk_lang_assert(len == iv_len_hex);
		mk_lib_crypto_mode_xts_aes_256_rw_set_key_enc(&alg, &key);
		mk_lib_crypto_mode_xts_aes_256_rw_set_iv(&alg, &iv);
		m = msgs_lens[i] / msg_len_hex;
		for(j = 0; j != m; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_many_n(&msg[j].m_data.m_base.m_data.m_uint8s[0], msg_len_bytes, &msgs[i][j * msg_len_hex], msg_len_hex); mk_lang_assert(len == msg_len_hex);
		}
		mk_lib_crypto_mode_xts_aes_256_rw_encrypt(&alg, &msg[0], &msg[0], ((mk_lang_types_usize_t)(m)));
		for(j = 0; j != m; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_many_n(&out.m_data.m_base.m_data.m_uint8s[0], msg_len_bytes, &outs[i][j * (msg_len_hex)], msg_len_hex); mk_lang_assert(len == (msg_len_hex));
			mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&msg[j].m_data.m_base.m_data.m_uint8s[0], &out.m_data.m_base.m_data.m_uint8s[0], ((mk_lang_types_usize_t)(msg_len_bytes))) == 0);
		}
		mk_lib_crypto_mode_xts_aes_256_rw_set_key_dec(&alg, &key);
		mk_lib_crypto_mode_xts_aes_256_rw_set_iv(&alg, &iv);
		mk_lib_crypto_mode_xts_aes_256_rw_decrypt(&alg, &msg[0], &msg[0], ((mk_lang_types_usize_t)(m)));
		for(j = 0; j != m; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_many_n(&out.m_data.m_base.m_data.m_uint8s[0], msg_len_bytes, &msgs[i][j * (msg_len_hex)], msg_len_hex); mk_lang_assert(len == (msg_len_hex));
			mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&msg[j].m_data.m_base.m_data.m_uint8s[0], &out.m_data.m_base.m_data.m_uint8s[0], ((mk_lang_types_usize_t)(msg_len_bytes))) == 0);
		}
	}

	#undef key_1
	#undef key_2
	#undef key_3
	#undef key_4
	#undef key_5

	#undef iv_1
	#undef iv_2
	#undef iv_3
	#undef iv_4
	#undef iv_5

	#undef msg_1
	#undef msg_2
	#undef msg_3
	#undef msg_4
	#undef msg_5

	#undef out_1
	#undef out_2
	#undef out_3
	#undef out_4
	#undef out_5
}


#include "mk_lang_warning_msvc_pop.h"


#endif
