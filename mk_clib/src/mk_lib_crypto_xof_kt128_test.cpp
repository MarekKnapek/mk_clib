#ifndef mk_include_guard_mk_lib_crypto_xof_kt128_test_cpp
#define mk_include_guard_mk_lib_crypto_xof_kt128_test_cpp


#if defined mk_lang_jumbo_want
#undef mk_lang_jumbo_want
#endif
#define mk_lang_jumbo_want 2


#include "mk_lang_warning_msvc_push_c4514.h"


#include "mk_lib_crypto_xof_kt128_test.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_crypto_xof_kt128.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_test_generate_ptn(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const off, mk_lang_types_sint_t const len)
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;

	n = len;
	for(i = 0; i != n; ++i)
	{
		tuc = ((mk_lang_types_uchar_t)(((off + i) % 0xfb) & 0xff));
		mk_sl_cui_uint8_from_bi_uchar(&buf[i], &tuc);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt128_test_generate_ff(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len)
{
	mk_sl_cui_uint8_t mx mk_lang_constexpr_init;

	mk_sl_cui_uint8_set_max(&mx);
	mk_sl_cui_uint8_memset_fn(buf, &mx, ((mk_lang_types_usize_t)(len)));
}

#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
template<mk_lang_types_usize_t expected_digest_str_lit_len>
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_crypto_xof_kt128_test_one(mk_lang_types_bool_t const ptn, mk_lang_types_sint_t const input_bytes_count, mk_lang_types_sint_t const customization_bytes_count, mk_lang_types_sint_t const skip, mk_lang_types_sint_t const digest_len, mk_lang_types_pchar_ct(&expected_digest)[expected_digest_str_lit_len])
#else
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_crypto_xof_kt128_test_one(mk_lang_types_bool_t const ptn, mk_lang_types_sint_t const input_bytes_count, mk_lang_types_sint_t const customization_bytes_count, mk_lang_types_sint_t const skip, mk_lang_types_sint_t const digest_len, mk_lang_types_pchar_pct const expected_digest)
#endif
{
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_lib_crypto_xof_kt128_t kt128 mk_lang_constexpr_init;
	mk_lang_types_sint_t offset mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t count mk_lang_constexpr_init;
	mk_sl_cui_uint8_t input[1024] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t digest[64] mk_lang_constexpr_init;
	mk_lang_types_pchar_pct expected_str mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_sl_cui_uint8_t expected[mk_lang_countof(digest)] mk_lang_constexpr_init;

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
	mk_lang_static_assert(expected_digest_str_lit_len >= 1);
	mk_lang_static_assert((expected_digest_str_lit_len - 1) % mk_sl_cui_uint8_strlen_hex_v == 0);
	mk_lang_assert(digest_len == (expected_digest_str_lit_len - 1) / mk_sl_cui_uint8_strlen_hex_v);
	#endif

	mk_lang_assert(ptn == mk_lang_true || ptn == mk_lang_false);
	mk_lang_assert(input_bytes_count >= 0);
	mk_lang_assert(customization_bytes_count >= 0);
	mk_lang_assert(skip >= 0);
	mk_lang_assert(digest_len >= 1);
	mk_lang_assert(expected_digest);

	gud = mk_lang_true;
	mk_lib_crypto_xof_kt128_init(&kt128);
	offset = 0;
	rem = input_bytes_count;
	do
	{
		count = mk_lang_min(rem, mk_lang_countof(input));
		if(ptn)
		{
			mk_lib_crypto_xof_kt128_test_generate_ptn(&input[0], offset, count);
		}
		else
		{
			mk_lib_crypto_xof_kt128_test_generate_ff(&input[0], count);
		}
		mk_lib_crypto_xof_kt128_append_message_u8s(&kt128, &input[0], ((mk_lang_types_usize_t)(count)));
		offset += count;
		rem -= count;
	}while(rem != 0);
	offset = 0;
	rem = customization_bytes_count;
	do
	{
		count = mk_lang_min(rem, mk_lang_countof(input));
		mk_lib_crypto_xof_kt128_test_generate_ptn(&input[0], offset, count);
		mk_lib_crypto_xof_kt128_append_customization_u8s(&kt128, &input[0], ((mk_lang_types_usize_t)(count)));
		offset += count;
		rem -= count;
	}while(rem != 0);
	mk_lib_crypto_xof_kt128_finish(&kt128);
	rem = skip;
	do
	{
		count = mk_lang_min(rem, mk_lang_countof(digest));
		mk_lib_crypto_xof_kt128_squeeze_u8s(&kt128, &digest[0], ((mk_lang_types_usize_t)(count)));
		rem -= count;
	}while(rem != 0);
	rem = digest_len;
	expected_str = expected_digest;
	do
	{
		count = mk_lang_min(rem, mk_lang_countof(digest));
		len = mk_sl_cui_uint8_from_str_hex_many_n(&expected[0], count, expected_str, count * mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == count * mk_sl_cui_uint8_strlen_hex_v);
		mk_lib_crypto_xof_kt128_squeeze_u8s(&kt128, &digest[0], ((mk_lang_types_usize_t)(count)));
		gud = gud && mk_sl_cui_uint8_memcmp_fn(&digest[0], &expected[0], ((mk_lang_types_usize_t)(count))) == 0;
		rem -= count;
		expected_str += count * mk_sl_cui_uint8_strlen_hex_v;
	}while(rem != 0);
	return gud;
}


mk_lang_extern_force_c mk_lang_types_void_t mk_lib_crypto_xof_kt128_test(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lib_crypto_xof_kt128_test_one(mk_lang_true ,                  0,                  0,     0, 32, "1ac2d450fc3b4205d19da7bfca1b37513c0803577ac7167f06fe2ce1f0ef39e5"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt128_test_one(mk_lang_true ,                  0,                  0,     0, 64, "1ac2d450fc3b4205d19da7bfca1b37513c0803577ac7167f06fe2ce1f0ef39e54269c056b8c82e48276038b6d292966cc07a3d4645272e31ff38508139eb0a71"));
	mk_lang_assert       (mk_lib_crypto_xof_kt128_test_one(mk_lang_true ,                  0,                  0, 10000, 32, "e8dc563642f7228c84684c898405d3a834799158c079b12880277a1d28e2ff6d"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt128_test_one(mk_lang_true ,                  1,                  0,     0, 32, "2bda92450e8b147f8a7cb629e784a058efca7cf7d8218e02d345dfaa65244a1f"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt128_test_one(mk_lang_true , mk_lang_pow(17, 1),                  0,     0, 32, "6bf75fa2239198db4772e36478f8e19b0f371205f6a9a93a273f51df37122888"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt128_test_one(mk_lang_true , mk_lang_pow(17, 2),                  0,     0, 32, "0c315ebcdedbf61426de7dcf8fb725d1e74675d7f5327a5067f367b108ecb67c"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt128_test_one(mk_lang_true , mk_lang_pow(17, 3),                  0,     0, 32, "cb552e2ec77d9910701d578b457ddf772c12e322e4ee7fe417f92c758f0d59d0"));
	mk_lang_assert       (mk_lib_crypto_xof_kt128_test_one(mk_lang_true , mk_lang_pow(17, 4),                  0,     0, 32, "8701045e22205345ff4dda05555cbb5c3af1a771c2b89baef37db43d9998b9fe"));
	mk_lang_assert       (mk_lib_crypto_xof_kt128_test_one(mk_lang_true , mk_lang_pow(17, 5),                  0,     0, 32, "844d610933b1b9963cbdeb5ae3b6b05cc7cbd67ceedf883eb678a0a8e0371682"));
	mk_lang_assert       (mk_lib_crypto_xof_kt128_test_one(mk_lang_true , mk_lang_pow(17, 6),                  0,     0, 32, "3c390782a8a4e89fa6367f72feaaf13255c8d95878481d3cd8ce85f58e880af8"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt128_test_one(mk_lang_true ,                  0,                  1,     0, 32, "fab658db63e94a246188bf7af69a133045f46ee984c56e3c3328caaf1aa1a583"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt128_test_one(mk_lang_false,                  1, mk_lang_pow(41, 1),     0, 32, "d848c5068ced736f4462159b9867fd4c20b808acc3d5bc48e0b06ba0a3762ec4"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt128_test_one(mk_lang_false,                  3, mk_lang_pow(41, 2),     0, 32, "c389e5009ae57120854c2e8c64670ac01358cf4c1baf89447a724234dc7ced74"));
	mk_lang_assert       (mk_lib_crypto_xof_kt128_test_one(mk_lang_false,                  7, mk_lang_pow(41, 3),     0, 32, "75d2f86a2e644566726b4fbcfc5657b9dbcf070c7b0dca06450ab291d7443bcf"));
	mk_lang_assert       (mk_lib_crypto_xof_kt128_test_one(mk_lang_true ,               8191,                  0,     0, 32, "1b577636f723643e990cc7d6a659837436fd6a103626600eb8301cd1dbe553d6"));
	mk_lang_assert       (mk_lib_crypto_xof_kt128_test_one(mk_lang_true ,               8192,                  0,     0, 32, "48f256f6772f9edfb6a8b661ec92dc93b95ebd05a08a17b39ae3490870c926c3"));
	mk_lang_assert       (mk_lib_crypto_xof_kt128_test_one(mk_lang_true ,               8192,               8189,     0, 32, "3ed12f70fb05ddb58689510ab3e4d23c6c6033849aa01e1d8c220a297fedcd0b"));
	mk_lang_assert       (mk_lib_crypto_xof_kt128_test_one(mk_lang_true ,               8192,               8190,     0, 32, "6a7c1b6a5cd0d8c9ca943a4a216cc64604559a2ea45f78570a15253d67ba00ae"));
}


#include "mk_lang_warning_msvc_pop.h"


#endif
