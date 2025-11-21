#ifndef mk_include_guard_mk_lib_crypto_xof_kt256_test_cpp
#define mk_include_guard_mk_lib_crypto_xof_kt256_test_cpp


#if defined mk_lang_jumbo_want
#undef mk_lang_jumbo_want
#endif
#define mk_lang_jumbo_want 2


#include "mk_lang_warning_msvc_push_c4514.h"


#include "mk_lib_crypto_xof_kt256_test.hpp"

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
#include "mk_lib_crypto_xof_kt256.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt256_test_generate_ptn(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const off, mk_lang_types_sint_t const len)
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

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_xof_kt256_test_generate_ff(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len)
{
	mk_sl_cui_uint8_t mx mk_lang_constexpr_init;

	mk_sl_cui_uint8_set_max(&mx);
	mk_sl_cui_uint8_memset_fn(buf, &mx, ((mk_lang_types_usize_t)(len)));
}

#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
template<mk_lang_types_usize_t expected_digest_str_lit_len>
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_crypto_xof_kt256_test_one(mk_lang_types_bool_t const ptn, mk_lang_types_sint_t const input_bytes_count, mk_lang_types_sint_t const customization_bytes_count, mk_lang_types_sint_t const skip, mk_lang_types_sint_t const digest_len, mk_lang_types_pchar_ct(&expected_digest)[expected_digest_str_lit_len])
#else
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_crypto_xof_kt256_test_one(mk_lang_types_bool_t const ptn, mk_lang_types_sint_t const input_bytes_count, mk_lang_types_sint_t const customization_bytes_count, mk_lang_types_sint_t const skip, mk_lang_types_sint_t const digest_len, mk_lang_types_pchar_pct const expected_digest)
#endif
{
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_lib_crypto_xof_kt256_t kt256 mk_lang_constexpr_init;
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
	mk_lib_crypto_xof_kt256_init(&kt256);
	offset = 0;
	rem = input_bytes_count;
	do
	{
		count = mk_lang_min(rem, mk_lang_countof(input));
		if(ptn)
		{
			mk_lib_crypto_xof_kt256_test_generate_ptn(&input[0], offset, count);
		}
		else
		{
			mk_lib_crypto_xof_kt256_test_generate_ff(&input[0], count);
		}
		mk_lib_crypto_xof_kt256_append_message_u8s(&kt256, &input[0], ((mk_lang_types_usize_t)(count)));
		offset += count;
		rem -= count;
	}while(rem != 0);
	offset = 0;
	rem = customization_bytes_count;
	do
	{
		count = mk_lang_min(rem, mk_lang_countof(input));
		mk_lib_crypto_xof_kt256_test_generate_ptn(&input[0], offset, count);
		mk_lib_crypto_xof_kt256_append_customization_u8s(&kt256, &input[0], ((mk_lang_types_usize_t)(count)));
		offset += count;
		rem -= count;
	}while(rem != 0);
	mk_lib_crypto_xof_kt256_finish(&kt256);
	rem = skip;
	do
	{
		count = mk_lang_min(rem, mk_lang_countof(digest));
		mk_lib_crypto_xof_kt256_squeeze_u8s(&kt256, &digest[0], ((mk_lang_types_usize_t)(count)));
		rem -= count;
	}while(rem != 0);
	rem = digest_len;
	expected_str = expected_digest;
	do
	{
		count = mk_lang_min(rem, mk_lang_countof(digest));
		len = mk_sl_cui_uint8_from_str_hex_many_n(&expected[0], count, expected_str, count * mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == count * mk_sl_cui_uint8_strlen_hex_v);
		mk_lib_crypto_xof_kt256_squeeze_u8s(&kt256, &digest[0], ((mk_lang_types_usize_t)(count)));
		gud = gud && mk_sl_cui_uint8_memcmp_fn(&digest[0], &expected[0], ((mk_lang_types_usize_t)(count))) == 0;
		rem -= count;
		expected_str += count * mk_sl_cui_uint8_strlen_hex_v;
	}while(rem != 0);
	return gud;
}


