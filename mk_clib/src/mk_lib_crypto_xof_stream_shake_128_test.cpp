#include "mk_lib_crypto_xof_stream_shake_128_test.hpp"
#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpp.h"
#include "mk_lang_crash.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr.hpp"
#include "mk_lib_crypto_xof_stream_shake_128.h"
#include "mk_sl_uint8.h"


#define xof_bits 3000


union mk_lib_crypto_xof_stream_shake_128_test_digest_u
{
	mk_lib_crypto_xof_block_shake_128_digest_t m_data[mk_lang_div_roundup(xof_bits / 8, sizeof(mk_lib_crypto_xof_block_shake_128_digest_t))];
	mk_sl_cui_uint8_t m_uint8s[sizeof(mk_lib_crypto_xof_block_shake_128_digest_t)];
};
typedef union mk_lib_crypto_xof_stream_shake_128_test_digest_u mk_lib_crypto_xof_stream_shake_128_test_digest_t;


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_xof_stream_shake_128_test_compute_from_str_lit(char const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_lang_types_usize_t const s_len = str_lit_len - 1;

	mk_lib_crypto_xof_stream_shake_128_t shake_128 mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t uch mk_lang_constexpr_init;
	mk_lib_crypto_xof_stream_shake_128_test_digest_t digest mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, xof_bits / 8> ret mk_lang_constexpr_init;
	mk_lang_types_usize_t b mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_len >= 1);

	mk_lib_crypto_xof_stream_shake_128_init(&shake_128);
	for(i = 0; i  != s_len; ++i)
	{
		uch = ((mk_lang_types_uchar_t)(str_lit[i]));
		mk_lib_crypto_xof_stream_shake_128_append(&shake_128, &uch, 1);
	}
	mk_lib_crypto_xof_stream_shake_128_finish(&shake_128, xof_bits / 8, digest.m_data);
	for(i = 0; i != xof_bits / 8; ++i)
	{
		b = i / sizeof(mk_lib_crypto_xof_block_shake_128_digest_t);
		s = i % sizeof(mk_lib_crypto_xof_block_shake_128_digest_t);
		mk_sl_cui_uint8_to_bi_uchar(&digest.m_data[b].m_uint8s[s], &ret[i]);
	}
	return ret;
}

#endif


