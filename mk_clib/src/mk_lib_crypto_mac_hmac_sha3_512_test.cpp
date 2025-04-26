#ifndef mk_include_guard_mk_lib_crypto_mac_hmac_sha3_512_test_cpp
#define mk_include_guard_mk_lib_crypto_mac_hmac_sha3_512_test_cpp


#if defined mk_lang_jumbo_want
#undef mk_lang_jumbo_want
#endif
#define mk_lang_jumbo_want 2


#include "mk_lang_warning_msvc_push_c4514.h"


#include "mk_lib_crypto_mac_hmac_sha3_512_test.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr_array_u8.hpp"
#include "mk_lib_crypto_mac_hmac_sha3_512.h"
#include "mk_sl_cui_uint8.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t mac_len, mk_lang_types_usize_t msg_str_lit_len, mk_lang_types_usize_t key_str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_mac_hmac_sha3_512_test_compute_from_str_lit(mk_lang_types_pchar_t const(&msg_str_lit)[msg_str_lit_len], mk_lang_types_pchar_t const(&key_str_lit)[key_str_lit_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, msg_str_lit_len - 1> msg mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (key_str_lit_len - 1) / 2> key mk_lang_constexpr_init;
	mk_lib_crypto_mac_hmac_sha3_512_t hmac mk_lang_constexpr_init;
	mk_lib_crypto_mac_hmac_sha3_512_digest_t digest mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mac_len> ret mk_lang_constexpr_init;

	mk_lang_static_assert(mac_len >= 1);
	mk_lang_static_assert(mac_len <= mk_lib_crypto_mac_hmac_sha3_512_digest_len_v);
	mk_lang_static_assert(msg_str_lit_len >= 1);
	mk_lang_static_assert(key_str_lit_len >= 1);
	mk_lang_static_assert((key_str_lit_len - 1) % 2 == 0);

	msg = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(msg_str_lit);
	key = mk_lib_cpp_constexpr_array_u8_from_hex_lit(key_str_lit);
	mk_lib_crypto_mac_hmac_sha3_512_init(&hmac, key.data(), key.size());
	mk_lib_crypto_mac_hmac_sha3_512_append(&hmac, msg.data(), msg.size());
	mk_lib_crypto_mac_hmac_sha3_512_finish(&hmac, &digest);
	mk_sl_cui_uint8_memcpy_fn(ret.data(), &digest.m_data.m_uint8s[0], mac_len);
	return ret;
}

#endif


