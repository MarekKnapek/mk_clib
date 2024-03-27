#include "mk_lib_crypto_xof_stream_blake3_test.hpp"
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
#include "mk_lib_crypto_xof_stream_blake3.h"
#include "mk_sl_uint8.h"


#define xof_bits 3000


struct mk_lib_crypto_xof_stream_blake3_test_digest_s
{
	mk_sl_cui_uint8_t m_uint8s[mk_lang_div_roundup(xof_bits, 8)];
};
typedef struct mk_lib_crypto_xof_stream_blake3_test_digest_s mk_lib_crypto_xof_stream_blake3_test_digest_t;


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_xof_stream_blake3_test_compute_from_str_lit(char const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, str_lit_len - 1> msg mk_lang_constexpr_init;
	mk_lib_crypto_xof_stream_blake3_t blake3 mk_lang_constexpr_init;
	mk_lib_crypto_xof_stream_blake3_test_digest_t digest mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, xof_bits / 8> ret mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_len >= 1);

	msg = mk_lib_cpp_constexpr_str_lit_to_u8s(str_lit);
	mk_lib_crypto_xof_stream_blake3_init(&blake3);
	mk_lib_crypto_xof_stream_blake3_append_u8(&blake3, msg.data(), msg.size());
	mk_lib_crypto_xof_stream_blake3_finish(&blake3);
	mk_lib_crypto_xof_stream_blake3_squeeze(&blake3, xof_bits / 8, &digest.m_uint8s[0]);
	for(i = 0; i != xof_bits / 8; ++i)
	{
		ret[i] = digest.m_uint8s[i];
	}
	return ret;
}

#endif