mk_lang_extern_c void mk_lib_crypto_xof_stream_shake_128_test(void) mk_lang_noexcept
{
	#define message_1 ""
	#define message_2 "a"
	#define message_3 "abc"
	#define message_4 "message digest"
	#define message_5 "abcdefghijklmnopqrstuvwxyz"
	#define message_6 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
	#define message_7 "12345678901234567890123456789012345678901234567890123456789012345678901234567890"
	#define message_8 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

	#define digest_1 "7f9c2ba4e88f827d616045507605853ed73b8093f6efbc88eb1a6eacfa66ef263cb1eea988004b93103cfb0aeefd2a686e01fa4a58e8a3639ca8a1e3f9ae57e235b8cc873c23dc62b8d260169afa2f75ab916a58d974918835d25e6a435085b2badfd6dfaac359a5efbb7bcc4b59d538df9a04302e10c8bc1cbf1a0b3a5120ea17cda7cfad765f5623474d368ccca8af0007cd9f5e4c849f167a580b14aabdefaee7eef47cb0fca9767be1fda69419dfb927e9df07348b196691abaeb580b32def58538b8d23f87732ea63b02b4fa0f4873360e2841928cd60dd4cee8cc0d4c922a96188d032675c8ac850933c7aff1533b94c834adbb69c6115bad4692d8619f90b0cdf8a7b9c264029ac185b70b83f2801f2f4b3f70c593ea3aeeb613a7f1b1de33fd75081f592305f2e4526edc09631b10958f464d889f31ba010250fda7f1368ec2967fc84ef2ae9aff268e0b1700affc6820b523a3d917135f2dff2ee06bfe72b3124721d4a26c04e53a75e30e73a7a9c4a95d91c"
	#define digest_2 "85c8de88d28866bf0868090b3961162bf82392f690d9e4730910f4af7c6ab3ee4354b49ca729eb356ee3f5b0fbd29b66769383e5e401b1f85e044c92bb5231aa4dee1799af7a7cee213a23adcd03c4806c9a8b0d8a2eead8ea7a6134c13e523ccf93ad39d227d3e7d022d9654f3b49413788758a6417e42d41957cb30cf04da37f26897c2cf2f80055846293fde02331cf4a269aaf2d47eb27aba0faba4a678ec002bc0d3064ead0a3f2e0d8a7fa404af54ebf4f5b183562a8dad73b9a55bf1c066e0007e7ab8a8988a5a1d31729c2c6aeb06f5a5c1bc996f84d6dd227b989862db670465c02da0501cd1b4a324a90fa4ce7316665fb68d4c495d792782cb45cfe07c9a887196c5aa4c966dbdd77b88d8b5515e816213cd6e9d9344faa79bd40c36b2cbe021737770dec56d68f2eb28c1f20bef0b9ea5a293b69a9c6ff7399c26fa11e93cb3f8d41565c67727eaee9574067fa04b31b4b25cfde40e5e9d988ec6d3262e3d243b64bfa82492f8db767a486b87bcb342f4c"
	#define digest_3 "5881092dd818bf5cf8a3ddb793fbcba74097d5c526a6d35f97b83351940f2cc844c50af32acd3f2cdd066568706f509bc1bdde58295dae3f891a9a0fca5783789a41f8611214ce612394df286a62d1a2252aa94db9c538956c717dc2bed4f232a0294c857c730aa16067ac1062f1201fb0d377cfb9cde4c63599b27f3462bba4a0ed296c801f9ff7f57302bb3076ee145f97a32ae68e76ab66c48d51675bd49acc29082f5647584e6aa01b3f5af057805f973ff8ecb8b226ac32ada6f01c1fcd4818cb006aa5b4cdb3611eb1e533c8964cacfdf31012cd3fb744d02225b988b475375faad996eb1b9176ecb0f8b2871723d6dbb804e23357e50732f5cfc904b1319795000d7361d9e5e1b77b4b8f5774aa1482cfa58f83096bdb2e06a3eed543a38919b57ecbec737f4086be007f8ef80094ceea8807193d46e9be540b6e99b4c1c71507095028a024e8d39aa8f4c5854cedd50d30a223e7d54e9a24f0a2526b31002afbd1b4ebea69c8400c3deb4c1c35d6dbb75651b2"
	#define digest_4 "cbef732961b55b4c31396796577df491b6eed61d8949ce967226801e411e53f09544c13fe4df40fc8df5f9853e8541d04541f10077d9d44e7493e87f160a0a0d37b3d6dac9645988ed5d06dd5321993d873574d147e336d7233a682731872148e93e722816b3b1cc313bc433945f74f21439dfd8c89bc59bf3d16d489a5d5cafdf77ac07be5d96a76e95275307d883cad6257143b5610073cbbf7b8e8970317466a8b685d48178b8524c66c19582c2e5cc3fa6fca4492ac39d635f535907c5b524cfd12669ded658e2048fc9236ef9fddc95f462cbb1ca39413ffbdfe9d9a6d3079d4f7eecf129d0839bcfce2442deff22694469139fa451b5bb84ccda7783c2a97104ba8f51fd11128b47eaffe115d6371688caa8092173b8c8383052c5c4ff124d10bc8ccf8cbd8283924efc174ce941b408f9554f0ba049575898da0767106a2c8e4b5b79816bb5590aa6b45c2ffb5ea1949cda2666bf5de085c504dbe5487868daee4c3cd87a41f108746f800ba85d4928020737ae"
	#define digest_5 "961c919c0854576e561320e81514bf3724197d0715e16a364520384ee997f6ef3be7ad1ab687d31ebd7e6604ef2c7652932e4206113d263514e72f31f5e1df87c5f54fc43e8f857fc4a52bbb565bd6d45869df9259c09774728394e3e0c3b326410085c356e5b173d570087945b0f068e4c63a5b191fef22d93b9fd4211328d70e514fec92b1b48643495918b641eab05460d0798cbe42fda47a2375f1065d037ebc76bdceff29efa43c82793c9ff41e19834717532faa42bcc91287bbddd88efe22fb471db95463dd3d6d3dfc5079042181bc405be83321c0a51431588b98019506a1e2def66bfe45a49c2d662b547becdcecb7e87a51e1aca962f08e3a4808f6c119f471eebca33d8894219a13637464c9ef601b5ac6e21629d15a82d22a632d9b2ae535a94c9fd8ee278cab57c9599171021a2d72f07a866e8814f46daeb52d30cbf50a7bd3a71e6aff0f315637b8c0eba30b06b733e0577a72e4cd73da2ec1807978c3ea872e9ef65a127af8c7eeb7ff16c259d010"
	#define digest_6 "54dd201e53249910db3c7d366574fbb64e71fae442a4bac13439f26dd489688370d012a15586d87e7300beedd9233eea98f916dab266513802502440315bba9e40cdb860097b12dfd88d4f242f77c22e93adfd3eb7899482d39f7c0f160ecc07047347829473314674a56a13e701d5d8aa37546b43c5733656c1ac3ca4697a30320b98adf9bca3c68bec9f14e33b8fae30d55ec60e8015a51680bb37eb5a7ebc9088cdcf09ff2d6bf2f92f464cf2daec3a3f6ec2041782e07733fcb9083333b93d6ac0bef6264f712a5f64120e1c7a342b8f25c95db848d93c0cd57392d29e7e1938a59ce05332df7a94cbb862133a65f93087ed981f14ffe18128cb7d62a9d758606b702137f56239c9e52fa8443649b8f20ccbc5b267b6f0c33ea3199afa152b7ef5add7270cee26aee554494b1e900b00362658267f785e9ecdb79a1bf85b70ac321a9a6d22680bb850e9d4da213466e11366456d4c76218a2dec0f8117a28bf4121205d919ded9f12978e11a513857e562028c69ea"
	#define digest_7 "7bf451c92fdc77b9771e6c9056445894ee867f00c2b70d3af0d196a0cf6b28e12ced960537f22a0e90334103675844993c4fd713646800bd899951e56f0645fcf03978a627c07c62a75a543b8af7edb0afe7643d9495363b30bcc5501c74df195b2ad428831b779bf1ab2a0dfc92a5925ac8d59790eebcf2ec29b3338f660c5a6f6673ce322cc1039ae5f1463b86ca7e96aaa99a270993026ac813dac4b9eb8214e31ce86827cb21297e2e4eb4e1f4d5414dfad2bcaf6572e9f310431c9f431a26d06e23154570026a277694ccc19d0a5c203ce710ca6339155ca2ed2a9938c86b2e7cfccb0797771476e9b6030261ec05d346d85a0a4141c62f54c67f2a400c7397ab98b0d5636ec96d2af42e93b7a8105baeb230b69f4541fa6e2cd279e014a9b55fb84bd780ed67ee1f53c548dd34a045a878d145b06df55b54858574a1a11046dd8a68f913f967cea0c8429dd09e280385da9d5f396ade9899960eb58cfeee08906899b4cc3fb1c724f8f935d42f5657de7db9811d"
	#define digest_8 "d5fb6e239091e17b8638f2167bc6eea2e7aead9037d705a067bcbc755f66b9d4a64907dc4666bb0207c8778a0cf2cee691874a81d918979267f6a26db72e6a6bc06a85e6b9c805b6b60fabd4eec620b0279caa8e44914cbe8db5e9c33a9a07ff51b446d0468be8cde9cd8ba2d60b8920e03408c0059919d1e2eab7a8db76848a03f850ced98951b7dd9060a457332358094598e476a0faaa0427af806e981a8cb939ba8eaf11479133da7d6d13108cc0a5757b67e630f0a964b4aea9139579fc3fa6d4f57afc5bcf1ddfec2458a214442ddc8616eaa0ce74248f1477ac925f05a19c80e969a3f4bcaf13fe9342bdc6448d3626d00f210ea41ef3d747d5b685b9c9d8946c96c38ccb2ec3aeab0ccd6e1f2aa2ba64c8714f7037b72154d6f83fa3aae548fbe20dc146789f7cd02c06c67ad6d00fe27eaf9596d61b125c0c3598cf2d182fa7d3880b9f14936343cbf8a894500c88872d72690c2a3cc8ae4c5c9f6f3001c5f1489bb0458d8992a94a6a75ac037990b99c2e01"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_digest_computed_1 = mk_lib_crypto_xof_stream_shake_128_test_compute_from_str_lit(message_1);
	mk_lang_constexpr_static auto const s_digest_computed_2 = mk_lib_crypto_xof_stream_shake_128_test_compute_from_str_lit(message_2);
	mk_lang_constexpr_static auto const s_digest_computed_3 = mk_lib_crypto_xof_stream_shake_128_test_compute_from_str_lit(message_3);
	mk_lang_constexpr_static auto const s_digest_computed_4 = mk_lib_crypto_xof_stream_shake_128_test_compute_from_str_lit(message_4);
	mk_lang_constexpr_static auto const s_digest_computed_5 = mk_lib_crypto_xof_stream_shake_128_test_compute_from_str_lit(message_5);
	mk_lang_constexpr_static auto const s_digest_computed_6 = mk_lib_crypto_xof_stream_shake_128_test_compute_from_str_lit(message_6);
	mk_lang_constexpr_static auto const s_digest_computed_7 = mk_lib_crypto_xof_stream_shake_128_test_compute_from_str_lit(message_7);
	mk_lang_constexpr_static auto const s_digest_computed_8 = mk_lib_crypto_xof_stream_shake_128_test_compute_from_str_lit(message_8);

	mk_lang_constexpr_static auto const s_digest_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_1);
	mk_lang_constexpr_static auto const s_digest_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_2);
	mk_lang_constexpr_static auto const s_digest_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_3);
	mk_lang_constexpr_static auto const s_digest_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_4);
	mk_lang_constexpr_static auto const s_digest_precomputed_5 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_5);
	mk_lang_constexpr_static auto const s_digest_precomputed_6 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_6);
	mk_lang_constexpr_static auto const s_digest_precomputed_7 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_7);
	mk_lang_constexpr_static auto const s_digest_precomputed_8 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_8);

	mk_lang_static_assert(s_digest_computed_1 == s_digest_precomputed_1);
	mk_lang_static_assert(s_digest_computed_2 == s_digest_precomputed_2);
	mk_lang_static_assert(s_digest_computed_3 == s_digest_precomputed_3);
	mk_lang_static_assert(s_digest_computed_4 == s_digest_precomputed_4);
	mk_lang_static_assert(s_digest_computed_5 == s_digest_precomputed_5);
	mk_lang_static_assert(s_digest_computed_6 == s_digest_precomputed_6);
	mk_lang_static_assert(s_digest_computed_7 == s_digest_precomputed_7);
	mk_lang_static_assert(s_digest_computed_8 == s_digest_precomputed_8);

	#endif

	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_assert(0); mk_lang_crash(); } ((void)(0))

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
	mk_lib_crypto_xof_stream_shake_128_t shake_128;
	mk_lib_crypto_xof_stream_shake_128_test_digest_t digest;
	int j;
	mk_lang_types_uchar_t hi;
	mk_lang_types_uchar_t lo;
	mk_lang_types_uchar_t byte;
	int b;
	int s;
	mk_lang_types_uchar_t ta;

	mk_lang_static_assert(sizeof(s_messages) / sizeof(s_messages[0]) == sizeof(s_digests) / sizeof(s_digests[0]));
	mk_lang_static_assert(sizeof(s_messages) / sizeof(s_messages[0]) == sizeof(s_message_lens) / sizeof(s_message_lens[0]));

	n = ((int)(sizeof(s_messages) / sizeof(s_messages[0])));
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(s_message_lens[i] >= 0);
		mk_lib_crypto_xof_stream_shake_128_init(&shake_128);
		mk_lib_crypto_xof_stream_shake_128_append(&shake_128, ((mk_lang_types_uchar_pct)(s_messages[i])), s_message_lens[i]);
		mk_lib_crypto_xof_stream_shake_128_finish(&shake_128, xof_bits / 8, digest.m_data);
		for(j = 0; j != xof_bits / 8; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_digests[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_digests[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			b = j / sizeof(mk_lib_crypto_xof_block_shake_128_digest_t);
			s = j % sizeof(mk_lib_crypto_xof_block_shake_128_digest_t);
			mk_sl_cui_uint8_to_bi_uchar(&digest.m_data[b].m_uint8s[s], &ta);
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


#undef xof_bits
