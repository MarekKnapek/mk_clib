#include "mk_lib_crypto_mode_gcm_be_aes_256_test.hpp"
#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpp.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr.hpp"
#include "mk_lib_crypto_mode_gcm_be_aes_256.h"
#include "mk_sl_uint8.h"

#define mk_lang_memcpy_t_name mk_lib_crypto_mode_gcm_be_aes_256_test_memcpyu8
#define mk_lang_memcpy_t_type mk_sl_cui_uint8_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t bytes_count>
struct mk_lib_crypto_mode_gcm_be_aes_256_test_crypt_result_s
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, bytes_count> m_bytes;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, 16> m_tag;
};

template<mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t iv_lit_len, mk_lang_types_usize_t aad_lit_len, mk_lang_types_usize_t msg_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_mode_gcm_be_aes_256_test_encrypt_from_str_lit(mk_lang_types_pchar_t const(&key_lit)[key_lit_len], mk_lang_types_pchar_t const(&iv_lit)[iv_lit_len], mk_lang_types_pchar_t const(&aad_lit)[aad_lit_len], mk_lang_types_pchar_t const(&msg_lit)[msg_lit_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_mode_gcm_be_aes_256_key_len_v> key_bytes mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (iv_lit_len - 1) / 2> iv_bytes mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (aad_lit_len - 1) / 2> aad_bytes mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (msg_lit_len - 1) / 2> msg_bytes mk_lang_constexpr_init;
	mk_lib_crypto_mode_gcm_be_aes_256_key_t key mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lib_crypto_mode_gcm_be_aes_256_msg_t, ((msg_lit_len - 1) / 2) / 16> msgs mk_lang_constexpr_init;
	mk_lib_crypto_mode_gcm_be_aes_256_t cipher mk_lang_constexpr_init;
	mk_lib_crypto_mode_gcm_be_aes_256_msg_t tag mk_lang_constexpr_init;
	mk_lib_crypto_mode_gcm_be_aes_256_test_crypt_result_s<(msg_lit_len - 1) / 2> ret mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == mk_lib_crypto_mode_gcm_be_aes_256_key_len_v * 2 + 1);

	key_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(key_lit);
	iv_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(iv_lit);
	aad_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(aad_lit);
	msg_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_lit);
	mk_lib_crypto_mode_gcm_be_aes_256_test_memcpyu8_fn(&key.m_data.m_data.m_uint8s[0], key_bytes.cdata(), key_bytes.size());
	n = msgs.size();
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_mode_gcm_be_aes_256_test_memcpyu8_fn(&msgs.data()[i].m_data.m_data.m_uint8s[0], msg_bytes.cdata() + i * 16, 16);
	}
	mk_lib_crypto_mode_gcm_be_aes_256_expand_enc(&cipher, &key);
	mk_lib_crypto_mode_gcm_be_aes_256_iv_append(&cipher, iv_bytes.cdata(), iv_bytes.size());
	mk_lib_crypto_mode_gcm_be_aes_256_iv_finish(&cipher);
	mk_lib_crypto_mode_gcm_be_aes_256_aad_append(&cipher, aad_bytes.cdata(), aad_bytes.size());
	mk_lib_crypto_mode_gcm_be_aes_256_aad_finish(&cipher);
	mk_lib_crypto_mode_gcm_be_aes_256_encrypt(&cipher, msgs.cdata(), msgs.data(), msgs.size());
	mk_lib_crypto_mode_gcm_be_aes_256_finish_enc(&cipher, msg_bytes.cdata() + msgs.size() * 16, msg_bytes.data() + msgs.size() * 16, msg_bytes.size() % 16, &tag);
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_mode_gcm_be_aes_256_test_memcpyu8_fn(msg_bytes.data() + i * 16, &msgs.cdata()[i].m_data.m_data.m_uint8s[0], 16);
	}
	ret.m_bytes = msg_bytes;
	mk_lib_crypto_mode_gcm_be_aes_256_test_memcpyu8_fn(ret.m_tag.data(), &tag.m_data.m_data.m_uint8s[0], 16);
	return ret;
}

