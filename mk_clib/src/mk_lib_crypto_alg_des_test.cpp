#include "mk_lib_crypto_alg_des_test.hpp"
#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpp.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr.hpp"
#include "mk_lib_crypto_alg_des.h"
#include "mk_sl_uint8.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t msg_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_alg_des_test_encrypt_from_str_lit(char const(&key_lit)[key_lit_len], char const(&msg_lit)[msg_lit_len]) mk_lang_noexcept
{
	mk_lib_crypto_alg_des_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_alg_des_msg_t msg mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_alg_des_msg_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == mk_lib_crypto_alg_des_key_len_v * 2 + 1);
	mk_lang_static_assert(msg_lit_len == mk_lib_crypto_alg_des_msg_len_v * 2 + 1);

	mk_lib_cpp_constexpr_hex_str_lit_to_u8s_arr(key.m_data.m_uint8s, key_lit);
	mk_lib_cpp_constexpr_hex_str_lit_to_u8s_arr(msg.m_data.m_uint8s, msg_lit);
	mk_lib_crypto_alg_des_encrypt(&key, &msg, &msg);
	for(i = 0; i != mk_lib_crypto_alg_des_msg_len_v; ++i){ ret[i] = msg.m_data.m_uint8s[i]; }
	return ret;
}

template<mk_lang_types_usize_t key_lit_len, typename msg_t>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_alg_des_test_decrypt_from_str_lit(char const(&key_lit)[key_lit_len], msg_t const& m) mk_lang_noexcept
{
	mk_lib_crypto_alg_des_key_t key mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_alg_des_msg_t msg mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_alg_des_msg_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == mk_lib_crypto_alg_des_key_len_v * 2 + 1);
	mk_lang_static_assert(msg_t::s_size == mk_lib_crypto_alg_des_msg_len_v);

	mk_lib_cpp_constexpr_hex_str_lit_to_u8s_arr(key.m_data.m_uint8s, key_lit);
	for(i = 0; i != mk_lib_crypto_alg_des_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = m[i]; }
	mk_lib_crypto_alg_des_decrypt(&key, &msg, &msg);
	for(i = 0; i != mk_lib_crypto_alg_des_msg_len_v; ++i){ ret[i] = msg.m_data.m_uint8s[i]; }
	return ret;
}

#endif


