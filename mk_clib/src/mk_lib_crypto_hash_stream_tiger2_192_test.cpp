#ifndef mk_include_guard_mk_lib_crypto_hash_stream_tiger2_192_test_cpp
#define mk_include_guard_mk_lib_crypto_hash_stream_tiger2_192_test_cpp


#if defined mk_lang_jumbo_want
#undef mk_lang_jumbo_want
#endif
#define mk_lang_jumbo_want 2


#include "mk_lang_warning_msvc_push_c4514.h"


#include "mk_lib_crypto_hash_stream_tiger2_192_test.hpp"

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
#include "mk_lib_crypto_hash_stream_tiger2_192.h"
#include "mk_sl_cui_uint8.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_hash_stream_tiger2_192_test_compute_from_str_lit(mk_lang_types_pchar_t const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, str_lit_len - 1> msg mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_tiger2_192_t tiger2_192 mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_tiger2_192_digest_t digest mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_hash_stream_tiger2_192_digest_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_len >= 1);

	msg = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(str_lit);
	mk_lib_crypto_hash_stream_tiger2_192_init(&tiger2_192);
	mk_lib_crypto_hash_stream_tiger2_192_append_u8s(&tiger2_192, msg.data(), msg.size());
	mk_lib_crypto_hash_stream_tiger2_192_finish(&tiger2_192, &digest);
	ret = mk_lib_cpp_constexpr_array_u8_from_u8s(digest.m_data.m_uint8s);
	return ret;
}

#endif