mk_lang_extern_c mk_lang_types_void_t mk_lib_crypto_xof_stream_blake3_test(mk_lang_types_void_t) mk_lang_noexcept
{
	#define message_1 ""
	#define message_2 "a"
	#define message_3 "abc"
	#define message_4 "message digest"
	#define message_5 "abcdefghijklmnopqrstuvwxyz"
	#define message_6 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
	#define message_7 "12345678901234567890123456789012345678901234567890123456789012345678901234567890"
	#define message_8 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

	#define digest_1 "af1349b9f5f9a1a6a0404dea36dcc9499bcb25c9adc112b7cc9a93cae41f3262e00f03e7b69af26b7faaf09fcd333050338ddfe085b8cc869ca98b206c08243a26f5487789e8f660afe6c99ef9e0c52b92e7393024a80459cf91f476f9ffdbda7001c22e159b402631f277ca96f2defdf1078282314e763699a31c5363165421cce14d30f8a03e49ee25d2ea3cd48a568957b378a65af65fc35fb3e9e12b81ca2d82cdee16c68908a6772f827564336933c89e6908b2f9c7d1811c0eb795cbd5898fe6f5e8af763319ca863718a59aff3d99660ef642483e217ef0c8785827284fea90d42225e3cdd6a179bee852fd24e7d45b38c27b9c2f9469ea8dbdb893f00e28534c7d15b59badd5a5bdeb090e98eb93c5b2f42101394acb7c72e9b60094d5442096754600db8c0fa6dbdfea154c324c07bf17b7ab0d1488ae5ef76cb7611baef17087d84c08b4f950d3d85e00e7001813fe029a10722bb003531d5ae406386e78cca4ca7cace8a41d294f6ee3b1c645832109b5b1"
	#define digest_2 "17762fddd969a453925d65717ac3eea21320b66b54342fde15128d6caf21215f992bfdc2cae59c82b0737ada9e969aa6e9a96f3b8ad48cf3b2c0942d35e4ff5e3d960b42ae4d5205f0e589933d9b1761e571019a9f24bc197831d7475244aae458290f85997bba6237e4c16c9e72897a2ad284ccb607728e79e8716675c90051e35e41ffd71dbbecf928275f149bc7e1afd9b95a19f445e194c57f91b0cfaefcf219a509b9bfd29e63b7398a153d5345e81e8b6fe4cc77a034aeb16a6e2b14096b50d5208d2ddeab1e32cceb6b1aaf62802305c2a5b2adae3323a7e8d1c8cc0990e47e33b69ca8efe175b35d45f6b1cf2d9f6353758dab57cb48ca0a2b48293fd6b99d064bcc07687f73040aba8dc61f1a0b9da779dfcad120317c5647772d07cb636b6e07ef8a9f9e79146b15c4d026870bfb0bdb756aa4882993da5e92cb1b3b058e4c8b0551fcef22946ebc37c3abe106727372d62e855dd22310591e9e845aae98e90fdc51257eec66c50d2e8f3e1f7511fe1af1c3"
	#define digest_3 "6437b3ac38465133ffb63b75273a8db548c558465d79db03fd359c6cd5bd9d851fb250ae7393f5d02813b65d521a0d492d9ba09cf7ce7f4cffd900f23374bf0bc08a1fb0b38ed276181ccbd9f7b7edbddf9f86404ad7929605f6ffa3fb1ac87983105f013384f2f11d38879c985d47003804b905f0c38975e28d36804bb60d8c3036536a35fb881af2a7b0a8bcc14e596bc521ca63d659d74324c3aa6bb259fd9f01887ead3dfec31982ac53899cd6e0d7af9cfd271a561539eb6ee2a091201713b15c8b7854d1c4213f7eb159c61a3598eda87372208ecc5c66ec32d70e037bd9bdb392097715428daca4a0f1d0b827dff25e3af68609a75f2564f907cd0b31b4af7095450912570dddc70adea14c7bb98f3042623ccdbc98a64fe442f5758d337bf1e01ec821c3e771649fadc7a37ac04481097fc4adcc73f9924ca37615477e0c008a346dc7e01164111b9ebff58715e506493ad1fc266c0a63f0746776aaf4bba0f603ec2470d1678e0c2c19b7e2ffd210d5ccdad7"
	#define digest_4 "7bc2a2eeb95ddbf9b7ecf6adcb76b453091c58dc43955e1d9482b1942f08d19b0447a7a2deca621550350063fafd727f660f108bb992d0905f0f35b966d84ff3669be674e036b21539b97a1f91a43682f8da33fdf4a8b44694b4244cff0f82967eed813428408f1c8362a5c7bedf3e750b37e87cbef6daa3bdb911cfa60e8eae8693b8fff4d28a8adcdb4242c5d8d883f4482e94f90be987e0639a43399f7557584e0e4ab3aa734a44b575e3741320a5489763a611a8b30151b9ff987de9cbeb831c771e05ff4849e7078df42debbb7e783ee5fed1b302050920c5f555fe2c866cda5fde95dfb3413d05de90c464f8495a1b97761c4c80075e1654bfc6aa61ea02afab0cd6893c71b7fe386d552a2dad3ec81b9e17b58eb44ba8dac8ce93ec45353c60331a474744a7b39c1a077bb7b3a482c48f6c6b7a5a61585358848c8f2e9f01497ee617afd70517ebed3fcb7720beb4ee2181d189acd749e1cc239a73e9c57c2deca0bd7efb02edb5f0d083823bd26ad614098601"
	#define digest_5 "2468eec8894acfb4e4df3a51ea916ba115d48268287754290aae8e9e6228e85f29d5c0ccdcab1524708f03c8e85e1ddc24fdc3671fe72e93823d9371aff729595dda8b899fdcb3bbb550f9fe850e93139efafb20c8f5537f0e1c5797c55fb9ef4cbcd9bdcd3ffa1076ba38d8da0ededc38643f1704de132d8c02f49e0a42b2cb147b3c265538d21e97dce5309e8d05b1b28108267a2987551884ae502891d143be5791ba2d120fd6e5ff73810b1ccb409ea932f5a9809b557ac0ddf72b8888ffc3c398dbf3949ec6763a17afb6d59ae098e7ef369550cac7cce99089478153abfa1d61e41ddca1d966bc6944bbdb303c3bc1d617595451205645a7e8ff4516fcf6a2878ba1cb974b6e1994e03a4fb34a36b16266b7c6483489641d889438aeb57067ba8cd2416c1c18dd88e46a5d2159650e4be0f8de11e276acc7b91c572bbce8e905d48679ee0b6563ec2054af2be1fd7cbb806df2732c30d5395bf673523c59d1da89cfaa58c7fff0fb9163f8ce1bba28a851e5ff7b"
	#define digest_6 "8bee3200baa9f3a1acd279f049f914f110e730555ff15109bd59cdd73895e2399250cc8e1f9151722bd5ad6c691469eb54288f558ddb96661114883e5937ce294e7374c5f4a2714d4a2ad723ee319d3cce84aadb3ef779d506aefc8db73f71adae0036170c9f41bef54752aac2a54e15d21109ba65bc662cf564867d116ae8858cdad26d095ab7bed1ca55a60b433328d0c0ec2c23e93a5219492890e7d5c85d8440e19b67915135b1f61e1b70281b19b848bf88959b5ed72121524019b09de9854684a8b4a32789c1c2d725970b0eac638c4c842c2b6f3b597a9e5ee86750fe28c4b12ae5abf04619b774db5ff3d269b987f1f17bc1ef551bedf219b088cd20668f9f397915889db2a9cb1af41a53e775e958464bcb834c7fb4638e63cee5f09013ff1e2e28e777d7841471c9dd1f8bc477c7f3ba91793d8f060fefa4f683257f632e00ddb51badc4481b5edec66a7fe750bf4cebf1ead563bf587122cc57ee32c104bb2b0b44d71375e1fe24921b62fe9ef1a3723639"
	#define digest_7 "f263acf51621980b9c8de5da4a17d314984e05abe4a21cc83a07fe3e1e366dd12fe87889ba47b2d7fe29877fb6225a0af559d1f737f11b4918ae315ff36f615dfaab08b7b2f6767da315945cebb990e40850bf045912de537fe6cc285c522386e598e3585da873145b0262eea48fc245624353d4f98b8dee5f2e9cfcc9c2ea28dad1fff318b6de2111d91a8b44946ad121f009ee89d53b7811a0e1525e702257685826dc8a9ea0e6289369b01b865e7cd7e6b02efaf55403ff2c7d6b84cad3a89bab17a12eee5ab708990ca10c6484b060bdf75080df805cb73f0593a5f04811ac4bc85f8d99afbdf17ef823d82514b7119ac052ee2cce4a07f3636c07972c837b1b21cd9c8ceaf9ef9f97641220dc25354e594947dd5e1166dbcbbf5ace78fec14c67f89d743d23020ea8b558134454e9027bbf1cfa821b2b6e1c5826249420e3024b96b831fc6aecc6bc6b51647770570e97fc7b74a990b2a3985c5edcb785ac56ca6683196fc8046b98a10aa3e33ecaca0eec886ef6"
	#define digest_8 "c9bd36ec7c6c45e1ef67d38ad298fceb2ff34d84f676eeeba82ff9223efd13dfca50905929a8d36f512b3737f31af52e0005e81077fc0d8bdd0845ef1f5dc43d7020279eb290e4f816e47839c2dfc6d2cf3f501ed46e615928a07e1b3e8eb7995f152437d393b769c60629e9a77795c0fc69a254b1b0c53cc9a26d47baf86bbf42060e2a9b828325709774dccb301bb8b7044df0d01ef8bd5e413e97b4630ee4837b03245b4ce1eeb750fad9eb442eaaf7a70e110828e7f327159d870aa72a91b5794d5b35a5968eda4a771d56519e8e08d5cff98bd0c0bf4c9fd193bb38552340468f84dfd3cb56af8764910d6a5f222cb020a1d80941bdd8a7177e77b7abc826af4e0721d0131de41f881cda71eef40a5a0b58465377f93013a06274cd4ebd18adf871a613a2377ad0968c041b37193f1a3d20cb0d4a5a4e41136a64155ff89d1e93418cef27adc7b81b20a101662b8a7272f4c71fcf91b35e43a87d669bdb12d7ebfe6fa06df1539769380348512940dd49f5b417a3"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_digest_computed_1 = mk_lib_crypto_xof_stream_blake3_test_compute_from_str_lit(message_1);
	mk_lang_constexpr_static auto const s_digest_computed_2 = mk_lib_crypto_xof_stream_blake3_test_compute_from_str_lit(message_2);
	mk_lang_constexpr_static auto const s_digest_computed_3 = mk_lib_crypto_xof_stream_blake3_test_compute_from_str_lit(message_3);
	mk_lang_constexpr_static auto const s_digest_computed_4 = mk_lib_crypto_xof_stream_blake3_test_compute_from_str_lit(message_4);
	mk_lang_constexpr_static auto const s_digest_computed_5 = mk_lib_crypto_xof_stream_blake3_test_compute_from_str_lit(message_5);
	mk_lang_constexpr_static auto const s_digest_computed_6 = mk_lib_crypto_xof_stream_blake3_test_compute_from_str_lit(message_6);
	mk_lang_constexpr_static auto const s_digest_computed_7 = mk_lib_crypto_xof_stream_blake3_test_compute_from_str_lit(message_7);
	mk_lang_constexpr_static auto const s_digest_computed_8 = mk_lib_crypto_xof_stream_blake3_test_compute_from_str_lit(message_8);

	mk_lang_constexpr_static auto const s_digest_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(digest_1);
	mk_lang_constexpr_static auto const s_digest_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(digest_2);
	mk_lang_constexpr_static auto const s_digest_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(digest_3);
	mk_lang_constexpr_static auto const s_digest_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(digest_4);
	mk_lang_constexpr_static auto const s_digest_precomputed_5 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(digest_5);
	mk_lang_constexpr_static auto const s_digest_precomputed_6 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(digest_6);
	mk_lang_constexpr_static auto const s_digest_precomputed_7 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(digest_7);
	mk_lang_constexpr_static auto const s_digest_precomputed_8 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(digest_8);

	mk_lang_static_assert(s_digest_computed_1 == s_digest_precomputed_1);
	mk_lang_static_assert(s_digest_computed_2 == s_digest_precomputed_2);
	mk_lang_static_assert(s_digest_computed_3 == s_digest_precomputed_3);
	mk_lang_static_assert(s_digest_computed_4 == s_digest_precomputed_4);
	mk_lang_static_assert(s_digest_computed_5 == s_digest_precomputed_5);
	mk_lang_static_assert(s_digest_computed_6 == s_digest_precomputed_6);
	mk_lang_static_assert(s_digest_computed_7 == s_digest_precomputed_7);
	mk_lang_static_assert(s_digest_computed_8 == s_digest_precomputed_8);

	#endif

	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_crash(); } ((mk_lang_types_void_t)(0))

	static mk_lang_types_pchar_pct const s_messages[] =
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

	static mk_lang_types_sint_t const s_message_lens[] =
	{
		((mk_lang_types_sint_t)(sizeof(message_1) / sizeof(message_1[0]) - 1)),
		((mk_lang_types_sint_t)(sizeof(message_2) / sizeof(message_2[0]) - 1)),
		((mk_lang_types_sint_t)(sizeof(message_3) / sizeof(message_3[0]) - 1)),
		((mk_lang_types_sint_t)(sizeof(message_4) / sizeof(message_4[0]) - 1)),
		((mk_lang_types_sint_t)(sizeof(message_5) / sizeof(message_5[0]) - 1)),
		((mk_lang_types_sint_t)(sizeof(message_6) / sizeof(message_6[0]) - 1)),
		((mk_lang_types_sint_t)(sizeof(message_7) / sizeof(message_7[0]) - 1)),
		((mk_lang_types_sint_t)(sizeof(message_8) / sizeof(message_8[0]) - 1)),
	};

	static mk_lang_types_pchar_pct const s_digests[] =
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

	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_crypto_xof_stream_blake3_t blake3;
	mk_sl_cui_uint8_t digest[mk_lang_div_roundup(xof_bits, 8)];
	mk_lang_types_sint_t j;
	mk_lang_types_uchar_t hi;
	mk_lang_types_uchar_t lo;
	mk_lang_types_uchar_t byte;
	mk_lang_types_uchar_t ta;

	mk_lang_static_assert(sizeof(s_messages) / sizeof(s_messages[0]) == sizeof(s_digests) / sizeof(s_digests[0]));
	mk_lang_static_assert(sizeof(s_messages) / sizeof(s_messages[0]) == sizeof(s_message_lens) / sizeof(s_message_lens[0]));

	n = ((mk_lang_types_sint_t)(sizeof(s_messages) / sizeof(s_messages[0])));
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(s_message_lens[i] >= 0);
		mk_lib_crypto_xof_stream_blake3_init(&blake3);
		mk_lib_crypto_xof_stream_blake3_append(&blake3, ((mk_lang_types_uchar_pct)(s_messages[i])), s_message_lens[i]);
		mk_lib_crypto_xof_stream_blake3_finish(&blake3);
		mk_lib_crypto_xof_stream_blake3_squeeze(&blake3, xof_bits / 8, &digest[0]);
		for(j = 0; j != xof_bits / 8; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_digests[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_digests[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_to_bi_uchar(&digest[j], &ta);
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
