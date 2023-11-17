#include "mk_lib_crypto_hash_block_streebog_base.h"

/* http://tc26.ru/research/polozhenie/GOST_R_34_11-2012_eng.pdf */

#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#define mk_sl_cui_uint64_cc(a, b) mk_sl_cui_uint64_c \
( \
	( \
		((((b) >> (0 * 8)) & 0xfful) << (3 * 8)) | \
		((((b) >> (1 * 8)) & 0xfful) << (2 * 8)) | \
		((((b) >> (2 * 8)) & 0xfful) << (1 * 8)) | \
		((((b) >> (3 * 8)) & 0xfful) << (0 * 8)) \
	), \
	( \
		((((a) >> (0 * 8)) & 0xfful) << (3 * 8)) | \
		((((a) >> (1 * 8)) & 0xfful) << (2 * 8)) | \
		((((a) >> (2 * 8)) & 0xfful) << (1 * 8)) | \
		((((a) >> (3 * 8)) & 0xfful) << (0 * 8)) \
	) \
)
#define mk_lib_crypto_hash_block_streebog_base_swap_8(a, b, c, d, e, f, g, h) h, g, f, e, d, c, b, a


#define s_mk_lib_crypto_hash_block_streebog_base_nrounds 12

mk_lang_constexpr_static_inline mk_sl_cui_uint8_t const s_mk_lib_crypto_hash_block_streebog_base_table_pi[0xff + 0x01] =
{
	mk_sl_cui_uint8_c(0xfcul), mk_sl_cui_uint8_c(0xeeul), mk_sl_cui_uint8_c(0xddul), mk_sl_cui_uint8_c(0x11ul), mk_sl_cui_uint8_c(0xcful), mk_sl_cui_uint8_c(0x6eul), mk_sl_cui_uint8_c(0x31ul), mk_sl_cui_uint8_c(0x16ul), mk_sl_cui_uint8_c(0xfbul), mk_sl_cui_uint8_c(0xc4ul), mk_sl_cui_uint8_c(0xfaul), mk_sl_cui_uint8_c(0xdaul), mk_sl_cui_uint8_c(0x23ul), mk_sl_cui_uint8_c(0xc5ul), mk_sl_cui_uint8_c(0x04ul), mk_sl_cui_uint8_c(0x4dul),
	mk_sl_cui_uint8_c(0xe9ul), mk_sl_cui_uint8_c(0x77ul), mk_sl_cui_uint8_c(0xf0ul), mk_sl_cui_uint8_c(0xdbul), mk_sl_cui_uint8_c(0x93ul), mk_sl_cui_uint8_c(0x2eul), mk_sl_cui_uint8_c(0x99ul), mk_sl_cui_uint8_c(0xbaul), mk_sl_cui_uint8_c(0x17ul), mk_sl_cui_uint8_c(0x36ul), mk_sl_cui_uint8_c(0xf1ul), mk_sl_cui_uint8_c(0xbbul), mk_sl_cui_uint8_c(0x14ul), mk_sl_cui_uint8_c(0xcdul), mk_sl_cui_uint8_c(0x5ful), mk_sl_cui_uint8_c(0xc1ul),
	mk_sl_cui_uint8_c(0xf9ul), mk_sl_cui_uint8_c(0x18ul), mk_sl_cui_uint8_c(0x65ul), mk_sl_cui_uint8_c(0x5aul), mk_sl_cui_uint8_c(0xe2ul), mk_sl_cui_uint8_c(0x5cul), mk_sl_cui_uint8_c(0xeful), mk_sl_cui_uint8_c(0x21ul), mk_sl_cui_uint8_c(0x81ul), mk_sl_cui_uint8_c(0x1cul), mk_sl_cui_uint8_c(0x3cul), mk_sl_cui_uint8_c(0x42ul), mk_sl_cui_uint8_c(0x8bul), mk_sl_cui_uint8_c(0x01ul), mk_sl_cui_uint8_c(0x8eul), mk_sl_cui_uint8_c(0x4ful),
	mk_sl_cui_uint8_c(0x05ul), mk_sl_cui_uint8_c(0x84ul), mk_sl_cui_uint8_c(0x02ul), mk_sl_cui_uint8_c(0xaeul), mk_sl_cui_uint8_c(0xe3ul), mk_sl_cui_uint8_c(0x6aul), mk_sl_cui_uint8_c(0x8ful), mk_sl_cui_uint8_c(0xa0ul), mk_sl_cui_uint8_c(0x06ul), mk_sl_cui_uint8_c(0x0bul), mk_sl_cui_uint8_c(0xedul), mk_sl_cui_uint8_c(0x98ul), mk_sl_cui_uint8_c(0x7ful), mk_sl_cui_uint8_c(0xd4ul), mk_sl_cui_uint8_c(0xd3ul), mk_sl_cui_uint8_c(0x1ful),
	mk_sl_cui_uint8_c(0xebul), mk_sl_cui_uint8_c(0x34ul), mk_sl_cui_uint8_c(0x2cul), mk_sl_cui_uint8_c(0x51ul), mk_sl_cui_uint8_c(0xeaul), mk_sl_cui_uint8_c(0xc8ul), mk_sl_cui_uint8_c(0x48ul), mk_sl_cui_uint8_c(0xabul), mk_sl_cui_uint8_c(0xf2ul), mk_sl_cui_uint8_c(0x2aul), mk_sl_cui_uint8_c(0x68ul), mk_sl_cui_uint8_c(0xa2ul), mk_sl_cui_uint8_c(0xfdul), mk_sl_cui_uint8_c(0x3aul), mk_sl_cui_uint8_c(0xceul), mk_sl_cui_uint8_c(0xccul),
	mk_sl_cui_uint8_c(0xb5ul), mk_sl_cui_uint8_c(0x70ul), mk_sl_cui_uint8_c(0x0eul), mk_sl_cui_uint8_c(0x56ul), mk_sl_cui_uint8_c(0x08ul), mk_sl_cui_uint8_c(0x0cul), mk_sl_cui_uint8_c(0x76ul), mk_sl_cui_uint8_c(0x12ul), mk_sl_cui_uint8_c(0xbful), mk_sl_cui_uint8_c(0x72ul), mk_sl_cui_uint8_c(0x13ul), mk_sl_cui_uint8_c(0x47ul), mk_sl_cui_uint8_c(0x9cul), mk_sl_cui_uint8_c(0xb7ul), mk_sl_cui_uint8_c(0x5dul), mk_sl_cui_uint8_c(0x87ul),
	mk_sl_cui_uint8_c(0x15ul), mk_sl_cui_uint8_c(0xa1ul), mk_sl_cui_uint8_c(0x96ul), mk_sl_cui_uint8_c(0x29ul), mk_sl_cui_uint8_c(0x10ul), mk_sl_cui_uint8_c(0x7bul), mk_sl_cui_uint8_c(0x9aul), mk_sl_cui_uint8_c(0xc7ul), mk_sl_cui_uint8_c(0xf3ul), mk_sl_cui_uint8_c(0x91ul), mk_sl_cui_uint8_c(0x78ul), mk_sl_cui_uint8_c(0x6ful), mk_sl_cui_uint8_c(0x9dul), mk_sl_cui_uint8_c(0x9eul), mk_sl_cui_uint8_c(0xb2ul), mk_sl_cui_uint8_c(0xb1ul),
	mk_sl_cui_uint8_c(0x32ul), mk_sl_cui_uint8_c(0x75ul), mk_sl_cui_uint8_c(0x19ul), mk_sl_cui_uint8_c(0x3dul), mk_sl_cui_uint8_c(0xfful), mk_sl_cui_uint8_c(0x35ul), mk_sl_cui_uint8_c(0x8aul), mk_sl_cui_uint8_c(0x7eul), mk_sl_cui_uint8_c(0x6dul), mk_sl_cui_uint8_c(0x54ul), mk_sl_cui_uint8_c(0xc6ul), mk_sl_cui_uint8_c(0x80ul), mk_sl_cui_uint8_c(0xc3ul), mk_sl_cui_uint8_c(0xbdul), mk_sl_cui_uint8_c(0x0dul), mk_sl_cui_uint8_c(0x57ul),
	mk_sl_cui_uint8_c(0xdful), mk_sl_cui_uint8_c(0xf5ul), mk_sl_cui_uint8_c(0x24ul), mk_sl_cui_uint8_c(0xa9ul), mk_sl_cui_uint8_c(0x3eul), mk_sl_cui_uint8_c(0xa8ul), mk_sl_cui_uint8_c(0x43ul), mk_sl_cui_uint8_c(0xc9ul), mk_sl_cui_uint8_c(0xd7ul), mk_sl_cui_uint8_c(0x79ul), mk_sl_cui_uint8_c(0xd6ul), mk_sl_cui_uint8_c(0xf6ul), mk_sl_cui_uint8_c(0x7cul), mk_sl_cui_uint8_c(0x22ul), mk_sl_cui_uint8_c(0xb9ul), mk_sl_cui_uint8_c(0x03ul),
	mk_sl_cui_uint8_c(0xe0ul), mk_sl_cui_uint8_c(0x0ful), mk_sl_cui_uint8_c(0xecul), mk_sl_cui_uint8_c(0xdeul), mk_sl_cui_uint8_c(0x7aul), mk_sl_cui_uint8_c(0x94ul), mk_sl_cui_uint8_c(0xb0ul), mk_sl_cui_uint8_c(0xbcul), mk_sl_cui_uint8_c(0xdcul), mk_sl_cui_uint8_c(0xe8ul), mk_sl_cui_uint8_c(0x28ul), mk_sl_cui_uint8_c(0x50ul), mk_sl_cui_uint8_c(0x4eul), mk_sl_cui_uint8_c(0x33ul), mk_sl_cui_uint8_c(0x0aul), mk_sl_cui_uint8_c(0x4aul),
	mk_sl_cui_uint8_c(0xa7ul), mk_sl_cui_uint8_c(0x97ul), mk_sl_cui_uint8_c(0x60ul), mk_sl_cui_uint8_c(0x73ul), mk_sl_cui_uint8_c(0x1eul), mk_sl_cui_uint8_c(0x00ul), mk_sl_cui_uint8_c(0x62ul), mk_sl_cui_uint8_c(0x44ul), mk_sl_cui_uint8_c(0x1aul), mk_sl_cui_uint8_c(0xb8ul), mk_sl_cui_uint8_c(0x38ul), mk_sl_cui_uint8_c(0x82ul), mk_sl_cui_uint8_c(0x64ul), mk_sl_cui_uint8_c(0x9ful), mk_sl_cui_uint8_c(0x26ul), mk_sl_cui_uint8_c(0x41ul),
	mk_sl_cui_uint8_c(0xadul), mk_sl_cui_uint8_c(0x45ul), mk_sl_cui_uint8_c(0x46ul), mk_sl_cui_uint8_c(0x92ul), mk_sl_cui_uint8_c(0x27ul), mk_sl_cui_uint8_c(0x5eul), mk_sl_cui_uint8_c(0x55ul), mk_sl_cui_uint8_c(0x2ful), mk_sl_cui_uint8_c(0x8cul), mk_sl_cui_uint8_c(0xa3ul), mk_sl_cui_uint8_c(0xa5ul), mk_sl_cui_uint8_c(0x7dul), mk_sl_cui_uint8_c(0x69ul), mk_sl_cui_uint8_c(0xd5ul), mk_sl_cui_uint8_c(0x95ul), mk_sl_cui_uint8_c(0x3bul),
	mk_sl_cui_uint8_c(0x07ul), mk_sl_cui_uint8_c(0x58ul), mk_sl_cui_uint8_c(0xb3ul), mk_sl_cui_uint8_c(0x40ul), mk_sl_cui_uint8_c(0x86ul), mk_sl_cui_uint8_c(0xacul), mk_sl_cui_uint8_c(0x1dul), mk_sl_cui_uint8_c(0xf7ul), mk_sl_cui_uint8_c(0x30ul), mk_sl_cui_uint8_c(0x37ul), mk_sl_cui_uint8_c(0x6bul), mk_sl_cui_uint8_c(0xe4ul), mk_sl_cui_uint8_c(0x88ul), mk_sl_cui_uint8_c(0xd9ul), mk_sl_cui_uint8_c(0xe7ul), mk_sl_cui_uint8_c(0x89ul),
	mk_sl_cui_uint8_c(0xe1ul), mk_sl_cui_uint8_c(0x1bul), mk_sl_cui_uint8_c(0x83ul), mk_sl_cui_uint8_c(0x49ul), mk_sl_cui_uint8_c(0x4cul), mk_sl_cui_uint8_c(0x3ful), mk_sl_cui_uint8_c(0xf8ul), mk_sl_cui_uint8_c(0xfeul), mk_sl_cui_uint8_c(0x8dul), mk_sl_cui_uint8_c(0x53ul), mk_sl_cui_uint8_c(0xaaul), mk_sl_cui_uint8_c(0x90ul), mk_sl_cui_uint8_c(0xcaul), mk_sl_cui_uint8_c(0xd8ul), mk_sl_cui_uint8_c(0x85ul), mk_sl_cui_uint8_c(0x61ul),
	mk_sl_cui_uint8_c(0x20ul), mk_sl_cui_uint8_c(0x71ul), mk_sl_cui_uint8_c(0x67ul), mk_sl_cui_uint8_c(0xa4ul), mk_sl_cui_uint8_c(0x2dul), mk_sl_cui_uint8_c(0x2bul), mk_sl_cui_uint8_c(0x09ul), mk_sl_cui_uint8_c(0x5bul), mk_sl_cui_uint8_c(0xcbul), mk_sl_cui_uint8_c(0x9bul), mk_sl_cui_uint8_c(0x25ul), mk_sl_cui_uint8_c(0xd0ul), mk_sl_cui_uint8_c(0xbeul), mk_sl_cui_uint8_c(0xe5ul), mk_sl_cui_uint8_c(0x6cul), mk_sl_cui_uint8_c(0x52ul),
	mk_sl_cui_uint8_c(0x59ul), mk_sl_cui_uint8_c(0xa6ul), mk_sl_cui_uint8_c(0x74ul), mk_sl_cui_uint8_c(0xd2ul), mk_sl_cui_uint8_c(0xe6ul), mk_sl_cui_uint8_c(0xf4ul), mk_sl_cui_uint8_c(0xb4ul), mk_sl_cui_uint8_c(0xc0ul), mk_sl_cui_uint8_c(0xd1ul), mk_sl_cui_uint8_c(0x66ul), mk_sl_cui_uint8_c(0xaful), mk_sl_cui_uint8_c(0xc2ul), mk_sl_cui_uint8_c(0x39ul), mk_sl_cui_uint8_c(0x4bul), mk_sl_cui_uint8_c(0x63ul), mk_sl_cui_uint8_c(0xb6ul),
};

