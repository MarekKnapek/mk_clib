#include "mk_lib_crypto_alg_twofish_128.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"


#define mk_lib_crypto_alg_twofish_128_word_bytes (32 / mk_lang_charbit)
#define mk_lib_crypto_alg_twofish_128_key_words (mk_lib_crypto_alg_twofish_128_key_len_m / mk_lib_crypto_alg_twofish_128_word_bytes)
#define mk_lib_crypto_alg_twofish_128_msg_words (mk_lib_crypto_alg_twofish_128_msg_len_m / mk_lib_crypto_alg_twofish_128_word_bytes)
#define mk_lib_crypto_alg_twofish_128_sbox_words (mk_lib_crypto_alg_twofish_128_key_words / 2)


union mk_lib_crypto_alg_twofish_128_table_data_u
{
	mk_lang_alignas(64) mk_sl_cui_uint8_t m_uint8s[0xff + 1];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_twofish_128_table_data_u mk_lib_crypto_alg_twofish_128_table_data_t;

struct mk_lib_crypto_alg_twofish_128_table_s
{
	mk_lib_crypto_alg_twofish_128_table_data_t m_data;
};
typedef struct mk_lib_crypto_alg_twofish_128_table_s mk_lib_crypto_alg_twofish_128_table_t;


struct mk_lib_crypto_alg_twofish_128_tables_data_s
{
	mk_lib_crypto_alg_twofish_128_table_t m_tables[2];
};
typedef struct mk_lib_crypto_alg_twofish_128_tables_data_s mk_lib_crypto_alg_twofish_128_tables_data_t;

struct mk_lib_crypto_alg_twofish_128_tables_s
{
	mk_lib_crypto_alg_twofish_128_tables_data_t m_data;
};
typedef struct mk_lib_crypto_alg_twofish_128_tables_s mk_lib_crypto_alg_twofish_128_tables_t;


mk_lang_constexpr_static_inline mk_lib_crypto_alg_twofish_128_tables_t const s_mk_lib_crypto_alg_twofish_128_tables =
{{{
	{{{
		mk_sl_cui_uint8_c(0xa9ul), mk_sl_cui_uint8_c(0x67ul), mk_sl_cui_uint8_c(0xb3ul), mk_sl_cui_uint8_c(0xe8ul), mk_sl_cui_uint8_c(0x04ul), mk_sl_cui_uint8_c(0xfdul), mk_sl_cui_uint8_c(0xa3ul), mk_sl_cui_uint8_c(0x76ul),
		mk_sl_cui_uint8_c(0x9aul), mk_sl_cui_uint8_c(0x92ul), mk_sl_cui_uint8_c(0x80ul), mk_sl_cui_uint8_c(0x78ul), mk_sl_cui_uint8_c(0xe4ul), mk_sl_cui_uint8_c(0xddul), mk_sl_cui_uint8_c(0xd1ul), mk_sl_cui_uint8_c(0x38ul),
		mk_sl_cui_uint8_c(0x0dul), mk_sl_cui_uint8_c(0xc6ul), mk_sl_cui_uint8_c(0x35ul), mk_sl_cui_uint8_c(0x98ul), mk_sl_cui_uint8_c(0x18ul), mk_sl_cui_uint8_c(0xf7ul), mk_sl_cui_uint8_c(0xecul), mk_sl_cui_uint8_c(0x6cul),
		mk_sl_cui_uint8_c(0x43ul), mk_sl_cui_uint8_c(0x75ul), mk_sl_cui_uint8_c(0x37ul), mk_sl_cui_uint8_c(0x26ul), mk_sl_cui_uint8_c(0xfaul), mk_sl_cui_uint8_c(0x13ul), mk_sl_cui_uint8_c(0x94ul), mk_sl_cui_uint8_c(0x48ul),
		mk_sl_cui_uint8_c(0xf2ul), mk_sl_cui_uint8_c(0xd0ul), mk_sl_cui_uint8_c(0x8bul), mk_sl_cui_uint8_c(0x30ul), mk_sl_cui_uint8_c(0x84ul), mk_sl_cui_uint8_c(0x54ul), mk_sl_cui_uint8_c(0xdful), mk_sl_cui_uint8_c(0x23ul),
		mk_sl_cui_uint8_c(0x19ul), mk_sl_cui_uint8_c(0x5bul), mk_sl_cui_uint8_c(0x3dul), mk_sl_cui_uint8_c(0x59ul), mk_sl_cui_uint8_c(0xf3ul), mk_sl_cui_uint8_c(0xaeul), mk_sl_cui_uint8_c(0xa2ul), mk_sl_cui_uint8_c(0x82ul),
		mk_sl_cui_uint8_c(0x63ul), mk_sl_cui_uint8_c(0x01ul), mk_sl_cui_uint8_c(0x83ul), mk_sl_cui_uint8_c(0x2eul), mk_sl_cui_uint8_c(0xd9ul), mk_sl_cui_uint8_c(0x51ul), mk_sl_cui_uint8_c(0x9bul), mk_sl_cui_uint8_c(0x7cul),
		mk_sl_cui_uint8_c(0xa6ul), mk_sl_cui_uint8_c(0xebul), mk_sl_cui_uint8_c(0xa5ul), mk_sl_cui_uint8_c(0xbeul), mk_sl_cui_uint8_c(0x16ul), mk_sl_cui_uint8_c(0x0cul), mk_sl_cui_uint8_c(0xe3ul), mk_sl_cui_uint8_c(0x61ul),
		mk_sl_cui_uint8_c(0xc0ul), mk_sl_cui_uint8_c(0x8cul), mk_sl_cui_uint8_c(0x3aul), mk_sl_cui_uint8_c(0xf5ul), mk_sl_cui_uint8_c(0x73ul), mk_sl_cui_uint8_c(0x2cul), mk_sl_cui_uint8_c(0x25ul), mk_sl_cui_uint8_c(0x0bul),
		mk_sl_cui_uint8_c(0xbbul), mk_sl_cui_uint8_c(0x4eul), mk_sl_cui_uint8_c(0x89ul), mk_sl_cui_uint8_c(0x6bul), mk_sl_cui_uint8_c(0x53ul), mk_sl_cui_uint8_c(0x6aul), mk_sl_cui_uint8_c(0xb4ul), mk_sl_cui_uint8_c(0xf1ul),
		mk_sl_cui_uint8_c(0xe1ul), mk_sl_cui_uint8_c(0xe6ul), mk_sl_cui_uint8_c(0xbdul), mk_sl_cui_uint8_c(0x45ul), mk_sl_cui_uint8_c(0xe2ul), mk_sl_cui_uint8_c(0xf4ul), mk_sl_cui_uint8_c(0xb6ul), mk_sl_cui_uint8_c(0x66ul),
		mk_sl_cui_uint8_c(0xccul), mk_sl_cui_uint8_c(0x95ul), mk_sl_cui_uint8_c(0x03ul), mk_sl_cui_uint8_c(0x56ul), mk_sl_cui_uint8_c(0xd4ul), mk_sl_cui_uint8_c(0x1cul), mk_sl_cui_uint8_c(0x1eul), mk_sl_cui_uint8_c(0xd7ul),
		mk_sl_cui_uint8_c(0xfbul), mk_sl_cui_uint8_c(0xc3ul), mk_sl_cui_uint8_c(0x8eul), mk_sl_cui_uint8_c(0xb5ul), mk_sl_cui_uint8_c(0xe9ul), mk_sl_cui_uint8_c(0xcful), mk_sl_cui_uint8_c(0xbful), mk_sl_cui_uint8_c(0xbaul),
		mk_sl_cui_uint8_c(0xeaul), mk_sl_cui_uint8_c(0x77ul), mk_sl_cui_uint8_c(0x39ul), mk_sl_cui_uint8_c(0xaful), mk_sl_cui_uint8_c(0x33ul), mk_sl_cui_uint8_c(0xc9ul), mk_sl_cui_uint8_c(0x62ul), mk_sl_cui_uint8_c(0x71ul),
		mk_sl_cui_uint8_c(0x81ul), mk_sl_cui_uint8_c(0x79ul), mk_sl_cui_uint8_c(0x09ul), mk_sl_cui_uint8_c(0xadul), mk_sl_cui_uint8_c(0x24ul), mk_sl_cui_uint8_c(0xcdul), mk_sl_cui_uint8_c(0xf9ul), mk_sl_cui_uint8_c(0xd8ul),
		mk_sl_cui_uint8_c(0xe5ul), mk_sl_cui_uint8_c(0xc5ul), mk_sl_cui_uint8_c(0xb9ul), mk_sl_cui_uint8_c(0x4dul), mk_sl_cui_uint8_c(0x44ul), mk_sl_cui_uint8_c(0x08ul), mk_sl_cui_uint8_c(0x86ul), mk_sl_cui_uint8_c(0xe7ul),
		mk_sl_cui_uint8_c(0xa1ul), mk_sl_cui_uint8_c(0x1dul), mk_sl_cui_uint8_c(0xaaul), mk_sl_cui_uint8_c(0xedul), mk_sl_cui_uint8_c(0x06ul), mk_sl_cui_uint8_c(0x70ul), mk_sl_cui_uint8_c(0xb2ul), mk_sl_cui_uint8_c(0xd2ul),
		mk_sl_cui_uint8_c(0x41ul), mk_sl_cui_uint8_c(0x7bul), mk_sl_cui_uint8_c(0xa0ul), mk_sl_cui_uint8_c(0x11ul), mk_sl_cui_uint8_c(0x31ul), mk_sl_cui_uint8_c(0xc2ul), mk_sl_cui_uint8_c(0x27ul), mk_sl_cui_uint8_c(0x90ul),
		mk_sl_cui_uint8_c(0x20ul), mk_sl_cui_uint8_c(0xf6ul), mk_sl_cui_uint8_c(0x60ul), mk_sl_cui_uint8_c(0xfful), mk_sl_cui_uint8_c(0x96ul), mk_sl_cui_uint8_c(0x5cul), mk_sl_cui_uint8_c(0xb1ul), mk_sl_cui_uint8_c(0xabul),
		mk_sl_cui_uint8_c(0x9eul), mk_sl_cui_uint8_c(0x9cul), mk_sl_cui_uint8_c(0x52ul), mk_sl_cui_uint8_c(0x1bul), mk_sl_cui_uint8_c(0x5ful), mk_sl_cui_uint8_c(0x93ul), mk_sl_cui_uint8_c(0x0aul), mk_sl_cui_uint8_c(0xeful),
		mk_sl_cui_uint8_c(0x91ul), mk_sl_cui_uint8_c(0x85ul), mk_sl_cui_uint8_c(0x49ul), mk_sl_cui_uint8_c(0xeeul), mk_sl_cui_uint8_c(0x2dul), mk_sl_cui_uint8_c(0x4ful), mk_sl_cui_uint8_c(0x8ful), mk_sl_cui_uint8_c(0x3bul),
		mk_sl_cui_uint8_c(0x47ul), mk_sl_cui_uint8_c(0x87ul), mk_sl_cui_uint8_c(0x6dul), mk_sl_cui_uint8_c(0x46ul), mk_sl_cui_uint8_c(0xd6ul), mk_sl_cui_uint8_c(0x3eul), mk_sl_cui_uint8_c(0x69ul), mk_sl_cui_uint8_c(0x64ul),
		mk_sl_cui_uint8_c(0x2aul), mk_sl_cui_uint8_c(0xceul), mk_sl_cui_uint8_c(0xcbul), mk_sl_cui_uint8_c(0x2ful), mk_sl_cui_uint8_c(0xfcul), mk_sl_cui_uint8_c(0x97ul), mk_sl_cui_uint8_c(0x05ul), mk_sl_cui_uint8_c(0x7aul),
		mk_sl_cui_uint8_c(0xacul), mk_sl_cui_uint8_c(0x7ful), mk_sl_cui_uint8_c(0xd5ul), mk_sl_cui_uint8_c(0x1aul), mk_sl_cui_uint8_c(0x4bul), mk_sl_cui_uint8_c(0x0eul), mk_sl_cui_uint8_c(0xa7ul), mk_sl_cui_uint8_c(0x5aul),
		mk_sl_cui_uint8_c(0x28ul), mk_sl_cui_uint8_c(0x14ul), mk_sl_cui_uint8_c(0x3ful), mk_sl_cui_uint8_c(0x29ul), mk_sl_cui_uint8_c(0x88ul), mk_sl_cui_uint8_c(0x3cul), mk_sl_cui_uint8_c(0x4cul), mk_sl_cui_uint8_c(0x02ul),
		mk_sl_cui_uint8_c(0xb8ul), mk_sl_cui_uint8_c(0xdaul), mk_sl_cui_uint8_c(0xb0ul), mk_sl_cui_uint8_c(0x17ul), mk_sl_cui_uint8_c(0x55ul), mk_sl_cui_uint8_c(0x1ful), mk_sl_cui_uint8_c(0x8aul), mk_sl_cui_uint8_c(0x7dul),
		mk_sl_cui_uint8_c(0x57ul), mk_sl_cui_uint8_c(0xc7ul), mk_sl_cui_uint8_c(0x8dul), mk_sl_cui_uint8_c(0x74ul), mk_sl_cui_uint8_c(0xb7ul), mk_sl_cui_uint8_c(0xc4ul), mk_sl_cui_uint8_c(0x9ful), mk_sl_cui_uint8_c(0x72ul),
		mk_sl_cui_uint8_c(0x7eul), mk_sl_cui_uint8_c(0x15ul), mk_sl_cui_uint8_c(0x22ul), mk_sl_cui_uint8_c(0x12ul), mk_sl_cui_uint8_c(0x58ul), mk_sl_cui_uint8_c(0x07ul), mk_sl_cui_uint8_c(0x99ul), mk_sl_cui_uint8_c(0x34ul),
		mk_sl_cui_uint8_c(0x6eul), mk_sl_cui_uint8_c(0x50ul), mk_sl_cui_uint8_c(0xdeul), mk_sl_cui_uint8_c(0x68ul), mk_sl_cui_uint8_c(0x65ul), mk_sl_cui_uint8_c(0xbcul), mk_sl_cui_uint8_c(0xdbul), mk_sl_cui_uint8_c(0xf8ul),
		mk_sl_cui_uint8_c(0xc8ul), mk_sl_cui_uint8_c(0xa8ul), mk_sl_cui_uint8_c(0x2bul), mk_sl_cui_uint8_c(0x40ul), mk_sl_cui_uint8_c(0xdcul), mk_sl_cui_uint8_c(0xfeul), mk_sl_cui_uint8_c(0x32ul), mk_sl_cui_uint8_c(0xa4ul),
		mk_sl_cui_uint8_c(0xcaul), mk_sl_cui_uint8_c(0x10ul), mk_sl_cui_uint8_c(0x21ul), mk_sl_cui_uint8_c(0xf0ul), mk_sl_cui_uint8_c(0xd3ul), mk_sl_cui_uint8_c(0x5dul), mk_sl_cui_uint8_c(0x0ful), mk_sl_cui_uint8_c(0x00ul),
		mk_sl_cui_uint8_c(0x6ful), mk_sl_cui_uint8_c(0x9dul), mk_sl_cui_uint8_c(0x36ul), mk_sl_cui_uint8_c(0x42ul), mk_sl_cui_uint8_c(0x4aul), mk_sl_cui_uint8_c(0x5eul), mk_sl_cui_uint8_c(0xc1ul), mk_sl_cui_uint8_c(0xe0ul),
	}}},
	{{{
		mk_sl_cui_uint8_c(0x75ul), mk_sl_cui_uint8_c(0xf3ul), mk_sl_cui_uint8_c(0xc6ul), mk_sl_cui_uint8_c(0xf4ul), mk_sl_cui_uint8_c(0xdbul), mk_sl_cui_uint8_c(0x7bul), mk_sl_cui_uint8_c(0xfbul), mk_sl_cui_uint8_c(0xc8ul),
		mk_sl_cui_uint8_c(0x4aul), mk_sl_cui_uint8_c(0xd3ul), mk_sl_cui_uint8_c(0xe6ul), mk_sl_cui_uint8_c(0x6bul), mk_sl_cui_uint8_c(0x45ul), mk_sl_cui_uint8_c(0x7dul), mk_sl_cui_uint8_c(0xe8ul), mk_sl_cui_uint8_c(0x4bul),
		mk_sl_cui_uint8_c(0xd6ul), mk_sl_cui_uint8_c(0x32ul), mk_sl_cui_uint8_c(0xd8ul), mk_sl_cui_uint8_c(0xfdul), mk_sl_cui_uint8_c(0x37ul), mk_sl_cui_uint8_c(0x71ul), mk_sl_cui_uint8_c(0xf1ul), mk_sl_cui_uint8_c(0xe1ul),
		mk_sl_cui_uint8_c(0x30ul), mk_sl_cui_uint8_c(0x0ful), mk_sl_cui_uint8_c(0xf8ul), mk_sl_cui_uint8_c(0x1bul), mk_sl_cui_uint8_c(0x87ul), mk_sl_cui_uint8_c(0xfaul), mk_sl_cui_uint8_c(0x06ul), mk_sl_cui_uint8_c(0x3ful),
		mk_sl_cui_uint8_c(0x5eul), mk_sl_cui_uint8_c(0xbaul), mk_sl_cui_uint8_c(0xaeul), mk_sl_cui_uint8_c(0x5bul), mk_sl_cui_uint8_c(0x8aul), mk_sl_cui_uint8_c(0x00ul), mk_sl_cui_uint8_c(0xbcul), mk_sl_cui_uint8_c(0x9dul),
		mk_sl_cui_uint8_c(0x6dul), mk_sl_cui_uint8_c(0xc1ul), mk_sl_cui_uint8_c(0xb1ul), mk_sl_cui_uint8_c(0x0eul), mk_sl_cui_uint8_c(0x80ul), mk_sl_cui_uint8_c(0x5dul), mk_sl_cui_uint8_c(0xd2ul), mk_sl_cui_uint8_c(0xd5ul),
		mk_sl_cui_uint8_c(0xa0ul), mk_sl_cui_uint8_c(0x84ul), mk_sl_cui_uint8_c(0x07ul), mk_sl_cui_uint8_c(0x14ul), mk_sl_cui_uint8_c(0xb5ul), mk_sl_cui_uint8_c(0x90ul), mk_sl_cui_uint8_c(0x2cul), mk_sl_cui_uint8_c(0xa3ul),
		mk_sl_cui_uint8_c(0xb2ul), mk_sl_cui_uint8_c(0x73ul), mk_sl_cui_uint8_c(0x4cul), mk_sl_cui_uint8_c(0x54ul), mk_sl_cui_uint8_c(0x92ul), mk_sl_cui_uint8_c(0x74ul), mk_sl_cui_uint8_c(0x36ul), mk_sl_cui_uint8_c(0x51ul),
		mk_sl_cui_uint8_c(0x38ul), mk_sl_cui_uint8_c(0xb0ul), mk_sl_cui_uint8_c(0xbdul), mk_sl_cui_uint8_c(0x5aul), mk_sl_cui_uint8_c(0xfcul), mk_sl_cui_uint8_c(0x60ul), mk_sl_cui_uint8_c(0x62ul), mk_sl_cui_uint8_c(0x96ul),
		mk_sl_cui_uint8_c(0x6cul), mk_sl_cui_uint8_c(0x42ul), mk_sl_cui_uint8_c(0xf7ul), mk_sl_cui_uint8_c(0x10ul), mk_sl_cui_uint8_c(0x7cul), mk_sl_cui_uint8_c(0x28ul), mk_sl_cui_uint8_c(0x27ul), mk_sl_cui_uint8_c(0x8cul),
		mk_sl_cui_uint8_c(0x13ul), mk_sl_cui_uint8_c(0x95ul), mk_sl_cui_uint8_c(0x9cul), mk_sl_cui_uint8_c(0xc7ul), mk_sl_cui_uint8_c(0x24ul), mk_sl_cui_uint8_c(0x46ul), mk_sl_cui_uint8_c(0x3bul), mk_sl_cui_uint8_c(0x70ul),
		mk_sl_cui_uint8_c(0xcaul), mk_sl_cui_uint8_c(0xe3ul), mk_sl_cui_uint8_c(0x85ul), mk_sl_cui_uint8_c(0xcbul), mk_sl_cui_uint8_c(0x11ul), mk_sl_cui_uint8_c(0xd0ul), mk_sl_cui_uint8_c(0x93ul), mk_sl_cui_uint8_c(0xb8ul),
		mk_sl_cui_uint8_c(0xa6ul), mk_sl_cui_uint8_c(0x83ul), mk_sl_cui_uint8_c(0x20ul), mk_sl_cui_uint8_c(0xfful), mk_sl_cui_uint8_c(0x9ful), mk_sl_cui_uint8_c(0x77ul), mk_sl_cui_uint8_c(0xc3ul), mk_sl_cui_uint8_c(0xccul),
		mk_sl_cui_uint8_c(0x03ul), mk_sl_cui_uint8_c(0x6ful), mk_sl_cui_uint8_c(0x08ul), mk_sl_cui_uint8_c(0xbful), mk_sl_cui_uint8_c(0x40ul), mk_sl_cui_uint8_c(0xe7ul), mk_sl_cui_uint8_c(0x2bul), mk_sl_cui_uint8_c(0xe2ul),
		mk_sl_cui_uint8_c(0x79ul), mk_sl_cui_uint8_c(0x0cul), mk_sl_cui_uint8_c(0xaaul), mk_sl_cui_uint8_c(0x82ul), mk_sl_cui_uint8_c(0x41ul), mk_sl_cui_uint8_c(0x3aul), mk_sl_cui_uint8_c(0xeaul), mk_sl_cui_uint8_c(0xb9ul),
		mk_sl_cui_uint8_c(0xe4ul), mk_sl_cui_uint8_c(0x9aul), mk_sl_cui_uint8_c(0xa4ul), mk_sl_cui_uint8_c(0x97ul), mk_sl_cui_uint8_c(0x7eul), mk_sl_cui_uint8_c(0xdaul), mk_sl_cui_uint8_c(0x7aul), mk_sl_cui_uint8_c(0x17ul),
		mk_sl_cui_uint8_c(0x66ul), mk_sl_cui_uint8_c(0x94ul), mk_sl_cui_uint8_c(0xa1ul), mk_sl_cui_uint8_c(0x1dul), mk_sl_cui_uint8_c(0x3dul), mk_sl_cui_uint8_c(0xf0ul), mk_sl_cui_uint8_c(0xdeul), mk_sl_cui_uint8_c(0xb3ul),
		mk_sl_cui_uint8_c(0x0bul), mk_sl_cui_uint8_c(0x72ul), mk_sl_cui_uint8_c(0xa7ul), mk_sl_cui_uint8_c(0x1cul), mk_sl_cui_uint8_c(0xeful), mk_sl_cui_uint8_c(0xd1ul), mk_sl_cui_uint8_c(0x53ul), mk_sl_cui_uint8_c(0x3eul),
		mk_sl_cui_uint8_c(0x8ful), mk_sl_cui_uint8_c(0x33ul), mk_sl_cui_uint8_c(0x26ul), mk_sl_cui_uint8_c(0x5ful), mk_sl_cui_uint8_c(0xecul), mk_sl_cui_uint8_c(0x76ul), mk_sl_cui_uint8_c(0x2aul), mk_sl_cui_uint8_c(0x49ul),
		mk_sl_cui_uint8_c(0x81ul), mk_sl_cui_uint8_c(0x88ul), mk_sl_cui_uint8_c(0xeeul), mk_sl_cui_uint8_c(0x21ul), mk_sl_cui_uint8_c(0xc4ul), mk_sl_cui_uint8_c(0x1aul), mk_sl_cui_uint8_c(0xebul), mk_sl_cui_uint8_c(0xd9ul),
		mk_sl_cui_uint8_c(0xc5ul), mk_sl_cui_uint8_c(0x39ul), mk_sl_cui_uint8_c(0x99ul), mk_sl_cui_uint8_c(0xcdul), mk_sl_cui_uint8_c(0xadul), mk_sl_cui_uint8_c(0x31ul), mk_sl_cui_uint8_c(0x8bul), mk_sl_cui_uint8_c(0x01ul),
		mk_sl_cui_uint8_c(0x18ul), mk_sl_cui_uint8_c(0x23ul), mk_sl_cui_uint8_c(0xddul), mk_sl_cui_uint8_c(0x1ful), mk_sl_cui_uint8_c(0x4eul), mk_sl_cui_uint8_c(0x2dul), mk_sl_cui_uint8_c(0xf9ul), mk_sl_cui_uint8_c(0x48ul),
		mk_sl_cui_uint8_c(0x4ful), mk_sl_cui_uint8_c(0xf2ul), mk_sl_cui_uint8_c(0x65ul), mk_sl_cui_uint8_c(0x8eul), mk_sl_cui_uint8_c(0x78ul), mk_sl_cui_uint8_c(0x5cul), mk_sl_cui_uint8_c(0x58ul), mk_sl_cui_uint8_c(0x19ul),
		mk_sl_cui_uint8_c(0x8dul), mk_sl_cui_uint8_c(0xe5ul), mk_sl_cui_uint8_c(0x98ul), mk_sl_cui_uint8_c(0x57ul), mk_sl_cui_uint8_c(0x67ul), mk_sl_cui_uint8_c(0x7ful), mk_sl_cui_uint8_c(0x05ul), mk_sl_cui_uint8_c(0x64ul),
		mk_sl_cui_uint8_c(0xaful), mk_sl_cui_uint8_c(0x63ul), mk_sl_cui_uint8_c(0xb6ul), mk_sl_cui_uint8_c(0xfeul), mk_sl_cui_uint8_c(0xf5ul), mk_sl_cui_uint8_c(0xb7ul), mk_sl_cui_uint8_c(0x3cul), mk_sl_cui_uint8_c(0xa5ul),
		mk_sl_cui_uint8_c(0xceul), mk_sl_cui_uint8_c(0xe9ul), mk_sl_cui_uint8_c(0x68ul), mk_sl_cui_uint8_c(0x44ul), mk_sl_cui_uint8_c(0xe0ul), mk_sl_cui_uint8_c(0x4dul), mk_sl_cui_uint8_c(0x43ul), mk_sl_cui_uint8_c(0x69ul),
		mk_sl_cui_uint8_c(0x29ul), mk_sl_cui_uint8_c(0x2eul), mk_sl_cui_uint8_c(0xacul), mk_sl_cui_uint8_c(0x15ul), mk_sl_cui_uint8_c(0x59ul), mk_sl_cui_uint8_c(0xa8ul), mk_sl_cui_uint8_c(0x0aul), mk_sl_cui_uint8_c(0x9eul),
		mk_sl_cui_uint8_c(0x6eul), mk_sl_cui_uint8_c(0x47ul), mk_sl_cui_uint8_c(0xdful), mk_sl_cui_uint8_c(0x34ul), mk_sl_cui_uint8_c(0x35ul), mk_sl_cui_uint8_c(0x6aul), mk_sl_cui_uint8_c(0xcful), mk_sl_cui_uint8_c(0xdcul),
		mk_sl_cui_uint8_c(0x22ul), mk_sl_cui_uint8_c(0xc9ul), mk_sl_cui_uint8_c(0xc0ul), mk_sl_cui_uint8_c(0x9bul), mk_sl_cui_uint8_c(0x89ul), mk_sl_cui_uint8_c(0xd4ul), mk_sl_cui_uint8_c(0xedul), mk_sl_cui_uint8_c(0xabul),
		mk_sl_cui_uint8_c(0x12ul), mk_sl_cui_uint8_c(0xa2ul), mk_sl_cui_uint8_c(0x0dul), mk_sl_cui_uint8_c(0x52ul), mk_sl_cui_uint8_c(0xbbul), mk_sl_cui_uint8_c(0x02ul), mk_sl_cui_uint8_c(0x2ful), mk_sl_cui_uint8_c(0xa9ul),
		mk_sl_cui_uint8_c(0xd7ul), mk_sl_cui_uint8_c(0x61ul), mk_sl_cui_uint8_c(0x1eul), mk_sl_cui_uint8_c(0xb4ul), mk_sl_cui_uint8_c(0x50ul), mk_sl_cui_uint8_c(0x04ul), mk_sl_cui_uint8_c(0xf6ul), mk_sl_cui_uint8_c(0xc2ul),
		mk_sl_cui_uint8_c(0x16ul), mk_sl_cui_uint8_c(0x25ul), mk_sl_cui_uint8_c(0x86ul), mk_sl_cui_uint8_c(0x56ul), mk_sl_cui_uint8_c(0x55ul), mk_sl_cui_uint8_c(0x09ul), mk_sl_cui_uint8_c(0xbeul), mk_sl_cui_uint8_c(0x91ul),
	}}},
}}};


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_lfsr_1(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint8_shr3(a, 1, &ta);
	tuc = mk_sl_cui_uint8_has_lsb(a) ? ((mk_lang_types_uchar_t)(0xb4)) : ((mk_lang_types_uchar_t)(0x00));
	mk_sl_cui_uint8_from_bi_uchar(&tb, &tuc);
	mk_sl_cui_uint8_xor3(&ta, &tb, b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_lfsr_2(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint8_shr3(a, 2, &ta);
	mk_sl_cui_uint8_shr3(a, 1, &tb);
	tuc = mk_sl_cui_uint8_has_lsb(&tb) ? ((mk_lang_types_uchar_t)(0xb4)) : ((mk_lang_types_uchar_t)(0x00));
	mk_sl_cui_uint8_from_bi_uchar(&tb, &tuc);
	mk_sl_cui_uint8_xor2(&ta, &tb);
	tuc = mk_sl_cui_uint8_has_lsb(a) ? ((mk_lang_types_uchar_t)(0x5a)) : ((mk_lang_types_uchar_t)(0x00));
	mk_sl_cui_uint8_from_bi_uchar(&tb, &tuc);
	mk_sl_cui_uint8_xor3(&ta, &tb, b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_1(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = *a;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_x(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_alg_twofish_128_lfsr_2(a, &ta);
	mk_sl_cui_uint8_xor3(a, &ta, b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_y(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_alg_twofish_128_lfsr_1(a, &ta);
	mk_lib_crypto_alg_twofish_128_lfsr_2(a, &tb);
	mk_sl_cui_uint8_xor2(&ta, &tb);
	mk_sl_cui_uint8_xor3(a, &ta, b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_00(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_1(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_01(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_y(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_02(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_x(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_03(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_x(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_10(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_x(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_11(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_y(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_12(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_y(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_13(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_1(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_20(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_y(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_21(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_x(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_22(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_1(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_23(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_y(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_30(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_y(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_31(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_1(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_32(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_y(a, b); }
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_33(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pt const b) mk_lang_noexcept { mk_lib_crypto_alg_twofish_128_mul_x(a, b); }

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mul_xy(mk_lang_types_sint_t const a, mk_lang_types_sint_t const b, mk_sl_cui_uint8_pct const c, mk_sl_cui_uint8_pt const d) mk_lang_noexcept
{
	mk_lang_types_sint_t ta mk_lang_constexpr_init;

	mk_lang_assert(a >= 0 && a < 4);
	mk_lang_assert(b >= 0 && b < 4);

	ta = a * 10 + b;
	switch(ta)
	{
		case 00: mk_lib_crypto_alg_twofish_128_mul_00(c, d); break;
		case 01: mk_lib_crypto_alg_twofish_128_mul_01(c, d); break;
		case 02: mk_lib_crypto_alg_twofish_128_mul_02(c, d); break;
		case 03: mk_lib_crypto_alg_twofish_128_mul_03(c, d); break;
		case 10: mk_lib_crypto_alg_twofish_128_mul_10(c, d); break;
		case 11: mk_lib_crypto_alg_twofish_128_mul_11(c, d); break;
		case 12: mk_lib_crypto_alg_twofish_128_mul_12(c, d); break;
		case 13: mk_lib_crypto_alg_twofish_128_mul_13(c, d); break;
		case 20: mk_lib_crypto_alg_twofish_128_mul_20(c, d); break;
		case 21: mk_lib_crypto_alg_twofish_128_mul_21(c, d); break;
		case 22: mk_lib_crypto_alg_twofish_128_mul_22(c, d); break;
		case 23: mk_lib_crypto_alg_twofish_128_mul_23(c, d); break;
		case 30: mk_lib_crypto_alg_twofish_128_mul_30(c, d); break;
		case 31: mk_lib_crypto_alg_twofish_128_mul_31(c, d); break;
		case 32: mk_lib_crypto_alg_twofish_128_mul_32(c, d); break;
		case 33: mk_lib_crypto_alg_twofish_128_mul_33(c, d); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_00(mk_lang_types_void_t) mk_lang_noexcept { return 1; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_01(mk_lang_types_void_t) mk_lang_noexcept { return 0; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_02(mk_lang_types_void_t) mk_lang_noexcept { return 0; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_03(mk_lang_types_void_t) mk_lang_noexcept { return 1; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_04(mk_lang_types_void_t) mk_lang_noexcept { return 1; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_10(mk_lang_types_void_t) mk_lang_noexcept { return 0; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_11(mk_lang_types_void_t) mk_lang_noexcept { return 0; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_12(mk_lang_types_void_t) mk_lang_noexcept { return 1; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_13(mk_lang_types_void_t) mk_lang_noexcept { return 1; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_14(mk_lang_types_void_t) mk_lang_noexcept { return 0; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_20(mk_lang_types_void_t) mk_lang_noexcept { return 1; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_21(mk_lang_types_void_t) mk_lang_noexcept { return 1; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_22(mk_lang_types_void_t) mk_lang_noexcept { return 0; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_23(mk_lang_types_void_t) mk_lang_noexcept { return 0; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_24(mk_lang_types_void_t) mk_lang_noexcept { return 0; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_30(mk_lang_types_void_t) mk_lang_noexcept { return 0; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_31(mk_lang_types_void_t) mk_lang_noexcept { return 1; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_32(mk_lang_types_void_t) mk_lang_noexcept { return 1; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_33(mk_lang_types_void_t) mk_lang_noexcept { return 0; }
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_34(mk_lang_types_void_t) mk_lang_noexcept { return 1; }

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_twofish_128_idx_xy(mk_lang_types_sint_t const a, mk_lang_types_sint_t const b) mk_lang_noexcept
{
	mk_lang_types_sint_t ta mk_lang_constexpr_init;

	mk_lang_assert(a >= 0 && a < 4);
	mk_lang_assert(b >= 0 && b < 5);

	ta = a * 10 + b;
	switch(ta)
	{
		case 00: return mk_lib_crypto_alg_twofish_128_idx_00(); break;
		case 01: return mk_lib_crypto_alg_twofish_128_idx_01(); break;
		case 02: return mk_lib_crypto_alg_twofish_128_idx_02(); break;
		case 03: return mk_lib_crypto_alg_twofish_128_idx_03(); break;
		case 04: return mk_lib_crypto_alg_twofish_128_idx_04(); break;
		case 10: return mk_lib_crypto_alg_twofish_128_idx_10(); break;
		case 11: return mk_lib_crypto_alg_twofish_128_idx_11(); break;
		case 12: return mk_lib_crypto_alg_twofish_128_idx_12(); break;
		case 13: return mk_lib_crypto_alg_twofish_128_idx_13(); break;
		case 14: return mk_lib_crypto_alg_twofish_128_idx_14(); break;
		case 20: return mk_lib_crypto_alg_twofish_128_idx_20(); break;
		case 21: return mk_lib_crypto_alg_twofish_128_idx_21(); break;
		case 22: return mk_lib_crypto_alg_twofish_128_idx_22(); break;
		case 23: return mk_lib_crypto_alg_twofish_128_idx_23(); break;
		case 24: return mk_lib_crypto_alg_twofish_128_idx_24(); break;
		case 30: return mk_lib_crypto_alg_twofish_128_idx_30(); break;
		case 31: return mk_lib_crypto_alg_twofish_128_idx_31(); break;
		case 32: return mk_lib_crypto_alg_twofish_128_idx_32(); break;
		case 33: return mk_lib_crypto_alg_twofish_128_idx_33(); break;
		case 34: return mk_lib_crypto_alg_twofish_128_idx_34(); break;
		default: mk_lang_assert(mk_lang_false); return -1; break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_f_x(mk_lang_types_sint_t const a, mk_sl_cui_uint8_pct const b, mk_lang_static_param(mk_sl_cui_uint32_ct, c, mk_lib_crypto_alg_twofish_128_sbox_words), mk_sl_cui_uint8_pt const d) mk_lang_noexcept
{
	mk_sl_cui_uint8_t bb[mk_lib_crypto_alg_twofish_128_word_bytes] mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct ta mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb mk_lang_constexpr_init;

	mk_lang_assert(a >= 0 && a < mk_lib_crypto_alg_twofish_128_word_bytes);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	mk_sl_cui_uint8_to_bi_sint(b, &tsi);
	ta = &s_mk_lib_crypto_alg_twofish_128_tables.m_data.m_tables[mk_lib_crypto_alg_twofish_128_idx_xy(a, 2)].m_data.m_uint8s[tsi];
	mk_sl_uint_32_to_8_le(&c[1], &bb[0]);
	mk_sl_cui_uint8_xor3(ta, &bb[a], &tb);
	mk_sl_cui_uint8_to_bi_sint(&tb, &tsi);
	ta = &s_mk_lib_crypto_alg_twofish_128_tables.m_data.m_tables[mk_lib_crypto_alg_twofish_128_idx_xy(a, 1)].m_data.m_uint8s[tsi];
	mk_sl_uint_32_to_8_le(&c[0], &bb[0]);
	mk_sl_cui_uint8_xor3(ta, &bb[a], &tb);
	mk_sl_cui_uint8_to_bi_sint(&tb, &tsi);
	*d = s_mk_lib_crypto_alg_twofish_128_tables.m_data.m_tables[mk_lib_crypto_alg_twofish_128_idx_xy(a, 0)].m_data.m_uint8s[tsi];
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_f(mk_sl_cui_uint32_pct const a, mk_lang_static_param(mk_sl_cui_uint32_ct, b, mk_lib_crypto_alg_twofish_128_sbox_words), mk_sl_cui_uint32_pt const c) mk_lang_noexcept
{
	mk_sl_cui_uint8_t ta[mk_lib_crypto_alg_twofish_128_word_bytes] mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tb[mk_lib_crypto_alg_twofish_128_word_bytes] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t td mk_lang_constexpr_init;
	mk_sl_cui_uint8_t te[mk_lib_crypto_alg_twofish_128_word_bytes] mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_uint_32_to_8_le(a, &ta[0]);
	for(i = 0; i != mk_lib_crypto_alg_twofish_128_word_bytes; ++i)
	{
		mk_lib_crypto_alg_twofish_128_f_x(i, &ta[i], b, &ta[i]);
	}
	for(i = 0; i != mk_lib_crypto_alg_twofish_128_word_bytes; ++i)
	{
		for(j = 0; j != mk_lib_crypto_alg_twofish_128_word_bytes; ++j)
		{
			mk_lib_crypto_alg_twofish_128_mul_xy(i, j, &ta[j], &tb[j]);
		}
		mk_sl_cui_uint8_xor3(&tb[0], &tb[1], &tc);
		mk_sl_cui_uint8_xor3(&tb[2], &tb[3], &td);
		mk_sl_cui_uint8_xor3(&tc, &td, &te[i]);
	}
	mk_sl_uint_32_from_8_le(c, &te[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_rs_rem(mk_sl_cui_uint32_pct const a, mk_sl_cui_uint32_pt const b) mk_lang_noexcept
{
	mk_sl_cui_uint32_t bb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t g2 mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32 mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t g3 mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint32_shr3(a, 24, &bb);
	mk_sl_cui_uint32_shl3(&bb, 1, &g2);
	mk_sl_cui_uint32_set_mask(&tu32, 8);
	mk_sl_cui_uint32_and2(&g2, &tu32);
	mk_sl_cui_uint32_shr3(&bb, 7, &tu32);
	tuc = mk_sl_cui_uint32_is_zero(&tu32) ? ((mk_lang_types_uchar_t)(0x00)) : ((mk_lang_types_uchar_t)(0x4d));
	mk_sl_cui_uint32_from_bi_uchar(&tu32, &tuc);
	mk_sl_cui_uint32_xor2(&g2, &tu32);
	mk_sl_cui_uint32_shr3(&bb, 1, &g3);
	tuc = mk_sl_cui_uint32_has_lsb(&bb) ? ((mk_lang_types_uchar_t)(0xa6)) : ((mk_lang_types_uchar_t)(0x00));
	mk_sl_cui_uint32_from_bi_uchar(&tu32, &tuc);
	mk_sl_cui_uint32_xor2(&g3, &tu32);
	mk_sl_cui_uint32_xor2(&g3, &g2);
	mk_sl_cui_uint32_shl3(&g3, 24, &tu32);
	mk_sl_cui_uint32_shl2(&g3, 8);
	mk_sl_cui_uint32_or2(&g3, &tu32);
	mk_sl_cui_uint32_shl2(&g2, 16);
	mk_sl_cui_uint32_or2(&g2, &bb);
	mk_sl_cui_uint32_or2(&g2, &g3);
	mk_sl_cui_uint32_shl3(a, 8, &tu32);
	mk_sl_cui_uint32_xor3(&tu32, &g2, b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_mds_encode(mk_sl_cui_uint32_prct const a, mk_sl_cui_uint32_prct const b, mk_sl_cui_uint32_prt const c) mk_lang_noexcept
{
	mk_sl_cui_uint32_t r mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);

	r = *b;
	for(i = 0; i != 4; ++i)
	{
		mk_lib_crypto_alg_twofish_128_rs_rem(&r, &r);
	}
	mk_sl_cui_uint32_xor2(&r, a);
	for(i = 0; i != 4; ++i)
	{
		mk_lib_crypto_alg_twofish_128_rs_rem(&r, &r);
	}
	*c = r;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_expand(mk_lib_crypto_alg_twofish_128_key_pct const key, mk_lib_crypto_alg_twofish_128_schedule_pt const schedule) mk_lang_noexcept
{
	#define mk_lib_crypto_alg_twofish_128_sk_step (0x02020202ul)
	#define mk_lib_crypto_alg_twofish_128_sk_bump (0x01010101ul)

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ke[mk_lib_crypto_alg_twofish_128_key_words / 2] mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ko[mk_lib_crypto_alg_twofish_128_key_words / 2] mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_sl_cui_uint32_t skta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t sktb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ska mk_lang_constexpr_init;
	mk_sl_cui_uint32_t a mk_lang_constexpr_init;
	mk_sl_cui_uint32_t skb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t b mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	n = mk_lib_crypto_alg_twofish_128_sbox_words;
	for(i = 0; i != n; ++i)
	{
		mk_sl_uint_32_from_8_le(&ke[i], &key->m_data.m_uint8s[(i * 2 + 0) * mk_lib_crypto_alg_twofish_128_word_bytes]);
		mk_sl_uint_32_from_8_le(&ko[i], &key->m_data.m_uint8s[(i * 2 + 1) * mk_lib_crypto_alg_twofish_128_word_bytes]);
		mk_lib_crypto_alg_twofish_128_mds_encode(&ke[i], &ko[i], &schedule->m_data.m_uint32s[(0 * mk_lib_crypto_alg_twofish_128_sbox_words) + (mk_lib_crypto_alg_twofish_128_sbox_words - 1) - i]);
	}
	tul = mk_lib_crypto_alg_twofish_128_sk_step; mk_sl_cui_uint32_from_bi_ulong(&skta, &tul);
	tul = mk_lib_crypto_alg_twofish_128_sk_bump; mk_sl_cui_uint32_from_bi_ulong(&sktb, &tul);
	mk_sl_cui_uint32_set_zero(&ska);
	n = (2 * mk_lib_crypto_alg_twofish_128_msg_words + 2 * mk_lib_crypto_alg_twofish_128_nr);
	for(i = 0; i != n / 2; ++i)
	{
		mk_lib_crypto_alg_twofish_128_f(&ska, &ke[0], &a); mk_sl_cui_uint32_add3_wrap_cid_cod(&ska, &sktb, &skb);
		mk_lib_crypto_alg_twofish_128_f(&skb, &ko[0], &b); mk_sl_cui_uint32_add2_wrap_cid_cod(&ska, &skta);
		mk_sl_cui_uint32_rotl2(&b, 8);
		mk_sl_cui_uint32_add3_wrap_cid_cod(&a, &b, &schedule->m_data.m_uint32s[(1 * mk_lib_crypto_alg_twofish_128_sbox_words) + i * 2 + 0]);
		mk_sl_cui_uint32_shl2(&b, 1);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&a, &b);
		mk_sl_cui_uint32_rotl3(&a, 9, &schedule->m_data.m_uint32s[(1 * mk_lib_crypto_alg_twofish_128_sbox_words) + i * 2 + 1]);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_schedule_encrypt_round(mk_lib_crypto_alg_twofish_128_schedule_pct const schedule, mk_lang_types_sint_t const ir, mk_lang_static_param(mk_sl_cui_uint32_t, x, mk_lib_crypto_alg_twofish_128_msg_words)) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ttb mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(ir >= 0 && ir < mk_lib_crypto_alg_twofish_128_nr);
	mk_lang_assert(x);

	mk_sl_cui_uint32_rotl3(&x[1], 8, &ta);
	mk_lib_crypto_alg_twofish_128_f(&x[0], &schedule->m_data.m_uint32s[(0 * mk_lib_crypto_alg_twofish_128_sbox_words)], &tta);
	mk_lib_crypto_alg_twofish_128_f(&ta, &schedule->m_data.m_uint32s[(0 * mk_lib_crypto_alg_twofish_128_sbox_words)], &ttb);
	mk_sl_cui_uint32_rotl2(&x[3], 1);
	mk_sl_cui_uint32_add3_wrap_cid_cod(&tta, &ttb, &ta);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &schedule->m_data.m_uint32s[(1 * mk_lib_crypto_alg_twofish_128_sbox_words) + (2 * mk_lib_crypto_alg_twofish_128_msg_words) + 2 * ir + 0]);
	mk_sl_cui_uint32_xor2(&x[2], &ta);
	mk_sl_cui_uint32_shl3(&ttb, 1, &ta);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &tta);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &schedule->m_data.m_uint32s[(1 * mk_lib_crypto_alg_twofish_128_sbox_words) + (2 * mk_lib_crypto_alg_twofish_128_msg_words) + 2 * ir + 1]);
	mk_sl_cui_uint32_xor2(&x[3], &ta);
	mk_sl_cui_uint32_rotr2(&x[2], 1);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_schedule_decrypt_round(mk_lib_crypto_alg_twofish_128_schedule_pct const schedule, mk_lang_types_sint_t const ir, mk_lang_static_param(mk_sl_cui_uint32_t, x, mk_lib_crypto_alg_twofish_128_msg_words)) mk_lang_noexcept
{
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ttb mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(ir >= 0 && ir < mk_lib_crypto_alg_twofish_128_nr);
	mk_lang_assert(x);

	mk_sl_cui_uint32_rotl3(&x[1], 8, &ta);
	mk_lib_crypto_alg_twofish_128_f(&x[0], &schedule->m_data.m_uint32s[(0 * mk_lib_crypto_alg_twofish_128_sbox_words)], &tta);
	mk_lib_crypto_alg_twofish_128_f(&ta, &schedule->m_data.m_uint32s[(0 * mk_lib_crypto_alg_twofish_128_sbox_words)], &ttb);
	mk_sl_cui_uint32_rotl2(&x[2], 1);
	mk_sl_cui_uint32_add3_wrap_cid_cod(&tta, &ttb, &ta);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &schedule->m_data.m_uint32s[(1 * mk_lib_crypto_alg_twofish_128_sbox_words) + (2 * mk_lib_crypto_alg_twofish_128_msg_words) + 2 * ir + 0]);
	mk_sl_cui_uint32_xor2(&x[2], &ta);
	mk_sl_cui_uint32_shl3(&ttb, 1, &ta);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &tta);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&ta, &schedule->m_data.m_uint32s[(1 * mk_lib_crypto_alg_twofish_128_sbox_words) + (2 * mk_lib_crypto_alg_twofish_128_msg_words) + 2 * ir + 1]);
	mk_sl_cui_uint32_xor2(&x[3], &ta);
	mk_sl_cui_uint32_rotr2(&x[3], 1);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_schedule_encrypt_one(mk_lib_crypto_alg_twofish_128_schedule_pct const schedule, mk_lib_crypto_alg_twofish_128_msg_pct const input, mk_lib_crypto_alg_twofish_128_msg_pt const output) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint32_t x[mk_lib_crypto_alg_twofish_128_msg_words] mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	n = mk_lib_crypto_alg_twofish_128_msg_words;
	for(i = 0; i != n; ++i)
	{
		mk_sl_uint_32_from_8_le(&x[i], &input->m_data.m_uint8s[i * mk_lib_crypto_alg_twofish_128_word_bytes]);
		mk_sl_cui_uint32_xor2(&x[i], &schedule->m_data.m_uint32s[(1 * mk_lib_crypto_alg_twofish_128_sbox_words) + (0 * mk_lib_crypto_alg_twofish_128_msg_words) + i]);
	}
	n = mk_lib_crypto_alg_twofish_128_nr;
	for(i = 0; i != n - 1; ++i)
	{
		mk_lib_crypto_alg_twofish_128_schedule_encrypt_round(schedule, i, &x[0]);
		ta = x[0]; x[0] = x[2]; x[2] = ta;
		ta = x[1]; x[1] = x[3]; x[3] = ta;
	}
	mk_lib_crypto_alg_twofish_128_schedule_encrypt_round(schedule, i, &x[0]);
	n = mk_lib_crypto_alg_twofish_128_msg_words;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint32_xor2(&x[i], &schedule->m_data.m_uint32s[(1 * mk_lib_crypto_alg_twofish_128_sbox_words) + (1 * mk_lib_crypto_alg_twofish_128_msg_words) + i]);
		mk_sl_uint_32_to_8_le(&x[i], &output->m_data.m_uint8s[i * mk_lib_crypto_alg_twofish_128_word_bytes]);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_schedule_decrypt_one(mk_lib_crypto_alg_twofish_128_schedule_pct const schedule, mk_lib_crypto_alg_twofish_128_msg_pct const input, mk_lib_crypto_alg_twofish_128_msg_pt const output) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint32_t x[mk_lib_crypto_alg_twofish_128_msg_words] mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	n = mk_lib_crypto_alg_twofish_128_msg_words;
	for(i = 0; i != n; ++i)
	{
		mk_sl_uint_32_from_8_le(&x[i], &input->m_data.m_uint8s[i * mk_lib_crypto_alg_twofish_128_word_bytes]);
		mk_sl_cui_uint32_xor2(&x[i], &schedule->m_data.m_uint32s[(1 * mk_lib_crypto_alg_twofish_128_sbox_words) + (1 * mk_lib_crypto_alg_twofish_128_msg_words) + i]);
	}
	n = mk_lib_crypto_alg_twofish_128_nr;
	for(i = 0; i != n - 1; ++i)
	{
		mk_lib_crypto_alg_twofish_128_schedule_decrypt_round(schedule, (mk_lib_crypto_alg_twofish_128_nr - 1) - i, &x[0]);
		ta = x[0]; x[0] = x[2]; x[2] = ta;
		ta = x[1]; x[1] = x[3]; x[3] = ta;
	}
	mk_lib_crypto_alg_twofish_128_schedule_decrypt_round(schedule, (mk_lib_crypto_alg_twofish_128_nr - 1) - i, &x[0]);
	n = mk_lib_crypto_alg_twofish_128_msg_words;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint32_xor2(&x[i], &schedule->m_data.m_uint32s[(1 * mk_lib_crypto_alg_twofish_128_sbox_words) + (0 * mk_lib_crypto_alg_twofish_128_msg_words) + i]);
		mk_sl_uint_32_to_8_le(&x[i], &output->m_data.m_uint8s[i * mk_lib_crypto_alg_twofish_128_word_bytes]);
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_schedule_encrypt(mk_lib_crypto_alg_twofish_128_schedule_pct const schedule, mk_lib_crypto_alg_twofish_128_msg_pct const input, mk_lib_crypto_alg_twofish_128_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input || nblocks == 0);
	mk_lang_assert(output || nblocks == 0);
	mk_lang_assert(nblocks >= 0);

	n = nblocks;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_alg_twofish_128_schedule_encrypt_one(schedule, &input[i], &output[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_schedule_decrypt(mk_lib_crypto_alg_twofish_128_schedule_pct const schedule, mk_lib_crypto_alg_twofish_128_msg_pct const input, mk_lib_crypto_alg_twofish_128_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input || nblocks == 0);
	mk_lang_assert(output || nblocks == 0);
	mk_lang_assert(nblocks >= 0);

	n = nblocks;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_alg_twofish_128_schedule_decrypt_one(schedule, &input[i], &output[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_expand_enc(mk_lib_crypto_alg_twofish_128_key_pct const key, mk_lib_crypto_alg_twofish_128_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_twofish_128_expand(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_expand_dec(mk_lib_crypto_alg_twofish_128_key_pct const key, mk_lib_crypto_alg_twofish_128_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_twofish_128_expand(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_encrypt(mk_lib_crypto_alg_twofish_128_key_pct const key, mk_lib_crypto_alg_twofish_128_msg_pct const input, mk_lib_crypto_alg_twofish_128_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_twofish_128_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_twofish_128_expand_enc(key, &schedule);
	mk_lib_crypto_alg_twofish_128_schedule_encrypt(&schedule, input, output, 1);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_128_decrypt(mk_lib_crypto_alg_twofish_128_key_pct const key, mk_lib_crypto_alg_twofish_128_msg_pct const input, mk_lib_crypto_alg_twofish_128_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_twofish_128_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_twofish_128_expand_dec(key, &schedule);
	mk_lib_crypto_alg_twofish_128_schedule_decrypt(&schedule, input, output, 1);
}
