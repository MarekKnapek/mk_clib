#ifndef mk_include_guard_mk_lib_crypto_hash_stream_sha1_test_cpp
#define mk_include_guard_mk_lib_crypto_hash_stream_sha1_test_cpp


#if defined mk_lang_jumbo_want
#undef mk_lang_jumbo_want
#endif
#define mk_lang_jumbo_want 2


#include "mk_lang_warning_msvc_push_c4514.h"


#include "mk_lib_crypto_hash_stream_sha1_test.hpp"

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
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_sl_cui_uint8.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_hash_stream_sha1_test_compute_from_str_lit(mk_lang_types_pchar_t const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, str_lit_len - 1> msg mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha1_t sha1 mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha1_digest_t digest mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_hash_stream_sha1_digest_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_len >= 1);

	msg = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(str_lit);
	mk_lib_crypto_hash_stream_sha1_init(&sha1);
	mk_lib_crypto_hash_stream_sha1_append_u8s(&sha1, msg.data(), msg.size());
	mk_lib_crypto_hash_stream_sha1_finish(&sha1, &digest);
	ret = mk_lib_cpp_constexpr_array_u8_from_u8s(digest.m_data.m_uint8s);
	return ret;
}

template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(mk_lang_types_pchar_t const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (str_lit_len - 1) / mk_sl_cui_uint8_strlen_hex_v> msg mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha1_t sha1 mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha1_digest_t digest mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_hash_stream_sha1_digest_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_len >= 1);
	mk_lang_static_assert((str_lit_len - 1) % mk_sl_cui_uint8_strlen_hex_v == 0);

	msg = mk_lib_cpp_constexpr_array_u8_from_hex_lit(str_lit);
	mk_lib_crypto_hash_stream_sha1_init(&sha1);
	mk_lib_crypto_hash_stream_sha1_append_u8s(&sha1, msg.data(), msg.size());
	mk_lib_crypto_hash_stream_sha1_finish(&sha1, &digest);
	ret = mk_lib_cpp_constexpr_array_u8_from_u8s(digest.m_data.m_uint8s);
	return ret;
}

#endif