mk_lang_constexpr_static_inline mk_sl_cui_uint8_t const s_mk_lib_crypto_hash_block_streebog_base_table_tau[64] =
{
	mk_sl_cui_uint8_c(0x00ul), mk_sl_cui_uint8_c(0x08ul), mk_sl_cui_uint8_c(0x10ul), mk_sl_cui_uint8_c(0x18ul), mk_sl_cui_uint8_c(0x20ul), mk_sl_cui_uint8_c(0x28ul), mk_sl_cui_uint8_c(0x30ul), mk_sl_cui_uint8_c(0x38ul),
	mk_sl_cui_uint8_c(0x01ul), mk_sl_cui_uint8_c(0x09ul), mk_sl_cui_uint8_c(0x11ul), mk_sl_cui_uint8_c(0x19ul), mk_sl_cui_uint8_c(0x21ul), mk_sl_cui_uint8_c(0x29ul), mk_sl_cui_uint8_c(0x31ul), mk_sl_cui_uint8_c(0x39ul),
	mk_sl_cui_uint8_c(0x02ul), mk_sl_cui_uint8_c(0x0aul), mk_sl_cui_uint8_c(0x12ul), mk_sl_cui_uint8_c(0x1aul), mk_sl_cui_uint8_c(0x22ul), mk_sl_cui_uint8_c(0x2aul), mk_sl_cui_uint8_c(0x32ul), mk_sl_cui_uint8_c(0x3aul),
	mk_sl_cui_uint8_c(0x03ul), mk_sl_cui_uint8_c(0x0bul), mk_sl_cui_uint8_c(0x13ul), mk_sl_cui_uint8_c(0x1bul), mk_sl_cui_uint8_c(0x23ul), mk_sl_cui_uint8_c(0x2bul), mk_sl_cui_uint8_c(0x33ul), mk_sl_cui_uint8_c(0x3bul),
	mk_sl_cui_uint8_c(0x04ul), mk_sl_cui_uint8_c(0x0cul), mk_sl_cui_uint8_c(0x14ul), mk_sl_cui_uint8_c(0x1cul), mk_sl_cui_uint8_c(0x24ul), mk_sl_cui_uint8_c(0x2cul), mk_sl_cui_uint8_c(0x34ul), mk_sl_cui_uint8_c(0x3cul),
	mk_sl_cui_uint8_c(0x05ul), mk_sl_cui_uint8_c(0x0dul), mk_sl_cui_uint8_c(0x15ul), mk_sl_cui_uint8_c(0x1dul), mk_sl_cui_uint8_c(0x25ul), mk_sl_cui_uint8_c(0x2dul), mk_sl_cui_uint8_c(0x35ul), mk_sl_cui_uint8_c(0x3dul),
	mk_sl_cui_uint8_c(0x06ul), mk_sl_cui_uint8_c(0x0eul), mk_sl_cui_uint8_c(0x16ul), mk_sl_cui_uint8_c(0x1eul), mk_sl_cui_uint8_c(0x26ul), mk_sl_cui_uint8_c(0x2eul), mk_sl_cui_uint8_c(0x36ul), mk_sl_cui_uint8_c(0x3eul),
	mk_sl_cui_uint8_c(0x07ul), mk_sl_cui_uint8_c(0x0ful), mk_sl_cui_uint8_c(0x17ul), mk_sl_cui_uint8_c(0x1ful), mk_sl_cui_uint8_c(0x27ul), mk_sl_cui_uint8_c(0x2ful), mk_sl_cui_uint8_c(0x37ul), mk_sl_cui_uint8_c(0x3ful),
};

