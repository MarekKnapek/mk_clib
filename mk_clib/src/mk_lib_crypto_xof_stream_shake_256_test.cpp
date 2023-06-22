#include "mk_lib_crypto_xof_stream_shake_256_test.hpp"
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
#include "mk_lib_crypto_xof_stream_shake_256.h"
#include "mk_sl_uint8.h"


#define xof_bits 3000


union mk_lib_crypto_xof_stream_shake_256_test_digest_u
{
	mk_lib_crypto_xof_block_shake_256_digest_t m_data[mk_lang_div_roundup(xof_bits / 8, sizeof(mk_lib_crypto_xof_block_shake_256_digest_t))];
	mk_sl_cui_uint8_t m_uint8s[sizeof(mk_lib_crypto_xof_block_shake_256_digest_t)];
};
typedef union mk_lib_crypto_xof_stream_shake_256_test_digest_u mk_lib_crypto_xof_stream_shake_256_test_digest_t;


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_xof_stream_shake_256_test_compute_from_str_lit(char const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_lang_types_usize_t const s_len = str_lit_len - 1;

	mk_lib_crypto_xof_stream_shake_256_t shake_256 mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t uch mk_lang_constexpr_init;
	mk_lib_crypto_xof_stream_shake_256_test_digest_t digest mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, xof_bits / 8> ret mk_lang_constexpr_init;
	mk_lang_types_usize_t b mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_len >= 1);

	mk_lib_crypto_xof_stream_shake_256_init(&shake_256);
	for(i = 0; i  != s_len; ++i)
	{
		uch = ((mk_lang_types_uchar_t)(str_lit[i]));
		mk_lib_crypto_xof_stream_shake_256_append(&shake_256, &uch, 1);
	}
	mk_lib_crypto_xof_stream_shake_256_finish(&shake_256, xof_bits / 8, digest.m_data);
	for(i = 0; i != xof_bits / 8; ++i)
	{
		b = i / sizeof(mk_lib_crypto_xof_block_shake_256_digest_t);
		s = i % sizeof(mk_lib_crypto_xof_block_shake_256_digest_t);
		mk_sl_cui_uint8_to_bi_uchar(&digest.m_data[b].m_uint8s[s], &ret[i]);
	}
	return ret;
}

#endif