template<mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t iv_lit_len, mk_lang_types_usize_t aad_lit_len, mk_lang_types_usize_t msg_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_mode_gcm_be_aes_256_test_decrypt_from_str_lit(mk_lang_types_pchar_t const(&key_lit)[key_lit_len], mk_lang_types_pchar_t const(&iv_lit)[iv_lit_len], mk_lang_types_pchar_t const(&aad_lit)[aad_lit_len], mk_lang_types_pchar_t const(&msg_lit)[msg_lit_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_mode_gcm_be_aes_256_key_len_v> key_bytes mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (iv_lit_len - 1) / 2> iv_bytes mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (aad_lit_len - 1) / 2> aad_bytes mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (msg_lit_len - 1) / 2> msg_bytes mk_lang_constexpr_init;
	mk_lib_crypto_mode_gcm_be_aes_256_key_t key mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lib_crypto_mode_gcm_be_aes_256_msg_t, ((msg_lit_len - 1) / 2) / 16> msgs mk_lang_constexpr_init;
	mk_lib_crypto_mode_gcm_be_aes_256_t cipher mk_lang_constexpr_init;
	mk_lib_crypto_mode_gcm_be_aes_256_msg_t tag mk_lang_constexpr_init;
	mk_lib_crypto_mode_gcm_be_aes_256_test_crypt_result_s<(msg_lit_len - 1) / 2> ret mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == mk_lib_crypto_mode_gcm_be_aes_256_key_len_v * 2 + 1);

	key_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(key_lit);
	iv_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(iv_lit);
	aad_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(aad_lit);
	msg_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_lit);
	mk_lib_crypto_mode_gcm_be_aes_256_test_memcpyu8_fn(&key.m_data.m_data.m_uint8s[0], key_bytes.cdata(), key_bytes.size());
	n = msgs.size();
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_mode_gcm_be_aes_256_test_memcpyu8_fn(&msgs.data()[i].m_data.m_data.m_uint8s[0], msg_bytes.cdata() + i * 16, 16);
	}
	mk_lib_crypto_mode_gcm_be_aes_256_expand_dec(&cipher, &key);
	mk_lib_crypto_mode_gcm_be_aes_256_iv_append(&cipher, iv_bytes.cdata(), iv_bytes.size());
	mk_lib_crypto_mode_gcm_be_aes_256_iv_finish(&cipher);
	mk_lib_crypto_mode_gcm_be_aes_256_aad_append(&cipher, aad_bytes.cdata(), aad_bytes.size());
	mk_lib_crypto_mode_gcm_be_aes_256_aad_finish(&cipher);
	mk_lib_crypto_mode_gcm_be_aes_256_decrypt(&cipher, msgs.cdata(), msgs.data(), msgs.size());
	mk_lib_crypto_mode_gcm_be_aes_256_finish_dec(&cipher, msg_bytes.cdata() + msgs.size() * 16, msg_bytes.data() + msgs.size() * 16, msg_bytes.size() % 16, &tag);
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_mode_gcm_be_aes_256_test_memcpyu8_fn(msg_bytes.data() + i * 16, &msgs.cdata()[i].m_data.m_data.m_uint8s[0], 16);
	}
	ret.m_bytes = msg_bytes;
	mk_lib_crypto_mode_gcm_be_aes_256_test_memcpyu8_fn(ret.m_tag.data(), &tag.m_data.m_data.m_uint8s[0], 16);
	return ret;
}

#endif