mk_lang_constexpr_static_inline mk_sl_cui_uint64_t const s_mk_lib_crypto_hash_block_streebog_base_table_a[64] =
{
	mk_sl_cui_uint64_c(0x8e20faa7ul, 0x2ba0b470ul), mk_sl_cui_uint64_c(0x47107dddul, 0x9b505a38ul), mk_sl_cui_uint64_c(0xad08b0e0ul, 0xc3282d1cul), mk_sl_cui_uint64_c(0xd8045870ul, 0xef14980eul),
	mk_sl_cui_uint64_c(0x6c022c38ul, 0xf90a4c07ul), mk_sl_cui_uint64_c(0x3601161cul, 0xf205268dul), mk_sl_cui_uint64_c(0x1b8e0b0eul, 0x798c13c8ul), mk_sl_cui_uint64_c(0x83478b07ul, 0xb2468764ul),
	mk_sl_cui_uint64_c(0xa011d380ul, 0x818e8f40ul), mk_sl_cui_uint64_c(0x5086e740ul, 0xce47c920ul), mk_sl_cui_uint64_c(0x2843fd20ul, 0x67adea10ul), mk_sl_cui_uint64_c(0x14aff010ul, 0xbdd87508ul),
	mk_sl_cui_uint64_c(0x0ad97808ul, 0xd06cb404ul), mk_sl_cui_uint64_c(0x05e23c04ul, 0x68365a02ul), mk_sl_cui_uint64_c(0x8c711e02ul, 0x341b2d01ul), mk_sl_cui_uint64_c(0x46b60f01ul, 0x1a83988eul),
	mk_sl_cui_uint64_c(0x90dab52aul, 0x387ae76ful), mk_sl_cui_uint64_c(0x486dd415ul, 0x1c3dfdb9ul), mk_sl_cui_uint64_c(0x24b86a84ul, 0x0e90f0d2ul), mk_sl_cui_uint64_c(0x125c3542ul, 0x07487869ul),
	mk_sl_cui_uint64_c(0x092e9421ul, 0x8d243cbaul), mk_sl_cui_uint64_c(0x8a174a9eul, 0xc8121e5dul), mk_sl_cui_uint64_c(0x4585254ful, 0x64090fa0ul), mk_sl_cui_uint64_c(0xaccc9ca9ul, 0x328a8950ul),
	mk_sl_cui_uint64_c(0x9d4df05dul, 0x5f661451ul), mk_sl_cui_uint64_c(0xc0a878a0ul, 0xa1330aa6ul), mk_sl_cui_uint64_c(0x60543c50ul, 0xde970553ul), mk_sl_cui_uint64_c(0x302a1e28ul, 0x6fc58ca7ul),
	mk_sl_cui_uint64_c(0x18150f14ul, 0xb9ec46ddul), mk_sl_cui_uint64_c(0x0c84890aul, 0xd27623e0ul), mk_sl_cui_uint64_c(0x0642ca05ul, 0x693b9f70ul), mk_sl_cui_uint64_c(0x0321658cul, 0xba93c138ul),
	mk_sl_cui_uint64_c(0x86275df0ul, 0x9ce8aaa8ul), mk_sl_cui_uint64_c(0x439da078ul, 0x4e745554ul), mk_sl_cui_uint64_c(0xafc0503cul, 0x273aa42aul), mk_sl_cui_uint64_c(0xd960281eul, 0x9d1d5215ul),
	mk_sl_cui_uint64_c(0xe230140ful, 0xc0802984ul), mk_sl_cui_uint64_c(0x71180a89ul, 0x60409a42ul), mk_sl_cui_uint64_c(0xb60c05caul, 0x30204d21ul), mk_sl_cui_uint64_c(0x5b068c65ul, 0x1810a89eul),
	mk_sl_cui_uint64_c(0x456c3488ul, 0x7a3805b9ul), mk_sl_cui_uint64_c(0xac361a44ul, 0x3d1c8cd2ul), mk_sl_cui_uint64_c(0x561b0d22ul, 0x900e4669ul), mk_sl_cui_uint64_c(0x2b838811ul, 0x480723baul),
	mk_sl_cui_uint64_c(0x9bcf4486ul, 0x248d9f5dul), mk_sl_cui_uint64_c(0xc3e92243ul, 0x12c8c1a0ul), mk_sl_cui_uint64_c(0xeffa11aful, 0x0964ee50ul), mk_sl_cui_uint64_c(0xf97d86d9ul, 0x8a327728ul),
	mk_sl_cui_uint64_c(0xe4fa2054ul, 0xa80b329cul), mk_sl_cui_uint64_c(0x727d102aul, 0x548b194eul), mk_sl_cui_uint64_c(0x39b00815ul, 0x2acb8227ul), mk_sl_cui_uint64_c(0x92580484ul, 0x15eb419dul),
	mk_sl_cui_uint64_c(0x492c0242ul, 0x84fbaec0ul), mk_sl_cui_uint64_c(0xaa160121ul, 0x42f35760ul), mk_sl_cui_uint64_c(0x550b8e9eul, 0x21f7a530ul), mk_sl_cui_uint64_c(0xa48b474ful, 0x9ef5dc18ul),
	mk_sl_cui_uint64_c(0x70a6a56eul, 0x2440598eul), mk_sl_cui_uint64_c(0x3853dc37ul, 0x1220a247ul), mk_sl_cui_uint64_c(0x1ca76e95ul, 0x091051adul), mk_sl_cui_uint64_c(0x0edd37c4ul, 0x8a08a6d8ul),
	mk_sl_cui_uint64_c(0x07e09562ul, 0x4504536cul), mk_sl_cui_uint64_c(0x8d70c431ul, 0xac02a736ul), mk_sl_cui_uint64_c(0xc8386296ul, 0x5601dd1bul), mk_sl_cui_uint64_c(0x641c314bul, 0x2b8ee083ul),
};