mk_lang_extern_c void mk_lib_crypto_alg_des_test(void) mk_lang_noexcept
{
	/* http://www.ecs.soton.ac.uk/~prw99r/ez438/testvectors.htm */
	/* http://www.ecs.soton.ac.uk/~prw99r/ez438/alltest.txt */

	#define key_000 "10316e028c8f3b4a"
	#define key_001 "0101010101010101"
	#define key_002 "0101010101010101"
	#define key_003 "0101010101010101"
	#define key_004 "0101010101010101"
	#define key_005 "0101010101010101"
	#define key_006 "0101010101010101"
	#define key_007 "0101010101010101"
	#define key_008 "0101010101010101"
	#define key_009 "0101010101010101"
	#define key_010 "0101010101010101"
	#define key_011 "0101010101010101"
	#define key_012 "0101010101010101"
	#define key_013 "0101010101010101"
	#define key_014 "0101010101010101"
	#define key_015 "0101010101010101"
	#define key_016 "0101010101010101"
	#define key_017 "0101010101010101"
	#define key_018 "0101010101010101"
	#define key_019 "0101010101010101"
	#define key_020 "0101010101010101"
	#define key_021 "0101010101010101"
	#define key_022 "0101010101010101"
	#define key_023 "0101010101010101"
	#define key_024 "0101010101010101"
	#define key_025 "0101010101010101"
	#define key_026 "0101010101010101"
	#define key_027 "0101010101010101"
	#define key_028 "0101010101010101"
	#define key_029 "0101010101010101"
	#define key_030 "0101010101010101"
	#define key_031 "0101010101010101"
	#define key_032 "0101010101010101"
	#define key_033 "0101010101010101"
	#define key_034 "0101010101010101"
	#define key_035 "0101010101010101"
	#define key_036 "0101010101010101"
	#define key_037 "0101010101010101"
	#define key_038 "0101010101010101"
	#define key_039 "0101010101010101"
	#define key_040 "0101010101010101"
	#define key_041 "0101010101010101"
	#define key_042 "0101010101010101"
	#define key_043 "0101010101010101"
	#define key_044 "0101010101010101"
	#define key_045 "0101010101010101"
	#define key_046 "0101010101010101"
	#define key_047 "0101010101010101"
	#define key_048 "0101010101010101"
	#define key_049 "0101010101010101"
	#define key_050 "0101010101010101"
	#define key_051 "0101010101010101"
	#define key_052 "0101010101010101"
	#define key_053 "0101010101010101"
	#define key_054 "0101010101010101"
	#define key_055 "0101010101010101"
	#define key_056 "0101010101010101"
	#define key_057 "0101010101010101"
	#define key_058 "0101010101010101"
	#define key_059 "0101010101010101"
	#define key_060 "0101010101010101"
	#define key_061 "0101010101010101"
	#define key_062 "0101010101010101"
	#define key_063 "0101010101010101"
	#define key_064 "0101010101010101"
	#define key_065 "0101010101010101"
	#define key_066 "0101010101010101"
	#define key_067 "0101010101010101"
	#define key_068 "0101010101010101"
	#define key_069 "0101010101010101"
	#define key_070 "0101010101010101"
	#define key_071 "0101010101010101"
	#define key_072 "0101010101010101"
	#define key_073 "0101010101010101"
	#define key_074 "0101010101010101"
	#define key_075 "0101010101010101"
	#define key_076 "0101010101010101"
	#define key_077 "0101010101010101"
	#define key_078 "0101010101010101"
	#define key_079 "0101010101010101"
	#define key_080 "0101010101010101"
	#define key_081 "0101010101010101"
	#define key_082 "0101010101010101"
	#define key_083 "0101010101010101"
	#define key_084 "0101010101010101"
	#define key_085 "0101010101010101"
	#define key_086 "0101010101010101"
	#define key_087 "0101010101010101"
	#define key_088 "0101010101010101"
	#define key_089 "0101010101010101"
	#define key_090 "0101010101010101"
	#define key_091 "0101010101010101"
	#define key_092 "0101010101010101"
	#define key_093 "0101010101010101"
	#define key_094 "0101010101010101"
	#define key_095 "0101010101010101"
	#define key_096 "0101010101010101"
	#define key_097 "0101010101010101"
	#define key_098 "0101010101010101"
	#define key_099 "0101010101010101"
	#define key_100 "0101010101010101"
	#define key_101 "0101010101010101"
	#define key_102 "0101010101010101"
	#define key_103 "0101010101010101"
	#define key_104 "0101010101010101"
	#define key_105 "0101010101010101"
	#define key_106 "0101010101010101"
	#define key_107 "0101010101010101"
	#define key_108 "0101010101010101"
	#define key_109 "0101010101010101"
	#define key_110 "0101010101010101"
	#define key_111 "0101010101010101"
	#define key_112 "0101010101010101"
	#define key_113 "0101010101010101"
	#define key_114 "0101010101010101"
	#define key_115 "0101010101010101"
	#define key_116 "0101010101010101"
	#define key_117 "0101010101010101"
	#define key_118 "0101010101010101"
	#define key_119 "0101010101010101"
	#define key_120 "0101010101010101"
	#define key_121 "0101010101010101"
	#define key_122 "0101010101010101"
	#define key_123 "0101010101010101"
	#define key_124 "0101010101010101"
	#define key_125 "0101010101010101"
	#define key_126 "0101010101010101"
	#define key_127 "0101010101010101"
	#define key_128 "0101010101010101"
	#define key_129 "8001010101010101"
	#define key_130 "4001010101010101"
	#define key_131 "2001010101010101"
	#define key_132 "1001010101010101"
	#define key_133 "0801010101010101"
	#define key_134 "0401010101010101"
	#define key_135 "0201010101010101"
	#define key_136 "0180010101010101"
	#define key_137 "0140010101010101"
	#define key_138 "0120010101010101"
	#define key_139 "0110010101010101"
	#define key_140 "0108010101010101"
	#define key_141 "0104010101010101"
	#define key_142 "0102010101010101"
	#define key_143 "0101800101010101"
	#define key_144 "0101400101010101"
	#define key_145 "0101200101010101"
	#define key_146 "0101100101010101"
	#define key_147 "0101080101010101"
	#define key_148 "0101040101010101"
	#define key_149 "0101020101010101"
	#define key_150 "0101018001010101"
	#define key_151 "0101014001010101"
	#define key_152 "0101012001010101"
	#define key_153 "0101011001010101"
	#define key_154 "0101010801010101"
	#define key_155 "0101010401010101"
	#define key_156 "0101010201010101"
	#define key_157 "0101010180010101"
	#define key_158 "0101010140010101"
	#define key_159 "0101010120010101"
	#define key_160 "0101010110010101"
	#define key_161 "0101010108010101"
	#define key_162 "0101010104010101"
	#define key_163 "0101010102010101"
	#define key_164 "0101010101800101"
	#define key_165 "0101010101400101"
	#define key_166 "0101010101200101"
	#define key_167 "0101010101100101"
	#define key_168 "0101010101080101"
	#define key_169 "0101010101040101"
	#define key_170 "0101010101020101"
	#define key_171 "0101010101018001"
	#define key_172 "0101010101014001"
	#define key_173 "0101010101012001"
	#define key_174 "0101010101011001"
	#define key_175 "0101010101010801"
	#define key_176 "0101010101010401"
	#define key_177 "0101010101010201"
	#define key_178 "0101010101010180"
	#define key_179 "0101010101010140"
	#define key_180 "0101010101010120"
	#define key_181 "0101010101010110"
	#define key_182 "0101010101010108"
	#define key_183 "0101010101010104"
	#define key_184 "0101010101010102"
	#define key_185 "1046913489980131"
	#define key_186 "1007103489988020"
	#define key_187 "10071034c8980120"
	#define key_188 "1046103489988020"
	#define key_189 "1086911519190101"
	#define key_190 "1086911519580101"
	#define key_191 "5107b01519580101"
	#define key_192 "1007b01519190101"
	#define key_193 "3107915498080101"
	#define key_194 "3107919498080101"
	#define key_195 "10079115b9080140"
	#define key_196 "3107911598080140"
	#define key_197 "1007d01589980101"
	#define key_198 "9107911589980101"
	#define key_199 "9107d01589190101"
	#define key_200 "1007d01598980120"
	#define key_201 "1007940498190101"
	#define key_202 "0107910491190401"
	#define key_203 "0107910491190101"
	#define key_204 "0107940491190401"
	#define key_205 "19079210981a0101"
	#define key_206 "1007911998190801"
	#define key_207 "10079119981a0801"
	#define key_208 "1007921098190101"
	#define key_209 "100791159819010b"
	#define key_210 "1004801598190101"
	#define key_211 "1004801598190102"
	#define key_212 "1004801598190108"
	#define key_213 "1002911498100104"
	#define key_214 "1002911598190104"
	#define key_215 "1002911598100201"
	#define key_216 "1002911698100101"
	#define key_217 "7ca110454a1a6e57"
	#define key_218 "0131d9619dc1376e"
	#define key_219 "07a1133e4a0b2686"
	#define key_220 "3849674c2602319e"
	#define key_221 "04b915ba43feb5b6"
	#define key_222 "0113b970fd34f2ce"
	#define key_223 "0170f175468fb5e6"
	#define key_224 "43297fad38e373fe"
	#define key_225 "07a7137045da2a16"
	#define key_226 "04689104c2fd3b2f"
	#define key_227 "37d06bb516cb7546"
	#define key_228 "1f08260d1ac2465e"
	#define key_229 "584023641aba6176"
	#define key_230 "025816164629b007"
	#define key_231 "49793ebc79b3258f"
	#define key_232 "4fb05e1515ab73a7"
	#define key_233 "49e95d6d4ca229bf"
	#define key_234 "018310dc409b26d6"
	#define key_235 "1c587f1c13924fef"
	#define key_236 "0000000000000000"
	#define key_237 "ffffffffffffffff"
	#define key_238 "3000000000000000"
	#define key_239 "1111111111111111"
	#define key_240 "0123456789abcdef"
	#define key_241 "1111111111111111"
	#define key_242 "0000000000000000"
	#define key_243 "fedcba9876543210"
	#define key_244 "7ca110454a1a6e57"
	#define key_245 "0131d9619dc1376e"
	#define key_246 "07a1133e4a0b2686"
	#define key_247 "3849674c2602319e"
	#define key_248 "04b915ba43feb5b6"
	#define key_249 "0113b970fd34f2ce"
	#define key_250 "0170f175468fb5e6"
	#define key_251 "43297fad38e373fe"
	#define key_252 "07a7137045da2a16"
	#define key_253 "04689104c2fd3b2f"
	#define key_254 "37d06bb516cb7546"
	#define key_255 "1f08260d1ac2465e"
	#define key_256 "584023641aba6176"
	#define key_257 "025816164629b007"
	#define key_258 "49793ebc79b3258f"
	#define key_259 "4fb05e1515ab73a7"
	#define key_260 "49e95d6d4ca229bf"
	#define key_261 "018310dc409b26d6"
	#define key_262 "1c587f1c13924fef"
	#define key_263 "0101010101010101"
	#define key_264 "1f1f1f1f0e0e0e0e"
	#define key_265 "e0fee0fef1fef1fe"
	#define key_266 "0000000000000000"
	#define key_267 "ffffffffffffffff"
	#define key_268 "0123456789abcdef"
	#define key_269 "fedcba9876543210"

	#define msg_000 "0000000000000000"
	#define msg_001 "95f8a5e5dd31d900"
	#define msg_002 "dd7f121ca5015619"
	#define msg_003 "2e8653104f3834ea"
	#define msg_004 "4bd388ff6cd81d4f"
	#define msg_005 "20b9e767b2fb1456"
	#define msg_006 "55579380d77138ef"
	#define msg_007 "6cc5defaaf04512f"
	#define msg_008 "0d9f279ba5d87260"
	#define msg_009 "d9031b0271bd5a0a"
	#define msg_010 "424250b37c3dd951"
	#define msg_011 "b8061b7ecd9a21e5"
	#define msg_012 "f15d0f286b65bd28"
	#define msg_013 "add0cc8d6e5deba1"
	#define msg_014 "e6d5f82752ad63d1"
	#define msg_015 "ecbfe3bd3f591a5e"
	#define msg_016 "f356834379d165cd"
	#define msg_017 "2b9f982f20037fa9"
	#define msg_018 "889de068a16f0be6"
	#define msg_019 "e19e275d846a1298"
	#define msg_020 "329a8ed523d71aec"
	#define msg_021 "e7fce22557d23c97"
	#define msg_022 "12a9f5817ff2d65d"
	#define msg_023 "a484c3ad38dc9c19"
	#define msg_024 "fbe00a8a1ef8ad72"
	#define msg_025 "750d079407521363"
	#define msg_026 "64feed9c724c2faf"
	#define msg_027 "f02b263b328e2b60"
	#define msg_028 "9d64555a9a10b852"
	#define msg_029 "d106ff0bed5255d7"
	#define msg_030 "e1652c6b138c64a5"
	#define msg_031 "e428581186ec8f46"
	#define msg_032 "aeb5f5ede22d1a36"
	#define msg_033 "e943d7568aec0c5c"
	#define msg_034 "df98c8276f54b04b"
	#define msg_035 "b160e4680f6c696f"
	#define msg_036 "fa0752b07d9c4ab8"
	#define msg_037 "ca3a2b036dbc8502"
	#define msg_038 "5e0905517bb59bcf"
	#define msg_039 "814eeb3b91d90726"
	#define msg_040 "4d49db1532919c9f"
	#define msg_041 "25eb5fc3f8cf0621"
	#define msg_042 "ab6a20c0620d1c6f"
	#define msg_043 "79e90dbc98f92cca"
	#define msg_044 "866ecedd8072bb0e"
	#define msg_045 "8b54536f2f3e64a8"
	#define msg_046 "ea51d3975595b86b"
	#define msg_047 "caffc6ac4542de31"
	#define msg_048 "8dd45a2ddf90796c"
	#define msg_049 "1029d55e880ec2d0"
	#define msg_050 "5d86cb23639dbea9"
	#define msg_051 "1d1ca853ae7c0c5f"
	#define msg_052 "ce332329248f3228"
	#define msg_053 "8405d1abe24fb942"
	#define msg_054 "e643d78090ca4207"
	#define msg_055 "48221b9937748a23"
	#define msg_056 "dd7c0bbd61fafd54"
	#define msg_057 "2fbc291a570db5c4"
	#define msg_058 "e07c30d7e4e26e12"
	#define msg_059 "0953e2258e8e90a1"
	#define msg_060 "5b711bc4ceebf2ee"
	#define msg_061 "cc083f1e6d9e85f6"
	#define msg_062 "d2fd8867d50d2dfe"
	#define msg_063 "06e7ea22ce92708f"
	#define msg_064 "166b40b44aba4bd6"
	#define msg_065 "8000000000000000"
	#define msg_066 "4000000000000000"
	#define msg_067 "2000000000000000"
	#define msg_068 "1000000000000000"
	#define msg_069 "0800000000000000"
	#define msg_070 "0400000000000000"
	#define msg_071 "0200000000000000"
	#define msg_072 "0100000000000000"
	#define msg_073 "0080000000000000"
	#define msg_074 "0040000000000000"
	#define msg_075 "0020000000000000"
	#define msg_076 "0010000000000000"
	#define msg_077 "0008000000000000"
	#define msg_078 "0004000000000000"
	#define msg_079 "0002000000000000"
	#define msg_080 "0001000000000000"
	#define msg_081 "0000800000000000"
	#define msg_082 "0000400000000000"
	#define msg_083 "0000200000000000"
	#define msg_084 "0000100000000000"
	#define msg_085 "0000080000000000"
	#define msg_086 "0000040000000000"
	#define msg_087 "0000020000000000"
	#define msg_088 "0000010000000000"
	#define msg_089 "0000008000000000"
	#define msg_090 "0000004000000000"
	#define msg_091 "0000002000000000"
	#define msg_092 "0000001000000000"
	#define msg_093 "0000000800000000"
	#define msg_094 "0000000400000000"
	#define msg_095 "0000000200000000"
	#define msg_096 "0000000100000000"
	#define msg_097 "0000000080000000"
	#define msg_098 "0000000040000000"
	#define msg_099 "0000000020000000"
	#define msg_100 "0000000010000000"
	#define msg_101 "0000000008000000"
	#define msg_102 "0000000004000000"
	#define msg_103 "0000000002000000"
	#define msg_104 "0000000001000000"
	#define msg_105 "0000000000800000"
	#define msg_106 "0000000000400000"
	#define msg_107 "0000000000200000"
	#define msg_108 "0000000000100000"
	#define msg_109 "0000000000080000"
	#define msg_110 "0000000000040000"
	#define msg_111 "0000000000020000"
	#define msg_112 "0000000000010000"
	#define msg_113 "0000000000008000"
	#define msg_114 "0000000000004000"
	#define msg_115 "0000000000002000"
	#define msg_116 "0000000000001000"
	#define msg_117 "0000000000000800"
	#define msg_118 "0000000000000400"
	#define msg_119 "0000000000000200"
	#define msg_120 "0000000000000100"
	#define msg_121 "0000000000000080"
	#define msg_122 "0000000000000040"
	#define msg_123 "0000000000000020"
	#define msg_124 "0000000000000010"
	#define msg_125 "0000000000000008"
	#define msg_126 "0000000000000004"
	#define msg_127 "0000000000000002"
	#define msg_128 "0000000000000001"
	#define msg_129 "0000000000000000"
	#define msg_130 "0000000000000000"
	#define msg_131 "0000000000000000"
	#define msg_132 "0000000000000000"
	#define msg_133 "0000000000000000"
	#define msg_134 "0000000000000000"
	#define msg_135 "0000000000000000"
	#define msg_136 "0000000000000000"
	#define msg_137 "0000000000000000"
	#define msg_138 "0000000000000000"
	#define msg_139 "0000000000000000"
	#define msg_140 "0000000000000000"
	#define msg_141 "0000000000000000"
	#define msg_142 "0000000000000000"
	#define msg_143 "0000000000000000"
	#define msg_144 "0000000000000000"
	#define msg_145 "0000000000000000"
	#define msg_146 "0000000000000000"
	#define msg_147 "0000000000000000"
	#define msg_148 "0000000000000000"
	#define msg_149 "0000000000000000"
	#define msg_150 "0000000000000000"
	#define msg_151 "0000000000000000"
	#define msg_152 "0000000000000000"
	#define msg_153 "0000000000000000"
	#define msg_154 "0000000000000000"
	#define msg_155 "0000000000000000"
	#define msg_156 "0000000000000000"
	#define msg_157 "0000000000000000"
	#define msg_158 "0000000000000000"
	#define msg_159 "0000000000000000"
	#define msg_160 "0000000000000000"
	#define msg_161 "0000000000000000"
	#define msg_162 "0000000000000000"
	#define msg_163 "0000000000000000"
	#define msg_164 "0000000000000000"
	#define msg_165 "0000000000000000"
	#define msg_166 "0000000000000000"
	#define msg_167 "0000000000000000"
	#define msg_168 "0000000000000000"
	#define msg_169 "0000000000000000"
	#define msg_170 "0000000000000000"
	#define msg_171 "0000000000000000"
	#define msg_172 "0000000000000000"
	#define msg_173 "0000000000000000"
	#define msg_174 "0000000000000000"
	#define msg_175 "0000000000000000"
	#define msg_176 "0000000000000000"
	#define msg_177 "0000000000000000"
	#define msg_178 "0000000000000000"
	#define msg_179 "0000000000000000"
	#define msg_180 "0000000000000000"
	#define msg_181 "0000000000000000"
	#define msg_182 "0000000000000000"
	#define msg_183 "0000000000000000"
	#define msg_184 "0000000000000000"
	#define msg_185 "0000000000000000"
	#define msg_186 "0000000000000000"
	#define msg_187 "0000000000000000"
	#define msg_188 "0000000000000000"
	#define msg_189 "0000000000000000"
	#define msg_190 "0000000000000000"
	#define msg_191 "0000000000000000"
	#define msg_192 "0000000000000000"
	#define msg_193 "0000000000000000"
	#define msg_194 "0000000000000000"
	#define msg_195 "0000000000000000"
	#define msg_196 "0000000000000000"
	#define msg_197 "0000000000000000"
	#define msg_198 "0000000000000000"
	#define msg_199 "0000000000000000"
	#define msg_200 "0000000000000000"
	#define msg_201 "0000000000000000"
	#define msg_202 "0000000000000000"
	#define msg_203 "0000000000000000"
	#define msg_204 "0000000000000000"
	#define msg_205 "0000000000000000"
	#define msg_206 "0000000000000000"
	#define msg_207 "0000000000000000"
	#define msg_208 "0000000000000000"
	#define msg_209 "0000000000000000"
	#define msg_210 "0000000000000000"
	#define msg_211 "0000000000000000"
	#define msg_212 "0000000000000000"
	#define msg_213 "0000000000000000"
	#define msg_214 "0000000000000000"
	#define msg_215 "0000000000000000"
	#define msg_216 "0000000000000000"
	#define msg_217 "01a1d6d039776742"
	#define msg_218 "5cd54ca83def57da"
	#define msg_219 "0248d43806f67172"
	#define msg_220 "51454b582ddf440a"
	#define msg_221 "42fd443059577fa2"
	#define msg_222 "059b5e0851cf143a"
	#define msg_223 "0756d8e0774761d2"
	#define msg_224 "762514b829bf486a"
	#define msg_225 "3bdd119049372802"
	#define msg_226 "26955f6835af609a"
	#define msg_227 "164d5e404f275232"
	#define msg_228 "6b056e18759f5cca"
	#define msg_229 "004bd6ef09176062"
	#define msg_230 "480d39006ee762f2"
	#define msg_231 "437540c8698f3cfa"
	#define msg_232 "072d43a077075292"
	#define msg_233 "02fe55778117f12a"
	#define msg_234 "1d9d5c5018f728c2"
	#define msg_235 "305532286d6f295a"
	#define msg_236 "0000000000000000"
	#define msg_237 "ffffffffffffffff"
	#define msg_238 "1000000000000001"
	#define msg_239 "1111111111111111"
	#define msg_240 "1111111111111111"
	#define msg_241 "0123456789abcdef"
	#define msg_242 "0000000000000000"
	#define msg_243 "0123456789abcdef"
	#define msg_244 "01a1d6d039776742"
	#define msg_245 "5cd54ca83def57da"
	#define msg_246 "0248d43806f67172"
	#define msg_247 "51454b582ddf440a"
	#define msg_248 "42fd443059577fa2"
	#define msg_249 "059b5e0851cf143a"
	#define msg_250 "0756d8e0774761d2"
	#define msg_251 "762514b829bf486a"
	#define msg_252 "3bdd119049372802"
	#define msg_253 "26955f6835af609a"
	#define msg_254 "164d5e404f275232"
	#define msg_255 "6b056e18759f5cca"
	#define msg_256 "004bd6ef09176062"
	#define msg_257 "480d39006ee762f2"
	#define msg_258 "437540c8698f3cfa"
	#define msg_259 "072d43a077075292"
	#define msg_260 "02fe55778117f12a"
	#define msg_261 "1d9d5c5018f728c2"
	#define msg_262 "305532286d6f295a"
	#define msg_263 "0123456789abcdef"
	#define msg_264 "0123456789abcdef"
	#define msg_265 "0123456789abcdef"
	#define msg_266 "ffffffffffffffff"
	#define msg_267 "0000000000000000"
	#define msg_268 "0000000000000000"
	#define msg_269 "ffffffffffffffff"

	#define out_000 "82dcbafbdeab6602"
	#define out_001 "8000000000000000"
	#define out_002 "4000000000000000"
	#define out_003 "2000000000000000"
	#define out_004 "1000000000000000"
	#define out_005 "0800000000000000"
	#define out_006 "0400000000000000"
	#define out_007 "0200000000000000"
	#define out_008 "0100000000000000"
	#define out_009 "0080000000000000"
	#define out_010 "0040000000000000"
	#define out_011 "0020000000000000"
	#define out_012 "0010000000000000"
	#define out_013 "0008000000000000"
	#define out_014 "0004000000000000"
	#define out_015 "0002000000000000"
	#define out_016 "0001000000000000"
	#define out_017 "0000800000000000"
	#define out_018 "0000400000000000"
	#define out_019 "0000200000000000"
	#define out_020 "0000100000000000"
	#define out_021 "0000080000000000"
	#define out_022 "0000040000000000"
	#define out_023 "0000020000000000"
	#define out_024 "0000010000000000"
	#define out_025 "0000008000000000"
	#define out_026 "0000004000000000"
	#define out_027 "0000002000000000"
	#define out_028 "0000001000000000"
	#define out_029 "0000000800000000"
	#define out_030 "0000000400000000"
	#define out_031 "0000000200000000"
	#define out_032 "0000000100000000"
	#define out_033 "0000000080000000"
	#define out_034 "0000000040000000"
	#define out_035 "0000000020000000"
	#define out_036 "0000000010000000"
	#define out_037 "0000000008000000"
	#define out_038 "0000000004000000"
	#define out_039 "0000000002000000"
	#define out_040 "0000000001000000"
	#define out_041 "0000000000800000"
	#define out_042 "0000000000400000"
	#define out_043 "0000000000200000"
	#define out_044 "0000000000100000"
	#define out_045 "0000000000080000"
	#define out_046 "0000000000040000"
	#define out_047 "0000000000020000"
	#define out_048 "0000000000010000"
	#define out_049 "0000000000008000"
	#define out_050 "0000000000004000"
	#define out_051 "0000000000002000"
	#define out_052 "0000000000001000"
	#define out_053 "0000000000000800"
	#define out_054 "0000000000000400"
	#define out_055 "0000000000000200"
	#define out_056 "0000000000000100"
	#define out_057 "0000000000000080"
	#define out_058 "0000000000000040"
	#define out_059 "0000000000000020"
	#define out_060 "0000000000000010"
	#define out_061 "0000000000000008"
	#define out_062 "0000000000000004"
	#define out_063 "0000000000000002"
	#define out_064 "0000000000000001"
	#define out_065 "95f8a5e5dd31d900"
	#define out_066 "dd7f121ca5015619"
	#define out_067 "2e8653104f3834ea"
	#define out_068 "4bd388ff6cd81d4f"
	#define out_069 "20b9e767b2fb1456"
	#define out_070 "55579380d77138ef"
	#define out_071 "6cc5defaaf04512f"
	#define out_072 "0d9f279ba5d87260"
	#define out_073 "d9031b0271bd5a0a"
	#define out_074 "424250b37c3dd951"
	#define out_075 "b8061b7ecd9a21e5"
	#define out_076 "f15d0f286b65bd28"
	#define out_077 "add0cc8d6e5deba1"
	#define out_078 "e6d5f82752ad63d1"
	#define out_079 "ecbfe3bd3f591a5e"
	#define out_080 "f356834379d165cd"
	#define out_081 "2b9f982f20037fa9"
	#define out_082 "889de068a16f0be6"
	#define out_083 "e19e275d846a1298"
	#define out_084 "329a8ed523d71aec"
	#define out_085 "e7fce22557d23c97"
	#define out_086 "12a9f5817ff2d65d"
	#define out_087 "a484c3ad38dc9c19"
	#define out_088 "fbe00a8a1ef8ad72"
	#define out_089 "750d079407521363"
	#define out_090 "64feed9c724c2faf"
	#define out_091 "f02b263b328e2b60"
	#define out_092 "9d64555a9a10b852"
	#define out_093 "d106ff0bed5255d7"
	#define out_094 "e1652c6b138c64a5"
	#define out_095 "e428581186ec8f46"
	#define out_096 "aeb5f5ede22d1a36"
	#define out_097 "e943d7568aec0c5c"
	#define out_098 "df98c8276f54b04b"
	#define out_099 "b160e4680f6c696f"
	#define out_100 "fa0752b07d9c4ab8"
	#define out_101 "ca3a2b036dbc8502"
	#define out_102 "5e0905517bb59bcf"
	#define out_103 "814eeb3b91d90726"
	#define out_104 "4d49db1532919c9f"
	#define out_105 "25eb5fc3f8cf0621"
	#define out_106 "ab6a20c0620d1c6f"
	#define out_107 "79e90dbc98f92cca"
	#define out_108 "866ecedd8072bb0e"
	#define out_109 "8b54536f2f3e64a8"
	#define out_110 "ea51d3975595b86b"
	#define out_111 "caffc6ac4542de31"
	#define out_112 "8dd45a2ddf90796c"
	#define out_113 "1029d55e880ec2d0"
	#define out_114 "5d86cb23639dbea9"
	#define out_115 "1d1ca853ae7c0c5f"
	#define out_116 "ce332329248f3228"
	#define out_117 "8405d1abe24fb942"
	#define out_118 "e643d78090ca4207"
	#define out_119 "48221b9937748a23"
	#define out_120 "dd7c0bbd61fafd54"
	#define out_121 "2fbc291a570db5c4"
	#define out_122 "e07c30d7e4e26e12"
	#define out_123 "0953e2258e8e90a1"
	#define out_124 "5b711bc4ceebf2ee"
	#define out_125 "cc083f1e6d9e85f6"
	#define out_126 "d2fd8867d50d2dfe"
	#define out_127 "06e7ea22ce92708f"
	#define out_128 "166b40b44aba4bd6"
	#define out_129 "95a8d72813daa94d"
	#define out_130 "0eec1487dd8c26d5"
	#define out_131 "7ad16ffb79c45926"
	#define out_132 "d3746294ca6a6cf3"
	#define out_133 "809f5f873c1fd761"
	#define out_134 "c02faffec989d1fc"
	#define out_135 "4615aa1d33e72f10"
	#define out_136 "2055123350c00858"
	#define out_137 "df3b99d6577397c8"
	#define out_138 "31fe17369b5288c9"
	#define out_139 "dfdd3cc64dae1642"
	#define out_140 "178c83ce2b399d94"
	#define out_141 "50f636324a9b7f80"
	#define out_142 "a8468ee3bc18f06d"
	#define out_143 "a2dc9e92fd3cde92"
	#define out_144 "cac09f797d031287"
	#define out_145 "90ba680b22aeb525"
	#define out_146 "ce7a24f350e280b6"
	#define out_147 "882bff0aa01a0b87"
	#define out_148 "25610288924511c2"
	#define out_149 "c71516c29c75d170"
	#define out_150 "5199c29a52c9f059"
	#define out_151 "c22f0a294a71f29f"
	#define out_152 "ee371483714c02ea"
	#define out_153 "a81fbd448f9e522f"
	#define out_154 "4f644c92e192dfed"
	#define out_155 "1afa9a66a6df92ae"
	#define out_156 "b3c1cc715cb879d8"
	#define out_157 "19d032e64ab0bd8b"
	#define out_158 "3cfaa7a7dc8720dc"
	#define out_159 "b7265f7f447ac6f3"
	#define out_160 "9db73b3c0d163f54"
	#define out_161 "8181b65babf4a975"
	#define out_162 "93c9b64042eaa240"
	#define out_163 "5570530829705592"
	#define out_164 "8638809e878787a0"
	#define out_165 "41b9a79af79ac208"
	#define out_166 "7a9be42f2009a892"
	#define out_167 "29038d56ba6d2745"
	#define out_168 "5495c6abf1e5df51"
	#define out_169 "ae13dbd561488933"
	#define out_170 "024d1ffa8904e389"
	#define out_171 "d1399712f99bf02e"
	#define out_172 "14c1d7c1cffec79e"
	#define out_173 "1de5279dae3bed6f"
	#define out_174 "e941a33f85501303"
	#define out_175 "da99dbbc9a03f379"
	#define out_176 "b7fc92f91d8e92e9"
	#define out_177 "ae8e5caa3ca04e85"
	#define out_178 "9cc62df43b6eed74"
	#define out_179 "d863dbb5c59a91a0"
	#define out_180 "a1ab2190545b91d7"
	#define out_181 "0875041e64c570f7"
	#define out_182 "5a594528bebef1cc"
	#define out_183 "fcdb3291de21f0c0"
	#define out_184 "869efd7f9f265a09"
	#define out_185 "88d55e54f54c97b4"
	#define out_186 "0c0cc00c83ea48fd"
	#define out_187 "83bc8ef3a6570183"
	#define out_188 "df725dcad94ea2e9"
	#define out_189 "e652b53b550be8b0"
	#define out_190 "af527120c485cbb0"
	#define out_191 "0f04ce393db926d5"
	#define out_192 "c9f00ffc74079067"
	#define out_193 "7cfd82a593252b4e"
	#define out_194 "cb49a2f9e91363e3"
	#define out_195 "00b588be70d23f56"
	#define out_196 "406a9a6ab43399ae"
	#define out_197 "6cb773611dca9ada"
	#define out_198 "67fd21c17dbb5d70"
	#define out_199 "9592cb4110430787"
	#define out_200 "a6b7ff68a318ddd3"
	#define out_201 "4d102196c914ca16"
	#define out_202 "2dfa9f4573594965"
	#define out_203 "b46604816c0e0774"
	#define out_204 "6e7e6221a4f34e87"
	#define out_205 "aa85e74643233199"
	#define out_206 "2e5a19db4d1962d6"
	#define out_207 "23a866a809d30894"
	#define out_208 "d812d961f017d320"
	#define out_209 "055605816e58608f"
	#define out_210 "abd88e8b1b7716f1"
	#define out_211 "537ac95be69da1e1"
	#define out_212 "aed0f6ae3c25cdd8"
	#define out_213 "b3e35a5ee53e7b8d"
	#define out_214 "61c79c71921a2ef8"
	#define out_215 "e2f5728f0995013c"
	#define out_216 "1aeac39a61f0a464"
	#define out_217 "690f5b0d9a26939b"
	#define out_218 "7a389d10354bd271"
	#define out_219 "868ebb51cab4599a"
	#define out_220 "7178876e01f19b2a"
	#define out_221 "af37fb421f8c4095"
	#define out_222 "86a560f10ec6d85b"
	#define out_223 "0cd3da020021dc09"
	#define out_224 "ea676b2cb7db2b7a"
	#define out_225 "dfd64a815caf1a0f"
	#define out_226 "5c513c9c4886c088"
	#define out_227 "0a2aeeae3ff4ab77"
	#define out_228 "ef1bf03e5dfa575a"
	#define out_229 "88bf0db6d70dee56"
	#define out_230 "a1f9915541020b56"
	#define out_231 "6fbf1cafcffd0556"
	#define out_232 "2f22e49bab7ca1ac"
	#define out_233 "5a6b612cc26cce4a"
	#define out_234 "5f4c038ed12b2e41"
	#define out_235 "63fac0d034d9f793"
	#define out_236 "8ca64de9c1b123a7"
	#define out_237 "7359b2163e4edc58"
	#define out_238 "958e6e627a05557b"
	#define out_239 "f40379ab9e0ec533"
	#define out_240 "17668dfc7292532d"
	#define out_241 "8a5ae1f81ab8f2dd"
	#define out_242 "8ca64de9c1b123a7"
	#define out_243 "ed39d950fa74bcc4"
	#define out_244 "690f5b0d9a26939b"
	#define out_245 "7a389d10354bd271"
	#define out_246 "868ebb51cab4599a"
	#define out_247 "7178876e01f19b2a"
	#define out_248 "af37fb421f8c4095"
	#define out_249 "86a560f10ec6d85b"
	#define out_250 "0cd3da020021dc09"
	#define out_251 "ea676b2cb7db2b7a"
	#define out_252 "dfd64a815caf1a0f"
	#define out_253 "5c513c9c4886c088"
	#define out_254 "0a2aeeae3ff4ab77"
	#define out_255 "ef1bf03e5dfa575a"
	#define out_256 "88bf0db6d70dee56"
	#define out_257 "a1f9915541020b56"
	#define out_258 "6fbf1cafcffd0556"
	#define out_259 "2f22e49bab7ca1ac"
	#define out_260 "5a6b612cc26cce4a"
	#define out_261 "5f4c038ed12b2e41"
	#define out_262 "63fac0d034d9f793"
	#define out_263 "617b3a0ce8f07100"
	#define out_264 "db958605f8c8c606"
	#define out_265 "edbfd1c66c29ccc7"
	#define out_266 "355550b2150e2451"
	#define out_267 "caaaaf4deaf1dbae"
	#define out_268 "d5d44ff720683d0d"
	#define out_269 "2a2bb008df97c2f2"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_out_computed_000 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_000, msg_000);
	mk_lang_constexpr_static auto const s_out_computed_001 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_001, msg_001);
	mk_lang_constexpr_static auto const s_out_computed_002 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_002, msg_002);
	mk_lang_constexpr_static auto const s_out_computed_003 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_003, msg_003);
	mk_lang_constexpr_static auto const s_out_computed_004 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_004, msg_004);
	mk_lang_constexpr_static auto const s_out_computed_005 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_005, msg_005);
	mk_lang_constexpr_static auto const s_out_computed_006 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_006, msg_006);
	mk_lang_constexpr_static auto const s_out_computed_007 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_007, msg_007);
	mk_lang_constexpr_static auto const s_out_computed_008 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_008, msg_008);
	mk_lang_constexpr_static auto const s_out_computed_009 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_009, msg_009);
	mk_lang_constexpr_static auto const s_out_computed_010 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_010, msg_010);
	mk_lang_constexpr_static auto const s_out_computed_011 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_011, msg_011);
	mk_lang_constexpr_static auto const s_out_computed_012 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_012, msg_012);
	mk_lang_constexpr_static auto const s_out_computed_013 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_013, msg_013);
	mk_lang_constexpr_static auto const s_out_computed_014 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_014, msg_014);
	mk_lang_constexpr_static auto const s_out_computed_015 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_015, msg_015);
	mk_lang_constexpr_static auto const s_out_computed_016 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_016, msg_016);
	mk_lang_constexpr_static auto const s_out_computed_017 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_017, msg_017);
	mk_lang_constexpr_static auto const s_out_computed_018 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_018, msg_018);
	mk_lang_constexpr_static auto const s_out_computed_019 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_019, msg_019);
	mk_lang_constexpr_static auto const s_out_computed_020 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_020, msg_020);
	mk_lang_constexpr_static auto const s_out_computed_021 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_021, msg_021);
	mk_lang_constexpr_static auto const s_out_computed_022 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_022, msg_022);
	mk_lang_constexpr_static auto const s_out_computed_023 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_023, msg_023);
	mk_lang_constexpr_static auto const s_out_computed_024 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_024, msg_024);
	mk_lang_constexpr_static auto const s_out_computed_025 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_025, msg_025);
	mk_lang_constexpr_static auto const s_out_computed_026 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_026, msg_026);
	mk_lang_constexpr_static auto const s_out_computed_027 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_027, msg_027);
	mk_lang_constexpr_static auto const s_out_computed_028 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_028, msg_028);
	mk_lang_constexpr_static auto const s_out_computed_029 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_029, msg_029);
	mk_lang_constexpr_static auto const s_out_computed_030 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_030, msg_030);
	mk_lang_constexpr_static auto const s_out_computed_031 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_031, msg_031);
	mk_lang_constexpr_static auto const s_out_computed_032 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_032, msg_032);
	mk_lang_constexpr_static auto const s_out_computed_033 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_033, msg_033);
	mk_lang_constexpr_static auto const s_out_computed_034 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_034, msg_034);
	mk_lang_constexpr_static auto const s_out_computed_035 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_035, msg_035);
	mk_lang_constexpr_static auto const s_out_computed_036 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_036, msg_036);
	mk_lang_constexpr_static auto const s_out_computed_037 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_037, msg_037);
	mk_lang_constexpr_static auto const s_out_computed_038 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_038, msg_038);
	mk_lang_constexpr_static auto const s_out_computed_039 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_039, msg_039);
	mk_lang_constexpr_static auto const s_out_computed_040 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_040, msg_040);
	mk_lang_constexpr_static auto const s_out_computed_041 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_041, msg_041);
	mk_lang_constexpr_static auto const s_out_computed_042 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_042, msg_042);
	mk_lang_constexpr_static auto const s_out_computed_043 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_043, msg_043);
	mk_lang_constexpr_static auto const s_out_computed_044 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_044, msg_044);
	mk_lang_constexpr_static auto const s_out_computed_045 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_045, msg_045);
	mk_lang_constexpr_static auto const s_out_computed_046 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_046, msg_046);
	mk_lang_constexpr_static auto const s_out_computed_047 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_047, msg_047);
	mk_lang_constexpr_static auto const s_out_computed_048 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_048, msg_048);
	mk_lang_constexpr_static auto const s_out_computed_049 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_049, msg_049);
	mk_lang_constexpr_static auto const s_out_computed_050 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_050, msg_050);
	mk_lang_constexpr_static auto const s_out_computed_051 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_051, msg_051);
	mk_lang_constexpr_static auto const s_out_computed_052 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_052, msg_052);
	mk_lang_constexpr_static auto const s_out_computed_053 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_053, msg_053);
	mk_lang_constexpr_static auto const s_out_computed_054 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_054, msg_054);
	mk_lang_constexpr_static auto const s_out_computed_055 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_055, msg_055);
	mk_lang_constexpr_static auto const s_out_computed_056 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_056, msg_056);
	mk_lang_constexpr_static auto const s_out_computed_057 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_057, msg_057);
	mk_lang_constexpr_static auto const s_out_computed_058 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_058, msg_058);
	mk_lang_constexpr_static auto const s_out_computed_059 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_059, msg_059);
	mk_lang_constexpr_static auto const s_out_computed_060 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_060, msg_060);
	mk_lang_constexpr_static auto const s_out_computed_061 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_061, msg_061);
	mk_lang_constexpr_static auto const s_out_computed_062 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_062, msg_062);
	mk_lang_constexpr_static auto const s_out_computed_063 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_063, msg_063);
	mk_lang_constexpr_static auto const s_out_computed_064 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_064, msg_064);
	mk_lang_constexpr_static auto const s_out_computed_065 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_065, msg_065);
	mk_lang_constexpr_static auto const s_out_computed_066 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_066, msg_066);
	mk_lang_constexpr_static auto const s_out_computed_067 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_067, msg_067);
	mk_lang_constexpr_static auto const s_out_computed_068 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_068, msg_068);
	mk_lang_constexpr_static auto const s_out_computed_069 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_069, msg_069);
	mk_lang_constexpr_static auto const s_out_computed_070 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_070, msg_070);
	mk_lang_constexpr_static auto const s_out_computed_071 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_071, msg_071);
	mk_lang_constexpr_static auto const s_out_computed_072 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_072, msg_072);
	mk_lang_constexpr_static auto const s_out_computed_073 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_073, msg_073);
	mk_lang_constexpr_static auto const s_out_computed_074 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_074, msg_074);
	mk_lang_constexpr_static auto const s_out_computed_075 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_075, msg_075);
	mk_lang_constexpr_static auto const s_out_computed_076 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_076, msg_076);
	mk_lang_constexpr_static auto const s_out_computed_077 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_077, msg_077);
	mk_lang_constexpr_static auto const s_out_computed_078 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_078, msg_078);
	mk_lang_constexpr_static auto const s_out_computed_079 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_079, msg_079);
	mk_lang_constexpr_static auto const s_out_computed_080 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_080, msg_080);
	mk_lang_constexpr_static auto const s_out_computed_081 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_081, msg_081);
	mk_lang_constexpr_static auto const s_out_computed_082 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_082, msg_082);
	mk_lang_constexpr_static auto const s_out_computed_083 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_083, msg_083);
	mk_lang_constexpr_static auto const s_out_computed_084 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_084, msg_084);
	mk_lang_constexpr_static auto const s_out_computed_085 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_085, msg_085);
	mk_lang_constexpr_static auto const s_out_computed_086 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_086, msg_086);
	mk_lang_constexpr_static auto const s_out_computed_087 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_087, msg_087);
	mk_lang_constexpr_static auto const s_out_computed_088 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_088, msg_088);
	mk_lang_constexpr_static auto const s_out_computed_089 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_089, msg_089);
	mk_lang_constexpr_static auto const s_out_computed_090 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_090, msg_090);
	mk_lang_constexpr_static auto const s_out_computed_091 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_091, msg_091);
	mk_lang_constexpr_static auto const s_out_computed_092 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_092, msg_092);
	mk_lang_constexpr_static auto const s_out_computed_093 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_093, msg_093);
	mk_lang_constexpr_static auto const s_out_computed_094 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_094, msg_094);
	mk_lang_constexpr_static auto const s_out_computed_095 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_095, msg_095);
	mk_lang_constexpr_static auto const s_out_computed_096 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_096, msg_096);
	mk_lang_constexpr_static auto const s_out_computed_097 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_097, msg_097);
	mk_lang_constexpr_static auto const s_out_computed_098 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_098, msg_098);
	mk_lang_constexpr_static auto const s_out_computed_099 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_099, msg_099);
	mk_lang_constexpr_static auto const s_out_computed_100 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_100, msg_100);
	mk_lang_constexpr_static auto const s_out_computed_101 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_101, msg_101);
	mk_lang_constexpr_static auto const s_out_computed_102 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_102, msg_102);
	mk_lang_constexpr_static auto const s_out_computed_103 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_103, msg_103);
	mk_lang_constexpr_static auto const s_out_computed_104 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_104, msg_104);
	mk_lang_constexpr_static auto const s_out_computed_105 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_105, msg_105);
	mk_lang_constexpr_static auto const s_out_computed_106 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_106, msg_106);
	mk_lang_constexpr_static auto const s_out_computed_107 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_107, msg_107);
	mk_lang_constexpr_static auto const s_out_computed_108 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_108, msg_108);
	mk_lang_constexpr_static auto const s_out_computed_109 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_109, msg_109);
	mk_lang_constexpr_static auto const s_out_computed_110 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_110, msg_110);
	mk_lang_constexpr_static auto const s_out_computed_111 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_111, msg_111);
	mk_lang_constexpr_static auto const s_out_computed_112 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_112, msg_112);
	mk_lang_constexpr_static auto const s_out_computed_113 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_113, msg_113);
	mk_lang_constexpr_static auto const s_out_computed_114 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_114, msg_114);
	mk_lang_constexpr_static auto const s_out_computed_115 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_115, msg_115);
	mk_lang_constexpr_static auto const s_out_computed_116 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_116, msg_116);
	mk_lang_constexpr_static auto const s_out_computed_117 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_117, msg_117);
	mk_lang_constexpr_static auto const s_out_computed_118 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_118, msg_118);
	mk_lang_constexpr_static auto const s_out_computed_119 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_119, msg_119);
	mk_lang_constexpr_static auto const s_out_computed_120 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_120, msg_120);
	mk_lang_constexpr_static auto const s_out_computed_121 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_121, msg_121);
	mk_lang_constexpr_static auto const s_out_computed_122 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_122, msg_122);
	mk_lang_constexpr_static auto const s_out_computed_123 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_123, msg_123);
	mk_lang_constexpr_static auto const s_out_computed_124 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_124, msg_124);
	mk_lang_constexpr_static auto const s_out_computed_125 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_125, msg_125);
	mk_lang_constexpr_static auto const s_out_computed_126 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_126, msg_126);
	mk_lang_constexpr_static auto const s_out_computed_127 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_127, msg_127);
	mk_lang_constexpr_static auto const s_out_computed_128 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_128, msg_128);
	mk_lang_constexpr_static auto const s_out_computed_129 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_129, msg_129);
	mk_lang_constexpr_static auto const s_out_computed_130 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_130, msg_130);
	mk_lang_constexpr_static auto const s_out_computed_131 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_131, msg_131);
	mk_lang_constexpr_static auto const s_out_computed_132 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_132, msg_132);
	mk_lang_constexpr_static auto const s_out_computed_133 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_133, msg_133);
	mk_lang_constexpr_static auto const s_out_computed_134 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_134, msg_134);
	mk_lang_constexpr_static auto const s_out_computed_135 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_135, msg_135);
	mk_lang_constexpr_static auto const s_out_computed_136 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_136, msg_136);
	mk_lang_constexpr_static auto const s_out_computed_137 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_137, msg_137);
	mk_lang_constexpr_static auto const s_out_computed_138 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_138, msg_138);
	mk_lang_constexpr_static auto const s_out_computed_139 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_139, msg_139);
	mk_lang_constexpr_static auto const s_out_computed_140 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_140, msg_140);
	mk_lang_constexpr_static auto const s_out_computed_141 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_141, msg_141);
	mk_lang_constexpr_static auto const s_out_computed_142 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_142, msg_142);
	mk_lang_constexpr_static auto const s_out_computed_143 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_143, msg_143);
	mk_lang_constexpr_static auto const s_out_computed_144 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_144, msg_144);
	mk_lang_constexpr_static auto const s_out_computed_145 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_145, msg_145);
	mk_lang_constexpr_static auto const s_out_computed_146 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_146, msg_146);
	mk_lang_constexpr_static auto const s_out_computed_147 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_147, msg_147);
	mk_lang_constexpr_static auto const s_out_computed_148 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_148, msg_148);
	mk_lang_constexpr_static auto const s_out_computed_149 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_149, msg_149);
	mk_lang_constexpr_static auto const s_out_computed_150 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_150, msg_150);
	mk_lang_constexpr_static auto const s_out_computed_151 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_151, msg_151);
	mk_lang_constexpr_static auto const s_out_computed_152 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_152, msg_152);
	mk_lang_constexpr_static auto const s_out_computed_153 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_153, msg_153);
	mk_lang_constexpr_static auto const s_out_computed_154 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_154, msg_154);
	mk_lang_constexpr_static auto const s_out_computed_155 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_155, msg_155);
	mk_lang_constexpr_static auto const s_out_computed_156 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_156, msg_156);
	mk_lang_constexpr_static auto const s_out_computed_157 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_157, msg_157);
	mk_lang_constexpr_static auto const s_out_computed_158 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_158, msg_158);
	mk_lang_constexpr_static auto const s_out_computed_159 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_159, msg_159);
	mk_lang_constexpr_static auto const s_out_computed_160 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_160, msg_160);
	mk_lang_constexpr_static auto const s_out_computed_161 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_161, msg_161);
	mk_lang_constexpr_static auto const s_out_computed_162 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_162, msg_162);
	mk_lang_constexpr_static auto const s_out_computed_163 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_163, msg_163);
	mk_lang_constexpr_static auto const s_out_computed_164 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_164, msg_164);
	mk_lang_constexpr_static auto const s_out_computed_165 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_165, msg_165);
	mk_lang_constexpr_static auto const s_out_computed_166 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_166, msg_166);
	mk_lang_constexpr_static auto const s_out_computed_167 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_167, msg_167);
	mk_lang_constexpr_static auto const s_out_computed_168 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_168, msg_168);
	mk_lang_constexpr_static auto const s_out_computed_169 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_169, msg_169);
	mk_lang_constexpr_static auto const s_out_computed_170 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_170, msg_170);
	mk_lang_constexpr_static auto const s_out_computed_171 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_171, msg_171);
	mk_lang_constexpr_static auto const s_out_computed_172 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_172, msg_172);
	mk_lang_constexpr_static auto const s_out_computed_173 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_173, msg_173);
	mk_lang_constexpr_static auto const s_out_computed_174 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_174, msg_174);
	mk_lang_constexpr_static auto const s_out_computed_175 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_175, msg_175);
	mk_lang_constexpr_static auto const s_out_computed_176 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_176, msg_176);
	mk_lang_constexpr_static auto const s_out_computed_177 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_177, msg_177);
	mk_lang_constexpr_static auto const s_out_computed_178 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_178, msg_178);
	mk_lang_constexpr_static auto const s_out_computed_179 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_179, msg_179);
	mk_lang_constexpr_static auto const s_out_computed_180 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_180, msg_180);
	mk_lang_constexpr_static auto const s_out_computed_181 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_181, msg_181);
	mk_lang_constexpr_static auto const s_out_computed_182 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_182, msg_182);
	mk_lang_constexpr_static auto const s_out_computed_183 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_183, msg_183);
	mk_lang_constexpr_static auto const s_out_computed_184 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_184, msg_184);
	mk_lang_constexpr_static auto const s_out_computed_185 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_185, msg_185);
	mk_lang_constexpr_static auto const s_out_computed_186 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_186, msg_186);
	mk_lang_constexpr_static auto const s_out_computed_187 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_187, msg_187);
	mk_lang_constexpr_static auto const s_out_computed_188 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_188, msg_188);
	mk_lang_constexpr_static auto const s_out_computed_189 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_189, msg_189);
	mk_lang_constexpr_static auto const s_out_computed_190 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_190, msg_190);
	mk_lang_constexpr_static auto const s_out_computed_191 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_191, msg_191);
	mk_lang_constexpr_static auto const s_out_computed_192 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_192, msg_192);
	mk_lang_constexpr_static auto const s_out_computed_193 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_193, msg_193);
	mk_lang_constexpr_static auto const s_out_computed_194 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_194, msg_194);
	mk_lang_constexpr_static auto const s_out_computed_195 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_195, msg_195);
	mk_lang_constexpr_static auto const s_out_computed_196 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_196, msg_196);
	mk_lang_constexpr_static auto const s_out_computed_197 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_197, msg_197);
	mk_lang_constexpr_static auto const s_out_computed_198 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_198, msg_198);
	mk_lang_constexpr_static auto const s_out_computed_199 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_199, msg_199);
	mk_lang_constexpr_static auto const s_out_computed_200 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_200, msg_200);
	mk_lang_constexpr_static auto const s_out_computed_201 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_201, msg_201);
	mk_lang_constexpr_static auto const s_out_computed_202 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_202, msg_202);
	mk_lang_constexpr_static auto const s_out_computed_203 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_203, msg_203);
	mk_lang_constexpr_static auto const s_out_computed_204 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_204, msg_204);
	mk_lang_constexpr_static auto const s_out_computed_205 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_205, msg_205);
	mk_lang_constexpr_static auto const s_out_computed_206 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_206, msg_206);
	mk_lang_constexpr_static auto const s_out_computed_207 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_207, msg_207);
	mk_lang_constexpr_static auto const s_out_computed_208 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_208, msg_208);
	mk_lang_constexpr_static auto const s_out_computed_209 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_209, msg_209);
	mk_lang_constexpr_static auto const s_out_computed_210 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_210, msg_210);
	mk_lang_constexpr_static auto const s_out_computed_211 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_211, msg_211);
	mk_lang_constexpr_static auto const s_out_computed_212 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_212, msg_212);
	mk_lang_constexpr_static auto const s_out_computed_213 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_213, msg_213);
	mk_lang_constexpr_static auto const s_out_computed_214 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_214, msg_214);
	mk_lang_constexpr_static auto const s_out_computed_215 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_215, msg_215);
	mk_lang_constexpr_static auto const s_out_computed_216 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_216, msg_216);
	mk_lang_constexpr_static auto const s_out_computed_217 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_217, msg_217);
	mk_lang_constexpr_static auto const s_out_computed_218 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_218, msg_218);
	mk_lang_constexpr_static auto const s_out_computed_219 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_219, msg_219);
	mk_lang_constexpr_static auto const s_out_computed_220 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_220, msg_220);
	mk_lang_constexpr_static auto const s_out_computed_221 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_221, msg_221);
	mk_lang_constexpr_static auto const s_out_computed_222 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_222, msg_222);
	mk_lang_constexpr_static auto const s_out_computed_223 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_223, msg_223);
	mk_lang_constexpr_static auto const s_out_computed_224 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_224, msg_224);
	mk_lang_constexpr_static auto const s_out_computed_225 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_225, msg_225);
	mk_lang_constexpr_static auto const s_out_computed_226 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_226, msg_226);
	mk_lang_constexpr_static auto const s_out_computed_227 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_227, msg_227);
	mk_lang_constexpr_static auto const s_out_computed_228 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_228, msg_228);
	mk_lang_constexpr_static auto const s_out_computed_229 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_229, msg_229);
	mk_lang_constexpr_static auto const s_out_computed_230 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_230, msg_230);
	mk_lang_constexpr_static auto const s_out_computed_231 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_231, msg_231);
	mk_lang_constexpr_static auto const s_out_computed_232 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_232, msg_232);
	mk_lang_constexpr_static auto const s_out_computed_233 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_233, msg_233);
	mk_lang_constexpr_static auto const s_out_computed_234 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_234, msg_234);
	mk_lang_constexpr_static auto const s_out_computed_235 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_235, msg_235);
	mk_lang_constexpr_static auto const s_out_computed_236 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_236, msg_236);
	mk_lang_constexpr_static auto const s_out_computed_237 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_237, msg_237);
	mk_lang_constexpr_static auto const s_out_computed_238 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_238, msg_238);
	mk_lang_constexpr_static auto const s_out_computed_239 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_239, msg_239);
	mk_lang_constexpr_static auto const s_out_computed_240 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_240, msg_240);
	mk_lang_constexpr_static auto const s_out_computed_241 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_241, msg_241);
	mk_lang_constexpr_static auto const s_out_computed_242 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_242, msg_242);
	mk_lang_constexpr_static auto const s_out_computed_243 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_243, msg_243);
	mk_lang_constexpr_static auto const s_out_computed_244 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_244, msg_244);
	mk_lang_constexpr_static auto const s_out_computed_245 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_245, msg_245);
	mk_lang_constexpr_static auto const s_out_computed_246 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_246, msg_246);
	mk_lang_constexpr_static auto const s_out_computed_247 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_247, msg_247);
	mk_lang_constexpr_static auto const s_out_computed_248 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_248, msg_248);
	mk_lang_constexpr_static auto const s_out_computed_249 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_249, msg_249);
	mk_lang_constexpr_static auto const s_out_computed_250 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_250, msg_250);
	mk_lang_constexpr_static auto const s_out_computed_251 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_251, msg_251);
	mk_lang_constexpr_static auto const s_out_computed_252 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_252, msg_252);
	mk_lang_constexpr_static auto const s_out_computed_253 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_253, msg_253);
	mk_lang_constexpr_static auto const s_out_computed_254 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_254, msg_254);
	mk_lang_constexpr_static auto const s_out_computed_255 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_255, msg_255);
	mk_lang_constexpr_static auto const s_out_computed_256 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_256, msg_256);
	mk_lang_constexpr_static auto const s_out_computed_257 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_257, msg_257);
	mk_lang_constexpr_static auto const s_out_computed_258 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_258, msg_258);
	mk_lang_constexpr_static auto const s_out_computed_259 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_259, msg_259);
	mk_lang_constexpr_static auto const s_out_computed_260 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_260, msg_260);
	mk_lang_constexpr_static auto const s_out_computed_261 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_261, msg_261);
	mk_lang_constexpr_static auto const s_out_computed_262 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_262, msg_262);
	mk_lang_constexpr_static auto const s_out_computed_263 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_263, msg_263);
	mk_lang_constexpr_static auto const s_out_computed_264 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_264, msg_264);
	mk_lang_constexpr_static auto const s_out_computed_265 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_265, msg_265);
	mk_lang_constexpr_static auto const s_out_computed_266 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_266, msg_266);
	mk_lang_constexpr_static auto const s_out_computed_267 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_267, msg_267);
	mk_lang_constexpr_static auto const s_out_computed_268 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_268, msg_268);
	mk_lang_constexpr_static auto const s_out_computed_269 = mk_lib_crypto_alg_des_test_encrypt_from_str_lit(key_269, msg_269);

	mk_lang_constexpr_static auto const s_msg_computed_000 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_000, s_out_computed_000);
	mk_lang_constexpr_static auto const s_msg_computed_001 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_001, s_out_computed_001);
	mk_lang_constexpr_static auto const s_msg_computed_002 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_002, s_out_computed_002);
	mk_lang_constexpr_static auto const s_msg_computed_003 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_003, s_out_computed_003);
	mk_lang_constexpr_static auto const s_msg_computed_004 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_004, s_out_computed_004);
	mk_lang_constexpr_static auto const s_msg_computed_005 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_005, s_out_computed_005);
	mk_lang_constexpr_static auto const s_msg_computed_006 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_006, s_out_computed_006);
	mk_lang_constexpr_static auto const s_msg_computed_007 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_007, s_out_computed_007);
	mk_lang_constexpr_static auto const s_msg_computed_008 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_008, s_out_computed_008);
	mk_lang_constexpr_static auto const s_msg_computed_009 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_009, s_out_computed_009);
	mk_lang_constexpr_static auto const s_msg_computed_010 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_010, s_out_computed_010);
	mk_lang_constexpr_static auto const s_msg_computed_011 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_011, s_out_computed_011);
	mk_lang_constexpr_static auto const s_msg_computed_012 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_012, s_out_computed_012);
	mk_lang_constexpr_static auto const s_msg_computed_013 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_013, s_out_computed_013);
	mk_lang_constexpr_static auto const s_msg_computed_014 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_014, s_out_computed_014);
	mk_lang_constexpr_static auto const s_msg_computed_015 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_015, s_out_computed_015);
	mk_lang_constexpr_static auto const s_msg_computed_016 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_016, s_out_computed_016);
	mk_lang_constexpr_static auto const s_msg_computed_017 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_017, s_out_computed_017);
	mk_lang_constexpr_static auto const s_msg_computed_018 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_018, s_out_computed_018);
	mk_lang_constexpr_static auto const s_msg_computed_019 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_019, s_out_computed_019);
	mk_lang_constexpr_static auto const s_msg_computed_020 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_020, s_out_computed_020);
	mk_lang_constexpr_static auto const s_msg_computed_021 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_021, s_out_computed_021);
	mk_lang_constexpr_static auto const s_msg_computed_022 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_022, s_out_computed_022);
	mk_lang_constexpr_static auto const s_msg_computed_023 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_023, s_out_computed_023);
	mk_lang_constexpr_static auto const s_msg_computed_024 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_024, s_out_computed_024);
	mk_lang_constexpr_static auto const s_msg_computed_025 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_025, s_out_computed_025);
	mk_lang_constexpr_static auto const s_msg_computed_026 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_026, s_out_computed_026);
	mk_lang_constexpr_static auto const s_msg_computed_027 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_027, s_out_computed_027);
	mk_lang_constexpr_static auto const s_msg_computed_028 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_028, s_out_computed_028);
	mk_lang_constexpr_static auto const s_msg_computed_029 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_029, s_out_computed_029);
	mk_lang_constexpr_static auto const s_msg_computed_030 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_030, s_out_computed_030);
	mk_lang_constexpr_static auto const s_msg_computed_031 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_031, s_out_computed_031);
	mk_lang_constexpr_static auto const s_msg_computed_032 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_032, s_out_computed_032);
	mk_lang_constexpr_static auto const s_msg_computed_033 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_033, s_out_computed_033);
	mk_lang_constexpr_static auto const s_msg_computed_034 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_034, s_out_computed_034);
	mk_lang_constexpr_static auto const s_msg_computed_035 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_035, s_out_computed_035);
	mk_lang_constexpr_static auto const s_msg_computed_036 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_036, s_out_computed_036);
	mk_lang_constexpr_static auto const s_msg_computed_037 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_037, s_out_computed_037);
	mk_lang_constexpr_static auto const s_msg_computed_038 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_038, s_out_computed_038);
	mk_lang_constexpr_static auto const s_msg_computed_039 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_039, s_out_computed_039);
	mk_lang_constexpr_static auto const s_msg_computed_040 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_040, s_out_computed_040);
	mk_lang_constexpr_static auto const s_msg_computed_041 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_041, s_out_computed_041);
	mk_lang_constexpr_static auto const s_msg_computed_042 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_042, s_out_computed_042);
	mk_lang_constexpr_static auto const s_msg_computed_043 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_043, s_out_computed_043);
	mk_lang_constexpr_static auto const s_msg_computed_044 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_044, s_out_computed_044);
	mk_lang_constexpr_static auto const s_msg_computed_045 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_045, s_out_computed_045);
	mk_lang_constexpr_static auto const s_msg_computed_046 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_046, s_out_computed_046);
	mk_lang_constexpr_static auto const s_msg_computed_047 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_047, s_out_computed_047);
	mk_lang_constexpr_static auto const s_msg_computed_048 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_048, s_out_computed_048);
	mk_lang_constexpr_static auto const s_msg_computed_049 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_049, s_out_computed_049);
	mk_lang_constexpr_static auto const s_msg_computed_050 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_050, s_out_computed_050);
	mk_lang_constexpr_static auto const s_msg_computed_051 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_051, s_out_computed_051);
	mk_lang_constexpr_static auto const s_msg_computed_052 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_052, s_out_computed_052);
	mk_lang_constexpr_static auto const s_msg_computed_053 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_053, s_out_computed_053);
	mk_lang_constexpr_static auto const s_msg_computed_054 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_054, s_out_computed_054);
	mk_lang_constexpr_static auto const s_msg_computed_055 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_055, s_out_computed_055);
	mk_lang_constexpr_static auto const s_msg_computed_056 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_056, s_out_computed_056);
	mk_lang_constexpr_static auto const s_msg_computed_057 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_057, s_out_computed_057);
	mk_lang_constexpr_static auto const s_msg_computed_058 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_058, s_out_computed_058);
	mk_lang_constexpr_static auto const s_msg_computed_059 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_059, s_out_computed_059);
	mk_lang_constexpr_static auto const s_msg_computed_060 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_060, s_out_computed_060);
	mk_lang_constexpr_static auto const s_msg_computed_061 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_061, s_out_computed_061);
	mk_lang_constexpr_static auto const s_msg_computed_062 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_062, s_out_computed_062);
	mk_lang_constexpr_static auto const s_msg_computed_063 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_063, s_out_computed_063);
	mk_lang_constexpr_static auto const s_msg_computed_064 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_064, s_out_computed_064);
	mk_lang_constexpr_static auto const s_msg_computed_065 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_065, s_out_computed_065);
	mk_lang_constexpr_static auto const s_msg_computed_066 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_066, s_out_computed_066);
	mk_lang_constexpr_static auto const s_msg_computed_067 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_067, s_out_computed_067);
	mk_lang_constexpr_static auto const s_msg_computed_068 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_068, s_out_computed_068);
	mk_lang_constexpr_static auto const s_msg_computed_069 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_069, s_out_computed_069);
	mk_lang_constexpr_static auto const s_msg_computed_070 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_070, s_out_computed_070);
	mk_lang_constexpr_static auto const s_msg_computed_071 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_071, s_out_computed_071);
	mk_lang_constexpr_static auto const s_msg_computed_072 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_072, s_out_computed_072);
	mk_lang_constexpr_static auto const s_msg_computed_073 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_073, s_out_computed_073);
	mk_lang_constexpr_static auto const s_msg_computed_074 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_074, s_out_computed_074);
	mk_lang_constexpr_static auto const s_msg_computed_075 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_075, s_out_computed_075);
	mk_lang_constexpr_static auto const s_msg_computed_076 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_076, s_out_computed_076);
	mk_lang_constexpr_static auto const s_msg_computed_077 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_077, s_out_computed_077);
	mk_lang_constexpr_static auto const s_msg_computed_078 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_078, s_out_computed_078);
	mk_lang_constexpr_static auto const s_msg_computed_079 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_079, s_out_computed_079);
	mk_lang_constexpr_static auto const s_msg_computed_080 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_080, s_out_computed_080);
	mk_lang_constexpr_static auto const s_msg_computed_081 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_081, s_out_computed_081);
	mk_lang_constexpr_static auto const s_msg_computed_082 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_082, s_out_computed_082);
	mk_lang_constexpr_static auto const s_msg_computed_083 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_083, s_out_computed_083);
	mk_lang_constexpr_static auto const s_msg_computed_084 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_084, s_out_computed_084);
	mk_lang_constexpr_static auto const s_msg_computed_085 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_085, s_out_computed_085);
	mk_lang_constexpr_static auto const s_msg_computed_086 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_086, s_out_computed_086);
	mk_lang_constexpr_static auto const s_msg_computed_087 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_087, s_out_computed_087);
	mk_lang_constexpr_static auto const s_msg_computed_088 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_088, s_out_computed_088);
	mk_lang_constexpr_static auto const s_msg_computed_089 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_089, s_out_computed_089);
	mk_lang_constexpr_static auto const s_msg_computed_090 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_090, s_out_computed_090);
	mk_lang_constexpr_static auto const s_msg_computed_091 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_091, s_out_computed_091);
	mk_lang_constexpr_static auto const s_msg_computed_092 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_092, s_out_computed_092);
	mk_lang_constexpr_static auto const s_msg_computed_093 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_093, s_out_computed_093);
	mk_lang_constexpr_static auto const s_msg_computed_094 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_094, s_out_computed_094);
	mk_lang_constexpr_static auto const s_msg_computed_095 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_095, s_out_computed_095);
	mk_lang_constexpr_static auto const s_msg_computed_096 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_096, s_out_computed_096);
	mk_lang_constexpr_static auto const s_msg_computed_097 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_097, s_out_computed_097);
	mk_lang_constexpr_static auto const s_msg_computed_098 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_098, s_out_computed_098);
	mk_lang_constexpr_static auto const s_msg_computed_099 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_099, s_out_computed_099);
	mk_lang_constexpr_static auto const s_msg_computed_100 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_100, s_out_computed_100);
	mk_lang_constexpr_static auto const s_msg_computed_101 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_101, s_out_computed_101);
	mk_lang_constexpr_static auto const s_msg_computed_102 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_102, s_out_computed_102);
	mk_lang_constexpr_static auto const s_msg_computed_103 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_103, s_out_computed_103);
	mk_lang_constexpr_static auto const s_msg_computed_104 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_104, s_out_computed_104);
	mk_lang_constexpr_static auto const s_msg_computed_105 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_105, s_out_computed_105);
	mk_lang_constexpr_static auto const s_msg_computed_106 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_106, s_out_computed_106);
	mk_lang_constexpr_static auto const s_msg_computed_107 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_107, s_out_computed_107);
	mk_lang_constexpr_static auto const s_msg_computed_108 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_108, s_out_computed_108);
	mk_lang_constexpr_static auto const s_msg_computed_109 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_109, s_out_computed_109);
	mk_lang_constexpr_static auto const s_msg_computed_110 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_110, s_out_computed_110);
	mk_lang_constexpr_static auto const s_msg_computed_111 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_111, s_out_computed_111);
	mk_lang_constexpr_static auto const s_msg_computed_112 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_112, s_out_computed_112);
	mk_lang_constexpr_static auto const s_msg_computed_113 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_113, s_out_computed_113);
	mk_lang_constexpr_static auto const s_msg_computed_114 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_114, s_out_computed_114);
	mk_lang_constexpr_static auto const s_msg_computed_115 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_115, s_out_computed_115);
	mk_lang_constexpr_static auto const s_msg_computed_116 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_116, s_out_computed_116);
	mk_lang_constexpr_static auto const s_msg_computed_117 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_117, s_out_computed_117);
	mk_lang_constexpr_static auto const s_msg_computed_118 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_118, s_out_computed_118);
	mk_lang_constexpr_static auto const s_msg_computed_119 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_119, s_out_computed_119);
	mk_lang_constexpr_static auto const s_msg_computed_120 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_120, s_out_computed_120);
	mk_lang_constexpr_static auto const s_msg_computed_121 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_121, s_out_computed_121);
	mk_lang_constexpr_static auto const s_msg_computed_122 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_122, s_out_computed_122);
	mk_lang_constexpr_static auto const s_msg_computed_123 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_123, s_out_computed_123);
	mk_lang_constexpr_static auto const s_msg_computed_124 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_124, s_out_computed_124);
	mk_lang_constexpr_static auto const s_msg_computed_125 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_125, s_out_computed_125);
	mk_lang_constexpr_static auto const s_msg_computed_126 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_126, s_out_computed_126);
	mk_lang_constexpr_static auto const s_msg_computed_127 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_127, s_out_computed_127);
	mk_lang_constexpr_static auto const s_msg_computed_128 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_128, s_out_computed_128);
	mk_lang_constexpr_static auto const s_msg_computed_129 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_129, s_out_computed_129);
	mk_lang_constexpr_static auto const s_msg_computed_130 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_130, s_out_computed_130);
	mk_lang_constexpr_static auto const s_msg_computed_131 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_131, s_out_computed_131);
	mk_lang_constexpr_static auto const s_msg_computed_132 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_132, s_out_computed_132);
	mk_lang_constexpr_static auto const s_msg_computed_133 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_133, s_out_computed_133);
	mk_lang_constexpr_static auto const s_msg_computed_134 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_134, s_out_computed_134);
	mk_lang_constexpr_static auto const s_msg_computed_135 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_135, s_out_computed_135);
	mk_lang_constexpr_static auto const s_msg_computed_136 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_136, s_out_computed_136);
	mk_lang_constexpr_static auto const s_msg_computed_137 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_137, s_out_computed_137);
	mk_lang_constexpr_static auto const s_msg_computed_138 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_138, s_out_computed_138);
	mk_lang_constexpr_static auto const s_msg_computed_139 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_139, s_out_computed_139);
	mk_lang_constexpr_static auto const s_msg_computed_140 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_140, s_out_computed_140);
	mk_lang_constexpr_static auto const s_msg_computed_141 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_141, s_out_computed_141);
	mk_lang_constexpr_static auto const s_msg_computed_142 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_142, s_out_computed_142);
	mk_lang_constexpr_static auto const s_msg_computed_143 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_143, s_out_computed_143);
	mk_lang_constexpr_static auto const s_msg_computed_144 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_144, s_out_computed_144);
	mk_lang_constexpr_static auto const s_msg_computed_145 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_145, s_out_computed_145);
	mk_lang_constexpr_static auto const s_msg_computed_146 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_146, s_out_computed_146);
	mk_lang_constexpr_static auto const s_msg_computed_147 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_147, s_out_computed_147);
	mk_lang_constexpr_static auto const s_msg_computed_148 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_148, s_out_computed_148);
	mk_lang_constexpr_static auto const s_msg_computed_149 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_149, s_out_computed_149);
	mk_lang_constexpr_static auto const s_msg_computed_150 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_150, s_out_computed_150);
	mk_lang_constexpr_static auto const s_msg_computed_151 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_151, s_out_computed_151);
	mk_lang_constexpr_static auto const s_msg_computed_152 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_152, s_out_computed_152);
	mk_lang_constexpr_static auto const s_msg_computed_153 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_153, s_out_computed_153);
	mk_lang_constexpr_static auto const s_msg_computed_154 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_154, s_out_computed_154);
	mk_lang_constexpr_static auto const s_msg_computed_155 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_155, s_out_computed_155);
	mk_lang_constexpr_static auto const s_msg_computed_156 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_156, s_out_computed_156);
	mk_lang_constexpr_static auto const s_msg_computed_157 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_157, s_out_computed_157);
	mk_lang_constexpr_static auto const s_msg_computed_158 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_158, s_out_computed_158);
	mk_lang_constexpr_static auto const s_msg_computed_159 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_159, s_out_computed_159);
	mk_lang_constexpr_static auto const s_msg_computed_160 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_160, s_out_computed_160);
	mk_lang_constexpr_static auto const s_msg_computed_161 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_161, s_out_computed_161);
	mk_lang_constexpr_static auto const s_msg_computed_162 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_162, s_out_computed_162);
	mk_lang_constexpr_static auto const s_msg_computed_163 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_163, s_out_computed_163);
	mk_lang_constexpr_static auto const s_msg_computed_164 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_164, s_out_computed_164);
	mk_lang_constexpr_static auto const s_msg_computed_165 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_165, s_out_computed_165);
	mk_lang_constexpr_static auto const s_msg_computed_166 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_166, s_out_computed_166);
	mk_lang_constexpr_static auto const s_msg_computed_167 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_167, s_out_computed_167);
	mk_lang_constexpr_static auto const s_msg_computed_168 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_168, s_out_computed_168);
	mk_lang_constexpr_static auto const s_msg_computed_169 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_169, s_out_computed_169);
	mk_lang_constexpr_static auto const s_msg_computed_170 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_170, s_out_computed_170);
	mk_lang_constexpr_static auto const s_msg_computed_171 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_171, s_out_computed_171);
	mk_lang_constexpr_static auto const s_msg_computed_172 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_172, s_out_computed_172);
	mk_lang_constexpr_static auto const s_msg_computed_173 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_173, s_out_computed_173);
	mk_lang_constexpr_static auto const s_msg_computed_174 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_174, s_out_computed_174);
	mk_lang_constexpr_static auto const s_msg_computed_175 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_175, s_out_computed_175);
	mk_lang_constexpr_static auto const s_msg_computed_176 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_176, s_out_computed_176);
	mk_lang_constexpr_static auto const s_msg_computed_177 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_177, s_out_computed_177);
	mk_lang_constexpr_static auto const s_msg_computed_178 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_178, s_out_computed_178);
	mk_lang_constexpr_static auto const s_msg_computed_179 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_179, s_out_computed_179);
	mk_lang_constexpr_static auto const s_msg_computed_180 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_180, s_out_computed_180);
	mk_lang_constexpr_static auto const s_msg_computed_181 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_181, s_out_computed_181);
	mk_lang_constexpr_static auto const s_msg_computed_182 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_182, s_out_computed_182);
	mk_lang_constexpr_static auto const s_msg_computed_183 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_183, s_out_computed_183);
	mk_lang_constexpr_static auto const s_msg_computed_184 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_184, s_out_computed_184);
	mk_lang_constexpr_static auto const s_msg_computed_185 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_185, s_out_computed_185);
	mk_lang_constexpr_static auto const s_msg_computed_186 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_186, s_out_computed_186);
	mk_lang_constexpr_static auto const s_msg_computed_187 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_187, s_out_computed_187);
	mk_lang_constexpr_static auto const s_msg_computed_188 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_188, s_out_computed_188);
	mk_lang_constexpr_static auto const s_msg_computed_189 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_189, s_out_computed_189);
	mk_lang_constexpr_static auto const s_msg_computed_190 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_190, s_out_computed_190);
	mk_lang_constexpr_static auto const s_msg_computed_191 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_191, s_out_computed_191);
	mk_lang_constexpr_static auto const s_msg_computed_192 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_192, s_out_computed_192);
	mk_lang_constexpr_static auto const s_msg_computed_193 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_193, s_out_computed_193);
	mk_lang_constexpr_static auto const s_msg_computed_194 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_194, s_out_computed_194);
	mk_lang_constexpr_static auto const s_msg_computed_195 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_195, s_out_computed_195);
	mk_lang_constexpr_static auto const s_msg_computed_196 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_196, s_out_computed_196);
	mk_lang_constexpr_static auto const s_msg_computed_197 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_197, s_out_computed_197);
	mk_lang_constexpr_static auto const s_msg_computed_198 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_198, s_out_computed_198);
	mk_lang_constexpr_static auto const s_msg_computed_199 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_199, s_out_computed_199);
	mk_lang_constexpr_static auto const s_msg_computed_200 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_200, s_out_computed_200);
	mk_lang_constexpr_static auto const s_msg_computed_201 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_201, s_out_computed_201);
	mk_lang_constexpr_static auto const s_msg_computed_202 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_202, s_out_computed_202);
	mk_lang_constexpr_static auto const s_msg_computed_203 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_203, s_out_computed_203);
	mk_lang_constexpr_static auto const s_msg_computed_204 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_204, s_out_computed_204);
	mk_lang_constexpr_static auto const s_msg_computed_205 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_205, s_out_computed_205);
	mk_lang_constexpr_static auto const s_msg_computed_206 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_206, s_out_computed_206);
	mk_lang_constexpr_static auto const s_msg_computed_207 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_207, s_out_computed_207);
	mk_lang_constexpr_static auto const s_msg_computed_208 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_208, s_out_computed_208);
	mk_lang_constexpr_static auto const s_msg_computed_209 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_209, s_out_computed_209);
	mk_lang_constexpr_static auto const s_msg_computed_210 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_210, s_out_computed_210);
	mk_lang_constexpr_static auto const s_msg_computed_211 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_211, s_out_computed_211);
	mk_lang_constexpr_static auto const s_msg_computed_212 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_212, s_out_computed_212);
	mk_lang_constexpr_static auto const s_msg_computed_213 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_213, s_out_computed_213);
	mk_lang_constexpr_static auto const s_msg_computed_214 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_214, s_out_computed_214);
	mk_lang_constexpr_static auto const s_msg_computed_215 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_215, s_out_computed_215);
	mk_lang_constexpr_static auto const s_msg_computed_216 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_216, s_out_computed_216);
	mk_lang_constexpr_static auto const s_msg_computed_217 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_217, s_out_computed_217);
	mk_lang_constexpr_static auto const s_msg_computed_218 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_218, s_out_computed_218);
	mk_lang_constexpr_static auto const s_msg_computed_219 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_219, s_out_computed_219);
	mk_lang_constexpr_static auto const s_msg_computed_220 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_220, s_out_computed_220);
	mk_lang_constexpr_static auto const s_msg_computed_221 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_221, s_out_computed_221);
	mk_lang_constexpr_static auto const s_msg_computed_222 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_222, s_out_computed_222);
	mk_lang_constexpr_static auto const s_msg_computed_223 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_223, s_out_computed_223);
	mk_lang_constexpr_static auto const s_msg_computed_224 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_224, s_out_computed_224);
	mk_lang_constexpr_static auto const s_msg_computed_225 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_225, s_out_computed_225);
	mk_lang_constexpr_static auto const s_msg_computed_226 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_226, s_out_computed_226);
	mk_lang_constexpr_static auto const s_msg_computed_227 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_227, s_out_computed_227);
	mk_lang_constexpr_static auto const s_msg_computed_228 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_228, s_out_computed_228);
	mk_lang_constexpr_static auto const s_msg_computed_229 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_229, s_out_computed_229);
	mk_lang_constexpr_static auto const s_msg_computed_230 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_230, s_out_computed_230);
	mk_lang_constexpr_static auto const s_msg_computed_231 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_231, s_out_computed_231);
	mk_lang_constexpr_static auto const s_msg_computed_232 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_232, s_out_computed_232);
	mk_lang_constexpr_static auto const s_msg_computed_233 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_233, s_out_computed_233);
	mk_lang_constexpr_static auto const s_msg_computed_234 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_234, s_out_computed_234);
	mk_lang_constexpr_static auto const s_msg_computed_235 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_235, s_out_computed_235);
	mk_lang_constexpr_static auto const s_msg_computed_236 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_236, s_out_computed_236);
	mk_lang_constexpr_static auto const s_msg_computed_237 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_237, s_out_computed_237);
	mk_lang_constexpr_static auto const s_msg_computed_238 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_238, s_out_computed_238);
	mk_lang_constexpr_static auto const s_msg_computed_239 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_239, s_out_computed_239);
	mk_lang_constexpr_static auto const s_msg_computed_240 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_240, s_out_computed_240);
	mk_lang_constexpr_static auto const s_msg_computed_241 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_241, s_out_computed_241);
	mk_lang_constexpr_static auto const s_msg_computed_242 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_242, s_out_computed_242);
	mk_lang_constexpr_static auto const s_msg_computed_243 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_243, s_out_computed_243);
	mk_lang_constexpr_static auto const s_msg_computed_244 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_244, s_out_computed_244);
	mk_lang_constexpr_static auto const s_msg_computed_245 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_245, s_out_computed_245);
	mk_lang_constexpr_static auto const s_msg_computed_246 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_246, s_out_computed_246);
	mk_lang_constexpr_static auto const s_msg_computed_247 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_247, s_out_computed_247);
	mk_lang_constexpr_static auto const s_msg_computed_248 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_248, s_out_computed_248);
	mk_lang_constexpr_static auto const s_msg_computed_249 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_249, s_out_computed_249);
	mk_lang_constexpr_static auto const s_msg_computed_250 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_250, s_out_computed_250);
	mk_lang_constexpr_static auto const s_msg_computed_251 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_251, s_out_computed_251);
	mk_lang_constexpr_static auto const s_msg_computed_252 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_252, s_out_computed_252);
	mk_lang_constexpr_static auto const s_msg_computed_253 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_253, s_out_computed_253);
	mk_lang_constexpr_static auto const s_msg_computed_254 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_254, s_out_computed_254);
	mk_lang_constexpr_static auto const s_msg_computed_255 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_255, s_out_computed_255);
	mk_lang_constexpr_static auto const s_msg_computed_256 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_256, s_out_computed_256);
	mk_lang_constexpr_static auto const s_msg_computed_257 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_257, s_out_computed_257);
	mk_lang_constexpr_static auto const s_msg_computed_258 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_258, s_out_computed_258);
	mk_lang_constexpr_static auto const s_msg_computed_259 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_259, s_out_computed_259);
	mk_lang_constexpr_static auto const s_msg_computed_260 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_260, s_out_computed_260);
	mk_lang_constexpr_static auto const s_msg_computed_261 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_261, s_out_computed_261);
	mk_lang_constexpr_static auto const s_msg_computed_262 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_262, s_out_computed_262);
	mk_lang_constexpr_static auto const s_msg_computed_263 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_263, s_out_computed_263);
	mk_lang_constexpr_static auto const s_msg_computed_264 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_264, s_out_computed_264);
	mk_lang_constexpr_static auto const s_msg_computed_265 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_265, s_out_computed_265);
	mk_lang_constexpr_static auto const s_msg_computed_266 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_266, s_out_computed_266);
	mk_lang_constexpr_static auto const s_msg_computed_267 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_267, s_out_computed_267);
	mk_lang_constexpr_static auto const s_msg_computed_268 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_268, s_out_computed_268);
	mk_lang_constexpr_static auto const s_msg_computed_269 = mk_lib_crypto_alg_des_test_decrypt_from_str_lit(key_269, s_out_computed_269);

	mk_lang_constexpr_static auto const s_out_precomputed_000 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_000);
	mk_lang_constexpr_static auto const s_out_precomputed_001 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_001);
	mk_lang_constexpr_static auto const s_out_precomputed_002 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_002);
	mk_lang_constexpr_static auto const s_out_precomputed_003 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_003);
	mk_lang_constexpr_static auto const s_out_precomputed_004 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_004);
	mk_lang_constexpr_static auto const s_out_precomputed_005 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_005);
	mk_lang_constexpr_static auto const s_out_precomputed_006 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_006);
	mk_lang_constexpr_static auto const s_out_precomputed_007 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_007);
	mk_lang_constexpr_static auto const s_out_precomputed_008 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_008);
	mk_lang_constexpr_static auto const s_out_precomputed_009 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_009);
	mk_lang_constexpr_static auto const s_out_precomputed_010 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_010);
	mk_lang_constexpr_static auto const s_out_precomputed_011 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_011);
	mk_lang_constexpr_static auto const s_out_precomputed_012 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_012);
	mk_lang_constexpr_static auto const s_out_precomputed_013 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_013);
	mk_lang_constexpr_static auto const s_out_precomputed_014 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_014);
	mk_lang_constexpr_static auto const s_out_precomputed_015 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_015);
	mk_lang_constexpr_static auto const s_out_precomputed_016 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_016);
	mk_lang_constexpr_static auto const s_out_precomputed_017 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_017);
	mk_lang_constexpr_static auto const s_out_precomputed_018 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_018);
	mk_lang_constexpr_static auto const s_out_precomputed_019 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_019);
	mk_lang_constexpr_static auto const s_out_precomputed_020 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_020);
	mk_lang_constexpr_static auto const s_out_precomputed_021 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_021);
	mk_lang_constexpr_static auto const s_out_precomputed_022 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_022);
	mk_lang_constexpr_static auto const s_out_precomputed_023 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_023);
	mk_lang_constexpr_static auto const s_out_precomputed_024 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_024);
	mk_lang_constexpr_static auto const s_out_precomputed_025 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_025);
	mk_lang_constexpr_static auto const s_out_precomputed_026 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_026);
	mk_lang_constexpr_static auto const s_out_precomputed_027 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_027);
	mk_lang_constexpr_static auto const s_out_precomputed_028 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_028);
	mk_lang_constexpr_static auto const s_out_precomputed_029 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_029);
	mk_lang_constexpr_static auto const s_out_precomputed_030 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_030);
	mk_lang_constexpr_static auto const s_out_precomputed_031 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_031);
	mk_lang_constexpr_static auto const s_out_precomputed_032 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_032);
	mk_lang_constexpr_static auto const s_out_precomputed_033 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_033);
	mk_lang_constexpr_static auto const s_out_precomputed_034 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_034);
	mk_lang_constexpr_static auto const s_out_precomputed_035 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_035);
	mk_lang_constexpr_static auto const s_out_precomputed_036 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_036);
	mk_lang_constexpr_static auto const s_out_precomputed_037 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_037);
	mk_lang_constexpr_static auto const s_out_precomputed_038 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_038);
	mk_lang_constexpr_static auto const s_out_precomputed_039 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_039);
	mk_lang_constexpr_static auto const s_out_precomputed_040 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_040);
	mk_lang_constexpr_static auto const s_out_precomputed_041 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_041);
	mk_lang_constexpr_static auto const s_out_precomputed_042 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_042);
	mk_lang_constexpr_static auto const s_out_precomputed_043 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_043);
	mk_lang_constexpr_static auto const s_out_precomputed_044 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_044);
	mk_lang_constexpr_static auto const s_out_precomputed_045 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_045);
	mk_lang_constexpr_static auto const s_out_precomputed_046 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_046);
	mk_lang_constexpr_static auto const s_out_precomputed_047 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_047);
	mk_lang_constexpr_static auto const s_out_precomputed_048 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_048);
	mk_lang_constexpr_static auto const s_out_precomputed_049 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_049);
	mk_lang_constexpr_static auto const s_out_precomputed_050 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_050);
	mk_lang_constexpr_static auto const s_out_precomputed_051 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_051);
	mk_lang_constexpr_static auto const s_out_precomputed_052 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_052);
	mk_lang_constexpr_static auto const s_out_precomputed_053 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_053);
	mk_lang_constexpr_static auto const s_out_precomputed_054 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_054);
	mk_lang_constexpr_static auto const s_out_precomputed_055 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_055);
	mk_lang_constexpr_static auto const s_out_precomputed_056 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_056);
	mk_lang_constexpr_static auto const s_out_precomputed_057 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_057);
	mk_lang_constexpr_static auto const s_out_precomputed_058 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_058);
	mk_lang_constexpr_static auto const s_out_precomputed_059 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_059);
	mk_lang_constexpr_static auto const s_out_precomputed_060 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_060);
	mk_lang_constexpr_static auto const s_out_precomputed_061 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_061);
	mk_lang_constexpr_static auto const s_out_precomputed_062 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_062);
	mk_lang_constexpr_static auto const s_out_precomputed_063 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_063);
	mk_lang_constexpr_static auto const s_out_precomputed_064 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_064);
	mk_lang_constexpr_static auto const s_out_precomputed_065 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_065);
	mk_lang_constexpr_static auto const s_out_precomputed_066 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_066);
	mk_lang_constexpr_static auto const s_out_precomputed_067 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_067);
	mk_lang_constexpr_static auto const s_out_precomputed_068 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_068);
	mk_lang_constexpr_static auto const s_out_precomputed_069 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_069);
	mk_lang_constexpr_static auto const s_out_precomputed_070 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_070);
	mk_lang_constexpr_static auto const s_out_precomputed_071 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_071);
	mk_lang_constexpr_static auto const s_out_precomputed_072 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_072);
	mk_lang_constexpr_static auto const s_out_precomputed_073 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_073);
	mk_lang_constexpr_static auto const s_out_precomputed_074 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_074);
	mk_lang_constexpr_static auto const s_out_precomputed_075 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_075);
	mk_lang_constexpr_static auto const s_out_precomputed_076 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_076);
	mk_lang_constexpr_static auto const s_out_precomputed_077 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_077);
	mk_lang_constexpr_static auto const s_out_precomputed_078 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_078);
	mk_lang_constexpr_static auto const s_out_precomputed_079 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_079);
	mk_lang_constexpr_static auto const s_out_precomputed_080 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_080);
	mk_lang_constexpr_static auto const s_out_precomputed_081 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_081);
	mk_lang_constexpr_static auto const s_out_precomputed_082 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_082);
	mk_lang_constexpr_static auto const s_out_precomputed_083 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_083);
	mk_lang_constexpr_static auto const s_out_precomputed_084 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_084);
	mk_lang_constexpr_static auto const s_out_precomputed_085 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_085);
	mk_lang_constexpr_static auto const s_out_precomputed_086 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_086);
	mk_lang_constexpr_static auto const s_out_precomputed_087 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_087);
	mk_lang_constexpr_static auto const s_out_precomputed_088 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_088);
	mk_lang_constexpr_static auto const s_out_precomputed_089 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_089);
	mk_lang_constexpr_static auto const s_out_precomputed_090 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_090);
	mk_lang_constexpr_static auto const s_out_precomputed_091 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_091);
	mk_lang_constexpr_static auto const s_out_precomputed_092 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_092);
	mk_lang_constexpr_static auto const s_out_precomputed_093 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_093);
	mk_lang_constexpr_static auto const s_out_precomputed_094 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_094);
	mk_lang_constexpr_static auto const s_out_precomputed_095 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_095);
	mk_lang_constexpr_static auto const s_out_precomputed_096 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_096);
	mk_lang_constexpr_static auto const s_out_precomputed_097 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_097);
	mk_lang_constexpr_static auto const s_out_precomputed_098 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_098);
	mk_lang_constexpr_static auto const s_out_precomputed_099 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_099);
	mk_lang_constexpr_static auto const s_out_precomputed_100 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_100);
	mk_lang_constexpr_static auto const s_out_precomputed_101 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_101);
	mk_lang_constexpr_static auto const s_out_precomputed_102 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_102);
	mk_lang_constexpr_static auto const s_out_precomputed_103 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_103);
	mk_lang_constexpr_static auto const s_out_precomputed_104 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_104);
	mk_lang_constexpr_static auto const s_out_precomputed_105 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_105);
	mk_lang_constexpr_static auto const s_out_precomputed_106 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_106);
	mk_lang_constexpr_static auto const s_out_precomputed_107 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_107);
	mk_lang_constexpr_static auto const s_out_precomputed_108 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_108);
	mk_lang_constexpr_static auto const s_out_precomputed_109 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_109);
	mk_lang_constexpr_static auto const s_out_precomputed_110 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_110);
	mk_lang_constexpr_static auto const s_out_precomputed_111 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_111);
	mk_lang_constexpr_static auto const s_out_precomputed_112 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_112);
	mk_lang_constexpr_static auto const s_out_precomputed_113 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_113);
	mk_lang_constexpr_static auto const s_out_precomputed_114 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_114);
	mk_lang_constexpr_static auto const s_out_precomputed_115 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_115);
	mk_lang_constexpr_static auto const s_out_precomputed_116 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_116);
	mk_lang_constexpr_static auto const s_out_precomputed_117 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_117);
	mk_lang_constexpr_static auto const s_out_precomputed_118 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_118);
	mk_lang_constexpr_static auto const s_out_precomputed_119 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_119);
	mk_lang_constexpr_static auto const s_out_precomputed_120 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_120);
	mk_lang_constexpr_static auto const s_out_precomputed_121 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_121);
	mk_lang_constexpr_static auto const s_out_precomputed_122 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_122);
	mk_lang_constexpr_static auto const s_out_precomputed_123 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_123);
	mk_lang_constexpr_static auto const s_out_precomputed_124 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_124);
	mk_lang_constexpr_static auto const s_out_precomputed_125 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_125);
	mk_lang_constexpr_static auto const s_out_precomputed_126 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_126);
	mk_lang_constexpr_static auto const s_out_precomputed_127 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_127);
	mk_lang_constexpr_static auto const s_out_precomputed_128 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_128);
	mk_lang_constexpr_static auto const s_out_precomputed_129 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_129);
	mk_lang_constexpr_static auto const s_out_precomputed_130 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_130);
	mk_lang_constexpr_static auto const s_out_precomputed_131 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_131);
	mk_lang_constexpr_static auto const s_out_precomputed_132 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_132);
	mk_lang_constexpr_static auto const s_out_precomputed_133 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_133);
	mk_lang_constexpr_static auto const s_out_precomputed_134 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_134);
	mk_lang_constexpr_static auto const s_out_precomputed_135 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_135);
	mk_lang_constexpr_static auto const s_out_precomputed_136 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_136);
	mk_lang_constexpr_static auto const s_out_precomputed_137 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_137);
	mk_lang_constexpr_static auto const s_out_precomputed_138 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_138);
	mk_lang_constexpr_static auto const s_out_precomputed_139 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_139);
	mk_lang_constexpr_static auto const s_out_precomputed_140 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_140);
	mk_lang_constexpr_static auto const s_out_precomputed_141 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_141);
	mk_lang_constexpr_static auto const s_out_precomputed_142 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_142);
	mk_lang_constexpr_static auto const s_out_precomputed_143 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_143);
	mk_lang_constexpr_static auto const s_out_precomputed_144 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_144);
	mk_lang_constexpr_static auto const s_out_precomputed_145 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_145);
	mk_lang_constexpr_static auto const s_out_precomputed_146 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_146);
	mk_lang_constexpr_static auto const s_out_precomputed_147 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_147);
	mk_lang_constexpr_static auto const s_out_precomputed_148 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_148);
	mk_lang_constexpr_static auto const s_out_precomputed_149 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_149);
	mk_lang_constexpr_static auto const s_out_precomputed_150 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_150);
	mk_lang_constexpr_static auto const s_out_precomputed_151 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_151);
	mk_lang_constexpr_static auto const s_out_precomputed_152 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_152);
	mk_lang_constexpr_static auto const s_out_precomputed_153 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_153);
	mk_lang_constexpr_static auto const s_out_precomputed_154 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_154);
	mk_lang_constexpr_static auto const s_out_precomputed_155 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_155);
	mk_lang_constexpr_static auto const s_out_precomputed_156 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_156);
	mk_lang_constexpr_static auto const s_out_precomputed_157 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_157);
	mk_lang_constexpr_static auto const s_out_precomputed_158 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_158);
	mk_lang_constexpr_static auto const s_out_precomputed_159 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_159);
	mk_lang_constexpr_static auto const s_out_precomputed_160 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_160);
	mk_lang_constexpr_static auto const s_out_precomputed_161 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_161);
	mk_lang_constexpr_static auto const s_out_precomputed_162 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_162);
	mk_lang_constexpr_static auto const s_out_precomputed_163 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_163);
	mk_lang_constexpr_static auto const s_out_precomputed_164 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_164);
	mk_lang_constexpr_static auto const s_out_precomputed_165 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_165);
	mk_lang_constexpr_static auto const s_out_precomputed_166 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_166);
	mk_lang_constexpr_static auto const s_out_precomputed_167 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_167);
	mk_lang_constexpr_static auto const s_out_precomputed_168 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_168);
	mk_lang_constexpr_static auto const s_out_precomputed_169 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_169);
	mk_lang_constexpr_static auto const s_out_precomputed_170 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_170);
	mk_lang_constexpr_static auto const s_out_precomputed_171 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_171);
	mk_lang_constexpr_static auto const s_out_precomputed_172 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_172);
	mk_lang_constexpr_static auto const s_out_precomputed_173 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_173);
	mk_lang_constexpr_static auto const s_out_precomputed_174 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_174);
	mk_lang_constexpr_static auto const s_out_precomputed_175 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_175);
	mk_lang_constexpr_static auto const s_out_precomputed_176 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_176);
	mk_lang_constexpr_static auto const s_out_precomputed_177 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_177);
	mk_lang_constexpr_static auto const s_out_precomputed_178 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_178);
	mk_lang_constexpr_static auto const s_out_precomputed_179 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_179);
	mk_lang_constexpr_static auto const s_out_precomputed_180 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_180);
	mk_lang_constexpr_static auto const s_out_precomputed_181 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_181);
	mk_lang_constexpr_static auto const s_out_precomputed_182 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_182);
	mk_lang_constexpr_static auto const s_out_precomputed_183 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_183);
	mk_lang_constexpr_static auto const s_out_precomputed_184 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_184);
	mk_lang_constexpr_static auto const s_out_precomputed_185 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_185);
	mk_lang_constexpr_static auto const s_out_precomputed_186 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_186);
	mk_lang_constexpr_static auto const s_out_precomputed_187 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_187);
	mk_lang_constexpr_static auto const s_out_precomputed_188 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_188);
	mk_lang_constexpr_static auto const s_out_precomputed_189 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_189);
	mk_lang_constexpr_static auto const s_out_precomputed_190 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_190);
	mk_lang_constexpr_static auto const s_out_precomputed_191 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_191);
	mk_lang_constexpr_static auto const s_out_precomputed_192 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_192);
	mk_lang_constexpr_static auto const s_out_precomputed_193 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_193);
	mk_lang_constexpr_static auto const s_out_precomputed_194 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_194);
	mk_lang_constexpr_static auto const s_out_precomputed_195 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_195);
	mk_lang_constexpr_static auto const s_out_precomputed_196 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_196);
	mk_lang_constexpr_static auto const s_out_precomputed_197 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_197);
	mk_lang_constexpr_static auto const s_out_precomputed_198 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_198);
	mk_lang_constexpr_static auto const s_out_precomputed_199 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_199);
	mk_lang_constexpr_static auto const s_out_precomputed_200 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_200);
	mk_lang_constexpr_static auto const s_out_precomputed_201 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_201);
	mk_lang_constexpr_static auto const s_out_precomputed_202 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_202);
	mk_lang_constexpr_static auto const s_out_precomputed_203 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_203);
	mk_lang_constexpr_static auto const s_out_precomputed_204 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_204);
	mk_lang_constexpr_static auto const s_out_precomputed_205 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_205);
	mk_lang_constexpr_static auto const s_out_precomputed_206 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_206);
	mk_lang_constexpr_static auto const s_out_precomputed_207 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_207);
	mk_lang_constexpr_static auto const s_out_precomputed_208 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_208);
	mk_lang_constexpr_static auto const s_out_precomputed_209 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_209);
	mk_lang_constexpr_static auto const s_out_precomputed_210 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_210);
	mk_lang_constexpr_static auto const s_out_precomputed_211 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_211);
	mk_lang_constexpr_static auto const s_out_precomputed_212 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_212);
	mk_lang_constexpr_static auto const s_out_precomputed_213 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_213);
	mk_lang_constexpr_static auto const s_out_precomputed_214 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_214);
	mk_lang_constexpr_static auto const s_out_precomputed_215 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_215);
	mk_lang_constexpr_static auto const s_out_precomputed_216 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_216);
	mk_lang_constexpr_static auto const s_out_precomputed_217 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_217);
	mk_lang_constexpr_static auto const s_out_precomputed_218 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_218);
	mk_lang_constexpr_static auto const s_out_precomputed_219 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_219);
	mk_lang_constexpr_static auto const s_out_precomputed_220 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_220);
	mk_lang_constexpr_static auto const s_out_precomputed_221 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_221);
	mk_lang_constexpr_static auto const s_out_precomputed_222 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_222);
	mk_lang_constexpr_static auto const s_out_precomputed_223 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_223);
	mk_lang_constexpr_static auto const s_out_precomputed_224 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_224);
	mk_lang_constexpr_static auto const s_out_precomputed_225 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_225);
	mk_lang_constexpr_static auto const s_out_precomputed_226 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_226);
	mk_lang_constexpr_static auto const s_out_precomputed_227 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_227);
	mk_lang_constexpr_static auto const s_out_precomputed_228 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_228);
	mk_lang_constexpr_static auto const s_out_precomputed_229 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_229);
	mk_lang_constexpr_static auto const s_out_precomputed_230 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_230);
	mk_lang_constexpr_static auto const s_out_precomputed_231 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_231);
	mk_lang_constexpr_static auto const s_out_precomputed_232 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_232);
	mk_lang_constexpr_static auto const s_out_precomputed_233 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_233);
	mk_lang_constexpr_static auto const s_out_precomputed_234 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_234);
	mk_lang_constexpr_static auto const s_out_precomputed_235 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_235);
	mk_lang_constexpr_static auto const s_out_precomputed_236 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_236);
	mk_lang_constexpr_static auto const s_out_precomputed_237 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_237);
	mk_lang_constexpr_static auto const s_out_precomputed_238 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_238);
	mk_lang_constexpr_static auto const s_out_precomputed_239 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_239);
	mk_lang_constexpr_static auto const s_out_precomputed_240 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_240);
	mk_lang_constexpr_static auto const s_out_precomputed_241 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_241);
	mk_lang_constexpr_static auto const s_out_precomputed_242 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_242);
	mk_lang_constexpr_static auto const s_out_precomputed_243 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_243);
	mk_lang_constexpr_static auto const s_out_precomputed_244 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_244);
	mk_lang_constexpr_static auto const s_out_precomputed_245 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_245);
	mk_lang_constexpr_static auto const s_out_precomputed_246 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_246);
	mk_lang_constexpr_static auto const s_out_precomputed_247 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_247);
	mk_lang_constexpr_static auto const s_out_precomputed_248 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_248);
	mk_lang_constexpr_static auto const s_out_precomputed_249 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_249);
	mk_lang_constexpr_static auto const s_out_precomputed_250 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_250);
	mk_lang_constexpr_static auto const s_out_precomputed_251 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_251);
	mk_lang_constexpr_static auto const s_out_precomputed_252 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_252);
	mk_lang_constexpr_static auto const s_out_precomputed_253 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_253);
	mk_lang_constexpr_static auto const s_out_precomputed_254 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_254);
	mk_lang_constexpr_static auto const s_out_precomputed_255 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_255);
	mk_lang_constexpr_static auto const s_out_precomputed_256 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_256);
	mk_lang_constexpr_static auto const s_out_precomputed_257 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_257);
	mk_lang_constexpr_static auto const s_out_precomputed_258 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_258);
	mk_lang_constexpr_static auto const s_out_precomputed_259 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_259);
	mk_lang_constexpr_static auto const s_out_precomputed_260 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_260);
	mk_lang_constexpr_static auto const s_out_precomputed_261 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_261);
	mk_lang_constexpr_static auto const s_out_precomputed_262 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_262);
	mk_lang_constexpr_static auto const s_out_precomputed_263 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_263);
	mk_lang_constexpr_static auto const s_out_precomputed_264 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_264);
	mk_lang_constexpr_static auto const s_out_precomputed_265 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_265);
	mk_lang_constexpr_static auto const s_out_precomputed_266 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_266);
	mk_lang_constexpr_static auto const s_out_precomputed_267 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_267);
	mk_lang_constexpr_static auto const s_out_precomputed_268 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_268);
	mk_lang_constexpr_static auto const s_out_precomputed_269 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_269);

	mk_lang_constexpr_static auto const s_msg_precomputed_000 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_000);
	mk_lang_constexpr_static auto const s_msg_precomputed_001 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_001);
	mk_lang_constexpr_static auto const s_msg_precomputed_002 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_002);
	mk_lang_constexpr_static auto const s_msg_precomputed_003 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_003);
	mk_lang_constexpr_static auto const s_msg_precomputed_004 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_004);
	mk_lang_constexpr_static auto const s_msg_precomputed_005 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_005);
	mk_lang_constexpr_static auto const s_msg_precomputed_006 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_006);
	mk_lang_constexpr_static auto const s_msg_precomputed_007 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_007);
	mk_lang_constexpr_static auto const s_msg_precomputed_008 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_008);
	mk_lang_constexpr_static auto const s_msg_precomputed_009 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_009);
	mk_lang_constexpr_static auto const s_msg_precomputed_010 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_010);
	mk_lang_constexpr_static auto const s_msg_precomputed_011 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_011);
	mk_lang_constexpr_static auto const s_msg_precomputed_012 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_012);
	mk_lang_constexpr_static auto const s_msg_precomputed_013 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_013);
	mk_lang_constexpr_static auto const s_msg_precomputed_014 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_014);
	mk_lang_constexpr_static auto const s_msg_precomputed_015 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_015);
	mk_lang_constexpr_static auto const s_msg_precomputed_016 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_016);
	mk_lang_constexpr_static auto const s_msg_precomputed_017 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_017);
	mk_lang_constexpr_static auto const s_msg_precomputed_018 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_018);
	mk_lang_constexpr_static auto const s_msg_precomputed_019 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_019);
	mk_lang_constexpr_static auto const s_msg_precomputed_020 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_020);
	mk_lang_constexpr_static auto const s_msg_precomputed_021 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_021);
	mk_lang_constexpr_static auto const s_msg_precomputed_022 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_022);
	mk_lang_constexpr_static auto const s_msg_precomputed_023 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_023);
	mk_lang_constexpr_static auto const s_msg_precomputed_024 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_024);
	mk_lang_constexpr_static auto const s_msg_precomputed_025 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_025);
	mk_lang_constexpr_static auto const s_msg_precomputed_026 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_026);
	mk_lang_constexpr_static auto const s_msg_precomputed_027 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_027);
	mk_lang_constexpr_static auto const s_msg_precomputed_028 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_028);
	mk_lang_constexpr_static auto const s_msg_precomputed_029 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_029);
	mk_lang_constexpr_static auto const s_msg_precomputed_030 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_030);
	mk_lang_constexpr_static auto const s_msg_precomputed_031 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_031);
	mk_lang_constexpr_static auto const s_msg_precomputed_032 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_032);
	mk_lang_constexpr_static auto const s_msg_precomputed_033 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_033);
	mk_lang_constexpr_static auto const s_msg_precomputed_034 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_034);
	mk_lang_constexpr_static auto const s_msg_precomputed_035 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_035);
	mk_lang_constexpr_static auto const s_msg_precomputed_036 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_036);
	mk_lang_constexpr_static auto const s_msg_precomputed_037 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_037);
	mk_lang_constexpr_static auto const s_msg_precomputed_038 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_038);
	mk_lang_constexpr_static auto const s_msg_precomputed_039 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_039);
	mk_lang_constexpr_static auto const s_msg_precomputed_040 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_040);
	mk_lang_constexpr_static auto const s_msg_precomputed_041 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_041);
	mk_lang_constexpr_static auto const s_msg_precomputed_042 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_042);
	mk_lang_constexpr_static auto const s_msg_precomputed_043 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_043);
	mk_lang_constexpr_static auto const s_msg_precomputed_044 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_044);
	mk_lang_constexpr_static auto const s_msg_precomputed_045 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_045);
	mk_lang_constexpr_static auto const s_msg_precomputed_046 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_046);
	mk_lang_constexpr_static auto const s_msg_precomputed_047 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_047);
	mk_lang_constexpr_static auto const s_msg_precomputed_048 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_048);
	mk_lang_constexpr_static auto const s_msg_precomputed_049 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_049);
	mk_lang_constexpr_static auto const s_msg_precomputed_050 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_050);
	mk_lang_constexpr_static auto const s_msg_precomputed_051 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_051);
	mk_lang_constexpr_static auto const s_msg_precomputed_052 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_052);
	mk_lang_constexpr_static auto const s_msg_precomputed_053 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_053);
	mk_lang_constexpr_static auto const s_msg_precomputed_054 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_054);
	mk_lang_constexpr_static auto const s_msg_precomputed_055 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_055);
	mk_lang_constexpr_static auto const s_msg_precomputed_056 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_056);
	mk_lang_constexpr_static auto const s_msg_precomputed_057 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_057);
	mk_lang_constexpr_static auto const s_msg_precomputed_058 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_058);
	mk_lang_constexpr_static auto const s_msg_precomputed_059 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_059);
	mk_lang_constexpr_static auto const s_msg_precomputed_060 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_060);
	mk_lang_constexpr_static auto const s_msg_precomputed_061 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_061);
	mk_lang_constexpr_static auto const s_msg_precomputed_062 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_062);
	mk_lang_constexpr_static auto const s_msg_precomputed_063 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_063);
	mk_lang_constexpr_static auto const s_msg_precomputed_064 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_064);
	mk_lang_constexpr_static auto const s_msg_precomputed_065 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_065);
	mk_lang_constexpr_static auto const s_msg_precomputed_066 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_066);
	mk_lang_constexpr_static auto const s_msg_precomputed_067 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_067);
	mk_lang_constexpr_static auto const s_msg_precomputed_068 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_068);
	mk_lang_constexpr_static auto const s_msg_precomputed_069 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_069);
	mk_lang_constexpr_static auto const s_msg_precomputed_070 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_070);
	mk_lang_constexpr_static auto const s_msg_precomputed_071 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_071);
	mk_lang_constexpr_static auto const s_msg_precomputed_072 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_072);
	mk_lang_constexpr_static auto const s_msg_precomputed_073 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_073);
	mk_lang_constexpr_static auto const s_msg_precomputed_074 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_074);
	mk_lang_constexpr_static auto const s_msg_precomputed_075 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_075);
	mk_lang_constexpr_static auto const s_msg_precomputed_076 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_076);
	mk_lang_constexpr_static auto const s_msg_precomputed_077 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_077);
	mk_lang_constexpr_static auto const s_msg_precomputed_078 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_078);
	mk_lang_constexpr_static auto const s_msg_precomputed_079 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_079);
	mk_lang_constexpr_static auto const s_msg_precomputed_080 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_080);
	mk_lang_constexpr_static auto const s_msg_precomputed_081 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_081);
	mk_lang_constexpr_static auto const s_msg_precomputed_082 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_082);
	mk_lang_constexpr_static auto const s_msg_precomputed_083 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_083);
	mk_lang_constexpr_static auto const s_msg_precomputed_084 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_084);
	mk_lang_constexpr_static auto const s_msg_precomputed_085 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_085);
	mk_lang_constexpr_static auto const s_msg_precomputed_086 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_086);
	mk_lang_constexpr_static auto const s_msg_precomputed_087 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_087);
	mk_lang_constexpr_static auto const s_msg_precomputed_088 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_088);
	mk_lang_constexpr_static auto const s_msg_precomputed_089 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_089);
	mk_lang_constexpr_static auto const s_msg_precomputed_090 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_090);
	mk_lang_constexpr_static auto const s_msg_precomputed_091 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_091);
	mk_lang_constexpr_static auto const s_msg_precomputed_092 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_092);
	mk_lang_constexpr_static auto const s_msg_precomputed_093 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_093);
	mk_lang_constexpr_static auto const s_msg_precomputed_094 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_094);
	mk_lang_constexpr_static auto const s_msg_precomputed_095 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_095);
	mk_lang_constexpr_static auto const s_msg_precomputed_096 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_096);
	mk_lang_constexpr_static auto const s_msg_precomputed_097 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_097);
	mk_lang_constexpr_static auto const s_msg_precomputed_098 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_098);
	mk_lang_constexpr_static auto const s_msg_precomputed_099 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_099);
	mk_lang_constexpr_static auto const s_msg_precomputed_100 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_100);
	mk_lang_constexpr_static auto const s_msg_precomputed_101 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_101);
	mk_lang_constexpr_static auto const s_msg_precomputed_102 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_102);
	mk_lang_constexpr_static auto const s_msg_precomputed_103 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_103);
	mk_lang_constexpr_static auto const s_msg_precomputed_104 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_104);
	mk_lang_constexpr_static auto const s_msg_precomputed_105 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_105);
	mk_lang_constexpr_static auto const s_msg_precomputed_106 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_106);
	mk_lang_constexpr_static auto const s_msg_precomputed_107 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_107);
	mk_lang_constexpr_static auto const s_msg_precomputed_108 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_108);
	mk_lang_constexpr_static auto const s_msg_precomputed_109 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_109);
	mk_lang_constexpr_static auto const s_msg_precomputed_110 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_110);
	mk_lang_constexpr_static auto const s_msg_precomputed_111 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_111);
	mk_lang_constexpr_static auto const s_msg_precomputed_112 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_112);
	mk_lang_constexpr_static auto const s_msg_precomputed_113 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_113);
	mk_lang_constexpr_static auto const s_msg_precomputed_114 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_114);
	mk_lang_constexpr_static auto const s_msg_precomputed_115 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_115);
	mk_lang_constexpr_static auto const s_msg_precomputed_116 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_116);
	mk_lang_constexpr_static auto const s_msg_precomputed_117 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_117);
	mk_lang_constexpr_static auto const s_msg_precomputed_118 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_118);
	mk_lang_constexpr_static auto const s_msg_precomputed_119 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_119);
	mk_lang_constexpr_static auto const s_msg_precomputed_120 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_120);
	mk_lang_constexpr_static auto const s_msg_precomputed_121 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_121);
	mk_lang_constexpr_static auto const s_msg_precomputed_122 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_122);
	mk_lang_constexpr_static auto const s_msg_precomputed_123 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_123);
	mk_lang_constexpr_static auto const s_msg_precomputed_124 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_124);
	mk_lang_constexpr_static auto const s_msg_precomputed_125 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_125);
	mk_lang_constexpr_static auto const s_msg_precomputed_126 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_126);
	mk_lang_constexpr_static auto const s_msg_precomputed_127 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_127);
	mk_lang_constexpr_static auto const s_msg_precomputed_128 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_128);
	mk_lang_constexpr_static auto const s_msg_precomputed_129 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_129);
	mk_lang_constexpr_static auto const s_msg_precomputed_130 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_130);
	mk_lang_constexpr_static auto const s_msg_precomputed_131 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_131);
	mk_lang_constexpr_static auto const s_msg_precomputed_132 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_132);
	mk_lang_constexpr_static auto const s_msg_precomputed_133 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_133);
	mk_lang_constexpr_static auto const s_msg_precomputed_134 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_134);
	mk_lang_constexpr_static auto const s_msg_precomputed_135 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_135);
	mk_lang_constexpr_static auto const s_msg_precomputed_136 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_136);
	mk_lang_constexpr_static auto const s_msg_precomputed_137 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_137);
	mk_lang_constexpr_static auto const s_msg_precomputed_138 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_138);
	mk_lang_constexpr_static auto const s_msg_precomputed_139 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_139);
	mk_lang_constexpr_static auto const s_msg_precomputed_140 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_140);
	mk_lang_constexpr_static auto const s_msg_precomputed_141 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_141);
	mk_lang_constexpr_static auto const s_msg_precomputed_142 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_142);
	mk_lang_constexpr_static auto const s_msg_precomputed_143 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_143);
	mk_lang_constexpr_static auto const s_msg_precomputed_144 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_144);
	mk_lang_constexpr_static auto const s_msg_precomputed_145 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_145);
	mk_lang_constexpr_static auto const s_msg_precomputed_146 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_146);
	mk_lang_constexpr_static auto const s_msg_precomputed_147 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_147);
	mk_lang_constexpr_static auto const s_msg_precomputed_148 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_148);
	mk_lang_constexpr_static auto const s_msg_precomputed_149 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_149);
	mk_lang_constexpr_static auto const s_msg_precomputed_150 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_150);
	mk_lang_constexpr_static auto const s_msg_precomputed_151 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_151);
	mk_lang_constexpr_static auto const s_msg_precomputed_152 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_152);
	mk_lang_constexpr_static auto const s_msg_precomputed_153 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_153);
	mk_lang_constexpr_static auto const s_msg_precomputed_154 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_154);
	mk_lang_constexpr_static auto const s_msg_precomputed_155 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_155);
	mk_lang_constexpr_static auto const s_msg_precomputed_156 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_156);
	mk_lang_constexpr_static auto const s_msg_precomputed_157 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_157);
	mk_lang_constexpr_static auto const s_msg_precomputed_158 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_158);
	mk_lang_constexpr_static auto const s_msg_precomputed_159 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_159);
	mk_lang_constexpr_static auto const s_msg_precomputed_160 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_160);
	mk_lang_constexpr_static auto const s_msg_precomputed_161 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_161);
	mk_lang_constexpr_static auto const s_msg_precomputed_162 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_162);
	mk_lang_constexpr_static auto const s_msg_precomputed_163 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_163);
	mk_lang_constexpr_static auto const s_msg_precomputed_164 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_164);
	mk_lang_constexpr_static auto const s_msg_precomputed_165 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_165);
	mk_lang_constexpr_static auto const s_msg_precomputed_166 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_166);
	mk_lang_constexpr_static auto const s_msg_precomputed_167 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_167);
	mk_lang_constexpr_static auto const s_msg_precomputed_168 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_168);
	mk_lang_constexpr_static auto const s_msg_precomputed_169 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_169);
	mk_lang_constexpr_static auto const s_msg_precomputed_170 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_170);
	mk_lang_constexpr_static auto const s_msg_precomputed_171 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_171);
	mk_lang_constexpr_static auto const s_msg_precomputed_172 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_172);
	mk_lang_constexpr_static auto const s_msg_precomputed_173 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_173);
	mk_lang_constexpr_static auto const s_msg_precomputed_174 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_174);
	mk_lang_constexpr_static auto const s_msg_precomputed_175 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_175);
	mk_lang_constexpr_static auto const s_msg_precomputed_176 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_176);
	mk_lang_constexpr_static auto const s_msg_precomputed_177 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_177);
	mk_lang_constexpr_static auto const s_msg_precomputed_178 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_178);
	mk_lang_constexpr_static auto const s_msg_precomputed_179 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_179);
	mk_lang_constexpr_static auto const s_msg_precomputed_180 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_180);
	mk_lang_constexpr_static auto const s_msg_precomputed_181 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_181);
	mk_lang_constexpr_static auto const s_msg_precomputed_182 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_182);
	mk_lang_constexpr_static auto const s_msg_precomputed_183 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_183);
	mk_lang_constexpr_static auto const s_msg_precomputed_184 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_184);
	mk_lang_constexpr_static auto const s_msg_precomputed_185 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_185);
	mk_lang_constexpr_static auto const s_msg_precomputed_186 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_186);
	mk_lang_constexpr_static auto const s_msg_precomputed_187 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_187);
	mk_lang_constexpr_static auto const s_msg_precomputed_188 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_188);
	mk_lang_constexpr_static auto const s_msg_precomputed_189 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_189);
	mk_lang_constexpr_static auto const s_msg_precomputed_190 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_190);
	mk_lang_constexpr_static auto const s_msg_precomputed_191 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_191);
	mk_lang_constexpr_static auto const s_msg_precomputed_192 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_192);
	mk_lang_constexpr_static auto const s_msg_precomputed_193 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_193);
	mk_lang_constexpr_static auto const s_msg_precomputed_194 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_194);
	mk_lang_constexpr_static auto const s_msg_precomputed_195 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_195);
	mk_lang_constexpr_static auto const s_msg_precomputed_196 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_196);
	mk_lang_constexpr_static auto const s_msg_precomputed_197 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_197);
	mk_lang_constexpr_static auto const s_msg_precomputed_198 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_198);
	mk_lang_constexpr_static auto const s_msg_precomputed_199 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_199);
	mk_lang_constexpr_static auto const s_msg_precomputed_200 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_200);
	mk_lang_constexpr_static auto const s_msg_precomputed_201 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_201);
	mk_lang_constexpr_static auto const s_msg_precomputed_202 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_202);
	mk_lang_constexpr_static auto const s_msg_precomputed_203 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_203);
	mk_lang_constexpr_static auto const s_msg_precomputed_204 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_204);
	mk_lang_constexpr_static auto const s_msg_precomputed_205 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_205);
	mk_lang_constexpr_static auto const s_msg_precomputed_206 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_206);
	mk_lang_constexpr_static auto const s_msg_precomputed_207 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_207);
	mk_lang_constexpr_static auto const s_msg_precomputed_208 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_208);
	mk_lang_constexpr_static auto const s_msg_precomputed_209 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_209);
	mk_lang_constexpr_static auto const s_msg_precomputed_210 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_210);
	mk_lang_constexpr_static auto const s_msg_precomputed_211 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_211);
	mk_lang_constexpr_static auto const s_msg_precomputed_212 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_212);
	mk_lang_constexpr_static auto const s_msg_precomputed_213 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_213);
	mk_lang_constexpr_static auto const s_msg_precomputed_214 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_214);
	mk_lang_constexpr_static auto const s_msg_precomputed_215 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_215);
	mk_lang_constexpr_static auto const s_msg_precomputed_216 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_216);
	mk_lang_constexpr_static auto const s_msg_precomputed_217 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_217);
	mk_lang_constexpr_static auto const s_msg_precomputed_218 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_218);
	mk_lang_constexpr_static auto const s_msg_precomputed_219 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_219);
	mk_lang_constexpr_static auto const s_msg_precomputed_220 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_220);
	mk_lang_constexpr_static auto const s_msg_precomputed_221 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_221);
	mk_lang_constexpr_static auto const s_msg_precomputed_222 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_222);
	mk_lang_constexpr_static auto const s_msg_precomputed_223 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_223);
	mk_lang_constexpr_static auto const s_msg_precomputed_224 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_224);
	mk_lang_constexpr_static auto const s_msg_precomputed_225 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_225);
	mk_lang_constexpr_static auto const s_msg_precomputed_226 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_226);
	mk_lang_constexpr_static auto const s_msg_precomputed_227 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_227);
	mk_lang_constexpr_static auto const s_msg_precomputed_228 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_228);
	mk_lang_constexpr_static auto const s_msg_precomputed_229 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_229);
	mk_lang_constexpr_static auto const s_msg_precomputed_230 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_230);
	mk_lang_constexpr_static auto const s_msg_precomputed_231 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_231);
	mk_lang_constexpr_static auto const s_msg_precomputed_232 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_232);
	mk_lang_constexpr_static auto const s_msg_precomputed_233 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_233);
	mk_lang_constexpr_static auto const s_msg_precomputed_234 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_234);
	mk_lang_constexpr_static auto const s_msg_precomputed_235 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_235);
	mk_lang_constexpr_static auto const s_msg_precomputed_236 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_236);
	mk_lang_constexpr_static auto const s_msg_precomputed_237 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_237);
	mk_lang_constexpr_static auto const s_msg_precomputed_238 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_238);
	mk_lang_constexpr_static auto const s_msg_precomputed_239 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_239);
	mk_lang_constexpr_static auto const s_msg_precomputed_240 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_240);
	mk_lang_constexpr_static auto const s_msg_precomputed_241 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_241);
	mk_lang_constexpr_static auto const s_msg_precomputed_242 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_242);
	mk_lang_constexpr_static auto const s_msg_precomputed_243 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_243);
	mk_lang_constexpr_static auto const s_msg_precomputed_244 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_244);
	mk_lang_constexpr_static auto const s_msg_precomputed_245 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_245);
	mk_lang_constexpr_static auto const s_msg_precomputed_246 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_246);
	mk_lang_constexpr_static auto const s_msg_precomputed_247 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_247);
	mk_lang_constexpr_static auto const s_msg_precomputed_248 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_248);
	mk_lang_constexpr_static auto const s_msg_precomputed_249 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_249);
	mk_lang_constexpr_static auto const s_msg_precomputed_250 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_250);
	mk_lang_constexpr_static auto const s_msg_precomputed_251 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_251);
	mk_lang_constexpr_static auto const s_msg_precomputed_252 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_252);
	mk_lang_constexpr_static auto const s_msg_precomputed_253 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_253);
	mk_lang_constexpr_static auto const s_msg_precomputed_254 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_254);
	mk_lang_constexpr_static auto const s_msg_precomputed_255 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_255);
	mk_lang_constexpr_static auto const s_msg_precomputed_256 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_256);
	mk_lang_constexpr_static auto const s_msg_precomputed_257 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_257);
	mk_lang_constexpr_static auto const s_msg_precomputed_258 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_258);
	mk_lang_constexpr_static auto const s_msg_precomputed_259 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_259);
	mk_lang_constexpr_static auto const s_msg_precomputed_260 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_260);
	mk_lang_constexpr_static auto const s_msg_precomputed_261 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_261);
	mk_lang_constexpr_static auto const s_msg_precomputed_262 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_262);
	mk_lang_constexpr_static auto const s_msg_precomputed_263 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_263);
	mk_lang_constexpr_static auto const s_msg_precomputed_264 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_264);
	mk_lang_constexpr_static auto const s_msg_precomputed_265 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_265);
	mk_lang_constexpr_static auto const s_msg_precomputed_266 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_266);
	mk_lang_constexpr_static auto const s_msg_precomputed_267 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_267);
	mk_lang_constexpr_static auto const s_msg_precomputed_268 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_268);
	mk_lang_constexpr_static auto const s_msg_precomputed_269 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_269);

	mk_lang_static_assert(s_out_computed_000 == s_out_precomputed_000);
	mk_lang_static_assert(s_out_computed_001 == s_out_precomputed_001);
	mk_lang_static_assert(s_out_computed_002 == s_out_precomputed_002);
	mk_lang_static_assert(s_out_computed_003 == s_out_precomputed_003);
	mk_lang_static_assert(s_out_computed_004 == s_out_precomputed_004);
	mk_lang_static_assert(s_out_computed_005 == s_out_precomputed_005);
	mk_lang_static_assert(s_out_computed_006 == s_out_precomputed_006);
	mk_lang_static_assert(s_out_computed_007 == s_out_precomputed_007);
	mk_lang_static_assert(s_out_computed_008 == s_out_precomputed_008);
	mk_lang_static_assert(s_out_computed_009 == s_out_precomputed_009);
	mk_lang_static_assert(s_out_computed_010 == s_out_precomputed_010);
	mk_lang_static_assert(s_out_computed_011 == s_out_precomputed_011);
	mk_lang_static_assert(s_out_computed_012 == s_out_precomputed_012);
	mk_lang_static_assert(s_out_computed_013 == s_out_precomputed_013);
	mk_lang_static_assert(s_out_computed_014 == s_out_precomputed_014);
	mk_lang_static_assert(s_out_computed_015 == s_out_precomputed_015);
	mk_lang_static_assert(s_out_computed_016 == s_out_precomputed_016);
	mk_lang_static_assert(s_out_computed_017 == s_out_precomputed_017);
	mk_lang_static_assert(s_out_computed_018 == s_out_precomputed_018);
	mk_lang_static_assert(s_out_computed_019 == s_out_precomputed_019);
	mk_lang_static_assert(s_out_computed_020 == s_out_precomputed_020);
	mk_lang_static_assert(s_out_computed_021 == s_out_precomputed_021);
	mk_lang_static_assert(s_out_computed_022 == s_out_precomputed_022);
	mk_lang_static_assert(s_out_computed_023 == s_out_precomputed_023);
	mk_lang_static_assert(s_out_computed_024 == s_out_precomputed_024);
	mk_lang_static_assert(s_out_computed_025 == s_out_precomputed_025);
	mk_lang_static_assert(s_out_computed_026 == s_out_precomputed_026);
	mk_lang_static_assert(s_out_computed_027 == s_out_precomputed_027);
	mk_lang_static_assert(s_out_computed_028 == s_out_precomputed_028);
	mk_lang_static_assert(s_out_computed_029 == s_out_precomputed_029);
	mk_lang_static_assert(s_out_computed_030 == s_out_precomputed_030);
	mk_lang_static_assert(s_out_computed_031 == s_out_precomputed_031);
	mk_lang_static_assert(s_out_computed_032 == s_out_precomputed_032);
	mk_lang_static_assert(s_out_computed_033 == s_out_precomputed_033);
	mk_lang_static_assert(s_out_computed_034 == s_out_precomputed_034);
	mk_lang_static_assert(s_out_computed_035 == s_out_precomputed_035);
	mk_lang_static_assert(s_out_computed_036 == s_out_precomputed_036);
	mk_lang_static_assert(s_out_computed_037 == s_out_precomputed_037);
	mk_lang_static_assert(s_out_computed_038 == s_out_precomputed_038);
	mk_lang_static_assert(s_out_computed_039 == s_out_precomputed_039);
	mk_lang_static_assert(s_out_computed_040 == s_out_precomputed_040);
	mk_lang_static_assert(s_out_computed_041 == s_out_precomputed_041);
	mk_lang_static_assert(s_out_computed_042 == s_out_precomputed_042);
	mk_lang_static_assert(s_out_computed_043 == s_out_precomputed_043);
	mk_lang_static_assert(s_out_computed_044 == s_out_precomputed_044);
	mk_lang_static_assert(s_out_computed_045 == s_out_precomputed_045);
	mk_lang_static_assert(s_out_computed_046 == s_out_precomputed_046);
	mk_lang_static_assert(s_out_computed_047 == s_out_precomputed_047);
	mk_lang_static_assert(s_out_computed_048 == s_out_precomputed_048);
	mk_lang_static_assert(s_out_computed_049 == s_out_precomputed_049);
	mk_lang_static_assert(s_out_computed_050 == s_out_precomputed_050);
	mk_lang_static_assert(s_out_computed_051 == s_out_precomputed_051);
	mk_lang_static_assert(s_out_computed_052 == s_out_precomputed_052);
	mk_lang_static_assert(s_out_computed_053 == s_out_precomputed_053);
	mk_lang_static_assert(s_out_computed_054 == s_out_precomputed_054);
	mk_lang_static_assert(s_out_computed_055 == s_out_precomputed_055);
	mk_lang_static_assert(s_out_computed_056 == s_out_precomputed_056);
	mk_lang_static_assert(s_out_computed_057 == s_out_precomputed_057);
	mk_lang_static_assert(s_out_computed_058 == s_out_precomputed_058);
	mk_lang_static_assert(s_out_computed_059 == s_out_precomputed_059);
	mk_lang_static_assert(s_out_computed_060 == s_out_precomputed_060);
	mk_lang_static_assert(s_out_computed_061 == s_out_precomputed_061);
	mk_lang_static_assert(s_out_computed_062 == s_out_precomputed_062);
	mk_lang_static_assert(s_out_computed_063 == s_out_precomputed_063);
	mk_lang_static_assert(s_out_computed_064 == s_out_precomputed_064);
	mk_lang_static_assert(s_out_computed_065 == s_out_precomputed_065);
	mk_lang_static_assert(s_out_computed_066 == s_out_precomputed_066);
	mk_lang_static_assert(s_out_computed_067 == s_out_precomputed_067);
	mk_lang_static_assert(s_out_computed_068 == s_out_precomputed_068);
	mk_lang_static_assert(s_out_computed_069 == s_out_precomputed_069);
	mk_lang_static_assert(s_out_computed_070 == s_out_precomputed_070);
	mk_lang_static_assert(s_out_computed_071 == s_out_precomputed_071);
	mk_lang_static_assert(s_out_computed_072 == s_out_precomputed_072);
	mk_lang_static_assert(s_out_computed_073 == s_out_precomputed_073);
	mk_lang_static_assert(s_out_computed_074 == s_out_precomputed_074);
	mk_lang_static_assert(s_out_computed_075 == s_out_precomputed_075);
	mk_lang_static_assert(s_out_computed_076 == s_out_precomputed_076);
	mk_lang_static_assert(s_out_computed_077 == s_out_precomputed_077);
	mk_lang_static_assert(s_out_computed_078 == s_out_precomputed_078);
	mk_lang_static_assert(s_out_computed_079 == s_out_precomputed_079);
	mk_lang_static_assert(s_out_computed_080 == s_out_precomputed_080);
	mk_lang_static_assert(s_out_computed_081 == s_out_precomputed_081);
	mk_lang_static_assert(s_out_computed_082 == s_out_precomputed_082);
	mk_lang_static_assert(s_out_computed_083 == s_out_precomputed_083);
	mk_lang_static_assert(s_out_computed_084 == s_out_precomputed_084);
	mk_lang_static_assert(s_out_computed_085 == s_out_precomputed_085);
	mk_lang_static_assert(s_out_computed_086 == s_out_precomputed_086);
	mk_lang_static_assert(s_out_computed_087 == s_out_precomputed_087);
	mk_lang_static_assert(s_out_computed_088 == s_out_precomputed_088);
	mk_lang_static_assert(s_out_computed_089 == s_out_precomputed_089);
	mk_lang_static_assert(s_out_computed_090 == s_out_precomputed_090);
	mk_lang_static_assert(s_out_computed_091 == s_out_precomputed_091);
	mk_lang_static_assert(s_out_computed_092 == s_out_precomputed_092);
	mk_lang_static_assert(s_out_computed_093 == s_out_precomputed_093);
	mk_lang_static_assert(s_out_computed_094 == s_out_precomputed_094);
	mk_lang_static_assert(s_out_computed_095 == s_out_precomputed_095);
	mk_lang_static_assert(s_out_computed_096 == s_out_precomputed_096);
	mk_lang_static_assert(s_out_computed_097 == s_out_precomputed_097);
	mk_lang_static_assert(s_out_computed_098 == s_out_precomputed_098);
	mk_lang_static_assert(s_out_computed_099 == s_out_precomputed_099);
	mk_lang_static_assert(s_out_computed_100 == s_out_precomputed_100);
	mk_lang_static_assert(s_out_computed_101 == s_out_precomputed_101);
	mk_lang_static_assert(s_out_computed_102 == s_out_precomputed_102);
	mk_lang_static_assert(s_out_computed_103 == s_out_precomputed_103);
	mk_lang_static_assert(s_out_computed_104 == s_out_precomputed_104);
	mk_lang_static_assert(s_out_computed_105 == s_out_precomputed_105);
	mk_lang_static_assert(s_out_computed_106 == s_out_precomputed_106);
	mk_lang_static_assert(s_out_computed_107 == s_out_precomputed_107);
	mk_lang_static_assert(s_out_computed_108 == s_out_precomputed_108);
	mk_lang_static_assert(s_out_computed_109 == s_out_precomputed_109);
	mk_lang_static_assert(s_out_computed_110 == s_out_precomputed_110);
	mk_lang_static_assert(s_out_computed_111 == s_out_precomputed_111);
	mk_lang_static_assert(s_out_computed_112 == s_out_precomputed_112);
	mk_lang_static_assert(s_out_computed_113 == s_out_precomputed_113);
	mk_lang_static_assert(s_out_computed_114 == s_out_precomputed_114);
	mk_lang_static_assert(s_out_computed_115 == s_out_precomputed_115);
	mk_lang_static_assert(s_out_computed_116 == s_out_precomputed_116);
	mk_lang_static_assert(s_out_computed_117 == s_out_precomputed_117);
	mk_lang_static_assert(s_out_computed_118 == s_out_precomputed_118);
	mk_lang_static_assert(s_out_computed_119 == s_out_precomputed_119);
	mk_lang_static_assert(s_out_computed_120 == s_out_precomputed_120);
	mk_lang_static_assert(s_out_computed_121 == s_out_precomputed_121);
	mk_lang_static_assert(s_out_computed_122 == s_out_precomputed_122);
	mk_lang_static_assert(s_out_computed_123 == s_out_precomputed_123);
	mk_lang_static_assert(s_out_computed_124 == s_out_precomputed_124);
	mk_lang_static_assert(s_out_computed_125 == s_out_precomputed_125);
	mk_lang_static_assert(s_out_computed_126 == s_out_precomputed_126);
	mk_lang_static_assert(s_out_computed_127 == s_out_precomputed_127);
	mk_lang_static_assert(s_out_computed_128 == s_out_precomputed_128);
	mk_lang_static_assert(s_out_computed_129 == s_out_precomputed_129);
	mk_lang_static_assert(s_out_computed_130 == s_out_precomputed_130);
	mk_lang_static_assert(s_out_computed_131 == s_out_precomputed_131);
	mk_lang_static_assert(s_out_computed_132 == s_out_precomputed_132);
	mk_lang_static_assert(s_out_computed_133 == s_out_precomputed_133);
	mk_lang_static_assert(s_out_computed_134 == s_out_precomputed_134);
	mk_lang_static_assert(s_out_computed_135 == s_out_precomputed_135);
	mk_lang_static_assert(s_out_computed_136 == s_out_precomputed_136);
	mk_lang_static_assert(s_out_computed_137 == s_out_precomputed_137);
	mk_lang_static_assert(s_out_computed_138 == s_out_precomputed_138);
	mk_lang_static_assert(s_out_computed_139 == s_out_precomputed_139);
	mk_lang_static_assert(s_out_computed_140 == s_out_precomputed_140);
	mk_lang_static_assert(s_out_computed_141 == s_out_precomputed_141);
	mk_lang_static_assert(s_out_computed_142 == s_out_precomputed_142);
	mk_lang_static_assert(s_out_computed_143 == s_out_precomputed_143);
	mk_lang_static_assert(s_out_computed_144 == s_out_precomputed_144);
	mk_lang_static_assert(s_out_computed_145 == s_out_precomputed_145);
	mk_lang_static_assert(s_out_computed_146 == s_out_precomputed_146);
	mk_lang_static_assert(s_out_computed_147 == s_out_precomputed_147);
	mk_lang_static_assert(s_out_computed_148 == s_out_precomputed_148);
	mk_lang_static_assert(s_out_computed_149 == s_out_precomputed_149);
	mk_lang_static_assert(s_out_computed_150 == s_out_precomputed_150);
	mk_lang_static_assert(s_out_computed_151 == s_out_precomputed_151);
	mk_lang_static_assert(s_out_computed_152 == s_out_precomputed_152);
	mk_lang_static_assert(s_out_computed_153 == s_out_precomputed_153);
	mk_lang_static_assert(s_out_computed_154 == s_out_precomputed_154);
	mk_lang_static_assert(s_out_computed_155 == s_out_precomputed_155);
	mk_lang_static_assert(s_out_computed_156 == s_out_precomputed_156);
	mk_lang_static_assert(s_out_computed_157 == s_out_precomputed_157);
	mk_lang_static_assert(s_out_computed_158 == s_out_precomputed_158);
	mk_lang_static_assert(s_out_computed_159 == s_out_precomputed_159);
	mk_lang_static_assert(s_out_computed_160 == s_out_precomputed_160);
	mk_lang_static_assert(s_out_computed_161 == s_out_precomputed_161);
	mk_lang_static_assert(s_out_computed_162 == s_out_precomputed_162);
	mk_lang_static_assert(s_out_computed_163 == s_out_precomputed_163);
	mk_lang_static_assert(s_out_computed_164 == s_out_precomputed_164);
	mk_lang_static_assert(s_out_computed_165 == s_out_precomputed_165);
	mk_lang_static_assert(s_out_computed_166 == s_out_precomputed_166);
	mk_lang_static_assert(s_out_computed_167 == s_out_precomputed_167);
	mk_lang_static_assert(s_out_computed_168 == s_out_precomputed_168);
	mk_lang_static_assert(s_out_computed_169 == s_out_precomputed_169);
	mk_lang_static_assert(s_out_computed_170 == s_out_precomputed_170);
	mk_lang_static_assert(s_out_computed_171 == s_out_precomputed_171);
	mk_lang_static_assert(s_out_computed_172 == s_out_precomputed_172);
	mk_lang_static_assert(s_out_computed_173 == s_out_precomputed_173);
	mk_lang_static_assert(s_out_computed_174 == s_out_precomputed_174);
	mk_lang_static_assert(s_out_computed_175 == s_out_precomputed_175);
	mk_lang_static_assert(s_out_computed_176 == s_out_precomputed_176);
	mk_lang_static_assert(s_out_computed_177 == s_out_precomputed_177);
	mk_lang_static_assert(s_out_computed_178 == s_out_precomputed_178);
	mk_lang_static_assert(s_out_computed_179 == s_out_precomputed_179);
	mk_lang_static_assert(s_out_computed_180 == s_out_precomputed_180);
	mk_lang_static_assert(s_out_computed_181 == s_out_precomputed_181);
	mk_lang_static_assert(s_out_computed_182 == s_out_precomputed_182);
	mk_lang_static_assert(s_out_computed_183 == s_out_precomputed_183);
	mk_lang_static_assert(s_out_computed_184 == s_out_precomputed_184);
	mk_lang_static_assert(s_out_computed_185 == s_out_precomputed_185);
	mk_lang_static_assert(s_out_computed_186 == s_out_precomputed_186);
	mk_lang_static_assert(s_out_computed_187 == s_out_precomputed_187);
	mk_lang_static_assert(s_out_computed_188 == s_out_precomputed_188);
	mk_lang_static_assert(s_out_computed_189 == s_out_precomputed_189);
	mk_lang_static_assert(s_out_computed_190 == s_out_precomputed_190);
	mk_lang_static_assert(s_out_computed_191 == s_out_precomputed_191);
	mk_lang_static_assert(s_out_computed_192 == s_out_precomputed_192);
	mk_lang_static_assert(s_out_computed_193 == s_out_precomputed_193);
	mk_lang_static_assert(s_out_computed_194 == s_out_precomputed_194);
	mk_lang_static_assert(s_out_computed_195 == s_out_precomputed_195);
	mk_lang_static_assert(s_out_computed_196 == s_out_precomputed_196);
	mk_lang_static_assert(s_out_computed_197 == s_out_precomputed_197);
	mk_lang_static_assert(s_out_computed_198 == s_out_precomputed_198);
	mk_lang_static_assert(s_out_computed_199 == s_out_precomputed_199);
	mk_lang_static_assert(s_out_computed_200 == s_out_precomputed_200);
	mk_lang_static_assert(s_out_computed_201 == s_out_precomputed_201);
	mk_lang_static_assert(s_out_computed_202 == s_out_precomputed_202);
	mk_lang_static_assert(s_out_computed_203 == s_out_precomputed_203);
	mk_lang_static_assert(s_out_computed_204 == s_out_precomputed_204);
	mk_lang_static_assert(s_out_computed_205 == s_out_precomputed_205);
	mk_lang_static_assert(s_out_computed_206 == s_out_precomputed_206);
	mk_lang_static_assert(s_out_computed_207 == s_out_precomputed_207);
	mk_lang_static_assert(s_out_computed_208 == s_out_precomputed_208);
	mk_lang_static_assert(s_out_computed_209 == s_out_precomputed_209);
	mk_lang_static_assert(s_out_computed_210 == s_out_precomputed_210);
	mk_lang_static_assert(s_out_computed_211 == s_out_precomputed_211);
	mk_lang_static_assert(s_out_computed_212 == s_out_precomputed_212);
	mk_lang_static_assert(s_out_computed_213 == s_out_precomputed_213);
	mk_lang_static_assert(s_out_computed_214 == s_out_precomputed_214);
	mk_lang_static_assert(s_out_computed_215 == s_out_precomputed_215);
	mk_lang_static_assert(s_out_computed_216 == s_out_precomputed_216);
	mk_lang_static_assert(s_out_computed_217 == s_out_precomputed_217);
	mk_lang_static_assert(s_out_computed_218 == s_out_precomputed_218);
	mk_lang_static_assert(s_out_computed_219 == s_out_precomputed_219);
	mk_lang_static_assert(s_out_computed_220 == s_out_precomputed_220);
	mk_lang_static_assert(s_out_computed_221 == s_out_precomputed_221);
	mk_lang_static_assert(s_out_computed_222 == s_out_precomputed_222);
	mk_lang_static_assert(s_out_computed_223 == s_out_precomputed_223);
	mk_lang_static_assert(s_out_computed_224 == s_out_precomputed_224);
	mk_lang_static_assert(s_out_computed_225 == s_out_precomputed_225);
	mk_lang_static_assert(s_out_computed_226 == s_out_precomputed_226);
	mk_lang_static_assert(s_out_computed_227 == s_out_precomputed_227);
	mk_lang_static_assert(s_out_computed_228 == s_out_precomputed_228);
	mk_lang_static_assert(s_out_computed_229 == s_out_precomputed_229);
	mk_lang_static_assert(s_out_computed_230 == s_out_precomputed_230);
	mk_lang_static_assert(s_out_computed_231 == s_out_precomputed_231);
	mk_lang_static_assert(s_out_computed_232 == s_out_precomputed_232);
	mk_lang_static_assert(s_out_computed_233 == s_out_precomputed_233);
	mk_lang_static_assert(s_out_computed_234 == s_out_precomputed_234);
	mk_lang_static_assert(s_out_computed_235 == s_out_precomputed_235);
	mk_lang_static_assert(s_out_computed_236 == s_out_precomputed_236);
	mk_lang_static_assert(s_out_computed_237 == s_out_precomputed_237);
	mk_lang_static_assert(s_out_computed_238 == s_out_precomputed_238);
	mk_lang_static_assert(s_out_computed_239 == s_out_precomputed_239);
	mk_lang_static_assert(s_out_computed_240 == s_out_precomputed_240);
	mk_lang_static_assert(s_out_computed_241 == s_out_precomputed_241);
	mk_lang_static_assert(s_out_computed_242 == s_out_precomputed_242);
	mk_lang_static_assert(s_out_computed_243 == s_out_precomputed_243);
	mk_lang_static_assert(s_out_computed_244 == s_out_precomputed_244);
	mk_lang_static_assert(s_out_computed_245 == s_out_precomputed_245);
	mk_lang_static_assert(s_out_computed_246 == s_out_precomputed_246);
	mk_lang_static_assert(s_out_computed_247 == s_out_precomputed_247);
	mk_lang_static_assert(s_out_computed_248 == s_out_precomputed_248);
	mk_lang_static_assert(s_out_computed_249 == s_out_precomputed_249);
	mk_lang_static_assert(s_out_computed_250 == s_out_precomputed_250);
	mk_lang_static_assert(s_out_computed_251 == s_out_precomputed_251);
	mk_lang_static_assert(s_out_computed_252 == s_out_precomputed_252);
	mk_lang_static_assert(s_out_computed_253 == s_out_precomputed_253);
	mk_lang_static_assert(s_out_computed_254 == s_out_precomputed_254);
	mk_lang_static_assert(s_out_computed_255 == s_out_precomputed_255);
	mk_lang_static_assert(s_out_computed_256 == s_out_precomputed_256);
	mk_lang_static_assert(s_out_computed_257 == s_out_precomputed_257);
	mk_lang_static_assert(s_out_computed_258 == s_out_precomputed_258);
	mk_lang_static_assert(s_out_computed_259 == s_out_precomputed_259);
	mk_lang_static_assert(s_out_computed_260 == s_out_precomputed_260);
	mk_lang_static_assert(s_out_computed_261 == s_out_precomputed_261);
	mk_lang_static_assert(s_out_computed_262 == s_out_precomputed_262);
	mk_lang_static_assert(s_out_computed_263 == s_out_precomputed_263);
	mk_lang_static_assert(s_out_computed_264 == s_out_precomputed_264);
	mk_lang_static_assert(s_out_computed_265 == s_out_precomputed_265);
	mk_lang_static_assert(s_out_computed_266 == s_out_precomputed_266);
	mk_lang_static_assert(s_out_computed_267 == s_out_precomputed_267);
	mk_lang_static_assert(s_out_computed_268 == s_out_precomputed_268);
	mk_lang_static_assert(s_out_computed_269 == s_out_precomputed_269);

	mk_lang_static_assert(s_msg_computed_000 == s_msg_precomputed_000);
	mk_lang_static_assert(s_msg_computed_001 == s_msg_precomputed_001);
	mk_lang_static_assert(s_msg_computed_002 == s_msg_precomputed_002);
	mk_lang_static_assert(s_msg_computed_003 == s_msg_precomputed_003);
	mk_lang_static_assert(s_msg_computed_004 == s_msg_precomputed_004);
	mk_lang_static_assert(s_msg_computed_005 == s_msg_precomputed_005);
	mk_lang_static_assert(s_msg_computed_006 == s_msg_precomputed_006);
	mk_lang_static_assert(s_msg_computed_007 == s_msg_precomputed_007);
	mk_lang_static_assert(s_msg_computed_008 == s_msg_precomputed_008);
	mk_lang_static_assert(s_msg_computed_009 == s_msg_precomputed_009);
	mk_lang_static_assert(s_msg_computed_010 == s_msg_precomputed_010);
	mk_lang_static_assert(s_msg_computed_011 == s_msg_precomputed_011);
	mk_lang_static_assert(s_msg_computed_012 == s_msg_precomputed_012);
	mk_lang_static_assert(s_msg_computed_013 == s_msg_precomputed_013);
	mk_lang_static_assert(s_msg_computed_014 == s_msg_precomputed_014);
	mk_lang_static_assert(s_msg_computed_015 == s_msg_precomputed_015);
	mk_lang_static_assert(s_msg_computed_016 == s_msg_precomputed_016);
	mk_lang_static_assert(s_msg_computed_017 == s_msg_precomputed_017);
	mk_lang_static_assert(s_msg_computed_018 == s_msg_precomputed_018);
	mk_lang_static_assert(s_msg_computed_019 == s_msg_precomputed_019);
	mk_lang_static_assert(s_msg_computed_020 == s_msg_precomputed_020);
	mk_lang_static_assert(s_msg_computed_021 == s_msg_precomputed_021);
	mk_lang_static_assert(s_msg_computed_022 == s_msg_precomputed_022);
	mk_lang_static_assert(s_msg_computed_023 == s_msg_precomputed_023);
	mk_lang_static_assert(s_msg_computed_024 == s_msg_precomputed_024);
	mk_lang_static_assert(s_msg_computed_025 == s_msg_precomputed_025);
	mk_lang_static_assert(s_msg_computed_026 == s_msg_precomputed_026);
	mk_lang_static_assert(s_msg_computed_027 == s_msg_precomputed_027);
	mk_lang_static_assert(s_msg_computed_028 == s_msg_precomputed_028);
	mk_lang_static_assert(s_msg_computed_029 == s_msg_precomputed_029);
	mk_lang_static_assert(s_msg_computed_030 == s_msg_precomputed_030);
	mk_lang_static_assert(s_msg_computed_031 == s_msg_precomputed_031);
	mk_lang_static_assert(s_msg_computed_032 == s_msg_precomputed_032);
	mk_lang_static_assert(s_msg_computed_033 == s_msg_precomputed_033);
	mk_lang_static_assert(s_msg_computed_034 == s_msg_precomputed_034);
	mk_lang_static_assert(s_msg_computed_035 == s_msg_precomputed_035);
	mk_lang_static_assert(s_msg_computed_036 == s_msg_precomputed_036);
	mk_lang_static_assert(s_msg_computed_037 == s_msg_precomputed_037);
	mk_lang_static_assert(s_msg_computed_038 == s_msg_precomputed_038);
	mk_lang_static_assert(s_msg_computed_039 == s_msg_precomputed_039);
	mk_lang_static_assert(s_msg_computed_040 == s_msg_precomputed_040);
	mk_lang_static_assert(s_msg_computed_041 == s_msg_precomputed_041);
	mk_lang_static_assert(s_msg_computed_042 == s_msg_precomputed_042);
	mk_lang_static_assert(s_msg_computed_043 == s_msg_precomputed_043);
	mk_lang_static_assert(s_msg_computed_044 == s_msg_precomputed_044);
	mk_lang_static_assert(s_msg_computed_045 == s_msg_precomputed_045);
	mk_lang_static_assert(s_msg_computed_046 == s_msg_precomputed_046);
	mk_lang_static_assert(s_msg_computed_047 == s_msg_precomputed_047);
	mk_lang_static_assert(s_msg_computed_048 == s_msg_precomputed_048);
	mk_lang_static_assert(s_msg_computed_049 == s_msg_precomputed_049);
	mk_lang_static_assert(s_msg_computed_050 == s_msg_precomputed_050);
	mk_lang_static_assert(s_msg_computed_051 == s_msg_precomputed_051);
	mk_lang_static_assert(s_msg_computed_052 == s_msg_precomputed_052);
	mk_lang_static_assert(s_msg_computed_053 == s_msg_precomputed_053);
	mk_lang_static_assert(s_msg_computed_054 == s_msg_precomputed_054);
	mk_lang_static_assert(s_msg_computed_055 == s_msg_precomputed_055);
	mk_lang_static_assert(s_msg_computed_056 == s_msg_precomputed_056);
	mk_lang_static_assert(s_msg_computed_057 == s_msg_precomputed_057);
	mk_lang_static_assert(s_msg_computed_058 == s_msg_precomputed_058);
	mk_lang_static_assert(s_msg_computed_059 == s_msg_precomputed_059);
	mk_lang_static_assert(s_msg_computed_060 == s_msg_precomputed_060);
	mk_lang_static_assert(s_msg_computed_061 == s_msg_precomputed_061);
	mk_lang_static_assert(s_msg_computed_062 == s_msg_precomputed_062);
	mk_lang_static_assert(s_msg_computed_063 == s_msg_precomputed_063);
	mk_lang_static_assert(s_msg_computed_064 == s_msg_precomputed_064);
	mk_lang_static_assert(s_msg_computed_065 == s_msg_precomputed_065);
	mk_lang_static_assert(s_msg_computed_066 == s_msg_precomputed_066);
	mk_lang_static_assert(s_msg_computed_067 == s_msg_precomputed_067);
	mk_lang_static_assert(s_msg_computed_068 == s_msg_precomputed_068);
	mk_lang_static_assert(s_msg_computed_069 == s_msg_precomputed_069);
	mk_lang_static_assert(s_msg_computed_070 == s_msg_precomputed_070);
	mk_lang_static_assert(s_msg_computed_071 == s_msg_precomputed_071);
	mk_lang_static_assert(s_msg_computed_072 == s_msg_precomputed_072);
	mk_lang_static_assert(s_msg_computed_073 == s_msg_precomputed_073);
	mk_lang_static_assert(s_msg_computed_074 == s_msg_precomputed_074);
	mk_lang_static_assert(s_msg_computed_075 == s_msg_precomputed_075);
	mk_lang_static_assert(s_msg_computed_076 == s_msg_precomputed_076);
	mk_lang_static_assert(s_msg_computed_077 == s_msg_precomputed_077);
	mk_lang_static_assert(s_msg_computed_078 == s_msg_precomputed_078);
	mk_lang_static_assert(s_msg_computed_079 == s_msg_precomputed_079);
	mk_lang_static_assert(s_msg_computed_080 == s_msg_precomputed_080);
	mk_lang_static_assert(s_msg_computed_081 == s_msg_precomputed_081);
	mk_lang_static_assert(s_msg_computed_082 == s_msg_precomputed_082);
	mk_lang_static_assert(s_msg_computed_083 == s_msg_precomputed_083);
	mk_lang_static_assert(s_msg_computed_084 == s_msg_precomputed_084);
	mk_lang_static_assert(s_msg_computed_085 == s_msg_precomputed_085);
	mk_lang_static_assert(s_msg_computed_086 == s_msg_precomputed_086);
	mk_lang_static_assert(s_msg_computed_087 == s_msg_precomputed_087);
	mk_lang_static_assert(s_msg_computed_088 == s_msg_precomputed_088);
	mk_lang_static_assert(s_msg_computed_089 == s_msg_precomputed_089);
	mk_lang_static_assert(s_msg_computed_090 == s_msg_precomputed_090);
	mk_lang_static_assert(s_msg_computed_091 == s_msg_precomputed_091);
	mk_lang_static_assert(s_msg_computed_092 == s_msg_precomputed_092);
	mk_lang_static_assert(s_msg_computed_093 == s_msg_precomputed_093);
	mk_lang_static_assert(s_msg_computed_094 == s_msg_precomputed_094);
	mk_lang_static_assert(s_msg_computed_095 == s_msg_precomputed_095);
	mk_lang_static_assert(s_msg_computed_096 == s_msg_precomputed_096);
	mk_lang_static_assert(s_msg_computed_097 == s_msg_precomputed_097);
	mk_lang_static_assert(s_msg_computed_098 == s_msg_precomputed_098);
	mk_lang_static_assert(s_msg_computed_099 == s_msg_precomputed_099);
	mk_lang_static_assert(s_msg_computed_100 == s_msg_precomputed_100);
	mk_lang_static_assert(s_msg_computed_101 == s_msg_precomputed_101);
	mk_lang_static_assert(s_msg_computed_102 == s_msg_precomputed_102);
	mk_lang_static_assert(s_msg_computed_103 == s_msg_precomputed_103);
	mk_lang_static_assert(s_msg_computed_104 == s_msg_precomputed_104);
	mk_lang_static_assert(s_msg_computed_105 == s_msg_precomputed_105);
	mk_lang_static_assert(s_msg_computed_106 == s_msg_precomputed_106);
	mk_lang_static_assert(s_msg_computed_107 == s_msg_precomputed_107);
	mk_lang_static_assert(s_msg_computed_108 == s_msg_precomputed_108);
	mk_lang_static_assert(s_msg_computed_109 == s_msg_precomputed_109);
	mk_lang_static_assert(s_msg_computed_110 == s_msg_precomputed_110);
	mk_lang_static_assert(s_msg_computed_111 == s_msg_precomputed_111);
	mk_lang_static_assert(s_msg_computed_112 == s_msg_precomputed_112);
	mk_lang_static_assert(s_msg_computed_113 == s_msg_precomputed_113);
	mk_lang_static_assert(s_msg_computed_114 == s_msg_precomputed_114);
	mk_lang_static_assert(s_msg_computed_115 == s_msg_precomputed_115);
	mk_lang_static_assert(s_msg_computed_116 == s_msg_precomputed_116);
	mk_lang_static_assert(s_msg_computed_117 == s_msg_precomputed_117);
	mk_lang_static_assert(s_msg_computed_118 == s_msg_precomputed_118);
	mk_lang_static_assert(s_msg_computed_119 == s_msg_precomputed_119);
	mk_lang_static_assert(s_msg_computed_120 == s_msg_precomputed_120);
	mk_lang_static_assert(s_msg_computed_121 == s_msg_precomputed_121);
	mk_lang_static_assert(s_msg_computed_122 == s_msg_precomputed_122);
	mk_lang_static_assert(s_msg_computed_123 == s_msg_precomputed_123);
	mk_lang_static_assert(s_msg_computed_124 == s_msg_precomputed_124);
	mk_lang_static_assert(s_msg_computed_125 == s_msg_precomputed_125);
	mk_lang_static_assert(s_msg_computed_126 == s_msg_precomputed_126);
	mk_lang_static_assert(s_msg_computed_127 == s_msg_precomputed_127);
	mk_lang_static_assert(s_msg_computed_128 == s_msg_precomputed_128);
	mk_lang_static_assert(s_msg_computed_129 == s_msg_precomputed_129);
	mk_lang_static_assert(s_msg_computed_130 == s_msg_precomputed_130);
	mk_lang_static_assert(s_msg_computed_131 == s_msg_precomputed_131);
	mk_lang_static_assert(s_msg_computed_132 == s_msg_precomputed_132);
	mk_lang_static_assert(s_msg_computed_133 == s_msg_precomputed_133);
	mk_lang_static_assert(s_msg_computed_134 == s_msg_precomputed_134);
	mk_lang_static_assert(s_msg_computed_135 == s_msg_precomputed_135);
	mk_lang_static_assert(s_msg_computed_136 == s_msg_precomputed_136);
	mk_lang_static_assert(s_msg_computed_137 == s_msg_precomputed_137);
	mk_lang_static_assert(s_msg_computed_138 == s_msg_precomputed_138);
	mk_lang_static_assert(s_msg_computed_139 == s_msg_precomputed_139);
	mk_lang_static_assert(s_msg_computed_140 == s_msg_precomputed_140);
	mk_lang_static_assert(s_msg_computed_141 == s_msg_precomputed_141);
	mk_lang_static_assert(s_msg_computed_142 == s_msg_precomputed_142);
	mk_lang_static_assert(s_msg_computed_143 == s_msg_precomputed_143);
	mk_lang_static_assert(s_msg_computed_144 == s_msg_precomputed_144);
	mk_lang_static_assert(s_msg_computed_145 == s_msg_precomputed_145);
	mk_lang_static_assert(s_msg_computed_146 == s_msg_precomputed_146);
	mk_lang_static_assert(s_msg_computed_147 == s_msg_precomputed_147);
	mk_lang_static_assert(s_msg_computed_148 == s_msg_precomputed_148);
	mk_lang_static_assert(s_msg_computed_149 == s_msg_precomputed_149);
	mk_lang_static_assert(s_msg_computed_150 == s_msg_precomputed_150);
	mk_lang_static_assert(s_msg_computed_151 == s_msg_precomputed_151);
	mk_lang_static_assert(s_msg_computed_152 == s_msg_precomputed_152);
	mk_lang_static_assert(s_msg_computed_153 == s_msg_precomputed_153);
	mk_lang_static_assert(s_msg_computed_154 == s_msg_precomputed_154);
	mk_lang_static_assert(s_msg_computed_155 == s_msg_precomputed_155);
	mk_lang_static_assert(s_msg_computed_156 == s_msg_precomputed_156);
	mk_lang_static_assert(s_msg_computed_157 == s_msg_precomputed_157);
	mk_lang_static_assert(s_msg_computed_158 == s_msg_precomputed_158);
	mk_lang_static_assert(s_msg_computed_159 == s_msg_precomputed_159);
	mk_lang_static_assert(s_msg_computed_160 == s_msg_precomputed_160);
	mk_lang_static_assert(s_msg_computed_161 == s_msg_precomputed_161);
	mk_lang_static_assert(s_msg_computed_162 == s_msg_precomputed_162);
	mk_lang_static_assert(s_msg_computed_163 == s_msg_precomputed_163);
	mk_lang_static_assert(s_msg_computed_164 == s_msg_precomputed_164);
	mk_lang_static_assert(s_msg_computed_165 == s_msg_precomputed_165);
	mk_lang_static_assert(s_msg_computed_166 == s_msg_precomputed_166);
	mk_lang_static_assert(s_msg_computed_167 == s_msg_precomputed_167);
	mk_lang_static_assert(s_msg_computed_168 == s_msg_precomputed_168);
	mk_lang_static_assert(s_msg_computed_169 == s_msg_precomputed_169);
	mk_lang_static_assert(s_msg_computed_170 == s_msg_precomputed_170);
	mk_lang_static_assert(s_msg_computed_171 == s_msg_precomputed_171);
	mk_lang_static_assert(s_msg_computed_172 == s_msg_precomputed_172);
	mk_lang_static_assert(s_msg_computed_173 == s_msg_precomputed_173);
	mk_lang_static_assert(s_msg_computed_174 == s_msg_precomputed_174);
	mk_lang_static_assert(s_msg_computed_175 == s_msg_precomputed_175);
	mk_lang_static_assert(s_msg_computed_176 == s_msg_precomputed_176);
	mk_lang_static_assert(s_msg_computed_177 == s_msg_precomputed_177);
	mk_lang_static_assert(s_msg_computed_178 == s_msg_precomputed_178);
	mk_lang_static_assert(s_msg_computed_179 == s_msg_precomputed_179);
	mk_lang_static_assert(s_msg_computed_180 == s_msg_precomputed_180);
	mk_lang_static_assert(s_msg_computed_181 == s_msg_precomputed_181);
	mk_lang_static_assert(s_msg_computed_182 == s_msg_precomputed_182);
	mk_lang_static_assert(s_msg_computed_183 == s_msg_precomputed_183);
	mk_lang_static_assert(s_msg_computed_184 == s_msg_precomputed_184);
	mk_lang_static_assert(s_msg_computed_185 == s_msg_precomputed_185);
	mk_lang_static_assert(s_msg_computed_186 == s_msg_precomputed_186);
	mk_lang_static_assert(s_msg_computed_187 == s_msg_precomputed_187);
	mk_lang_static_assert(s_msg_computed_188 == s_msg_precomputed_188);
	mk_lang_static_assert(s_msg_computed_189 == s_msg_precomputed_189);
	mk_lang_static_assert(s_msg_computed_190 == s_msg_precomputed_190);
	mk_lang_static_assert(s_msg_computed_191 == s_msg_precomputed_191);
	mk_lang_static_assert(s_msg_computed_192 == s_msg_precomputed_192);
	mk_lang_static_assert(s_msg_computed_193 == s_msg_precomputed_193);
	mk_lang_static_assert(s_msg_computed_194 == s_msg_precomputed_194);
	mk_lang_static_assert(s_msg_computed_195 == s_msg_precomputed_195);
	mk_lang_static_assert(s_msg_computed_196 == s_msg_precomputed_196);
	mk_lang_static_assert(s_msg_computed_197 == s_msg_precomputed_197);
	mk_lang_static_assert(s_msg_computed_198 == s_msg_precomputed_198);
	mk_lang_static_assert(s_msg_computed_199 == s_msg_precomputed_199);
	mk_lang_static_assert(s_msg_computed_200 == s_msg_precomputed_200);
	mk_lang_static_assert(s_msg_computed_201 == s_msg_precomputed_201);
	mk_lang_static_assert(s_msg_computed_202 == s_msg_precomputed_202);
	mk_lang_static_assert(s_msg_computed_203 == s_msg_precomputed_203);
	mk_lang_static_assert(s_msg_computed_204 == s_msg_precomputed_204);
	mk_lang_static_assert(s_msg_computed_205 == s_msg_precomputed_205);
	mk_lang_static_assert(s_msg_computed_206 == s_msg_precomputed_206);
	mk_lang_static_assert(s_msg_computed_207 == s_msg_precomputed_207);
	mk_lang_static_assert(s_msg_computed_208 == s_msg_precomputed_208);
	mk_lang_static_assert(s_msg_computed_209 == s_msg_precomputed_209);
	mk_lang_static_assert(s_msg_computed_210 == s_msg_precomputed_210);
	mk_lang_static_assert(s_msg_computed_211 == s_msg_precomputed_211);
	mk_lang_static_assert(s_msg_computed_212 == s_msg_precomputed_212);
	mk_lang_static_assert(s_msg_computed_213 == s_msg_precomputed_213);
	mk_lang_static_assert(s_msg_computed_214 == s_msg_precomputed_214);
	mk_lang_static_assert(s_msg_computed_215 == s_msg_precomputed_215);
	mk_lang_static_assert(s_msg_computed_216 == s_msg_precomputed_216);
	mk_lang_static_assert(s_msg_computed_217 == s_msg_precomputed_217);
	mk_lang_static_assert(s_msg_computed_218 == s_msg_precomputed_218);
	mk_lang_static_assert(s_msg_computed_219 == s_msg_precomputed_219);
	mk_lang_static_assert(s_msg_computed_220 == s_msg_precomputed_220);
	mk_lang_static_assert(s_msg_computed_221 == s_msg_precomputed_221);
	mk_lang_static_assert(s_msg_computed_222 == s_msg_precomputed_222);
	mk_lang_static_assert(s_msg_computed_223 == s_msg_precomputed_223);
	mk_lang_static_assert(s_msg_computed_224 == s_msg_precomputed_224);
	mk_lang_static_assert(s_msg_computed_225 == s_msg_precomputed_225);
	mk_lang_static_assert(s_msg_computed_226 == s_msg_precomputed_226);
	mk_lang_static_assert(s_msg_computed_227 == s_msg_precomputed_227);
	mk_lang_static_assert(s_msg_computed_228 == s_msg_precomputed_228);
	mk_lang_static_assert(s_msg_computed_229 == s_msg_precomputed_229);
	mk_lang_static_assert(s_msg_computed_230 == s_msg_precomputed_230);
	mk_lang_static_assert(s_msg_computed_231 == s_msg_precomputed_231);
	mk_lang_static_assert(s_msg_computed_232 == s_msg_precomputed_232);
	mk_lang_static_assert(s_msg_computed_233 == s_msg_precomputed_233);
	mk_lang_static_assert(s_msg_computed_234 == s_msg_precomputed_234);
	mk_lang_static_assert(s_msg_computed_235 == s_msg_precomputed_235);
	mk_lang_static_assert(s_msg_computed_236 == s_msg_precomputed_236);
	mk_lang_static_assert(s_msg_computed_237 == s_msg_precomputed_237);
	mk_lang_static_assert(s_msg_computed_238 == s_msg_precomputed_238);
	mk_lang_static_assert(s_msg_computed_239 == s_msg_precomputed_239);
	mk_lang_static_assert(s_msg_computed_240 == s_msg_precomputed_240);
	mk_lang_static_assert(s_msg_computed_241 == s_msg_precomputed_241);
	mk_lang_static_assert(s_msg_computed_242 == s_msg_precomputed_242);
	mk_lang_static_assert(s_msg_computed_243 == s_msg_precomputed_243);
	mk_lang_static_assert(s_msg_computed_244 == s_msg_precomputed_244);
	mk_lang_static_assert(s_msg_computed_245 == s_msg_precomputed_245);
	mk_lang_static_assert(s_msg_computed_246 == s_msg_precomputed_246);
	mk_lang_static_assert(s_msg_computed_247 == s_msg_precomputed_247);
	mk_lang_static_assert(s_msg_computed_248 == s_msg_precomputed_248);
	mk_lang_static_assert(s_msg_computed_249 == s_msg_precomputed_249);
	mk_lang_static_assert(s_msg_computed_250 == s_msg_precomputed_250);
	mk_lang_static_assert(s_msg_computed_251 == s_msg_precomputed_251);
	mk_lang_static_assert(s_msg_computed_252 == s_msg_precomputed_252);
	mk_lang_static_assert(s_msg_computed_253 == s_msg_precomputed_253);
	mk_lang_static_assert(s_msg_computed_254 == s_msg_precomputed_254);
	mk_lang_static_assert(s_msg_computed_255 == s_msg_precomputed_255);
	mk_lang_static_assert(s_msg_computed_256 == s_msg_precomputed_256);
	mk_lang_static_assert(s_msg_computed_257 == s_msg_precomputed_257);
	mk_lang_static_assert(s_msg_computed_258 == s_msg_precomputed_258);
	mk_lang_static_assert(s_msg_computed_259 == s_msg_precomputed_259);
	mk_lang_static_assert(s_msg_computed_260 == s_msg_precomputed_260);
	mk_lang_static_assert(s_msg_computed_261 == s_msg_precomputed_261);
	mk_lang_static_assert(s_msg_computed_262 == s_msg_precomputed_262);
	mk_lang_static_assert(s_msg_computed_263 == s_msg_precomputed_263);
	mk_lang_static_assert(s_msg_computed_264 == s_msg_precomputed_264);
	mk_lang_static_assert(s_msg_computed_265 == s_msg_precomputed_265);
	mk_lang_static_assert(s_msg_computed_266 == s_msg_precomputed_266);
	mk_lang_static_assert(s_msg_computed_267 == s_msg_precomputed_267);
	mk_lang_static_assert(s_msg_computed_268 == s_msg_precomputed_268);
	mk_lang_static_assert(s_msg_computed_269 == s_msg_precomputed_269);

	#endif

	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_crash(); } ((void)(0))

	static char const* const s_keys[] =
	{
		key_000,
		key_001,
		key_002,
		key_003,
		key_004,
		key_005,
		key_006,
		key_007,
		key_008,
		key_009,
		key_010,
		key_011,
		key_012,
		key_013,
		key_014,
		key_015,
		key_016,
		key_017,
		key_018,
		key_019,
		key_020,
		key_021,
		key_022,
		key_023,
		key_024,
		key_025,
		key_026,
		key_027,
		key_028,
		key_029,
		key_030,
		key_031,
		key_032,
		key_033,
		key_034,
		key_035,
		key_036,
		key_037,
		key_038,
		key_039,
		key_040,
		key_041,
		key_042,
		key_043,
		key_044,
		key_045,
		key_046,
		key_047,
		key_048,
		key_049,
		key_050,
		key_051,
		key_052,
		key_053,
		key_054,
		key_055,
		key_056,
		key_057,
		key_058,
		key_059,
		key_060,
		key_061,
		key_062,
		key_063,
		key_064,
		key_065,
		key_066,
		key_067,
		key_068,
		key_069,
		key_070,
		key_071,
		key_072,
		key_073,
		key_074,
		key_075,
		key_076,
		key_077,
		key_078,
		key_079,
		key_080,
		key_081,
		key_082,
		key_083,
		key_084,
		key_085,
		key_086,
		key_087,
		key_088,
		key_089,
		key_090,
		key_091,
		key_092,
		key_093,
		key_094,
		key_095,
		key_096,
		key_097,
		key_098,
		key_099,
		key_100,
		key_101,
		key_102,
		key_103,
		key_104,
		key_105,
		key_106,
		key_107,
		key_108,
		key_109,
		key_110,
		key_111,
		key_112,
		key_113,
		key_114,
		key_115,
		key_116,
		key_117,
		key_118,
		key_119,
		key_120,
		key_121,
		key_122,
		key_123,
		key_124,
		key_125,
		key_126,
		key_127,
		key_128,
		key_129,
		key_130,
		key_131,
		key_132,
		key_133,
		key_134,
		key_135,
		key_136,
		key_137,
		key_138,
		key_139,
		key_140,
		key_141,
		key_142,
		key_143,
		key_144,
		key_145,
		key_146,
		key_147,
		key_148,
		key_149,
		key_150,
		key_151,
		key_152,
		key_153,
		key_154,
		key_155,
		key_156,
		key_157,
		key_158,
		key_159,
		key_160,
		key_161,
		key_162,
		key_163,
		key_164,
		key_165,
		key_166,
		key_167,
		key_168,
		key_169,
		key_170,
		key_171,
		key_172,
		key_173,
		key_174,
		key_175,
		key_176,
		key_177,
		key_178,
		key_179,
		key_180,
		key_181,
		key_182,
		key_183,
		key_184,
		key_185,
		key_186,
		key_187,
		key_188,
		key_189,
		key_190,
		key_191,
		key_192,
		key_193,
		key_194,
		key_195,
		key_196,
		key_197,
		key_198,
		key_199,
		key_200,
		key_201,
		key_202,
		key_203,
		key_204,
		key_205,
		key_206,
		key_207,
		key_208,
		key_209,
		key_210,
		key_211,
		key_212,
		key_213,
		key_214,
		key_215,
		key_216,
		key_217,
		key_218,
		key_219,
		key_220,
		key_221,
		key_222,
		key_223,
		key_224,
		key_225,
		key_226,
		key_227,
		key_228,
		key_229,
		key_230,
		key_231,
		key_232,
		key_233,
		key_234,
		key_235,
		key_236,
		key_237,
		key_238,
		key_239,
		key_240,
		key_241,
		key_242,
		key_243,
		key_244,
		key_245,
		key_246,
		key_247,
		key_248,
		key_249,
		key_250,
		key_251,
		key_252,
		key_253,
		key_254,
		key_255,
		key_256,
		key_257,
		key_258,
		key_259,
		key_260,
		key_261,
		key_262,
		key_263,
		key_264,
		key_265,
		key_266,
		key_267,
		key_268,
		key_269,
	};

	static char const* const s_msgs[] =
	{
		msg_000,
		msg_001,
		msg_002,
		msg_003,
		msg_004,
		msg_005,
		msg_006,
		msg_007,
		msg_008,
		msg_009,
		msg_010,
		msg_011,
		msg_012,
		msg_013,
		msg_014,
		msg_015,
		msg_016,
		msg_017,
		msg_018,
		msg_019,
		msg_020,
		msg_021,
		msg_022,
		msg_023,
		msg_024,
		msg_025,
		msg_026,
		msg_027,
		msg_028,
		msg_029,
		msg_030,
		msg_031,
		msg_032,
		msg_033,
		msg_034,
		msg_035,
		msg_036,
		msg_037,
		msg_038,
		msg_039,
		msg_040,
		msg_041,
		msg_042,
		msg_043,
		msg_044,
		msg_045,
		msg_046,
		msg_047,
		msg_048,
		msg_049,
		msg_050,
		msg_051,
		msg_052,
		msg_053,
		msg_054,
		msg_055,
		msg_056,
		msg_057,
		msg_058,
		msg_059,
		msg_060,
		msg_061,
		msg_062,
		msg_063,
		msg_064,
		msg_065,
		msg_066,
		msg_067,
		msg_068,
		msg_069,
		msg_070,
		msg_071,
		msg_072,
		msg_073,
		msg_074,
		msg_075,
		msg_076,
		msg_077,
		msg_078,
		msg_079,
		msg_080,
		msg_081,
		msg_082,
		msg_083,
		msg_084,
		msg_085,
		msg_086,
		msg_087,
		msg_088,
		msg_089,
		msg_090,
		msg_091,
		msg_092,
		msg_093,
		msg_094,
		msg_095,
		msg_096,
		msg_097,
		msg_098,
		msg_099,
		msg_100,
		msg_101,
		msg_102,
		msg_103,
		msg_104,
		msg_105,
		msg_106,
		msg_107,
		msg_108,
		msg_109,
		msg_110,
		msg_111,
		msg_112,
		msg_113,
		msg_114,
		msg_115,
		msg_116,
		msg_117,
		msg_118,
		msg_119,
		msg_120,
		msg_121,
		msg_122,
		msg_123,
		msg_124,
		msg_125,
		msg_126,
		msg_127,
		msg_128,
		msg_129,
		msg_130,
		msg_131,
		msg_132,
		msg_133,
		msg_134,
		msg_135,
		msg_136,
		msg_137,
		msg_138,
		msg_139,
		msg_140,
		msg_141,
		msg_142,
		msg_143,
		msg_144,
		msg_145,
		msg_146,
		msg_147,
		msg_148,
		msg_149,
		msg_150,
		msg_151,
		msg_152,
		msg_153,
		msg_154,
		msg_155,
		msg_156,
		msg_157,
		msg_158,
		msg_159,
		msg_160,
		msg_161,
		msg_162,
		msg_163,
		msg_164,
		msg_165,
		msg_166,
		msg_167,
		msg_168,
		msg_169,
		msg_170,
		msg_171,
		msg_172,
		msg_173,
		msg_174,
		msg_175,
		msg_176,
		msg_177,
		msg_178,
		msg_179,
		msg_180,
		msg_181,
		msg_182,
		msg_183,
		msg_184,
		msg_185,
		msg_186,
		msg_187,
		msg_188,
		msg_189,
		msg_190,
		msg_191,
		msg_192,
		msg_193,
		msg_194,
		msg_195,
		msg_196,
		msg_197,
		msg_198,
		msg_199,
		msg_200,
		msg_201,
		msg_202,
		msg_203,
		msg_204,
		msg_205,
		msg_206,
		msg_207,
		msg_208,
		msg_209,
		msg_210,
		msg_211,
		msg_212,
		msg_213,
		msg_214,
		msg_215,
		msg_216,
		msg_217,
		msg_218,
		msg_219,
		msg_220,
		msg_221,
		msg_222,
		msg_223,
		msg_224,
		msg_225,
		msg_226,
		msg_227,
		msg_228,
		msg_229,
		msg_230,
		msg_231,
		msg_232,
		msg_233,
		msg_234,
		msg_235,
		msg_236,
		msg_237,
		msg_238,
		msg_239,
		msg_240,
		msg_241,
		msg_242,
		msg_243,
		msg_244,
		msg_245,
		msg_246,
		msg_247,
		msg_248,
		msg_249,
		msg_250,
		msg_251,
		msg_252,
		msg_253,
		msg_254,
		msg_255,
		msg_256,
		msg_257,
		msg_258,
		msg_259,
		msg_260,
		msg_261,
		msg_262,
		msg_263,
		msg_264,
		msg_265,
		msg_266,
		msg_267,
		msg_268,
		msg_269,
	};

	static char const* const s_outs[] =
	{
		out_000,
		out_001,
		out_002,
		out_003,
		out_004,
		out_005,
		out_006,
		out_007,
		out_008,
		out_009,
		out_010,
		out_011,
		out_012,
		out_013,
		out_014,
		out_015,
		out_016,
		out_017,
		out_018,
		out_019,
		out_020,
		out_021,
		out_022,
		out_023,
		out_024,
		out_025,
		out_026,
		out_027,
		out_028,
		out_029,
		out_030,
		out_031,
		out_032,
		out_033,
		out_034,
		out_035,
		out_036,
		out_037,
		out_038,
		out_039,
		out_040,
		out_041,
		out_042,
		out_043,
		out_044,
		out_045,
		out_046,
		out_047,
		out_048,
		out_049,
		out_050,
		out_051,
		out_052,
		out_053,
		out_054,
		out_055,
		out_056,
		out_057,
		out_058,
		out_059,
		out_060,
		out_061,
		out_062,
		out_063,
		out_064,
		out_065,
		out_066,
		out_067,
		out_068,
		out_069,
		out_070,
		out_071,
		out_072,
		out_073,
		out_074,
		out_075,
		out_076,
		out_077,
		out_078,
		out_079,
		out_080,
		out_081,
		out_082,
		out_083,
		out_084,
		out_085,
		out_086,
		out_087,
		out_088,
		out_089,
		out_090,
		out_091,
		out_092,
		out_093,
		out_094,
		out_095,
		out_096,
		out_097,
		out_098,
		out_099,
		out_100,
		out_101,
		out_102,
		out_103,
		out_104,
		out_105,
		out_106,
		out_107,
		out_108,
		out_109,
		out_110,
		out_111,
		out_112,
		out_113,
		out_114,
		out_115,
		out_116,
		out_117,
		out_118,
		out_119,
		out_120,
		out_121,
		out_122,
		out_123,
		out_124,
		out_125,
		out_126,
		out_127,
		out_128,
		out_129,
		out_130,
		out_131,
		out_132,
		out_133,
		out_134,
		out_135,
		out_136,
		out_137,
		out_138,
		out_139,
		out_140,
		out_141,
		out_142,
		out_143,
		out_144,
		out_145,
		out_146,
		out_147,
		out_148,
		out_149,
		out_150,
		out_151,
		out_152,
		out_153,
		out_154,
		out_155,
		out_156,
		out_157,
		out_158,
		out_159,
		out_160,
		out_161,
		out_162,
		out_163,
		out_164,
		out_165,
		out_166,
		out_167,
		out_168,
		out_169,
		out_170,
		out_171,
		out_172,
		out_173,
		out_174,
		out_175,
		out_176,
		out_177,
		out_178,
		out_179,
		out_180,
		out_181,
		out_182,
		out_183,
		out_184,
		out_185,
		out_186,
		out_187,
		out_188,
		out_189,
		out_190,
		out_191,
		out_192,
		out_193,
		out_194,
		out_195,
		out_196,
		out_197,
		out_198,
		out_199,
		out_200,
		out_201,
		out_202,
		out_203,
		out_204,
		out_205,
		out_206,
		out_207,
		out_208,
		out_209,
		out_210,
		out_211,
		out_212,
		out_213,
		out_214,
		out_215,
		out_216,
		out_217,
		out_218,
		out_219,
		out_220,
		out_221,
		out_222,
		out_223,
		out_224,
		out_225,
		out_226,
		out_227,
		out_228,
		out_229,
		out_230,
		out_231,
		out_232,
		out_233,
		out_234,
		out_235,
		out_236,
		out_237,
		out_238,
		out_239,
		out_240,
		out_241,
		out_242,
		out_243,
		out_244,
		out_245,
		out_246,
		out_247,
		out_248,
		out_249,
		out_250,
		out_251,
		out_252,
		out_253,
		out_254,
		out_255,
		out_256,
		out_257,
		out_258,
		out_259,
		out_260,
		out_261,
		out_262,
		out_263,
		out_264,
		out_265,
		out_266,
		out_267,
		out_268,
		out_269,
	};

	int n;
	int i;
	int j;
	mk_lang_types_uchar_t hi;
	mk_lang_types_uchar_t lo;
	mk_lang_types_uchar_t byte;
	mk_lib_crypto_alg_des_key_t key;
	mk_lib_crypto_alg_des_msg_t msg;
	mk_sl_cui_uint8_t u8;

	mk_lang_static_assert(sizeof(s_keys) / sizeof(s_keys[0]) == sizeof(s_msgs) / sizeof(s_msgs[0]));
	mk_lang_static_assert(sizeof(s_keys) / sizeof(s_keys[0]) == sizeof(s_outs) / sizeof(s_outs[0]));

	mk_lang_cpuid_init();
	n = ((int)(sizeof(s_keys) / sizeof(s_keys[0])));
	for(i = 0; i != n; ++i)
	{
		for(j = 0; j != mk_lib_crypto_alg_des_key_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&key.m_data.m_uint8s[j], &byte);
		}
		for(j = 0; j != mk_lib_crypto_alg_des_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&msg.m_data.m_uint8s[j], &byte);
		}
		mk_lib_crypto_alg_des_encrypt(&key, &msg, &msg);
		for(j = 0; j != mk_lib_crypto_alg_des_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
			test(mk_sl_cui_uint8_eq(&msg.m_data.m_uint8s[j], &u8));
		}
		mk_lib_crypto_alg_des_decrypt(&key, &msg, &msg);
		for(j = 0; j != mk_lib_crypto_alg_des_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
			test(mk_sl_cui_uint8_eq(&msg.m_data.m_uint8s[j], &u8));
		}
	}

	#undef test

	#undef key_000
	#undef key_001
	#undef key_002
	#undef key_003
	#undef key_004
	#undef key_005
	#undef key_006
	#undef key_007
	#undef key_008
	#undef key_009
	#undef key_010
	#undef key_011
	#undef key_012
	#undef key_013
	#undef key_014
	#undef key_015
	#undef key_016
	#undef key_017
	#undef key_018
	#undef key_019
	#undef key_020
	#undef key_021
	#undef key_022
	#undef key_023
	#undef key_024
	#undef key_025
	#undef key_026
	#undef key_027
	#undef key_028
	#undef key_029
	#undef key_030
	#undef key_031
	#undef key_032
	#undef key_033
	#undef key_034
	#undef key_035
	#undef key_036
	#undef key_037
	#undef key_038
	#undef key_039
	#undef key_040
	#undef key_041
	#undef key_042
	#undef key_043
	#undef key_044
	#undef key_045
	#undef key_046
	#undef key_047
	#undef key_048
	#undef key_049
	#undef key_050
	#undef key_051
	#undef key_052
	#undef key_053
	#undef key_054
	#undef key_055
	#undef key_056
	#undef key_057
	#undef key_058
	#undef key_059
	#undef key_060
	#undef key_061
	#undef key_062
	#undef key_063
	#undef key_064
	#undef key_065
	#undef key_066
	#undef key_067
	#undef key_068
	#undef key_069
	#undef key_070
	#undef key_071
	#undef key_072
	#undef key_073
	#undef key_074
	#undef key_075
	#undef key_076
	#undef key_077
	#undef key_078
	#undef key_079
	#undef key_080
	#undef key_081
	#undef key_082
	#undef key_083
	#undef key_084
	#undef key_085
	#undef key_086
	#undef key_087
	#undef key_088
	#undef key_089
	#undef key_090
	#undef key_091
	#undef key_092
	#undef key_093
	#undef key_094
	#undef key_095
	#undef key_096
	#undef key_097
	#undef key_098
	#undef key_099
	#undef key_100
	#undef key_101
	#undef key_102
	#undef key_103
	#undef key_104
	#undef key_105
	#undef key_106
	#undef key_107
	#undef key_108
	#undef key_109
	#undef key_110
	#undef key_111
	#undef key_112
	#undef key_113
	#undef key_114
	#undef key_115
	#undef key_116
	#undef key_117
	#undef key_118
	#undef key_119
	#undef key_120
	#undef key_121
	#undef key_122
	#undef key_123
	#undef key_124
	#undef key_125
	#undef key_126
	#undef key_127
	#undef key_128
	#undef key_129
	#undef key_130
	#undef key_131
	#undef key_132
	#undef key_133
	#undef key_134
	#undef key_135
	#undef key_136
	#undef key_137
	#undef key_138
	#undef key_139
	#undef key_140
	#undef key_141
	#undef key_142
	#undef key_143
	#undef key_144
	#undef key_145
	#undef key_146
	#undef key_147
	#undef key_148
	#undef key_149
	#undef key_150
	#undef key_151
	#undef key_152
	#undef key_153
	#undef key_154
	#undef key_155
	#undef key_156
	#undef key_157
	#undef key_158
	#undef key_159
	#undef key_160
	#undef key_161
	#undef key_162
	#undef key_163
	#undef key_164
	#undef key_165
	#undef key_166
	#undef key_167
	#undef key_168
	#undef key_169
	#undef key_170
	#undef key_171
	#undef key_172
	#undef key_173
	#undef key_174
	#undef key_175
	#undef key_176
	#undef key_177
	#undef key_178
	#undef key_179
	#undef key_180
	#undef key_181
	#undef key_182
	#undef key_183
	#undef key_184
	#undef key_185
	#undef key_186
	#undef key_187
	#undef key_188
	#undef key_189
	#undef key_190
	#undef key_191
	#undef key_192
	#undef key_193
	#undef key_194
	#undef key_195
	#undef key_196
	#undef key_197
	#undef key_198
	#undef key_199
	#undef key_200
	#undef key_201
	#undef key_202
	#undef key_203
	#undef key_204
	#undef key_205
	#undef key_206
	#undef key_207
	#undef key_208
	#undef key_209
	#undef key_210
	#undef key_211
	#undef key_212
	#undef key_213
	#undef key_214
	#undef key_215
	#undef key_216
	#undef key_217
	#undef key_218
	#undef key_219
	#undef key_220
	#undef key_221
	#undef key_222
	#undef key_223
	#undef key_224
	#undef key_225
	#undef key_226
	#undef key_227
	#undef key_228
	#undef key_229
	#undef key_230
	#undef key_231
	#undef key_232
	#undef key_233
	#undef key_234
	#undef key_235
	#undef key_236
	#undef key_237
	#undef key_238
	#undef key_239
	#undef key_240
	#undef key_241
	#undef key_242
	#undef key_243
	#undef key_244
	#undef key_245
	#undef key_246
	#undef key_247
	#undef key_248
	#undef key_249
	#undef key_250
	#undef key_251
	#undef key_252
	#undef key_253
	#undef key_254
	#undef key_255
	#undef key_256
	#undef key_257
	#undef key_258
	#undef key_259
	#undef key_260
	#undef key_261
	#undef key_262
	#undef key_263
	#undef key_264
	#undef key_265
	#undef key_266
	#undef key_267
	#undef key_268
	#undef key_269

	#undef msg_000
	#undef msg_001
	#undef msg_002
	#undef msg_003
	#undef msg_004
	#undef msg_005
	#undef msg_006
	#undef msg_007
	#undef msg_008
	#undef msg_009
	#undef msg_010
	#undef msg_011
	#undef msg_012
	#undef msg_013
	#undef msg_014
	#undef msg_015
	#undef msg_016
	#undef msg_017
	#undef msg_018
	#undef msg_019
	#undef msg_020
	#undef msg_021
	#undef msg_022
	#undef msg_023
	#undef msg_024
	#undef msg_025
	#undef msg_026
	#undef msg_027
	#undef msg_028
	#undef msg_029
	#undef msg_030
	#undef msg_031
	#undef msg_032
	#undef msg_033
	#undef msg_034
	#undef msg_035
	#undef msg_036
	#undef msg_037
	#undef msg_038
	#undef msg_039
	#undef msg_040
	#undef msg_041
	#undef msg_042
	#undef msg_043
	#undef msg_044
	#undef msg_045
	#undef msg_046
	#undef msg_047
	#undef msg_048
	#undef msg_049
	#undef msg_050
	#undef msg_051
	#undef msg_052
	#undef msg_053
	#undef msg_054
	#undef msg_055
	#undef msg_056
	#undef msg_057
	#undef msg_058
	#undef msg_059
	#undef msg_060
	#undef msg_061
	#undef msg_062
	#undef msg_063
	#undef msg_064
	#undef msg_065
	#undef msg_066
	#undef msg_067
	#undef msg_068
	#undef msg_069
	#undef msg_070
	#undef msg_071
	#undef msg_072
	#undef msg_073
	#undef msg_074
	#undef msg_075
	#undef msg_076
	#undef msg_077
	#undef msg_078
	#undef msg_079
	#undef msg_080
	#undef msg_081
	#undef msg_082
	#undef msg_083
	#undef msg_084
	#undef msg_085
	#undef msg_086
	#undef msg_087
	#undef msg_088
	#undef msg_089
	#undef msg_090
	#undef msg_091
	#undef msg_092
	#undef msg_093
	#undef msg_094
	#undef msg_095
	#undef msg_096
	#undef msg_097
	#undef msg_098
	#undef msg_099
	#undef msg_100
	#undef msg_101
	#undef msg_102
	#undef msg_103
	#undef msg_104
	#undef msg_105
	#undef msg_106
	#undef msg_107
	#undef msg_108
	#undef msg_109
	#undef msg_110
	#undef msg_111
	#undef msg_112
	#undef msg_113
	#undef msg_114
	#undef msg_115
	#undef msg_116
	#undef msg_117
	#undef msg_118
	#undef msg_119
	#undef msg_120
	#undef msg_121
	#undef msg_122
	#undef msg_123
	#undef msg_124
	#undef msg_125
	#undef msg_126
	#undef msg_127
	#undef msg_128
	#undef msg_129
	#undef msg_130
	#undef msg_131
	#undef msg_132
	#undef msg_133
	#undef msg_134
	#undef msg_135
	#undef msg_136
	#undef msg_137
	#undef msg_138
	#undef msg_139
	#undef msg_140
	#undef msg_141
	#undef msg_142
	#undef msg_143
	#undef msg_144
	#undef msg_145
	#undef msg_146
	#undef msg_147
	#undef msg_148
	#undef msg_149
	#undef msg_150
	#undef msg_151
	#undef msg_152
	#undef msg_153
	#undef msg_154
	#undef msg_155
	#undef msg_156
	#undef msg_157
	#undef msg_158
	#undef msg_159
	#undef msg_160
	#undef msg_161
	#undef msg_162
	#undef msg_163
	#undef msg_164
	#undef msg_165
	#undef msg_166
	#undef msg_167
	#undef msg_168
	#undef msg_169
	#undef msg_170
	#undef msg_171
	#undef msg_172
	#undef msg_173
	#undef msg_174
	#undef msg_175
	#undef msg_176
	#undef msg_177
	#undef msg_178
	#undef msg_179
	#undef msg_180
	#undef msg_181
	#undef msg_182
	#undef msg_183
	#undef msg_184
	#undef msg_185
	#undef msg_186
	#undef msg_187
	#undef msg_188
	#undef msg_189
	#undef msg_190
	#undef msg_191
	#undef msg_192
	#undef msg_193
	#undef msg_194
	#undef msg_195
	#undef msg_196
	#undef msg_197
	#undef msg_198
	#undef msg_199
	#undef msg_200
	#undef msg_201
	#undef msg_202
	#undef msg_203
	#undef msg_204
	#undef msg_205
	#undef msg_206
	#undef msg_207
	#undef msg_208
	#undef msg_209
	#undef msg_210
	#undef msg_211
	#undef msg_212
	#undef msg_213
	#undef msg_214
	#undef msg_215
	#undef msg_216
	#undef msg_217
	#undef msg_218
	#undef msg_219
	#undef msg_220
	#undef msg_221
	#undef msg_222
	#undef msg_223
	#undef msg_224
	#undef msg_225
	#undef msg_226
	#undef msg_227
	#undef msg_228
	#undef msg_229
	#undef msg_230
	#undef msg_231
	#undef msg_232
	#undef msg_233
	#undef msg_234
	#undef msg_235
	#undef msg_236
	#undef msg_237
	#undef msg_238
	#undef msg_239
	#undef msg_240
	#undef msg_241
	#undef msg_242
	#undef msg_243
	#undef msg_244
	#undef msg_245
	#undef msg_246
	#undef msg_247
	#undef msg_248
	#undef msg_249
	#undef msg_250
	#undef msg_251
	#undef msg_252
	#undef msg_253
	#undef msg_254
	#undef msg_255
	#undef msg_256
	#undef msg_257
	#undef msg_258
	#undef msg_259
	#undef msg_260
	#undef msg_261
	#undef msg_262
	#undef msg_263
	#undef msg_264
	#undef msg_265
	#undef msg_266
	#undef msg_267
	#undef msg_268
	#undef msg_269

	#undef out_000
	#undef out_001
	#undef out_002
	#undef out_003
	#undef out_004
	#undef out_005
	#undef out_006
	#undef out_007
	#undef out_008
	#undef out_009
	#undef out_010
	#undef out_011
	#undef out_012
	#undef out_013
	#undef out_014
	#undef out_015
	#undef out_016
	#undef out_017
	#undef out_018
	#undef out_019
	#undef out_020
	#undef out_021
	#undef out_022
	#undef out_023
	#undef out_024
	#undef out_025
	#undef out_026
	#undef out_027
	#undef out_028
	#undef out_029
	#undef out_030
	#undef out_031
	#undef out_032
	#undef out_033
	#undef out_034
	#undef out_035
	#undef out_036
	#undef out_037
	#undef out_038
	#undef out_039
	#undef out_040
	#undef out_041
	#undef out_042
	#undef out_043
	#undef out_044
	#undef out_045
	#undef out_046
	#undef out_047
	#undef out_048
	#undef out_049
	#undef out_050
	#undef out_051
	#undef out_052
	#undef out_053
	#undef out_054
	#undef out_055
	#undef out_056
	#undef out_057
	#undef out_058
	#undef out_059
	#undef out_060
	#undef out_061
	#undef out_062
	#undef out_063
	#undef out_064
	#undef out_065
	#undef out_066
	#undef out_067
	#undef out_068
	#undef out_069
	#undef out_070
	#undef out_071
	#undef out_072
	#undef out_073
	#undef out_074
	#undef out_075
	#undef out_076
	#undef out_077
	#undef out_078
	#undef out_079
	#undef out_080
	#undef out_081
	#undef out_082
	#undef out_083
	#undef out_084
	#undef out_085
	#undef out_086
	#undef out_087
	#undef out_088
	#undef out_089
	#undef out_090
	#undef out_091
	#undef out_092
	#undef out_093
	#undef out_094
	#undef out_095
	#undef out_096
	#undef out_097
	#undef out_098
	#undef out_099
	#undef out_100
	#undef out_101
	#undef out_102
	#undef out_103
	#undef out_104
	#undef out_105
	#undef out_106
	#undef out_107
	#undef out_108
	#undef out_109
	#undef out_110
	#undef out_111
	#undef out_112
	#undef out_113
	#undef out_114
	#undef out_115
	#undef out_116
	#undef out_117
	#undef out_118
	#undef out_119
	#undef out_120
	#undef out_121
	#undef out_122
	#undef out_123
	#undef out_124
	#undef out_125
	#undef out_126
	#undef out_127
	#undef out_128
	#undef out_129
	#undef out_130
	#undef out_131
	#undef out_132
	#undef out_133
	#undef out_134
	#undef out_135
	#undef out_136
	#undef out_137
	#undef out_138
	#undef out_139
	#undef out_140
	#undef out_141
	#undef out_142
	#undef out_143
	#undef out_144
	#undef out_145
	#undef out_146
	#undef out_147
	#undef out_148
	#undef out_149
	#undef out_150
	#undef out_151
	#undef out_152
	#undef out_153
	#undef out_154
	#undef out_155
	#undef out_156
	#undef out_157
	#undef out_158
	#undef out_159
	#undef out_160
	#undef out_161
	#undef out_162
	#undef out_163
	#undef out_164
	#undef out_165
	#undef out_166
	#undef out_167
	#undef out_168
	#undef out_169
	#undef out_170
	#undef out_171
	#undef out_172
	#undef out_173
	#undef out_174
	#undef out_175
	#undef out_176
	#undef out_177
	#undef out_178
	#undef out_179
	#undef out_180
	#undef out_181
	#undef out_182
	#undef out_183
	#undef out_184
	#undef out_185
	#undef out_186
	#undef out_187
	#undef out_188
	#undef out_189
	#undef out_190
	#undef out_191
	#undef out_192
	#undef out_193
	#undef out_194
	#undef out_195
	#undef out_196
	#undef out_197
	#undef out_198
	#undef out_199
	#undef out_200
	#undef out_201
	#undef out_202
	#undef out_203
	#undef out_204
	#undef out_205
	#undef out_206
	#undef out_207
	#undef out_208
	#undef out_209
	#undef out_210
	#undef out_211
	#undef out_212
	#undef out_213
	#undef out_214
	#undef out_215
	#undef out_216
	#undef out_217
	#undef out_218
	#undef out_219
	#undef out_220
	#undef out_221
	#undef out_222
	#undef out_223
	#undef out_224
	#undef out_225
	#undef out_226
	#undef out_227
	#undef out_228
	#undef out_229
	#undef out_230
	#undef out_231
	#undef out_232
	#undef out_233
	#undef out_234
	#undef out_235
	#undef out_236
	#undef out_237
	#undef out_238
	#undef out_239
	#undef out_240
	#undef out_241
	#undef out_242
	#undef out_243
	#undef out_244
	#undef out_245
	#undef out_246
	#undef out_247
	#undef out_248
	#undef out_249
	#undef out_250
	#undef out_251
	#undef out_252
	#undef out_253
	#undef out_254
	#undef out_255
	#undef out_256
	#undef out_257
	#undef out_258
	#undef out_259
	#undef out_260
	#undef out_261
	#undef out_262
	#undef out_263
	#undef out_264
	#undef out_265
	#undef out_266
	#undef out_267
	#undef out_268
	#undef out_269
}
