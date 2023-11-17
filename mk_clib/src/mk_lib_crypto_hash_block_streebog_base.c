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


#define mk_lib_crypto_hash_block_streebog_base_fast 1


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

#if defined mk_lib_crypto_hash_block_streebog_base_fast && mk_lib_crypto_hash_block_streebog_base_fast == 0

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

#elif defined mk_lib_crypto_hash_block_streebog_base_fast && mk_lib_crypto_hash_block_streebog_base_fast == 1

mk_lang_constexpr_static_inline mk_sl_cui_uint64_t const s_mk_lib_crypto_hash_block_streebog_base_table_a[8][0xff + 1] =
{
	{
		mk_sl_cui_uint64_c(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_c(0x641c314bul, 0x2b8ee083ul), mk_sl_cui_uint64_c(0xc8386296ul, 0x5601dd1bul), mk_sl_cui_uint64_c(0xac2453ddul, 0x7d8f3d98ul),
		mk_sl_cui_uint64_c(0x8d70c431ul, 0xac02a736ul), mk_sl_cui_uint64_c(0xe96cf57aul, 0x878c47b5ul), mk_sl_cui_uint64_c(0x4548a6a7ul, 0xfa037a2dul), mk_sl_cui_uint64_c(0x215497ecul, 0xd18d9aaeul),
		mk_sl_cui_uint64_c(0x07e09562ul, 0x4504536cul), mk_sl_cui_uint64_c(0x63fca429ul, 0x6e8ab3eful), mk_sl_cui_uint64_c(0xcfd8f7f4ul, 0x13058e77ul), mk_sl_cui_uint64_c(0xabc4c6bful, 0x388b6ef4ul),
		mk_sl_cui_uint64_c(0x8a905153ul, 0xe906f45aul), mk_sl_cui_uint64_c(0xee8c6018ul, 0xc28814d9ul), mk_sl_cui_uint64_c(0x42a833c5ul, 0xbf072941ul), mk_sl_cui_uint64_c(0x26b4028eul, 0x9489c9c2ul),
		mk_sl_cui_uint64_c(0x0edd37c4ul, 0x8a08a6d8ul), mk_sl_cui_uint64_c(0x6ac1068ful, 0xa186465bul), mk_sl_cui_uint64_c(0xc6e55552ul, 0xdc097bc3ul), mk_sl_cui_uint64_c(0xa2f96419ul, 0xf7879b40ul),
		mk_sl_cui_uint64_c(0x83adf3f5ul, 0x260a01eeul), mk_sl_cui_uint64_c(0xe7b1c2beul, 0x0d84e16dul), mk_sl_cui_uint64_c(0x4b959163ul, 0x700bdcf5ul), mk_sl_cui_uint64_c(0x2f89a028ul, 0x5b853c76ul),
		mk_sl_cui_uint64_c(0x093da2a6ul, 0xcf0cf5b4ul), mk_sl_cui_uint64_c(0x6d2193edul, 0xe4821537ul), mk_sl_cui_uint64_c(0xc105c030ul, 0x990d28aful), mk_sl_cui_uint64_c(0xa519f17bul, 0xb283c82cul),
		mk_sl_cui_uint64_c(0x844d6697ul, 0x630e5282ul), mk_sl_cui_uint64_c(0xe05157dcul, 0x4880b201ul), mk_sl_cui_uint64_c(0x4c750401ul, 0x350f8f99ul), mk_sl_cui_uint64_c(0x2869354aul, 0x1e816f1aul),
		mk_sl_cui_uint64_c(0x1ca76e95ul, 0x091051adul), mk_sl_cui_uint64_c(0x78bb5fdeul, 0x229eb12eul), mk_sl_cui_uint64_c(0xd49f0c03ul, 0x5f118cb6ul), mk_sl_cui_uint64_c(0xb0833d48ul, 0x749f6c35ul),
		mk_sl_cui_uint64_c(0x91d7aaa4ul, 0xa512f69bul), mk_sl_cui_uint64_c(0xf5cb9beful, 0x8e9c1618ul), mk_sl_cui_uint64_c(0x59efc832ul, 0xf3132b80ul), mk_sl_cui_uint64_c(0x3df3f979ul, 0xd89dcb03ul),
		mk_sl_cui_uint64_c(0x1b47fbf7ul, 0x4c1402c1ul), mk_sl_cui_uint64_c(0x7f5bcabcul, 0x679ae242ul), mk_sl_cui_uint64_c(0xd37f9961ul, 0x1a15dfdaul), mk_sl_cui_uint64_c(0xb763a82aul, 0x319b3f59ul),
		mk_sl_cui_uint64_c(0x96373fc6ul, 0xe016a5f7ul), mk_sl_cui_uint64_c(0xf22b0e8dul, 0xcb984574ul), mk_sl_cui_uint64_c(0x5e0f5d50ul, 0xb61778ecul), mk_sl_cui_uint64_c(0x3a136c1bul, 0x9d99986ful),
		mk_sl_cui_uint64_c(0x127a5951ul, 0x8318f775ul), mk_sl_cui_uint64_c(0x7666681aul, 0xa89617f6ul), mk_sl_cui_uint64_c(0xda423bc7ul, 0xd5192a6eul), mk_sl_cui_uint64_c(0xbe5e0a8cul, 0xfe97caedul),
		mk_sl_cui_uint64_c(0x9f0a9d60ul, 0x2f1a5043ul), mk_sl_cui_uint64_c(0xfb16ac2bul, 0x0494b0c0ul), mk_sl_cui_uint64_c(0x5732fff6ul, 0x791b8d58ul), mk_sl_cui_uint64_c(0x332ecebdul, 0x52956ddbul),
		mk_sl_cui_uint64_c(0x159acc33ul, 0xc61ca419ul), mk_sl_cui_uint64_c(0x7186fd78ul, 0xed92449aul), mk_sl_cui_uint64_c(0xdda2aea5ul, 0x901d7902ul), mk_sl_cui_uint64_c(0xb9be9feeul, 0xbb939981ul),
		mk_sl_cui_uint64_c(0x98ea0802ul, 0x6a1e032ful), mk_sl_cui_uint64_c(0xfcf63949ul, 0x4190e3acul), mk_sl_cui_uint64_c(0x50d26a94ul, 0x3c1fde34ul), mk_sl_cui_uint64_c(0x34ce5bdful, 0x17913eb7ul),
		mk_sl_cui_uint64_c(0x3853dc37ul, 0x1220a247ul), mk_sl_cui_uint64_c(0x5c4fed7cul, 0x39ae42c4ul), mk_sl_cui_uint64_c(0xf06bbea1ul, 0x44217f5cul), mk_sl_cui_uint64_c(0x94778feaul, 0x6faf9fdful),
		mk_sl_cui_uint64_c(0xb5231806ul, 0xbe220571ul), mk_sl_cui_uint64_c(0xd13f294dul, 0x95ace5f2ul), mk_sl_cui_uint64_c(0x7d1b7a90ul, 0xe823d86aul), mk_sl_cui_uint64_c(0x19074bdbul, 0xc3ad38e9ul),
		mk_sl_cui_uint64_c(0x3fb34955ul, 0x5724f12bul), mk_sl_cui_uint64_c(0x5baf781eul, 0x7caa11a8ul), mk_sl_cui_uint64_c(0xf78b2bc3ul, 0x01252c30ul), mk_sl_cui_uint64_c(0x93971a88ul, 0x2aabccb3ul),
		mk_sl_cui_uint64_c(0xb2c38d64ul, 0xfb26561dul), mk_sl_cui_uint64_c(0xd6dfbc2ful, 0xd0a8b69eul), mk_sl_cui_uint64_c(0x7afbeff2ul, 0xad278b06ul), mk_sl_cui_uint64_c(0x1ee7deb9ul, 0x86a96b85ul),
		mk_sl_cui_uint64_c(0x368eebf3ul, 0x9828049ful), mk_sl_cui_uint64_c(0x5292dab8ul, 0xb3a6e41cul), mk_sl_cui_uint64_c(0xfeb68965ul, 0xce29d984ul), mk_sl_cui_uint64_c(0x9aaab82eul, 0xe5a73907ul),
		mk_sl_cui_uint64_c(0xbbfe2fc2ul, 0x342aa3a9ul), mk_sl_cui_uint64_c(0xdfe21e89ul, 0x1fa4432aul), mk_sl_cui_uint64_c(0x73c64d54ul, 0x622b7eb2ul), mk_sl_cui_uint64_c(0x17da7c1ful, 0x49a59e31ul),
		mk_sl_cui_uint64_c(0x316e7e91ul, 0xdd2c57f3ul), mk_sl_cui_uint64_c(0x55724fdaul, 0xf6a2b770ul), mk_sl_cui_uint64_c(0xf9561c07ul, 0x8b2d8ae8ul), mk_sl_cui_uint64_c(0x9d4a2d4cul, 0xa0a36a6bul),
		mk_sl_cui_uint64_c(0xbc1ebaa0ul, 0x712ef0c5ul), mk_sl_cui_uint64_c(0xd8028bebul, 0x5aa01046ul), mk_sl_cui_uint64_c(0x7426d836ul, 0x272f2ddeul), mk_sl_cui_uint64_c(0x103ae97dul, 0x0ca1cd5dul),
		mk_sl_cui_uint64_c(0x24f4b2a2ul, 0x1b30f3eaul), mk_sl_cui_uint64_c(0x40e883e9ul, 0x30be1369ul), mk_sl_cui_uint64_c(0xecccd034ul, 0x4d312ef1ul), mk_sl_cui_uint64_c(0x88d0e17ful, 0x66bfce72ul),
		mk_sl_cui_uint64_c(0xa9847693ul, 0xb73254dcul), mk_sl_cui_uint64_c(0xcd9847d8ul, 0x9cbcb45ful), mk_sl_cui_uint64_c(0x61bc1405ul, 0xe13389c7ul), mk_sl_cui_uint64_c(0x05a0254eul, 0xcabd6944ul),
		mk_sl_cui_uint64_c(0x231427c0ul, 0x5e34a086ul), mk_sl_cui_uint64_c(0x4708168bul, 0x75ba4005ul), mk_sl_cui_uint64_c(0xeb2c4556ul, 0x08357d9dul), mk_sl_cui_uint64_c(0x8f30741dul, 0x23bb9d1eul),
		mk_sl_cui_uint64_c(0xae64e3f1ul, 0xf23607b0ul), mk_sl_cui_uint64_c(0xca78d2baul, 0xd9b8e733ul), mk_sl_cui_uint64_c(0x665c8167ul, 0xa437daabul), mk_sl_cui_uint64_c(0x0240b02cul, 0x8fb93a28ul),
		mk_sl_cui_uint64_c(0x2a298566ul, 0x91385532ul), mk_sl_cui_uint64_c(0x4e35b42dul, 0xbab6b5b1ul), mk_sl_cui_uint64_c(0xe211e7f0ul, 0xc7398829ul), mk_sl_cui_uint64_c(0x860dd6bbul, 0xecb768aaul),
		mk_sl_cui_uint64_c(0xa7594157ul, 0x3d3af204ul), mk_sl_cui_uint64_c(0xc345701cul, 0x16b41287ul), mk_sl_cui_uint64_c(0x6f6123c1ul, 0x6b3b2f1ful), mk_sl_cui_uint64_c(0x0b7d128aul, 0x40b5cf9cul),
		mk_sl_cui_uint64_c(0x2dc91004ul, 0xd43c065eul), mk_sl_cui_uint64_c(0x49d5214ful, 0xffb2e6ddul), mk_sl_cui_uint64_c(0xe5f17292ul, 0x823ddb45ul), mk_sl_cui_uint64_c(0x81ed43d9ul, 0xa9b33bc6ul),
		mk_sl_cui_uint64_c(0xa0b9d435ul, 0x783ea168ul), mk_sl_cui_uint64_c(0xc4a5e57eul, 0x53b041ebul), mk_sl_cui_uint64_c(0x6881b6a3ul, 0x2e3f7c73ul), mk_sl_cui_uint64_c(0x0c9d87e8ul, 0x05b19cf0ul),
		mk_sl_cui_uint64_c(0x70a6a56eul, 0x2440598eul), mk_sl_cui_uint64_c(0x14ba9425ul, 0x0fceb90dul), mk_sl_cui_uint64_c(0xb89ec7f8ul, 0x72418495ul), mk_sl_cui_uint64_c(0xdc82f6b3ul, 0x59cf6416ul),
		mk_sl_cui_uint64_c(0xfdd6615ful, 0x8842feb8ul), mk_sl_cui_uint64_c(0x99ca5014ul, 0xa3cc1e3bul), mk_sl_cui_uint64_c(0x35ee03c9ul, 0xde4323a3ul), mk_sl_cui_uint64_c(0x51f23282ul, 0xf5cdc320ul),
		mk_sl_cui_uint64_c(0x7746300cul, 0x61440ae2ul), mk_sl_cui_uint64_c(0x135a0147ul, 0x4acaea61ul), mk_sl_cui_uint64_c(0xbf7e529aul, 0x3745d7f9ul), mk_sl_cui_uint64_c(0xdb6263d1ul, 0x1ccb377aul),
		mk_sl_cui_uint64_c(0xfa36f43dul, 0xcd46add4ul), mk_sl_cui_uint64_c(0x9e2ac576ul, 0xe6c84d57ul), mk_sl_cui_uint64_c(0x320e96abul, 0x9b4770cful), mk_sl_cui_uint64_c(0x5612a7e0ul, 0xb0c9904cul),
		mk_sl_cui_uint64_c(0x7e7b92aaul, 0xae48ff56ul), mk_sl_cui_uint64_c(0x1a67a3e1ul, 0x85c61fd5ul), mk_sl_cui_uint64_c(0xb643f03cul, 0xf849224dul), mk_sl_cui_uint64_c(0xd25fc177ul, 0xd3c7c2ceul),
		mk_sl_cui_uint64_c(0xf30b569bul, 0x024a5860ul), mk_sl_cui_uint64_c(0x971767d0ul, 0x29c4b8e3ul), mk_sl_cui_uint64_c(0x3b33340dul, 0x544b857bul), mk_sl_cui_uint64_c(0x5f2f0546ul, 0x7fc565f8ul),
		mk_sl_cui_uint64_c(0x799b07c8ul, 0xeb4cac3aul), mk_sl_cui_uint64_c(0x1d873683ul, 0xc0c24cb9ul), mk_sl_cui_uint64_c(0xb1a3655eul, 0xbd4d7121ul), mk_sl_cui_uint64_c(0xd5bf5415ul, 0x96c391a2ul),
		mk_sl_cui_uint64_c(0xf4ebc3f9ul, 0x474e0b0cul), mk_sl_cui_uint64_c(0x90f7f2b2ul, 0x6cc0eb8ful), mk_sl_cui_uint64_c(0x3cd3a16ful, 0x114fd617ul), mk_sl_cui_uint64_c(0x58cf9024ul, 0x3ac13694ul),
		mk_sl_cui_uint64_c(0x6c01cbfbul, 0x2d500823ul), mk_sl_cui_uint64_c(0x081dfab0ul, 0x06dee8a0ul), mk_sl_cui_uint64_c(0xa439a96dul, 0x7b51d538ul), mk_sl_cui_uint64_c(0xc0259826ul, 0x50df35bbul),
		mk_sl_cui_uint64_c(0xe1710fcaul, 0x8152af15ul), mk_sl_cui_uint64_c(0x856d3e81ul, 0xaadc4f96ul), mk_sl_cui_uint64_c(0x29496d5cul, 0xd753720eul), mk_sl_cui_uint64_c(0x4d555c17ul, 0xfcdd928dul),
		mk_sl_cui_uint64_c(0x6be15e99ul, 0x68545b4ful), mk_sl_cui_uint64_c(0x0ffd6fd2ul, 0x43dabbccul), mk_sl_cui_uint64_c(0xa3d93c0ful, 0x3e558654ul), mk_sl_cui_uint64_c(0xc7c50d44ul, 0x15db66d7ul),
		mk_sl_cui_uint64_c(0xe6919aa8ul, 0xc456fc79ul), mk_sl_cui_uint64_c(0x828dabe3ul, 0xefd81cfaul), mk_sl_cui_uint64_c(0x2ea9f83eul, 0x92572162ul), mk_sl_cui_uint64_c(0x4ab5c975ul, 0xb9d9c1e1ul),
		mk_sl_cui_uint64_c(0x62dcfc3ful, 0xa758aefbul), mk_sl_cui_uint64_c(0x06c0cd74ul, 0x8cd64e78ul), mk_sl_cui_uint64_c(0xaae49ea9ul, 0xf15973e0ul), mk_sl_cui_uint64_c(0xcef8afe2ul, 0xdad79363ul),
		mk_sl_cui_uint64_c(0xefac380eul, 0x0b5a09cdul), mk_sl_cui_uint64_c(0x8bb00945ul, 0x20d4e94eul), mk_sl_cui_uint64_c(0x27945a98ul, 0x5d5bd4d6ul), mk_sl_cui_uint64_c(0x43886bd3ul, 0x76d53455ul),
		mk_sl_cui_uint64_c(0x653c695dul, 0xe25cfd97ul), mk_sl_cui_uint64_c(0x01205816ul, 0xc9d21d14ul), mk_sl_cui_uint64_c(0xad040bcbul, 0xb45d208cul), mk_sl_cui_uint64_c(0xc9183a80ul, 0x9fd3c00ful),
		mk_sl_cui_uint64_c(0xe84cad6cul, 0x4e5e5aa1ul), mk_sl_cui_uint64_c(0x8c509c27ul, 0x65d0ba22ul), mk_sl_cui_uint64_c(0x2074cffaul, 0x185f87baul), mk_sl_cui_uint64_c(0x4468feb1ul, 0x33d16739ul),
		mk_sl_cui_uint64_c(0x48f57959ul, 0x3660fbc9ul), mk_sl_cui_uint64_c(0x2ce94812ul, 0x1dee1b4aul), mk_sl_cui_uint64_c(0x80cd1bcful, 0x606126d2ul), mk_sl_cui_uint64_c(0xe4d12a84ul, 0x4befc651ul),
		mk_sl_cui_uint64_c(0xc585bd68ul, 0x9a625cfful), mk_sl_cui_uint64_c(0xa1998c23ul, 0xb1ecbc7cul), mk_sl_cui_uint64_c(0x0dbddffeul, 0xcc6381e4ul), mk_sl_cui_uint64_c(0x69a1eeb5ul, 0xe7ed6167ul),
		mk_sl_cui_uint64_c(0x4f15ec3bul, 0x7364a8a5ul), mk_sl_cui_uint64_c(0x2b09dd70ul, 0x58ea4826ul), mk_sl_cui_uint64_c(0x872d8eadul, 0x256575beul), mk_sl_cui_uint64_c(0xe331bfe6ul, 0x0eeb953dul),
		mk_sl_cui_uint64_c(0xc265280aul, 0xdf660f93ul), mk_sl_cui_uint64_c(0xa6791941ul, 0xf4e8ef10ul), mk_sl_cui_uint64_c(0x0a5d4a9cul, 0x8967d288ul), mk_sl_cui_uint64_c(0x6e417bd7ul, 0xa2e9320bul),
		mk_sl_cui_uint64_c(0x46284e9dul, 0xbc685d11ul), mk_sl_cui_uint64_c(0x22347fd6ul, 0x97e6bd92ul), mk_sl_cui_uint64_c(0x8e102c0bul, 0xea69800aul), mk_sl_cui_uint64_c(0xea0c1d40ul, 0xc1e76089ul),
		mk_sl_cui_uint64_c(0xcb588aacul, 0x106afa27ul), mk_sl_cui_uint64_c(0xaf44bbe7ul, 0x3be41aa4ul), mk_sl_cui_uint64_c(0x0360e83aul, 0x466b273cul), mk_sl_cui_uint64_c(0x677cd971ul, 0x6de5c7bful),
		mk_sl_cui_uint64_c(0x41c8dbfful, 0xf96c0e7dul), mk_sl_cui_uint64_c(0x25d4eab4ul, 0xd2e2eefeul), mk_sl_cui_uint64_c(0x89f0b969ul, 0xaf6dd366ul), mk_sl_cui_uint64_c(0xedec8822ul, 0x84e333e5ul),
		mk_sl_cui_uint64_c(0xccb81fceul, 0x556ea94bul), mk_sl_cui_uint64_c(0xa8a42e85ul, 0x7ee049c8ul), mk_sl_cui_uint64_c(0x04807d58ul, 0x036f7450ul), mk_sl_cui_uint64_c(0x609c4c13ul, 0x28e194d3ul),
		mk_sl_cui_uint64_c(0x545217ccul, 0x3f70aa64ul), mk_sl_cui_uint64_c(0x304e2687ul, 0x14fe4ae7ul), mk_sl_cui_uint64_c(0x9c6a755aul, 0x6971777ful), mk_sl_cui_uint64_c(0xf8764411ul, 0x42ff97fcul),
		mk_sl_cui_uint64_c(0xd922d3fdul, 0x93720d52ul), mk_sl_cui_uint64_c(0xbd3ee2b6ul, 0xb8fcedd1ul), mk_sl_cui_uint64_c(0x111ab16bul, 0xc573d049ul), mk_sl_cui_uint64_c(0x75068020ul, 0xeefd30caul),
		mk_sl_cui_uint64_c(0x53b282aeul, 0x7a74f908ul), mk_sl_cui_uint64_c(0x37aeb3e5ul, 0x51fa198bul), mk_sl_cui_uint64_c(0x9b8ae038ul, 0x2c752413ul), mk_sl_cui_uint64_c(0xff96d173ul, 0x07fbc490ul),
		mk_sl_cui_uint64_c(0xdec2469ful, 0xd6765e3eul), mk_sl_cui_uint64_c(0xbade77d4ul, 0xfdf8bebdul), mk_sl_cui_uint64_c(0x16fa2409ul, 0x80778325ul), mk_sl_cui_uint64_c(0x72e61542ul, 0xabf963a6ul),
		mk_sl_cui_uint64_c(0x5a8f2008ul, 0xb5780cbcul), mk_sl_cui_uint64_c(0x3e931143ul, 0x9ef6ec3ful), mk_sl_cui_uint64_c(0x92b7429eul, 0xe379d1a7ul), mk_sl_cui_uint64_c(0xf6ab73d5ul, 0xc8f73124ul),
		mk_sl_cui_uint64_c(0xd7ffe439ul, 0x197aab8aul), mk_sl_cui_uint64_c(0xb3e3d572ul, 0x32f44b09ul), mk_sl_cui_uint64_c(0x1fc786aful, 0x4f7b7691ul), mk_sl_cui_uint64_c(0x7bdbb7e4ul, 0x64f59612ul),
		mk_sl_cui_uint64_c(0x5d6fb56aul, 0xf07c5fd0ul), mk_sl_cui_uint64_c(0x39738421ul, 0xdbf2bf53ul), mk_sl_cui_uint64_c(0x9557d7fcul, 0xa67d82cbul), mk_sl_cui_uint64_c(0xf14be6b7ul, 0x8df36248ul),
		mk_sl_cui_uint64_c(0xd01f715bul, 0x5c7ef8e6ul), mk_sl_cui_uint64_c(0xb4034010ul, 0x77f01865ul), mk_sl_cui_uint64_c(0x182713cdul, 0x0a7f25fdul), mk_sl_cui_uint64_c(0x7c3b2286ul, 0x21f1c57eul),
	},
	{
		mk_sl_cui_uint64_c(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_c(0xa48b474ful, 0x9ef5dc18ul), mk_sl_cui_uint64_c(0x550b8e9eul, 0x21f7a530ul), mk_sl_cui_uint64_c(0xf180c9d1ul, 0xbf027928ul),
		mk_sl_cui_uint64_c(0xaa160121ul, 0x42f35760ul), mk_sl_cui_uint64_c(0x0e9d466eul, 0xdc068b78ul), mk_sl_cui_uint64_c(0xff1d8fbful, 0x6304f250ul), mk_sl_cui_uint64_c(0x5b96c8f0ul, 0xfdf12e48ul),
		mk_sl_cui_uint64_c(0x492c0242ul, 0x84fbaec0ul), mk_sl_cui_uint64_c(0xeda7450dul, 0x1a0e72d8ul), mk_sl_cui_uint64_c(0x1c278cdcul, 0xa50c0bf0ul), mk_sl_cui_uint64_c(0xb8accb93ul, 0x3bf9d7e8ul),
		mk_sl_cui_uint64_c(0xe33a0363ul, 0xc608f9a0ul), mk_sl_cui_uint64_c(0x47b1442cul, 0x58fd25b8ul), mk_sl_cui_uint64_c(0xb6318dfdul, 0xe7ff5c90ul), mk_sl_cui_uint64_c(0x12bacab2ul, 0x790a8088ul),
		mk_sl_cui_uint64_c(0x92580484ul, 0x15eb419dul), mk_sl_cui_uint64_c(0x36d343cbul, 0x8b1e9d85ul), mk_sl_cui_uint64_c(0xc7538a1aul, 0x341ce4adul), mk_sl_cui_uint64_c(0x63d8cd55ul, 0xaae938b5ul),
		mk_sl_cui_uint64_c(0x384e05a5ul, 0x571816fdul), mk_sl_cui_uint64_c(0x9cc542eaul, 0xc9edcae5ul), mk_sl_cui_uint64_c(0x6d458b3bul, 0x76efb3cdul), mk_sl_cui_uint64_c(0xc9cecc74ul, 0xe81a6fd5ul),
		mk_sl_cui_uint64_c(0xdb7406c6ul, 0x9110ef5dul), mk_sl_cui_uint64_c(0x7fff4189ul, 0x0fe53345ul), mk_sl_cui_uint64_c(0x8e7f8858ul, 0xb0e74a6dul), mk_sl_cui_uint64_c(0x2af4cf17ul, 0x2e129675ul),
		mk_sl_cui_uint64_c(0x716207e7ul, 0xd3e3b83dul), mk_sl_cui_uint64_c(0xd5e940a8ul, 0x4d166425ul), mk_sl_cui_uint64_c(0x24698979ul, 0xf2141d0dul), mk_sl_cui_uint64_c(0x80e2ce36ul, 0x6ce1c115ul),
		mk_sl_cui_uint64_c(0x39b00815ul, 0x2acb8227ul), mk_sl_cui_uint64_c(0x9d3b4f5aul, 0xb43e5e3ful), mk_sl_cui_uint64_c(0x6cbb868bul, 0x0b3c2717ul), mk_sl_cui_uint64_c(0xc830c1c4ul, 0x95c9fb0ful),
		mk_sl_cui_uint64_c(0x93a60934ul, 0x6838d547ul), mk_sl_cui_uint64_c(0x372d4e7bul, 0xf6cd095ful), mk_sl_cui_uint64_c(0xc6ad87aaul, 0x49cf7077ul), mk_sl_cui_uint64_c(0x6226c0e5ul, 0xd73aac6ful),
		mk_sl_cui_uint64_c(0x709c0a57ul, 0xae302ce7ul), mk_sl_cui_uint64_c(0xd4174d18ul, 0x30c5f0fful), mk_sl_cui_uint64_c(0x259784c9ul, 0x8fc789d7ul), mk_sl_cui_uint64_c(0x811cc386ul, 0x113255cful),
		mk_sl_cui_uint64_c(0xda8a0b76ul, 0xecc37b87ul), mk_sl_cui_uint64_c(0x7e014c39ul, 0x7236a79ful), mk_sl_cui_uint64_c(0x8f8185e8ul, 0xcd34deb7ul), mk_sl_cui_uint64_c(0x2b0ac2a7ul, 0x53c102aful),
		mk_sl_cui_uint64_c(0xabe80c91ul, 0x3f20c3baul), mk_sl_cui_uint64_c(0x0f634bdeul, 0xa1d51fa2ul), mk_sl_cui_uint64_c(0xfee3820ful, 0x1ed7668aul), mk_sl_cui_uint64_c(0x5a68c540ul, 0x8022ba92ul),
		mk_sl_cui_uint64_c(0x01fe0db0ul, 0x7dd394daul), mk_sl_cui_uint64_c(0xa5754afful, 0xe32648c2ul), mk_sl_cui_uint64_c(0x54f5832eul, 0x5c2431eaul), mk_sl_cui_uint64_c(0xf07ec461ul, 0xc2d1edf2ul),
		mk_sl_cui_uint64_c(0xe2c40ed3ul, 0xbbdb6d7aul), mk_sl_cui_uint64_c(0x464f499cul, 0x252eb162ul), mk_sl_cui_uint64_c(0xb7cf804dul, 0x9a2cc84aul), mk_sl_cui_uint64_c(0x1344c702ul, 0x04d91452ul),
		mk_sl_cui_uint64_c(0x48d20ff2ul, 0xf9283a1aul), mk_sl_cui_uint64_c(0xec5948bdul, 0x67dde602ul), mk_sl_cui_uint64_c(0x1dd9816cul, 0xd8df9f2aul), mk_sl_cui_uint64_c(0xb952c623ul, 0x462a4332ul),
		mk_sl_cui_uint64_c(0x727d102aul, 0x548b194eul), mk_sl_cui_uint64_c(0xd6f65765ul, 0xca7ec556ul), mk_sl_cui_uint64_c(0x27769eb4ul, 0x757cbc7eul), mk_sl_cui_uint64_c(0x83fdd9fbul, 0xeb896066ul),
		mk_sl_cui_uint64_c(0xd86b110bul, 0x16784e2eul), mk_sl_cui_uint64_c(0x7ce05644ul, 0x888d9236ul), mk_sl_cui_uint64_c(0x8d609f95ul, 0x378feb1eul), mk_sl_cui_uint64_c(0x29ebd8daul, 0xa97a3706ul),
		mk_sl_cui_uint64_c(0x3b511268ul, 0xd070b78eul), mk_sl_cui_uint64_c(0x9fda5527ul, 0x4e856b96ul), mk_sl_cui_uint64_c(0x6e5a9cf6ul, 0xf18712beul), mk_sl_cui_uint64_c(0xcad1dbb9ul, 0x6f72cea6ul),
		mk_sl_cui_uint64_c(0x91471349ul, 0x9283e0eeul), mk_sl_cui_uint64_c(0x35cc5406ul, 0x0c763cf6ul), mk_sl_cui_uint64_c(0xc44c9dd7ul, 0xb37445deul), mk_sl_cui_uint64_c(0x60c7da98ul, 0x2d8199c6ul),
		mk_sl_cui_uint64_c(0xe02514aeul, 0x416058d3ul), mk_sl_cui_uint64_c(0x44ae53e1ul, 0xdf9584cbul), mk_sl_cui_uint64_c(0xb52e9a30ul, 0x6097fde3ul), mk_sl_cui_uint64_c(0x11a5dd7ful, 0xfe6221fbul),
		mk_sl_cui_uint64_c(0x4a33158ful, 0x03930fb3ul), mk_sl_cui_uint64_c(0xeeb852c0ul, 0x9d66d3abul), mk_sl_cui_uint64_c(0x1f389b11ul, 0x2264aa83ul), mk_sl_cui_uint64_c(0xbbb3dc5eul, 0xbc91769bul),
		mk_sl_cui_uint64_c(0xa90916ecul, 0xc59bf613ul), mk_sl_cui_uint64_c(0x0d8251a3ul, 0x5b6e2a0bul), mk_sl_cui_uint64_c(0xfc029872ul, 0xe46c5323ul), mk_sl_cui_uint64_c(0x5889df3dul, 0x7a998f3bul),
		mk_sl_cui_uint64_c(0x031f17cdul, 0x8768a173ul), mk_sl_cui_uint64_c(0xa7945082ul, 0x199d7d6bul), mk_sl_cui_uint64_c(0x56149953ul, 0xa69f0443ul), mk_sl_cui_uint64_c(0xf29fde1cul, 0x386ad85bul),
		mk_sl_cui_uint64_c(0x4bcd183ful, 0x7e409b69ul), mk_sl_cui_uint64_c(0xef465f70ul, 0xe0b54771ul), mk_sl_cui_uint64_c(0x1ec696a1ul, 0x5fb73e59ul), mk_sl_cui_uint64_c(0xba4dd1eeul, 0xc142e241ul),
		mk_sl_cui_uint64_c(0xe1db191eul, 0x3cb3cc09ul), mk_sl_cui_uint64_c(0x45505e51ul, 0xa2461011ul), mk_sl_cui_uint64_c(0xb4d09780ul, 0x1d446939ul), mk_sl_cui_uint64_c(0x105bd0cful, 0x83b1b521ul),
		mk_sl_cui_uint64_c(0x02e11a7dul, 0xfabb35a9ul), mk_sl_cui_uint64_c(0xa66a5d32ul, 0x644ee9b1ul), mk_sl_cui_uint64_c(0x57ea94e3ul, 0xdb4c9099ul), mk_sl_cui_uint64_c(0xf361d3acul, 0x45b94c81ul),
		mk_sl_cui_uint64_c(0xa8f71b5cul, 0xb84862c9ul), mk_sl_cui_uint64_c(0x0c7c5c13ul, 0x26bdbed1ul), mk_sl_cui_uint64_c(0xfdfc95c2ul, 0x99bfc7f9ul), mk_sl_cui_uint64_c(0x5977d28dul, 0x074a1be1ul),
		mk_sl_cui_uint64_c(0xd9951cbbul, 0x6babdaf4ul), mk_sl_cui_uint64_c(0x7d1e5bf4ul, 0xf55e06ecul), mk_sl_cui_uint64_c(0x8c9e9225ul, 0x4a5c7fc4ul), mk_sl_cui_uint64_c(0x2815d56aul, 0xd4a9a3dcul),
		mk_sl_cui_uint64_c(0x73831d9aul, 0x29588d94ul), mk_sl_cui_uint64_c(0xd7085ad5ul, 0xb7ad518cul), mk_sl_cui_uint64_c(0x26889304ul, 0x08af28a4ul), mk_sl_cui_uint64_c(0x8203d44bul, 0x965af4bcul),
		mk_sl_cui_uint64_c(0x90b91ef9ul, 0xef507434ul), mk_sl_cui_uint64_c(0x343259b6ul, 0x71a5a82cul), mk_sl_cui_uint64_c(0xc5b29067ul, 0xcea7d104ul), mk_sl_cui_uint64_c(0x6139d728ul, 0x50520d1cul),
		mk_sl_cui_uint64_c(0x3aaf1fd8ul, 0xada32354ul), mk_sl_cui_uint64_c(0x9e245897ul, 0x3356ff4cul), mk_sl_cui_uint64_c(0x6fa49146ul, 0x8c548664ul), mk_sl_cui_uint64_c(0xcb2fd609ul, 0x12a15a7cul),
		mk_sl_cui_uint64_c(0xe4fa2054ul, 0xa80b329cul), mk_sl_cui_uint64_c(0x4071671bul, 0x36feee84ul), mk_sl_cui_uint64_c(0xb1f1aecaul, 0x89fc97acul), mk_sl_cui_uint64_c(0x157ae985ul, 0x17094bb4ul),
		mk_sl_cui_uint64_c(0x4eec2175ul, 0xeaf865fcul), mk_sl_cui_uint64_c(0xea67663aul, 0x740db9e4ul), mk_sl_cui_uint64_c(0x1be7afebul, 0xcb0fc0ccul), mk_sl_cui_uint64_c(0xbf6ce8a4ul, 0x55fa1cd4ul),
		mk_sl_cui_uint64_c(0xadd62216ul, 0x2cf09c5cul), mk_sl_cui_uint64_c(0x095d6559ul, 0xb2054044ul), mk_sl_cui_uint64_c(0xf8ddac88ul, 0x0d07396cul), mk_sl_cui_uint64_c(0x5c56ebc7ul, 0x93f2e574ul),
		mk_sl_cui_uint64_c(0x07c02337ul, 0x6e03cb3cul), mk_sl_cui_uint64_c(0xa34b6478ul, 0xf0f61724ul), mk_sl_cui_uint64_c(0x52cbada9ul, 0x4ff46e0cul), mk_sl_cui_uint64_c(0xf640eae6ul, 0xd101b214ul),
		mk_sl_cui_uint64_c(0x76a224d0ul, 0xbde07301ul), mk_sl_cui_uint64_c(0xd229639ful, 0x2315af19ul), mk_sl_cui_uint64_c(0x23a9aa4eul, 0x9c17d631ul), mk_sl_cui_uint64_c(0x8722ed01ul, 0x02e20a29ul),
		mk_sl_cui_uint64_c(0xdcb425f1ul, 0xff132461ul), mk_sl_cui_uint64_c(0x783f62beul, 0x61e6f879ul), mk_sl_cui_uint64_c(0x89bfab6ful, 0xdee48151ul), mk_sl_cui_uint64_c(0x2d34ec20ul, 0x40115d49ul),
		mk_sl_cui_uint64_c(0x3f8e2692ul, 0x391bddc1ul), mk_sl_cui_uint64_c(0x9b0561ddul, 0xa7ee01d9ul), mk_sl_cui_uint64_c(0x6a85a80cul, 0x18ec78f1ul), mk_sl_cui_uint64_c(0xce0eef43ul, 0x8619a4e9ul),
		mk_sl_cui_uint64_c(0x959827b3ul, 0x7be88aa1ul), mk_sl_cui_uint64_c(0x311360fcul, 0xe51d56b9ul), mk_sl_cui_uint64_c(0xc093a92dul, 0x5a1f2f91ul), mk_sl_cui_uint64_c(0x6418ee62ul, 0xc4eaf389ul),
		mk_sl_cui_uint64_c(0xdd4a2841ul, 0x82c0b0bbul), mk_sl_cui_uint64_c(0x79c16f0eul, 0x1c356ca3ul), mk_sl_cui_uint64_c(0x8841a6dful, 0xa337158bul), mk_sl_cui_uint64_c(0x2ccae190ul, 0x3dc2c993ul),
		mk_sl_cui_uint64_c(0x775c2960ul, 0xc033e7dbul), mk_sl_cui_uint64_c(0xd3d76e2ful, 0x5ec63bc3ul), mk_sl_cui_uint64_c(0x2257a7feul, 0xe1c442ebul), mk_sl_cui_uint64_c(0x86dce0b1ul, 0x7f319ef3ul),
		mk_sl_cui_uint64_c(0x94662a03ul, 0x063b1e7bul), mk_sl_cui_uint64_c(0x30ed6d4cul, 0x98cec263ul), mk_sl_cui_uint64_c(0xc16da49dul, 0x27ccbb4bul), mk_sl_cui_uint64_c(0x65e6e3d2ul, 0xb9396753ul),
		mk_sl_cui_uint64_c(0x3e702b22ul, 0x44c8491bul), mk_sl_cui_uint64_c(0x9afb6c6dul, 0xda3d9503ul), mk_sl_cui_uint64_c(0x6b7ba5bcul, 0x653fec2bul), mk_sl_cui_uint64_c(0xcff0e2f3ul, 0xfbca3033ul),
		mk_sl_cui_uint64_c(0x4f122cc5ul, 0x972bf126ul), mk_sl_cui_uint64_c(0xeb996b8aul, 0x09de2d3eul), mk_sl_cui_uint64_c(0x1a19a25bul, 0xb6dc5416ul), mk_sl_cui_uint64_c(0xbe92e514ul, 0x2829880eul),
		mk_sl_cui_uint64_c(0xe5042de4ul, 0xd5d8a646ul), mk_sl_cui_uint64_c(0x418f6aabul, 0x4b2d7a5eul), mk_sl_cui_uint64_c(0xb00fa37aul, 0xf42f0376ul), mk_sl_cui_uint64_c(0x1484e435ul, 0x6adadf6eul),
		mk_sl_cui_uint64_c(0x063e2e87ul, 0x13d05fe6ul), mk_sl_cui_uint64_c(0xa2b569c8ul, 0x8d2583feul), mk_sl_cui_uint64_c(0x5335a019ul, 0x3227fad6ul), mk_sl_cui_uint64_c(0xf7bee756ul, 0xacd226ceul),
		mk_sl_cui_uint64_c(0xac282fa6ul, 0x51230886ul), mk_sl_cui_uint64_c(0x08a368e9ul, 0xcfd6d49eul), mk_sl_cui_uint64_c(0xf923a138ul, 0x70d4adb6ul), mk_sl_cui_uint64_c(0x5da8e677ul, 0xee2171aeul),
		mk_sl_cui_uint64_c(0x9687307eul, 0xfc802bd2ul), mk_sl_cui_uint64_c(0x320c7731ul, 0x6275f7caul), mk_sl_cui_uint64_c(0xc38cbee0ul, 0xdd778ee2ul), mk_sl_cui_uint64_c(0x6707f9aful, 0x438252faul),
		mk_sl_cui_uint64_c(0x3c91315ful, 0xbe737cb2ul), mk_sl_cui_uint64_c(0x981a7610ul, 0x2086a0aaul), mk_sl_cui_uint64_c(0x699abfc1ul, 0x9f84d982ul), mk_sl_cui_uint64_c(0xcd11f88eul, 0x0171059aul),
		mk_sl_cui_uint64_c(0xdfab323cul, 0x787b8512ul), mk_sl_cui_uint64_c(0x7b207573ul, 0xe68e590aul), mk_sl_cui_uint64_c(0x8aa0bca2ul, 0x598c2022ul), mk_sl_cui_uint64_c(0x2e2bfbedul, 0xc779fc3aul),
		mk_sl_cui_uint64_c(0x75bd331dul, 0x3a88d272ul), mk_sl_cui_uint64_c(0xd1367452ul, 0xa47d0e6aul), mk_sl_cui_uint64_c(0x20b6bd83ul, 0x1b7f7742ul), mk_sl_cui_uint64_c(0x843dfaccul, 0x858aab5aul),
		mk_sl_cui_uint64_c(0x04df34faul, 0xe96b6a4ful), mk_sl_cui_uint64_c(0xa05473b5ul, 0x779eb657ul), mk_sl_cui_uint64_c(0x51d4ba64ul, 0xc89ccf7ful), mk_sl_cui_uint64_c(0xf55ffd2bul, 0x56691367ul),
		mk_sl_cui_uint64_c(0xaec935dbul, 0xab983d2ful), mk_sl_cui_uint64_c(0x0a427294ul, 0x356de137ul), mk_sl_cui_uint64_c(0xfbc2bb45ul, 0x8a6f981ful), mk_sl_cui_uint64_c(0x5f49fc0aul, 0x149a4407ul),
		mk_sl_cui_uint64_c(0x4df336b8ul, 0x6d90c48ful), mk_sl_cui_uint64_c(0xe97871f7ul, 0xf3651897ul), mk_sl_cui_uint64_c(0x18f8b826ul, 0x4c6761bful), mk_sl_cui_uint64_c(0xbc73ff69ul, 0xd292bda7ul),
		mk_sl_cui_uint64_c(0xe7e53799ul, 0x2f6393eful), mk_sl_cui_uint64_c(0x436e70d6ul, 0xb1964ff7ul), mk_sl_cui_uint64_c(0xb2eeb907ul, 0x0e9436dful), mk_sl_cui_uint64_c(0x1665fe48ul, 0x9061eac7ul),
		mk_sl_cui_uint64_c(0xaf37386bul, 0xd64ba9f5ul), mk_sl_cui_uint64_c(0x0bbc7f24ul, 0x48be75edul), mk_sl_cui_uint64_c(0xfa3cb6f5ul, 0xf7bc0cc5ul), mk_sl_cui_uint64_c(0x5eb7f1baul, 0x6949d0ddul),
		mk_sl_cui_uint64_c(0x0521394aul, 0x94b8fe95ul), mk_sl_cui_uint64_c(0xa1aa7e05ul, 0x0a4d228dul), mk_sl_cui_uint64_c(0x502ab7d4ul, 0xb54f5ba5ul), mk_sl_cui_uint64_c(0xf4a1f09bul, 0x2bba87bdul),
		mk_sl_cui_uint64_c(0xe61b3a29ul, 0x52b00735ul), mk_sl_cui_uint64_c(0x42907d66ul, 0xcc45db2dul), mk_sl_cui_uint64_c(0xb310b4b7ul, 0x7347a205ul), mk_sl_cui_uint64_c(0x179bf3f8ul, 0xedb27e1dul),
		mk_sl_cui_uint64_c(0x4c0d3b08ul, 0x10435055ul), mk_sl_cui_uint64_c(0xe8867c47ul, 0x8eb68c4dul), mk_sl_cui_uint64_c(0x1906b596ul, 0x31b4f565ul), mk_sl_cui_uint64_c(0xbd8df2d9ul, 0xaf41297dul),
		mk_sl_cui_uint64_c(0x3d6f3ceful, 0xc3a0e868ul), mk_sl_cui_uint64_c(0x99e47ba0ul, 0x5d553470ul), mk_sl_cui_uint64_c(0x6864b271ul, 0xe2574d58ul), mk_sl_cui_uint64_c(0xcceff53eul, 0x7ca29140ul),
		mk_sl_cui_uint64_c(0x97793dceul, 0x8153bf08ul), mk_sl_cui_uint64_c(0x33f27a81ul, 0x1fa66310ul), mk_sl_cui_uint64_c(0xc272b350ul, 0xa0a41a38ul), mk_sl_cui_uint64_c(0x66f9f41ful, 0x3e51c620ul),
		mk_sl_cui_uint64_c(0x74433eadul, 0x475b46a8ul), mk_sl_cui_uint64_c(0xd0c879e2ul, 0xd9ae9ab0ul), mk_sl_cui_uint64_c(0x2148b033ul, 0x66ace398ul), mk_sl_cui_uint64_c(0x85c3f77cul, 0xf8593f80ul),
		mk_sl_cui_uint64_c(0xde553f8cul, 0x05a811c8ul), mk_sl_cui_uint64_c(0x7ade78c3ul, 0x9b5dcdd0ul), mk_sl_cui_uint64_c(0x8b5eb112ul, 0x245fb4f8ul), mk_sl_cui_uint64_c(0x2fd5f65dul, 0xbaaa68e0ul),
	},
	{
		mk_sl_cui_uint64_c(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_c(0xf97d86d9ul, 0x8a327728ul), mk_sl_cui_uint64_c(0xeffa11aful, 0x0964ee50ul), mk_sl_cui_uint64_c(0x16879776ul, 0x83569978ul),
		mk_sl_cui_uint64_c(0xc3e92243ul, 0x12c8c1a0ul), mk_sl_cui_uint64_c(0x3a94a49aul, 0x98fab688ul), mk_sl_cui_uint64_c(0x2c1333ecul, 0x1bac2ff0ul), mk_sl_cui_uint64_c(0xd56eb535ul, 0x919e58d8ul),
		mk_sl_cui_uint64_c(0x9bcf4486ul, 0x248d9f5dul), mk_sl_cui_uint64_c(0x62b2c25ful, 0xaebfe875ul), mk_sl_cui_uint64_c(0x74355529ul, 0x2de9710dul), mk_sl_cui_uint64_c(0x8d48d3f0ul, 0xa7db0625ul),
		mk_sl_cui_uint64_c(0x582666c5ul, 0x36455efdul), mk_sl_cui_uint64_c(0xa15be01cul, 0xbc7729d5ul), mk_sl_cui_uint64_c(0xb7dc776aul, 0x3f21b0adul), mk_sl_cui_uint64_c(0x4ea1f1b3ul, 0xb513c785ul),
		mk_sl_cui_uint64_c(0x2b838811ul, 0x480723baul), mk_sl_cui_uint64_c(0xd2fe0ec8ul, 0xc2355492ul), mk_sl_cui_uint64_c(0xc47999beul, 0x4163cdeaul), mk_sl_cui_uint64_c(0x3d041f67ul, 0xcb51bac2ul),
		mk_sl_cui_uint64_c(0xe86aaa52ul, 0x5acfe21aul), mk_sl_cui_uint64_c(0x11172c8bul, 0xd0fd9532ul), mk_sl_cui_uint64_c(0x0790bbfdul, 0x53ab0c4aul), mk_sl_cui_uint64_c(0xfeed3d24ul, 0xd9997b62ul),
		mk_sl_cui_uint64_c(0xb04ccc97ul, 0x6c8abce7ul), mk_sl_cui_uint64_c(0x49314a4eul, 0xe6b8cbcful), mk_sl_cui_uint64_c(0x5fb6dd38ul, 0x65ee52b7ul), mk_sl_cui_uint64_c(0xa6cb5be1ul, 0xefdc259ful),
		mk_sl_cui_uint64_c(0x73a5eed4ul, 0x7e427d47ul), mk_sl_cui_uint64_c(0x8ad8680dul, 0xf4700a6ful), mk_sl_cui_uint64_c(0x9c5fff7bul, 0x77269317ul), mk_sl_cui_uint64_c(0x652279a2ul, 0xfd14e43ful),
		mk_sl_cui_uint64_c(0x561b0d22ul, 0x900e4669ul), mk_sl_cui_uint64_c(0xaf668bfbul, 0x1a3c3141ul), mk_sl_cui_uint64_c(0xb9e11c8dul, 0x996aa839ul), mk_sl_cui_uint64_c(0x409c9a54ul, 0x1358df11ul),
		mk_sl_cui_uint64_c(0x95f22f61ul, 0x82c687c9ul), mk_sl_cui_uint64_c(0x6c8fa9b8ul, 0x08f4f0e1ul), mk_sl_cui_uint64_c(0x7a083eceul, 0x8ba26999ul), mk_sl_cui_uint64_c(0x8375b817ul, 0x01901eb1ul),
		mk_sl_cui_uint64_c(0xcdd449a4ul, 0xb483d934ul), mk_sl_cui_uint64_c(0x34a9cf7dul, 0x3eb1ae1cul), mk_sl_cui_uint64_c(0x222e580bul, 0xbde73764ul), mk_sl_cui_uint64_c(0xdb53ded2ul, 0x37d5404cul),
		mk_sl_cui_uint64_c(0x0e3d6be7ul, 0xa64b1894ul), mk_sl_cui_uint64_c(0xf740ed3eul, 0x2c796fbcul), mk_sl_cui_uint64_c(0xe1c77a48ul, 0xaf2ff6c4ul), mk_sl_cui_uint64_c(0x18bafc91ul, 0x251d81ecul),
		mk_sl_cui_uint64_c(0x7d988533ul, 0xd80965d3ul), mk_sl_cui_uint64_c(0x84e503eaul, 0x523b12fbul), mk_sl_cui_uint64_c(0x9262949cul, 0xd16d8b83ul), mk_sl_cui_uint64_c(0x6b1f1245ul, 0x5b5ffcabul),
		mk_sl_cui_uint64_c(0xbe71a770ul, 0xcac1a473ul), mk_sl_cui_uint64_c(0x470c21a9ul, 0x40f3d35bul), mk_sl_cui_uint64_c(0x518bb6dful, 0xc3a54a23ul), mk_sl_cui_uint64_c(0xa8f63006ul, 0x49973d0bul),
		mk_sl_cui_uint64_c(0xe657c1b5ul, 0xfc84fa8eul), mk_sl_cui_uint64_c(0x1f2a476cul, 0x76b68da6ul), mk_sl_cui_uint64_c(0x09add01aul, 0xf5e014deul), mk_sl_cui_uint64_c(0xf0d056c3ul, 0x7fd263f6ul),
		mk_sl_cui_uint64_c(0x25bee3f6ul, 0xee4c3b2eul), mk_sl_cui_uint64_c(0xdcc3652ful, 0x647e4c06ul), mk_sl_cui_uint64_c(0xca44f259ul, 0xe728d57eul), mk_sl_cui_uint64_c(0x33397480ul, 0x6d1aa256ul),
		mk_sl_cui_uint64_c(0xac361a44ul, 0x3d1c8cd2ul), mk_sl_cui_uint64_c(0x554b9c9dul, 0xb72efbfaul), mk_sl_cui_uint64_c(0x43cc0bebul, 0x34786282ul), mk_sl_cui_uint64_c(0xbab18d32ul, 0xbe4a15aaul),
		mk_sl_cui_uint64_c(0x6fdf3807ul, 0x2fd44d72ul), mk_sl_cui_uint64_c(0x96a2bedeul, 0xa5e63a5aul), mk_sl_cui_uint64_c(0x802529a8ul, 0x26b0a322ul), mk_sl_cui_uint64_c(0x7958af71ul, 0xac82d40aul),
		mk_sl_cui_uint64_c(0x37f95ec2ul, 0x1991138ful), mk_sl_cui_uint64_c(0xce84d81bul, 0x93a364a7ul), mk_sl_cui_uint64_c(0xd8034f6dul, 0x10f5fddful), mk_sl_cui_uint64_c(0x217ec9b4ul, 0x9ac78af7ul),
		mk_sl_cui_uint64_c(0xf4107c81ul, 0x0b59d22ful), mk_sl_cui_uint64_c(0x0d6dfa58ul, 0x816ba507ul), mk_sl_cui_uint64_c(0x1bea6d2eul, 0x023d3c7ful), mk_sl_cui_uint64_c(0xe297ebf7ul, 0x880f4b57ul),
		mk_sl_cui_uint64_c(0x87b59255ul, 0x751baf68ul), mk_sl_cui_uint64_c(0x7ec8148cul, 0xff29d840ul), mk_sl_cui_uint64_c(0x684f83faul, 0x7c7f4138ul), mk_sl_cui_uint64_c(0x91320523ul, 0xf64d3610ul),
		mk_sl_cui_uint64_c(0x445cb016ul, 0x67d36ec8ul), mk_sl_cui_uint64_c(0xbd2136cful, 0xede119e0ul), mk_sl_cui_uint64_c(0xaba6a1b9ul, 0x6eb78098ul), mk_sl_cui_uint64_c(0x52db2760ul, 0xe485f7b0ul),
		mk_sl_cui_uint64_c(0x1c7ad6d3ul, 0x51963035ul), mk_sl_cui_uint64_c(0xe507500aul, 0xdba4471dul), mk_sl_cui_uint64_c(0xf380c77cul, 0x58f2de65ul), mk_sl_cui_uint64_c(0x0afd41a5ul, 0xd2c0a94dul),
		mk_sl_cui_uint64_c(0xdf93f490ul, 0x435ef195ul), mk_sl_cui_uint64_c(0x26ee7249ul, 0xc96c86bdul), mk_sl_cui_uint64_c(0x3069e53ful, 0x4a3a1fc5ul), mk_sl_cui_uint64_c(0xc91463e6ul, 0xc00868edul),
		mk_sl_cui_uint64_c(0xfa2d1766ul, 0xad12cabbul), mk_sl_cui_uint64_c(0x035091bful, 0x2720bd93ul), mk_sl_cui_uint64_c(0x15d706c9ul, 0xa47624ebul), mk_sl_cui_uint64_c(0xecaa8010ul, 0x2e4453c3ul),
		mk_sl_cui_uint64_c(0x39c43525ul, 0xbfda0b1bul), mk_sl_cui_uint64_c(0xc0b9b3fcul, 0x35e87c33ul), mk_sl_cui_uint64_c(0xd63e248aul, 0xb6bee54bul), mk_sl_cui_uint64_c(0x2f43a253ul, 0x3c8c9263ul),
		mk_sl_cui_uint64_c(0x61e253e0ul, 0x899f55e6ul), mk_sl_cui_uint64_c(0x989fd539ul, 0x03ad22ceul), mk_sl_cui_uint64_c(0x8e18424ful, 0x80fbbbb6ul), mk_sl_cui_uint64_c(0x7765c496ul, 0x0ac9cc9eul),
		mk_sl_cui_uint64_c(0xa20b71a3ul, 0x9b579446ul), mk_sl_cui_uint64_c(0x5b76f77aul, 0x1165e36eul), mk_sl_cui_uint64_c(0x4df1600cul, 0x92337a16ul), mk_sl_cui_uint64_c(0xb48ce6d5ul, 0x18010d3eul),
		mk_sl_cui_uint64_c(0xd1ae9f77ul, 0xe515e901ul), mk_sl_cui_uint64_c(0x28d319aeul, 0x6f279e29ul), mk_sl_cui_uint64_c(0x3e548ed8ul, 0xec710751ul), mk_sl_cui_uint64_c(0xc7290801ul, 0x66437079ul),
		mk_sl_cui_uint64_c(0x1247bd34ul, 0xf7dd28a1ul), mk_sl_cui_uint64_c(0xeb3a3bedul, 0x7def5f89ul), mk_sl_cui_uint64_c(0xfdbdac9bul, 0xfeb9c6f1ul), mk_sl_cui_uint64_c(0x04c02a42ul, 0x748bb1d9ul),
		mk_sl_cui_uint64_c(0x4a61dbf1ul, 0xc198765cul), mk_sl_cui_uint64_c(0xb31c5d28ul, 0x4baa0174ul), mk_sl_cui_uint64_c(0xa59bca5eul, 0xc8fc980cul), mk_sl_cui_uint64_c(0x5ce64c87ul, 0x42ceef24ul),
		mk_sl_cui_uint64_c(0x8988f9b2ul, 0xd350b7fcul), mk_sl_cui_uint64_c(0x70f57f6bul, 0x5962c0d4ul), mk_sl_cui_uint64_c(0x6672e81dul, 0xda3459acul), mk_sl_cui_uint64_c(0x9f0f6ec4ul, 0x50062e84ul),
		mk_sl_cui_uint64_c(0x456c3488ul, 0x7a3805b9ul), mk_sl_cui_uint64_c(0xbc11b251ul, 0xf00a7291ul), mk_sl_cui_uint64_c(0xaa962527ul, 0x735cebe9ul), mk_sl_cui_uint64_c(0x53eba3feul, 0xf96e9cc1ul),
		mk_sl_cui_uint64_c(0x868516cbul, 0x68f0c419ul), mk_sl_cui_uint64_c(0x7ff89012ul, 0xe2c2b331ul), mk_sl_cui_uint64_c(0x697f0764ul, 0x61942a49ul), mk_sl_cui_uint64_c(0x900281bdul, 0xeba65d61ul),
		mk_sl_cui_uint64_c(0xdea3700eul, 0x5eb59ae4ul), mk_sl_cui_uint64_c(0x27def6d7ul, 0xd487edccul), mk_sl_cui_uint64_c(0x315961a1ul, 0x57d174b4ul), mk_sl_cui_uint64_c(0xc824e778ul, 0xdde3039cul),
		mk_sl_cui_uint64_c(0x1d4a524dul, 0x4c7d5b44ul), mk_sl_cui_uint64_c(0xe437d494ul, 0xc64f2c6cul), mk_sl_cui_uint64_c(0xf2b043e2ul, 0x4519b514ul), mk_sl_cui_uint64_c(0x0bcdc53bul, 0xcf2bc23cul),
		mk_sl_cui_uint64_c(0x6eefbc99ul, 0x323f2603ul), mk_sl_cui_uint64_c(0x97923a40ul, 0xb80d512bul), mk_sl_cui_uint64_c(0x8115ad36ul, 0x3b5bc853ul), mk_sl_cui_uint64_c(0x78682beful, 0xb169bf7bul),
		mk_sl_cui_uint64_c(0xad069edaul, 0x20f7e7a3ul), mk_sl_cui_uint64_c(0x547b1803ul, 0xaac5908bul), mk_sl_cui_uint64_c(0x42fc8f75ul, 0x299309f3ul), mk_sl_cui_uint64_c(0xbb8109acul, 0xa3a17edbul),
		mk_sl_cui_uint64_c(0xf520f81ful, 0x16b2b95eul), mk_sl_cui_uint64_c(0x0c5d7ec6ul, 0x9c80ce76ul), mk_sl_cui_uint64_c(0x1adae9b0ul, 0x1fd6570eul), mk_sl_cui_uint64_c(0xe3a76f69ul, 0x95e42026ul),
		mk_sl_cui_uint64_c(0x36c9da5cul, 0x047a78feul), mk_sl_cui_uint64_c(0xcfb45c85ul, 0x8e480fd6ul), mk_sl_cui_uint64_c(0xd933cbf3ul, 0x0d1e96aeul), mk_sl_cui_uint64_c(0x204e4d2aul, 0x872ce186ul),
		mk_sl_cui_uint64_c(0x137739aaul, 0xea3643d0ul), mk_sl_cui_uint64_c(0xea0abf73ul, 0x600434f8ul), mk_sl_cui_uint64_c(0xfc8d2805ul, 0xe352ad80ul), mk_sl_cui_uint64_c(0x05f0aedcul, 0x6960daa8ul),
		mk_sl_cui_uint64_c(0xd09e1be9ul, 0xf8fe8270ul), mk_sl_cui_uint64_c(0x29e39d30ul, 0x72ccf558ul), mk_sl_cui_uint64_c(0x3f640a46ul, 0xf19a6c20ul), mk_sl_cui_uint64_c(0xc6198c9ful, 0x7ba81b08ul),
		mk_sl_cui_uint64_c(0x88b87d2cul, 0xcebbdc8dul), mk_sl_cui_uint64_c(0x71c5fbf5ul, 0x4489aba5ul), mk_sl_cui_uint64_c(0x67426c83ul, 0xc7df32ddul), mk_sl_cui_uint64_c(0x9e3fea5aul, 0x4ded45f5ul),
		mk_sl_cui_uint64_c(0x4b515f6ful, 0xdc731d2dul), mk_sl_cui_uint64_c(0xb22cd9b6ul, 0x56416a05ul), mk_sl_cui_uint64_c(0xa4ab4ec0ul, 0xd517f37dul), mk_sl_cui_uint64_c(0x5dd6c819ul, 0x5f258455ul),
		mk_sl_cui_uint64_c(0x38f4b1bbul, 0xa231606aul), mk_sl_cui_uint64_c(0xc1893762ul, 0x28031742ul), mk_sl_cui_uint64_c(0xd70ea014ul, 0xab558e3aul), mk_sl_cui_uint64_c(0x2e7326cdul, 0x2167f912ul),
		mk_sl_cui_uint64_c(0xfb1d93f8ul, 0xb0f9a1caul), mk_sl_cui_uint64_c(0x02601521ul, 0x3acbd6e2ul), mk_sl_cui_uint64_c(0x14e78257ul, 0xb99d4f9aul), mk_sl_cui_uint64_c(0xed9a048eul, 0x33af38b2ul),
		mk_sl_cui_uint64_c(0xa33bf53dul, 0x86bcff37ul), mk_sl_cui_uint64_c(0x5a4673e4ul, 0x0c8e881ful), mk_sl_cui_uint64_c(0x4cc1e492ul, 0x8fd81167ul), mk_sl_cui_uint64_c(0xb5bc624bul, 0x05ea664ful),
		mk_sl_cui_uint64_c(0x60d2d77eul, 0x94743e97ul), mk_sl_cui_uint64_c(0x99af51a7ul, 0x1e4649bful), mk_sl_cui_uint64_c(0x8f28c6d1ul, 0x9d10d0c7ul), mk_sl_cui_uint64_c(0x76554008ul, 0x1722a7eful),
		mk_sl_cui_uint64_c(0xe95a2eccul, 0x4724896bul), mk_sl_cui_uint64_c(0x1027a815ul, 0xcd16fe43ul), mk_sl_cui_uint64_c(0x06a03f63ul, 0x4e40673bul), mk_sl_cui_uint64_c(0xffddb9baul, 0xc4721013ul),
		mk_sl_cui_uint64_c(0x2ab30c8ful, 0x55ec48cbul), mk_sl_cui_uint64_c(0xd3ce8a56ul, 0xdfde3fe3ul), mk_sl_cui_uint64_c(0xc5491d20ul, 0x5c88a69bul), mk_sl_cui_uint64_c(0x3c349bf9ul, 0xd6bad1b3ul),
		mk_sl_cui_uint64_c(0x72956a4aul, 0x63a91636ul), mk_sl_cui_uint64_c(0x8be8ec93ul, 0xe99b611eul), mk_sl_cui_uint64_c(0x9d6f7be5ul, 0x6acdf866ul), mk_sl_cui_uint64_c(0x6412fd3cul, 0xe0ff8f4eul),
		mk_sl_cui_uint64_c(0xb17c4809ul, 0x7161d796ul), mk_sl_cui_uint64_c(0x4801ced0ul, 0xfb53a0beul), mk_sl_cui_uint64_c(0x5e8659a6ul, 0x780539c6ul), mk_sl_cui_uint64_c(0xa7fbdf7ful, 0xf2374eeeul),
		mk_sl_cui_uint64_c(0xc2d9a6ddul, 0x0f23aad1ul), mk_sl_cui_uint64_c(0x3ba42004ul, 0x8511ddf9ul), mk_sl_cui_uint64_c(0x2d23b772ul, 0x06474481ul), mk_sl_cui_uint64_c(0xd45e31abul, 0x8c7533a9ul),
		mk_sl_cui_uint64_c(0x0130849eul, 0x1deb6b71ul), mk_sl_cui_uint64_c(0xf84d0247ul, 0x97d91c59ul), mk_sl_cui_uint64_c(0xeeca9531ul, 0x148f8521ul), mk_sl_cui_uint64_c(0x17b713e8ul, 0x9ebdf209ul),
		mk_sl_cui_uint64_c(0x5916e25bul, 0x2bae358cul), mk_sl_cui_uint64_c(0xa06b6482ul, 0xa19c42a4ul), mk_sl_cui_uint64_c(0xb6ecf3f4ul, 0x22cadbdcul), mk_sl_cui_uint64_c(0x4f91752dul, 0xa8f8acf4ul),
		mk_sl_cui_uint64_c(0x9affc018ul, 0x3966f42cul), mk_sl_cui_uint64_c(0x638246c1ul, 0xb3548304ul), mk_sl_cui_uint64_c(0x7505d1b7ul, 0x30021a7cul), mk_sl_cui_uint64_c(0x8c78576eul, 0xba306d54ul),
		mk_sl_cui_uint64_c(0xbf4123eeul, 0xd72acf02ul), mk_sl_cui_uint64_c(0x463ca537ul, 0x5d18b82aul), mk_sl_cui_uint64_c(0x50bb3241ul, 0xde4e2152ul), mk_sl_cui_uint64_c(0xa9c6b498ul, 0x547c567aul),
		mk_sl_cui_uint64_c(0x7ca801adul, 0xc5e20ea2ul), mk_sl_cui_uint64_c(0x85d58774ul, 0x4fd0798aul), mk_sl_cui_uint64_c(0x93521002ul, 0xcc86e0f2ul), mk_sl_cui_uint64_c(0x6a2f96dbul, 0x46b497daul),
		mk_sl_cui_uint64_c(0x248e6768ul, 0xf3a7505ful), mk_sl_cui_uint64_c(0xddf3e1b1ul, 0x79952777ul), mk_sl_cui_uint64_c(0xcb7476c7ul, 0xfac3be0ful), mk_sl_cui_uint64_c(0x3209f01eul, 0x70f1c927ul),
		mk_sl_cui_uint64_c(0xe767452bul, 0xe16f91fful), mk_sl_cui_uint64_c(0x1e1ac3f2ul, 0x6b5de6d7ul), mk_sl_cui_uint64_c(0x089d5484ul, 0xe80b7faful), mk_sl_cui_uint64_c(0xf1e0d25dul, 0x62390887ul),
		mk_sl_cui_uint64_c(0x94c2abfful, 0x9f2decb8ul), mk_sl_cui_uint64_c(0x6dbf2d26ul, 0x151f9b90ul), mk_sl_cui_uint64_c(0x7b38ba50ul, 0x964902e8ul), mk_sl_cui_uint64_c(0x82453c89ul, 0x1c7b75c0ul),
		mk_sl_cui_uint64_c(0x572b89bcul, 0x8de52d18ul), mk_sl_cui_uint64_c(0xae560f65ul, 0x07d75a30ul), mk_sl_cui_uint64_c(0xb8d19813ul, 0x8481c348ul), mk_sl_cui_uint64_c(0x41ac1ecaul, 0x0eb3b460ul),
		mk_sl_cui_uint64_c(0x0f0def79ul, 0xbba073e5ul), mk_sl_cui_uint64_c(0xf67069a0ul, 0x319204cdul), mk_sl_cui_uint64_c(0xe0f7fed6ul, 0xb2c49db5ul), mk_sl_cui_uint64_c(0x198a780ful, 0x38f6ea9dul),
		mk_sl_cui_uint64_c(0xcce4cd3aul, 0xa968b245ul), mk_sl_cui_uint64_c(0x35994be3ul, 0x235ac56dul), mk_sl_cui_uint64_c(0x231edc95ul, 0xa00c5c15ul), mk_sl_cui_uint64_c(0xda635a4cul, 0x2a3e2b3dul),
	},
	{
		mk_sl_cui_uint64_c(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_c(0x5b068c65ul, 0x1810a89eul), mk_sl_cui_uint64_c(0xb60c05caul, 0x30204d21ul), mk_sl_cui_uint64_c(0xed0a89aful, 0x2830e5bful),
		mk_sl_cui_uint64_c(0x71180a89ul, 0x60409a42ul), mk_sl_cui_uint64_c(0x2a1e86ecul, 0x785032dcul), mk_sl_cui_uint64_c(0xc7140f43ul, 0x5060d763ul), mk_sl_cui_uint64_c(0x9c128326ul, 0x48707ffdul),
		mk_sl_cui_uint64_c(0xe230140ful, 0xc0802984ul), mk_sl_cui_uint64_c(0xb936986aul, 0xd890811aul), mk_sl_cui_uint64_c(0x543c11c5ul, 0xf0a064a5ul), mk_sl_cui_uint64_c(0x0f3a9da0ul, 0xe8b0cc3bul),
		mk_sl_cui_uint64_c(0x93281e86ul, 0xa0c0b3c6ul), mk_sl_cui_uint64_c(0xc82e92e3ul, 0xb8d01b58ul), mk_sl_cui_uint64_c(0x25241b4cul, 0x90e0fee7ul), mk_sl_cui_uint64_c(0x7e229729ul, 0x88f05679ul),
		mk_sl_cui_uint64_c(0xd960281eul, 0x9d1d5215ul), mk_sl_cui_uint64_c(0x8266a47bul, 0x850dfa8bul), mk_sl_cui_uint64_c(0x6f6c2dd4ul, 0xad3d1f34ul), mk_sl_cui_uint64_c(0x346aa1b1ul, 0xb52db7aaul),
		mk_sl_cui_uint64_c(0xa8782297ul, 0xfd5dc857ul), mk_sl_cui_uint64_c(0xf37eaef2ul, 0xe54d60c9ul), mk_sl_cui_uint64_c(0x1e74275dul, 0xcd7d8576ul), mk_sl_cui_uint64_c(0x4572ab38ul, 0xd56d2de8ul),
		mk_sl_cui_uint64_c(0x3b503c11ul, 0x5d9d7b91ul), mk_sl_cui_uint64_c(0x6056b074ul, 0x458dd30ful), mk_sl_cui_uint64_c(0x8d5c39dbul, 0x6dbd36b0ul), mk_sl_cui_uint64_c(0xd65ab5beul, 0x75ad9e2eul),
		mk_sl_cui_uint64_c(0x4a483698ul, 0x3ddde1d3ul), mk_sl_cui_uint64_c(0x114ebafdul, 0x25cd494dul), mk_sl_cui_uint64_c(0xfc443352ul, 0x0dfdacf2ul), mk_sl_cui_uint64_c(0xa742bf37ul, 0x15ed046cul),
		mk_sl_cui_uint64_c(0xafc0503cul, 0x273aa42aul), mk_sl_cui_uint64_c(0xf4c6dc59ul, 0x3f2a0cb4ul), mk_sl_cui_uint64_c(0x19cc55f6ul, 0x171ae90bul), mk_sl_cui_uint64_c(0x42cad993ul, 0x0f0a4195ul),
		mk_sl_cui_uint64_c(0xded85ab5ul, 0x477a3e68ul), mk_sl_cui_uint64_c(0x85ded6d0ul, 0x5f6a96f6ul), mk_sl_cui_uint64_c(0x68d45f7ful, 0x775a7349ul), mk_sl_cui_uint64_c(0x33d2d31aul, 0x6f4adbd7ul),
		mk_sl_cui_uint64_c(0x4df04433ul, 0xe7ba8daeul), mk_sl_cui_uint64_c(0x16f6c856ul, 0xffaa2530ul), mk_sl_cui_uint64_c(0xfbfc41f9ul, 0xd79ac08ful), mk_sl_cui_uint64_c(0xa0facd9cul, 0xcf8a6811ul),
		mk_sl_cui_uint64_c(0x3ce84ebaul, 0x87fa17ecul), mk_sl_cui_uint64_c(0x67eec2dful, 0x9feabf72ul), mk_sl_cui_uint64_c(0x8ae44b70ul, 0xb7da5acdul), mk_sl_cui_uint64_c(0xd1e2c715ul, 0xafcaf253ul),
		mk_sl_cui_uint64_c(0x76a07822ul, 0xba27f63ful), mk_sl_cui_uint64_c(0x2da6f447ul, 0xa2375ea1ul), mk_sl_cui_uint64_c(0xc0ac7de8ul, 0x8a07bb1eul), mk_sl_cui_uint64_c(0x9baaf18dul, 0x92171380ul),
		mk_sl_cui_uint64_c(0x07b872abul, 0xda676c7dul), mk_sl_cui_uint64_c(0x5cbefeceul, 0xc277c4e3ul), mk_sl_cui_uint64_c(0xb1b47761ul, 0xea47215cul), mk_sl_cui_uint64_c(0xeab2fb04ul, 0xf25789c2ul),
		mk_sl_cui_uint64_c(0x94906c2dul, 0x7aa7dfbbul), mk_sl_cui_uint64_c(0xcf96e048ul, 0x62b77725ul), mk_sl_cui_uint64_c(0x229c69e7ul, 0x4a87929aul), mk_sl_cui_uint64_c(0x799ae582ul, 0x52973a04ul),
		mk_sl_cui_uint64_c(0xe58866a4ul, 0x1ae745f9ul), mk_sl_cui_uint64_c(0xbe8eeac1ul, 0x02f7ed67ul), mk_sl_cui_uint64_c(0x5384636eul, 0x2ac708d8ul), mk_sl_cui_uint64_c(0x0882ef0bul, 0x32d7a046ul),
		mk_sl_cui_uint64_c(0x439da078ul, 0x4e745554ul), mk_sl_cui_uint64_c(0x189b2c1dul, 0x5664fdcaul), mk_sl_cui_uint64_c(0xf591a5b2ul, 0x7e541875ul), mk_sl_cui_uint64_c(0xae9729d7ul, 0x6644b0ebul),
		mk_sl_cui_uint64_c(0x3285aaf1ul, 0x2e34cf16ul), mk_sl_cui_uint64_c(0x69832694ul, 0x36246788ul), mk_sl_cui_uint64_c(0x8489af3bul, 0x1e148237ul), mk_sl_cui_uint64_c(0xdf8f235eul, 0x06042aa9ul),
		mk_sl_cui_uint64_c(0xa1adb477ul, 0x8ef47cd0ul), mk_sl_cui_uint64_c(0xfaab3812ul, 0x96e4d44eul), mk_sl_cui_uint64_c(0x17a1b1bdul, 0xbed431f1ul), mk_sl_cui_uint64_c(0x4ca73dd8ul, 0xa6c4996ful),
		mk_sl_cui_uint64_c(0xd0b5befeul, 0xeeb4e692ul), mk_sl_cui_uint64_c(0x8bb3329bul, 0xf6a44e0cul), mk_sl_cui_uint64_c(0x66b9bb34ul, 0xde94abb3ul), mk_sl_cui_uint64_c(0x3dbf3751ul, 0xc684032dul),
		mk_sl_cui_uint64_c(0x9afd8866ul, 0xd3690741ul), mk_sl_cui_uint64_c(0xc1fb0403ul, 0xcb79afdful), mk_sl_cui_uint64_c(0x2cf18dacul, 0xe3494a60ul), mk_sl_cui_uint64_c(0x77f701c9ul, 0xfb59e2feul),
		mk_sl_cui_uint64_c(0xebe582eful, 0xb3299d03ul), mk_sl_cui_uint64_c(0xb0e30e8aul, 0xab39359dul), mk_sl_cui_uint64_c(0x5de98725ul, 0x8309d022ul), mk_sl_cui_uint64_c(0x06ef0b40ul, 0x9b1978bcul),
		mk_sl_cui_uint64_c(0x78cd9c69ul, 0x13e92ec5ul), mk_sl_cui_uint64_c(0x23cb100cul, 0x0bf9865bul), mk_sl_cui_uint64_c(0xcec199a3ul, 0x23c963e4ul), mk_sl_cui_uint64_c(0x95c715c6ul, 0x3bd9cb7aul),
		mk_sl_cui_uint64_c(0x09d596e0ul, 0x73a9b487ul), mk_sl_cui_uint64_c(0x52d31a85ul, 0x6bb91c19ul), mk_sl_cui_uint64_c(0xbfd9932aul, 0x4389f9a6ul), mk_sl_cui_uint64_c(0xe4df1f4ful, 0x5b995138ul),
		mk_sl_cui_uint64_c(0xec5df044ul, 0x694ef17eul), mk_sl_cui_uint64_c(0xb75b7c21ul, 0x715e59e0ul), mk_sl_cui_uint64_c(0x5a51f58eul, 0x596ebc5ful), mk_sl_cui_uint64_c(0x015779ebul, 0x417e14c1ul),
		mk_sl_cui_uint64_c(0x9d45facdul, 0x090e6b3cul), mk_sl_cui_uint64_c(0xc64376a8ul, 0x111ec3a2ul), mk_sl_cui_uint64_c(0x2b49ff07ul, 0x392e261dul), mk_sl_cui_uint64_c(0x704f7362ul, 0x213e8e83ul),
		mk_sl_cui_uint64_c(0x0e6de44bul, 0xa9ced8faul), mk_sl_cui_uint64_c(0x556b682eul, 0xb1de7064ul), mk_sl_cui_uint64_c(0xb861e181ul, 0x99ee95dbul), mk_sl_cui_uint64_c(0xe3676de4ul, 0x81fe3d45ul),
		mk_sl_cui_uint64_c(0x7f75eec2ul, 0xc98e42b8ul), mk_sl_cui_uint64_c(0x247362a7ul, 0xd19eea26ul), mk_sl_cui_uint64_c(0xc979eb08ul, 0xf9ae0f99ul), mk_sl_cui_uint64_c(0x927f676dul, 0xe1bea707ul),
		mk_sl_cui_uint64_c(0x353dd85aul, 0xf453a36bul), mk_sl_cui_uint64_c(0x6e3b543ful, 0xec430bf5ul), mk_sl_cui_uint64_c(0x8331dd90ul, 0xc473ee4aul), mk_sl_cui_uint64_c(0xd83751f5ul, 0xdc6346d4ul),
		mk_sl_cui_uint64_c(0x4425d2d3ul, 0x94133929ul), mk_sl_cui_uint64_c(0x1f235eb6ul, 0x8c0391b7ul), mk_sl_cui_uint64_c(0xf229d719ul, 0xa4337408ul), mk_sl_cui_uint64_c(0xa92f5b7cul, 0xbc23dc96ul),
		mk_sl_cui_uint64_c(0xd70dcc55ul, 0x34d38aeful), mk_sl_cui_uint64_c(0x8c0b4030ul, 0x2cc32271ul), mk_sl_cui_uint64_c(0x6101c99ful, 0x04f3c7ceul), mk_sl_cui_uint64_c(0x3a0745faul, 0x1ce36f50ul),
		mk_sl_cui_uint64_c(0xa615c6dcul, 0x549310adul), mk_sl_cui_uint64_c(0xfd134ab9ul, 0x4c83b833ul), mk_sl_cui_uint64_c(0x1019c316ul, 0x64b35d8cul), mk_sl_cui_uint64_c(0x4b1f4f73ul, 0x7ca3f512ul),
		mk_sl_cui_uint64_c(0x86275df0ul, 0x9ce8aaa8ul), mk_sl_cui_uint64_c(0xdd21d195ul, 0x84f80236ul), mk_sl_cui_uint64_c(0x302b583aul, 0xacc8e789ul), mk_sl_cui_uint64_c(0x6b2dd45ful, 0xb4d84f17ul),
		mk_sl_cui_uint64_c(0xf73f5779ul, 0xfca830eaul), mk_sl_cui_uint64_c(0xac39db1cul, 0xe4b89874ul), mk_sl_cui_uint64_c(0x413352b3ul, 0xcc887dcbul), mk_sl_cui_uint64_c(0x1a35ded6ul, 0xd498d555ul),
		mk_sl_cui_uint64_c(0x641749fful, 0x5c68832cul), mk_sl_cui_uint64_c(0x3f11c59aul, 0x44782bb2ul), mk_sl_cui_uint64_c(0xd21b4c35ul, 0x6c48ce0dul), mk_sl_cui_uint64_c(0x891dc050ul, 0x74586693ul),
		mk_sl_cui_uint64_c(0x150f4376ul, 0x3c28196eul), mk_sl_cui_uint64_c(0x4e09cf13ul, 0x2438b1f0ul), mk_sl_cui_uint64_c(0xa30346bcul, 0x0c08544ful), mk_sl_cui_uint64_c(0xf805cad9ul, 0x1418fcd1ul),
		mk_sl_cui_uint64_c(0x5f4775eeul, 0x01f5f8bdul), mk_sl_cui_uint64_c(0x0441f98bul, 0x19e55023ul), mk_sl_cui_uint64_c(0xe94b7024ul, 0x31d5b59cul), mk_sl_cui_uint64_c(0xb24dfc41ul, 0x29c51d02ul),
		mk_sl_cui_uint64_c(0x2e5f7f67ul, 0x61b562fful), mk_sl_cui_uint64_c(0x7559f302ul, 0x79a5ca61ul), mk_sl_cui_uint64_c(0x98537aadul, 0x51952fdeul), mk_sl_cui_uint64_c(0xc355f6c8ul, 0x49858740ul),
		mk_sl_cui_uint64_c(0xbd7761e1ul, 0xc175d139ul), mk_sl_cui_uint64_c(0xe671ed84ul, 0xd96579a7ul), mk_sl_cui_uint64_c(0x0b7b642bul, 0xf1559c18ul), mk_sl_cui_uint64_c(0x507de84eul, 0xe9453486ul),
		mk_sl_cui_uint64_c(0xcc6f6b68ul, 0xa1354b7bul), mk_sl_cui_uint64_c(0x9769e70dul, 0xb925e3e5ul), mk_sl_cui_uint64_c(0x7a636ea2ul, 0x9115065aul), mk_sl_cui_uint64_c(0x2165e2c7ul, 0x8905aec4ul),
		mk_sl_cui_uint64_c(0x29e70dccul, 0xbbd20e82ul), mk_sl_cui_uint64_c(0x72e181a9ul, 0xa3c2a61cul), mk_sl_cui_uint64_c(0x9feb0806ul, 0x8bf243a3ul), mk_sl_cui_uint64_c(0xc4ed8463ul, 0x93e2eb3dul),
		mk_sl_cui_uint64_c(0x58ff0745ul, 0xdb9294c0ul), mk_sl_cui_uint64_c(0x03f98b20ul, 0xc3823c5eul), mk_sl_cui_uint64_c(0xeef3028ful, 0xebb2d9e1ul), mk_sl_cui_uint64_c(0xb5f58eeaul, 0xf3a2717ful),
		mk_sl_cui_uint64_c(0xcbd719c3ul, 0x7b522706ul), mk_sl_cui_uint64_c(0x90d195a6ul, 0x63428f98ul), mk_sl_cui_uint64_c(0x7ddb1c09ul, 0x4b726a27ul), mk_sl_cui_uint64_c(0x26dd906cul, 0x5362c2b9ul),
		mk_sl_cui_uint64_c(0xbacf134aul, 0x1b12bd44ul), mk_sl_cui_uint64_c(0xe1c99f2ful, 0x030215daul), mk_sl_cui_uint64_c(0x0cc31680ul, 0x2b32f065ul), mk_sl_cui_uint64_c(0x57c59ae5ul, 0x332258fbul),
		mk_sl_cui_uint64_c(0xf08725d2ul, 0x26cf5c97ul), mk_sl_cui_uint64_c(0xab81a9b7ul, 0x3edff409ul), mk_sl_cui_uint64_c(0x468b2018ul, 0x16ef11b6ul), mk_sl_cui_uint64_c(0x1d8dac7dul, 0x0effb928ul),
		mk_sl_cui_uint64_c(0x819f2f5bul, 0x468fc6d5ul), mk_sl_cui_uint64_c(0xda99a33eul, 0x5e9f6e4bul), mk_sl_cui_uint64_c(0x37932a91ul, 0x76af8bf4ul), mk_sl_cui_uint64_c(0x6c95a6f4ul, 0x6ebf236aul),
		mk_sl_cui_uint64_c(0x12b731ddul, 0xe64f7513ul), mk_sl_cui_uint64_c(0x49b1bdb8ul, 0xfe5fdd8dul), mk_sl_cui_uint64_c(0xa4bb3417ul, 0xd66f3832ul), mk_sl_cui_uint64_c(0xffbdb872ul, 0xce7f90acul),
		mk_sl_cui_uint64_c(0x63af3b54ul, 0x860fef51ul), mk_sl_cui_uint64_c(0x38a9b731ul, 0x9e1f47cful), mk_sl_cui_uint64_c(0xd5a33e9eul, 0xb62fa270ul), mk_sl_cui_uint64_c(0x8ea5b2fbul, 0xae3f0aeeul),
		mk_sl_cui_uint64_c(0xc5bafd88ul, 0xd29cfffcul), mk_sl_cui_uint64_c(0x9ebc71edul, 0xca8c5762ul), mk_sl_cui_uint64_c(0x73b6f842ul, 0xe2bcb2ddul), mk_sl_cui_uint64_c(0x28b07427ul, 0xfaac1a43ul),
		mk_sl_cui_uint64_c(0xb4a2f701ul, 0xb2dc65beul), mk_sl_cui_uint64_c(0xefa47b64ul, 0xaacccd20ul), mk_sl_cui_uint64_c(0x02aef2cbul, 0x82fc289ful), mk_sl_cui_uint64_c(0x59a87eaeul, 0x9aec8001ul),
		mk_sl_cui_uint64_c(0x278ae987ul, 0x121cd678ul), mk_sl_cui_uint64_c(0x7c8c65e2ul, 0x0a0c7ee6ul), mk_sl_cui_uint64_c(0x9186ec4dul, 0x223c9b59ul), mk_sl_cui_uint64_c(0xca806028ul, 0x3a2c33c7ul),
		mk_sl_cui_uint64_c(0x5692e30eul, 0x725c4c3aul), mk_sl_cui_uint64_c(0x0d946f6bul, 0x6a4ce4a4ul), mk_sl_cui_uint64_c(0xe09ee6c4ul, 0x427c011bul), mk_sl_cui_uint64_c(0xbb986aa1ul, 0x5a6ca985ul),
		mk_sl_cui_uint64_c(0x1cdad596ul, 0x4f81ade9ul), mk_sl_cui_uint64_c(0x47dc59f3ul, 0x57910577ul), mk_sl_cui_uint64_c(0xaad6d05cul, 0x7fa1e0c8ul), mk_sl_cui_uint64_c(0xf1d05c39ul, 0x67b14856ul),
		mk_sl_cui_uint64_c(0x6dc2df1ful, 0x2fc137abul), mk_sl_cui_uint64_c(0x36c4537aul, 0x37d19f35ul), mk_sl_cui_uint64_c(0xdbcedad5ul, 0x1fe17a8aul), mk_sl_cui_uint64_c(0x80c856b0ul, 0x07f1d214ul),
		mk_sl_cui_uint64_c(0xfeeac199ul, 0x8f01846dul), mk_sl_cui_uint64_c(0xa5ec4dfcul, 0x97112cf3ul), mk_sl_cui_uint64_c(0x48e6c453ul, 0xbf21c94cul), mk_sl_cui_uint64_c(0x13e04836ul, 0xa73161d2ul),
		mk_sl_cui_uint64_c(0x8ff2cb10ul, 0xef411e2ful), mk_sl_cui_uint64_c(0xd4f44775ul, 0xf751b6b1ul), mk_sl_cui_uint64_c(0x39fecedaul, 0xdf61530eul), mk_sl_cui_uint64_c(0x62f842bful, 0xc771fb90ul),
		mk_sl_cui_uint64_c(0x6a7aadb4ul, 0xf5a65bd6ul), mk_sl_cui_uint64_c(0x317c21d1ul, 0xedb6f348ul), mk_sl_cui_uint64_c(0xdc76a87eul, 0xc58616f7ul), mk_sl_cui_uint64_c(0x8770241bul, 0xdd96be69ul),
		mk_sl_cui_uint64_c(0x1b62a73dul, 0x95e6c194ul), mk_sl_cui_uint64_c(0x40642b58ul, 0x8df6690aul), mk_sl_cui_uint64_c(0xad6ea2f7ul, 0xa5c68cb5ul), mk_sl_cui_uint64_c(0xf6682e92ul, 0xbdd6242bul),
		mk_sl_cui_uint64_c(0x884ab9bbul, 0x35267252ul), mk_sl_cui_uint64_c(0xd34c35deul, 0x2d36daccul), mk_sl_cui_uint64_c(0x3e46bc71ul, 0x05063f73ul), mk_sl_cui_uint64_c(0x65403014ul, 0x1d1697edul),
		mk_sl_cui_uint64_c(0xf952b332ul, 0x5566e810ul), mk_sl_cui_uint64_c(0xa2543f57ul, 0x4d76408eul), mk_sl_cui_uint64_c(0x4f5eb6f8ul, 0x6546a531ul), mk_sl_cui_uint64_c(0x14583a9dul, 0x7d560daful),
		mk_sl_cui_uint64_c(0xb31a85aaul, 0x68bb09c3ul), mk_sl_cui_uint64_c(0xe81c09cful, 0x70aba15dul), mk_sl_cui_uint64_c(0x05168060ul, 0x589b44e2ul), mk_sl_cui_uint64_c(0x5e100c05ul, 0x408bec7cul),
		mk_sl_cui_uint64_c(0xc2028f23ul, 0x08fb9381ul), mk_sl_cui_uint64_c(0x99040346ul, 0x10eb3b1ful), mk_sl_cui_uint64_c(0x740e8ae9ul, 0x38dbdea0ul), mk_sl_cui_uint64_c(0x2f08068cul, 0x20cb763eul),
		mk_sl_cui_uint64_c(0x512a91a5ul, 0xa83b2047ul), mk_sl_cui_uint64_c(0x0a2c1dc0ul, 0xb02b88d9ul), mk_sl_cui_uint64_c(0xe726946ful, 0x981b6d66ul), mk_sl_cui_uint64_c(0xbc20180aul, 0x800bc5f8ul),
		mk_sl_cui_uint64_c(0x20329b2cul, 0xc87bba05ul), mk_sl_cui_uint64_c(0x7b341749ul, 0xd06b129bul), mk_sl_cui_uint64_c(0x963e9ee6ul, 0xf85bf724ul), mk_sl_cui_uint64_c(0xcd381283ul, 0xe04b5fbaul),
	},
	{
		mk_sl_cui_uint64_c(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_c(0x0321658cul, 0xba93c138ul), mk_sl_cui_uint64_c(0x0642ca05ul, 0x693b9f70ul), mk_sl_cui_uint64_c(0x0563af89ul, 0xd3a85e48ul),
		mk_sl_cui_uint64_c(0x0c84890aul, 0xd27623e0ul), mk_sl_cui_uint64_c(0x0fa5ec86ul, 0x68e5e2d8ul), mk_sl_cui_uint64_c(0x0ac6430ful, 0xbb4dbc90ul), mk_sl_cui_uint64_c(0x09e72683ul, 0x01de7da8ul),
		mk_sl_cui_uint64_c(0x18150f14ul, 0xb9ec46ddul), mk_sl_cui_uint64_c(0x1b346a98ul, 0x037f87e5ul), mk_sl_cui_uint64_c(0x1e57c511ul, 0xd0d7d9adul), mk_sl_cui_uint64_c(0x1d76a09dul, 0x6a441895ul),
		mk_sl_cui_uint64_c(0x1491861eul, 0x6b9a653dul), mk_sl_cui_uint64_c(0x17b0e392ul, 0xd109a405ul), mk_sl_cui_uint64_c(0x12d34c1bul, 0x02a1fa4dul), mk_sl_cui_uint64_c(0x11f22997ul, 0xb8323b75ul),
		mk_sl_cui_uint64_c(0x302a1e28ul, 0x6fc58ca7ul), mk_sl_cui_uint64_c(0x330b7ba4ul, 0xd5564d9ful), mk_sl_cui_uint64_c(0x3668d42dul, 0x06fe13d7ul), mk_sl_cui_uint64_c(0x3549b1a1ul, 0xbc6dd2eful),
		mk_sl_cui_uint64_c(0x3cae9722ul, 0xbdb3af47ul), mk_sl_cui_uint64_c(0x3f8ff2aeul, 0x07206e7ful), mk_sl_cui_uint64_c(0x3aec5d27ul, 0xd4883037ul), mk_sl_cui_uint64_c(0x39cd38abul, 0x6e1bf10ful),
		mk_sl_cui_uint64_c(0x283f113cul, 0xd629ca7aul), mk_sl_cui_uint64_c(0x2b1e74b0ul, 0x6cba0b42ul), mk_sl_cui_uint64_c(0x2e7ddb39ul, 0xbf12550aul), mk_sl_cui_uint64_c(0x2d5cbeb5ul, 0x05819432ul),
		mk_sl_cui_uint64_c(0x24bb9836ul, 0x045fe99aul), mk_sl_cui_uint64_c(0x279afdbaul, 0xbecc28a2ul), mk_sl_cui_uint64_c(0x22f95233ul, 0x6d6476eaul), mk_sl_cui_uint64_c(0x21d837bful, 0xd7f7b7d2ul),
		mk_sl_cui_uint64_c(0x60543c50ul, 0xde970553ul), mk_sl_cui_uint64_c(0x637559dcul, 0x6404c46bul), mk_sl_cui_uint64_c(0x6616f655ul, 0xb7ac9a23ul), mk_sl_cui_uint64_c(0x653793d9ul, 0x0d3f5b1bul),
		mk_sl_cui_uint64_c(0x6cd0b55aul, 0x0ce126b3ul), mk_sl_cui_uint64_c(0x6ff1d0d6ul, 0xb672e78bul), mk_sl_cui_uint64_c(0x6a927f5ful, 0x65dab9c3ul), mk_sl_cui_uint64_c(0x69b31ad3ul, 0xdf4978fbul),
		mk_sl_cui_uint64_c(0x78413344ul, 0x677b438eul), mk_sl_cui_uint64_c(0x7b6056c8ul, 0xdde882b6ul), mk_sl_cui_uint64_c(0x7e03f941ul, 0x0e40dcfeul), mk_sl_cui_uint64_c(0x7d229ccdul, 0xb4d31dc6ul),
		mk_sl_cui_uint64_c(0x74c5ba4eul, 0xb50d606eul), mk_sl_cui_uint64_c(0x77e4dfc2ul, 0x0f9ea156ul), mk_sl_cui_uint64_c(0x7287704bul, 0xdc36ff1eul), mk_sl_cui_uint64_c(0x71a615c7ul, 0x66a53e26ul),
		mk_sl_cui_uint64_c(0x507e2278ul, 0xb15289f4ul), mk_sl_cui_uint64_c(0x535f47f4ul, 0x0bc148ccul), mk_sl_cui_uint64_c(0x563ce87dul, 0xd8691684ul), mk_sl_cui_uint64_c(0x551d8df1ul, 0x62fad7bcul),
		mk_sl_cui_uint64_c(0x5cfaab72ul, 0x6324aa14ul), mk_sl_cui_uint64_c(0x5fdbcefeul, 0xd9b76b2cul), mk_sl_cui_uint64_c(0x5ab86177ul, 0x0a1f3564ul), mk_sl_cui_uint64_c(0x599904fbul, 0xb08cf45cul),
		mk_sl_cui_uint64_c(0x486b2d6cul, 0x08becf29ul), mk_sl_cui_uint64_c(0x4b4a48e0ul, 0xb22d0e11ul), mk_sl_cui_uint64_c(0x4e29e769ul, 0x61855059ul), mk_sl_cui_uint64_c(0x4d0882e5ul, 0xdb169161ul),
		mk_sl_cui_uint64_c(0x44efa466ul, 0xdac8ecc9ul), mk_sl_cui_uint64_c(0x47cec1eaul, 0x605b2df1ul), mk_sl_cui_uint64_c(0x42ad6e63ul, 0xb3f373b9ul), mk_sl_cui_uint64_c(0x418c0beful, 0x0960b281ul),
		mk_sl_cui_uint64_c(0xc0a878a0ul, 0xa1330aa6ul), mk_sl_cui_uint64_c(0xc3891d2cul, 0x1ba0cb9eul), mk_sl_cui_uint64_c(0xc6eab2a5ul, 0xc80895d6ul), mk_sl_cui_uint64_c(0xc5cbd729ul, 0x729b54eeul),
		mk_sl_cui_uint64_c(0xcc2cf1aaul, 0x73452946ul), mk_sl_cui_uint64_c(0xcf0d9426ul, 0xc9d6e87eul), mk_sl_cui_uint64_c(0xca6e3baful, 0x1a7eb636ul), mk_sl_cui_uint64_c(0xc94f5e23ul, 0xa0ed770eul),
		mk_sl_cui_uint64_c(0xd8bd77b4ul, 0x18df4c7bul), mk_sl_cui_uint64_c(0xdb9c1238ul, 0xa24c8d43ul), mk_sl_cui_uint64_c(0xdeffbdb1ul, 0x71e4d30bul), mk_sl_cui_uint64_c(0xddded83dul, 0xcb771233ul),
		mk_sl_cui_uint64_c(0xd439febeul, 0xcaa96f9bul), mk_sl_cui_uint64_c(0xd7189b32ul, 0x703aaea3ul), mk_sl_cui_uint64_c(0xd27b34bbul, 0xa392f0ebul), mk_sl_cui_uint64_c(0xd15a5137ul, 0x190131d3ul),
		mk_sl_cui_uint64_c(0xf0826688ul, 0xcef68601ul), mk_sl_cui_uint64_c(0xf3a30304ul, 0x74654739ul), mk_sl_cui_uint64_c(0xf6c0ac8dul, 0xa7cd1971ul), mk_sl_cui_uint64_c(0xf5e1c901ul, 0x1d5ed849ul),
		mk_sl_cui_uint64_c(0xfc06ef82ul, 0x1c80a5e1ul), mk_sl_cui_uint64_c(0xff278a0eul, 0xa61364d9ul), mk_sl_cui_uint64_c(0xfa442587ul, 0x75bb3a91ul), mk_sl_cui_uint64_c(0xf965400bul, 0xcf28fba9ul),
		mk_sl_cui_uint64_c(0xe897699cul, 0x771ac0dcul), mk_sl_cui_uint64_c(0xebb60c10ul, 0xcd8901e4ul), mk_sl_cui_uint64_c(0xeed5a399ul, 0x1e215facul), mk_sl_cui_uint64_c(0xedf4c615ul, 0xa4b29e94ul),
		mk_sl_cui_uint64_c(0xe413e096ul, 0xa56ce33cul), mk_sl_cui_uint64_c(0xe732851aul, 0x1fff2204ul), mk_sl_cui_uint64_c(0xe2512a93ul, 0xcc577c4cul), mk_sl_cui_uint64_c(0xe1704f1ful, 0x76c4bd74ul),
		mk_sl_cui_uint64_c(0xa0fc44f0ul, 0x7fa40ff5ul), mk_sl_cui_uint64_c(0xa3dd217cul, 0xc537cecdul), mk_sl_cui_uint64_c(0xa6be8ef5ul, 0x169f9085ul), mk_sl_cui_uint64_c(0xa59feb79ul, 0xac0c51bdul),
		mk_sl_cui_uint64_c(0xac78cdfaul, 0xadd22c15ul), mk_sl_cui_uint64_c(0xaf59a876ul, 0x1741ed2dul), mk_sl_cui_uint64_c(0xaa3a07fful, 0xc4e9b365ul), mk_sl_cui_uint64_c(0xa91b6273ul, 0x7e7a725dul),
		mk_sl_cui_uint64_c(0xb8e94be4ul, 0xc6484928ul), mk_sl_cui_uint64_c(0xbbc82e68ul, 0x7cdb8810ul), mk_sl_cui_uint64_c(0xbeab81e1ul, 0xaf73d658ul), mk_sl_cui_uint64_c(0xbd8ae46dul, 0x15e01760ul),
		mk_sl_cui_uint64_c(0xb46dc2eeul, 0x143e6ac8ul), mk_sl_cui_uint64_c(0xb74ca762ul, 0xaeadabf0ul), mk_sl_cui_uint64_c(0xb22f08ebul, 0x7d05f5b8ul), mk_sl_cui_uint64_c(0xb10e6d67ul, 0xc7963480ul),
		mk_sl_cui_uint64_c(0x90d65ad8ul, 0x10618352ul), mk_sl_cui_uint64_c(0x93f73f54ul, 0xaaf2426aul), mk_sl_cui_uint64_c(0x969490ddul, 0x795a1c22ul), mk_sl_cui_uint64_c(0x95b5f551ul, 0xc3c9dd1aul),
		mk_sl_cui_uint64_c(0x9c52d3d2ul, 0xc217a0b2ul), mk_sl_cui_uint64_c(0x9f73b65eul, 0x7884618aul), mk_sl_cui_uint64_c(0x9a1019d7ul, 0xab2c3fc2ul), mk_sl_cui_uint64_c(0x99317c5bul, 0x11bffefaul),
		mk_sl_cui_uint64_c(0x88c355ccul, 0xa98dc58ful), mk_sl_cui_uint64_c(0x8be23040ul, 0x131e04b7ul), mk_sl_cui_uint64_c(0x8e819fc9ul, 0xc0b65afful), mk_sl_cui_uint64_c(0x8da0fa45ul, 0x7a259bc7ul),
		mk_sl_cui_uint64_c(0x8447dcc6ul, 0x7bfbe66ful), mk_sl_cui_uint64_c(0x8766b94aul, 0xc1682757ul), mk_sl_cui_uint64_c(0x820516c3ul, 0x12c0791ful), mk_sl_cui_uint64_c(0x8124734ful, 0xa853b827ul),
		mk_sl_cui_uint64_c(0x9d4df05dul, 0x5f661451ul), mk_sl_cui_uint64_c(0x9e6c95d1ul, 0xe5f5d569ul), mk_sl_cui_uint64_c(0x9b0f3a58ul, 0x365d8b21ul), mk_sl_cui_uint64_c(0x982e5fd4ul, 0x8cce4a19ul),
		mk_sl_cui_uint64_c(0x91c97957ul, 0x8d1037b1ul), mk_sl_cui_uint64_c(0x92e81cdbul, 0x3783f689ul), mk_sl_cui_uint64_c(0x978bb352ul, 0xe42ba8c1ul), mk_sl_cui_uint64_c(0x94aad6deul, 0x5eb869f9ul),
		mk_sl_cui_uint64_c(0x8558ff49ul, 0xe68a528cul), mk_sl_cui_uint64_c(0x86799ac5ul, 0x5c1993b4ul), mk_sl_cui_uint64_c(0x831a354cul, 0x8fb1cdfcul), mk_sl_cui_uint64_c(0x803b50c0ul, 0x35220cc4ul),
		mk_sl_cui_uint64_c(0x89dc7643ul, 0x34fc716cul), mk_sl_cui_uint64_c(0x8afd13cful, 0x8e6fb054ul), mk_sl_cui_uint64_c(0x8f9ebc46ul, 0x5dc7ee1cul), mk_sl_cui_uint64_c(0x8cbfd9caul, 0xe7542f24ul),
		mk_sl_cui_uint64_c(0xad67ee75ul, 0x30a398f6ul), mk_sl_cui_uint64_c(0xae468bf9ul, 0x8a3059ceul), mk_sl_cui_uint64_c(0xab252470ul, 0x59980786ul), mk_sl_cui_uint64_c(0xa80441fcul, 0xe30bc6beul),
		mk_sl_cui_uint64_c(0xa1e3677ful, 0xe2d5bb16ul), mk_sl_cui_uint64_c(0xa2c202f3ul, 0x58467a2eul), mk_sl_cui_uint64_c(0xa7a1ad7aul, 0x8bee2466ul), mk_sl_cui_uint64_c(0xa480c8f6ul, 0x317de55eul),
		mk_sl_cui_uint64_c(0xb572e161ul, 0x894fde2bul), mk_sl_cui_uint64_c(0xb65384edul, 0x33dc1f13ul), mk_sl_cui_uint64_c(0xb3302b64ul, 0xe074415bul), mk_sl_cui_uint64_c(0xb0114ee8ul, 0x5ae78063ul),
		mk_sl_cui_uint64_c(0xb9f6686bul, 0x5b39fdcbul), mk_sl_cui_uint64_c(0xbad70de7ul, 0xe1aa3cf3ul), mk_sl_cui_uint64_c(0xbfb4a26eul, 0x320262bbul), mk_sl_cui_uint64_c(0xbc95c7e2ul, 0x8891a383ul),
		mk_sl_cui_uint64_c(0xfd19cc0dul, 0x81f11102ul), mk_sl_cui_uint64_c(0xfe38a981ul, 0x3b62d03aul), mk_sl_cui_uint64_c(0xfb5b0608ul, 0xe8ca8e72ul), mk_sl_cui_uint64_c(0xf87a6384ul, 0x52594f4aul),
		mk_sl_cui_uint64_c(0xf19d4507ul, 0x538732e2ul), mk_sl_cui_uint64_c(0xf2bc208bul, 0xe914f3daul), mk_sl_cui_uint64_c(0xf7df8f02ul, 0x3abcad92ul), mk_sl_cui_uint64_c(0xf4feea8eul, 0x802f6caaul),
		mk_sl_cui_uint64_c(0xe50cc319ul, 0x381d57dful), mk_sl_cui_uint64_c(0xe62da695ul, 0x828e96e7ul), mk_sl_cui_uint64_c(0xe34e091cul, 0x5126c8aful), mk_sl_cui_uint64_c(0xe06f6c90ul, 0xebb50997ul),
		mk_sl_cui_uint64_c(0xe9884a13ul, 0xea6b743ful), mk_sl_cui_uint64_c(0xeaa92f9ful, 0x50f8b507ul), mk_sl_cui_uint64_c(0xefca8016ul, 0x8350eb4ful), mk_sl_cui_uint64_c(0xecebe59aul, 0x39c32a77ul),
		mk_sl_cui_uint64_c(0xcd33d225ul, 0xee349da5ul), mk_sl_cui_uint64_c(0xce12b7a9ul, 0x54a75c9dul), mk_sl_cui_uint64_c(0xcb711820ul, 0x870f02d5ul), mk_sl_cui_uint64_c(0xc8507dacul, 0x3d9cc3edul),
		mk_sl_cui_uint64_c(0xc1b75b2ful, 0x3c42be45ul), mk_sl_cui_uint64_c(0xc2963ea3ul, 0x86d17f7dul), mk_sl_cui_uint64_c(0xc7f5912aul, 0x55792135ul), mk_sl_cui_uint64_c(0xc4d4f4a6ul, 0xefeae00dul),
		mk_sl_cui_uint64_c(0xd526dd31ul, 0x57d8db78ul), mk_sl_cui_uint64_c(0xd607b8bdul, 0xed4b1a40ul), mk_sl_cui_uint64_c(0xd3641734ul, 0x3ee34408ul), mk_sl_cui_uint64_c(0xd04572b8ul, 0x84708530ul),
		mk_sl_cui_uint64_c(0xd9a2543bul, 0x85aef898ul), mk_sl_cui_uint64_c(0xda8331b7ul, 0x3f3d39a0ul), mk_sl_cui_uint64_c(0xdfe09e3eul, 0xec9567e8ul), mk_sl_cui_uint64_c(0xdcc1fbb2ul, 0x5606a6d0ul),
		mk_sl_cui_uint64_c(0x5de588fdul, 0xfe551ef7ul), mk_sl_cui_uint64_c(0x5ec4ed71ul, 0x44c6dfcful), mk_sl_cui_uint64_c(0x5ba742f8ul, 0x976e8187ul), mk_sl_cui_uint64_c(0x58862774ul, 0x2dfd40bful),
		mk_sl_cui_uint64_c(0x516101f7ul, 0x2c233d17ul), mk_sl_cui_uint64_c(0x5240647bul, 0x96b0fc2ful), mk_sl_cui_uint64_c(0x5723cbf2ul, 0x4518a267ul), mk_sl_cui_uint64_c(0x5402ae7eul, 0xff8b635ful),
		mk_sl_cui_uint64_c(0x45f087e9ul, 0x47b9582aul), mk_sl_cui_uint64_c(0x46d1e265ul, 0xfd2a9912ul), mk_sl_cui_uint64_c(0x43b24decul, 0x2e82c75aul), mk_sl_cui_uint64_c(0x40932860ul, 0x94110662ul),
		mk_sl_cui_uint64_c(0x49740ee3ul, 0x95cf7bcaul), mk_sl_cui_uint64_c(0x4a556b6ful, 0x2f5cbaf2ul), mk_sl_cui_uint64_c(0x4f36c4e6ul, 0xfcf4e4baul), mk_sl_cui_uint64_c(0x4c17a16aul, 0x46672582ul),
		mk_sl_cui_uint64_c(0x6dcf96d5ul, 0x91909250ul), mk_sl_cui_uint64_c(0x6eeef359ul, 0x2b035368ul), mk_sl_cui_uint64_c(0x6b8d5cd0ul, 0xf8ab0d20ul), mk_sl_cui_uint64_c(0x68ac395cul, 0x4238cc18ul),
		mk_sl_cui_uint64_c(0x614b1fdful, 0x43e6b1b0ul), mk_sl_cui_uint64_c(0x626a7a53ul, 0xf9757088ul), mk_sl_cui_uint64_c(0x6709d5daul, 0x2add2ec0ul), mk_sl_cui_uint64_c(0x6428b056ul, 0x904eeff8ul),
		mk_sl_cui_uint64_c(0x75da99c1ul, 0x287cd48dul), mk_sl_cui_uint64_c(0x76fbfc4dul, 0x92ef15b5ul), mk_sl_cui_uint64_c(0x739853c4ul, 0x41474bfdul), mk_sl_cui_uint64_c(0x70b93648ul, 0xfbd48ac5ul),
		mk_sl_cui_uint64_c(0x795e10cbul, 0xfa0af76dul), mk_sl_cui_uint64_c(0x7a7f7547ul, 0x40993655ul), mk_sl_cui_uint64_c(0x7f1cdaceul, 0x9331681dul), mk_sl_cui_uint64_c(0x7c3dbf42ul, 0x29a2a925ul),
		mk_sl_cui_uint64_c(0x3db1b4adul, 0x20c21ba4ul), mk_sl_cui_uint64_c(0x3e90d121ul, 0x9a51da9cul), mk_sl_cui_uint64_c(0x3bf37ea8ul, 0x49f984d4ul), mk_sl_cui_uint64_c(0x38d21b24ul, 0xf36a45ecul),
		mk_sl_cui_uint64_c(0x31353da7ul, 0xf2b43844ul), mk_sl_cui_uint64_c(0x3214582bul, 0x4827f97cul), mk_sl_cui_uint64_c(0x3777f7a2ul, 0x9b8fa734ul), mk_sl_cui_uint64_c(0x3456922eul, 0x211c660cul),
		mk_sl_cui_uint64_c(0x25a4bbb9ul, 0x992e5d79ul), mk_sl_cui_uint64_c(0x2685de35ul, 0x23bd9c41ul), mk_sl_cui_uint64_c(0x23e671bcul, 0xf015c209ul), mk_sl_cui_uint64_c(0x20c71430ul, 0x4a860331ul),
		mk_sl_cui_uint64_c(0x292032b3ul, 0x4b587e99ul), mk_sl_cui_uint64_c(0x2a01573ful, 0xf1cbbfa1ul), mk_sl_cui_uint64_c(0x2f62f8b6ul, 0x2263e1e9ul), mk_sl_cui_uint64_c(0x2c439d3aul, 0x98f020d1ul),
		mk_sl_cui_uint64_c(0x0d9baa85ul, 0x4f079703ul), mk_sl_cui_uint64_c(0x0ebacf09ul, 0xf594563bul), mk_sl_cui_uint64_c(0x0bd96080ul, 0x263c0873ul), mk_sl_cui_uint64_c(0x08f8050cul, 0x9cafc94bul),
		mk_sl_cui_uint64_c(0x011f238ful, 0x9d71b4e3ul), mk_sl_cui_uint64_c(0x023e4603ul, 0x27e275dbul), mk_sl_cui_uint64_c(0x075de98aul, 0xf44a2b93ul), mk_sl_cui_uint64_c(0x047c8c06ul, 0x4ed9eaabul),
		mk_sl_cui_uint64_c(0x158ea591ul, 0xf6ebd1deul), mk_sl_cui_uint64_c(0x16afc01dul, 0x4c7810e6ul), mk_sl_cui_uint64_c(0x13cc6f94ul, 0x9fd04eaeul), mk_sl_cui_uint64_c(0x10ed0a18ul, 0x25438f96ul),
		mk_sl_cui_uint64_c(0x190a2c9bul, 0x249df23eul), mk_sl_cui_uint64_c(0x1a2b4917ul, 0x9e0e3306ul), mk_sl_cui_uint64_c(0x1f48e69eul, 0x4da66d4eul), mk_sl_cui_uint64_c(0x1c698312ul, 0xf735ac76ul),
	},
	{
		mk_sl_cui_uint64_c(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_c(0xaccc9ca9ul, 0x328a8950ul), mk_sl_cui_uint64_c(0x4585254ful, 0x64090fa0ul), mk_sl_cui_uint64_c(0xe949b9e6ul, 0x568386f0ul),
		mk_sl_cui_uint64_c(0x8a174a9eul, 0xc8121e5dul), mk_sl_cui_uint64_c(0x26dbd637ul, 0xfa98970dul), mk_sl_cui_uint64_c(0xcf926fd1ul, 0xac1b11fdul), mk_sl_cui_uint64_c(0x635ef378ul, 0x9e9198adul),
		mk_sl_cui_uint64_c(0x092e9421ul, 0x8d243cbaul), mk_sl_cui_uint64_c(0xa5e20888ul, 0xbfaeb5eaul), mk_sl_cui_uint64_c(0x4cabb16eul, 0xe92d331aul), mk_sl_cui_uint64_c(0xe0672dc7ul, 0xdba7ba4aul),
		mk_sl_cui_uint64_c(0x8339debful, 0x453622e7ul), mk_sl_cui_uint64_c(0x2ff54216ul, 0x77bcabb7ul), mk_sl_cui_uint64_c(0xc6bcfbf0ul, 0x213f2d47ul), mk_sl_cui_uint64_c(0x6a706759ul, 0x13b5a417ul),
		mk_sl_cui_uint64_c(0x125c3542ul, 0x07487869ul), mk_sl_cui_uint64_c(0xbe90a9ebul, 0x35c2f139ul), mk_sl_cui_uint64_c(0x57d9100dul, 0x634177c9ul), mk_sl_cui_uint64_c(0xfb158ca4ul, 0x51cbfe99ul),
		mk_sl_cui_uint64_c(0x984b7fdcul, 0xcf5a6634ul), mk_sl_cui_uint64_c(0x3487e375ul, 0xfdd0ef64ul), mk_sl_cui_uint64_c(0xddce5a93ul, 0xab536994ul), mk_sl_cui_uint64_c(0x7102c63aul, 0x99d9e0c4ul),
		mk_sl_cui_uint64_c(0x1b72a163ul, 0x8a6c44d3ul), mk_sl_cui_uint64_c(0xb7be3dcaul, 0xb8e6cd83ul), mk_sl_cui_uint64_c(0x5ef7842cul, 0xee654b73ul), mk_sl_cui_uint64_c(0xf23b1885ul, 0xdcefc223ul),
		mk_sl_cui_uint64_c(0x9165ebfdul, 0x427e5a8eul), mk_sl_cui_uint64_c(0x3da97754ul, 0x70f4d3deul), mk_sl_cui_uint64_c(0xd4e0ceb2ul, 0x2677552eul), mk_sl_cui_uint64_c(0x782c521bul, 0x14fddc7eul),
		mk_sl_cui_uint64_c(0x24b86a84ul, 0x0e90f0d2ul), mk_sl_cui_uint64_c(0x8874f62dul, 0x3c1a7982ul), mk_sl_cui_uint64_c(0x613d4fcbul, 0x6a99ff72ul), mk_sl_cui_uint64_c(0xcdf1d362ul, 0x58137622ul),
		mk_sl_cui_uint64_c(0xaeaf201aul, 0xc682ee8ful), mk_sl_cui_uint64_c(0x0263bcb3ul, 0xf40867dful), mk_sl_cui_uint64_c(0xeb2a0555ul, 0xa28be12ful), mk_sl_cui_uint64_c(0x47e699fcul, 0x9001687ful),
		mk_sl_cui_uint64_c(0x2d96fea5ul, 0x83b4cc68ul), mk_sl_cui_uint64_c(0x815a620cul, 0xb13e4538ul), mk_sl_cui_uint64_c(0x6813dbeaul, 0xe7bdc3c8ul), mk_sl_cui_uint64_c(0xc4df4743ul, 0xd5374a98ul),
		mk_sl_cui_uint64_c(0xa781b43bul, 0x4ba6d235ul), mk_sl_cui_uint64_c(0x0b4d2892ul, 0x792c5b65ul), mk_sl_cui_uint64_c(0xe2049174ul, 0x2fafdd95ul), mk_sl_cui_uint64_c(0x4ec80dddul, 0x1d2554c5ul),
		mk_sl_cui_uint64_c(0x36e45fc6ul, 0x09d888bbul), mk_sl_cui_uint64_c(0x9a28c36ful, 0x3b5201ebul), mk_sl_cui_uint64_c(0x73617a89ul, 0x6dd1871bul), mk_sl_cui_uint64_c(0xdfade620ul, 0x5f5b0e4bul),
		mk_sl_cui_uint64_c(0xbcf31558ul, 0xc1ca96e6ul), mk_sl_cui_uint64_c(0x103f89f1ul, 0xf3401fb6ul), mk_sl_cui_uint64_c(0xf9763017ul, 0xa5c39946ul), mk_sl_cui_uint64_c(0x55baacbeul, 0x97491016ul),
		mk_sl_cui_uint64_c(0x3fcacbe7ul, 0x84fcb401ul), mk_sl_cui_uint64_c(0x9306574eul, 0xb6763d51ul), mk_sl_cui_uint64_c(0x7a4feea8ul, 0xe0f5bba1ul), mk_sl_cui_uint64_c(0xd6837201ul, 0xd27f32f1ul),
		mk_sl_cui_uint64_c(0xb5dd8179ul, 0x4ceeaa5cul), mk_sl_cui_uint64_c(0x19111dd0ul, 0x7e64230cul), mk_sl_cui_uint64_c(0xf058a436ul, 0x28e7a5fcul), mk_sl_cui_uint64_c(0x5c94389ful, 0x1a6d2cacul),
		mk_sl_cui_uint64_c(0x486dd415ul, 0x1c3dfdb9ul), mk_sl_cui_uint64_c(0xe4a148bcul, 0x2eb774e9ul), mk_sl_cui_uint64_c(0x0de8f15aul, 0x7834f219ul), mk_sl_cui_uint64_c(0xa1246df3ul, 0x4abe7b49ul),
		mk_sl_cui_uint64_c(0xc27a9e8bul, 0xd42fe3e4ul), mk_sl_cui_uint64_c(0x6eb60222ul, 0xe6a56ab4ul), mk_sl_cui_uint64_c(0x87ffbbc4ul, 0xb026ec44ul), mk_sl_cui_uint64_c(0x2b33276dul, 0x82ac6514ul),
		mk_sl_cui_uint64_c(0x41434034ul, 0x9119c103ul), mk_sl_cui_uint64_c(0xed8fdc9dul, 0xa3934853ul), mk_sl_cui_uint64_c(0x04c6657bul, 0xf510cea3ul), mk_sl_cui_uint64_c(0xa80af9d2ul, 0xc79a47f3ul),
		mk_sl_cui_uint64_c(0xcb540aaaul, 0x590bdf5eul), mk_sl_cui_uint64_c(0x67989603ul, 0x6b81560eul), mk_sl_cui_uint64_c(0x8ed12fe5ul, 0x3d02d0feul), mk_sl_cui_uint64_c(0x221db34cul, 0x0f8859aeul),
		mk_sl_cui_uint64_c(0x5a31e157ul, 0x1b7585d0ul), mk_sl_cui_uint64_c(0xf6fd7dfeul, 0x29ff0c80ul), mk_sl_cui_uint64_c(0x1fb4c418ul, 0x7f7c8a70ul), mk_sl_cui_uint64_c(0xb37858b1ul, 0x4df60320ul),
		mk_sl_cui_uint64_c(0xd026abc9ul, 0xd3679b8dul), mk_sl_cui_uint64_c(0x7cea3760ul, 0xe1ed12ddul), mk_sl_cui_uint64_c(0x95a38e86ul, 0xb76e942dul), mk_sl_cui_uint64_c(0x396f122ful, 0x85e41d7dul),
		mk_sl_cui_uint64_c(0x531f7576ul, 0x9651b96aul), mk_sl_cui_uint64_c(0xffd3e9dful, 0xa4db303aul), mk_sl_cui_uint64_c(0x169a5039ul, 0xf258b6caul), mk_sl_cui_uint64_c(0xba56cc90ul, 0xc0d23f9aul),
		mk_sl_cui_uint64_c(0xd9083fe8ul, 0x5e43a737ul), mk_sl_cui_uint64_c(0x75c4a341ul, 0x6cc92e67ul), mk_sl_cui_uint64_c(0x9c8d1aa7ul, 0x3a4aa897ul), mk_sl_cui_uint64_c(0x3041860eul, 0x08c021c7ul),
		mk_sl_cui_uint64_c(0x6cd5be91ul, 0x12ad0d6bul), mk_sl_cui_uint64_c(0xc0192238ul, 0x2027843bul), mk_sl_cui_uint64_c(0x29509bdeul, 0x76a402cbul), mk_sl_cui_uint64_c(0x859c0777ul, 0x442e8b9bul),
		mk_sl_cui_uint64_c(0xe6c2f40ful, 0xdabf1336ul), mk_sl_cui_uint64_c(0x4a0e68a6ul, 0xe8359a66ul), mk_sl_cui_uint64_c(0xa347d140ul, 0xbeb61c96ul), mk_sl_cui_uint64_c(0x0f8b4de9ul, 0x8c3c95c6ul),
		mk_sl_cui_uint64_c(0x65fb2ab0ul, 0x9f8931d1ul), mk_sl_cui_uint64_c(0xc937b619ul, 0xad03b881ul), mk_sl_cui_uint64_c(0x207e0ffful, 0xfb803e71ul), mk_sl_cui_uint64_c(0x8cb29356ul, 0xc90ab721ul),
		mk_sl_cui_uint64_c(0xefec602eul, 0x579b2f8cul), mk_sl_cui_uint64_c(0x4320fc87ul, 0x6511a6dcul), mk_sl_cui_uint64_c(0xaa694561ul, 0x3392202cul), mk_sl_cui_uint64_c(0x06a5d9c8ul, 0x0118a97cul),
		mk_sl_cui_uint64_c(0x7e898bd3ul, 0x15e57502ul), mk_sl_cui_uint64_c(0xd245177aul, 0x276ffc52ul), mk_sl_cui_uint64_c(0x3b0cae9cul, 0x71ec7aa2ul), mk_sl_cui_uint64_c(0x97c03235ul, 0x4366f3f2ul),
		mk_sl_cui_uint64_c(0xf49ec14dul, 0xddf76b5ful), mk_sl_cui_uint64_c(0x58525de4ul, 0xef7de20ful), mk_sl_cui_uint64_c(0xb11be402ul, 0xb9fe64fful), mk_sl_cui_uint64_c(0x1dd778abul, 0x8b74edaful),
		mk_sl_cui_uint64_c(0x77a71ff2ul, 0x98c149b8ul), mk_sl_cui_uint64_c(0xdb6b835bul, 0xaa4bc0e8ul), mk_sl_cui_uint64_c(0x32223abdul, 0xfcc84618ul), mk_sl_cui_uint64_c(0x9eeea614ul, 0xce42cf48ul),
		mk_sl_cui_uint64_c(0xfdb0556cul, 0x50d357e5ul), mk_sl_cui_uint64_c(0x517cc9c5ul, 0x6259deb5ul), mk_sl_cui_uint64_c(0xb8357023ul, 0x34da5845ul), mk_sl_cui_uint64_c(0x14f9ec8aul, 0x0650d115ul),
		mk_sl_cui_uint64_c(0x90dab52aul, 0x387ae76ful), mk_sl_cui_uint64_c(0x3c162983ul, 0x0af06e3ful), mk_sl_cui_uint64_c(0xd55f9065ul, 0x5c73e8cful), mk_sl_cui_uint64_c(0x79930cccul, 0x6ef9619ful),
		mk_sl_cui_uint64_c(0x1acdffb4ul, 0xf068f932ul), mk_sl_cui_uint64_c(0xb601631dul, 0xc2e27062ul), mk_sl_cui_uint64_c(0x5f48dafbul, 0x9461f692ul), mk_sl_cui_uint64_c(0xf3844652ul, 0xa6eb7fc2ul),
		mk_sl_cui_uint64_c(0x99f4210bul, 0xb55edbd5ul), mk_sl_cui_uint64_c(0x3538bda2ul, 0x87d45285ul), mk_sl_cui_uint64_c(0xdc710444ul, 0xd157d475ul), mk_sl_cui_uint64_c(0x70bd98edul, 0xe3dd5d25ul),
		mk_sl_cui_uint64_c(0x13e36b95ul, 0x7d4cc588ul), mk_sl_cui_uint64_c(0xbf2ff73cul, 0x4fc64cd8ul), mk_sl_cui_uint64_c(0x56664edaul, 0x1945ca28ul), mk_sl_cui_uint64_c(0xfaaad273ul, 0x2bcf4378ul),
		mk_sl_cui_uint64_c(0x82868068ul, 0x3f329f06ul), mk_sl_cui_uint64_c(0x2e4a1cc1ul, 0x0db81656ul), mk_sl_cui_uint64_c(0xc703a527ul, 0x5b3b90a6ul), mk_sl_cui_uint64_c(0x6bcf398eul, 0x69b119f6ul),
		mk_sl_cui_uint64_c(0x0891caf6ul, 0xf720815bul), mk_sl_cui_uint64_c(0xa45d565ful, 0xc5aa080bul), mk_sl_cui_uint64_c(0x4d14efb9ul, 0x93298efbul), mk_sl_cui_uint64_c(0xe1d87310ul, 0xa1a307abul),
		mk_sl_cui_uint64_c(0x8ba81449ul, 0xb216a3bcul), mk_sl_cui_uint64_c(0x276488e0ul, 0x809c2aecul), mk_sl_cui_uint64_c(0xce2d3106ul, 0xd61fac1cul), mk_sl_cui_uint64_c(0x62e1adaful, 0xe495254cul),
		mk_sl_cui_uint64_c(0x01bf5ed7ul, 0x7a04bde1ul), mk_sl_cui_uint64_c(0xad73c27eul, 0x488e34b1ul), mk_sl_cui_uint64_c(0x443a7b98ul, 0x1e0db241ul), mk_sl_cui_uint64_c(0xe8f6e731ul, 0x2c873b11ul),
		mk_sl_cui_uint64_c(0xb462dfaeul, 0x36ea17bdul), mk_sl_cui_uint64_c(0x18ae4307ul, 0x04609eedul), mk_sl_cui_uint64_c(0xf1e7fae1ul, 0x52e3181dul), mk_sl_cui_uint64_c(0x5d2b6648ul, 0x6069914dul),
		mk_sl_cui_uint64_c(0x3e759530ul, 0xfef809e0ul), mk_sl_cui_uint64_c(0x92b90999ul, 0xcc7280b0ul), mk_sl_cui_uint64_c(0x7bf0b07ful, 0x9af10640ul), mk_sl_cui_uint64_c(0xd73c2cd6ul, 0xa87b8f10ul),
		mk_sl_cui_uint64_c(0xbd4c4b8ful, 0xbbce2b07ul), mk_sl_cui_uint64_c(0x1180d726ul, 0x8944a257ul), mk_sl_cui_uint64_c(0xf8c96ec0ul, 0xdfc724a7ul), mk_sl_cui_uint64_c(0x5405f269ul, 0xed4dadf7ul),
		mk_sl_cui_uint64_c(0x375b0111ul, 0x73dc355aul), mk_sl_cui_uint64_c(0x9b979db8ul, 0x4156bc0aul), mk_sl_cui_uint64_c(0x72de245eul, 0x17d53afaul), mk_sl_cui_uint64_c(0xde12b8f7ul, 0x255fb3aaul),
		mk_sl_cui_uint64_c(0xa63eeaecul, 0x31a26fd4ul), mk_sl_cui_uint64_c(0x0af27645ul, 0x0328e684ul), mk_sl_cui_uint64_c(0xe3bbcfa3ul, 0x55ab6074ul), mk_sl_cui_uint64_c(0x4f77530aul, 0x6721e924ul),
		mk_sl_cui_uint64_c(0x2c29a072ul, 0xf9b07189ul), mk_sl_cui_uint64_c(0x80e53cdbul, 0xcb3af8d9ul), mk_sl_cui_uint64_c(0x69ac853dul, 0x9db97e29ul), mk_sl_cui_uint64_c(0xc5601994ul, 0xaf33f779ul),
		mk_sl_cui_uint64_c(0xaf107ecdul, 0xbc86536eul), mk_sl_cui_uint64_c(0x03dce264ul, 0x8e0cda3eul), mk_sl_cui_uint64_c(0xea955b82ul, 0xd88f5cceul), mk_sl_cui_uint64_c(0x4659c72bul, 0xea05d59eul),
		mk_sl_cui_uint64_c(0x25073453ul, 0x74944d33ul), mk_sl_cui_uint64_c(0x89cba8faul, 0x461ec463ul), mk_sl_cui_uint64_c(0x6082111cul, 0x109d4293ul), mk_sl_cui_uint64_c(0xcc4e8db5ul, 0x2217cbc3ul),
		mk_sl_cui_uint64_c(0xd8b7613ful, 0x24471ad6ul), mk_sl_cui_uint64_c(0x747bfd96ul, 0x16cd9386ul), mk_sl_cui_uint64_c(0x9d324470ul, 0x404e1576ul), mk_sl_cui_uint64_c(0x31fed8d9ul, 0x72c49c26ul),
		mk_sl_cui_uint64_c(0x52a02ba1ul, 0xec55048bul), mk_sl_cui_uint64_c(0xfe6cb708ul, 0xdedf8ddbul), mk_sl_cui_uint64_c(0x17250eeeul, 0x885c0b2bul), mk_sl_cui_uint64_c(0xbbe99247ul, 0xbad6827bul),
		mk_sl_cui_uint64_c(0xd199f51eul, 0xa963266cul), mk_sl_cui_uint64_c(0x7d5569b7ul, 0x9be9af3cul), mk_sl_cui_uint64_c(0x941cd051ul, 0xcd6a29ccul), mk_sl_cui_uint64_c(0x38d04cf8ul, 0xffe0a09cul),
		mk_sl_cui_uint64_c(0x5b8ebf80ul, 0x61713831ul), mk_sl_cui_uint64_c(0xf7422329ul, 0x53fbb161ul), mk_sl_cui_uint64_c(0x1e0b9acful, 0x05783791ul), mk_sl_cui_uint64_c(0xb2c70666ul, 0x37f2bec1ul),
		mk_sl_cui_uint64_c(0xcaeb547dul, 0x230f62bful), mk_sl_cui_uint64_c(0x6627c8d4ul, 0x1185ebeful), mk_sl_cui_uint64_c(0x8f6e7132ul, 0x47066d1ful), mk_sl_cui_uint64_c(0x23a2ed9bul, 0x758ce44ful),
		mk_sl_cui_uint64_c(0x40fc1ee3ul, 0xeb1d7ce2ul), mk_sl_cui_uint64_c(0xec30824aul, 0xd997f5b2ul), mk_sl_cui_uint64_c(0x05793bacul, 0x8f147342ul), mk_sl_cui_uint64_c(0xa9b5a705ul, 0xbd9efa12ul),
		mk_sl_cui_uint64_c(0xc3c5c05cul, 0xae2b5e05ul), mk_sl_cui_uint64_c(0x6f095cf5ul, 0x9ca1d755ul), mk_sl_cui_uint64_c(0x8640e513ul, 0xca2251a5ul), mk_sl_cui_uint64_c(0x2a8c79baul, 0xf8a8d8f5ul),
		mk_sl_cui_uint64_c(0x49d28ac2ul, 0x66394058ul), mk_sl_cui_uint64_c(0xe51e166bul, 0x54b3c908ul), mk_sl_cui_uint64_c(0x0c57af8dul, 0x02304ff8ul), mk_sl_cui_uint64_c(0xa09b3324ul, 0x30bac6a8ul),
		mk_sl_cui_uint64_c(0xfc0f0bbbul, 0x2ad7ea04ul), mk_sl_cui_uint64_c(0x50c39712ul, 0x185d6354ul), mk_sl_cui_uint64_c(0xb98a2ef4ul, 0x4edee5a4ul), mk_sl_cui_uint64_c(0x1546b25dul, 0x7c546cf4ul),
		mk_sl_cui_uint64_c(0x76184125ul, 0xe2c5f459ul), mk_sl_cui_uint64_c(0xdad4dd8cul, 0xd04f7d09ul), mk_sl_cui_uint64_c(0x339d646aul, 0x86ccfbf9ul), mk_sl_cui_uint64_c(0x9f51f8c3ul, 0xb44672a9ul),
		mk_sl_cui_uint64_c(0xf5219f9aul, 0xa7f3d6beul), mk_sl_cui_uint64_c(0x59ed0333ul, 0x95795feeul), mk_sl_cui_uint64_c(0xb0a4bad5ul, 0xc3fad91eul), mk_sl_cui_uint64_c(0x1c68267cul, 0xf170504eul),
		mk_sl_cui_uint64_c(0x7f36d504ul, 0x6fe1c8e3ul), mk_sl_cui_uint64_c(0xd3fa49adul, 0x5d6b41b3ul), mk_sl_cui_uint64_c(0x3ab3f04bul, 0x0be8c743ul), mk_sl_cui_uint64_c(0x967f6ce2ul, 0x39624e13ul),
		mk_sl_cui_uint64_c(0xee533ef9ul, 0x2d9f926dul), mk_sl_cui_uint64_c(0x429fa250ul, 0x1f151b3dul), mk_sl_cui_uint64_c(0xabd61bb6ul, 0x49969dcdul), mk_sl_cui_uint64_c(0x071a871ful, 0x7b1c149dul),
		mk_sl_cui_uint64_c(0x64447467ul, 0xe58d8c30ul), mk_sl_cui_uint64_c(0xc888e8ceul, 0xd7070560ul), mk_sl_cui_uint64_c(0x21c15128ul, 0x81848390ul), mk_sl_cui_uint64_c(0x8d0dcd81ul, 0xb30e0ac0ul),
		mk_sl_cui_uint64_c(0xe77daad8ul, 0xa0bbaed7ul), mk_sl_cui_uint64_c(0x4bb13671ul, 0x92312787ul), mk_sl_cui_uint64_c(0xa2f88f97ul, 0xc4b2a177ul), mk_sl_cui_uint64_c(0x0e34133eul, 0xf6382827ul),
		mk_sl_cui_uint64_c(0x6d6ae046ul, 0x68a9b08aul), mk_sl_cui_uint64_c(0xc1a67ceful, 0x5a2339daul), mk_sl_cui_uint64_c(0x28efc509ul, 0x0ca0bf2aul), mk_sl_cui_uint64_c(0x842359a0ul, 0x3e2a367aul),
	},
	{
		mk_sl_cui_uint64_c(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_c(0x46b60f01ul, 0x1a83988eul), mk_sl_cui_uint64_c(0x8c711e02ul, 0x341b2d01ul), mk_sl_cui_uint64_c(0xcac71103ul, 0x2e98b58ful),
		mk_sl_cui_uint64_c(0x05e23c04ul, 0x68365a02ul), mk_sl_cui_uint64_c(0x43543305ul, 0x72b5c28cul), mk_sl_cui_uint64_c(0x89932206ul, 0x5c2d7703ul), mk_sl_cui_uint64_c(0xcf252d07ul, 0x46aeef8dul),
		mk_sl_cui_uint64_c(0x0ad97808ul, 0xd06cb404ul), mk_sl_cui_uint64_c(0x4c6f7709ul, 0xcaef2c8aul), mk_sl_cui_uint64_c(0x86a8660aul, 0xe4779905ul), mk_sl_cui_uint64_c(0xc01e690bul, 0xfef4018bul),
		mk_sl_cui_uint64_c(0x0f3b440cul, 0xb85aee06ul), mk_sl_cui_uint64_c(0x498d4b0dul, 0xa2d97688ul), mk_sl_cui_uint64_c(0x834a5a0eul, 0x8c41c307ul), mk_sl_cui_uint64_c(0xc5fc550ful, 0x96c25b89ul),
		mk_sl_cui_uint64_c(0x14aff010ul, 0xbdd87508ul), mk_sl_cui_uint64_c(0x5219ff11ul, 0xa75bed86ul), mk_sl_cui_uint64_c(0x98deee12ul, 0x89c35809ul), mk_sl_cui_uint64_c(0xde68e113ul, 0x9340c087ul),
		mk_sl_cui_uint64_c(0x114dcc14ul, 0xd5ee2f0aul), mk_sl_cui_uint64_c(0x57fbc315ul, 0xcf6db784ul), mk_sl_cui_uint64_c(0x9d3cd216ul, 0xe1f5020bul), mk_sl_cui_uint64_c(0xdb8add17ul, 0xfb769a85ul),
		mk_sl_cui_uint64_c(0x1e768818ul, 0x6db4c10cul), mk_sl_cui_uint64_c(0x58c08719ul, 0x77375982ul), mk_sl_cui_uint64_c(0x9207961aul, 0x59afec0dul), mk_sl_cui_uint64_c(0xd4b1991bul, 0x432c7483ul),
		mk_sl_cui_uint64_c(0x1b94b41cul, 0x05829b0eul), mk_sl_cui_uint64_c(0x5d22bb1dul, 0x1f010380ul), mk_sl_cui_uint64_c(0x97e5aa1eul, 0x3199b60ful), mk_sl_cui_uint64_c(0xd153a51ful, 0x2b1a2e81ul),
		mk_sl_cui_uint64_c(0x2843fd20ul, 0x67adea10ul), mk_sl_cui_uint64_c(0x6ef5f221ul, 0x7d2e729eul), mk_sl_cui_uint64_c(0xa432e322ul, 0x53b6c711ul), mk_sl_cui_uint64_c(0xe284ec23ul, 0x49355f9ful),
		mk_sl_cui_uint64_c(0x2da1c124ul, 0x0f9bb012ul), mk_sl_cui_uint64_c(0x6b17ce25ul, 0x1518289cul), mk_sl_cui_uint64_c(0xa1d0df26ul, 0x3b809d13ul), mk_sl_cui_uint64_c(0xe766d027ul, 0x2103059dul),
		mk_sl_cui_uint64_c(0x229a8528ul, 0xb7c15e14ul), mk_sl_cui_uint64_c(0x642c8a29ul, 0xad42c69aul), mk_sl_cui_uint64_c(0xaeeb9b2aul, 0x83da7315ul), mk_sl_cui_uint64_c(0xe85d942bul, 0x9959eb9bul),
		mk_sl_cui_uint64_c(0x2778b92cul, 0xdff70416ul), mk_sl_cui_uint64_c(0x61ceb62dul, 0xc5749c98ul), mk_sl_cui_uint64_c(0xab09a72eul, 0xebec2917ul), mk_sl_cui_uint64_c(0xedbfa82ful, 0xf16fb199ul),
		mk_sl_cui_uint64_c(0x3cec0d30ul, 0xda759f18ul), mk_sl_cui_uint64_c(0x7a5a0231ul, 0xc0f60796ul), mk_sl_cui_uint64_c(0xb09d1332ul, 0xee6eb219ul), mk_sl_cui_uint64_c(0xf62b1c33ul, 0xf4ed2a97ul),
		mk_sl_cui_uint64_c(0x390e3134ul, 0xb243c51aul), mk_sl_cui_uint64_c(0x7fb83e35ul, 0xa8c05d94ul), mk_sl_cui_uint64_c(0xb57f2f36ul, 0x8658e81bul), mk_sl_cui_uint64_c(0xf3c92037ul, 0x9cdb7095ul),
		mk_sl_cui_uint64_c(0x36357538ul, 0x0a192b1cul), mk_sl_cui_uint64_c(0x70837a39ul, 0x109ab392ul), mk_sl_cui_uint64_c(0xba446b3aul, 0x3e02061dul), mk_sl_cui_uint64_c(0xfcf2643bul, 0x24819e93ul),
		mk_sl_cui_uint64_c(0x33d7493cul, 0x622f711eul), mk_sl_cui_uint64_c(0x7561463dul, 0x78ace990ul), mk_sl_cui_uint64_c(0xbfa6573eul, 0x56345c1ful), mk_sl_cui_uint64_c(0xf910583ful, 0x4cb7c491ul),
		mk_sl_cui_uint64_c(0x5086e740ul, 0xce47c920ul), mk_sl_cui_uint64_c(0x1630e841ul, 0xd4c451aeul), mk_sl_cui_uint64_c(0xdcf7f942ul, 0xfa5ce421ul), mk_sl_cui_uint64_c(0x9a41f643ul, 0xe0df7caful),
		mk_sl_cui_uint64_c(0x5564db44ul, 0xa6719322ul), mk_sl_cui_uint64_c(0x13d2d445ul, 0xbcf20bacul), mk_sl_cui_uint64_c(0xd915c546ul, 0x926abe23ul), mk_sl_cui_uint64_c(0x9fa3ca47ul, 0x88e926adul),
		mk_sl_cui_uint64_c(0x5a5f9f48ul, 0x1e2b7d24ul), mk_sl_cui_uint64_c(0x1ce99049ul, 0x04a8e5aaul), mk_sl_cui_uint64_c(0xd62e814aul, 0x2a305025ul), mk_sl_cui_uint64_c(0x90988e4bul, 0x30b3c8abul),
		mk_sl_cui_uint64_c(0x5fbda34cul, 0x761d2726ul), mk_sl_cui_uint64_c(0x190bac4dul, 0x6c9ebfa8ul), mk_sl_cui_uint64_c(0xd3ccbd4eul, 0x42060a27ul), mk_sl_cui_uint64_c(0x957ab24ful, 0x588592a9ul),
		mk_sl_cui_uint64_c(0x44291750ul, 0x739fbc28ul), mk_sl_cui_uint64_c(0x029f1851ul, 0x691c24a6ul), mk_sl_cui_uint64_c(0xc8580952ul, 0x47849129ul), mk_sl_cui_uint64_c(0x8eee0653ul, 0x5d0709a7ul),
		mk_sl_cui_uint64_c(0x41cb2b54ul, 0x1ba9e62aul), mk_sl_cui_uint64_c(0x077d2455ul, 0x012a7ea4ul), mk_sl_cui_uint64_c(0xcdba3556ul, 0x2fb2cb2bul), mk_sl_cui_uint64_c(0x8b0c3a57ul, 0x353153a5ul),
		mk_sl_cui_uint64_c(0x4ef06f58ul, 0xa3f3082cul), mk_sl_cui_uint64_c(0x08466059ul, 0xb97090a2ul), mk_sl_cui_uint64_c(0xc281715aul, 0x97e8252dul), mk_sl_cui_uint64_c(0x84377e5bul, 0x8d6bbda3ul),
		mk_sl_cui_uint64_c(0x4b12535cul, 0xcbc5522eul), mk_sl_cui_uint64_c(0x0da45c5dul, 0xd146caa0ul), mk_sl_cui_uint64_c(0xc7634d5eul, 0xffde7f2ful), mk_sl_cui_uint64_c(0x81d5425ful, 0xe55de7a1ul),
		mk_sl_cui_uint64_c(0x78c51a60ul, 0xa9ea2330ul), mk_sl_cui_uint64_c(0x3e731561ul, 0xb369bbbeul), mk_sl_cui_uint64_c(0xf4b40462ul, 0x9df10e31ul), mk_sl_cui_uint64_c(0xb2020b63ul, 0x877296bful),
		mk_sl_cui_uint64_c(0x7d272664ul, 0xc1dc7932ul), mk_sl_cui_uint64_c(0x3b912965ul, 0xdb5fe1bcul), mk_sl_cui_uint64_c(0xf1563866ul, 0xf5c75433ul), mk_sl_cui_uint64_c(0xb7e03767ul, 0xef44ccbdul),
		mk_sl_cui_uint64_c(0x721c6268ul, 0x79869734ul), mk_sl_cui_uint64_c(0x34aa6d69ul, 0x63050fbaul), mk_sl_cui_uint64_c(0xfe6d7c6aul, 0x4d9dba35ul), mk_sl_cui_uint64_c(0xb8db736bul, 0x571e22bbul),
		mk_sl_cui_uint64_c(0x77fe5e6cul, 0x11b0cd36ul), mk_sl_cui_uint64_c(0x3148516dul, 0x0b3355b8ul), mk_sl_cui_uint64_c(0xfb8f406eul, 0x25abe037ul), mk_sl_cui_uint64_c(0xbd394f6ful, 0x3f2878b9ul),
		mk_sl_cui_uint64_c(0x6c6aea70ul, 0x14325638ul), mk_sl_cui_uint64_c(0x2adce571ul, 0x0eb1ceb6ul), mk_sl_cui_uint64_c(0xe01bf472ul, 0x20297b39ul), mk_sl_cui_uint64_c(0xa6adfb73ul, 0x3aaae3b7ul),
		mk_sl_cui_uint64_c(0x6988d674ul, 0x7c040c3aul), mk_sl_cui_uint64_c(0x2f3ed975ul, 0x668794b4ul), mk_sl_cui_uint64_c(0xe5f9c876ul, 0x481f213bul), mk_sl_cui_uint64_c(0xa34fc777ul, 0x529cb9b5ul),
		mk_sl_cui_uint64_c(0x66b39278ul, 0xc45ee23cul), mk_sl_cui_uint64_c(0x20059d79ul, 0xdedd7ab2ul), mk_sl_cui_uint64_c(0xeac28c7aul, 0xf045cf3dul), mk_sl_cui_uint64_c(0xac74837bul, 0xeac657b3ul),
		mk_sl_cui_uint64_c(0x6351ae7cul, 0xac68b83eul), mk_sl_cui_uint64_c(0x25e7a17dul, 0xb6eb20b0ul), mk_sl_cui_uint64_c(0xef20b07eul, 0x9873953ful), mk_sl_cui_uint64_c(0xa996bf7ful, 0x82f00db1ul),
		mk_sl_cui_uint64_c(0xa011d380ul, 0x818e8f40ul), mk_sl_cui_uint64_c(0xe6a7dc81ul, 0x9b0d17ceul), mk_sl_cui_uint64_c(0x2c60cd82ul, 0xb595a241ul), mk_sl_cui_uint64_c(0x6ad6c283ul, 0xaf163acful),
		mk_sl_cui_uint64_c(0xa5f3ef84ul, 0xe9b8d542ul), mk_sl_cui_uint64_c(0xe345e085ul, 0xf33b4dccul), mk_sl_cui_uint64_c(0x2982f186ul, 0xdda3f843ul), mk_sl_cui_uint64_c(0x6f34fe87ul, 0xc72060cdul),
		mk_sl_cui_uint64_c(0xaac8ab88ul, 0x51e23b44ul), mk_sl_cui_uint64_c(0xec7ea489ul, 0x4b61a3caul), mk_sl_cui_uint64_c(0x26b9b58aul, 0x65f91645ul), mk_sl_cui_uint64_c(0x600fba8bul, 0x7f7a8ecbul),
		mk_sl_cui_uint64_c(0xaf2a978cul, 0x39d46146ul), mk_sl_cui_uint64_c(0xe99c988dul, 0x2357f9c8ul), mk_sl_cui_uint64_c(0x235b898eul, 0x0dcf4c47ul), mk_sl_cui_uint64_c(0x65ed868ful, 0x174cd4c9ul),
		mk_sl_cui_uint64_c(0xb4be2390ul, 0x3c56fa48ul), mk_sl_cui_uint64_c(0xf2082c91ul, 0x26d562c6ul), mk_sl_cui_uint64_c(0x38cf3d92ul, 0x084dd749ul), mk_sl_cui_uint64_c(0x7e793293ul, 0x12ce4fc7ul),
		mk_sl_cui_uint64_c(0xb15c1f94ul, 0x5460a04aul), mk_sl_cui_uint64_c(0xf7ea1095ul, 0x4ee338c4ul), mk_sl_cui_uint64_c(0x3d2d0196ul, 0x607b8d4bul), mk_sl_cui_uint64_c(0x7b9b0e97ul, 0x7af815c5ul),
		mk_sl_cui_uint64_c(0xbe675b98ul, 0xec3a4e4cul), mk_sl_cui_uint64_c(0xf8d15499ul, 0xf6b9d6c2ul), mk_sl_cui_uint64_c(0x3216459aul, 0xd821634dul), mk_sl_cui_uint64_c(0x74a04a9bul, 0xc2a2fbc3ul),
		mk_sl_cui_uint64_c(0xbb85679cul, 0x840c144eul), mk_sl_cui_uint64_c(0xfd33689dul, 0x9e8f8cc0ul), mk_sl_cui_uint64_c(0x37f4799eul, 0xb017394ful), mk_sl_cui_uint64_c(0x7142769ful, 0xaa94a1c1ul),
		mk_sl_cui_uint64_c(0x88522ea0ul, 0xe6236550ul), mk_sl_cui_uint64_c(0xcee421a1ul, 0xfca0fddeul), mk_sl_cui_uint64_c(0x042330a2ul, 0xd2384851ul), mk_sl_cui_uint64_c(0x42953fa3ul, 0xc8bbd0dful),
		mk_sl_cui_uint64_c(0x8db012a4ul, 0x8e153f52ul), mk_sl_cui_uint64_c(0xcb061da5ul, 0x9496a7dcul), mk_sl_cui_uint64_c(0x01c10ca6ul, 0xba0e1253ul), mk_sl_cui_uint64_c(0x477703a7ul, 0xa08d8addul),
		mk_sl_cui_uint64_c(0x828b56a8ul, 0x364fd154ul), mk_sl_cui_uint64_c(0xc43d59a9ul, 0x2ccc49daul), mk_sl_cui_uint64_c(0x0efa48aaul, 0x0254fc55ul), mk_sl_cui_uint64_c(0x484c47abul, 0x18d764dbul),
		mk_sl_cui_uint64_c(0x87696aacul, 0x5e798b56ul), mk_sl_cui_uint64_c(0xc1df65adul, 0x44fa13d8ul), mk_sl_cui_uint64_c(0x0b1874aeul, 0x6a62a657ul), mk_sl_cui_uint64_c(0x4dae7baful, 0x70e13ed9ul),
		mk_sl_cui_uint64_c(0x9cfddeb0ul, 0x5bfb1058ul), mk_sl_cui_uint64_c(0xda4bd1b1ul, 0x417888d6ul), mk_sl_cui_uint64_c(0x108cc0b2ul, 0x6fe03d59ul), mk_sl_cui_uint64_c(0x563acfb3ul, 0x7563a5d7ul),
		mk_sl_cui_uint64_c(0x991fe2b4ul, 0x33cd4a5aul), mk_sl_cui_uint64_c(0xdfa9edb5ul, 0x294ed2d4ul), mk_sl_cui_uint64_c(0x156efcb6ul, 0x07d6675bul), mk_sl_cui_uint64_c(0x53d8f3b7ul, 0x1d55ffd5ul),
		mk_sl_cui_uint64_c(0x9624a6b8ul, 0x8b97a45cul), mk_sl_cui_uint64_c(0xd092a9b9ul, 0x91143cd2ul), mk_sl_cui_uint64_c(0x1a55b8baul, 0xbf8c895dul), mk_sl_cui_uint64_c(0x5ce3b7bbul, 0xa50f11d3ul),
		mk_sl_cui_uint64_c(0x93c69abcul, 0xe3a1fe5eul), mk_sl_cui_uint64_c(0xd57095bdul, 0xf92266d0ul), mk_sl_cui_uint64_c(0x1fb784beul, 0xd7bad35ful), mk_sl_cui_uint64_c(0x59018bbful, 0xcd394bd1ul),
		mk_sl_cui_uint64_c(0xf09734c0ul, 0x4fc94660ul), mk_sl_cui_uint64_c(0xb6213bc1ul, 0x554adeeeul), mk_sl_cui_uint64_c(0x7ce62ac2ul, 0x7bd26b61ul), mk_sl_cui_uint64_c(0x3a5025c3ul, 0x6151f3eful),
		mk_sl_cui_uint64_c(0xf57508c4ul, 0x27ff1c62ul), mk_sl_cui_uint64_c(0xb3c307c5ul, 0x3d7c84ecul), mk_sl_cui_uint64_c(0x790416c6ul, 0x13e43163ul), mk_sl_cui_uint64_c(0x3fb219c7ul, 0x0967a9edul),
		mk_sl_cui_uint64_c(0xfa4e4cc8ul, 0x9fa5f264ul), mk_sl_cui_uint64_c(0xbcf843c9ul, 0x85266aeaul), mk_sl_cui_uint64_c(0x763f52caul, 0xabbedf65ul), mk_sl_cui_uint64_c(0x30895dcbul, 0xb13d47ebul),
		mk_sl_cui_uint64_c(0xffac70ccul, 0xf793a866ul), mk_sl_cui_uint64_c(0xb91a7fcdul, 0xed1030e8ul), mk_sl_cui_uint64_c(0x73dd6eceul, 0xc3888567ul), mk_sl_cui_uint64_c(0x356b61cful, 0xd90b1de9ul),
		mk_sl_cui_uint64_c(0xe438c4d0ul, 0xf2113368ul), mk_sl_cui_uint64_c(0xa28ecbd1ul, 0xe892abe6ul), mk_sl_cui_uint64_c(0x6849dad2ul, 0xc60a1e69ul), mk_sl_cui_uint64_c(0x2effd5d3ul, 0xdc8986e7ul),
		mk_sl_cui_uint64_c(0xe1daf8d4ul, 0x9a27696aul), mk_sl_cui_uint64_c(0xa76cf7d5ul, 0x80a4f1e4ul), mk_sl_cui_uint64_c(0x6dabe6d6ul, 0xae3c446bul), mk_sl_cui_uint64_c(0x2b1de9d7ul, 0xb4bfdce5ul),
		mk_sl_cui_uint64_c(0xeee1bcd8ul, 0x227d876cul), mk_sl_cui_uint64_c(0xa857b3d9ul, 0x38fe1fe2ul), mk_sl_cui_uint64_c(0x6290a2daul, 0x1666aa6dul), mk_sl_cui_uint64_c(0x2426addbul, 0x0ce532e3ul),
		mk_sl_cui_uint64_c(0xeb0380dcul, 0x4a4bdd6eul), mk_sl_cui_uint64_c(0xadb58fddul, 0x50c845e0ul), mk_sl_cui_uint64_c(0x67729edeul, 0x7e50f06ful), mk_sl_cui_uint64_c(0x21c491dful, 0x64d368e1ul),
		mk_sl_cui_uint64_c(0xd8d4c9e0ul, 0x2864ac70ul), mk_sl_cui_uint64_c(0x9e62c6e1ul, 0x32e734feul), mk_sl_cui_uint64_c(0x54a5d7e2ul, 0x1c7f8171ul), mk_sl_cui_uint64_c(0x1213d8e3ul, 0x06fc19fful),
		mk_sl_cui_uint64_c(0xdd36f5e4ul, 0x4052f672ul), mk_sl_cui_uint64_c(0x9b80fae5ul, 0x5ad16efcul), mk_sl_cui_uint64_c(0x5147ebe6ul, 0x7449db73ul), mk_sl_cui_uint64_c(0x17f1e4e7ul, 0x6eca43fdul),
		mk_sl_cui_uint64_c(0xd20db1e8ul, 0xf8081874ul), mk_sl_cui_uint64_c(0x94bbbee9ul, 0xe28b80faul), mk_sl_cui_uint64_c(0x5e7cafeaul, 0xcc133575ul), mk_sl_cui_uint64_c(0x18caa0ebul, 0xd690adfbul),
		mk_sl_cui_uint64_c(0xd7ef8decul, 0x903e4276ul), mk_sl_cui_uint64_c(0x915982edul, 0x8abddaf8ul), mk_sl_cui_uint64_c(0x5b9e93eeul, 0xa4256f77ul), mk_sl_cui_uint64_c(0x1d289ceful, 0xbea6f7f9ul),
		mk_sl_cui_uint64_c(0xcc7b39f0ul, 0x95bcd978ul), mk_sl_cui_uint64_c(0x8acd36f1ul, 0x8f3f41f6ul), mk_sl_cui_uint64_c(0x400a27f2ul, 0xa1a7f479ul), mk_sl_cui_uint64_c(0x06bc28f3ul, 0xbb246cf7ul),
		mk_sl_cui_uint64_c(0xc99905f4ul, 0xfd8a837aul), mk_sl_cui_uint64_c(0x8f2f0af5ul, 0xe7091bf4ul), mk_sl_cui_uint64_c(0x45e81bf6ul, 0xc991ae7bul), mk_sl_cui_uint64_c(0x035e14f7ul, 0xd31236f5ul),
		mk_sl_cui_uint64_c(0xc6a241f8ul, 0x45d06d7cul), mk_sl_cui_uint64_c(0x80144ef9ul, 0x5f53f5f2ul), mk_sl_cui_uint64_c(0x4ad35ffaul, 0x71cb407dul), mk_sl_cui_uint64_c(0x0c6550fbul, 0x6b48d8f3ul),
		mk_sl_cui_uint64_c(0xc3407dfcul, 0x2de6377eul), mk_sl_cui_uint64_c(0x85f672fdul, 0x3765aff0ul), mk_sl_cui_uint64_c(0x4f3163feul, 0x19fd1a7ful), mk_sl_cui_uint64_c(0x09876cfful, 0x037e82f1ul),
	},
	{
		mk_sl_cui_uint64_c(0x00000000ul, 0x00000000ul), mk_sl_cui_uint64_c(0x83478b07ul, 0xb2468764ul), mk_sl_cui_uint64_c(0x1b8e0b0eul, 0x798c13c8ul), mk_sl_cui_uint64_c(0x98c98009ul, 0xcbca94acul),
		mk_sl_cui_uint64_c(0x3601161cul, 0xf205268dul), mk_sl_cui_uint64_c(0xb5469d1bul, 0x4043a1e9ul), mk_sl_cui_uint64_c(0x2d8f1d12ul, 0x8b893545ul), mk_sl_cui_uint64_c(0xaec89615ul, 0x39cfb221ul),
		mk_sl_cui_uint64_c(0x6c022c38ul, 0xf90a4c07ul), mk_sl_cui_uint64_c(0xef45a73ful, 0x4b4ccb63ul), mk_sl_cui_uint64_c(0x778c2736ul, 0x80865fcful), mk_sl_cui_uint64_c(0xf4cbac31ul, 0x32c0d8abul),
		mk_sl_cui_uint64_c(0x5a033a24ul, 0x0b0f6a8aul), mk_sl_cui_uint64_c(0xd944b123ul, 0xb949edeeul), mk_sl_cui_uint64_c(0x418d312aul, 0x72837942ul), mk_sl_cui_uint64_c(0xc2caba2dul, 0xc0c5fe26ul),
		mk_sl_cui_uint64_c(0xd8045870ul, 0xef14980eul), mk_sl_cui_uint64_c(0x5b43d377ul, 0x5d521f6aul), mk_sl_cui_uint64_c(0xc38a537eul, 0x96988bc6ul), mk_sl_cui_uint64_c(0x40cdd879ul, 0x24de0ca2ul),
		mk_sl_cui_uint64_c(0xee054e6cul, 0x1d11be83ul), mk_sl_cui_uint64_c(0x6d42c56bul, 0xaf5739e7ul), mk_sl_cui_uint64_c(0xf58b4562ul, 0x649dad4bul), mk_sl_cui_uint64_c(0x76ccce65ul, 0xd6db2a2ful),
		mk_sl_cui_uint64_c(0xb4067448ul, 0x161ed409ul), mk_sl_cui_uint64_c(0x3741ff4ful, 0xa458536dul), mk_sl_cui_uint64_c(0xaf887f46ul, 0x6f92c7c1ul), mk_sl_cui_uint64_c(0x2ccff441ul, 0xddd440a5ul),
		mk_sl_cui_uint64_c(0x82076254ul, 0xe41bf284ul), mk_sl_cui_uint64_c(0x0140e953ul, 0x565d75e0ul), mk_sl_cui_uint64_c(0x9989695aul, 0x9d97e14cul), mk_sl_cui_uint64_c(0x1acee25dul, 0x2fd16628ul),
		mk_sl_cui_uint64_c(0xad08b0e0ul, 0xc3282d1cul), mk_sl_cui_uint64_c(0x2e4f3be7ul, 0x716eaa78ul), mk_sl_cui_uint64_c(0xb686bbeeul, 0xbaa43ed4ul), mk_sl_cui_uint64_c(0x35c130e9ul, 0x08e2b9b0ul),
		mk_sl_cui_uint64_c(0x9b09a6fcul, 0x312d0b91ul), mk_sl_cui_uint64_c(0x184e2dfbul, 0x836b8cf5ul), mk_sl_cui_uint64_c(0x8087adf2ul, 0x48a11859ul), mk_sl_cui_uint64_c(0x03c026f5ul, 0xfae79f3dul),
		mk_sl_cui_uint64_c(0xc10a9cd8ul, 0x3a22611bul), mk_sl_cui_uint64_c(0x424d17dful, 0x8864e67ful), mk_sl_cui_uint64_c(0xda8497d6ul, 0x43ae72d3ul), mk_sl_cui_uint64_c(0x59c31cd1ul, 0xf1e8f5b7ul),
		mk_sl_cui_uint64_c(0xf70b8ac4ul, 0xc8274796ul), mk_sl_cui_uint64_c(0x744c01c3ul, 0x7a61c0f2ul), mk_sl_cui_uint64_c(0xec8581caul, 0xb1ab545eul), mk_sl_cui_uint64_c(0x6fc20acdul, 0x03edd33aul),
		mk_sl_cui_uint64_c(0x750ce890ul, 0x2c3cb512ul), mk_sl_cui_uint64_c(0xf64b6397ul, 0x9e7a3276ul), mk_sl_cui_uint64_c(0x6e82e39eul, 0x55b0a6daul), mk_sl_cui_uint64_c(0xedc56899ul, 0xe7f621beul),
		mk_sl_cui_uint64_c(0x430dfe8cul, 0xde39939ful), mk_sl_cui_uint64_c(0xc04a758bul, 0x6c7f14fbul), mk_sl_cui_uint64_c(0x5883f582ul, 0xa7b58057ul), mk_sl_cui_uint64_c(0xdbc47e85ul, 0x15f30733ul),
		mk_sl_cui_uint64_c(0x190ec4a8ul, 0xd536f915ul), mk_sl_cui_uint64_c(0x9a494faful, 0x67707e71ul), mk_sl_cui_uint64_c(0x0280cfa6ul, 0xacbaeaddul), mk_sl_cui_uint64_c(0x81c744a1ul, 0x1efc6db9ul),
		mk_sl_cui_uint64_c(0x2f0fd2b4ul, 0x2733df98ul), mk_sl_cui_uint64_c(0xac4859b3ul, 0x957558fcul), mk_sl_cui_uint64_c(0x3481d9baul, 0x5ebfcc50ul), mk_sl_cui_uint64_c(0xb7c652bdul, 0xecf94b34ul),
		mk_sl_cui_uint64_c(0x47107dddul, 0x9b505a38ul), mk_sl_cui_uint64_c(0xc457f6daul, 0x2916dd5cul), mk_sl_cui_uint64_c(0x5c9e76d3ul, 0xe2dc49f0ul), mk_sl_cui_uint64_c(0xdfd9fdd4ul, 0x509ace94ul),
		mk_sl_cui_uint64_c(0x71116bc1ul, 0x69557cb5ul), mk_sl_cui_uint64_c(0xf256e0c6ul, 0xdb13fbd1ul), mk_sl_cui_uint64_c(0x6a9f60cful, 0x10d96f7dul), mk_sl_cui_uint64_c(0xe9d8ebc8ul, 0xa29fe819ul),
		mk_sl_cui_uint64_c(0x2b1251e5ul, 0x625a163ful), mk_sl_cui_uint64_c(0xa855dae2ul, 0xd01c915bul), mk_sl_cui_uint64_c(0x309c5aebul, 0x1bd605f7ul), mk_sl_cui_uint64_c(0xb3dbd1ecul, 0xa9908293ul),
		mk_sl_cui_uint64_c(0x1d1347f9ul, 0x905f30b2ul), mk_sl_cui_uint64_c(0x9e54ccfeul, 0x2219b7d6ul), mk_sl_cui_uint64_c(0x069d4cf7ul, 0xe9d3237aul), mk_sl_cui_uint64_c(0x85dac7f0ul, 0x5b95a41eul),
		mk_sl_cui_uint64_c(0x9f1425adul, 0x7444c236ul), mk_sl_cui_uint64_c(0x1c53aeaaul, 0xc6024552ul), mk_sl_cui_uint64_c(0x849a2ea3ul, 0x0dc8d1feul), mk_sl_cui_uint64_c(0x07dda5a4ul, 0xbf8e569aul),
		mk_sl_cui_uint64_c(0xa91533b1ul, 0x8641e4bbul), mk_sl_cui_uint64_c(0x2a52b8b6ul, 0x340763dful), mk_sl_cui_uint64_c(0xb29b38bful, 0xffcdf773ul), mk_sl_cui_uint64_c(0x31dcb3b8ul, 0x4d8b7017ul),
		mk_sl_cui_uint64_c(0xf3160995ul, 0x8d4e8e31ul), mk_sl_cui_uint64_c(0x70518292ul, 0x3f080955ul), mk_sl_cui_uint64_c(0xe898029bul, 0xf4c29df9ul), mk_sl_cui_uint64_c(0x6bdf899cul, 0x46841a9dul),
		mk_sl_cui_uint64_c(0xc5171f89ul, 0x7f4ba8bcul), mk_sl_cui_uint64_c(0x4650948eul, 0xcd0d2fd8ul), mk_sl_cui_uint64_c(0xde991487ul, 0x06c7bb74ul), mk_sl_cui_uint64_c(0x5dde9f80ul, 0xb4813c10ul),
		mk_sl_cui_uint64_c(0xea18cd3dul, 0x58787724ul), mk_sl_cui_uint64_c(0x695f463aul, 0xea3ef040ul), mk_sl_cui_uint64_c(0xf196c633ul, 0x21f464ecul), mk_sl_cui_uint64_c(0x72d14d34ul, 0x93b2e388ul),
		mk_sl_cui_uint64_c(0xdc19db21ul, 0xaa7d51a9ul), mk_sl_cui_uint64_c(0x5f5e5026ul, 0x183bd6cdul), mk_sl_cui_uint64_c(0xc797d02ful, 0xd3f14261ul), mk_sl_cui_uint64_c(0x44d05b28ul, 0x61b7c505ul),
		mk_sl_cui_uint64_c(0x861ae105ul, 0xa1723b23ul), mk_sl_cui_uint64_c(0x055d6a02ul, 0x1334bc47ul), mk_sl_cui_uint64_c(0x9d94ea0bul, 0xd8fe28ebul), mk_sl_cui_uint64_c(0x1ed3610cul, 0x6ab8af8ful),
		mk_sl_cui_uint64_c(0xb01bf719ul, 0x53771daeul), mk_sl_cui_uint64_c(0x335c7c1eul, 0xe1319acaul), mk_sl_cui_uint64_c(0xab95fc17ul, 0x2afb0e66ul), mk_sl_cui_uint64_c(0x28d27710ul, 0x98bd8902ul),
		mk_sl_cui_uint64_c(0x321c954dul, 0xb76cef2aul), mk_sl_cui_uint64_c(0xb15b1e4aul, 0x052a684eul), mk_sl_cui_uint64_c(0x29929e43ul, 0xcee0fce2ul), mk_sl_cui_uint64_c(0xaad51544ul, 0x7ca67b86ul),
		mk_sl_cui_uint64_c(0x041d8351ul, 0x4569c9a7ul), mk_sl_cui_uint64_c(0x875a0856ul, 0xf72f4ec3ul), mk_sl_cui_uint64_c(0x1f93885ful, 0x3ce5da6ful), mk_sl_cui_uint64_c(0x9cd40358ul, 0x8ea35d0bul),
		mk_sl_cui_uint64_c(0x5e1eb975ul, 0x4e66a32dul), mk_sl_cui_uint64_c(0xdd593272ul, 0xfc202449ul), mk_sl_cui_uint64_c(0x4590b27bul, 0x37eab0e5ul), mk_sl_cui_uint64_c(0xc6d7397cul, 0x85ac3781ul),
		mk_sl_cui_uint64_c(0x681faf69ul, 0xbc6385a0ul), mk_sl_cui_uint64_c(0xeb58246eul, 0x0e2502c4ul), mk_sl_cui_uint64_c(0x7391a467ul, 0xc5ef9668ul), mk_sl_cui_uint64_c(0xf0d62f60ul, 0x77a9110cul),
		mk_sl_cui_uint64_c(0x8e20faa7ul, 0x2ba0b470ul), mk_sl_cui_uint64_c(0x0d6771a0ul, 0x99e63314ul), mk_sl_cui_uint64_c(0x95aef1a9ul, 0x522ca7b8ul), mk_sl_cui_uint64_c(0x16e97aaeul, 0xe06a20dcul),
		mk_sl_cui_uint64_c(0xb821ecbbul, 0xd9a592fdul), mk_sl_cui_uint64_c(0x3b6667bcul, 0x6be31599ul), mk_sl_cui_uint64_c(0xa3afe7b5ul, 0xa0298135ul), mk_sl_cui_uint64_c(0x20e86cb2ul, 0x126f0651ul),
		mk_sl_cui_uint64_c(0xe222d69ful, 0xd2aaf877ul), mk_sl_cui_uint64_c(0x61655d98ul, 0x60ec7f13ul), mk_sl_cui_uint64_c(0xf9acdd91ul, 0xab26ebbful), mk_sl_cui_uint64_c(0x7aeb5696ul, 0x19606cdbul),
		mk_sl_cui_uint64_c(0xd423c083ul, 0x20afdefaul), mk_sl_cui_uint64_c(0x57644b84ul, 0x92e9599eul), mk_sl_cui_uint64_c(0xcfadcb8dul, 0x5923cd32ul), mk_sl_cui_uint64_c(0x4cea408aul, 0xeb654a56ul),
		mk_sl_cui_uint64_c(0x5624a2d7ul, 0xc4b42c7eul), mk_sl_cui_uint64_c(0xd56329d0ul, 0x76f2ab1aul), mk_sl_cui_uint64_c(0x4daaa9d9ul, 0xbd383fb6ul), mk_sl_cui_uint64_c(0xceed22deul, 0x0f7eb8d2ul),
		mk_sl_cui_uint64_c(0x6025b4cbul, 0x36b10af3ul), mk_sl_cui_uint64_c(0xe3623fccul, 0x84f78d97ul), mk_sl_cui_uint64_c(0x7babbfc5ul, 0x4f3d193bul), mk_sl_cui_uint64_c(0xf8ec34c2ul, 0xfd7b9e5ful),
		mk_sl_cui_uint64_c(0x3a268eeful, 0x3dbe6079ul), mk_sl_cui_uint64_c(0xb96105e8ul, 0x8ff8e71dul), mk_sl_cui_uint64_c(0x21a885e1ul, 0x443273b1ul), mk_sl_cui_uint64_c(0xa2ef0ee6ul, 0xf674f4d5ul),
		mk_sl_cui_uint64_c(0x0c2798f3ul, 0xcfbb46f4ul), mk_sl_cui_uint64_c(0x8f6013f4ul, 0x7dfdc190ul), mk_sl_cui_uint64_c(0x17a993fdul, 0xb637553cul), mk_sl_cui_uint64_c(0x94ee18faul, 0x0471d258ul),
		mk_sl_cui_uint64_c(0x23284a47ul, 0xe888996cul), mk_sl_cui_uint64_c(0xa06fc140ul, 0x5ace1e08ul), mk_sl_cui_uint64_c(0x38a64149ul, 0x91048aa4ul), mk_sl_cui_uint64_c(0xbbe1ca4eul, 0x23420dc0ul),
		mk_sl_cui_uint64_c(0x15295c5bul, 0x1a8dbfe1ul), mk_sl_cui_uint64_c(0x966ed75cul, 0xa8cb3885ul), mk_sl_cui_uint64_c(0x0ea75755ul, 0x6301ac29ul), mk_sl_cui_uint64_c(0x8de0dc52ul, 0xd1472b4dul),
		mk_sl_cui_uint64_c(0x4f2a667ful, 0x1182d56bul), mk_sl_cui_uint64_c(0xcc6ded78ul, 0xa3c4520ful), mk_sl_cui_uint64_c(0x54a46d71ul, 0x680ec6a3ul), mk_sl_cui_uint64_c(0xd7e3e676ul, 0xda4841c7ul),
		mk_sl_cui_uint64_c(0x792b7063ul, 0xe387f3e6ul), mk_sl_cui_uint64_c(0xfa6cfb64ul, 0x51c17482ul), mk_sl_cui_uint64_c(0x62a57b6dul, 0x9a0be02eul), mk_sl_cui_uint64_c(0xe1e2f06aul, 0x284d674aul),
		mk_sl_cui_uint64_c(0xfb2c1237ul, 0x079c0162ul), mk_sl_cui_uint64_c(0x786b9930ul, 0xb5da8606ul), mk_sl_cui_uint64_c(0xe0a21939ul, 0x7e1012aaul), mk_sl_cui_uint64_c(0x63e5923eul, 0xcc5695ceul),
		mk_sl_cui_uint64_c(0xcd2d042bul, 0xf59927eful), mk_sl_cui_uint64_c(0x4e6a8f2cul, 0x47dfa08bul), mk_sl_cui_uint64_c(0xd6a30f25ul, 0x8c153427ul), mk_sl_cui_uint64_c(0x55e48422ul, 0x3e53b343ul),
		mk_sl_cui_uint64_c(0x972e3e0ful, 0xfe964d65ul), mk_sl_cui_uint64_c(0x1469b508ul, 0x4cd0ca01ul), mk_sl_cui_uint64_c(0x8ca03501ul, 0x871a5eadul), mk_sl_cui_uint64_c(0x0fe7be06ul, 0x355cd9c9ul),
		mk_sl_cui_uint64_c(0xa12f2813ul, 0x0c936be8ul), mk_sl_cui_uint64_c(0x2268a314ul, 0xbed5ec8cul), mk_sl_cui_uint64_c(0xbaa1231dul, 0x751f7820ul), mk_sl_cui_uint64_c(0x39e6a81aul, 0xc759ff44ul),
		mk_sl_cui_uint64_c(0xc930877aul, 0xb0f0ee48ul), mk_sl_cui_uint64_c(0x4a770c7dul, 0x02b6692cul), mk_sl_cui_uint64_c(0xd2be8c74ul, 0xc97cfd80ul), mk_sl_cui_uint64_c(0x51f90773ul, 0x7b3a7ae4ul),
		mk_sl_cui_uint64_c(0xff319166ul, 0x42f5c8c5ul), mk_sl_cui_uint64_c(0x7c761a61ul, 0xf0b34fa1ul), mk_sl_cui_uint64_c(0xe4bf9a68ul, 0x3b79db0dul), mk_sl_cui_uint64_c(0x67f8116ful, 0x893f5c69ul),
		mk_sl_cui_uint64_c(0xa532ab42ul, 0x49faa24ful), mk_sl_cui_uint64_c(0x26752045ul, 0xfbbc252bul), mk_sl_cui_uint64_c(0xbebca04cul, 0x3076b187ul), mk_sl_cui_uint64_c(0x3dfb2b4bul, 0x823036e3ul),
		mk_sl_cui_uint64_c(0x9333bd5eul, 0xbbff84c2ul), mk_sl_cui_uint64_c(0x10743659ul, 0x09b903a6ul), mk_sl_cui_uint64_c(0x88bdb650ul, 0xc273970aul), mk_sl_cui_uint64_c(0x0bfa3d57ul, 0x7035106eul),
		mk_sl_cui_uint64_c(0x1134df0aul, 0x5fe47646ul), mk_sl_cui_uint64_c(0x9273540dul, 0xeda2f122ul), mk_sl_cui_uint64_c(0x0abad404ul, 0x2668658eul), mk_sl_cui_uint64_c(0x89fd5f03ul, 0x942ee2eaul),
		mk_sl_cui_uint64_c(0x2735c916ul, 0xade150cbul), mk_sl_cui_uint64_c(0xa4724211ul, 0x1fa7d7aful), mk_sl_cui_uint64_c(0x3cbbc218ul, 0xd46d4303ul), mk_sl_cui_uint64_c(0xbffc491ful, 0x662bc467ul),
		mk_sl_cui_uint64_c(0x7d36f332ul, 0xa6ee3a41ul), mk_sl_cui_uint64_c(0xfe717835ul, 0x14a8bd25ul), mk_sl_cui_uint64_c(0x66b8f83cul, 0xdf622989ul), mk_sl_cui_uint64_c(0xe5ff733bul, 0x6d24aeedul),
		mk_sl_cui_uint64_c(0x4b37e52eul, 0x54eb1cccul), mk_sl_cui_uint64_c(0xc8706e29ul, 0xe6ad9ba8ul), mk_sl_cui_uint64_c(0x50b9ee20ul, 0x2d670f04ul), mk_sl_cui_uint64_c(0xd3fe6527ul, 0x9f218860ul),
		mk_sl_cui_uint64_c(0x6438379aul, 0x73d8c354ul), mk_sl_cui_uint64_c(0xe77fbc9dul, 0xc19e4430ul), mk_sl_cui_uint64_c(0x7fb63c94ul, 0x0a54d09cul), mk_sl_cui_uint64_c(0xfcf1b793ul, 0xb81257f8ul),
		mk_sl_cui_uint64_c(0x52392186ul, 0x81dde5d9ul), mk_sl_cui_uint64_c(0xd17eaa81ul, 0x339b62bdul), mk_sl_cui_uint64_c(0x49b72a88ul, 0xf851f611ul), mk_sl_cui_uint64_c(0xcaf0a18ful, 0x4a177175ul),
		mk_sl_cui_uint64_c(0x083a1ba2ul, 0x8ad28f53ul), mk_sl_cui_uint64_c(0x8b7d90a5ul, 0x38940837ul), mk_sl_cui_uint64_c(0x13b410acul, 0xf35e9c9bul), mk_sl_cui_uint64_c(0x90f39babul, 0x41181bfful),
		mk_sl_cui_uint64_c(0x3e3b0dbeul, 0x78d7a9deul), mk_sl_cui_uint64_c(0xbd7c86b9ul, 0xca912ebaul), mk_sl_cui_uint64_c(0x25b506b0ul, 0x015bba16ul), mk_sl_cui_uint64_c(0xa6f28db7ul, 0xb31d3d72ul),
		mk_sl_cui_uint64_c(0xbc3c6feaul, 0x9ccc5b5aul), mk_sl_cui_uint64_c(0x3f7be4edul, 0x2e8adc3eul), mk_sl_cui_uint64_c(0xa7b264e4ul, 0xe5404892ul), mk_sl_cui_uint64_c(0x24f5efe3ul, 0x5706cff6ul),
		mk_sl_cui_uint64_c(0x8a3d79f6ul, 0x6ec97dd7ul), mk_sl_cui_uint64_c(0x097af2f1ul, 0xdc8ffab3ul), mk_sl_cui_uint64_c(0x91b372f8ul, 0x17456e1ful), mk_sl_cui_uint64_c(0x12f4f9fful, 0xa503e97bul),
		mk_sl_cui_uint64_c(0xd03e43d2ul, 0x65c6175dul), mk_sl_cui_uint64_c(0x5379c8d5ul, 0xd7809039ul), mk_sl_cui_uint64_c(0xcbb048dcul, 0x1c4a0495ul), mk_sl_cui_uint64_c(0x48f7c3dbul, 0xae0c83f1ul),
		mk_sl_cui_uint64_c(0xe63f55ceul, 0x97c331d0ul), mk_sl_cui_uint64_c(0x6578dec9ul, 0x2585b6b4ul), mk_sl_cui_uint64_c(0xfdb15ec0ul, 0xee4f2218ul), mk_sl_cui_uint64_c(0x7ef6d5c7ul, 0x5c09a57cul),
	},
};

#else

#error xxxxxxxxxx

#endif

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

#if defined mk_lib_crypto_hash_block_streebog_base_fast && mk_lib_crypto_hash_block_streebog_base_fast == 0

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

#elif defined mk_lib_crypto_hash_block_streebog_base_fast && mk_lib_crypto_hash_block_streebog_base_fast == 1

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_hash_block_streebog_base_l(mk_lib_crypto_hash_block_streebog_base_block2_pct const a, mk_lib_crypto_hash_block_streebog_base_block2_pt const b) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != 8; ++i)
	{
		ta = a->m_uint64s[i];
		mk_sl_cui_uint64_to_bi_uchar(&ta, &tuc);
		b->m_uint64s[i] = s_mk_lib_crypto_hash_block_streebog_base_table_a[0][tuc];
		for(j = 1; j != 8; ++j)
		{
			mk_sl_cui_uint64_shr2(&ta, mk_lang_charbit);
			mk_sl_cui_uint64_to_bi_uchar(&ta, &tuc);
			mk_sl_cui_uint64_xor2(&b->m_uint64s[i], &s_mk_lib_crypto_hash_block_streebog_base_table_a[j][tuc]);
		}
	}
}

#else

#error xxxxxxxxxx

#endif

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
