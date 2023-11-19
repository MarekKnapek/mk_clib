#include "mk_lib_crypto_kdf_pbkdf1_sha1x86_test.hpp"
#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1

#include "mk_lang_constexpr.h"
#include "mk_lang_cpp.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"

#if !mk_lang_constexpr_is_constant_evaluated && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2015

#include "mk_lang_assert.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr.hpp"
#include "mk_lib_crypto_kdf_pbkdf1_sha1x86.h"
#include "mk_sl_uint8.h"


mk_lang_extern_c void mk_lib_crypto_kdf_pbkdf1_sha1x86_test(void) mk_lang_noexcept
{
	#define password_1 "password"

	#define salt_1 "78578e5a5d63cb06"

	#define cost_1 1000

	#define key_1 "dc19847e05c64d2faf10ebfb4a3d2a20"

	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_crash(); } ((void)(0))

	static char const* const s_passwords[] =
	{
		password_1,
	};

	static int const s_password_lens[] =
	{
		((int)(sizeof(password_1) / sizeof(password_1[0]) - 1)),
	};

	static char const* const s_salts[] =
	{
		salt_1,
	};

	static mk_lang_types_ulong_t const s_costs[] =
	{
		cost_1,
	};

	static char const* const s_keys[] =
	{
		key_1,
	};

	static int const s_key_lens[] =
	{
		((int)(sizeof(key_1) / sizeof(key_1[0]) - 1)) / 2,
	};

	int n;
	int i;
	int j;
	mk_lang_types_uchar_t hi;
	mk_lang_types_uchar_t lo;
	mk_lang_types_uchar_t byte;
	mk_lang_types_uchar_t salt[8];
	mk_lang_types_uchar_t key[128];

	mk_lang_static_assert(sizeof(s_passwords) / sizeof(s_passwords[0]) == sizeof(s_password_lens) / sizeof(s_password_lens[0]));
	mk_lang_static_assert(sizeof(s_passwords) / sizeof(s_passwords[0]) == sizeof(s_salts) / sizeof(s_salts[0]));
	mk_lang_static_assert(sizeof(s_passwords) / sizeof(s_passwords[0]) == sizeof(s_costs) / sizeof(s_costs[0]));
	mk_lang_static_assert(sizeof(s_passwords) / sizeof(s_passwords[0]) == sizeof(s_keys) / sizeof(s_keys[0]));
	mk_lang_static_assert(sizeof(s_passwords) / sizeof(s_passwords[0]) == sizeof(s_key_lens) / sizeof(s_key_lens[0]));

	n = ((int)(sizeof(s_passwords) / sizeof(s_passwords[0])));
	for(i = 0; i != n; ++i)
	{
		for(j = 0; j != 8; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_salts[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_salts[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			salt[j] = byte;
		}
		mk_lang_assert(s_key_lens[i] <= ((int)(sizeof(key) / sizeof(key[0]))));
		mk_lib_crypto_kdf_pbkdf1_sha1x86(((mk_lang_types_uchar_pct)(s_passwords[i])), s_password_lens[i], salt, s_costs[i], s_key_lens[i], key);
		for(j = 0; j != s_key_lens[i]; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			test(key[j] == byte);
		}
	}

	#undef test

	#undef password_1

	#undef salt_1

	#undef cost_1

	#undef key_1
}

#else

mk_lang_extern_c void mk_lib_crypto_kdf_pbkdf1_sha1x86_test(void) mk_lang_noexcept
{
}

#endif