mk_lang_extern_force_c mk_lang_types_void_t mk_lib_crypto_hash_stream_tiger2_192_test(mk_lang_types_void_t) mk_lang_noexcept
{
	#define message_1 ""
	#define message_2 "a"
	#define message_3 "abc"
	#define message_4 "message digest"
	#define message_5 "abcdefghijklmnopqrstuvwxyz"
	#define message_6 "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"
	#define message_7 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
	#define message_8 "12345678901234567890123456789012345678901234567890123456789012345678901234567890"

	#define digest_1 "4441be75f6018773c206c22745374b924aa8313fef919f41"
	#define digest_2 "67e6ae8e9e968999f70a23e72aeaa9251cbc7c78a7916636"
	#define digest_3 "f68d7bc5af4b43a06e048d7829560d4a9415658bb0b1f3bf"
	#define digest_4 "e29419a1b5fa259de8005e7de75078ea81a542ef2552462d"
	#define digest_5 "f5b6b6a78c405c8547e91cd8624cb8be83fc804a474488fd"
	#define digest_6 "a6737f3997e8fbb63d20d2df88f86376b5fe2d5ce36646a9"
	#define digest_7 "ea9ab6228cee7b51b77544fca6066c8cbb5bbae6319505cd"
	#define digest_8 "d85278115329ebaa0eec85ecdc5396fda8aa3a5820942fff"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_digest_computed_1 = mk_lib_crypto_hash_stream_tiger2_192_test_compute_from_str_lit(message_1);
	mk_lang_constexpr_static auto const s_digest_computed_2 = mk_lib_crypto_hash_stream_tiger2_192_test_compute_from_str_lit(message_2);
	mk_lang_constexpr_static auto const s_digest_computed_3 = mk_lib_crypto_hash_stream_tiger2_192_test_compute_from_str_lit(message_3);
	mk_lang_constexpr_static auto const s_digest_computed_4 = mk_lib_crypto_hash_stream_tiger2_192_test_compute_from_str_lit(message_4);
	mk_lang_constexpr_static auto const s_digest_computed_5 = mk_lib_crypto_hash_stream_tiger2_192_test_compute_from_str_lit(message_5);
	mk_lang_constexpr_static auto const s_digest_computed_6 = mk_lib_crypto_hash_stream_tiger2_192_test_compute_from_str_lit(message_6);
	mk_lang_constexpr_static auto const s_digest_computed_7 = mk_lib_crypto_hash_stream_tiger2_192_test_compute_from_str_lit(message_7);
	mk_lang_constexpr_static auto const s_digest_computed_8 = mk_lib_crypto_hash_stream_tiger2_192_test_compute_from_str_lit(message_8);

	mk_lang_constexpr_static auto const s_digest_precomputed_1 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_1);
	mk_lang_constexpr_static auto const s_digest_precomputed_2 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_2);
	mk_lang_constexpr_static auto const s_digest_precomputed_3 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_3);
	mk_lang_constexpr_static auto const s_digest_precomputed_4 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_4);
	mk_lang_constexpr_static auto const s_digest_precomputed_5 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_5);
	mk_lang_constexpr_static auto const s_digest_precomputed_6 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_6);
	mk_lang_constexpr_static auto const s_digest_precomputed_7 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_7);
	mk_lang_constexpr_static auto const s_digest_precomputed_8 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_8);

	mk_lang_static_assert(s_digest_computed_1 == s_digest_precomputed_1);
	mk_lang_static_assert(s_digest_computed_2 == s_digest_precomputed_2);
	mk_lang_static_assert(s_digest_computed_3 == s_digest_precomputed_3);
	mk_lang_static_assert(s_digest_computed_4 == s_digest_precomputed_4);
	mk_lang_static_assert(s_digest_computed_5 == s_digest_precomputed_5);
	mk_lang_static_assert(s_digest_computed_6 == s_digest_precomputed_6);
	mk_lang_static_assert(s_digest_computed_7 == s_digest_precomputed_7);
	mk_lang_static_assert(s_digest_computed_8 == s_digest_precomputed_8);

	#endif

	mk_lang_types_pchar_pct const messages[] =
	{
		message_1,
		message_2,
		message_3,
		message_4,
		message_5,
		message_6,
		message_7,
		message_8,
	};

	mk_lang_types_sint_t const message_lens[] =
	{
		mk_lang_countstr(message_1),
		mk_lang_countstr(message_2),
		mk_lang_countstr(message_3),
		mk_lang_countstr(message_4),
		mk_lang_countstr(message_5),
		mk_lang_countstr(message_6),
		mk_lang_countstr(message_7),
		mk_lang_countstr(message_8),
	};

	mk_lang_types_pchar_pct const digests[] =
	{
		digest_1,
		digest_2,
		digest_3,
		digest_4,
		digest_5,
		digest_6,
		digest_7,
		digest_8,
	};

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_tiger2_192_t tiger2_192 mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_tiger2_192_digest_t digest mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(messages) == mk_lang_countof(digests));
	mk_lang_static_assert(mk_lang_countof(messages) == mk_lang_countof(message_lens));

	n = mk_lang_countof(messages);
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(message_lens[i] >= 0);
		mk_lib_crypto_hash_stream_tiger2_192_init(&tiger2_192);
		mk_lib_crypto_hash_stream_tiger2_192_append_u8s(&tiger2_192, ((mk_sl_cui_uint8_pct)(messages[i])), ((mk_lang_types_usize_t)(message_lens[i])));
		mk_lib_crypto_hash_stream_tiger2_192_finish(&tiger2_192, &digest);
		for(j = 0; j != mk_lib_crypto_hash_stream_tiger2_192_digest_len_v; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_n(&ta, &digests[i][j * 2], 2); mk_lang_assert(len == 2);
			mk_lang_test(mk_sl_cui_uint8_eq(&digest.m_data.m_uint8s[j], &ta));
		}
	}

	#undef message_1
	#undef message_2
	#undef message_3
	#undef message_4
	#undef message_5
	#undef message_6
	#undef message_7
	#undef message_8

	#undef digest_1
	#undef digest_2
	#undef digest_3
	#undef digest_4
	#undef digest_5
	#undef digest_6
	#undef digest_7
	#undef digest_8
}


#include "mk_lang_warning_msvc_pop.h"


#endif