mk_lang_extern_force_c mk_lang_types_void_t mk_lib_crypto_hash_stream_sha1_test(mk_lang_types_void_t) mk_lang_noexcept
{
	#define message_1 ""
	#define message_2 "a"
	#define message_3 "abc"
	#define message_4 "message digest"
	#define message_5 "abcdefghijklmnopqrstuvwxyz"
	#define message_6 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
	#define message_7 "12345678901234567890123456789012345678901234567890123456789012345678901234567890"
	#define message_8 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	#define message_9 "36"
	#define message_10 "195a"
	#define message_11 "df4bd2"
	#define message_12 "549e959e"
	#define message_13 "f7fb1be205"
	#define message_14 "c0e5abeaea63"
	#define message_15 "63bfc1ed7f78ab"
	#define message_16 "7e3d7b3eada98866"
	#define message_17 "9e61e55d9ed37b1c20"
	#define message_18 "9777cf90dd7c7e863506"
	#define message_19 "4eb08c9e683c94bea00dfa"
	#define message_20 "0938f2e2ebb64f8af8bbfc91"
	#define message_21 "74c9996d14e87d3e6cbea7029d"
	#define message_22 "51dca5c0f8e5d49596f32d3eb874"
	#define message_23 "3a36ea49684820a2adc7fc4175ba78"
	#define message_24 "3552694cdf663fd94b224747ac406aaf"
	#define message_25 "f216a1cbde2446b1edf41e93481d33e2ed"
	#define message_26 "a3cf714bf112647e727e8cfd46499acd35a6"
	#define message_27 "148de640f3c11591a6f8c5c48632c5fb79d3b7"
	#define message_28 "63a3cc83fd1ec1b6680e9974a0514e1a9ecebb6a"
	#define message_29 "875a90909a8afc92fb7070047e9d081ec92f3d08b8"
	#define message_30 "444b25f9c9259dc217772cc4478c44b6feff62353673"
	#define message_31 "487351c8a5f440e4d03386483d5fe7bb669d41adcbfdb7"
	#define message_32 "46b061ef132b87f6d3b0ee2462f67d910977da20aed13705"
	#define message_33 "3842b6137bb9d27f3ca5bafe5bbb62858344fe4ba5c41589a5"
	#define message_34 "44d91d3d465a4111462ba0c7ec223da6735f4f5200453cf132c3"
	#define message_35 "cce73f2eabcb52f785d5a6df63c0a105f34a91ca237fe534ee399d"
	#define message_36 "664e6e7946839203037a65a12174b244de8cbc6ec3f578967a84f9ce"
	#define message_37 "9597f714b2e45e3399a7f02aec44921bd78be0fefee0c5e9b499488f6e"
	#define message_38 "75c5ad1f3cbd22e8a95fc3b089526788fb4ebceed3e7d4443da6e081a35e"
	#define message_39 "dd245bffe6a638806667768360a95d0574e1a0bd0d18329fdb915ca484ac0d"
	#define message_40 "0321794b739418c24e7c2e565274791c4be749752ad234ed56cb0a6347430c6b"
	#define message_41 "4c3dcf95c2f0b5258c651fcd1d51bd10425d6203067d0748d37d1340d9ddda7db3"
	#define message_42 "b8d12582d25b45290a6e1bb95da429befcfdbf5b4dd41cdf3311d6988fa17cec0723"
	#define message_43 "6fda97527a662552be15efaeba32a3aea4ed449abb5c1ed8d9bfff544708a425d69b72"
	#define message_44 "09fa2792acbb2417e8ed269041cc03c77006466e6e7ae002cf3f1af551e8ce0bb506d705"
	#define message_45 "5efa2987da0baf0a54d8d728792bcfa707a15798dc66743754406914d1cfe3709b1374eaeb"
	#define message_46 "2836de99c0f641cd55e89f5af76638947b8227377ef88bfba662e5682babc1ec96c6992bc9a0"
	#define message_47 "42143a2b9e1d0b354df3264d08f7b602f54aad922a3d63006d097f683dc11b90178423bff2f7fe"
	#define message_48 "eb60c28ad8aeda807d69ebc87552024ad8aca68204f1bcd29dc5a81dd228b591e2efb7c4df75ef03"
	#define message_49 "7de4ba85ec54747cdc42b1f23546b7e490e31280f066e52fac117fd3b0792e4de62d5843ee98c72015"
	#define message_50 "e70653637bc5e388ccd8dc44e5eace36f7398f2bac993042b9bc2f4fb3b0ee7e23a96439dc01134b8c7d"
	#define message_51 "dd37bc9f0b3a4788f9b54966f252174c8ce487cbe59c53c22b81bf77621a7ce7616dcb5b1e2ee63c2c309b"
	#define message_52 "5f485c637ae30b1e30497f0fb7ec364e13c906e2813daa34161b7ac4a4fd7a1bddd79601bbd22cef1f57cbc7"
	#define message_53 "f6c237fb3cfe95ec8414cc16d203b4874e644cc9a543465cad2dc563488a659e8a2e7c981e2a9f22e5e868ffe1"
	#define message_54 "da7ab3291553c659873c95913768953c6e526d3a26590898c0ade89ff56fbd110f1436af590b17fed49f8c4b2b1e"
	#define message_55 "8cfa5fd56ee239ca47737591cba103e41a18acf8e8d257b0dbe8851134a81ff6b2e97104b39b76e19da256a17ce52d"
	#define message_56 "57e89659d878f360af6de45a9a5e372ef40c384988e82640a3d5e4b76d2ef181780b9a099ac06ef0f8a7f3f764209720"
	#define message_57 "b91e64235dbd234eea2ae14a92a173ebe835347239cff8b02074416f55c6b60dc6ced06ae9f8d705505f0d617e4b29aef9"
	#define message_58 "e42a67362a581e8cf3d847502215755d7ad425ca030c4360b0f7ef513e6980265f61c9fa18dd9ce668f38dbc2a1ef8f83cd6"
	#define message_59 "634db92c22010e1cbf1e1623923180406c515272209a8acc42de05cc2e96a1e94c1f9f6b93234b7f4c55de8b1961a3bf352259"
	#define message_60 "cc6ca3a8cb391cd8a5aff1faa7b3ffbdd21a5a3ce66cfaddbfe8b179e4c860be5ec66bd2c6de6a39a25622f9f2fcb3fc05af12b5"
	#define message_61 "7c0e6a0d35f8ac854c7245ebc73693731bbbc3e6fab644466de27bb522fcb99307126ae718fe8f00742e6e5cb7a687c88447cbc961"
	#define message_62 "c5581d40b331e24003901bd6bf244aca9e9601b9d81252bb38048642731f1146b8a4c69f88e148b2c8f8c14f15e1d6da57b2daa9991e"
	#define message_63 "ec6b4a88713df27c0f2d02e738b69db43abda3921317259c864c1c386e9a5a3f533dc05f3beeb2bec2aac8e06db4c6cb3cddcf697e03d5"
	#define message_64 "0321736beba578e90abc1a90aa56157d871618f6de0d764cc8c91e06c68ecd3b9de3824064503384db67beb7fe012232dacaef93a000fba7"
	#define message_65 "d0a249a97b5f1486721a50d4c4ab3f5d674a0e29925d5bf2678ef6d8d521e456bd84aa755328c83fc890837726a8e7877b570dba39579aabdd"
	#define message_66 "c32138531118f08c7dcc292428ad20b45ab27d9517a18445f38b8f0c2795bcdfe3ffe384e65ecbf74d2c9d0da88398575326074904c1709ba072"
	#define message_67 "b0f4cfb939ea785eabb7e7ca7c476cdd9b227f015d905368ba00ae96b9aaf720297491b3921267576b72c8f58d577617e844f9f0759b399c6b064c"
	#define message_68 "bd02e51b0cf2c2b8d204a026b41a66fbfc2ac37ee9411fc449c8d1194a0792a28ee731407dfc89b6dfc2b10faa27723a184afef8fd83def858a32d3f"
	#define message_69 "e33146b83e4bb671392218da9a77f8d9f5974147182fb95ba662cb66011989c16d9af104735d6f79841aa4d1df276615b50108df8a29dbc9de31f4260d"
	#define message_70 "411c13c75073c1e2d4b1ecf13139ba9656cd35c14201f1c7c6f0eeb58d2dbfe35bfdeccc92c3961cfabb590bc1eb77eac15732fb0275798680e0c7292e50"
	#define message_71 "f2c76ef617fa2bfc8a4d6bcbb15fe88436fdc2165d3074629579079d4d5b86f5081ab177b4c3f530376c9c924cbd421a8daf8830d0940c4fb7589865830699"
	#define message_72 "45927e32ddf801caf35e18e7b5078b7f5435278212ec6bb99df884f49b327c6486feae46ba187dc1cc9145121e1492e6b06e9007394dc33b7748f86ac3207cfe"

	#define digest_1 "da39a3ee5e6b4b0d3255bfef95601890afd80709"
	#define digest_2 "86f7e437faa5a7fce15d1ddcb9eaeaea377667b8"
	#define digest_3 "a9993e364706816aba3e25717850c26c9cd0d89d"
	#define digest_4 "c12252ceda8be8994d5fa0290a47231c1d16aae3"
	#define digest_5 "32d10c7b8cf96570ca04ce37f2a19d84240d3a89"
	#define digest_6 "761c457bf73b14d27e9e9265c46f4b4dda11f940"
	#define digest_7 "50abf5706a150990a08b2c5ea40fa0e585554732"
	#define digest_8 "003ef1ba9ea9f2f4dab3a2004e505ca8a4e7e5a3"
	#define digest_9 "c1dfd96eea8cc2b62785275bca38ac261256e278"
	#define digest_10 "0a1c2d555bbe431ad6288af5a54f93e0449c9232"
	#define digest_11 "bf36ed5d74727dfd5d7854ec6b1d49468d8ee8aa"
	#define digest_12 "b78bae6d14338ffccfd5d5b5674a275f6ef9c717"
	#define digest_13 "60b7d5bb560a1acf6fa45721bd0abb419a841a89"
	#define digest_14 "a6d338459780c08363090fd8fc7d28dc80e8e01f"
	#define digest_15 "860328d80509500c1783169ebf0ba0c4b94da5e5"
	#define digest_16 "24a2c34b976305277ce58c2f42d5092031572520"
	#define digest_17 "411ccee1f6e3677df12698411eb09d3ff580af97"
	#define digest_18 "05c915b5ed4e4c4afffc202961f3174371e90b5c"
	#define digest_19 "af320b42d7785ca6c8dd220463be23a2d2cb5afc"
	#define digest_20 "9f4e66b6ceea40dcf4b9166c28f1c88474141da9"
	#define digest_21 "e6c4363c0852951991057f40de27ec0890466f01"
	#define digest_22 "046a7b396c01379a684a894558779b07d8c7da20"
	#define digest_23 "d58a262ee7b6577c07228e71ae9b3e04c8abcda9"
	#define digest_24 "a150de927454202d94e656de4c7c0ca691de955d"
	#define digest_25 "35a4b39fef560e7ea61246676e1b7e13d587be30"
	#define digest_26 "7ce69b1acdce52ea7dbd382531fa1a83df13cae7"
	#define digest_27 "b47be2c64124fa9a124a887af9551a74354ca411"
	#define digest_28 "8bb8c0d815a9c68a1d2910f39d942603d807fbcc"
	#define digest_29 "b486f87fb833ebf0328393128646a6f6e660fcb1"
	#define digest_30 "76159368f99dece30aadcfb9b7b41dab33688858"
	#define digest_31 "dbc1cb575ce6aeb9dc4ebf0f843ba8aeb1451e89"
	#define digest_32 "d7a98289679005eb930ab75efd8f650f991ee952"
	#define digest_33 "fda26fa9b4874ab701ed0bb64d134f89b9c4cc50"
	#define digest_34 "c2ff7ccde143c8f0601f6974b1903eb8d5741b6e"
	#define digest_35 "643c9dc20a929608f6caa9709d843ca6fa7a76f4"
	#define digest_36 "509ef787343d5b5a269229b961b96241864a3d74"
	#define digest_37 "b61ce538f1a1e6c90432b233d7af5b6524ebfbe3"
	#define digest_38 "5b7b94076b2fc20d6adb82479e6b28d07c902b75"
	#define digest_39 "6066db99fc358952cf7fb0ec4d89cb0158ed91d7"
	#define digest_40 "b89962c94d60f6a332fd60f6f07d4f032a586b76"
	#define digest_41 "17bda899c13d35413d2546212bcd8a93ceb0657b"
	#define digest_42 "badcdd53fdc144b8bf2cc1e64d10f676eebe66ed"
	#define digest_43 "01b4646180f1f6d2e06bbe22c20e50030322673a"
	#define digest_44 "10016dc3a2719f9034ffcc689426d28292c42fc9"
	#define digest_45 "9f42fa2bce6ef021d93c6b2d902273797e426535"
	#define digest_46 "cdf48bacbff6f6152515323f9b43a286e0cb8113"
	#define digest_47 "b88fb75274b9b0fd57c0045988cfcef6c3ce6554"
	#define digest_48 "c06d3a6a12d9e8db62e8cff40ca23820d61d8aa7"
	#define digest_49 "6e40f9e83a4be93874bc97cdebb8da6889ae2c7a"
	#define digest_50 "3efc940c312ef0dfd4e1143812248db89542f6a5"
	#define digest_51 "a0cf03f7badd0c3c3c4ea3717f5a4fb7e67b2e56"
	#define digest_52 "a544e06f1a07ceb175a51d6d9c0111b3e15e9859"
	#define digest_53 "199d986ed991b99a071f450c6b1121a727e8c735"
	#define digest_54 "33bac6104b0ad6128d091b5d5e2999099c9f05de"
	#define digest_55 "76d7db6e18c1f4ae225ce8ccc93c8f9a0dfeb969"
	#define digest_56 "f652f3b1549f16710c7402895911e2b86a9b2aee"
	#define digest_57 "63faebb807f32be708cf00fc35519991dc4e7f68"
	#define digest_58 "0e6730bc4a0e9322ea205f4edfff1fffda26af0a"
	#define digest_59 "b61a3a6f42e8e6604b93196c43c9e84d5359e6fe"
	#define digest_60 "32d979ca1b3ed0ed8c890d99ec6dd85e6c16abf4"
	#define digest_61 "6f18190bd2d02fc93bce64756575cea36d08b1c3"
	#define digest_62 "68f525feea1d8dbe0117e417ca46708d18d7629a"
	#define digest_63 "a7272e2308622ff7a339460adc61efd0ea8dabdc"
	#define digest_64 "aef843b86916c16f66c84d83a6005d23fd005c9e"
	#define digest_65 "be2cd6f380969be59cde2dff5e848a44e7880bd6"
	#define digest_66 "e5eb4543deee8f6a5287845af8b593a95a9749a1"
	#define digest_67 "534c850448dd486787b62bdec2d4a0b140a1b170"
	#define digest_68 "6fbfa6e4edce4cc85a845bf0d228dc39acefc2fa"
	#define digest_69 "018872691d9b04e8220e09187df5bc5fa6257cd9"
	#define digest_70 "d98d512a35572f8bd20de62e9510cc21145c5bf4"
	#define digest_71 "9f3ea255f6af95c5454e55d7354cabb45352ea0b"
	#define digest_72 "a70cfbfe7563dd0e665c7c6715a96a8d756950c0"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_digest_computed_1 = mk_lib_crypto_hash_stream_sha1_test_compute_from_str_lit(message_1);
	mk_lang_constexpr_static auto const s_digest_computed_2 = mk_lib_crypto_hash_stream_sha1_test_compute_from_str_lit(message_2);
	mk_lang_constexpr_static auto const s_digest_computed_3 = mk_lib_crypto_hash_stream_sha1_test_compute_from_str_lit(message_3);
	mk_lang_constexpr_static auto const s_digest_computed_4 = mk_lib_crypto_hash_stream_sha1_test_compute_from_str_lit(message_4);
	mk_lang_constexpr_static auto const s_digest_computed_5 = mk_lib_crypto_hash_stream_sha1_test_compute_from_str_lit(message_5);
	mk_lang_constexpr_static auto const s_digest_computed_6 = mk_lib_crypto_hash_stream_sha1_test_compute_from_str_lit(message_6);
	mk_lang_constexpr_static auto const s_digest_computed_7 = mk_lib_crypto_hash_stream_sha1_test_compute_from_str_lit(message_7);
	mk_lang_constexpr_static auto const s_digest_computed_8 = mk_lib_crypto_hash_stream_sha1_test_compute_from_str_lit(message_8);
	mk_lang_constexpr_static auto const s_digest_computed_9 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_9);
	mk_lang_constexpr_static auto const s_digest_computed_10 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_10);
	mk_lang_constexpr_static auto const s_digest_computed_11 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_11);
	mk_lang_constexpr_static auto const s_digest_computed_12 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_12);
	mk_lang_constexpr_static auto const s_digest_computed_13 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_13);
	mk_lang_constexpr_static auto const s_digest_computed_14 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_14);
	mk_lang_constexpr_static auto const s_digest_computed_15 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_15);
	mk_lang_constexpr_static auto const s_digest_computed_16 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_16);
	mk_lang_constexpr_static auto const s_digest_computed_17 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_17);
	mk_lang_constexpr_static auto const s_digest_computed_18 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_18);
	mk_lang_constexpr_static auto const s_digest_computed_19 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_19);
	mk_lang_constexpr_static auto const s_digest_computed_20 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_20);
	mk_lang_constexpr_static auto const s_digest_computed_21 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_21);
	mk_lang_constexpr_static auto const s_digest_computed_22 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_22);
	mk_lang_constexpr_static auto const s_digest_computed_23 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_23);
	mk_lang_constexpr_static auto const s_digest_computed_24 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_24);
	mk_lang_constexpr_static auto const s_digest_computed_25 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_25);
	mk_lang_constexpr_static auto const s_digest_computed_26 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_26);
	mk_lang_constexpr_static auto const s_digest_computed_27 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_27);
	mk_lang_constexpr_static auto const s_digest_computed_28 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_28);
	mk_lang_constexpr_static auto const s_digest_computed_29 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_29);
	mk_lang_constexpr_static auto const s_digest_computed_30 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_30);
	mk_lang_constexpr_static auto const s_digest_computed_31 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_31);
	mk_lang_constexpr_static auto const s_digest_computed_32 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_32);
	mk_lang_constexpr_static auto const s_digest_computed_33 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_33);
	mk_lang_constexpr_static auto const s_digest_computed_34 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_34);
	mk_lang_constexpr_static auto const s_digest_computed_35 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_35);
	mk_lang_constexpr_static auto const s_digest_computed_36 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_36);
	mk_lang_constexpr_static auto const s_digest_computed_37 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_37);
	mk_lang_constexpr_static auto const s_digest_computed_38 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_38);
	mk_lang_constexpr_static auto const s_digest_computed_39 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_39);
	mk_lang_constexpr_static auto const s_digest_computed_40 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_40);
	mk_lang_constexpr_static auto const s_digest_computed_41 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_41);
	mk_lang_constexpr_static auto const s_digest_computed_42 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_42);
	mk_lang_constexpr_static auto const s_digest_computed_43 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_43);
	mk_lang_constexpr_static auto const s_digest_computed_44 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_44);
	mk_lang_constexpr_static auto const s_digest_computed_45 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_45);
	mk_lang_constexpr_static auto const s_digest_computed_46 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_46);
	mk_lang_constexpr_static auto const s_digest_computed_47 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_47);
	mk_lang_constexpr_static auto const s_digest_computed_48 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_48);
	mk_lang_constexpr_static auto const s_digest_computed_49 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_49);
	mk_lang_constexpr_static auto const s_digest_computed_50 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_50);
	mk_lang_constexpr_static auto const s_digest_computed_51 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_51);
	mk_lang_constexpr_static auto const s_digest_computed_52 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_52);
	mk_lang_constexpr_static auto const s_digest_computed_53 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_53);
	mk_lang_constexpr_static auto const s_digest_computed_54 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_54);
	mk_lang_constexpr_static auto const s_digest_computed_55 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_55);
	mk_lang_constexpr_static auto const s_digest_computed_56 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_56);
	mk_lang_constexpr_static auto const s_digest_computed_57 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_57);
	mk_lang_constexpr_static auto const s_digest_computed_58 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_58);
	mk_lang_constexpr_static auto const s_digest_computed_59 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_59);
	mk_lang_constexpr_static auto const s_digest_computed_60 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_60);
	mk_lang_constexpr_static auto const s_digest_computed_61 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_61);
	mk_lang_constexpr_static auto const s_digest_computed_62 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_62);
	mk_lang_constexpr_static auto const s_digest_computed_63 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_63);
	mk_lang_constexpr_static auto const s_digest_computed_64 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_64);
	mk_lang_constexpr_static auto const s_digest_computed_65 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_65);
	mk_lang_constexpr_static auto const s_digest_computed_66 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_66);
	mk_lang_constexpr_static auto const s_digest_computed_67 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_67);
	mk_lang_constexpr_static auto const s_digest_computed_68 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_68);
	mk_lang_constexpr_static auto const s_digest_computed_69 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_69);
	mk_lang_constexpr_static auto const s_digest_computed_70 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_70);
	mk_lang_constexpr_static auto const s_digest_computed_71 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_71);
	mk_lang_constexpr_static auto const s_digest_computed_72 = mk_lib_crypto_hash_stream_sha1_test_compute_from_hex_lit(message_72);

	mk_lang_constexpr_static auto const s_digest_precomputed_1 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_1);
	mk_lang_constexpr_static auto const s_digest_precomputed_2 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_2);
	mk_lang_constexpr_static auto const s_digest_precomputed_3 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_3);
	mk_lang_constexpr_static auto const s_digest_precomputed_4 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_4);
	mk_lang_constexpr_static auto const s_digest_precomputed_5 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_5);
	mk_lang_constexpr_static auto const s_digest_precomputed_6 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_6);
	mk_lang_constexpr_static auto const s_digest_precomputed_7 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_7);
	mk_lang_constexpr_static auto const s_digest_precomputed_8 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_8);
	mk_lang_constexpr_static auto const s_digest_precomputed_9 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_9);
	mk_lang_constexpr_static auto const s_digest_precomputed_10 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_10);
	mk_lang_constexpr_static auto const s_digest_precomputed_11 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_11);
	mk_lang_constexpr_static auto const s_digest_precomputed_12 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_12);
	mk_lang_constexpr_static auto const s_digest_precomputed_13 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_13);
	mk_lang_constexpr_static auto const s_digest_precomputed_14 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_14);
	mk_lang_constexpr_static auto const s_digest_precomputed_15 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_15);
	mk_lang_constexpr_static auto const s_digest_precomputed_16 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_16);
	mk_lang_constexpr_static auto const s_digest_precomputed_17 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_17);
	mk_lang_constexpr_static auto const s_digest_precomputed_18 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_18);
	mk_lang_constexpr_static auto const s_digest_precomputed_19 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_19);
	mk_lang_constexpr_static auto const s_digest_precomputed_20 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_20);
	mk_lang_constexpr_static auto const s_digest_precomputed_21 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_21);
	mk_lang_constexpr_static auto const s_digest_precomputed_22 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_22);
	mk_lang_constexpr_static auto const s_digest_precomputed_23 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_23);
	mk_lang_constexpr_static auto const s_digest_precomputed_24 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_24);
	mk_lang_constexpr_static auto const s_digest_precomputed_25 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_25);
	mk_lang_constexpr_static auto const s_digest_precomputed_26 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_26);
	mk_lang_constexpr_static auto const s_digest_precomputed_27 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_27);
	mk_lang_constexpr_static auto const s_digest_precomputed_28 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_28);
	mk_lang_constexpr_static auto const s_digest_precomputed_29 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_29);
	mk_lang_constexpr_static auto const s_digest_precomputed_30 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_30);
	mk_lang_constexpr_static auto const s_digest_precomputed_31 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_31);
	mk_lang_constexpr_static auto const s_digest_precomputed_32 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_32);
	mk_lang_constexpr_static auto const s_digest_precomputed_33 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_33);
	mk_lang_constexpr_static auto const s_digest_precomputed_34 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_34);
	mk_lang_constexpr_static auto const s_digest_precomputed_35 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_35);
	mk_lang_constexpr_static auto const s_digest_precomputed_36 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_36);
	mk_lang_constexpr_static auto const s_digest_precomputed_37 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_37);
	mk_lang_constexpr_static auto const s_digest_precomputed_38 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_38);
	mk_lang_constexpr_static auto const s_digest_precomputed_39 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_39);
	mk_lang_constexpr_static auto const s_digest_precomputed_40 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_40);
	mk_lang_constexpr_static auto const s_digest_precomputed_41 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_41);
	mk_lang_constexpr_static auto const s_digest_precomputed_42 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_42);
	mk_lang_constexpr_static auto const s_digest_precomputed_43 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_43);
	mk_lang_constexpr_static auto const s_digest_precomputed_44 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_44);
	mk_lang_constexpr_static auto const s_digest_precomputed_45 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_45);
	mk_lang_constexpr_static auto const s_digest_precomputed_46 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_46);
	mk_lang_constexpr_static auto const s_digest_precomputed_47 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_47);
	mk_lang_constexpr_static auto const s_digest_precomputed_48 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_48);
	mk_lang_constexpr_static auto const s_digest_precomputed_49 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_49);
	mk_lang_constexpr_static auto const s_digest_precomputed_50 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_50);
	mk_lang_constexpr_static auto const s_digest_precomputed_51 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_51);
	mk_lang_constexpr_static auto const s_digest_precomputed_52 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_52);
	mk_lang_constexpr_static auto const s_digest_precomputed_53 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_53);
	mk_lang_constexpr_static auto const s_digest_precomputed_54 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_54);
	mk_lang_constexpr_static auto const s_digest_precomputed_55 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_55);
	mk_lang_constexpr_static auto const s_digest_precomputed_56 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_56);
	mk_lang_constexpr_static auto const s_digest_precomputed_57 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_57);
	mk_lang_constexpr_static auto const s_digest_precomputed_58 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_58);
	mk_lang_constexpr_static auto const s_digest_precomputed_59 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_59);
	mk_lang_constexpr_static auto const s_digest_precomputed_60 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_60);
	mk_lang_constexpr_static auto const s_digest_precomputed_61 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_61);
	mk_lang_constexpr_static auto const s_digest_precomputed_62 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_62);
	mk_lang_constexpr_static auto const s_digest_precomputed_63 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_63);
	mk_lang_constexpr_static auto const s_digest_precomputed_64 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_64);
	mk_lang_constexpr_static auto const s_digest_precomputed_65 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_65);
	mk_lang_constexpr_static auto const s_digest_precomputed_66 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_66);
	mk_lang_constexpr_static auto const s_digest_precomputed_67 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_67);
	mk_lang_constexpr_static auto const s_digest_precomputed_68 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_68);
	mk_lang_constexpr_static auto const s_digest_precomputed_69 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_69);
	mk_lang_constexpr_static auto const s_digest_precomputed_70 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_70);
	mk_lang_constexpr_static auto const s_digest_precomputed_71 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_71);
	mk_lang_constexpr_static auto const s_digest_precomputed_72 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_72);

	mk_lang_static_assert(s_digest_computed_1 == s_digest_precomputed_1);
	mk_lang_static_assert(s_digest_computed_2 == s_digest_precomputed_2);
	mk_lang_static_assert(s_digest_computed_3 == s_digest_precomputed_3);
	mk_lang_static_assert(s_digest_computed_4 == s_digest_precomputed_4);
	mk_lang_static_assert(s_digest_computed_5 == s_digest_precomputed_5);
	mk_lang_static_assert(s_digest_computed_6 == s_digest_precomputed_6);
	mk_lang_static_assert(s_digest_computed_7 == s_digest_precomputed_7);
	mk_lang_static_assert(s_digest_computed_8 == s_digest_precomputed_8);
	mk_lang_static_assert(s_digest_computed_9 == s_digest_precomputed_9);
	mk_lang_static_assert(s_digest_computed_10 == s_digest_precomputed_10);
	mk_lang_static_assert(s_digest_computed_11 == s_digest_precomputed_11);
	mk_lang_static_assert(s_digest_computed_12 == s_digest_precomputed_12);
	mk_lang_static_assert(s_digest_computed_13 == s_digest_precomputed_13);
	mk_lang_static_assert(s_digest_computed_14 == s_digest_precomputed_14);
	mk_lang_static_assert(s_digest_computed_15 == s_digest_precomputed_15);
	mk_lang_static_assert(s_digest_computed_16 == s_digest_precomputed_16);
	mk_lang_static_assert(s_digest_computed_17 == s_digest_precomputed_17);
	mk_lang_static_assert(s_digest_computed_18 == s_digest_precomputed_18);
	mk_lang_static_assert(s_digest_computed_19 == s_digest_precomputed_19);
	mk_lang_static_assert(s_digest_computed_20 == s_digest_precomputed_20);
	mk_lang_static_assert(s_digest_computed_21 == s_digest_precomputed_21);
	mk_lang_static_assert(s_digest_computed_22 == s_digest_precomputed_22);
	mk_lang_static_assert(s_digest_computed_23 == s_digest_precomputed_23);
	mk_lang_static_assert(s_digest_computed_24 == s_digest_precomputed_24);
	mk_lang_static_assert(s_digest_computed_25 == s_digest_precomputed_25);
	mk_lang_static_assert(s_digest_computed_26 == s_digest_precomputed_26);
	mk_lang_static_assert(s_digest_computed_27 == s_digest_precomputed_27);
	mk_lang_static_assert(s_digest_computed_28 == s_digest_precomputed_28);
	mk_lang_static_assert(s_digest_computed_29 == s_digest_precomputed_29);
	mk_lang_static_assert(s_digest_computed_30 == s_digest_precomputed_30);
	mk_lang_static_assert(s_digest_computed_31 == s_digest_precomputed_31);
	mk_lang_static_assert(s_digest_computed_32 == s_digest_precomputed_32);
	mk_lang_static_assert(s_digest_computed_33 == s_digest_precomputed_33);
	mk_lang_static_assert(s_digest_computed_34 == s_digest_precomputed_34);
	mk_lang_static_assert(s_digest_computed_35 == s_digest_precomputed_35);
	mk_lang_static_assert(s_digest_computed_36 == s_digest_precomputed_36);
	mk_lang_static_assert(s_digest_computed_37 == s_digest_precomputed_37);
	mk_lang_static_assert(s_digest_computed_38 == s_digest_precomputed_38);
	mk_lang_static_assert(s_digest_computed_39 == s_digest_precomputed_39);
	mk_lang_static_assert(s_digest_computed_40 == s_digest_precomputed_40);
	mk_lang_static_assert(s_digest_computed_41 == s_digest_precomputed_41);
	mk_lang_static_assert(s_digest_computed_42 == s_digest_precomputed_42);
	mk_lang_static_assert(s_digest_computed_43 == s_digest_precomputed_43);
	mk_lang_static_assert(s_digest_computed_44 == s_digest_precomputed_44);
	mk_lang_static_assert(s_digest_computed_45 == s_digest_precomputed_45);
	mk_lang_static_assert(s_digest_computed_46 == s_digest_precomputed_46);
	mk_lang_static_assert(s_digest_computed_47 == s_digest_precomputed_47);
	mk_lang_static_assert(s_digest_computed_48 == s_digest_precomputed_48);
	mk_lang_static_assert(s_digest_computed_49 == s_digest_precomputed_49);
	mk_lang_static_assert(s_digest_computed_50 == s_digest_precomputed_50);
	mk_lang_static_assert(s_digest_computed_51 == s_digest_precomputed_51);
	mk_lang_static_assert(s_digest_computed_52 == s_digest_precomputed_52);
	mk_lang_static_assert(s_digest_computed_53 == s_digest_precomputed_53);
	mk_lang_static_assert(s_digest_computed_54 == s_digest_precomputed_54);
	mk_lang_static_assert(s_digest_computed_55 == s_digest_precomputed_55);
	mk_lang_static_assert(s_digest_computed_56 == s_digest_precomputed_56);
	mk_lang_static_assert(s_digest_computed_57 == s_digest_precomputed_57);
	mk_lang_static_assert(s_digest_computed_58 == s_digest_precomputed_58);
	mk_lang_static_assert(s_digest_computed_59 == s_digest_precomputed_59);
	mk_lang_static_assert(s_digest_computed_60 == s_digest_precomputed_60);
	mk_lang_static_assert(s_digest_computed_61 == s_digest_precomputed_61);
	mk_lang_static_assert(s_digest_computed_62 == s_digest_precomputed_62);
	mk_lang_static_assert(s_digest_computed_63 == s_digest_precomputed_63);
	mk_lang_static_assert(s_digest_computed_64 == s_digest_precomputed_64);
	mk_lang_static_assert(s_digest_computed_65 == s_digest_precomputed_65);
	mk_lang_static_assert(s_digest_computed_66 == s_digest_precomputed_66);
	mk_lang_static_assert(s_digest_computed_67 == s_digest_precomputed_67);
	mk_lang_static_assert(s_digest_computed_68 == s_digest_precomputed_68);
	mk_lang_static_assert(s_digest_computed_69 == s_digest_precomputed_69);
	mk_lang_static_assert(s_digest_computed_70 == s_digest_precomputed_70);
	mk_lang_static_assert(s_digest_computed_71 == s_digest_precomputed_71);
	mk_lang_static_assert(s_digest_computed_72 == s_digest_precomputed_72);

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

	mk_lang_types_pchar_pct const hex_messages[] =
	{
		message_9,
		message_10,
		message_11,
		message_12,
		message_13,
		message_14,
		message_15,
		message_16,
		message_17,
		message_18,
		message_19,
		message_20,
		message_21,
		message_22,
		message_23,
		message_24,
		message_25,
		message_26,
		message_27,
		message_28,
		message_29,
		message_30,
		message_31,
		message_32,
		message_33,
		message_34,
		message_35,
		message_36,
		message_37,
		message_38,
		message_39,
		message_40,
		message_41,
		message_42,
		message_43,
		message_44,
		message_45,
		message_46,
		message_47,
		message_48,
		message_49,
		message_50,
		message_51,
		message_52,
		message_53,
		message_54,
		message_55,
		message_56,
		message_57,
		message_58,
		message_59,
		message_60,
		message_61,
		message_62,
		message_63,
		message_64,
		message_65,
		message_66,
		message_67,
		message_68,
		message_69,
		message_70,
		message_71,
		message_72,
	};

	mk_lang_types_sint_t const hex_message_lens[] =
	{
		mk_lang_countstr(message_9),
		mk_lang_countstr(message_10),
		mk_lang_countstr(message_11),
		mk_lang_countstr(message_12),
		mk_lang_countstr(message_13),
		mk_lang_countstr(message_14),
		mk_lang_countstr(message_15),
		mk_lang_countstr(message_16),
		mk_lang_countstr(message_17),
		mk_lang_countstr(message_18),
		mk_lang_countstr(message_19),
		mk_lang_countstr(message_20),
		mk_lang_countstr(message_21),
		mk_lang_countstr(message_22),
		mk_lang_countstr(message_23),
		mk_lang_countstr(message_24),
		mk_lang_countstr(message_25),
		mk_lang_countstr(message_26),
		mk_lang_countstr(message_27),
		mk_lang_countstr(message_28),
		mk_lang_countstr(message_29),
		mk_lang_countstr(message_30),
		mk_lang_countstr(message_31),
		mk_lang_countstr(message_32),
		mk_lang_countstr(message_33),
		mk_lang_countstr(message_34),
		mk_lang_countstr(message_35),
		mk_lang_countstr(message_36),
		mk_lang_countstr(message_37),
		mk_lang_countstr(message_38),
		mk_lang_countstr(message_39),
		mk_lang_countstr(message_40),
		mk_lang_countstr(message_41),
		mk_lang_countstr(message_42),
		mk_lang_countstr(message_43),
		mk_lang_countstr(message_44),
		mk_lang_countstr(message_45),
		mk_lang_countstr(message_46),
		mk_lang_countstr(message_47),
		mk_lang_countstr(message_48),
		mk_lang_countstr(message_49),
		mk_lang_countstr(message_50),
		mk_lang_countstr(message_51),
		mk_lang_countstr(message_52),
		mk_lang_countstr(message_53),
		mk_lang_countstr(message_54),
		mk_lang_countstr(message_55),
		mk_lang_countstr(message_56),
		mk_lang_countstr(message_57),
		mk_lang_countstr(message_58),
		mk_lang_countstr(message_59),
		mk_lang_countstr(message_60),
		mk_lang_countstr(message_61),
		mk_lang_countstr(message_62),
		mk_lang_countstr(message_63),
		mk_lang_countstr(message_64),
		mk_lang_countstr(message_65),
		mk_lang_countstr(message_66),
		mk_lang_countstr(message_67),
		mk_lang_countstr(message_68),
		mk_lang_countstr(message_69),
		mk_lang_countstr(message_70),
		mk_lang_countstr(message_71),
		mk_lang_countstr(message_72),
	};

	mk_lang_types_pchar_pct const hex_digests[] =
	{
		digest_9,
		digest_10,
		digest_11,
		digest_12,
		digest_13,
		digest_14,
		digest_15,
		digest_16,
		digest_17,
		digest_18,
		digest_19,
		digest_20,
		digest_21,
		digest_22,
		digest_23,
		digest_24,
		digest_25,
		digest_26,
		digest_27,
		digest_28,
		digest_29,
		digest_30,
		digest_31,
		digest_32,
		digest_33,
		digest_34,
		digest_35,
		digest_36,
		digest_37,
		digest_38,
		digest_39,
		digest_40,
		digest_41,
		digest_42,
		digest_43,
		digest_44,
		digest_45,
		digest_46,
		digest_47,
		digest_48,
		digest_49,
		digest_50,
		digest_51,
		digest_52,
		digest_53,
		digest_54,
		digest_55,
		digest_56,
		digest_57,
		digest_58,
		digest_59,
		digest_60,
		digest_61,
		digest_62,
		digest_63,
		digest_64,
		digest_65,
		digest_66,
		digest_67,
		digest_68,
		digest_69,
		digest_70,
		digest_71,
		digest_72,
	};

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha1_t sha1 mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha1_digest_t digest mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(messages) == mk_lang_countof(digests));
	mk_lang_static_assert(mk_lang_countof(messages) == mk_lang_countof(message_lens));
	mk_lang_static_assert(mk_lang_countof(hex_messages) == mk_lang_countof(hex_digests));
	mk_lang_static_assert(mk_lang_countof(hex_messages) == mk_lang_countof(hex_message_lens));

	n = mk_lang_countof(messages);
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(message_lens[i] >= 0);
		mk_lib_crypto_hash_stream_sha1_init(&sha1);
		mk_lib_crypto_hash_stream_sha1_append_u8s(&sha1, ((mk_sl_cui_uint8_pct)(messages[i])), ((mk_lang_types_usize_t)(message_lens[i])));
		mk_lib_crypto_hash_stream_sha1_finish(&sha1, &digest);
		for(j = 0; j != mk_lib_crypto_hash_stream_sha1_digest_len_v; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_n(&ta, &digests[i][j * mk_sl_cui_uint8_strlen_hex_v], mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == mk_sl_cui_uint8_strlen_hex_v);
			mk_lang_test(mk_sl_cui_uint8_eq(&digest.m_data.m_uint8s[j], &ta));
		}
	}
	n = mk_lang_countof(hex_messages);
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(hex_message_lens[i] >= 0);
		mk_lang_assert(hex_message_lens[i] % mk_sl_cui_uint8_strlen_hex_v == 0);
		mk_lib_crypto_hash_stream_sha1_init(&sha1);
		for(j = 0; j != hex_message_lens[i] / mk_sl_cui_uint8_strlen_hex_v; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_n(&ta, &hex_messages[i][j * mk_sl_cui_uint8_strlen_hex_v], mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == mk_sl_cui_uint8_strlen_hex_v);
			mk_lib_crypto_hash_stream_sha1_append_u8s(&sha1, &ta, 1);
		}
		mk_lib_crypto_hash_stream_sha1_finish(&sha1, &digest);
		for(j = 0; j != mk_lib_crypto_hash_stream_sha1_digest_len_v; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_n(&ta, &hex_digests[i][j * mk_sl_cui_uint8_strlen_hex_v], mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == mk_sl_cui_uint8_strlen_hex_v);
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
	#undef message_9
	#undef message_10
	#undef message_11
	#undef message_12
	#undef message_13
	#undef message_14
	#undef message_15
	#undef message_16
	#undef message_17
	#undef message_18
	#undef message_19
	#undef message_20
	#undef message_21
	#undef message_22
	#undef message_23
	#undef message_24
	#undef message_25
	#undef message_26
	#undef message_27
	#undef message_28
	#undef message_29
	#undef message_30
	#undef message_31
	#undef message_32
	#undef message_33
	#undef message_34
	#undef message_35
	#undef message_36
	#undef message_37
	#undef message_38
	#undef message_39
	#undef message_40
	#undef message_41
	#undef message_42
	#undef message_43
	#undef message_44
	#undef message_45
	#undef message_46
	#undef message_47
	#undef message_48
	#undef message_49
	#undef message_50
	#undef message_51
	#undef message_52
	#undef message_53
	#undef message_54
	#undef message_55
	#undef message_56
	#undef message_57
	#undef message_58
	#undef message_59
	#undef message_60
	#undef message_61
	#undef message_62
	#undef message_63
	#undef message_64
	#undef message_65
	#undef message_66
	#undef message_67
	#undef message_68
	#undef message_69
	#undef message_70
	#undef message_71
	#undef message_72

	#undef digest_1
	#undef digest_2
	#undef digest_3
	#undef digest_4
	#undef digest_5
	#undef digest_6
	#undef digest_7
	#undef digest_8
	#undef digest_9
	#undef digest_10
	#undef digest_11
	#undef digest_12
	#undef digest_13
	#undef digest_14
	#undef digest_15
	#undef digest_16
	#undef digest_17
	#undef digest_18
	#undef digest_19
	#undef digest_20
	#undef digest_21
	#undef digest_22
	#undef digest_23
	#undef digest_24
	#undef digest_25
	#undef digest_26
	#undef digest_27
	#undef digest_28
	#undef digest_29
	#undef digest_30
	#undef digest_31
	#undef digest_32
	#undef digest_33
	#undef digest_34
	#undef digest_35
	#undef digest_36
	#undef digest_37
	#undef digest_38
	#undef digest_39
	#undef digest_40
	#undef digest_41
	#undef digest_42
	#undef digest_43
	#undef digest_44
	#undef digest_45
	#undef digest_46
	#undef digest_47
	#undef digest_48
	#undef digest_49
	#undef digest_50
	#undef digest_51
	#undef digest_52
	#undef digest_53
	#undef digest_54
	#undef digest_55
	#undef digest_56
	#undef digest_57
	#undef digest_58
	#undef digest_59
	#undef digest_60
	#undef digest_61
	#undef digest_62
	#undef digest_63
	#undef digest_64
	#undef digest_65
	#undef digest_66
	#undef digest_67
	#undef digest_68
	#undef digest_69
	#undef digest_70
	#undef digest_71
	#undef digest_72
}


#include "mk_lang_warning_msvc_pop.h"


#endif