mk_lang_constexpr_static_inline mk_lib_crypto_hash_block_streebog_base_block2_t const s_mk_lib_crypto_hash_block_streebog_base_table_c[12] =
{
	{{ mk_lib_crypto_hash_block_streebog_base_swap_8(mk_sl_cui_uint64_c(0xb1085bdaul, 0x1ecadae9ul), mk_sl_cui_uint64_c(0xebcb2f81ul, 0xc0657c1ful), mk_sl_cui_uint64_c(0x2f6a7643ul, 0x2e45d016ul), mk_sl_cui_uint64_c(0x714eb88dul, 0x7585c4fcul), mk_sl_cui_uint64_c(0x4b7ce091ul, 0x92676901ul), mk_sl_cui_uint64_c(0xa2422a08ul, 0xa460d315ul), mk_sl_cui_uint64_c(0x05767436ul, 0xcc744d23ul), mk_sl_cui_uint64_c(0xdd806559ul, 0xf2a64507ul)) }},
	{{ mk_lib_crypto_hash_block_streebog_base_swap_8(mk_sl_cui_uint64_c(0x6fa3b58aul, 0xa99d2f1aul), mk_sl_cui_uint64_c(0x4fe39d46ul, 0x0f70b5d7ul), mk_sl_cui_uint64_c(0xf3feea72ul, 0x0a232b98ul), mk_sl_cui_uint64_c(0x61d55e0ful, 0x16b50131ul), mk_sl_cui_uint64_c(0x9ab5176bul, 0x12d69958ul), mk_sl_cui_uint64_c(0x5cb561c2ul, 0xdb0aa7caul), mk_sl_cui_uint64_c(0x55dda21bul, 0xd7cbcd56ul), mk_sl_cui_uint64_c(0xe6790470ul, 0x21b19bb7ul)) }},
	{{ mk_lib_crypto_hash_block_streebog_base_swap_8(mk_sl_cui_uint64_c(0xf574dcacul, 0x2bce2fc7ul), mk_sl_cui_uint64_c(0x0a39fc28ul, 0x6a3d8435ul), mk_sl_cui_uint64_c(0x06f15e5ful, 0x529c1f8bul), mk_sl_cui_uint64_c(0xf2ea7514ul, 0xb1297b7bul), mk_sl_cui_uint64_c(0xd3e20fe4ul, 0x90359eb1ul), mk_sl_cui_uint64_c(0xc1c93a37ul, 0x6062db09ul), mk_sl_cui_uint64_c(0xc2b6f443ul, 0x867adb31ul), mk_sl_cui_uint64_c(0x991e96f5ul, 0x0aba0ab2ul)) }},
	{{ mk_lib_crypto_hash_block_streebog_base_swap_8(mk_sl_cui_uint64_c(0xef1fdfb3ul, 0xe81566d2ul), mk_sl_cui_uint64_c(0xf948e1a0ul, 0x5d71e4ddul), mk_sl_cui_uint64_c(0x488e857eul, 0x335c3c7dul), mk_sl_cui_uint64_c(0x9d721cadul, 0x685e353ful), mk_sl_cui_uint64_c(0xa9d72c82ul, 0xed03d675ul), mk_sl_cui_uint64_c(0xd8b71333ul, 0x935203beul), mk_sl_cui_uint64_c(0x3453eaa1ul, 0x93e837f1ul), mk_sl_cui_uint64_c(0x220cbebcul, 0x84e3d12eul)) }},
	{{ mk_lib_crypto_hash_block_streebog_base_swap_8(mk_sl_cui_uint64_c(0x4bea6bacul, 0xad474799ul), mk_sl_cui_uint64_c(0x9a3f410cul, 0x6ca92363ul), mk_sl_cui_uint64_c(0x7f151c1ful, 0x1686104aul), mk_sl_cui_uint64_c(0x359e35d7ul, 0x800fffbdul), mk_sl_cui_uint64_c(0xbfcd1747ul, 0x253af5a3ul), mk_sl_cui_uint64_c(0xdfff00b7ul, 0x23271a16ul), mk_sl_cui_uint64_c(0x7a56a27eul, 0xa9ea63f5ul), mk_sl_cui_uint64_c(0x601758fdul, 0x7c6cfe57ul)) }},
	{{ mk_lib_crypto_hash_block_streebog_base_swap_8(mk_sl_cui_uint64_c(0xae4faeaeul, 0x1d3ad3d9ul), mk_sl_cui_uint64_c(0x6fa4c33bul, 0x7a3039c0ul), mk_sl_cui_uint64_c(0x2d66c4f9ul, 0x5142a46cul), mk_sl_cui_uint64_c(0x187f9ab4ul, 0x9af08ec6ul), mk_sl_cui_uint64_c(0xcffaa6b7ul, 0x1c9ab7b4ul), mk_sl_cui_uint64_c(0x0af21f66ul, 0xc2bec6b6ul), mk_sl_cui_uint64_c(0xbf71c572ul, 0x36904f35ul), mk_sl_cui_uint64_c(0xfa68407aul, 0x46647d6eul)) }},
	{{ mk_lib_crypto_hash_block_streebog_base_swap_8(mk_sl_cui_uint64_c(0xf4c70e16ul, 0xeeaac5ecul), mk_sl_cui_uint64_c(0x51ac86feul, 0xbf240954ul), mk_sl_cui_uint64_c(0x399ec6c7ul, 0xe6bf87c9ul), mk_sl_cui_uint64_c(0xd3473e33ul, 0x197a93c9ul), mk_sl_cui_uint64_c(0x0992abc5ul, 0x2d822c37ul), mk_sl_cui_uint64_c(0x06476983ul, 0x284a0504ul), mk_sl_cui_uint64_c(0x3517454cul, 0xa23c4af3ul), mk_sl_cui_uint64_c(0x8886564dul, 0x3a14d493ul)) }},
	{{ mk_lib_crypto_hash_block_streebog_base_swap_8(mk_sl_cui_uint64_c(0x9b1f5b42ul, 0x4d93c9a7ul), mk_sl_cui_uint64_c(0x03e7aa02ul, 0x0c6e4141ul), mk_sl_cui_uint64_c(0x4eb7f871ul, 0x9c36de1eul), mk_sl_cui_uint64_c(0x89b4443bul, 0x4ddbc49aul), mk_sl_cui_uint64_c(0xf4892bcbul, 0x929b0690ul), mk_sl_cui_uint64_c(0x69d18d2bul, 0xd1a5c42ful), mk_sl_cui_uint64_c(0x36acc235ul, 0x5951a8d9ul), mk_sl_cui_uint64_c(0xa47f0dd4ul, 0xbf02e71eul)) }},
	{{ mk_lib_crypto_hash_block_streebog_base_swap_8(mk_sl_cui_uint64_c(0x378f5a54ul, 0x1631229bul), mk_sl_cui_uint64_c(0x944c9ad8ul, 0xec165fdeul), mk_sl_cui_uint64_c(0x3a7d3a1bul, 0x25894224ul), mk_sl_cui_uint64_c(0x3cd955b7ul, 0xe00d0984ul), mk_sl_cui_uint64_c(0x800a440bul, 0xdbb2ceb1ul), mk_sl_cui_uint64_c(0x7b2b8a9aul, 0xa6079c54ul), mk_sl_cui_uint64_c(0x0e38dc92ul, 0xcb1f2a60ul), mk_sl_cui_uint64_c(0x72614451ul, 0x83235adbul)) }},
	{{ mk_lib_crypto_hash_block_streebog_base_swap_8(mk_sl_cui_uint64_c(0xabbedea6ul, 0x80056f52ul), mk_sl_cui_uint64_c(0x382ae548ul, 0xb2e4f3f3ul), mk_sl_cui_uint64_c(0x8941e71cul, 0xff8a78dbul), mk_sl_cui_uint64_c(0x1fffe18aul, 0x1b336103ul), mk_sl_cui_uint64_c(0x9fe76702ul, 0xaf69334bul), mk_sl_cui_uint64_c(0x7a1e6c30ul, 0x3b7652f4ul), mk_sl_cui_uint64_c(0x3698fad1ul, 0x153bb6c3ul), mk_sl_cui_uint64_c(0x74b4c7fbul, 0x98459cedul)) }},
	{{ mk_lib_crypto_hash_block_streebog_base_swap_8(mk_sl_cui_uint64_c(0x7bcd9ed0ul, 0xefc889fbul), mk_sl_cui_uint64_c(0x3002c6cdul, 0x635afe94ul), mk_sl_cui_uint64_c(0xd8fa6bbbul, 0xebab0761ul), mk_sl_cui_uint64_c(0x20018021ul, 0x14846679ul), mk_sl_cui_uint64_c(0x8a1d71eful, 0xea48b9caul), mk_sl_cui_uint64_c(0xefbacd1dul, 0x7d476e98ul), mk_sl_cui_uint64_c(0xdea2594aul, 0xc06fd85dul), mk_sl_cui_uint64_c(0x6bcaa4cdul, 0x81f32d1bul)) }},
	{{ mk_lib_crypto_hash_block_streebog_base_swap_8(mk_sl_cui_uint64_c(0x378ee767ul, 0xf11631baul), mk_sl_cui_uint64_c(0xd21380b0ul, 0x0449b17aul), mk_sl_cui_uint64_c(0xcda43c32ul, 0xbcdf1d77ul), mk_sl_cui_uint64_c(0xf82012d4ul, 0x30219f9bul), mk_sl_cui_uint64_c(0x5d80ef9dul, 0x1891cc86ul), mk_sl_cui_uint64_c(0xe71da4aaul, 0x88e12852ul), mk_sl_cui_uint64_c(0xfaf417d5ul, 0xd9b21b99ul), mk_sl_cui_uint64_c(0x48bc924aul, 0xf11bd720ul)) }},
};


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_block2_from_u8s(mk_lib_crypto_hash_block_streebog_base_block2_pt const a, mk_lib_crypto_hash_block_streebog_base_block_pct const b) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != 8; ++i)
	{
		mk_sl_uint_64_from_8_le(&a->m_uint64s[i], &b->m_uint8s[i * 8]);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_block2_to_u8s(mk_lib_crypto_hash_block_streebog_base_block2_pct const a, mk_lib_crypto_hash_block_streebog_base_block_pt const b) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != 8; ++i)
	{
		mk_sl_uint_64_to_8_le(&a->m_uint64s[i], &b->m_uint8s[i * 8]);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_block2_from_bi_sint(mk_lib_crypto_hash_block_streebog_base_block2_pt const a, mk_lang_types_sint_pct const b) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint64_from_bi_sint(&a->m_uint64s[0], b);
	for(i = 1; i != 8; ++i)
	{
		mk_sl_cui_uint64_set_zero(&a->m_uint64s[i]);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_block2_add2(mk_lib_crypto_hash_block_streebog_base_block2_pt const a, mk_lib_crypto_hash_block_streebog_base_block2_pct const b) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_bool_t c mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	i = 0;
	mk_sl_cui_uint64_add2_wrap_cid_coe(&a->m_uint64s[i], &b->m_uint64s[i], &c);
	for(i = 0 + 1; i != 8 - 1; ++i)
	{
		mk_sl_cui_uint64_add2_wrap_cie_coe(&a->m_uint64s[i], &b->m_uint64s[i], c, &c);
	}
	mk_sl_cui_uint64_add2_wrap_cie_cod(&a->m_uint64s[i], &b->m_uint64s[i], c);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_block2_add_sint(mk_lib_crypto_hash_block_streebog_base_block2_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept
{
	mk_lang_types_sint_t nbits mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tu64 mk_lang_constexpr_init;
	mk_lang_types_bool_t c mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b >= 0);
	mk_lang_assert(b <= mk_lang_limits_sint_max / mk_lang_charbit);

	nbits = b * mk_lang_charbit;
	mk_sl_cui_uint64_from_bi_sint(&tu64, &nbits);
	mk_sl_cui_uint64_add2_wrap_cid_coe(&a->m_uint64s[0], &tu64, &c);
	if(c)
	{
		mk_sl_cui_uint64_inc1(&a->m_uint64s[1]);
		for(i = 0 + 2; i != 8 + 1 && mk_sl_cui_uint64_is_zero(&a->m_uint64s[i - 1]); ++i)
		{
			mk_sl_cui_uint64_inc1(&a->m_uint64s[i]);
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_block2_xor3(mk_lib_crypto_hash_block_streebog_base_block2_pct const a, mk_lib_crypto_hash_block_streebog_base_block2_pct const b, mk_lib_crypto_hash_block_streebog_base_block2_pt const c) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	for(i = 0; i != 8; ++i)
	{
		mk_sl_cui_uint64_xor3(&a->m_uint64s[i], &b->m_uint64s[i], &c->m_uint64s[i]);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_block2_xor2(mk_lib_crypto_hash_block_streebog_base_block2_pt const a, mk_lib_crypto_hash_block_streebog_base_block2_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_hash_block_streebog_base_block2_xor3(a, b, a);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_x(mk_lib_crypto_hash_block_streebog_base_block2_pct const a, mk_lib_crypto_hash_block_streebog_base_block2_pct const b, mk_lib_crypto_hash_block_streebog_base_block2_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_lib_crypto_hash_block_streebog_base_block2_xor3(a, b, c);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_s(mk_lib_crypto_hash_block_streebog_base_block2_pct const a, mk_lib_crypto_hash_block_streebog_base_block2_pt const b) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t uchars[8] mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != 8; ++i)
	{
		mk_sl_cui_uint64_to_buis_uchar_le(&a->m_uint64s[i], &uchars[0]);
		for(j = 0; j != 8; ++j)
		{
			mk_sl_cui_uint8_to_bi_uchar(&s_mk_lib_crypto_hash_block_streebog_base_table_pi[uchars[j]], &uchars[j]);
		}
		mk_sl_cui_uint64_from_buis_uchar_le(&b->m_uint64s[i], &uchars[0]);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_p(mk_lib_crypto_hash_block_streebog_base_block2_pct const a, mk_lib_crypto_hash_block_streebog_base_block2_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_streebog_base_block_t t mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8s[8] mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_hash_block_streebog_base_block2_to_u8s(a, &t);
	for(i = 0; i != 8; ++i)
	{
		for(j = 0; j != 8; ++j)
		{
			mk_sl_cui_uint8_to_bi_uchar(&s_mk_lib_crypto_hash_block_streebog_base_table_tau[i * 8 + j], &tuc);
			tu8s[j] = t.m_uint8s[tuc];
		}
		mk_sl_uint_64_from_8_le(&b->m_uint64s[i], &tu8s[0]);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_l(mk_lib_crypto_hash_block_streebog_base_block2_pct const a, mk_lib_crypto_hash_block_streebog_base_block2_pt const b) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != 8; ++i)
	{
		ta = a->m_uint64s[i];
		mk_sl_cui_uint64_set_zero(&b->m_uint64s[i]);
		for(j = 0; j != 64; ++j)
		{
			if(mk_sl_cui_uint64_has_lsb(&ta))
			{
				mk_sl_cui_uint64_xor2(&b->m_uint64s[i], &s_mk_lib_crypto_hash_block_streebog_base_table_a[(64 - 1) - j]);
			}
			mk_sl_cui_uint64_shr2(&ta, 1);
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_lps(mk_lib_crypto_hash_block_streebog_base_block2_pct const a, mk_lib_crypto_hash_block_streebog_base_block2_pt const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_hash_block_streebog_base_s(a, b);
	mk_lib_crypto_hash_block_streebog_base_p(b, b);
	mk_lib_crypto_hash_block_streebog_base_l(b, b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_k(mk_lib_crypto_hash_block_streebog_base_block2_pct const a, mk_lang_types_sint_t const b, mk_lib_crypto_hash_block_streebog_base_block2_pt const c) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_streebog_base_block2_t t mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < 12);
	mk_lang_assert(c);

	mk_lib_crypto_hash_block_streebog_base_block2_xor3(a, &s_mk_lib_crypto_hash_block_streebog_base_table_c[b], &t);
	mk_lib_crypto_hash_block_streebog_base_lps(&t, c);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_e(mk_lib_crypto_hash_block_streebog_base_block2_pct const a, mk_lib_crypto_hash_block_streebog_base_block2_pct const b, mk_lib_crypto_hash_block_streebog_base_block2_pt const c) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_streebog_base_block2_pt k_curr mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_streebog_base_block2_pt pta mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_streebog_base_block2_pt ptb mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_streebog_base_block2_t ta mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_streebog_base_block2_pt k_next mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_streebog_base_block2_t tb mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_streebog_base_block2_pt ptc mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	k_curr = ((mk_lib_crypto_hash_block_streebog_base_block2_pt)(a));
	pta = ((mk_lib_crypto_hash_block_streebog_base_block2_pt)(b));
	ptb = &ta;
	k_next = &tb;
	mk_lib_crypto_hash_block_streebog_base_x(k_curr, pta, ptb); pta = ptb; ptb = &ta;
	mk_lib_crypto_hash_block_streebog_base_lps(pta, ptb); ptc = pta; pta = ptb; ptb = ptc;
	mk_lib_crypto_hash_block_streebog_base_k(k_curr, 0, k_next); k_curr = k_next; k_next = &tb;
	mk_lib_crypto_hash_block_streebog_base_x(k_curr, pta, ptb); ptc = pta; pta = ptb; ptb = ptc;
	for(i = 0 + 1; i != s_mk_lib_crypto_hash_block_streebog_base_nrounds - 1; ++i)
	{
		mk_lib_crypto_hash_block_streebog_base_lps(pta, ptb); ptc = pta; pta = ptb; ptb = ptc;
		mk_lib_crypto_hash_block_streebog_base_k(k_curr, i, k_next); ptc = k_curr; k_curr = k_next; k_next = ptc;
		mk_lib_crypto_hash_block_streebog_base_x(k_curr, pta, ptb); ptc = pta; pta = ptb; ptb = ptc;
	}
	mk_lib_crypto_hash_block_streebog_base_lps(pta, ptb); ptc = pta; pta = ptb; ptb = ptc;
	mk_lib_crypto_hash_block_streebog_base_k(k_curr, i, k_next); ptc = k_curr; k_curr = k_next; k_next = ptc;
	mk_lib_crypto_hash_block_streebog_base_x(k_curr, pta, c);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_g(mk_lib_crypto_hash_block_streebog_base_block2_pct const a, mk_lib_crypto_hash_block_streebog_base_block2_pct const b, mk_lib_crypto_hash_block_streebog_base_block2_pct const c, mk_lib_crypto_hash_block_streebog_base_block2_pt const d) mk_lang_noexcept
{
	mk_lib_crypto_hash_block_streebog_base_block2_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_lib_crypto_hash_block_streebog_base_block2_xor3(b, a, &ta);
	mk_lib_crypto_hash_block_streebog_base_lps(&ta, &ta);
	mk_lib_crypto_hash_block_streebog_base_e(&ta, c, &ta);
	mk_lib_crypto_hash_block_streebog_base_block2_xor2(&ta, b);
	mk_lib_crypto_hash_block_streebog_base_block2_xor3(&ta, c, d);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_stage_2(mk_lib_crypto_hash_block_streebog_base_pt const streebog_base, mk_lib_crypto_hash_block_streebog_base_block2_pct const block) mk_lang_noexcept
{
	mk_lang_assert(streebog_base);
	mk_lang_assert(block);

	mk_lib_crypto_hash_block_streebog_base_g(&streebog_base->m_n, &streebog_base->m_h, block, &streebog_base->m_h);
	mk_lib_crypto_hash_block_streebog_base_block2_add_sint(&streebog_base->m_n, mk_lib_crypto_hash_block_streebog_base_block_len);
	mk_lib_crypto_hash_block_streebog_base_block2_add2(&streebog_base->m_s, block);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_block2_set_zero(mk_lib_crypto_hash_block_streebog_base_block2_pt const a) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);

	for(i = 0; i != 8; ++i)
	{
		mk_sl_cui_uint64_set_zero(&a->m_uint64s[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_append_blocks(mk_lib_crypto_hash_block_streebog_base_pt const streebog_base, mk_lib_crypto_hash_block_streebog_base_block_pct const pblocks, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_streebog_base_block2_t block mk_lang_constexpr_init;

	mk_lang_assert(streebog_base);
	mk_lang_assert(pblocks || nblocks == 0);
	mk_lang_assert(nblocks >= 0);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_hash_block_streebog_base_block_len);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		mk_lib_crypto_hash_block_streebog_base_block2_from_u8s(&block, &pblocks[iblock]);
		mk_lib_crypto_hash_block_streebog_base_stage_2(streebog_base, &block);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_stage_3(mk_lib_crypto_hash_block_streebog_base_pt const streebog_base, mk_lib_crypto_hash_block_streebog_base_block_pt const block, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_streebog_base_block2_t blck mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_streebog_base_block2_t zero mk_lang_constexpr_init;

	mk_lang_assert(streebog_base);
	mk_lang_assert(block);
	mk_lang_assert(idx >= 0 && idx < mk_lib_crypto_hash_block_streebog_base_block_len);

	tuc = 0x01; mk_sl_cui_uint8_from_bi_uchar(&block->m_uint8s[idx], &tuc);
	tuc = 0x00; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc);
	for(i = idx + 1; i != mk_lib_crypto_hash_block_streebog_base_block_len; ++i)
	{
		block->m_uint8s[i] = tu8;
	}
	mk_lib_crypto_hash_block_streebog_base_block2_from_u8s(&blck, block);
	mk_lib_crypto_hash_block_streebog_base_g(&streebog_base->m_n, &streebog_base->m_h, &blck, &streebog_base->m_h);
	mk_lib_crypto_hash_block_streebog_base_block2_add_sint(&streebog_base->m_n, idx);
	mk_lib_crypto_hash_block_streebog_base_block2_add2(&streebog_base->m_s, &blck);
	mk_lib_crypto_hash_block_streebog_base_block2_set_zero(&zero);
	mk_lib_crypto_hash_block_streebog_base_g(&zero, &streebog_base->m_h, &streebog_base->m_n, &streebog_base->m_h);
	mk_lib_crypto_hash_block_streebog_base_g(&zero, &streebog_base->m_h, &streebog_base->m_s, &streebog_base->m_h);
}
