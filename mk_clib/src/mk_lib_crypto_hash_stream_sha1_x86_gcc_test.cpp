#include "mk_lib_crypto_hash_stream_sha1_x86_gcc_test.hpp"
#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1

#include "mk_lang_arch.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpp.h"
#include "mk_lang_gnuc.h"
#include "mk_lang_noexcept.h"

#if !mk_lang_constexpr_is_constant_evaluated && mk_lang_gnuc_is_at_least(11, 1) && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)

#include "mk_lang_assert.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr.hpp"
#include "mk_lib_crypto_hash_stream_sha1_x86_gcc.h"
#include "mk_sl_uint8.h"


mk_lang_extern_c void mk_lib_crypto_hash_stream_sha1_x86_gcc_test(void) mk_lang_noexcept
{
	#define message_1 ""
	#define message_2 "a"
	#define message_3 "abc"
	#define message_4 "message digest"
	#define message_5 "abcdefghijklmnopqrstuvwxyz"
	#define message_6 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
	#define message_7 "12345678901234567890123456789012345678901234567890123456789012345678901234567890"
	#define message_8 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

	#define digest_1 "da39a3ee5e6b4b0d3255bfef95601890afd80709"
	#define digest_2 "86f7e437faa5a7fce15d1ddcb9eaeaea377667b8"
	#define digest_3 "a9993e364706816aba3e25717850c26c9cd0d89d"
	#define digest_4 "c12252ceda8be8994d5fa0290a47231c1d16aae3"
	#define digest_5 "32d10c7b8cf96570ca04ce37f2a19d84240d3a89"
	#define digest_6 "761c457bf73b14d27e9e9265c46f4b4dda11f940"
	#define digest_7 "50abf5706a150990a08b2c5ea40fa0e585554732"
	#define digest_8 "003ef1ba9ea9f2f4dab3a2004e505ca8a4e7e5a3"

	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_crash(); } ((void)(0))

	static char const* const s_messages[] =
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

	static int const s_message_lens[] =
	{
		((int)(sizeof(message_1) / sizeof(message_1[0]) - 1)),
		((int)(sizeof(message_2) / sizeof(message_2[0]) - 1)),
		((int)(sizeof(message_3) / sizeof(message_3[0]) - 1)),
		((int)(sizeof(message_4) / sizeof(message_4[0]) - 1)),
		((int)(sizeof(message_5) / sizeof(message_5[0]) - 1)),
		((int)(sizeof(message_6) / sizeof(message_6[0]) - 1)),
		((int)(sizeof(message_7) / sizeof(message_7[0]) - 1)),
		((int)(sizeof(message_8) / sizeof(message_8[0]) - 1)),
	};

	static char const* const s_digests[] =
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

	int n;
	int i;
	mk_lib_crypto_hash_stream_sha1_x86_gcc_t sha1;
	mk_lib_crypto_hash_block_sha1_x86_gcc_digest_t digest;
	int j;
	mk_lang_types_uchar_t hi;
	mk_lang_types_uchar_t lo;
	mk_lang_types_uchar_t byte;
	mk_lang_types_uchar_t ta;

	mk_lang_static_assert(sizeof(s_messages) / sizeof(s_messages[0]) == sizeof(s_digests) / sizeof(s_digests[0]));
	mk_lang_static_assert(sizeof(s_messages) / sizeof(s_messages[0]) == sizeof(s_message_lens) / sizeof(s_message_lens[0]));

	n = ((int)(sizeof(s_messages) / sizeof(s_messages[0])));
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(s_message_lens[i] >= 0);
		mk_lib_crypto_hash_stream_sha1_x86_gcc_init(&sha1);
		mk_lib_crypto_hash_stream_sha1_x86_gcc_append(&sha1, ((mk_lang_types_uchar_pct)(s_messages[i])), s_message_lens[i]);
		mk_lib_crypto_hash_stream_sha1_x86_gcc_finish(&sha1, &digest);
		for(j = 0; j != mk_lib_crypto_hash_block_sha1_x86_gcc_digest_len; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_digests[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_digests[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_to_bi_uchar(&digest.m_uint8s[j], &ta);
			test(ta == byte);
		}
	}

	#undef test

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

#else

mk_lang_extern_c void mk_lib_crypto_hash_stream_sha1_x86_gcc_test(void) mk_lang_noexcept
{
}

#endif