mk_lang_extern_force_c mk_lang_types_void_t mk_lib_crypto_mac_hmac_sha3_512_test(mk_lang_types_void_t) mk_lang_noexcept
{
	#define msg_1 "Sample message for keylen<blocklen"
	#define msg_2 "Sample message for keylen=blocklen"
	#define msg_3 "Sample message for keylen>blocklen"
	#define msg_4 "Sample message for keylen<blocklen, with truncated tag"

	#define key_1 "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f"
	#define key_2 "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f4041424344454647"
	#define key_3 "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f8081828384858687"
	#define key_4 "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f"

	#define mac_1 "4efd629d6c71bf86162658f29943b1c308ce27cdfa6db0d9c3ce81763f9cbce5f7ebe9868031db1a8f8eb7b6b95e5c5e3f657a8996c86a2f6527e307f0213196"
	#define mac_2 "544e257ea2a3e5ea19a590e6a24b724ce6327757723fe2751b75bf007d80f6b360744bf1b7a88ea585f9765b47911976d3191cf83c039f5ffab0d29cc9d9b6da"
	#define mac_3 "5f464f5e5b7848e3885e49b2c385f0694985d0e38966242dc4a5fe3fea4b37d46b65ceced5dcf59438dd840bab22269f0ba7febdb9fcf74602a35666b2a32915"
	#define mac_4 "7bb06d859257b25ce73ca700df34c5cbef5c898bac91029e0b27975d4e526a08"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_mac_computed_1 = mk_lib_crypto_mac_hmac_sha3_512_test_compute_from_str_lit<mk_lang_countstr(mac_1) / 2>(msg_1, key_1);
	mk_lang_constexpr_static auto const s_mac_computed_2 = mk_lib_crypto_mac_hmac_sha3_512_test_compute_from_str_lit<mk_lang_countstr(mac_2) / 2>(msg_2, key_2);
	mk_lang_constexpr_static auto const s_mac_computed_3 = mk_lib_crypto_mac_hmac_sha3_512_test_compute_from_str_lit<mk_lang_countstr(mac_3) / 2>(msg_3, key_3);
	mk_lang_constexpr_static auto const s_mac_computed_4 = mk_lib_crypto_mac_hmac_sha3_512_test_compute_from_str_lit<mk_lang_countstr(mac_4) / 2>(msg_4, key_4);

	mk_lang_constexpr_static auto const s_mac_precomputed_1 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(mac_1);
	mk_lang_constexpr_static auto const s_mac_precomputed_2 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(mac_2);
	mk_lang_constexpr_static auto const s_mac_precomputed_3 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(mac_3);
	mk_lang_constexpr_static auto const s_mac_precomputed_4 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(mac_4);

	mk_lang_static_assert(s_mac_computed_1 == s_mac_precomputed_1);
	mk_lang_static_assert(s_mac_computed_2 == s_mac_precomputed_2);
	mk_lang_static_assert(s_mac_computed_3 == s_mac_precomputed_3);
	mk_lang_static_assert(s_mac_computed_4 == s_mac_precomputed_4);

	#endif

	mk_lang_types_pchar_pct const msgs[] =
	{
		msg_1,
		msg_2,
		msg_3,
		msg_4,
	};

	mk_lang_types_sint_t const msg_lens[] =
	{
		mk_lang_countstr(msg_1),
		mk_lang_countstr(msg_2),
		mk_lang_countstr(msg_3),
		mk_lang_countstr(msg_4),
	};

	mk_lang_types_pchar_pct const keys[] =
	{
		key_1,
		key_2,
		key_3,
		key_4,
	};

	mk_lang_types_sint_t const key_lens[] =
	{
		mk_lang_countstr(key_1) / 2,
		mk_lang_countstr(key_2) / 2,
		mk_lang_countstr(key_3) / 2,
		mk_lang_countstr(key_4) / 2,
	};

	mk_lang_types_pchar_pct const macs[] =
	{
		mac_1,
		mac_2,
		mac_3,
		mac_4,
	};

	mk_lang_types_sint_t const mac_lens[] =
	{
		mk_lang_countstr(mac_1) / 2,
		mk_lang_countstr(mac_2) / 2,
		mk_lang_countstr(mac_3) / 2,
		mk_lang_countstr(mac_4) / 2,
	};

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_sl_cui_uint8_t key[512] mk_lang_constexpr_init;
	mk_lib_crypto_mac_hmac_sha3_512_t hmac mk_lang_constexpr_init;
	mk_lib_crypto_mac_hmac_sha3_512_digest_t digest mk_lang_constexpr_init;
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(msgs) == mk_lang_countof(msg_lens));
	mk_lang_static_assert(mk_lang_countof(msgs) == mk_lang_countof(keys));
	mk_lang_static_assert(mk_lang_countof(msgs) == mk_lang_countof(key_lens));
	mk_lang_static_assert(mk_lang_countof(msgs) == mk_lang_countof(macs));
	mk_lang_static_assert(mk_lang_countof(msgs) == mk_lang_countof(mac_lens));

	n = mk_lang_countof(msgs);
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(msg_lens[i] >= 0);
		mk_lang_assert(key_lens[i] >= 0);
		mk_lang_assert(key_lens[i] <= mk_lang_countof(key));
		mk_lang_assert(mac_lens[i] >= 1);
		mk_lang_assert(mac_lens[i] <= mk_lib_crypto_mac_hmac_sha3_512_digest_len_v);
		len = mk_sl_cui_uint8_from_str_hex_many_n(&key[0], key_lens[i], &keys[i][0], key_lens[i] * mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == key_lens[i] * mk_sl_cui_uint8_strlen_hex_v);
		mk_lib_crypto_mac_hmac_sha3_512_init(&hmac, &key[0], ((mk_lang_types_usize_t)(key_lens[i])));
		mk_lib_crypto_mac_hmac_sha3_512_append(&hmac, ((mk_sl_cui_uint8_pct)(msgs[i])), ((mk_lang_types_usize_t)(msg_lens[i])));
		mk_lib_crypto_mac_hmac_sha3_512_finish(&hmac, &digest);
		m = mac_lens[i];
		for(j = 0; j != m; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_n(&ta, &macs[i][j * mk_sl_cui_uint8_strlen_hex_v], mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == mk_sl_cui_uint8_strlen_hex_v);
			mk_lang_test(mk_sl_cui_uint8_eq(&digest.m_data.m_uint8s[j], &ta));
		}
	}

	#undef msg_1
	#undef msg_2
	#undef msg_3
	#undef msg_4

	#undef key_1
	#undef key_2
	#undef key_3
	#undef key_4

	#undef mac_1
	#undef mac_2
	#undef mac_3
	#undef mac_4
}


#include "mk_lang_warning_msvc_pop.h"


#endif