mk_lang_extern_c mk_lang_types_void_t mk_lib_crypto_mode_gcm_be_aes_256_test(mk_lang_types_void_t) mk_lang_noexcept
{
	#define key_1 "0000000000000000000000000000000000000000000000000000000000000000"
	#define key_2 "0000000000000000000000000000000000000000000000000000000000000000"
	#define key_3 "feffe9928665731c6d6a8f9467308308feffe9928665731c6d6a8f9467308308"
	#define key_4 "feffe9928665731c6d6a8f9467308308feffe9928665731c6d6a8f9467308308"
	#define key_5 "feffe9928665731c6d6a8f9467308308feffe9928665731c6d6a8f9467308308"
	#define key_6 "feffe9928665731c6d6a8f9467308308feffe9928665731c6d6a8f9467308308"

	#define iv_1 "000000000000000000000000"
	#define iv_2 "000000000000000000000000"
	#define iv_3 "cafebabefacedbaddecaf888"
	#define iv_4 "cafebabefacedbaddecaf888"
	#define iv_5 "cafebabefacedbad"
	#define iv_6 "9313225df88406e555909c5aff5269aa6a7a9538534f7da1e4c303d2a318a728c3c0c95156809539fcf0e2429a6b525416aedbf5a0de6a57a637b39b"

	#define aad_1 ""
	#define aad_2 ""
	#define aad_3 ""
	#define aad_4 "feedfacedeadbeeffeedfacedeadbeefabaddad2"
	#define aad_5 "feedfacedeadbeeffeedfacedeadbeefabaddad2"
	#define aad_6 "feedfacedeadbeeffeedfacedeadbeefabaddad2"

	#define msg_1 ""
	#define msg_2 "00000000000000000000000000000000"
	#define msg_3 "d9313225f88406e5a55909c5aff5269a86a7a9531534f7da2e4c303d8a318a721c3c0c95956809532fcf0e2449a6b525b16aedf5aa0de657ba637b391aafd255"
	#define msg_4 "d9313225f88406e5a55909c5aff5269a86a7a9531534f7da2e4c303d8a318a721c3c0c95956809532fcf0e2449a6b525b16aedf5aa0de657ba637b39"
	#define msg_5 "d9313225f88406e5a55909c5aff5269a86a7a9531534f7da2e4c303d8a318a721c3c0c95956809532fcf0e2449a6b525b16aedf5aa0de657ba637b39"
	#define msg_6 "d9313225f88406e5a55909c5aff5269a86a7a9531534f7da2e4c303d8a318a721c3c0c95956809532fcf0e2449a6b525b16aedf5aa0de657ba637b39"

	#define out_1 ""
	#define out_2 "cea7403d4d606b6e074ec5d3baf39d18"
	#define out_3 "522dc1f099567d07f47f37a32a84427d643a8cdcbfe5c0c97598a2bd2555d1aa8cb08e48590dbb3da7b08b1056828838c5f61e6393ba7a0abcc9f662898015ad"
	#define out_4 "522dc1f099567d07f47f37a32a84427d643a8cdcbfe5c0c97598a2bd2555d1aa8cb08e48590dbb3da7b08b1056828838c5f61e6393ba7a0abcc9f662"
	#define out_5 "c3762df1ca787d32ae47c13bf19844cbaf1ae14d0b976afac52ff7d79bba9de0feb582d33934a4f0954cc2363bc73f7862ac430e64abe499f47c9b1f"
	#define out_6 "5a8def2f0c9e53f1f75d7853659e2a20eeb2b22aafde6419a058ab4f6f746bf40fc0c3b780f244452da3ebf1c5d82cdea2418997200ef82e44ae7e3f"

	#define tag_1 "530f8afbc74536b9a963b4f1c4cb738b"
	#define tag_2 "d0d1c8a799996bf0265b98b5d48ab919"
	#define tag_3 "b094dac5d93471bdec1a502270e3cc6c"
	#define tag_4 "76fc6ece0f4e1768cddf8853bb2d551b"
	#define tag_5 "3a337dbf46a792c45e454913fe2ea8f2"
	#define tag_6 "a44a8266ee1c8eb0c8b5d4cf5ae9f19a"


	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_msg_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_1);
	mk_lang_constexpr_static auto const s_msg_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_2);
	mk_lang_constexpr_static auto const s_msg_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_3);
	mk_lang_constexpr_static auto const s_msg_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_4);
	mk_lang_constexpr_static auto const s_msg_precomputed_5 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_5);
	mk_lang_constexpr_static auto const s_msg_precomputed_6 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_6);

	mk_lang_constexpr_static auto const s_out_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_1);
	mk_lang_constexpr_static auto const s_out_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_2);
	mk_lang_constexpr_static auto const s_out_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_3);
	mk_lang_constexpr_static auto const s_out_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_4);
	mk_lang_constexpr_static auto const s_out_precomputed_5 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_5);
	mk_lang_constexpr_static auto const s_out_precomputed_6 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_6);

	mk_lang_constexpr_static auto const s_tag_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(tag_1);
	mk_lang_constexpr_static auto const s_tag_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(tag_2);
	mk_lang_constexpr_static auto const s_tag_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(tag_3);
	mk_lang_constexpr_static auto const s_tag_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(tag_4);
	mk_lang_constexpr_static auto const s_tag_precomputed_5 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(tag_5);
	mk_lang_constexpr_static auto const s_tag_precomputed_6 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(tag_6);

	mk_lang_constexpr_static auto const s_out_computed_1 = mk_lib_crypto_mode_gcm_be_aes_256_test_encrypt_from_str_lit(key_1, iv_1, aad_1, msg_1);
	mk_lang_constexpr_static auto const s_out_computed_2 = mk_lib_crypto_mode_gcm_be_aes_256_test_encrypt_from_str_lit(key_2, iv_2, aad_2, msg_2);
	mk_lang_constexpr_static auto const s_out_computed_3 = mk_lib_crypto_mode_gcm_be_aes_256_test_encrypt_from_str_lit(key_3, iv_3, aad_3, msg_3);
	mk_lang_constexpr_static auto const s_out_computed_4 = mk_lib_crypto_mode_gcm_be_aes_256_test_encrypt_from_str_lit(key_4, iv_4, aad_4, msg_4);
	mk_lang_constexpr_static auto const s_out_computed_5 = mk_lib_crypto_mode_gcm_be_aes_256_test_encrypt_from_str_lit(key_5, iv_5, aad_5, msg_5);
	mk_lang_constexpr_static auto const s_out_computed_6 = mk_lib_crypto_mode_gcm_be_aes_256_test_encrypt_from_str_lit(key_6, iv_6, aad_6, msg_6);

	mk_lang_constexpr_static auto const s_msg_computed_1 = mk_lib_crypto_mode_gcm_be_aes_256_test_decrypt_from_str_lit(key_1, iv_1, aad_1, out_1);
	mk_lang_constexpr_static auto const s_msg_computed_2 = mk_lib_crypto_mode_gcm_be_aes_256_test_decrypt_from_str_lit(key_2, iv_2, aad_2, out_2);
	mk_lang_constexpr_static auto const s_msg_computed_3 = mk_lib_crypto_mode_gcm_be_aes_256_test_decrypt_from_str_lit(key_3, iv_3, aad_3, out_3);
	mk_lang_constexpr_static auto const s_msg_computed_4 = mk_lib_crypto_mode_gcm_be_aes_256_test_decrypt_from_str_lit(key_4, iv_4, aad_4, out_4);
	mk_lang_constexpr_static auto const s_msg_computed_5 = mk_lib_crypto_mode_gcm_be_aes_256_test_decrypt_from_str_lit(key_5, iv_5, aad_5, out_5);
	mk_lang_constexpr_static auto const s_msg_computed_6 = mk_lib_crypto_mode_gcm_be_aes_256_test_decrypt_from_str_lit(key_6, iv_6, aad_6, out_6);

	mk_lang_static_assert(s_out_computed_1.m_bytes == s_out_precomputed_1);
	mk_lang_static_assert(s_out_computed_2.m_bytes == s_out_precomputed_2);
	mk_lang_static_assert(s_out_computed_3.m_bytes == s_out_precomputed_3);
	mk_lang_static_assert(s_out_computed_4.m_bytes == s_out_precomputed_4);
	mk_lang_static_assert(s_out_computed_5.m_bytes == s_out_precomputed_5);
	mk_lang_static_assert(s_out_computed_6.m_bytes == s_out_precomputed_6);

	mk_lang_static_assert(s_out_computed_1.m_tag == s_tag_precomputed_1);
	mk_lang_static_assert(s_out_computed_2.m_tag == s_tag_precomputed_2);
	mk_lang_static_assert(s_out_computed_3.m_tag == s_tag_precomputed_3);
	mk_lang_static_assert(s_out_computed_4.m_tag == s_tag_precomputed_4);
	mk_lang_static_assert(s_out_computed_5.m_tag == s_tag_precomputed_5);
	mk_lang_static_assert(s_out_computed_6.m_tag == s_tag_precomputed_6);

	mk_lang_static_assert(s_msg_computed_1.m_bytes == s_msg_precomputed_1);
	mk_lang_static_assert(s_msg_computed_2.m_bytes == s_msg_precomputed_2);
	mk_lang_static_assert(s_msg_computed_3.m_bytes == s_msg_precomputed_3);
	mk_lang_static_assert(s_msg_computed_4.m_bytes == s_msg_precomputed_4);
	mk_lang_static_assert(s_msg_computed_5.m_bytes == s_msg_precomputed_5);
	mk_lang_static_assert(s_msg_computed_6.m_bytes == s_msg_precomputed_6);

	mk_lang_static_assert(s_msg_computed_1.m_tag == s_tag_precomputed_1);
	mk_lang_static_assert(s_msg_computed_2.m_tag == s_tag_precomputed_2);
	mk_lang_static_assert(s_msg_computed_3.m_tag == s_tag_precomputed_3);
	mk_lang_static_assert(s_msg_computed_4.m_tag == s_tag_precomputed_4);
	mk_lang_static_assert(s_msg_computed_5.m_tag == s_tag_precomputed_5);
	mk_lang_static_assert(s_msg_computed_6.m_tag == s_tag_precomputed_6);

	#endif


	static mk_lang_types_pchar_pct const s_keys[] =
	{
		key_1,
		key_2,
		key_3,
		key_4,
		key_5,
		key_6,
	};

	static mk_lang_types_pchar_pct const s_ivs[] =
	{
		iv_1,
		iv_2,
		iv_3,
		iv_4,
		iv_5,
		iv_6,
	};

	static mk_lang_types_sint_t const s_iv_lens[] =
	{
		mk_lang_countstr(iv_1),
		mk_lang_countstr(iv_2),
		mk_lang_countstr(iv_3),
		mk_lang_countstr(iv_4),
		mk_lang_countstr(iv_5),
		mk_lang_countstr(iv_6),
	};

	static mk_lang_types_pchar_pct const s_aads[] =
	{
		aad_1,
		aad_2,
		aad_3,
		aad_4,
		aad_5,
		aad_6,
	};

	static mk_lang_types_sint_t const s_aad_lens[] =
	{
		mk_lang_countstr(aad_1),
		mk_lang_countstr(aad_2),
		mk_lang_countstr(aad_3),
		mk_lang_countstr(aad_4),
		mk_lang_countstr(aad_5),
		mk_lang_countstr(aad_6),
	};

	static mk_lang_types_pchar_pct const s_msgs[] =
	{
		msg_1,
		msg_2,
		msg_3,
		msg_4,
		msg_5,
		msg_6,
	};

	static mk_lang_types_sint_t const s_msg_lens[] =
	{
		mk_lang_countstr(msg_1),
		mk_lang_countstr(msg_2),
		mk_lang_countstr(msg_3),
		mk_lang_countstr(msg_4),
		mk_lang_countstr(msg_5),
		mk_lang_countstr(msg_6),
	};

	static mk_lang_types_pchar_pct const s_outs[] =
	{
		out_1,
		out_2,
		out_3,
		out_4,
		out_5,
		out_6,
	};

	static mk_lang_types_pchar_pct const s_tags[] =
	{
		tag_1,
		tag_2,
		tag_3,
		tag_4,
		tag_5,
		tag_6,
	};


	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t j;
	mk_lang_types_uchar_t hi;
	mk_lang_types_uchar_t lo;
	mk_lang_types_uchar_t byte;
	mk_lib_crypto_mode_gcm_be_aes_256_key_t key;
	mk_lib_crypto_mode_gcm_be_aes_256_t cipher;
	mk_lang_types_sint_t m;
	mk_sl_cui_uint8_t u8;
	mk_lang_types_sint_t k;
	mk_lib_crypto_mode_gcm_be_aes_256_msg_t msg;
	mk_lib_crypto_mode_gcm_be_aes_256_msg_t tag;

	mk_lang_static_assert(mk_lang_countof(s_keys) == mk_lang_countof(s_ivs));
	mk_lang_static_assert(mk_lang_countof(s_keys) == mk_lang_countof(s_iv_lens));
	mk_lang_static_assert(mk_lang_countof(s_keys) == mk_lang_countof(s_aads));
	mk_lang_static_assert(mk_lang_countof(s_keys) == mk_lang_countof(s_aad_lens));
	mk_lang_static_assert(mk_lang_countof(s_keys) == mk_lang_countof(s_msgs));
	mk_lang_static_assert(mk_lang_countof(s_keys) == mk_lang_countof(s_msg_lens));
	mk_lang_static_assert(mk_lang_countof(s_keys) == mk_lang_countof(s_outs));
	mk_lang_static_assert(mk_lang_countof(s_keys) == mk_lang_countof(s_tags));
	mk_lang_static_assert(mk_lib_crypto_mode_gcm_be_aes_256_msg_len_v == 16);

	mk_lang_cpuid_init();
	n = ((mk_lang_types_sint_t)(mk_lang_countof(s_keys)));
	for(i = 0; i != n; ++i)
	{
		{
			for(j = 0; j != mk_lib_crypto_mode_gcm_be_aes_256_key_len_v; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&key.m_data.m_data.m_uint8s[j], &byte);
			}
			mk_lib_crypto_mode_gcm_be_aes_256_expand_enc(&cipher, &key);
			mk_lang_test(s_iv_lens[i] % 2 == 0);
			m = s_iv_lens[i] / 2;
			for(j = 0; j != m; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_ivs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_ivs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
				mk_lib_crypto_mode_gcm_be_aes_256_iv_append(&cipher, &u8, 1);
			}
			mk_lib_crypto_mode_gcm_be_aes_256_iv_finish(&cipher);
			mk_lang_test(s_aad_lens[i] % 2 == 0);
			m = s_aad_lens[i] / 2;
			for(j = 0; j != m; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_aads[i][j * 2 + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_aads[i][j * 2 + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
				mk_lib_crypto_mode_gcm_be_aes_256_aad_append(&cipher, &u8, 1);
			}
			mk_lib_crypto_mode_gcm_be_aes_256_aad_finish(&cipher);
			mk_lang_test(s_msg_lens[i] % 2 == 0);
			m = s_msg_lens[i] / 2;
			for(j = 0; j != m / 16; ++j)
			{
				for(k = 0; k != 16; ++k)
				{
					hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(j * 16 + k) * 2 + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
					lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(j * 16 + k) * 2 + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
					byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
					mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
					msg.m_data.m_data.m_uint8s[k] = u8;
				}
				mk_lib_crypto_mode_gcm_be_aes_256_encrypt(&cipher, &msg, &msg, 1);
				for(k = 0; k != 16; ++k)
				{
					hi = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(j * 16 + k) * 2 + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
					lo = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(j * 16 + k) * 2 + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
					byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
					mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
					mk_lang_test(mk_sl_cui_uint8_eq(&msg.m_data.m_data.m_uint8s[k], &u8));
				}
			}
			for(k = 0; k != m % 16; ++k)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(j * 16 + k) * 2 + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(j * 16 + k) * 2 + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
				msg.m_data.m_data.m_uint8s[k] = u8;
			}
			mk_lib_crypto_mode_gcm_be_aes_256_finish_enc(&cipher, &msg.m_data.m_data.m_uint8s[0], &msg.m_data.m_data.m_uint8s[0], m % 16, &tag);
			for(k = 0; k != m % 16; ++k)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(j * 16 + k) * 2 + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(j * 16 + k) * 2 + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
				mk_lang_test(mk_sl_cui_uint8_eq(&msg.m_data.m_data.m_uint8s[k], &u8));
			}
			for(j = 0; j != mk_lib_crypto_mode_gcm_be_aes_256_msg_len_v; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_tags[i][(j * 2) + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_tags[i][(j * 2) + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
				mk_lang_test(mk_sl_cui_uint8_eq(&tag.m_data.m_data.m_uint8s[j], &u8));
			}
		}
		{
			for(j = 0; j != mk_lib_crypto_mode_gcm_be_aes_256_key_len_v; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&key.m_data.m_data.m_uint8s[j], &byte);
			}
			mk_lib_crypto_mode_gcm_be_aes_256_expand_dec(&cipher, &key);
			mk_lang_test(s_iv_lens[i] % 2 == 0);
			m = s_iv_lens[i] / 2;
			for(j = 0; j != m; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_ivs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_ivs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
				mk_lib_crypto_mode_gcm_be_aes_256_iv_append(&cipher, &u8, 1);
			}
			mk_lib_crypto_mode_gcm_be_aes_256_iv_finish(&cipher);
			mk_lang_test(s_aad_lens[i] % 2 == 0);
			m = s_aad_lens[i] / 2;
			for(j = 0; j != m; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_aads[i][j * 2 + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_aads[i][j * 2 + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
				mk_lib_crypto_mode_gcm_be_aes_256_aad_append(&cipher, &u8, 1);
			}
			mk_lib_crypto_mode_gcm_be_aes_256_aad_finish(&cipher);
			mk_lang_test(s_msg_lens[i] % 2 == 0);
			m = s_msg_lens[i] / 2;
			for(j = 0; j != m / 16; ++j)
			{
				for(k = 0; k != 16; ++k)
				{
					hi = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(j * 16 + k) * 2 + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
					lo = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(j * 16 + k) * 2 + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
					byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
					mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
					msg.m_data.m_data.m_uint8s[k] = u8;
				}
				mk_lib_crypto_mode_gcm_be_aes_256_decrypt(&cipher, &msg, &msg, 1);
				for(k = 0; k != 16; ++k)
				{
					hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(j * 16 + k) * 2 + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
					lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(j * 16 + k) * 2 + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
					byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
					mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
					mk_lang_test(mk_sl_cui_uint8_eq(&msg.m_data.m_data.m_uint8s[k], &u8));
				}
			}
			for(k = 0; k != m % 16; ++k)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(j * 16 + k) * 2 + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(j * 16 + k) * 2 + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
				msg.m_data.m_data.m_uint8s[k] = u8;
			}
			mk_lib_crypto_mode_gcm_be_aes_256_finish_dec(&cipher, &msg.m_data.m_data.m_uint8s[0], &msg.m_data.m_data.m_uint8s[0], m % 16, &tag);
			for(k = 0; k != m % 16; ++k)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(j * 16 + k) * 2 + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(j * 16 + k) * 2 + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
				mk_lang_test(mk_sl_cui_uint8_eq(&msg.m_data.m_data.m_uint8s[k], &u8));
			}
			for(j = 0; j != mk_lib_crypto_mode_gcm_be_aes_256_msg_len_v; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_tags[i][(j * 2) + 0]); mk_lang_assert(hi >= 0x00 && hi <= 0x0f);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_tags[i][(j * 2) + 1]); mk_lang_assert(lo >= 0x00 && lo <= 0x0f);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
				mk_lang_test(mk_sl_cui_uint8_eq(&tag.m_data.m_data.m_uint8s[j], &u8));
			}
		}
	}

	#undef key_1
	#undef key_2
	#undef key_3
	#undef key_4
	#undef key_5
	#undef key_6

	#undef iv_1
	#undef iv_2
	#undef iv_3
	#undef iv_4
	#undef iv_5
	#undef iv_6

	#undef aad_1
	#undef aad_2
	#undef aad_3
	#undef aad_4
	#undef aad_5
	#undef aad_6

	#undef msg_1
	#undef msg_2
	#undef msg_3
	#undef msg_4
	#undef msg_5
	#undef msg_6

	#undef out_1
	#undef out_2
	#undef out_3
	#undef out_4
	#undef out_5
	#undef out_6

	#undef tag_1
	#undef tag_2
	#undef tag_3
	#undef tag_4
	#undef tag_5
	#undef tag_6
}