mk_lang_extern_force_c mk_lang_types_void_t mk_lib_crypto_xof_kt256_test(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lib_crypto_xof_kt256_test_one(mk_lang_true ,                  0,                  0,     0,  64, "b23d2e9cea9f4904e02bec06817fc10ce38ce8e93ef4c89e6537076af8646404e3e8b68107b8833a5d30490aa33482353fd4adc7148ecb782855003aaebde4a9"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt256_test_one(mk_lang_true ,                  0,                  0,     0, 128, "b23d2e9cea9f4904e02bec06817fc10ce38ce8e93ef4c89e6537076af8646404e3e8b68107b8833a5d30490aa33482353fd4adc7148ecb782855003aaebde4a9b0925319d8ea1e121a609821ec19efea89e6d08daee1662b69c840289f188ba860f55760b61f82114c030c97e5178449608ccd2cd2d919fc7829ff69931ac4d0"));
	mk_lang_assert       (mk_lib_crypto_xof_kt256_test_one(mk_lang_true ,                  0,                  0, 10000,  64, "ad4a1d718cf950506709a4c33396139b4449041fc79a05d68da35f1e453522e056c64fe94958e7085f2964888259b9932752f3ccd855288efee5fcbb8b563069"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt256_test_one(mk_lang_true ,                  1,                  0,     0,  64, "0d005a194085360217128cf17f91e1f71314efa5564539d444912e3437efa17f82db6f6ffe76e781eaa068bce01f2bbf81eacb983d7230f2fb02834a21b1ddd0"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt256_test_one(mk_lang_true , mk_lang_pow(17, 1),                  0,     0,  64, "1ba3c02b1fc514474f06c8979978a9056c8483f4a1b63d0dccefe3a28a2f323e1cdcca40ebf006ac76ef0397152346837b1277d3e7faa9c9653b19075098527b"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt256_test_one(mk_lang_true , mk_lang_pow(17, 2),                  0,     0,  64, "de8ccbc63e0f133ebb4416814d4c66f691bbf8b6a61ec0a7700f836b086cb029d54f12ac7159472c72db118c35b4e6aa213c6562caaa9dcc518959e69b10f3ba"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt256_test_one(mk_lang_true , mk_lang_pow(17, 3),                  0,     0,  64, "647efb49fe9d717500171b41e7f11bd491544443209997ce1c2530d15eb1ffbb598935ef954528ffc152b1e4d731ee2683680674365cd191d562bae753b84aa5"));
	mk_lang_assert       (mk_lib_crypto_xof_kt256_test_one(mk_lang_true , mk_lang_pow(17, 4),                  0,     0,  64, "b06275d284cd1cf205bcbe57dccd3ec1ff6686e3ed15776383e1f2fa3c6ac8f08bf8a162829db1a44b2a43ff83dd89c3cf1ceb61ede659766d5ccf817a62ba8d"));
	mk_lang_assert       (mk_lib_crypto_xof_kt256_test_one(mk_lang_true , mk_lang_pow(17, 5),                  0,     0,  64, "9473831d76a4c7bf77ace45b59f1458b1673d64bcd877a7c66b2664aa6dd149e60eab71b5c2bab858c074ded81ddce2b4022b5215935c0d4d19bf511aeeb0772"));
	mk_lang_assert       (mk_lib_crypto_xof_kt256_test_one(mk_lang_true , mk_lang_pow(17, 6),                  0,     0,  64, "0652b740d78c5e1f7c8dcc1777097382768b7ff38f9a7a20f29f413bb1b3045b31a5578f568f911e09cf44746da84224a5266e96a4a535e871324e4f9c7004da"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt256_test_one(mk_lang_true ,                  0,                  1,     0,  64, "9280f5cc39b54a5a594ec63de0bb99371e4609d44bf845c2f5b8c316d72b159811f748f23e3fabbe5c3226ec96c62186df2d33e9df74c5069ceecbb4dd10eff6"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt256_test_one(mk_lang_false,                  1, mk_lang_pow(41, 1),     0,  64, "47ef96dd616f200937aa7847e34ec2feae8087e3761dc0f8c1a154f51dc9ccf845d7adbce57ff64b639722c6a1672e3bf5372d87e00aff89be97240756998853"));
	mk_lang_static_assert(mk_lib_crypto_xof_kt256_test_one(mk_lang_false,                  3, mk_lang_pow(41, 2),     0,  64, "3b48667a5051c5966c53c5d42b95de451e05584e7806e2fb765eda959074172cb438a9e91dde337c98e9c41bed94c4e0aef431d0b64ef2324f7932caa6f54969"));
	mk_lang_assert       (mk_lib_crypto_xof_kt256_test_one(mk_lang_false,                  7, mk_lang_pow(41, 3),     0,  64, "e0911cc00025e1540831e266d94add9b98712142b80d2629e643aac4efaf5a3a30a88cbf4ac2a91a2432743054fbcc9897670e86ba8cec2fc2ace9c966369724"));
	mk_lang_assert       (mk_lib_crypto_xof_kt256_test_one(mk_lang_true ,               8191,                  0,     0,  64, "3081434d93a4108d8d8a3305b89682cebedc7ca4ea8a3ce869fbb73cbe4a58eef6f24de38ffc170514c70e7ab2d01f03812616e863d769afb3753193ba045b20"));
	mk_lang_assert       (mk_lib_crypto_xof_kt256_test_one(mk_lang_true ,               8192,                  0,     0,  64, "c6ee8e2ad3200c018ac87aaa031cdac22121b412d07dc6e0dccbb53423747e9a1c18834d99df596cf0cf4b8dfafb7bf02d139d0c9035725adc1a01b7230a41fa"));
	mk_lang_assert       (mk_lib_crypto_xof_kt256_test_one(mk_lang_true ,               8192,               8189,     0,  64, "74e47879f10a9c5d11bd2da7e194fe57e86378bf3c3f7448eff3c576a0f18c5caae0999979512090a7f348af4260d4de3c37f1ecaf8d2c2c96c1d16c64b12496"));
	mk_lang_assert       (mk_lib_crypto_xof_kt256_test_one(mk_lang_true ,               8192,               8190,     0,  64, "f4b5908b929ffe01e0f79ec2f21243d41a396b2e7303a6af1d6399cd6c7a0a2dd7c4f607e8277f9c9b1cb4ab9ddc59d4b92d1fc7558441f1832c3279a4241b8b"));
}


#include "mk_lang_warning_msvc_pop.h"


#endif