mk_lang_extern_c void mk_lib_crypto_xof_stream_shake_256_test(void) mk_lang_noexcept
{
	#define message_1 ""
	#define message_2 "a"
	#define message_3 "abc"
	#define message_4 "message digest"
	#define message_5 "abcdefghijklmnopqrstuvwxyz"
	#define message_6 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
	#define message_7 "12345678901234567890123456789012345678901234567890123456789012345678901234567890"
	#define message_8 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

	#define digest_1 "46b9dd2b0ba88d13233b3feb743eeb243fcd52ea62b81b82b50c27646ed5762fd75dc4ddd8c0f200cb05019d67b592f6fc821c49479ab48640292eacb3b7c4be141e96616fb13957692cc7edd0b45ae3dc07223c8e92937bef84bc0eab862853349ec75546f58fb7c2775c38462c5010d846c185c15111e595522a6bcd16cf86f3d122109e3b1fdd943b6aec468a2d621a7c06c6a957c62b54dafc3be87567d677231395f6147293b68ceab7a9e0c58d864e8efde4e1b9a46cbe854713672f5caaae314ed9083dab4b099f8e300f01b8650f1f4b1d8fcf3f3cb53fb8e9eb2ea203bdc970f50ae55428a91f7f53ac266b28419c3778a15fd248d339ede785fb7f5a1aaa96d313eacc890936c173cdcd0fab882c45755feb3aed96d477ff96390bf9a66d1368b208e21f7c10d04a3dbd4e360633e5db4b602601c14cea737db3dcf722632cc77851cbdde2aaf0a33a07b373445df490cc8fc1e4160ff118378f11f0477de055a81a9eda57a4a2cfb0c83929d310912f729e"
	#define digest_2 "867e2cb04f5a04dcbd592501a5e8fe9ceaafca50255626ca736c138042530ba436b7b1ec0e06a279bc790733bb0aee6fa802683c7b355063c434e91189b0c651d092b01e55ce4d610b54a5466d02f88fc378096fb0dad0254857fe1e6381abc04e07e33d916935935636004896c5b1253464f1cb5ea73b007bc5028bbbea13ebc28668dbfc26b1240ce4239f8d50627ddaa01641dfeaa9d2fef03dd025e0b82cf071fb9ca3232c742d836b3cbcc8c3cba5b058b76795c177012314196dc822768991c0f16f8a655a731fd37ec92460d61ea722e2723c8681235c4cfa70fdddfeefac1a892d652cfbaa02b138e3b2d050d550f0c977c024bc2aab0c3456a6afeffab4941c8ba27ce775fccec151aafc7b3e9628cd03bb5e10eb5f90baa5e10028a1aa82cf36bc70fe2e22b37bbb0aec14c6e778bf7120ea707d856fe1c42035e2d8280ce8b9c823d07ab43c85696c29cd24a658cf193cb21c1b7d348e96ad6817fc521baa7bf51164c893e08661ad11469e1536c8fac669"
	#define digest_3 "483366601360a8771c6863080cc4114d8db44530f8f1e1ee4f94ea37e78b5739d5a15bef186a5386c75744c0527e1faa9f8726e462a12a4feb06bd8801e751e41385141204f329979fd3047a13c5657724ada64d2470157b3cdc288620944d78dbcddbd912993f0913f164fb2ce95131a2d09a3e6d51cbfc622720d7a75c6334e8a2d7ec71a7cc29cf0ea610eeff1a588290a53000faa79932becec0bd3cd0b33a7e5d397fed1ada9442b99903f4dcfd8559ed3950faf40fe6f3b5d710ed3b677513771af6bfe11934817e8762d9896ba579d88d84ba7aa3cdc7055f6796f195bd9ae788f2f5bb96100d6bbaff7fbc6eea24d4449a2477d172a5507dcc931412fc346b1bb39b878330e026b12ddf384af3334560ea1d363966caa7d8ddcbec7da52b42215c11d5f8ee57f341e399343ce63a752fc5edec99124a0eb314403e5f358b8b83d05be2d2970099284b00dcc33d7c753d1f752ab743325bc53d91aa671e50f9c3f93abf6e9662f90145c61954f2abbd26edad15"
	#define digest_4 "718e224088856840ade4dc73487e15826a07ecb8ed5e2bda526cc1acddb99d006049815844be0c6c29b759db80b7daa684cb46d90f7eef107d24aafcfaf0dacaca2888dfaa737694bc46d5c95f17c5cfe7b0c95cfd6a126dd9640c8e62e5ad1c06e575616a2dec0646066e8037e51a0054783d820b92c1141796f7c3e935038e6713bbba46080b2e1bc1ebd8c41cb8c5e19d3eb805aa98f2a1ec06eaf10ed45102042d26ac84f36185b9126888f5a981739a5c188bc90f798b3aa33c4ad09f61e5db6b4e3e2a1f864d15fbc1bd8bdefbdc0d2f117178014596633f8dc0ca9410a37f819781181badcdfea86e3ea77ae875b979ac8724dafa7236b504c0c032a0ee248e5ed8a304384f3f8e1942c82b1bc1c77344b7878d7f125f86ba2721d808deefbbfbce32bb456e11c182ec4e4e758af58c256db4572700b830a49366ff73a6bca7695b52b00a7f585c51da1df944a8d88dd2e0e485e5ae269075af170c702b1aba0c171f6d8347c673c4a633ef270877e7a5f948d4"
	#define digest_5 "b7b78b04a3dd30a265c8886c33fda94799853de5d3d10541fd4e9f4613701c61075249bed16b0781108fcfe086dbf38a7fb8300807cea85cc649328d07d4ff2b5e8908563ff0fdcc06a8092fbfe772f80e49f87a103b2aee12990ccb4798e9ec03aa4818a4bf5abda084e1a5fe687c2cfef4406846fe47a0d07bf45055a2699c37d6b6d9cd6c4ff0a675191553f1e30bf471eba3c78fa7a52bd33c48912c0d0c6f1145d3117a472fdcd9afbb866ba1bef4f5944c09b036b3adadc317cf96c1493b8f61cd4d1dea113d9ebf8a709f0f3bc847aabe02b068e4756752696ca0e1ca89360673c323e9b3994843b8b6f73391afe5f96d8f3914e95c74a6cb0a3052a5d0c882bff936c90b6a6200d46b0a505ac494995a8de1f255c2cf371af0ed3052ead05d9d67e434234e10f8d1175136e62811b94901129a2ea4007724ff3671f7a2ed8937fefff0cdd47dce91f0b1ad251f739a99ac295b4c7af14bb68fcf8934d5d5401fe6da79ee2762ec874b166bf7bff08b5818613b"
	#define digest_6 "31f19a097c723e91fa59b0998dd8523c2a9e7e13b4025d6b48fcbc328973a10878cfbeb3810d882fdb6a06e87f3ea52cf826ca5522316fb645b708acbe43b2cb3252092432427060c9639e21a898d388a7e153e42a8b8933f2ad0c275297698e257e05d2627539b42c101b9767bc6d900639311f8e4a2e88267bbb85b3fa4eadf401e074189f6bbf9e0aab86b8546d4a6698178f0e21ae617e8739cff10e529e841aa0612c811498c8f229915beca152e771a338e89c2b57b7a3390347a4483b18ccb36bbafc7fb4009b6c37777e9dfa672abbd619ecf53b112b58274408159f10196220e05351fc40c31a55510691a3f598517d6056ab527bac035110321743782d31d26586278ee89d531bc56bff2f895f1efe42bc828ec541c914514234824bb449f56967117cf56562a6f31a075984f274f8f4829e30525e32d8fd6a95acaebfdff9fc84be99cbceabc1d5b8825612a71097b6b21de791ba0319d77c5a828b4571f471918954c419aa4d4611454bc136e027521c75"
	#define digest_7 "24c508adefdf5e3f2596e8b5a888fe10eb7b5b22e1f35d858e6eff3025c4cc18a3c9ace51ddd243d08c8c70cf68e91d170603dc3e2a31c6ca89f20c4a595a2654fb7d53529427e812dea48e8e89abe062b88902f9bffb5eef28a6580fb241a15201f18f5299d03c3e7173d4143886880e4fb0be1f503eb4a109af6f9e97fa8dc2ee642e3c9181b8597a5bbfa009cd36bc60b13dcec3cd7be32210c44b3de09cef884b3b14a5bdc2359dbc07d30db23a2cf2a67d4b3efee8ff60b6500d8b7d34a071a8613660ee08d655b76187dbe9bfc72a4f1723932619498c599e9f9641c69bd4826ff7698f77cfd711ab62c2e391bd671895c50ef847a43692d58829d998c646d074b5075420e7092cab2741bbef51546fd4b28c1cbdf531fabfb53a306478d37e53489ff2d44db10f4eaf95edcaa337d94a1398549f9775e8663be20d0a53c43d7e319cb7bb8bdcaf51cafd7a17ec302c9484c05fd2b571417a6649cec05335f3b97c8155f2d5a3f3ad287b07638c71137022d4cb4"
	#define digest_8 "542e4338ca18e43776834307a2b6158f70c14f22400081b2dc345cc54a6298cd125383fc7cc5e05937618e0474a71308d82cbd6bacd48a6d69f540bd72f2b19e41f006067f6f782d5f8bf1fe6660fe84a6b2f402aa545efb76ff39cd85030ad8a31bc3ae3d967c4fe08aff6aab287d5cab2542b3fbd8951b712bcb1303a330d89c8b9a703ee909ddb49037fe4f5bfed89599507e2c3ba2d7eb3f52505dcc324247aa139008eee27876f5f49ca7371605c5f03bcc54fc093456e8639fae1443da0d04bd976a0711adc3d73ed82f3ffc68426043eea5a9177f871462525fa6294470a7084f363e9a9add39d1b3a6fd0d6adcc696eee88f827a3b23213492117c0324d202199fcca7102f85ded451be74461539b8c090773b49dbbf4b4849024888173c57ad8c45102d2e38faa9900a2b3f2e63507124ef7fc60730d64dc788d55bbede4fc32e355eb6f9ef9b951fae3ab3e2eb68aae682ed82376c33cfda9d074990ee04b3b1b8a20b8e677ecf491882b6f259f81c8631a7"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_digest_computed_1 = mk_lib_crypto_xof_stream_shake_256_test_compute_from_str_lit(message_1);
	mk_lang_constexpr_static auto const s_digest_computed_2 = mk_lib_crypto_xof_stream_shake_256_test_compute_from_str_lit(message_2);
	mk_lang_constexpr_static auto const s_digest_computed_3 = mk_lib_crypto_xof_stream_shake_256_test_compute_from_str_lit(message_3);
	mk_lang_constexpr_static auto const s_digest_computed_4 = mk_lib_crypto_xof_stream_shake_256_test_compute_from_str_lit(message_4);
	mk_lang_constexpr_static auto const s_digest_computed_5 = mk_lib_crypto_xof_stream_shake_256_test_compute_from_str_lit(message_5);
	mk_lang_constexpr_static auto const s_digest_computed_6 = mk_lib_crypto_xof_stream_shake_256_test_compute_from_str_lit(message_6);
	mk_lang_constexpr_static auto const s_digest_computed_7 = mk_lib_crypto_xof_stream_shake_256_test_compute_from_str_lit(message_7);
	mk_lang_constexpr_static auto const s_digest_computed_8 = mk_lib_crypto_xof_stream_shake_256_test_compute_from_str_lit(message_8);

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
	mk_lib_crypto_xof_stream_shake_256_t shake_256;
	mk_lib_crypto_xof_stream_shake_256_test_digest_t digest;
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
		mk_lib_crypto_xof_stream_shake_256_init(&shake_256);
		mk_lib_crypto_xof_stream_shake_256_append(&shake_256, ((mk_lang_types_uchar_pct)(s_messages[i])), s_message_lens[i]);
		mk_lib_crypto_xof_stream_shake_256_finish(&shake_256, xof_bits / 8, digest.m_data);
		for(j = 0; j != xof_bits / 8; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_digests[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_digests[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			b = j / sizeof(mk_lib_crypto_xof_block_shake_256_digest_t);
			s = j % sizeof(mk_lib_crypto_xof_block_shake_256_digest_t);
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
