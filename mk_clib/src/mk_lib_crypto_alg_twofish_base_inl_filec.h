#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"


#include "mk_lib_crypto_alg_twofish_base_inl_defd.h"


#define mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes (32 / mk_lang_charbit)
#define mk_lib_crypto_alg_twofish_base_inl_filec_key_words (mk_lib_crypto_alg_twofish_base_inl_defd_key_len_m / mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes)
#define mk_lib_crypto_alg_twofish_base_inl_filec_msg_words (mk_lib_crypto_alg_twofish_base_inl_defd_msg_len_m / mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes)
#define mk_lib_crypto_alg_twofish_base_inl_filec_sbox_words (mk_lib_crypto_alg_twofish_base_inl_filec_key_words / 2)


union mk_lib_crypto_alg_twofish_base_inl_defd_uint328_data_u
{
	mk_sl_cui_uint8_t m_uint8s[32 / 8];
	mk_sl_cui_uint32_t m_uint32;
};
typedef union mk_lib_crypto_alg_twofish_base_inl_defd_uint328_data_u mk_lib_crypto_alg_twofish_base_inl_defd_uint328_data_t;

struct mk_lib_crypto_alg_twofish_base_inl_defd_uint328_s
{
	mk_lib_crypto_alg_twofish_base_inl_defd_uint328_data_t m_data;
};
typedef struct mk_lib_crypto_alg_twofish_base_inl_defd_uint328_s mk_lib_crypto_alg_twofish_base_inl_defd_uint328_t;


union mk_lib_crypto_alg_twofish_base_inl_defd_table_q_data_u
{
	mk_lang_alignas(64) mk_sl_cui_uint8_t m_uint8s[0xff + 1];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_twofish_base_inl_defd_table_q_data_u mk_lib_crypto_alg_twofish_base_inl_defd_table_q_data_t;

struct mk_lib_crypto_alg_twofish_base_inl_defd_table_q_s
{
	mk_lib_crypto_alg_twofish_base_inl_defd_table_q_data_t m_data;
};
typedef struct mk_lib_crypto_alg_twofish_base_inl_defd_table_q_s mk_lib_crypto_alg_twofish_base_inl_defd_table_q_t;


struct mk_lib_crypto_alg_twofish_base_inl_defd_tables_q_data_s
{
	mk_lib_crypto_alg_twofish_base_inl_defd_table_q_t m_tables[2];
};
typedef struct mk_lib_crypto_alg_twofish_base_inl_defd_tables_q_data_s mk_lib_crypto_alg_twofish_base_inl_defd_tables_q_data_t;

struct mk_lib_crypto_alg_twofish_base_inl_defd_tables_q_s
{
	mk_lib_crypto_alg_twofish_base_inl_defd_tables_q_data_t m_data;
};
typedef struct mk_lib_crypto_alg_twofish_base_inl_defd_tables_q_s mk_lib_crypto_alg_twofish_base_inl_defd_tables_q_t;


union mk_lib_crypto_alg_twofish_base_inl_defd_table_mdsq_data_u
{
	mk_lang_alignas(64) mk_sl_cui_uint32_t m_uint32s[0xff + 1];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_twofish_base_inl_defd_table_mdsq_data_u mk_lib_crypto_alg_twofish_base_inl_defd_table_mdsq_data_t;

struct mk_lib_crypto_alg_twofish_base_inl_defd_table_mdsq_s
{
	mk_lib_crypto_alg_twofish_base_inl_defd_table_mdsq_data_t m_data;
};
typedef struct mk_lib_crypto_alg_twofish_base_inl_defd_table_mdsq_s mk_lib_crypto_alg_twofish_base_inl_defd_table_mdsq_t;


struct mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq_data_s
{
	mk_lib_crypto_alg_twofish_base_inl_defd_table_mdsq_t m_tables[4];
};
typedef struct mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq_data_s mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq_data_t;

struct mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq_s
{
	mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq_data_t m_data;
};
typedef struct mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq_s mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq_t;


union mk_lib_crypto_alg_twofish_base_inl_defd_table_rs_data_u
{
	mk_lang_alignas(64) mk_sl_cui_uint32_t m_uint32s[0xff + 1];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_crypto_alg_twofish_base_inl_defd_table_rs_data_u mk_lib_crypto_alg_twofish_base_inl_defd_table_rs_data_t;

struct mk_lib_crypto_alg_twofish_base_inl_defd_table_rs_s
{
	mk_lib_crypto_alg_twofish_base_inl_defd_table_rs_data_t m_data;
};
typedef struct mk_lib_crypto_alg_twofish_base_inl_defd_table_rs_s mk_lib_crypto_alg_twofish_base_inl_defd_table_rs_t;


struct mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs_data_s
{
	mk_lib_crypto_alg_twofish_base_inl_defd_table_rs_t m_tables[8];
};
typedef struct mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs_data_s mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs_data_t;

struct mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs_s
{
	mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs_data_t m_data;
};
typedef struct mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs_s mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs_t;


mk_lang_constexpr_static_inline mk_lib_crypto_alg_twofish_base_inl_defd_tables_q_t const mk_lib_crypto_alg_twofish_base_inl_defd_tables_q =
{{{
	{{{
			mk_sl_cui_uint8_c(0xa9ul), mk_sl_cui_uint8_c(0x67ul), mk_sl_cui_uint8_c(0xb3ul), mk_sl_cui_uint8_c(0xe8ul), mk_sl_cui_uint8_c(0x04ul), mk_sl_cui_uint8_c(0xfdul), mk_sl_cui_uint8_c(0xa3ul), mk_sl_cui_uint8_c(0x76ul), mk_sl_cui_uint8_c(0x9aul), mk_sl_cui_uint8_c(0x92ul), mk_sl_cui_uint8_c(0x80ul), mk_sl_cui_uint8_c(0x78ul), mk_sl_cui_uint8_c(0xe4ul), mk_sl_cui_uint8_c(0xddul), mk_sl_cui_uint8_c(0xd1ul), mk_sl_cui_uint8_c(0x38ul),
			mk_sl_cui_uint8_c(0x0dul), mk_sl_cui_uint8_c(0xc6ul), mk_sl_cui_uint8_c(0x35ul), mk_sl_cui_uint8_c(0x98ul), mk_sl_cui_uint8_c(0x18ul), mk_sl_cui_uint8_c(0xf7ul), mk_sl_cui_uint8_c(0xecul), mk_sl_cui_uint8_c(0x6cul), mk_sl_cui_uint8_c(0x43ul), mk_sl_cui_uint8_c(0x75ul), mk_sl_cui_uint8_c(0x37ul), mk_sl_cui_uint8_c(0x26ul), mk_sl_cui_uint8_c(0xfaul), mk_sl_cui_uint8_c(0x13ul), mk_sl_cui_uint8_c(0x94ul), mk_sl_cui_uint8_c(0x48ul),
			mk_sl_cui_uint8_c(0xf2ul), mk_sl_cui_uint8_c(0xd0ul), mk_sl_cui_uint8_c(0x8bul), mk_sl_cui_uint8_c(0x30ul), mk_sl_cui_uint8_c(0x84ul), mk_sl_cui_uint8_c(0x54ul), mk_sl_cui_uint8_c(0xdful), mk_sl_cui_uint8_c(0x23ul), mk_sl_cui_uint8_c(0x19ul), mk_sl_cui_uint8_c(0x5bul), mk_sl_cui_uint8_c(0x3dul), mk_sl_cui_uint8_c(0x59ul), mk_sl_cui_uint8_c(0xf3ul), mk_sl_cui_uint8_c(0xaeul), mk_sl_cui_uint8_c(0xa2ul), mk_sl_cui_uint8_c(0x82ul),
			mk_sl_cui_uint8_c(0x63ul), mk_sl_cui_uint8_c(0x01ul), mk_sl_cui_uint8_c(0x83ul), mk_sl_cui_uint8_c(0x2eul), mk_sl_cui_uint8_c(0xd9ul), mk_sl_cui_uint8_c(0x51ul), mk_sl_cui_uint8_c(0x9bul), mk_sl_cui_uint8_c(0x7cul), mk_sl_cui_uint8_c(0xa6ul), mk_sl_cui_uint8_c(0xebul), mk_sl_cui_uint8_c(0xa5ul), mk_sl_cui_uint8_c(0xbeul), mk_sl_cui_uint8_c(0x16ul), mk_sl_cui_uint8_c(0x0cul), mk_sl_cui_uint8_c(0xe3ul), mk_sl_cui_uint8_c(0x61ul),
			mk_sl_cui_uint8_c(0xc0ul), mk_sl_cui_uint8_c(0x8cul), mk_sl_cui_uint8_c(0x3aul), mk_sl_cui_uint8_c(0xf5ul), mk_sl_cui_uint8_c(0x73ul), mk_sl_cui_uint8_c(0x2cul), mk_sl_cui_uint8_c(0x25ul), mk_sl_cui_uint8_c(0x0bul), mk_sl_cui_uint8_c(0xbbul), mk_sl_cui_uint8_c(0x4eul), mk_sl_cui_uint8_c(0x89ul), mk_sl_cui_uint8_c(0x6bul), mk_sl_cui_uint8_c(0x53ul), mk_sl_cui_uint8_c(0x6aul), mk_sl_cui_uint8_c(0xb4ul), mk_sl_cui_uint8_c(0xf1ul),
			mk_sl_cui_uint8_c(0xe1ul), mk_sl_cui_uint8_c(0xe6ul), mk_sl_cui_uint8_c(0xbdul), mk_sl_cui_uint8_c(0x45ul), mk_sl_cui_uint8_c(0xe2ul), mk_sl_cui_uint8_c(0xf4ul), mk_sl_cui_uint8_c(0xb6ul), mk_sl_cui_uint8_c(0x66ul), mk_sl_cui_uint8_c(0xccul), mk_sl_cui_uint8_c(0x95ul), mk_sl_cui_uint8_c(0x03ul), mk_sl_cui_uint8_c(0x56ul), mk_sl_cui_uint8_c(0xd4ul), mk_sl_cui_uint8_c(0x1cul), mk_sl_cui_uint8_c(0x1eul), mk_sl_cui_uint8_c(0xd7ul),
			mk_sl_cui_uint8_c(0xfbul), mk_sl_cui_uint8_c(0xc3ul), mk_sl_cui_uint8_c(0x8eul), mk_sl_cui_uint8_c(0xb5ul), mk_sl_cui_uint8_c(0xe9ul), mk_sl_cui_uint8_c(0xcful), mk_sl_cui_uint8_c(0xbful), mk_sl_cui_uint8_c(0xbaul), mk_sl_cui_uint8_c(0xeaul), mk_sl_cui_uint8_c(0x77ul), mk_sl_cui_uint8_c(0x39ul), mk_sl_cui_uint8_c(0xaful), mk_sl_cui_uint8_c(0x33ul), mk_sl_cui_uint8_c(0xc9ul), mk_sl_cui_uint8_c(0x62ul), mk_sl_cui_uint8_c(0x71ul),
			mk_sl_cui_uint8_c(0x81ul), mk_sl_cui_uint8_c(0x79ul), mk_sl_cui_uint8_c(0x09ul), mk_sl_cui_uint8_c(0xadul), mk_sl_cui_uint8_c(0x24ul), mk_sl_cui_uint8_c(0xcdul), mk_sl_cui_uint8_c(0xf9ul), mk_sl_cui_uint8_c(0xd8ul), mk_sl_cui_uint8_c(0xe5ul), mk_sl_cui_uint8_c(0xc5ul), mk_sl_cui_uint8_c(0xb9ul), mk_sl_cui_uint8_c(0x4dul), mk_sl_cui_uint8_c(0x44ul), mk_sl_cui_uint8_c(0x08ul), mk_sl_cui_uint8_c(0x86ul), mk_sl_cui_uint8_c(0xe7ul),
			mk_sl_cui_uint8_c(0xa1ul), mk_sl_cui_uint8_c(0x1dul), mk_sl_cui_uint8_c(0xaaul), mk_sl_cui_uint8_c(0xedul), mk_sl_cui_uint8_c(0x06ul), mk_sl_cui_uint8_c(0x70ul), mk_sl_cui_uint8_c(0xb2ul), mk_sl_cui_uint8_c(0xd2ul), mk_sl_cui_uint8_c(0x41ul), mk_sl_cui_uint8_c(0x7bul), mk_sl_cui_uint8_c(0xa0ul), mk_sl_cui_uint8_c(0x11ul), mk_sl_cui_uint8_c(0x31ul), mk_sl_cui_uint8_c(0xc2ul), mk_sl_cui_uint8_c(0x27ul), mk_sl_cui_uint8_c(0x90ul),
			mk_sl_cui_uint8_c(0x20ul), mk_sl_cui_uint8_c(0xf6ul), mk_sl_cui_uint8_c(0x60ul), mk_sl_cui_uint8_c(0xfful), mk_sl_cui_uint8_c(0x96ul), mk_sl_cui_uint8_c(0x5cul), mk_sl_cui_uint8_c(0xb1ul), mk_sl_cui_uint8_c(0xabul), mk_sl_cui_uint8_c(0x9eul), mk_sl_cui_uint8_c(0x9cul), mk_sl_cui_uint8_c(0x52ul), mk_sl_cui_uint8_c(0x1bul), mk_sl_cui_uint8_c(0x5ful), mk_sl_cui_uint8_c(0x93ul), mk_sl_cui_uint8_c(0x0aul), mk_sl_cui_uint8_c(0xeful),
			mk_sl_cui_uint8_c(0x91ul), mk_sl_cui_uint8_c(0x85ul), mk_sl_cui_uint8_c(0x49ul), mk_sl_cui_uint8_c(0xeeul), mk_sl_cui_uint8_c(0x2dul), mk_sl_cui_uint8_c(0x4ful), mk_sl_cui_uint8_c(0x8ful), mk_sl_cui_uint8_c(0x3bul), mk_sl_cui_uint8_c(0x47ul), mk_sl_cui_uint8_c(0x87ul), mk_sl_cui_uint8_c(0x6dul), mk_sl_cui_uint8_c(0x46ul), mk_sl_cui_uint8_c(0xd6ul), mk_sl_cui_uint8_c(0x3eul), mk_sl_cui_uint8_c(0x69ul), mk_sl_cui_uint8_c(0x64ul),
			mk_sl_cui_uint8_c(0x2aul), mk_sl_cui_uint8_c(0xceul), mk_sl_cui_uint8_c(0xcbul), mk_sl_cui_uint8_c(0x2ful), mk_sl_cui_uint8_c(0xfcul), mk_sl_cui_uint8_c(0x97ul), mk_sl_cui_uint8_c(0x05ul), mk_sl_cui_uint8_c(0x7aul), mk_sl_cui_uint8_c(0xacul), mk_sl_cui_uint8_c(0x7ful), mk_sl_cui_uint8_c(0xd5ul), mk_sl_cui_uint8_c(0x1aul), mk_sl_cui_uint8_c(0x4bul), mk_sl_cui_uint8_c(0x0eul), mk_sl_cui_uint8_c(0xa7ul), mk_sl_cui_uint8_c(0x5aul),
			mk_sl_cui_uint8_c(0x28ul), mk_sl_cui_uint8_c(0x14ul), mk_sl_cui_uint8_c(0x3ful), mk_sl_cui_uint8_c(0x29ul), mk_sl_cui_uint8_c(0x88ul), mk_sl_cui_uint8_c(0x3cul), mk_sl_cui_uint8_c(0x4cul), mk_sl_cui_uint8_c(0x02ul), mk_sl_cui_uint8_c(0xb8ul), mk_sl_cui_uint8_c(0xdaul), mk_sl_cui_uint8_c(0xb0ul), mk_sl_cui_uint8_c(0x17ul), mk_sl_cui_uint8_c(0x55ul), mk_sl_cui_uint8_c(0x1ful), mk_sl_cui_uint8_c(0x8aul), mk_sl_cui_uint8_c(0x7dul),
			mk_sl_cui_uint8_c(0x57ul), mk_sl_cui_uint8_c(0xc7ul), mk_sl_cui_uint8_c(0x8dul), mk_sl_cui_uint8_c(0x74ul), mk_sl_cui_uint8_c(0xb7ul), mk_sl_cui_uint8_c(0xc4ul), mk_sl_cui_uint8_c(0x9ful), mk_sl_cui_uint8_c(0x72ul), mk_sl_cui_uint8_c(0x7eul), mk_sl_cui_uint8_c(0x15ul), mk_sl_cui_uint8_c(0x22ul), mk_sl_cui_uint8_c(0x12ul), mk_sl_cui_uint8_c(0x58ul), mk_sl_cui_uint8_c(0x07ul), mk_sl_cui_uint8_c(0x99ul), mk_sl_cui_uint8_c(0x34ul),
			mk_sl_cui_uint8_c(0x6eul), mk_sl_cui_uint8_c(0x50ul), mk_sl_cui_uint8_c(0xdeul), mk_sl_cui_uint8_c(0x68ul), mk_sl_cui_uint8_c(0x65ul), mk_sl_cui_uint8_c(0xbcul), mk_sl_cui_uint8_c(0xdbul), mk_sl_cui_uint8_c(0xf8ul), mk_sl_cui_uint8_c(0xc8ul), mk_sl_cui_uint8_c(0xa8ul), mk_sl_cui_uint8_c(0x2bul), mk_sl_cui_uint8_c(0x40ul), mk_sl_cui_uint8_c(0xdcul), mk_sl_cui_uint8_c(0xfeul), mk_sl_cui_uint8_c(0x32ul), mk_sl_cui_uint8_c(0xa4ul),
			mk_sl_cui_uint8_c(0xcaul), mk_sl_cui_uint8_c(0x10ul), mk_sl_cui_uint8_c(0x21ul), mk_sl_cui_uint8_c(0xf0ul), mk_sl_cui_uint8_c(0xd3ul), mk_sl_cui_uint8_c(0x5dul), mk_sl_cui_uint8_c(0x0ful), mk_sl_cui_uint8_c(0x00ul), mk_sl_cui_uint8_c(0x6ful), mk_sl_cui_uint8_c(0x9dul), mk_sl_cui_uint8_c(0x36ul), mk_sl_cui_uint8_c(0x42ul), mk_sl_cui_uint8_c(0x4aul), mk_sl_cui_uint8_c(0x5eul), mk_sl_cui_uint8_c(0xc1ul), mk_sl_cui_uint8_c(0xe0ul),
	}}},
	{{{
			mk_sl_cui_uint8_c(0x75ul), mk_sl_cui_uint8_c(0xf3ul), mk_sl_cui_uint8_c(0xc6ul), mk_sl_cui_uint8_c(0xf4ul), mk_sl_cui_uint8_c(0xdbul), mk_sl_cui_uint8_c(0x7bul), mk_sl_cui_uint8_c(0xfbul), mk_sl_cui_uint8_c(0xc8ul), mk_sl_cui_uint8_c(0x4aul), mk_sl_cui_uint8_c(0xd3ul), mk_sl_cui_uint8_c(0xe6ul), mk_sl_cui_uint8_c(0x6bul), mk_sl_cui_uint8_c(0x45ul), mk_sl_cui_uint8_c(0x7dul), mk_sl_cui_uint8_c(0xe8ul), mk_sl_cui_uint8_c(0x4bul),
			mk_sl_cui_uint8_c(0xd6ul), mk_sl_cui_uint8_c(0x32ul), mk_sl_cui_uint8_c(0xd8ul), mk_sl_cui_uint8_c(0xfdul), mk_sl_cui_uint8_c(0x37ul), mk_sl_cui_uint8_c(0x71ul), mk_sl_cui_uint8_c(0xf1ul), mk_sl_cui_uint8_c(0xe1ul), mk_sl_cui_uint8_c(0x30ul), mk_sl_cui_uint8_c(0x0ful), mk_sl_cui_uint8_c(0xf8ul), mk_sl_cui_uint8_c(0x1bul), mk_sl_cui_uint8_c(0x87ul), mk_sl_cui_uint8_c(0xfaul), mk_sl_cui_uint8_c(0x06ul), mk_sl_cui_uint8_c(0x3ful),
			mk_sl_cui_uint8_c(0x5eul), mk_sl_cui_uint8_c(0xbaul), mk_sl_cui_uint8_c(0xaeul), mk_sl_cui_uint8_c(0x5bul), mk_sl_cui_uint8_c(0x8aul), mk_sl_cui_uint8_c(0x00ul), mk_sl_cui_uint8_c(0xbcul), mk_sl_cui_uint8_c(0x9dul), mk_sl_cui_uint8_c(0x6dul), mk_sl_cui_uint8_c(0xc1ul), mk_sl_cui_uint8_c(0xb1ul), mk_sl_cui_uint8_c(0x0eul), mk_sl_cui_uint8_c(0x80ul), mk_sl_cui_uint8_c(0x5dul), mk_sl_cui_uint8_c(0xd2ul), mk_sl_cui_uint8_c(0xd5ul),
			mk_sl_cui_uint8_c(0xa0ul), mk_sl_cui_uint8_c(0x84ul), mk_sl_cui_uint8_c(0x07ul), mk_sl_cui_uint8_c(0x14ul), mk_sl_cui_uint8_c(0xb5ul), mk_sl_cui_uint8_c(0x90ul), mk_sl_cui_uint8_c(0x2cul), mk_sl_cui_uint8_c(0xa3ul), mk_sl_cui_uint8_c(0xb2ul), mk_sl_cui_uint8_c(0x73ul), mk_sl_cui_uint8_c(0x4cul), mk_sl_cui_uint8_c(0x54ul), mk_sl_cui_uint8_c(0x92ul), mk_sl_cui_uint8_c(0x74ul), mk_sl_cui_uint8_c(0x36ul), mk_sl_cui_uint8_c(0x51ul),
			mk_sl_cui_uint8_c(0x38ul), mk_sl_cui_uint8_c(0xb0ul), mk_sl_cui_uint8_c(0xbdul), mk_sl_cui_uint8_c(0x5aul), mk_sl_cui_uint8_c(0xfcul), mk_sl_cui_uint8_c(0x60ul), mk_sl_cui_uint8_c(0x62ul), mk_sl_cui_uint8_c(0x96ul), mk_sl_cui_uint8_c(0x6cul), mk_sl_cui_uint8_c(0x42ul), mk_sl_cui_uint8_c(0xf7ul), mk_sl_cui_uint8_c(0x10ul), mk_sl_cui_uint8_c(0x7cul), mk_sl_cui_uint8_c(0x28ul), mk_sl_cui_uint8_c(0x27ul), mk_sl_cui_uint8_c(0x8cul),
			mk_sl_cui_uint8_c(0x13ul), mk_sl_cui_uint8_c(0x95ul), mk_sl_cui_uint8_c(0x9cul), mk_sl_cui_uint8_c(0xc7ul), mk_sl_cui_uint8_c(0x24ul), mk_sl_cui_uint8_c(0x46ul), mk_sl_cui_uint8_c(0x3bul), mk_sl_cui_uint8_c(0x70ul), mk_sl_cui_uint8_c(0xcaul), mk_sl_cui_uint8_c(0xe3ul), mk_sl_cui_uint8_c(0x85ul), mk_sl_cui_uint8_c(0xcbul), mk_sl_cui_uint8_c(0x11ul), mk_sl_cui_uint8_c(0xd0ul), mk_sl_cui_uint8_c(0x93ul), mk_sl_cui_uint8_c(0xb8ul),
			mk_sl_cui_uint8_c(0xa6ul), mk_sl_cui_uint8_c(0x83ul), mk_sl_cui_uint8_c(0x20ul), mk_sl_cui_uint8_c(0xfful), mk_sl_cui_uint8_c(0x9ful), mk_sl_cui_uint8_c(0x77ul), mk_sl_cui_uint8_c(0xc3ul), mk_sl_cui_uint8_c(0xccul), mk_sl_cui_uint8_c(0x03ul), mk_sl_cui_uint8_c(0x6ful), mk_sl_cui_uint8_c(0x08ul), mk_sl_cui_uint8_c(0xbful), mk_sl_cui_uint8_c(0x40ul), mk_sl_cui_uint8_c(0xe7ul), mk_sl_cui_uint8_c(0x2bul), mk_sl_cui_uint8_c(0xe2ul),
			mk_sl_cui_uint8_c(0x79ul), mk_sl_cui_uint8_c(0x0cul), mk_sl_cui_uint8_c(0xaaul), mk_sl_cui_uint8_c(0x82ul), mk_sl_cui_uint8_c(0x41ul), mk_sl_cui_uint8_c(0x3aul), mk_sl_cui_uint8_c(0xeaul), mk_sl_cui_uint8_c(0xb9ul), mk_sl_cui_uint8_c(0xe4ul), mk_sl_cui_uint8_c(0x9aul), mk_sl_cui_uint8_c(0xa4ul), mk_sl_cui_uint8_c(0x97ul), mk_sl_cui_uint8_c(0x7eul), mk_sl_cui_uint8_c(0xdaul), mk_sl_cui_uint8_c(0x7aul), mk_sl_cui_uint8_c(0x17ul),
			mk_sl_cui_uint8_c(0x66ul), mk_sl_cui_uint8_c(0x94ul), mk_sl_cui_uint8_c(0xa1ul), mk_sl_cui_uint8_c(0x1dul), mk_sl_cui_uint8_c(0x3dul), mk_sl_cui_uint8_c(0xf0ul), mk_sl_cui_uint8_c(0xdeul), mk_sl_cui_uint8_c(0xb3ul), mk_sl_cui_uint8_c(0x0bul), mk_sl_cui_uint8_c(0x72ul), mk_sl_cui_uint8_c(0xa7ul), mk_sl_cui_uint8_c(0x1cul), mk_sl_cui_uint8_c(0xeful), mk_sl_cui_uint8_c(0xd1ul), mk_sl_cui_uint8_c(0x53ul), mk_sl_cui_uint8_c(0x3eul),
			mk_sl_cui_uint8_c(0x8ful), mk_sl_cui_uint8_c(0x33ul), mk_sl_cui_uint8_c(0x26ul), mk_sl_cui_uint8_c(0x5ful), mk_sl_cui_uint8_c(0xecul), mk_sl_cui_uint8_c(0x76ul), mk_sl_cui_uint8_c(0x2aul), mk_sl_cui_uint8_c(0x49ul), mk_sl_cui_uint8_c(0x81ul), mk_sl_cui_uint8_c(0x88ul), mk_sl_cui_uint8_c(0xeeul), mk_sl_cui_uint8_c(0x21ul), mk_sl_cui_uint8_c(0xc4ul), mk_sl_cui_uint8_c(0x1aul), mk_sl_cui_uint8_c(0xebul), mk_sl_cui_uint8_c(0xd9ul),
			mk_sl_cui_uint8_c(0xc5ul), mk_sl_cui_uint8_c(0x39ul), mk_sl_cui_uint8_c(0x99ul), mk_sl_cui_uint8_c(0xcdul), mk_sl_cui_uint8_c(0xadul), mk_sl_cui_uint8_c(0x31ul), mk_sl_cui_uint8_c(0x8bul), mk_sl_cui_uint8_c(0x01ul), mk_sl_cui_uint8_c(0x18ul), mk_sl_cui_uint8_c(0x23ul), mk_sl_cui_uint8_c(0xddul), mk_sl_cui_uint8_c(0x1ful), mk_sl_cui_uint8_c(0x4eul), mk_sl_cui_uint8_c(0x2dul), mk_sl_cui_uint8_c(0xf9ul), mk_sl_cui_uint8_c(0x48ul),
			mk_sl_cui_uint8_c(0x4ful), mk_sl_cui_uint8_c(0xf2ul), mk_sl_cui_uint8_c(0x65ul), mk_sl_cui_uint8_c(0x8eul), mk_sl_cui_uint8_c(0x78ul), mk_sl_cui_uint8_c(0x5cul), mk_sl_cui_uint8_c(0x58ul), mk_sl_cui_uint8_c(0x19ul), mk_sl_cui_uint8_c(0x8dul), mk_sl_cui_uint8_c(0xe5ul), mk_sl_cui_uint8_c(0x98ul), mk_sl_cui_uint8_c(0x57ul), mk_sl_cui_uint8_c(0x67ul), mk_sl_cui_uint8_c(0x7ful), mk_sl_cui_uint8_c(0x05ul), mk_sl_cui_uint8_c(0x64ul),
			mk_sl_cui_uint8_c(0xaful), mk_sl_cui_uint8_c(0x63ul), mk_sl_cui_uint8_c(0xb6ul), mk_sl_cui_uint8_c(0xfeul), mk_sl_cui_uint8_c(0xf5ul), mk_sl_cui_uint8_c(0xb7ul), mk_sl_cui_uint8_c(0x3cul), mk_sl_cui_uint8_c(0xa5ul), mk_sl_cui_uint8_c(0xceul), mk_sl_cui_uint8_c(0xe9ul), mk_sl_cui_uint8_c(0x68ul), mk_sl_cui_uint8_c(0x44ul), mk_sl_cui_uint8_c(0xe0ul), mk_sl_cui_uint8_c(0x4dul), mk_sl_cui_uint8_c(0x43ul), mk_sl_cui_uint8_c(0x69ul),
			mk_sl_cui_uint8_c(0x29ul), mk_sl_cui_uint8_c(0x2eul), mk_sl_cui_uint8_c(0xacul), mk_sl_cui_uint8_c(0x15ul), mk_sl_cui_uint8_c(0x59ul), mk_sl_cui_uint8_c(0xa8ul), mk_sl_cui_uint8_c(0x0aul), mk_sl_cui_uint8_c(0x9eul), mk_sl_cui_uint8_c(0x6eul), mk_sl_cui_uint8_c(0x47ul), mk_sl_cui_uint8_c(0xdful), mk_sl_cui_uint8_c(0x34ul), mk_sl_cui_uint8_c(0x35ul), mk_sl_cui_uint8_c(0x6aul), mk_sl_cui_uint8_c(0xcful), mk_sl_cui_uint8_c(0xdcul),
			mk_sl_cui_uint8_c(0x22ul), mk_sl_cui_uint8_c(0xc9ul), mk_sl_cui_uint8_c(0xc0ul), mk_sl_cui_uint8_c(0x9bul), mk_sl_cui_uint8_c(0x89ul), mk_sl_cui_uint8_c(0xd4ul), mk_sl_cui_uint8_c(0xedul), mk_sl_cui_uint8_c(0xabul), mk_sl_cui_uint8_c(0x12ul), mk_sl_cui_uint8_c(0xa2ul), mk_sl_cui_uint8_c(0x0dul), mk_sl_cui_uint8_c(0x52ul), mk_sl_cui_uint8_c(0xbbul), mk_sl_cui_uint8_c(0x02ul), mk_sl_cui_uint8_c(0x2ful), mk_sl_cui_uint8_c(0xa9ul),
			mk_sl_cui_uint8_c(0xd7ul), mk_sl_cui_uint8_c(0x61ul), mk_sl_cui_uint8_c(0x1eul), mk_sl_cui_uint8_c(0xb4ul), mk_sl_cui_uint8_c(0x50ul), mk_sl_cui_uint8_c(0x04ul), mk_sl_cui_uint8_c(0xf6ul), mk_sl_cui_uint8_c(0xc2ul), mk_sl_cui_uint8_c(0x16ul), mk_sl_cui_uint8_c(0x25ul), mk_sl_cui_uint8_c(0x86ul), mk_sl_cui_uint8_c(0x56ul), mk_sl_cui_uint8_c(0x55ul), mk_sl_cui_uint8_c(0x09ul), mk_sl_cui_uint8_c(0xbeul), mk_sl_cui_uint8_c(0x91ul),
	}}},
}}};

mk_lang_constexpr_static_inline mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq_t const mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq =
{{{
	{{{
		mk_sl_cui_uint32_c(0xbcbc3275ul), mk_sl_cui_uint32_c(0xecec21f3ul), mk_sl_cui_uint32_c(0x202043c6ul), mk_sl_cui_uint32_c(0xb3b3c9f4ul), mk_sl_cui_uint32_c(0xdada03dbul), mk_sl_cui_uint32_c(0x02028b7bul), mk_sl_cui_uint32_c(0xe2e22bfbul), mk_sl_cui_uint32_c(0x9e9efac8ul), mk_sl_cui_uint32_c(0xc9c9ec4aul), mk_sl_cui_uint32_c(0xd4d409d3ul), mk_sl_cui_uint32_c(0x18186be6ul), mk_sl_cui_uint32_c(0x1e1e9f6bul), mk_sl_cui_uint32_c(0x98980e45ul), mk_sl_cui_uint32_c(0xb2b2387dul), mk_sl_cui_uint32_c(0xa6a6d2e8ul), mk_sl_cui_uint32_c(0x2626b74bul),
		mk_sl_cui_uint32_c(0x3c3c57d6ul), mk_sl_cui_uint32_c(0x93938a32ul), mk_sl_cui_uint32_c(0x8282eed8ul), mk_sl_cui_uint32_c(0x525298fdul), mk_sl_cui_uint32_c(0x7b7bd437ul), mk_sl_cui_uint32_c(0xbbbb3771ul), mk_sl_cui_uint32_c(0x5b5b97f1ul), mk_sl_cui_uint32_c(0x474783e1ul), mk_sl_cui_uint32_c(0x24243c30ul), mk_sl_cui_uint32_c(0x5151e20ful), mk_sl_cui_uint32_c(0xbabac6f8ul), mk_sl_cui_uint32_c(0x4a4af31bul), mk_sl_cui_uint32_c(0xbfbf4887ul), mk_sl_cui_uint32_c(0x0d0d70faul), mk_sl_cui_uint32_c(0xb0b0b306ul), mk_sl_cui_uint32_c(0x7575de3ful),
		mk_sl_cui_uint32_c(0xd2d2fd5eul), mk_sl_cui_uint32_c(0x7d7d20baul), mk_sl_cui_uint32_c(0x666631aeul), mk_sl_cui_uint32_c(0x3a3aa35bul), mk_sl_cui_uint32_c(0x59591c8aul), mk_sl_cui_uint32_c(0x00000000ul), mk_sl_cui_uint32_c(0xcdcd93bcul), mk_sl_cui_uint32_c(0x1a1ae09dul), mk_sl_cui_uint32_c(0xaeae2c6dul), mk_sl_cui_uint32_c(0x7f7fabc1ul), mk_sl_cui_uint32_c(0x2b2bc7b1ul), mk_sl_cui_uint32_c(0xbebeb90eul), mk_sl_cui_uint32_c(0xe0e0a080ul), mk_sl_cui_uint32_c(0x8a8a105dul), mk_sl_cui_uint32_c(0x3b3b52d2ul), mk_sl_cui_uint32_c(0x6464bad5ul),
		mk_sl_cui_uint32_c(0xd8d888a0ul), mk_sl_cui_uint32_c(0xe7e7a584ul), mk_sl_cui_uint32_c(0x5f5fe807ul), mk_sl_cui_uint32_c(0x1b1b1114ul), mk_sl_cui_uint32_c(0x2c2cc2b5ul), mk_sl_cui_uint32_c(0xfcfcb490ul), mk_sl_cui_uint32_c(0x3131272cul), mk_sl_cui_uint32_c(0x808065a3ul), mk_sl_cui_uint32_c(0x73732ab2ul), mk_sl_cui_uint32_c(0x0c0c8173ul), mk_sl_cui_uint32_c(0x79795f4cul), mk_sl_cui_uint32_c(0x6b6b4154ul), mk_sl_cui_uint32_c(0x4b4b0292ul), mk_sl_cui_uint32_c(0x53536974ul), mk_sl_cui_uint32_c(0x94948f36ul), mk_sl_cui_uint32_c(0x83831f51ul),
		mk_sl_cui_uint32_c(0x2a2a3638ul), mk_sl_cui_uint32_c(0xc4c49cb0ul), mk_sl_cui_uint32_c(0x2222c8bdul), mk_sl_cui_uint32_c(0xd5d5f85aul), mk_sl_cui_uint32_c(0xbdbdc3fcul), mk_sl_cui_uint32_c(0x48487860ul), mk_sl_cui_uint32_c(0xffffce62ul), mk_sl_cui_uint32_c(0x4c4c0796ul), mk_sl_cui_uint32_c(0x4141776cul), mk_sl_cui_uint32_c(0xc7c7e642ul), mk_sl_cui_uint32_c(0xebeb24f7ul), mk_sl_cui_uint32_c(0x1c1c1410ul), mk_sl_cui_uint32_c(0x5d5d637cul), mk_sl_cui_uint32_c(0x36362228ul), mk_sl_cui_uint32_c(0x6767c027ul), mk_sl_cui_uint32_c(0xe9e9af8cul),
		mk_sl_cui_uint32_c(0x4444f913ul), mk_sl_cui_uint32_c(0x1414ea95ul), mk_sl_cui_uint32_c(0xf5f5bb9cul), mk_sl_cui_uint32_c(0xcfcf18c7ul), mk_sl_cui_uint32_c(0x3f3f2d24ul), mk_sl_cui_uint32_c(0xc0c0e346ul), mk_sl_cui_uint32_c(0x7272db3bul), mk_sl_cui_uint32_c(0x54546c70ul), mk_sl_cui_uint32_c(0x29294ccaul), mk_sl_cui_uint32_c(0xf0f035e3ul), mk_sl_cui_uint32_c(0x0808fe85ul), mk_sl_cui_uint32_c(0xc6c617cbul), mk_sl_cui_uint32_c(0xf3f34f11ul), mk_sl_cui_uint32_c(0x8c8ce4d0ul), mk_sl_cui_uint32_c(0xa4a45993ul), mk_sl_cui_uint32_c(0xcaca96b8ul),
		mk_sl_cui_uint32_c(0x68683ba6ul), mk_sl_cui_uint32_c(0xb8b84d83ul), mk_sl_cui_uint32_c(0x38382820ul), mk_sl_cui_uint32_c(0xe5e52efful), mk_sl_cui_uint32_c(0xadad569ful), mk_sl_cui_uint32_c(0x0b0b8477ul), mk_sl_cui_uint32_c(0xc8c81dc3ul), mk_sl_cui_uint32_c(0x9999ffccul), mk_sl_cui_uint32_c(0x5858ed03ul), mk_sl_cui_uint32_c(0x19199a6ful), mk_sl_cui_uint32_c(0x0e0e0a08ul), mk_sl_cui_uint32_c(0x95957ebful), mk_sl_cui_uint32_c(0x70705040ul), mk_sl_cui_uint32_c(0xf7f730e7ul), mk_sl_cui_uint32_c(0x6e6ecf2bul), mk_sl_cui_uint32_c(0x1f1f6ee2ul),
		mk_sl_cui_uint32_c(0xb5b53d79ul), mk_sl_cui_uint32_c(0x09090f0cul), mk_sl_cui_uint32_c(0x616134aaul), mk_sl_cui_uint32_c(0x57571682ul), mk_sl_cui_uint32_c(0x9f9f0b41ul), mk_sl_cui_uint32_c(0x9d9d803aul), mk_sl_cui_uint32_c(0x111164eaul), mk_sl_cui_uint32_c(0x2525cdb9ul), mk_sl_cui_uint32_c(0xafafdde4ul), mk_sl_cui_uint32_c(0x4545089aul), mk_sl_cui_uint32_c(0xdfdf8da4ul), mk_sl_cui_uint32_c(0xa3a35c97ul), mk_sl_cui_uint32_c(0xeaead57eul), mk_sl_cui_uint32_c(0x353558daul), mk_sl_cui_uint32_c(0xededd07aul), mk_sl_cui_uint32_c(0x4343fc17ul),
		mk_sl_cui_uint32_c(0xf8f8cb66ul), mk_sl_cui_uint32_c(0xfbfbb194ul), mk_sl_cui_uint32_c(0x3737d3a1ul), mk_sl_cui_uint32_c(0xfafa401dul), mk_sl_cui_uint32_c(0xc2c2683dul), mk_sl_cui_uint32_c(0xb4b4ccf0ul), mk_sl_cui_uint32_c(0x32325ddeul), mk_sl_cui_uint32_c(0x9c9c71b3ul), mk_sl_cui_uint32_c(0x5656e70bul), mk_sl_cui_uint32_c(0xe3e3da72ul), mk_sl_cui_uint32_c(0x878760a7ul), mk_sl_cui_uint32_c(0x15151b1cul), mk_sl_cui_uint32_c(0xf9f93aeful), mk_sl_cui_uint32_c(0x6363bfd1ul), mk_sl_cui_uint32_c(0x3434a953ul), mk_sl_cui_uint32_c(0x9a9a853eul),
		mk_sl_cui_uint32_c(0xb1b1428ful), mk_sl_cui_uint32_c(0x7c7cd133ul), mk_sl_cui_uint32_c(0x88889b26ul), mk_sl_cui_uint32_c(0x3d3da65ful), mk_sl_cui_uint32_c(0xa1a1d7ecul), mk_sl_cui_uint32_c(0xe4e4df76ul), mk_sl_cui_uint32_c(0x8181942aul), mk_sl_cui_uint32_c(0x91910149ul), mk_sl_cui_uint32_c(0x0f0ffb81ul), mk_sl_cui_uint32_c(0xeeeeaa88ul), mk_sl_cui_uint32_c(0x161661eeul), mk_sl_cui_uint32_c(0xd7d77321ul), mk_sl_cui_uint32_c(0x9797f5c4ul), mk_sl_cui_uint32_c(0xa5a5a81aul), mk_sl_cui_uint32_c(0xfefe3febul), mk_sl_cui_uint32_c(0x6d6db5d9ul),
		mk_sl_cui_uint32_c(0x7878aec5ul), mk_sl_cui_uint32_c(0xc5c56d39ul), mk_sl_cui_uint32_c(0x1d1de599ul), mk_sl_cui_uint32_c(0x7676a4cdul), mk_sl_cui_uint32_c(0x3e3edcadul), mk_sl_cui_uint32_c(0xcbcb6731ul), mk_sl_cui_uint32_c(0xb6b6478bul), mk_sl_cui_uint32_c(0xefef5b01ul), mk_sl_cui_uint32_c(0x12121e18ul), mk_sl_cui_uint32_c(0x6060c523ul), mk_sl_cui_uint32_c(0x6a6ab0ddul), mk_sl_cui_uint32_c(0x4d4df61ful), mk_sl_cui_uint32_c(0xcecee94eul), mk_sl_cui_uint32_c(0xdede7c2dul), mk_sl_cui_uint32_c(0x55559df9ul), mk_sl_cui_uint32_c(0x7e7e5a48ul),
		mk_sl_cui_uint32_c(0x2121b24ful), mk_sl_cui_uint32_c(0x03037af2ul), mk_sl_cui_uint32_c(0xa0a02665ul), mk_sl_cui_uint32_c(0x5e5e198eul), mk_sl_cui_uint32_c(0x5a5a6678ul), mk_sl_cui_uint32_c(0x65654b5cul), mk_sl_cui_uint32_c(0x62624e58ul), mk_sl_cui_uint32_c(0xfdfd4519ul), mk_sl_cui_uint32_c(0x0606f48dul), mk_sl_cui_uint32_c(0x404086e5ul), mk_sl_cui_uint32_c(0xf2f2be98ul), mk_sl_cui_uint32_c(0x3333ac57ul), mk_sl_cui_uint32_c(0x17179067ul), mk_sl_cui_uint32_c(0x05058e7ful), mk_sl_cui_uint32_c(0xe8e85e05ul), mk_sl_cui_uint32_c(0x4f4f7d64ul),
		mk_sl_cui_uint32_c(0x89896aaful), mk_sl_cui_uint32_c(0x10109563ul), mk_sl_cui_uint32_c(0x74742fb6ul), mk_sl_cui_uint32_c(0x0a0a75feul), mk_sl_cui_uint32_c(0x5c5c92f5ul), mk_sl_cui_uint32_c(0x9b9b74b7ul), mk_sl_cui_uint32_c(0x2d2d333cul), mk_sl_cui_uint32_c(0x3030d6a5ul), mk_sl_cui_uint32_c(0x2e2e49ceul), mk_sl_cui_uint32_c(0x494989e9ul), mk_sl_cui_uint32_c(0x46467268ul), mk_sl_cui_uint32_c(0x77775544ul), mk_sl_cui_uint32_c(0xa8a8d8e0ul), mk_sl_cui_uint32_c(0x9696044dul), mk_sl_cui_uint32_c(0x2828bd43ul), mk_sl_cui_uint32_c(0xa9a92969ul),
		mk_sl_cui_uint32_c(0xd9d97929ul), mk_sl_cui_uint32_c(0x8686912eul), mk_sl_cui_uint32_c(0xd1d187acul), mk_sl_cui_uint32_c(0xf4f44a15ul), mk_sl_cui_uint32_c(0x8d8d1559ul), mk_sl_cui_uint32_c(0xd6d682a8ul), mk_sl_cui_uint32_c(0xb9b9bc0aul), mk_sl_cui_uint32_c(0x42420d9eul), mk_sl_cui_uint32_c(0xf6f6c16eul), mk_sl_cui_uint32_c(0x2f2fb847ul), mk_sl_cui_uint32_c(0xdddd06dful), mk_sl_cui_uint32_c(0x23233934ul), mk_sl_cui_uint32_c(0xcccc6235ul), mk_sl_cui_uint32_c(0xf1f1c46aul), mk_sl_cui_uint32_c(0xc1c112cful), mk_sl_cui_uint32_c(0x8585ebdcul),
		mk_sl_cui_uint32_c(0x8f8f9e22ul), mk_sl_cui_uint32_c(0x7171a1c9ul), mk_sl_cui_uint32_c(0x9090f0c0ul), mk_sl_cui_uint32_c(0xaaaa539bul), mk_sl_cui_uint32_c(0x0101f189ul), mk_sl_cui_uint32_c(0x8b8be1d4ul), mk_sl_cui_uint32_c(0x4e4e8cedul), mk_sl_cui_uint32_c(0x8e8e6fabul), mk_sl_cui_uint32_c(0xababa212ul), mk_sl_cui_uint32_c(0x6f6f3ea2ul), mk_sl_cui_uint32_c(0xe6e6540dul), mk_sl_cui_uint32_c(0xdbdbf252ul), mk_sl_cui_uint32_c(0x92927bbbul), mk_sl_cui_uint32_c(0xb7b7b602ul), mk_sl_cui_uint32_c(0x6969ca2ful), mk_sl_cui_uint32_c(0x3939d9a9ul),
		mk_sl_cui_uint32_c(0xd3d30cd7ul), mk_sl_cui_uint32_c(0xa7a72361ul), mk_sl_cui_uint32_c(0xa2a2ad1eul), mk_sl_cui_uint32_c(0xc3c399b4ul), mk_sl_cui_uint32_c(0x6c6c4450ul), mk_sl_cui_uint32_c(0x07070504ul), mk_sl_cui_uint32_c(0x04047ff6ul), mk_sl_cui_uint32_c(0x272746c2ul), mk_sl_cui_uint32_c(0xacaca716ul), mk_sl_cui_uint32_c(0xd0d07625ul), mk_sl_cui_uint32_c(0x50501386ul), mk_sl_cui_uint32_c(0xdcdcf756ul), mk_sl_cui_uint32_c(0x84841a55ul), mk_sl_cui_uint32_c(0xe1e15109ul), mk_sl_cui_uint32_c(0x7a7a25beul), mk_sl_cui_uint32_c(0x1313ef91ul),
	}}},
	{{{
			mk_sl_cui_uint32_c(0xa9d93939ul), mk_sl_cui_uint32_c(0x67901717ul), mk_sl_cui_uint32_c(0xb3719c9cul), mk_sl_cui_uint32_c(0xe8d2a6a6ul), mk_sl_cui_uint32_c(0x04050707ul), mk_sl_cui_uint32_c(0xfd985252ul), mk_sl_cui_uint32_c(0xa3658080ul), mk_sl_cui_uint32_c(0x76dfe4e4ul), mk_sl_cui_uint32_c(0x9a084545ul), mk_sl_cui_uint32_c(0x92024b4bul), mk_sl_cui_uint32_c(0x80a0e0e0ul), mk_sl_cui_uint32_c(0x78665a5aul), mk_sl_cui_uint32_c(0xe4ddafaful), mk_sl_cui_uint32_c(0xddb06a6aul), mk_sl_cui_uint32_c(0xd1bf6363ul), mk_sl_cui_uint32_c(0x38362a2aul),
			mk_sl_cui_uint32_c(0x0d54e6e6ul), mk_sl_cui_uint32_c(0xc6432020ul), mk_sl_cui_uint32_c(0x3562ccccul), mk_sl_cui_uint32_c(0x98bef2f2ul), mk_sl_cui_uint32_c(0x181e1212ul), mk_sl_cui_uint32_c(0xf724ebebul), mk_sl_cui_uint32_c(0xecd7a1a1ul), mk_sl_cui_uint32_c(0x6c774141ul), mk_sl_cui_uint32_c(0x43bd2828ul), mk_sl_cui_uint32_c(0x7532bcbcul), mk_sl_cui_uint32_c(0x37d47b7bul), mk_sl_cui_uint32_c(0x269b8888ul), mk_sl_cui_uint32_c(0xfa700d0dul), mk_sl_cui_uint32_c(0x13f94444ul), mk_sl_cui_uint32_c(0x94b1fbfbul), mk_sl_cui_uint32_c(0x485a7e7eul),
			mk_sl_cui_uint32_c(0xf27a0303ul), mk_sl_cui_uint32_c(0xd0e48c8cul), mk_sl_cui_uint32_c(0x8b47b6b6ul), mk_sl_cui_uint32_c(0x303c2424ul), mk_sl_cui_uint32_c(0x84a5e7e7ul), mk_sl_cui_uint32_c(0x54416b6bul), mk_sl_cui_uint32_c(0xdf06ddddul), mk_sl_cui_uint32_c(0x23c56060ul), mk_sl_cui_uint32_c(0x1945fdfdul), mk_sl_cui_uint32_c(0x5ba33a3aul), mk_sl_cui_uint32_c(0x3d68c2c2ul), mk_sl_cui_uint32_c(0x59158d8dul), mk_sl_cui_uint32_c(0xf321ececul), mk_sl_cui_uint32_c(0xae316666ul), mk_sl_cui_uint32_c(0xa23e6f6ful), mk_sl_cui_uint32_c(0x82165757ul),
			mk_sl_cui_uint32_c(0x63951010ul), mk_sl_cui_uint32_c(0x015befeful), mk_sl_cui_uint32_c(0x834db8b8ul), mk_sl_cui_uint32_c(0x2e918686ul), mk_sl_cui_uint32_c(0xd9b56d6dul), mk_sl_cui_uint32_c(0x511f8383ul), mk_sl_cui_uint32_c(0x9b53aaaaul), mk_sl_cui_uint32_c(0x7c635d5dul), mk_sl_cui_uint32_c(0xa63b6868ul), mk_sl_cui_uint32_c(0xeb3ffefeul), mk_sl_cui_uint32_c(0xa5d63030ul), mk_sl_cui_uint32_c(0xbe257a7aul), mk_sl_cui_uint32_c(0x16a7acacul), mk_sl_cui_uint32_c(0x0c0f0909ul), mk_sl_cui_uint32_c(0xe335f0f0ul), mk_sl_cui_uint32_c(0x6123a7a7ul),
			mk_sl_cui_uint32_c(0xc0f09090ul), mk_sl_cui_uint32_c(0x8cafe9e9ul), mk_sl_cui_uint32_c(0x3a809d9dul), mk_sl_cui_uint32_c(0xf5925c5cul), mk_sl_cui_uint32_c(0x73810c0cul), mk_sl_cui_uint32_c(0x2c273131ul), mk_sl_cui_uint32_c(0x2576d0d0ul), mk_sl_cui_uint32_c(0x0be75656ul), mk_sl_cui_uint32_c(0xbb7b9292ul), mk_sl_cui_uint32_c(0x4ee9ceceul), mk_sl_cui_uint32_c(0x89f10101ul), mk_sl_cui_uint32_c(0x6b9f1e1eul), mk_sl_cui_uint32_c(0x53a93434ul), mk_sl_cui_uint32_c(0x6ac4f1f1ul), mk_sl_cui_uint32_c(0xb499c3c3ul), mk_sl_cui_uint32_c(0xf1975b5bul),
			mk_sl_cui_uint32_c(0xe1834747ul), mk_sl_cui_uint32_c(0xe66b1818ul), mk_sl_cui_uint32_c(0xbdc82222ul), mk_sl_cui_uint32_c(0x450e9898ul), mk_sl_cui_uint32_c(0xe26e1f1ful), mk_sl_cui_uint32_c(0xf4c9b3b3ul), mk_sl_cui_uint32_c(0xb62f7474ul), mk_sl_cui_uint32_c(0x66cbf8f8ul), mk_sl_cui_uint32_c(0xccff9999ul), mk_sl_cui_uint32_c(0x95ea1414ul), mk_sl_cui_uint32_c(0x03ed5858ul), mk_sl_cui_uint32_c(0x56f7dcdcul), mk_sl_cui_uint32_c(0xd4e18b8bul), mk_sl_cui_uint32_c(0x1c1b1515ul), mk_sl_cui_uint32_c(0x1eada2a2ul), mk_sl_cui_uint32_c(0xd70cd3d3ul),
			mk_sl_cui_uint32_c(0xfb2be2e2ul), mk_sl_cui_uint32_c(0xc31dc8c8ul), mk_sl_cui_uint32_c(0x8e195e5eul), mk_sl_cui_uint32_c(0xb5c22c2cul), mk_sl_cui_uint32_c(0xe9894949ul), mk_sl_cui_uint32_c(0xcf12c1c1ul), mk_sl_cui_uint32_c(0xbf7e9595ul), mk_sl_cui_uint32_c(0xba207d7dul), mk_sl_cui_uint32_c(0xea641111ul), mk_sl_cui_uint32_c(0x77840b0bul), mk_sl_cui_uint32_c(0x396dc5c5ul), mk_sl_cui_uint32_c(0xaf6a8989ul), mk_sl_cui_uint32_c(0x33d17c7cul), mk_sl_cui_uint32_c(0xc9a17171ul), mk_sl_cui_uint32_c(0x62cefffful), mk_sl_cui_uint32_c(0x7137bbbbul),
			mk_sl_cui_uint32_c(0x81fb0f0ful), mk_sl_cui_uint32_c(0x793db5b5ul), mk_sl_cui_uint32_c(0x0951e1e1ul), mk_sl_cui_uint32_c(0xaddc3e3eul), mk_sl_cui_uint32_c(0x242d3f3ful), mk_sl_cui_uint32_c(0xcda47676ul), mk_sl_cui_uint32_c(0xf99d5555ul), mk_sl_cui_uint32_c(0xd8ee8282ul), mk_sl_cui_uint32_c(0xe5864040ul), mk_sl_cui_uint32_c(0xc5ae7878ul), mk_sl_cui_uint32_c(0xb9cd2525ul), mk_sl_cui_uint32_c(0x4d049696ul), mk_sl_cui_uint32_c(0x44557777ul), mk_sl_cui_uint32_c(0x080a0e0eul), mk_sl_cui_uint32_c(0x86135050ul), mk_sl_cui_uint32_c(0xe730f7f7ul),
			mk_sl_cui_uint32_c(0xa1d33737ul), mk_sl_cui_uint32_c(0x1d40fafaul), mk_sl_cui_uint32_c(0xaa346161ul), mk_sl_cui_uint32_c(0xed8c4e4eul), mk_sl_cui_uint32_c(0x06b3b0b0ul), mk_sl_cui_uint32_c(0x706c5454ul), mk_sl_cui_uint32_c(0xb22a7373ul), mk_sl_cui_uint32_c(0xd2523b3bul), mk_sl_cui_uint32_c(0x410b9f9ful), mk_sl_cui_uint32_c(0x7b8b0202ul), mk_sl_cui_uint32_c(0xa088d8d8ul), mk_sl_cui_uint32_c(0x114ff3f3ul), mk_sl_cui_uint32_c(0x3167cbcbul), mk_sl_cui_uint32_c(0xc2462727ul), mk_sl_cui_uint32_c(0x27c06767ul), mk_sl_cui_uint32_c(0x90b4fcfcul),
			mk_sl_cui_uint32_c(0x20283838ul), mk_sl_cui_uint32_c(0xf67f0404ul), mk_sl_cui_uint32_c(0x60784848ul), mk_sl_cui_uint32_c(0xff2ee5e5ul), mk_sl_cui_uint32_c(0x96074c4cul), mk_sl_cui_uint32_c(0x5c4b6565ul), mk_sl_cui_uint32_c(0xb1c72b2bul), mk_sl_cui_uint32_c(0xab6f8e8eul), mk_sl_cui_uint32_c(0x9e0d4242ul), mk_sl_cui_uint32_c(0x9cbbf5f5ul), mk_sl_cui_uint32_c(0x52f2dbdbul), mk_sl_cui_uint32_c(0x1bf34a4aul), mk_sl_cui_uint32_c(0x5fa63d3dul), mk_sl_cui_uint32_c(0x9359a4a4ul), mk_sl_cui_uint32_c(0x0abcb9b9ul), mk_sl_cui_uint32_c(0xef3af9f9ul),
			mk_sl_cui_uint32_c(0x91ef1313ul), mk_sl_cui_uint32_c(0x85fe0808ul), mk_sl_cui_uint32_c(0x49019191ul), mk_sl_cui_uint32_c(0xee611616ul), mk_sl_cui_uint32_c(0x2d7cdedeul), mk_sl_cui_uint32_c(0x4fb22121ul), mk_sl_cui_uint32_c(0x8f42b1b1ul), mk_sl_cui_uint32_c(0x3bdb7272ul), mk_sl_cui_uint32_c(0x47b82f2ful), mk_sl_cui_uint32_c(0x8748bfbful), mk_sl_cui_uint32_c(0x6d2caeaeul), mk_sl_cui_uint32_c(0x46e3c0c0ul), mk_sl_cui_uint32_c(0xd6573c3cul), mk_sl_cui_uint32_c(0x3e859a9aul), mk_sl_cui_uint32_c(0x6929a9a9ul), mk_sl_cui_uint32_c(0x647d4f4ful),
			mk_sl_cui_uint32_c(0x2a948181ul), mk_sl_cui_uint32_c(0xce492e2eul), mk_sl_cui_uint32_c(0xcb17c6c6ul), mk_sl_cui_uint32_c(0x2fca6969ul), mk_sl_cui_uint32_c(0xfcc3bdbdul), mk_sl_cui_uint32_c(0x975ca3a3ul), mk_sl_cui_uint32_c(0x055ee8e8ul), mk_sl_cui_uint32_c(0x7ad0ededul), mk_sl_cui_uint32_c(0xac87d1d1ul), mk_sl_cui_uint32_c(0x7f8e0505ul), mk_sl_cui_uint32_c(0xd5ba6464ul), mk_sl_cui_uint32_c(0x1aa8a5a5ul), mk_sl_cui_uint32_c(0x4bb72626ul), mk_sl_cui_uint32_c(0x0eb9bebeul), mk_sl_cui_uint32_c(0xa7608787ul), mk_sl_cui_uint32_c(0x5af8d5d5ul),
			mk_sl_cui_uint32_c(0x28223636ul), mk_sl_cui_uint32_c(0x14111b1bul), mk_sl_cui_uint32_c(0x3fde7575ul), mk_sl_cui_uint32_c(0x2979d9d9ul), mk_sl_cui_uint32_c(0x88aaeeeeul), mk_sl_cui_uint32_c(0x3c332d2dul), mk_sl_cui_uint32_c(0x4c5f7979ul), mk_sl_cui_uint32_c(0x02b6b7b7ul), mk_sl_cui_uint32_c(0xb896cacaul), mk_sl_cui_uint32_c(0xda583535ul), mk_sl_cui_uint32_c(0xb09cc4c4ul), mk_sl_cui_uint32_c(0x17fc4343ul), mk_sl_cui_uint32_c(0x551a8484ul), mk_sl_cui_uint32_c(0x1ff64d4dul), mk_sl_cui_uint32_c(0x8a1c5959ul), mk_sl_cui_uint32_c(0x7d38b2b2ul),
			mk_sl_cui_uint32_c(0x57ac3333ul), mk_sl_cui_uint32_c(0xc718cfcful), mk_sl_cui_uint32_c(0x8df40606ul), mk_sl_cui_uint32_c(0x74695353ul), mk_sl_cui_uint32_c(0xb7749b9bul), mk_sl_cui_uint32_c(0xc4f59797ul), mk_sl_cui_uint32_c(0x9f56adadul), mk_sl_cui_uint32_c(0x72dae3e3ul), mk_sl_cui_uint32_c(0x7ed5eaeaul), mk_sl_cui_uint32_c(0x154af4f4ul), mk_sl_cui_uint32_c(0x229e8f8ful), mk_sl_cui_uint32_c(0x12a2ababul), mk_sl_cui_uint32_c(0x584e6262ul), mk_sl_cui_uint32_c(0x07e85f5ful), mk_sl_cui_uint32_c(0x99e51d1dul), mk_sl_cui_uint32_c(0x34392323ul),
			mk_sl_cui_uint32_c(0x6ec1f6f6ul), mk_sl_cui_uint32_c(0x50446c6cul), mk_sl_cui_uint32_c(0xde5d3232ul), mk_sl_cui_uint32_c(0x68724646ul), mk_sl_cui_uint32_c(0x6526a0a0ul), mk_sl_cui_uint32_c(0xbc93cdcdul), mk_sl_cui_uint32_c(0xdb03dadaul), mk_sl_cui_uint32_c(0xf8c6babaul), mk_sl_cui_uint32_c(0xc8fa9e9eul), mk_sl_cui_uint32_c(0xa882d6d6ul), mk_sl_cui_uint32_c(0x2bcf6e6eul), mk_sl_cui_uint32_c(0x40507070ul), mk_sl_cui_uint32_c(0xdceb8585ul), mk_sl_cui_uint32_c(0xfe750a0aul), mk_sl_cui_uint32_c(0x328a9393ul), mk_sl_cui_uint32_c(0xa48ddfdful),
			mk_sl_cui_uint32_c(0xca4c2929ul), mk_sl_cui_uint32_c(0x10141c1cul), mk_sl_cui_uint32_c(0x2173d7d7ul), mk_sl_cui_uint32_c(0xf0ccb4b4ul), mk_sl_cui_uint32_c(0xd309d4d4ul), mk_sl_cui_uint32_c(0x5d108a8aul), mk_sl_cui_uint32_c(0x0fe25151ul), mk_sl_cui_uint32_c(0x00000000ul), mk_sl_cui_uint32_c(0x6f9a1919ul), mk_sl_cui_uint32_c(0x9de01a1aul), mk_sl_cui_uint32_c(0x368f9494ul), mk_sl_cui_uint32_c(0x42e6c7c7ul), mk_sl_cui_uint32_c(0x4aecc9c9ul), mk_sl_cui_uint32_c(0x5efdd2d2ul), mk_sl_cui_uint32_c(0xc1ab7f7ful), mk_sl_cui_uint32_c(0xe0d8a8a8ul),
	}}},
	{{{
			mk_sl_cui_uint32_c(0xbc75bc32ul), mk_sl_cui_uint32_c(0xecf3ec21ul), mk_sl_cui_uint32_c(0x20c62043ul), mk_sl_cui_uint32_c(0xb3f4b3c9ul), mk_sl_cui_uint32_c(0xdadbda03ul), mk_sl_cui_uint32_c(0x027b028bul), mk_sl_cui_uint32_c(0xe2fbe22bul), mk_sl_cui_uint32_c(0x9ec89efaul), mk_sl_cui_uint32_c(0xc94ac9ecul), mk_sl_cui_uint32_c(0xd4d3d409ul), mk_sl_cui_uint32_c(0x18e6186bul), mk_sl_cui_uint32_c(0x1e6b1e9ful), mk_sl_cui_uint32_c(0x9845980eul), mk_sl_cui_uint32_c(0xb27db238ul), mk_sl_cui_uint32_c(0xa6e8a6d2ul), mk_sl_cui_uint32_c(0x264b26b7ul),
			mk_sl_cui_uint32_c(0x3cd63c57ul), mk_sl_cui_uint32_c(0x9332938aul), mk_sl_cui_uint32_c(0x82d882eeul), mk_sl_cui_uint32_c(0x52fd5298ul), mk_sl_cui_uint32_c(0x7b377bd4ul), mk_sl_cui_uint32_c(0xbb71bb37ul), mk_sl_cui_uint32_c(0x5bf15b97ul), mk_sl_cui_uint32_c(0x47e14783ul), mk_sl_cui_uint32_c(0x2430243cul), mk_sl_cui_uint32_c(0x510f51e2ul), mk_sl_cui_uint32_c(0xbaf8bac6ul), mk_sl_cui_uint32_c(0x4a1b4af3ul), mk_sl_cui_uint32_c(0xbf87bf48ul), mk_sl_cui_uint32_c(0x0dfa0d70ul), mk_sl_cui_uint32_c(0xb006b0b3ul), mk_sl_cui_uint32_c(0x753f75deul),
			mk_sl_cui_uint32_c(0xd25ed2fdul), mk_sl_cui_uint32_c(0x7dba7d20ul), mk_sl_cui_uint32_c(0x66ae6631ul), mk_sl_cui_uint32_c(0x3a5b3aa3ul), mk_sl_cui_uint32_c(0x598a591cul), mk_sl_cui_uint32_c(0x00000000ul), mk_sl_cui_uint32_c(0xcdbccd93ul), mk_sl_cui_uint32_c(0x1a9d1ae0ul), mk_sl_cui_uint32_c(0xae6dae2cul), mk_sl_cui_uint32_c(0x7fc17fabul), mk_sl_cui_uint32_c(0x2bb12bc7ul), mk_sl_cui_uint32_c(0xbe0ebeb9ul), mk_sl_cui_uint32_c(0xe080e0a0ul), mk_sl_cui_uint32_c(0x8a5d8a10ul), mk_sl_cui_uint32_c(0x3bd23b52ul), mk_sl_cui_uint32_c(0x64d564baul),
			mk_sl_cui_uint32_c(0xd8a0d888ul), mk_sl_cui_uint32_c(0xe784e7a5ul), mk_sl_cui_uint32_c(0x5f075fe8ul), mk_sl_cui_uint32_c(0x1b141b11ul), mk_sl_cui_uint32_c(0x2cb52cc2ul), mk_sl_cui_uint32_c(0xfc90fcb4ul), mk_sl_cui_uint32_c(0x312c3127ul), mk_sl_cui_uint32_c(0x80a38065ul), mk_sl_cui_uint32_c(0x73b2732aul), mk_sl_cui_uint32_c(0x0c730c81ul), mk_sl_cui_uint32_c(0x794c795ful), mk_sl_cui_uint32_c(0x6b546b41ul), mk_sl_cui_uint32_c(0x4b924b02ul), mk_sl_cui_uint32_c(0x53745369ul), mk_sl_cui_uint32_c(0x9436948ful), mk_sl_cui_uint32_c(0x8351831ful),
			mk_sl_cui_uint32_c(0x2a382a36ul), mk_sl_cui_uint32_c(0xc4b0c49cul), mk_sl_cui_uint32_c(0x22bd22c8ul), mk_sl_cui_uint32_c(0xd55ad5f8ul), mk_sl_cui_uint32_c(0xbdfcbdc3ul), mk_sl_cui_uint32_c(0x48604878ul), mk_sl_cui_uint32_c(0xff62ffceul), mk_sl_cui_uint32_c(0x4c964c07ul), mk_sl_cui_uint32_c(0x416c4177ul), mk_sl_cui_uint32_c(0xc742c7e6ul), mk_sl_cui_uint32_c(0xebf7eb24ul), mk_sl_cui_uint32_c(0x1c101c14ul), mk_sl_cui_uint32_c(0x5d7c5d63ul), mk_sl_cui_uint32_c(0x36283622ul), mk_sl_cui_uint32_c(0x672767c0ul), mk_sl_cui_uint32_c(0xe98ce9aful),
			mk_sl_cui_uint32_c(0x441344f9ul), mk_sl_cui_uint32_c(0x149514eaul), mk_sl_cui_uint32_c(0xf59cf5bbul), mk_sl_cui_uint32_c(0xcfc7cf18ul), mk_sl_cui_uint32_c(0x3f243f2dul), mk_sl_cui_uint32_c(0xc046c0e3ul), mk_sl_cui_uint32_c(0x723b72dbul), mk_sl_cui_uint32_c(0x5470546cul), mk_sl_cui_uint32_c(0x29ca294cul), mk_sl_cui_uint32_c(0xf0e3f035ul), mk_sl_cui_uint32_c(0x088508feul), mk_sl_cui_uint32_c(0xc6cbc617ul), mk_sl_cui_uint32_c(0xf311f34ful), mk_sl_cui_uint32_c(0x8cd08ce4ul), mk_sl_cui_uint32_c(0xa493a459ul), mk_sl_cui_uint32_c(0xcab8ca96ul),
			mk_sl_cui_uint32_c(0x68a6683bul), mk_sl_cui_uint32_c(0xb883b84dul), mk_sl_cui_uint32_c(0x38203828ul), mk_sl_cui_uint32_c(0xe5ffe52eul), mk_sl_cui_uint32_c(0xad9fad56ul), mk_sl_cui_uint32_c(0x0b770b84ul), mk_sl_cui_uint32_c(0xc8c3c81dul), mk_sl_cui_uint32_c(0x99cc99fful), mk_sl_cui_uint32_c(0x580358edul), mk_sl_cui_uint32_c(0x196f199aul), mk_sl_cui_uint32_c(0x0e080e0aul), mk_sl_cui_uint32_c(0x95bf957eul), mk_sl_cui_uint32_c(0x70407050ul), mk_sl_cui_uint32_c(0xf7e7f730ul), mk_sl_cui_uint32_c(0x6e2b6ecful), mk_sl_cui_uint32_c(0x1fe21f6eul),
			mk_sl_cui_uint32_c(0xb579b53dul), mk_sl_cui_uint32_c(0x090c090ful), mk_sl_cui_uint32_c(0x61aa6134ul), mk_sl_cui_uint32_c(0x57825716ul), mk_sl_cui_uint32_c(0x9f419f0bul), mk_sl_cui_uint32_c(0x9d3a9d80ul), mk_sl_cui_uint32_c(0x11ea1164ul), mk_sl_cui_uint32_c(0x25b925cdul), mk_sl_cui_uint32_c(0xafe4afddul), mk_sl_cui_uint32_c(0x459a4508ul), mk_sl_cui_uint32_c(0xdfa4df8dul), mk_sl_cui_uint32_c(0xa397a35cul), mk_sl_cui_uint32_c(0xea7eead5ul), mk_sl_cui_uint32_c(0x35da3558ul), mk_sl_cui_uint32_c(0xed7aedd0ul), mk_sl_cui_uint32_c(0x431743fcul),
			mk_sl_cui_uint32_c(0xf866f8cbul), mk_sl_cui_uint32_c(0xfb94fbb1ul), mk_sl_cui_uint32_c(0x37a137d3ul), mk_sl_cui_uint32_c(0xfa1dfa40ul), mk_sl_cui_uint32_c(0xc23dc268ul), mk_sl_cui_uint32_c(0xb4f0b4ccul), mk_sl_cui_uint32_c(0x32de325dul), mk_sl_cui_uint32_c(0x9cb39c71ul), mk_sl_cui_uint32_c(0x560b56e7ul), mk_sl_cui_uint32_c(0xe372e3daul), mk_sl_cui_uint32_c(0x87a78760ul), mk_sl_cui_uint32_c(0x151c151bul), mk_sl_cui_uint32_c(0xf9eff93aul), mk_sl_cui_uint32_c(0x63d163bful), mk_sl_cui_uint32_c(0x345334a9ul), mk_sl_cui_uint32_c(0x9a3e9a85ul),
			mk_sl_cui_uint32_c(0xb18fb142ul), mk_sl_cui_uint32_c(0x7c337cd1ul), mk_sl_cui_uint32_c(0x8826889bul), mk_sl_cui_uint32_c(0x3d5f3da6ul), mk_sl_cui_uint32_c(0xa1eca1d7ul), mk_sl_cui_uint32_c(0xe476e4dful), mk_sl_cui_uint32_c(0x812a8194ul), mk_sl_cui_uint32_c(0x91499101ul), mk_sl_cui_uint32_c(0x0f810ffbul), mk_sl_cui_uint32_c(0xee88eeaaul), mk_sl_cui_uint32_c(0x16ee1661ul), mk_sl_cui_uint32_c(0xd721d773ul), mk_sl_cui_uint32_c(0x97c497f5ul), mk_sl_cui_uint32_c(0xa51aa5a8ul), mk_sl_cui_uint32_c(0xfeebfe3ful), mk_sl_cui_uint32_c(0x6dd96db5ul),
			mk_sl_cui_uint32_c(0x78c578aeul), mk_sl_cui_uint32_c(0xc539c56dul), mk_sl_cui_uint32_c(0x1d991de5ul), mk_sl_cui_uint32_c(0x76cd76a4ul), mk_sl_cui_uint32_c(0x3ead3edcul), mk_sl_cui_uint32_c(0xcb31cb67ul), mk_sl_cui_uint32_c(0xb68bb647ul), mk_sl_cui_uint32_c(0xef01ef5bul), mk_sl_cui_uint32_c(0x1218121eul), mk_sl_cui_uint32_c(0x602360c5ul), mk_sl_cui_uint32_c(0x6add6ab0ul), mk_sl_cui_uint32_c(0x4d1f4df6ul), mk_sl_cui_uint32_c(0xce4ecee9ul), mk_sl_cui_uint32_c(0xde2dde7cul), mk_sl_cui_uint32_c(0x55f9559dul), mk_sl_cui_uint32_c(0x7e487e5aul),
			mk_sl_cui_uint32_c(0x214f21b2ul), mk_sl_cui_uint32_c(0x03f2037aul), mk_sl_cui_uint32_c(0xa065a026ul), mk_sl_cui_uint32_c(0x5e8e5e19ul), mk_sl_cui_uint32_c(0x5a785a66ul), mk_sl_cui_uint32_c(0x655c654bul), mk_sl_cui_uint32_c(0x6258624eul), mk_sl_cui_uint32_c(0xfd19fd45ul), mk_sl_cui_uint32_c(0x068d06f4ul), mk_sl_cui_uint32_c(0x40e54086ul), mk_sl_cui_uint32_c(0xf298f2beul), mk_sl_cui_uint32_c(0x335733acul), mk_sl_cui_uint32_c(0x17671790ul), mk_sl_cui_uint32_c(0x057f058eul), mk_sl_cui_uint32_c(0xe805e85eul), mk_sl_cui_uint32_c(0x4f644f7dul),
			mk_sl_cui_uint32_c(0x89af896aul), mk_sl_cui_uint32_c(0x10631095ul), mk_sl_cui_uint32_c(0x74b6742ful), mk_sl_cui_uint32_c(0x0afe0a75ul), mk_sl_cui_uint32_c(0x5cf55c92ul), mk_sl_cui_uint32_c(0x9bb79b74ul), mk_sl_cui_uint32_c(0x2d3c2d33ul), mk_sl_cui_uint32_c(0x30a530d6ul), mk_sl_cui_uint32_c(0x2ece2e49ul), mk_sl_cui_uint32_c(0x49e94989ul), mk_sl_cui_uint32_c(0x46684672ul), mk_sl_cui_uint32_c(0x77447755ul), mk_sl_cui_uint32_c(0xa8e0a8d8ul), mk_sl_cui_uint32_c(0x964d9604ul), mk_sl_cui_uint32_c(0x284328bdul), mk_sl_cui_uint32_c(0xa969a929ul),
			mk_sl_cui_uint32_c(0xd929d979ul), mk_sl_cui_uint32_c(0x862e8691ul), mk_sl_cui_uint32_c(0xd1acd187ul), mk_sl_cui_uint32_c(0xf415f44aul), mk_sl_cui_uint32_c(0x8d598d15ul), mk_sl_cui_uint32_c(0xd6a8d682ul), mk_sl_cui_uint32_c(0xb90ab9bcul), mk_sl_cui_uint32_c(0x429e420dul), mk_sl_cui_uint32_c(0xf66ef6c1ul), mk_sl_cui_uint32_c(0x2f472fb8ul), mk_sl_cui_uint32_c(0xdddfdd06ul), mk_sl_cui_uint32_c(0x23342339ul), mk_sl_cui_uint32_c(0xcc35cc62ul), mk_sl_cui_uint32_c(0xf16af1c4ul), mk_sl_cui_uint32_c(0xc1cfc112ul), mk_sl_cui_uint32_c(0x85dc85ebul),
			mk_sl_cui_uint32_c(0x8f228f9eul), mk_sl_cui_uint32_c(0x71c971a1ul), mk_sl_cui_uint32_c(0x90c090f0ul), mk_sl_cui_uint32_c(0xaa9baa53ul), mk_sl_cui_uint32_c(0x018901f1ul), mk_sl_cui_uint32_c(0x8bd48be1ul), mk_sl_cui_uint32_c(0x4eed4e8cul), mk_sl_cui_uint32_c(0x8eab8e6ful), mk_sl_cui_uint32_c(0xab12aba2ul), mk_sl_cui_uint32_c(0x6fa26f3eul), mk_sl_cui_uint32_c(0xe60de654ul), mk_sl_cui_uint32_c(0xdb52dbf2ul), mk_sl_cui_uint32_c(0x92bb927bul), mk_sl_cui_uint32_c(0xb702b7b6ul), mk_sl_cui_uint32_c(0x692f69caul), mk_sl_cui_uint32_c(0x39a939d9ul),
			mk_sl_cui_uint32_c(0xd3d7d30cul), mk_sl_cui_uint32_c(0xa761a723ul), mk_sl_cui_uint32_c(0xa21ea2adul), mk_sl_cui_uint32_c(0xc3b4c399ul), mk_sl_cui_uint32_c(0x6c506c44ul), mk_sl_cui_uint32_c(0x07040705ul), mk_sl_cui_uint32_c(0x04f6047ful), mk_sl_cui_uint32_c(0x27c22746ul), mk_sl_cui_uint32_c(0xac16aca7ul), mk_sl_cui_uint32_c(0xd025d076ul), mk_sl_cui_uint32_c(0x50865013ul), mk_sl_cui_uint32_c(0xdc56dcf7ul), mk_sl_cui_uint32_c(0x8455841aul), mk_sl_cui_uint32_c(0xe109e151ul), mk_sl_cui_uint32_c(0x7abe7a25ul), mk_sl_cui_uint32_c(0x139113eful),
	}}},
	{{{
			mk_sl_cui_uint32_c(0xd939a9d9ul), mk_sl_cui_uint32_c(0x90176790ul), mk_sl_cui_uint32_c(0x719cb371ul), mk_sl_cui_uint32_c(0xd2a6e8d2ul), mk_sl_cui_uint32_c(0x05070405ul), mk_sl_cui_uint32_c(0x9852fd98ul), mk_sl_cui_uint32_c(0x6580a365ul), mk_sl_cui_uint32_c(0xdfe476dful), mk_sl_cui_uint32_c(0x08459a08ul), mk_sl_cui_uint32_c(0x024b9202ul), mk_sl_cui_uint32_c(0xa0e080a0ul), mk_sl_cui_uint32_c(0x665a7866ul), mk_sl_cui_uint32_c(0xddafe4ddul), mk_sl_cui_uint32_c(0xb06addb0ul), mk_sl_cui_uint32_c(0xbf63d1bful), mk_sl_cui_uint32_c(0x362a3836ul),
			mk_sl_cui_uint32_c(0x54e60d54ul), mk_sl_cui_uint32_c(0x4320c643ul), mk_sl_cui_uint32_c(0x62cc3562ul), mk_sl_cui_uint32_c(0xbef298beul), mk_sl_cui_uint32_c(0x1e12181eul), mk_sl_cui_uint32_c(0x24ebf724ul), mk_sl_cui_uint32_c(0xd7a1ecd7ul), mk_sl_cui_uint32_c(0x77416c77ul), mk_sl_cui_uint32_c(0xbd2843bdul), mk_sl_cui_uint32_c(0x32bc7532ul), mk_sl_cui_uint32_c(0xd47b37d4ul), mk_sl_cui_uint32_c(0x9b88269bul), mk_sl_cui_uint32_c(0x700dfa70ul), mk_sl_cui_uint32_c(0xf94413f9ul), mk_sl_cui_uint32_c(0xb1fb94b1ul), mk_sl_cui_uint32_c(0x5a7e485aul),
			mk_sl_cui_uint32_c(0x7a03f27aul), mk_sl_cui_uint32_c(0xe48cd0e4ul), mk_sl_cui_uint32_c(0x47b68b47ul), mk_sl_cui_uint32_c(0x3c24303cul), mk_sl_cui_uint32_c(0xa5e784a5ul), mk_sl_cui_uint32_c(0x416b5441ul), mk_sl_cui_uint32_c(0x06dddf06ul), mk_sl_cui_uint32_c(0xc56023c5ul), mk_sl_cui_uint32_c(0x45fd1945ul), mk_sl_cui_uint32_c(0xa33a5ba3ul), mk_sl_cui_uint32_c(0x68c23d68ul), mk_sl_cui_uint32_c(0x158d5915ul), mk_sl_cui_uint32_c(0x21ecf321ul), mk_sl_cui_uint32_c(0x3166ae31ul), mk_sl_cui_uint32_c(0x3e6fa23eul), mk_sl_cui_uint32_c(0x16578216ul),
			mk_sl_cui_uint32_c(0x95106395ul), mk_sl_cui_uint32_c(0x5bef015bul), mk_sl_cui_uint32_c(0x4db8834dul), mk_sl_cui_uint32_c(0x91862e91ul), mk_sl_cui_uint32_c(0xb56dd9b5ul), mk_sl_cui_uint32_c(0x1f83511ful), mk_sl_cui_uint32_c(0x53aa9b53ul), mk_sl_cui_uint32_c(0x635d7c63ul), mk_sl_cui_uint32_c(0x3b68a63bul), mk_sl_cui_uint32_c(0x3ffeeb3ful), mk_sl_cui_uint32_c(0xd630a5d6ul), mk_sl_cui_uint32_c(0x257abe25ul), mk_sl_cui_uint32_c(0xa7ac16a7ul), mk_sl_cui_uint32_c(0x0f090c0ful), mk_sl_cui_uint32_c(0x35f0e335ul), mk_sl_cui_uint32_c(0x23a76123ul),
			mk_sl_cui_uint32_c(0xf090c0f0ul), mk_sl_cui_uint32_c(0xafe98caful), mk_sl_cui_uint32_c(0x809d3a80ul), mk_sl_cui_uint32_c(0x925cf592ul), mk_sl_cui_uint32_c(0x810c7381ul), mk_sl_cui_uint32_c(0x27312c27ul), mk_sl_cui_uint32_c(0x76d02576ul), mk_sl_cui_uint32_c(0xe7560be7ul), mk_sl_cui_uint32_c(0x7b92bb7bul), mk_sl_cui_uint32_c(0xe9ce4ee9ul), mk_sl_cui_uint32_c(0xf10189f1ul), mk_sl_cui_uint32_c(0x9f1e6b9ful), mk_sl_cui_uint32_c(0xa93453a9ul), mk_sl_cui_uint32_c(0xc4f16ac4ul), mk_sl_cui_uint32_c(0x99c3b499ul), mk_sl_cui_uint32_c(0x975bf197ul),
			mk_sl_cui_uint32_c(0x8347e183ul), mk_sl_cui_uint32_c(0x6b18e66bul), mk_sl_cui_uint32_c(0xc822bdc8ul), mk_sl_cui_uint32_c(0x0e98450eul), mk_sl_cui_uint32_c(0x6e1fe26eul), mk_sl_cui_uint32_c(0xc9b3f4c9ul), mk_sl_cui_uint32_c(0x2f74b62ful), mk_sl_cui_uint32_c(0xcbf866cbul), mk_sl_cui_uint32_c(0xff99ccfful), mk_sl_cui_uint32_c(0xea1495eaul), mk_sl_cui_uint32_c(0xed5803edul), mk_sl_cui_uint32_c(0xf7dc56f7ul), mk_sl_cui_uint32_c(0xe18bd4e1ul), mk_sl_cui_uint32_c(0x1b151c1bul), mk_sl_cui_uint32_c(0xada21eadul), mk_sl_cui_uint32_c(0x0cd3d70cul),
			mk_sl_cui_uint32_c(0x2be2fb2bul), mk_sl_cui_uint32_c(0x1dc8c31dul), mk_sl_cui_uint32_c(0x195e8e19ul), mk_sl_cui_uint32_c(0xc22cb5c2ul), mk_sl_cui_uint32_c(0x8949e989ul), mk_sl_cui_uint32_c(0x12c1cf12ul), mk_sl_cui_uint32_c(0x7e95bf7eul), mk_sl_cui_uint32_c(0x207dba20ul), mk_sl_cui_uint32_c(0x6411ea64ul), mk_sl_cui_uint32_c(0x840b7784ul), mk_sl_cui_uint32_c(0x6dc5396dul), mk_sl_cui_uint32_c(0x6a89af6aul), mk_sl_cui_uint32_c(0xd17c33d1ul), mk_sl_cui_uint32_c(0xa171c9a1ul), mk_sl_cui_uint32_c(0xceff62ceul), mk_sl_cui_uint32_c(0x37bb7137ul),
			mk_sl_cui_uint32_c(0xfb0f81fbul), mk_sl_cui_uint32_c(0x3db5793dul), mk_sl_cui_uint32_c(0x51e10951ul), mk_sl_cui_uint32_c(0xdc3eaddcul), mk_sl_cui_uint32_c(0x2d3f242dul), mk_sl_cui_uint32_c(0xa476cda4ul), mk_sl_cui_uint32_c(0x9d55f99dul), mk_sl_cui_uint32_c(0xee82d8eeul), mk_sl_cui_uint32_c(0x8640e586ul), mk_sl_cui_uint32_c(0xae78c5aeul), mk_sl_cui_uint32_c(0xcd25b9cdul), mk_sl_cui_uint32_c(0x04964d04ul), mk_sl_cui_uint32_c(0x55774455ul), mk_sl_cui_uint32_c(0x0a0e080aul), mk_sl_cui_uint32_c(0x13508613ul), mk_sl_cui_uint32_c(0x30f7e730ul),
			mk_sl_cui_uint32_c(0xd337a1d3ul), mk_sl_cui_uint32_c(0x40fa1d40ul), mk_sl_cui_uint32_c(0x3461aa34ul), mk_sl_cui_uint32_c(0x8c4eed8cul), mk_sl_cui_uint32_c(0xb3b006b3ul), mk_sl_cui_uint32_c(0x6c54706cul), mk_sl_cui_uint32_c(0x2a73b22aul), mk_sl_cui_uint32_c(0x523bd252ul), mk_sl_cui_uint32_c(0x0b9f410bul), mk_sl_cui_uint32_c(0x8b027b8bul), mk_sl_cui_uint32_c(0x88d8a088ul), mk_sl_cui_uint32_c(0x4ff3114ful), mk_sl_cui_uint32_c(0x67cb3167ul), mk_sl_cui_uint32_c(0x4627c246ul), mk_sl_cui_uint32_c(0xc06727c0ul), mk_sl_cui_uint32_c(0xb4fc90b4ul),
			mk_sl_cui_uint32_c(0x28382028ul), mk_sl_cui_uint32_c(0x7f04f67ful), mk_sl_cui_uint32_c(0x78486078ul), mk_sl_cui_uint32_c(0x2ee5ff2eul), mk_sl_cui_uint32_c(0x074c9607ul), mk_sl_cui_uint32_c(0x4b655c4bul), mk_sl_cui_uint32_c(0xc72bb1c7ul), mk_sl_cui_uint32_c(0x6f8eab6ful), mk_sl_cui_uint32_c(0x0d429e0dul), mk_sl_cui_uint32_c(0xbbf59cbbul), mk_sl_cui_uint32_c(0xf2db52f2ul), mk_sl_cui_uint32_c(0xf34a1bf3ul), mk_sl_cui_uint32_c(0xa63d5fa6ul), mk_sl_cui_uint32_c(0x59a49359ul), mk_sl_cui_uint32_c(0xbcb90abcul), mk_sl_cui_uint32_c(0x3af9ef3aul),
			mk_sl_cui_uint32_c(0xef1391eful), mk_sl_cui_uint32_c(0xfe0885feul), mk_sl_cui_uint32_c(0x01914901ul), mk_sl_cui_uint32_c(0x6116ee61ul), mk_sl_cui_uint32_c(0x7cde2d7cul), mk_sl_cui_uint32_c(0xb2214fb2ul), mk_sl_cui_uint32_c(0x42b18f42ul), mk_sl_cui_uint32_c(0xdb723bdbul), mk_sl_cui_uint32_c(0xb82f47b8ul), mk_sl_cui_uint32_c(0x48bf8748ul), mk_sl_cui_uint32_c(0x2cae6d2cul), mk_sl_cui_uint32_c(0xe3c046e3ul), mk_sl_cui_uint32_c(0x573cd657ul), mk_sl_cui_uint32_c(0x859a3e85ul), mk_sl_cui_uint32_c(0x29a96929ul), mk_sl_cui_uint32_c(0x7d4f647dul),
			mk_sl_cui_uint32_c(0x94812a94ul), mk_sl_cui_uint32_c(0x492ece49ul), mk_sl_cui_uint32_c(0x17c6cb17ul), mk_sl_cui_uint32_c(0xca692fcaul), mk_sl_cui_uint32_c(0xc3bdfcc3ul), mk_sl_cui_uint32_c(0x5ca3975cul), mk_sl_cui_uint32_c(0x5ee8055eul), mk_sl_cui_uint32_c(0xd0ed7ad0ul), mk_sl_cui_uint32_c(0x87d1ac87ul), mk_sl_cui_uint32_c(0x8e057f8eul), mk_sl_cui_uint32_c(0xba64d5baul), mk_sl_cui_uint32_c(0xa8a51aa8ul), mk_sl_cui_uint32_c(0xb7264bb7ul), mk_sl_cui_uint32_c(0xb9be0eb9ul), mk_sl_cui_uint32_c(0x6087a760ul), mk_sl_cui_uint32_c(0xf8d55af8ul),
			mk_sl_cui_uint32_c(0x22362822ul), mk_sl_cui_uint32_c(0x111b1411ul), mk_sl_cui_uint32_c(0xde753fdeul), mk_sl_cui_uint32_c(0x79d92979ul), mk_sl_cui_uint32_c(0xaaee88aaul), mk_sl_cui_uint32_c(0x332d3c33ul), mk_sl_cui_uint32_c(0x5f794c5ful), mk_sl_cui_uint32_c(0xb6b702b6ul), mk_sl_cui_uint32_c(0x96cab896ul), mk_sl_cui_uint32_c(0x5835da58ul), mk_sl_cui_uint32_c(0x9cc4b09cul), mk_sl_cui_uint32_c(0xfc4317fcul), mk_sl_cui_uint32_c(0x1a84551aul), mk_sl_cui_uint32_c(0xf64d1ff6ul), mk_sl_cui_uint32_c(0x1c598a1cul), mk_sl_cui_uint32_c(0x38b27d38ul),
			mk_sl_cui_uint32_c(0xac3357acul), mk_sl_cui_uint32_c(0x18cfc718ul), mk_sl_cui_uint32_c(0xf4068df4ul), mk_sl_cui_uint32_c(0x69537469ul), mk_sl_cui_uint32_c(0x749bb774ul), mk_sl_cui_uint32_c(0xf597c4f5ul), mk_sl_cui_uint32_c(0x56ad9f56ul), mk_sl_cui_uint32_c(0xdae372daul), mk_sl_cui_uint32_c(0xd5ea7ed5ul), mk_sl_cui_uint32_c(0x4af4154aul), mk_sl_cui_uint32_c(0x9e8f229eul), mk_sl_cui_uint32_c(0xa2ab12a2ul), mk_sl_cui_uint32_c(0x4e62584eul), mk_sl_cui_uint32_c(0xe85f07e8ul), mk_sl_cui_uint32_c(0xe51d99e5ul), mk_sl_cui_uint32_c(0x39233439ul),
			mk_sl_cui_uint32_c(0xc1f66ec1ul), mk_sl_cui_uint32_c(0x446c5044ul), mk_sl_cui_uint32_c(0x5d32de5dul), mk_sl_cui_uint32_c(0x72466872ul), mk_sl_cui_uint32_c(0x26a06526ul), mk_sl_cui_uint32_c(0x93cdbc93ul), mk_sl_cui_uint32_c(0x03dadb03ul), mk_sl_cui_uint32_c(0xc6baf8c6ul), mk_sl_cui_uint32_c(0xfa9ec8faul), mk_sl_cui_uint32_c(0x82d6a882ul), mk_sl_cui_uint32_c(0xcf6e2bcful), mk_sl_cui_uint32_c(0x50704050ul), mk_sl_cui_uint32_c(0xeb85dcebul), mk_sl_cui_uint32_c(0x750afe75ul), mk_sl_cui_uint32_c(0x8a93328aul), mk_sl_cui_uint32_c(0x8ddfa48dul),
			mk_sl_cui_uint32_c(0x4c29ca4cul), mk_sl_cui_uint32_c(0x141c1014ul), mk_sl_cui_uint32_c(0x73d72173ul), mk_sl_cui_uint32_c(0xccb4f0ccul), mk_sl_cui_uint32_c(0x09d4d309ul), mk_sl_cui_uint32_c(0x108a5d10ul), mk_sl_cui_uint32_c(0xe2510fe2ul), mk_sl_cui_uint32_c(0x00000000ul), mk_sl_cui_uint32_c(0x9a196f9aul), mk_sl_cui_uint32_c(0xe01a9de0ul), mk_sl_cui_uint32_c(0x8f94368ful), mk_sl_cui_uint32_c(0xe6c742e6ul), mk_sl_cui_uint32_c(0xecc94aecul), mk_sl_cui_uint32_c(0xfdd25efdul), mk_sl_cui_uint32_c(0xab7fc1abul), mk_sl_cui_uint32_c(0xd8a8e0d8ul),
	}}},
}}};

mk_lang_constexpr_static_inline mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs_t const mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs =
{{{
	{{{
			mk_sl_cui_uint32_c(0x00000000ul), mk_sl_cui_uint32_c(0xa402a401ul), mk_sl_cui_uint32_c(0x05040502ul), mk_sl_cui_uint32_c(0xa106a103ul), mk_sl_cui_uint32_c(0x0a080a04ul), mk_sl_cui_uint32_c(0xae0aae05ul), mk_sl_cui_uint32_c(0x0f0c0f06ul), mk_sl_cui_uint32_c(0xab0eab07ul), mk_sl_cui_uint32_c(0x14101408ul), mk_sl_cui_uint32_c(0xb012b009ul), mk_sl_cui_uint32_c(0x1114110aul), mk_sl_cui_uint32_c(0xb516b50bul), mk_sl_cui_uint32_c(0x1e181e0cul), mk_sl_cui_uint32_c(0xba1aba0dul), mk_sl_cui_uint32_c(0x1b1c1b0eul), mk_sl_cui_uint32_c(0xbf1ebf0ful),
			mk_sl_cui_uint32_c(0x28202810ul), mk_sl_cui_uint32_c(0x8c228c11ul), mk_sl_cui_uint32_c(0x2d242d12ul), mk_sl_cui_uint32_c(0x89268913ul), mk_sl_cui_uint32_c(0x22282214ul), mk_sl_cui_uint32_c(0x862a8615ul), mk_sl_cui_uint32_c(0x272c2716ul), mk_sl_cui_uint32_c(0x832e8317ul), mk_sl_cui_uint32_c(0x3c303c18ul), mk_sl_cui_uint32_c(0x98329819ul), mk_sl_cui_uint32_c(0x3934391aul), mk_sl_cui_uint32_c(0x9d369d1bul), mk_sl_cui_uint32_c(0x3638361cul), mk_sl_cui_uint32_c(0x923a921dul), mk_sl_cui_uint32_c(0x333c331eul), mk_sl_cui_uint32_c(0x973e971ful),
			mk_sl_cui_uint32_c(0x50405020ul), mk_sl_cui_uint32_c(0xf442f421ul), mk_sl_cui_uint32_c(0x55445522ul), mk_sl_cui_uint32_c(0xf146f123ul), mk_sl_cui_uint32_c(0x5a485a24ul), mk_sl_cui_uint32_c(0xfe4afe25ul), mk_sl_cui_uint32_c(0x5f4c5f26ul), mk_sl_cui_uint32_c(0xfb4efb27ul), mk_sl_cui_uint32_c(0x44504428ul), mk_sl_cui_uint32_c(0xe052e029ul), mk_sl_cui_uint32_c(0x4154412aul), mk_sl_cui_uint32_c(0xe556e52bul), mk_sl_cui_uint32_c(0x4e584e2cul), mk_sl_cui_uint32_c(0xea5aea2dul), mk_sl_cui_uint32_c(0x4b5c4b2eul), mk_sl_cui_uint32_c(0xef5eef2ful),
			mk_sl_cui_uint32_c(0x78607830ul), mk_sl_cui_uint32_c(0xdc62dc31ul), mk_sl_cui_uint32_c(0x7d647d32ul), mk_sl_cui_uint32_c(0xd966d933ul), mk_sl_cui_uint32_c(0x72687234ul), mk_sl_cui_uint32_c(0xd66ad635ul), mk_sl_cui_uint32_c(0x776c7736ul), mk_sl_cui_uint32_c(0xd36ed337ul), mk_sl_cui_uint32_c(0x6c706c38ul), mk_sl_cui_uint32_c(0xc872c839ul), mk_sl_cui_uint32_c(0x6974693aul), mk_sl_cui_uint32_c(0xcd76cd3bul), mk_sl_cui_uint32_c(0x6678663cul), mk_sl_cui_uint32_c(0xc27ac23dul), mk_sl_cui_uint32_c(0x637c633eul), mk_sl_cui_uint32_c(0xc77ec73ful),
			mk_sl_cui_uint32_c(0xa080a040ul), mk_sl_cui_uint32_c(0x04820441ul), mk_sl_cui_uint32_c(0xa584a542ul), mk_sl_cui_uint32_c(0x01860143ul), mk_sl_cui_uint32_c(0xaa88aa44ul), mk_sl_cui_uint32_c(0x0e8a0e45ul), mk_sl_cui_uint32_c(0xaf8caf46ul), mk_sl_cui_uint32_c(0x0b8e0b47ul), mk_sl_cui_uint32_c(0xb490b448ul), mk_sl_cui_uint32_c(0x10921049ul), mk_sl_cui_uint32_c(0xb194b14aul), mk_sl_cui_uint32_c(0x1596154bul), mk_sl_cui_uint32_c(0xbe98be4cul), mk_sl_cui_uint32_c(0x1a9a1a4dul), mk_sl_cui_uint32_c(0xbb9cbb4eul), mk_sl_cui_uint32_c(0x1f9e1f4ful),
			mk_sl_cui_uint32_c(0x88a08850ul), mk_sl_cui_uint32_c(0x2ca22c51ul), mk_sl_cui_uint32_c(0x8da48d52ul), mk_sl_cui_uint32_c(0x29a62953ul), mk_sl_cui_uint32_c(0x82a88254ul), mk_sl_cui_uint32_c(0x26aa2655ul), mk_sl_cui_uint32_c(0x87ac8756ul), mk_sl_cui_uint32_c(0x23ae2357ul), mk_sl_cui_uint32_c(0x9cb09c58ul), mk_sl_cui_uint32_c(0x38b23859ul), mk_sl_cui_uint32_c(0x99b4995aul), mk_sl_cui_uint32_c(0x3db63d5bul), mk_sl_cui_uint32_c(0x96b8965cul), mk_sl_cui_uint32_c(0x32ba325dul), mk_sl_cui_uint32_c(0x93bc935eul), mk_sl_cui_uint32_c(0x37be375ful),
			mk_sl_cui_uint32_c(0xf0c0f060ul), mk_sl_cui_uint32_c(0x54c25461ul), mk_sl_cui_uint32_c(0xf5c4f562ul), mk_sl_cui_uint32_c(0x51c65163ul), mk_sl_cui_uint32_c(0xfac8fa64ul), mk_sl_cui_uint32_c(0x5eca5e65ul), mk_sl_cui_uint32_c(0xffccff66ul), mk_sl_cui_uint32_c(0x5bce5b67ul), mk_sl_cui_uint32_c(0xe4d0e468ul), mk_sl_cui_uint32_c(0x40d24069ul), mk_sl_cui_uint32_c(0xe1d4e16aul), mk_sl_cui_uint32_c(0x45d6456bul), mk_sl_cui_uint32_c(0xeed8ee6cul), mk_sl_cui_uint32_c(0x4ada4a6dul), mk_sl_cui_uint32_c(0xebdceb6eul), mk_sl_cui_uint32_c(0x4fde4f6ful),
			mk_sl_cui_uint32_c(0xd8e0d870ul), mk_sl_cui_uint32_c(0x7ce27c71ul), mk_sl_cui_uint32_c(0xdde4dd72ul), mk_sl_cui_uint32_c(0x79e67973ul), mk_sl_cui_uint32_c(0xd2e8d274ul), mk_sl_cui_uint32_c(0x76ea7675ul), mk_sl_cui_uint32_c(0xd7ecd776ul), mk_sl_cui_uint32_c(0x73ee7377ul), mk_sl_cui_uint32_c(0xccf0cc78ul), mk_sl_cui_uint32_c(0x68f26879ul), mk_sl_cui_uint32_c(0xc9f4c97aul), mk_sl_cui_uint32_c(0x6df66d7bul), mk_sl_cui_uint32_c(0xc6f8c67cul), mk_sl_cui_uint32_c(0x62fa627dul), mk_sl_cui_uint32_c(0xc3fcc37eul), mk_sl_cui_uint32_c(0x67fe677ful),
			mk_sl_cui_uint32_c(0x0d4d0d80ul), mk_sl_cui_uint32_c(0xa94fa981ul), mk_sl_cui_uint32_c(0x08490882ul), mk_sl_cui_uint32_c(0xac4bac83ul), mk_sl_cui_uint32_c(0x07450784ul), mk_sl_cui_uint32_c(0xa347a385ul), mk_sl_cui_uint32_c(0x02410286ul), mk_sl_cui_uint32_c(0xa643a687ul), mk_sl_cui_uint32_c(0x195d1988ul), mk_sl_cui_uint32_c(0xbd5fbd89ul), mk_sl_cui_uint32_c(0x1c591c8aul), mk_sl_cui_uint32_c(0xb85bb88bul), mk_sl_cui_uint32_c(0x1355138cul), mk_sl_cui_uint32_c(0xb757b78dul), mk_sl_cui_uint32_c(0x1651168eul), mk_sl_cui_uint32_c(0xb253b28ful),
			mk_sl_cui_uint32_c(0x256d2590ul), mk_sl_cui_uint32_c(0x816f8191ul), mk_sl_cui_uint32_c(0x20692092ul), mk_sl_cui_uint32_c(0x846b8493ul), mk_sl_cui_uint32_c(0x2f652f94ul), mk_sl_cui_uint32_c(0x8b678b95ul), mk_sl_cui_uint32_c(0x2a612a96ul), mk_sl_cui_uint32_c(0x8e638e97ul), mk_sl_cui_uint32_c(0x317d3198ul), mk_sl_cui_uint32_c(0x957f9599ul), mk_sl_cui_uint32_c(0x3479349aul), mk_sl_cui_uint32_c(0x907b909bul), mk_sl_cui_uint32_c(0x3b753b9cul), mk_sl_cui_uint32_c(0x9f779f9dul), mk_sl_cui_uint32_c(0x3e713e9eul), mk_sl_cui_uint32_c(0x9a739a9ful),
			mk_sl_cui_uint32_c(0x5d0d5da0ul), mk_sl_cui_uint32_c(0xf90ff9a1ul), mk_sl_cui_uint32_c(0x580958a2ul), mk_sl_cui_uint32_c(0xfc0bfca3ul), mk_sl_cui_uint32_c(0x570557a4ul), mk_sl_cui_uint32_c(0xf307f3a5ul), mk_sl_cui_uint32_c(0x520152a6ul), mk_sl_cui_uint32_c(0xf603f6a7ul), mk_sl_cui_uint32_c(0x491d49a8ul), mk_sl_cui_uint32_c(0xed1feda9ul), mk_sl_cui_uint32_c(0x4c194caaul), mk_sl_cui_uint32_c(0xe81be8abul), mk_sl_cui_uint32_c(0x431543acul), mk_sl_cui_uint32_c(0xe717e7adul), mk_sl_cui_uint32_c(0x461146aeul), mk_sl_cui_uint32_c(0xe213e2aful),
			mk_sl_cui_uint32_c(0x752d75b0ul), mk_sl_cui_uint32_c(0xd12fd1b1ul), mk_sl_cui_uint32_c(0x702970b2ul), mk_sl_cui_uint32_c(0xd42bd4b3ul), mk_sl_cui_uint32_c(0x7f257fb4ul), mk_sl_cui_uint32_c(0xdb27dbb5ul), mk_sl_cui_uint32_c(0x7a217ab6ul), mk_sl_cui_uint32_c(0xde23deb7ul), mk_sl_cui_uint32_c(0x613d61b8ul), mk_sl_cui_uint32_c(0xc53fc5b9ul), mk_sl_cui_uint32_c(0x643964baul), mk_sl_cui_uint32_c(0xc03bc0bbul), mk_sl_cui_uint32_c(0x6b356bbcul), mk_sl_cui_uint32_c(0xcf37cfbdul), mk_sl_cui_uint32_c(0x6e316ebeul), mk_sl_cui_uint32_c(0xca33cabful),
			mk_sl_cui_uint32_c(0xadcdadc0ul), mk_sl_cui_uint32_c(0x09cf09c1ul), mk_sl_cui_uint32_c(0xa8c9a8c2ul), mk_sl_cui_uint32_c(0x0ccb0cc3ul), mk_sl_cui_uint32_c(0xa7c5a7c4ul), mk_sl_cui_uint32_c(0x03c703c5ul), mk_sl_cui_uint32_c(0xa2c1a2c6ul), mk_sl_cui_uint32_c(0x06c306c7ul), mk_sl_cui_uint32_c(0xb9ddb9c8ul), mk_sl_cui_uint32_c(0x1ddf1dc9ul), mk_sl_cui_uint32_c(0xbcd9bccaul), mk_sl_cui_uint32_c(0x18db18cbul), mk_sl_cui_uint32_c(0xb3d5b3ccul), mk_sl_cui_uint32_c(0x17d717cdul), mk_sl_cui_uint32_c(0xb6d1b6ceul), mk_sl_cui_uint32_c(0x12d312cful),
			mk_sl_cui_uint32_c(0x85ed85d0ul), mk_sl_cui_uint32_c(0x21ef21d1ul), mk_sl_cui_uint32_c(0x80e980d2ul), mk_sl_cui_uint32_c(0x24eb24d3ul), mk_sl_cui_uint32_c(0x8fe58fd4ul), mk_sl_cui_uint32_c(0x2be72bd5ul), mk_sl_cui_uint32_c(0x8ae18ad6ul), mk_sl_cui_uint32_c(0x2ee32ed7ul), mk_sl_cui_uint32_c(0x91fd91d8ul), mk_sl_cui_uint32_c(0x35ff35d9ul), mk_sl_cui_uint32_c(0x94f994daul), mk_sl_cui_uint32_c(0x30fb30dbul), mk_sl_cui_uint32_c(0x9bf59bdcul), mk_sl_cui_uint32_c(0x3ff73fddul), mk_sl_cui_uint32_c(0x9ef19edeul), mk_sl_cui_uint32_c(0x3af33adful),
			mk_sl_cui_uint32_c(0xfd8dfde0ul), mk_sl_cui_uint32_c(0x598f59e1ul), mk_sl_cui_uint32_c(0xf889f8e2ul), mk_sl_cui_uint32_c(0x5c8b5ce3ul), mk_sl_cui_uint32_c(0xf785f7e4ul), mk_sl_cui_uint32_c(0x538753e5ul), mk_sl_cui_uint32_c(0xf281f2e6ul), mk_sl_cui_uint32_c(0x568356e7ul), mk_sl_cui_uint32_c(0xe99de9e8ul), mk_sl_cui_uint32_c(0x4d9f4de9ul), mk_sl_cui_uint32_c(0xec99eceaul), mk_sl_cui_uint32_c(0x489b48ebul), mk_sl_cui_uint32_c(0xe395e3ecul), mk_sl_cui_uint32_c(0x479747edul), mk_sl_cui_uint32_c(0xe691e6eeul), mk_sl_cui_uint32_c(0x429342eful),
			mk_sl_cui_uint32_c(0xd5add5f0ul), mk_sl_cui_uint32_c(0x71af71f1ul), mk_sl_cui_uint32_c(0xd0a9d0f2ul), mk_sl_cui_uint32_c(0x74ab74f3ul), mk_sl_cui_uint32_c(0xdfa5dff4ul), mk_sl_cui_uint32_c(0x7ba77bf5ul), mk_sl_cui_uint32_c(0xdaa1daf6ul), mk_sl_cui_uint32_c(0x7ea37ef7ul), mk_sl_cui_uint32_c(0xc1bdc1f8ul), mk_sl_cui_uint32_c(0x65bf65f9ul), mk_sl_cui_uint32_c(0xc4b9c4faul), mk_sl_cui_uint32_c(0x60bb60fbul), mk_sl_cui_uint32_c(0xcbb5cbfcul), mk_sl_cui_uint32_c(0x6fb76ffdul), mk_sl_cui_uint32_c(0xceb1cefeul), mk_sl_cui_uint32_c(0x6ab36afful),
	}}},
	{{{
			mk_sl_cui_uint32_c(0x00000000ul), mk_sl_cui_uint32_c(0x55a156a4ul), mk_sl_cui_uint32_c(0xaa0fac05ul), mk_sl_cui_uint32_c(0xffaefaa1ul), mk_sl_cui_uint32_c(0x191e150aul), mk_sl_cui_uint32_c(0x4cbf43aeul), mk_sl_cui_uint32_c(0xb311b90ful), mk_sl_cui_uint32_c(0xe6b0efabul), mk_sl_cui_uint32_c(0x323c2a14ul), mk_sl_cui_uint32_c(0x679d7cb0ul), mk_sl_cui_uint32_c(0x98338611ul), mk_sl_cui_uint32_c(0xcd92d0b5ul), mk_sl_cui_uint32_c(0x2b223f1eul), mk_sl_cui_uint32_c(0x7e8369baul), mk_sl_cui_uint32_c(0x812d931bul), mk_sl_cui_uint32_c(0xd48cc5bful),
			mk_sl_cui_uint32_c(0x64785428ul), mk_sl_cui_uint32_c(0x31d9028cul), mk_sl_cui_uint32_c(0xce77f82dul), mk_sl_cui_uint32_c(0x9bd6ae89ul), mk_sl_cui_uint32_c(0x7d664122ul), mk_sl_cui_uint32_c(0x28c71786ul), mk_sl_cui_uint32_c(0xd769ed27ul), mk_sl_cui_uint32_c(0x82c8bb83ul), mk_sl_cui_uint32_c(0x56447e3cul), mk_sl_cui_uint32_c(0x03e52898ul), mk_sl_cui_uint32_c(0xfc4bd239ul), mk_sl_cui_uint32_c(0xa9ea849dul), mk_sl_cui_uint32_c(0x4f5a6b36ul), mk_sl_cui_uint32_c(0x1afb3d92ul), mk_sl_cui_uint32_c(0xe555c733ul), mk_sl_cui_uint32_c(0xb0f49197ul),
			mk_sl_cui_uint32_c(0xc8f0a850ul), mk_sl_cui_uint32_c(0x9d51fef4ul), mk_sl_cui_uint32_c(0x62ff0455ul), mk_sl_cui_uint32_c(0x375e52f1ul), mk_sl_cui_uint32_c(0xd1eebd5aul), mk_sl_cui_uint32_c(0x844febfeul), mk_sl_cui_uint32_c(0x7be1115ful), mk_sl_cui_uint32_c(0x2e4047fbul), mk_sl_cui_uint32_c(0xfacc8244ul), mk_sl_cui_uint32_c(0xaf6dd4e0ul), mk_sl_cui_uint32_c(0x50c32e41ul), mk_sl_cui_uint32_c(0x056278e5ul), mk_sl_cui_uint32_c(0xe3d2974eul), mk_sl_cui_uint32_c(0xb673c1eaul), mk_sl_cui_uint32_c(0x49dd3b4bul), mk_sl_cui_uint32_c(0x1c7c6deful),
			mk_sl_cui_uint32_c(0xac88fc78ul), mk_sl_cui_uint32_c(0xf929aadcul), mk_sl_cui_uint32_c(0x0687507dul), mk_sl_cui_uint32_c(0x532606d9ul), mk_sl_cui_uint32_c(0xb596e972ul), mk_sl_cui_uint32_c(0xe037bfd6ul), mk_sl_cui_uint32_c(0x1f994577ul), mk_sl_cui_uint32_c(0x4a3813d3ul), mk_sl_cui_uint32_c(0x9eb4d66cul), mk_sl_cui_uint32_c(0xcb1580c8ul), mk_sl_cui_uint32_c(0x34bb7a69ul), mk_sl_cui_uint32_c(0x611a2ccdul), mk_sl_cui_uint32_c(0x87aac366ul), mk_sl_cui_uint32_c(0xd20b95c2ul), mk_sl_cui_uint32_c(0x2da56f63ul), mk_sl_cui_uint32_c(0x780439c7ul),
			mk_sl_cui_uint32_c(0xddad1da0ul), mk_sl_cui_uint32_c(0x880c4b04ul), mk_sl_cui_uint32_c(0x77a2b1a5ul), mk_sl_cui_uint32_c(0x2203e701ul), mk_sl_cui_uint32_c(0xc4b308aaul), mk_sl_cui_uint32_c(0x91125e0eul), mk_sl_cui_uint32_c(0x6ebca4aful), mk_sl_cui_uint32_c(0x3b1df20bul), mk_sl_cui_uint32_c(0xef9137b4ul), mk_sl_cui_uint32_c(0xba306110ul), mk_sl_cui_uint32_c(0x459e9bb1ul), mk_sl_cui_uint32_c(0x103fcd15ul), mk_sl_cui_uint32_c(0xf68f22beul), mk_sl_cui_uint32_c(0xa32e741aul), mk_sl_cui_uint32_c(0x5c808ebbul), mk_sl_cui_uint32_c(0x0921d81ful),
			mk_sl_cui_uint32_c(0xb9d54988ul), mk_sl_cui_uint32_c(0xec741f2cul), mk_sl_cui_uint32_c(0x13dae58dul), mk_sl_cui_uint32_c(0x467bb329ul), mk_sl_cui_uint32_c(0xa0cb5c82ul), mk_sl_cui_uint32_c(0xf56a0a26ul), mk_sl_cui_uint32_c(0x0ac4f087ul), mk_sl_cui_uint32_c(0x5f65a623ul), mk_sl_cui_uint32_c(0x8be9639cul), mk_sl_cui_uint32_c(0xde483538ul), mk_sl_cui_uint32_c(0x21e6cf99ul), mk_sl_cui_uint32_c(0x7447993dul), mk_sl_cui_uint32_c(0x92f77696ul), mk_sl_cui_uint32_c(0xc7562032ul), mk_sl_cui_uint32_c(0x38f8da93ul), mk_sl_cui_uint32_c(0x6d598c37ul),
			mk_sl_cui_uint32_c(0x155db5f0ul), mk_sl_cui_uint32_c(0x40fce354ul), mk_sl_cui_uint32_c(0xbf5219f5ul), mk_sl_cui_uint32_c(0xeaf34f51ul), mk_sl_cui_uint32_c(0x0c43a0faul), mk_sl_cui_uint32_c(0x59e2f65eul), mk_sl_cui_uint32_c(0xa64c0cfful), mk_sl_cui_uint32_c(0xf3ed5a5bul), mk_sl_cui_uint32_c(0x27619fe4ul), mk_sl_cui_uint32_c(0x72c0c940ul), mk_sl_cui_uint32_c(0x8d6e33e1ul), mk_sl_cui_uint32_c(0xd8cf6545ul), mk_sl_cui_uint32_c(0x3e7f8aeeul), mk_sl_cui_uint32_c(0x6bdedc4aul), mk_sl_cui_uint32_c(0x947026ebul), mk_sl_cui_uint32_c(0xc1d1704ful),
			mk_sl_cui_uint32_c(0x7125e1d8ul), mk_sl_cui_uint32_c(0x2484b77cul), mk_sl_cui_uint32_c(0xdb2a4dddul), mk_sl_cui_uint32_c(0x8e8b1b79ul), mk_sl_cui_uint32_c(0x683bf4d2ul), mk_sl_cui_uint32_c(0x3d9aa276ul), mk_sl_cui_uint32_c(0xc23458d7ul), mk_sl_cui_uint32_c(0x97950e73ul), mk_sl_cui_uint32_c(0x4319cbccul), mk_sl_cui_uint32_c(0x16b89d68ul), mk_sl_cui_uint32_c(0xe91667c9ul), mk_sl_cui_uint32_c(0xbcb7316dul), mk_sl_cui_uint32_c(0x5a07dec6ul), mk_sl_cui_uint32_c(0x0fa68862ul), mk_sl_cui_uint32_c(0xf00872c3ul), mk_sl_cui_uint32_c(0xa5a92467ul),
			mk_sl_cui_uint32_c(0xf7173a0dul), mk_sl_cui_uint32_c(0xa2b66ca9ul), mk_sl_cui_uint32_c(0x5d189608ul), mk_sl_cui_uint32_c(0x08b9c0acul), mk_sl_cui_uint32_c(0xee092f07ul), mk_sl_cui_uint32_c(0xbba879a3ul), mk_sl_cui_uint32_c(0x44068302ul), mk_sl_cui_uint32_c(0x11a7d5a6ul), mk_sl_cui_uint32_c(0xc52b1019ul), mk_sl_cui_uint32_c(0x908a46bdul), mk_sl_cui_uint32_c(0x6f24bc1cul), mk_sl_cui_uint32_c(0x3a85eab8ul), mk_sl_cui_uint32_c(0xdc350513ul), mk_sl_cui_uint32_c(0x899453b7ul), mk_sl_cui_uint32_c(0x763aa916ul), mk_sl_cui_uint32_c(0x239bffb2ul),
			mk_sl_cui_uint32_c(0x936f6e25ul), mk_sl_cui_uint32_c(0xc6ce3881ul), mk_sl_cui_uint32_c(0x3960c220ul), mk_sl_cui_uint32_c(0x6cc19484ul), mk_sl_cui_uint32_c(0x8a717b2ful), mk_sl_cui_uint32_c(0xdfd02d8bul), mk_sl_cui_uint32_c(0x207ed72aul), mk_sl_cui_uint32_c(0x75df818eul), mk_sl_cui_uint32_c(0xa1534431ul), mk_sl_cui_uint32_c(0xf4f21295ul), mk_sl_cui_uint32_c(0x0b5ce834ul), mk_sl_cui_uint32_c(0x5efdbe90ul), mk_sl_cui_uint32_c(0xb84d513bul), mk_sl_cui_uint32_c(0xedec079ful), mk_sl_cui_uint32_c(0x1242fd3eul), mk_sl_cui_uint32_c(0x47e3ab9aul),
			mk_sl_cui_uint32_c(0x3fe7925dul), mk_sl_cui_uint32_c(0x6a46c4f9ul), mk_sl_cui_uint32_c(0x95e83e58ul), mk_sl_cui_uint32_c(0xc04968fcul), mk_sl_cui_uint32_c(0x26f98757ul), mk_sl_cui_uint32_c(0x7358d1f3ul), mk_sl_cui_uint32_c(0x8cf62b52ul), mk_sl_cui_uint32_c(0xd9577df6ul), mk_sl_cui_uint32_c(0x0ddbb849ul), mk_sl_cui_uint32_c(0x587aeeedul), mk_sl_cui_uint32_c(0xa7d4144cul), mk_sl_cui_uint32_c(0xf27542e8ul), mk_sl_cui_uint32_c(0x14c5ad43ul), mk_sl_cui_uint32_c(0x4164fbe7ul), mk_sl_cui_uint32_c(0xbeca0146ul), mk_sl_cui_uint32_c(0xeb6b57e2ul),
			mk_sl_cui_uint32_c(0x5b9fc675ul), mk_sl_cui_uint32_c(0x0e3e90d1ul), mk_sl_cui_uint32_c(0xf1906a70ul), mk_sl_cui_uint32_c(0xa4313cd4ul), mk_sl_cui_uint32_c(0x4281d37ful), mk_sl_cui_uint32_c(0x172085dbul), mk_sl_cui_uint32_c(0xe88e7f7aul), mk_sl_cui_uint32_c(0xbd2f29deul), mk_sl_cui_uint32_c(0x69a3ec61ul), mk_sl_cui_uint32_c(0x3c02bac5ul), mk_sl_cui_uint32_c(0xc3ac4064ul), mk_sl_cui_uint32_c(0x960d16c0ul), mk_sl_cui_uint32_c(0x70bdf96bul), mk_sl_cui_uint32_c(0x251cafcful), mk_sl_cui_uint32_c(0xdab2556eul), mk_sl_cui_uint32_c(0x8f1303caul),
			mk_sl_cui_uint32_c(0x2aba27adul), mk_sl_cui_uint32_c(0x7f1b7109ul), mk_sl_cui_uint32_c(0x80b58ba8ul), mk_sl_cui_uint32_c(0xd514dd0cul), mk_sl_cui_uint32_c(0x33a432a7ul), mk_sl_cui_uint32_c(0x66056403ul), mk_sl_cui_uint32_c(0x99ab9ea2ul), mk_sl_cui_uint32_c(0xcc0ac806ul), mk_sl_cui_uint32_c(0x18860db9ul), mk_sl_cui_uint32_c(0x4d275b1dul), mk_sl_cui_uint32_c(0xb289a1bcul), mk_sl_cui_uint32_c(0xe728f718ul), mk_sl_cui_uint32_c(0x019818b3ul), mk_sl_cui_uint32_c(0x54394e17ul), mk_sl_cui_uint32_c(0xab97b4b6ul), mk_sl_cui_uint32_c(0xfe36e212ul),
			mk_sl_cui_uint32_c(0x4ec27385ul), mk_sl_cui_uint32_c(0x1b632521ul), mk_sl_cui_uint32_c(0xe4cddf80ul), mk_sl_cui_uint32_c(0xb16c8924ul), mk_sl_cui_uint32_c(0x57dc668ful), mk_sl_cui_uint32_c(0x027d302bul), mk_sl_cui_uint32_c(0xfdd3ca8aul), mk_sl_cui_uint32_c(0xa8729c2eul), mk_sl_cui_uint32_c(0x7cfe5991ul), mk_sl_cui_uint32_c(0x295f0f35ul), mk_sl_cui_uint32_c(0xd6f1f594ul), mk_sl_cui_uint32_c(0x8350a330ul), mk_sl_cui_uint32_c(0x65e04c9bul), mk_sl_cui_uint32_c(0x30411a3ful), mk_sl_cui_uint32_c(0xcfefe09eul), mk_sl_cui_uint32_c(0x9a4eb63aul),
			mk_sl_cui_uint32_c(0xe24a8ffdul), mk_sl_cui_uint32_c(0xb7ebd959ul), mk_sl_cui_uint32_c(0x484523f8ul), mk_sl_cui_uint32_c(0x1de4755cul), mk_sl_cui_uint32_c(0xfb549af7ul), mk_sl_cui_uint32_c(0xaef5cc53ul), mk_sl_cui_uint32_c(0x515b36f2ul), mk_sl_cui_uint32_c(0x04fa6056ul), mk_sl_cui_uint32_c(0xd076a5e9ul), mk_sl_cui_uint32_c(0x85d7f34dul), mk_sl_cui_uint32_c(0x7a7909ecul), mk_sl_cui_uint32_c(0x2fd85f48ul), mk_sl_cui_uint32_c(0xc968b0e3ul), mk_sl_cui_uint32_c(0x9cc9e647ul), mk_sl_cui_uint32_c(0x63671ce6ul), mk_sl_cui_uint32_c(0x36c64a42ul),
			mk_sl_cui_uint32_c(0x8632dbd5ul), mk_sl_cui_uint32_c(0xd3938d71ul), mk_sl_cui_uint32_c(0x2c3d77d0ul), mk_sl_cui_uint32_c(0x799c2174ul), mk_sl_cui_uint32_c(0x9f2ccedful), mk_sl_cui_uint32_c(0xca8d987bul), mk_sl_cui_uint32_c(0x352362daul), mk_sl_cui_uint32_c(0x6082347eul), mk_sl_cui_uint32_c(0xb40ef1c1ul), mk_sl_cui_uint32_c(0xe1afa765ul), mk_sl_cui_uint32_c(0x1e015dc4ul), mk_sl_cui_uint32_c(0x4ba00b60ul), mk_sl_cui_uint32_c(0xad10e4cbul), mk_sl_cui_uint32_c(0xf8b1b26ful), mk_sl_cui_uint32_c(0x071f48ceul), mk_sl_cui_uint32_c(0x52be1e6aul),
	}}},
	{{{
			mk_sl_cui_uint32_c(0x00000000ul), mk_sl_cui_uint32_c(0x87fc8255ul), mk_sl_cui_uint32_c(0x43b549aaul), mk_sl_cui_uint32_c(0xc449cbfful), mk_sl_cui_uint32_c(0x86279219ul), mk_sl_cui_uint32_c(0x01db104cul), mk_sl_cui_uint32_c(0xc592dbb3ul), mk_sl_cui_uint32_c(0x426e59e6ul), mk_sl_cui_uint32_c(0x414e6932ul), mk_sl_cui_uint32_c(0xc6b2eb67ul), mk_sl_cui_uint32_c(0x02fb2098ul), mk_sl_cui_uint32_c(0x8507a2cdul), mk_sl_cui_uint32_c(0xc769fb2bul), mk_sl_cui_uint32_c(0x4095797eul), mk_sl_cui_uint32_c(0x84dcb281ul), mk_sl_cui_uint32_c(0x032030d4ul),
			mk_sl_cui_uint32_c(0x829cd264ul), mk_sl_cui_uint32_c(0x05605031ul), mk_sl_cui_uint32_c(0xc1299bceul), mk_sl_cui_uint32_c(0x46d5199bul), mk_sl_cui_uint32_c(0x04bb407dul), mk_sl_cui_uint32_c(0x8347c228ul), mk_sl_cui_uint32_c(0x470e09d7ul), mk_sl_cui_uint32_c(0xc0f28b82ul), mk_sl_cui_uint32_c(0xc3d2bb56ul), mk_sl_cui_uint32_c(0x442e3903ul), mk_sl_cui_uint32_c(0x8067f2fcul), mk_sl_cui_uint32_c(0x079b70a9ul), mk_sl_cui_uint32_c(0x45f5294ful), mk_sl_cui_uint32_c(0xc209ab1aul), mk_sl_cui_uint32_c(0x064060e5ul), mk_sl_cui_uint32_c(0x81bce2b0ul),
			mk_sl_cui_uint32_c(0x4975e9c8ul), mk_sl_cui_uint32_c(0xce896b9dul), mk_sl_cui_uint32_c(0x0ac0a062ul), mk_sl_cui_uint32_c(0x8d3c2237ul), mk_sl_cui_uint32_c(0xcf527bd1ul), mk_sl_cui_uint32_c(0x48aef984ul), mk_sl_cui_uint32_c(0x8ce7327bul), mk_sl_cui_uint32_c(0x0b1bb02eul), mk_sl_cui_uint32_c(0x083b80faul), mk_sl_cui_uint32_c(0x8fc702aful), mk_sl_cui_uint32_c(0x4b8ec950ul), mk_sl_cui_uint32_c(0xcc724b05ul), mk_sl_cui_uint32_c(0x8e1c12e3ul), mk_sl_cui_uint32_c(0x09e090b6ul), mk_sl_cui_uint32_c(0xcda95b49ul), mk_sl_cui_uint32_c(0x4a55d91cul),
			mk_sl_cui_uint32_c(0xcbe93bacul), mk_sl_cui_uint32_c(0x4c15b9f9ul), mk_sl_cui_uint32_c(0x885c7206ul), mk_sl_cui_uint32_c(0x0fa0f053ul), mk_sl_cui_uint32_c(0x4dcea9b5ul), mk_sl_cui_uint32_c(0xca322be0ul), mk_sl_cui_uint32_c(0x0e7be01ful), mk_sl_cui_uint32_c(0x8987624aul), mk_sl_cui_uint32_c(0x8aa7529eul), mk_sl_cui_uint32_c(0x0d5bd0cbul), mk_sl_cui_uint32_c(0xc9121b34ul), mk_sl_cui_uint32_c(0x4eee9961ul), mk_sl_cui_uint32_c(0x0c80c087ul), mk_sl_cui_uint32_c(0x8b7c42d2ul), mk_sl_cui_uint32_c(0x4f35892dul), mk_sl_cui_uint32_c(0xc8c90b78ul),
			mk_sl_cui_uint32_c(0x92ea9fddul), mk_sl_cui_uint32_c(0x15161d88ul), mk_sl_cui_uint32_c(0xd15fd677ul), mk_sl_cui_uint32_c(0x56a35422ul), mk_sl_cui_uint32_c(0x14cd0dc4ul), mk_sl_cui_uint32_c(0x93318f91ul), mk_sl_cui_uint32_c(0x5778446eul), mk_sl_cui_uint32_c(0xd084c63bul), mk_sl_cui_uint32_c(0xd3a4f6eful), mk_sl_cui_uint32_c(0x545874baul), mk_sl_cui_uint32_c(0x9011bf45ul), mk_sl_cui_uint32_c(0x17ed3d10ul), mk_sl_cui_uint32_c(0x558364f6ul), mk_sl_cui_uint32_c(0xd27fe6a3ul), mk_sl_cui_uint32_c(0x16362d5cul), mk_sl_cui_uint32_c(0x91caaf09ul),
			mk_sl_cui_uint32_c(0x10764db9ul), mk_sl_cui_uint32_c(0x978acfecul), mk_sl_cui_uint32_c(0x53c30413ul), mk_sl_cui_uint32_c(0xd43f8646ul), mk_sl_cui_uint32_c(0x9651dfa0ul), mk_sl_cui_uint32_c(0x11ad5df5ul), mk_sl_cui_uint32_c(0xd5e4960aul), mk_sl_cui_uint32_c(0x5218145ful), mk_sl_cui_uint32_c(0x5138248bul), mk_sl_cui_uint32_c(0xd6c4a6deul), mk_sl_cui_uint32_c(0x128d6d21ul), mk_sl_cui_uint32_c(0x9571ef74ul), mk_sl_cui_uint32_c(0xd71fb692ul), mk_sl_cui_uint32_c(0x50e334c7ul), mk_sl_cui_uint32_c(0x94aaff38ul), mk_sl_cui_uint32_c(0x13567d6dul),
			mk_sl_cui_uint32_c(0xdb9f7615ul), mk_sl_cui_uint32_c(0x5c63f440ul), mk_sl_cui_uint32_c(0x982a3fbful), mk_sl_cui_uint32_c(0x1fd6bdeaul), mk_sl_cui_uint32_c(0x5db8e40cul), mk_sl_cui_uint32_c(0xda446659ul), mk_sl_cui_uint32_c(0x1e0dada6ul), mk_sl_cui_uint32_c(0x99f12ff3ul), mk_sl_cui_uint32_c(0x9ad11f27ul), mk_sl_cui_uint32_c(0x1d2d9d72ul), mk_sl_cui_uint32_c(0xd964568dul), mk_sl_cui_uint32_c(0x5e98d4d8ul), mk_sl_cui_uint32_c(0x1cf68d3eul), mk_sl_cui_uint32_c(0x9b0a0f6bul), mk_sl_cui_uint32_c(0x5f43c494ul), mk_sl_cui_uint32_c(0xd8bf46c1ul),
			mk_sl_cui_uint32_c(0x5903a471ul), mk_sl_cui_uint32_c(0xdeff2624ul), mk_sl_cui_uint32_c(0x1ab6eddbul), mk_sl_cui_uint32_c(0x9d4a6f8eul), mk_sl_cui_uint32_c(0xdf243668ul), mk_sl_cui_uint32_c(0x58d8b43dul), mk_sl_cui_uint32_c(0x9c917fc2ul), mk_sl_cui_uint32_c(0x1b6dfd97ul), mk_sl_cui_uint32_c(0x184dcd43ul), mk_sl_cui_uint32_c(0x9fb14f16ul), mk_sl_cui_uint32_c(0x5bf884e9ul), mk_sl_cui_uint32_c(0xdc0406bcul), mk_sl_cui_uint32_c(0x9e6a5f5aul), mk_sl_cui_uint32_c(0x1996dd0ful), mk_sl_cui_uint32_c(0xdddf16f0ul), mk_sl_cui_uint32_c(0x5a2394a5ul),
			mk_sl_cui_uint32_c(0x699973f7ul), mk_sl_cui_uint32_c(0xee65f1a2ul), mk_sl_cui_uint32_c(0x2a2c3a5dul), mk_sl_cui_uint32_c(0xadd0b808ul), mk_sl_cui_uint32_c(0xefbee1eeul), mk_sl_cui_uint32_c(0x684263bbul), mk_sl_cui_uint32_c(0xac0ba844ul), mk_sl_cui_uint32_c(0x2bf72a11ul), mk_sl_cui_uint32_c(0x28d71ac5ul), mk_sl_cui_uint32_c(0xaf2b9890ul), mk_sl_cui_uint32_c(0x6b62536ful), mk_sl_cui_uint32_c(0xec9ed13aul), mk_sl_cui_uint32_c(0xaef088dcul), mk_sl_cui_uint32_c(0x290c0a89ul), mk_sl_cui_uint32_c(0xed45c176ul), mk_sl_cui_uint32_c(0x6ab94323ul),
			mk_sl_cui_uint32_c(0xeb05a193ul), mk_sl_cui_uint32_c(0x6cf923c6ul), mk_sl_cui_uint32_c(0xa8b0e839ul), mk_sl_cui_uint32_c(0x2f4c6a6cul), mk_sl_cui_uint32_c(0x6d22338aul), mk_sl_cui_uint32_c(0xeadeb1dful), mk_sl_cui_uint32_c(0x2e977a20ul), mk_sl_cui_uint32_c(0xa96bf875ul), mk_sl_cui_uint32_c(0xaa4bc8a1ul), mk_sl_cui_uint32_c(0x2db74af4ul), mk_sl_cui_uint32_c(0xe9fe810bul), mk_sl_cui_uint32_c(0x6e02035eul), mk_sl_cui_uint32_c(0x2c6c5ab8ul), mk_sl_cui_uint32_c(0xab90d8edul), mk_sl_cui_uint32_c(0x6fd91312ul), mk_sl_cui_uint32_c(0xe8259147ul),
			mk_sl_cui_uint32_c(0x20ec9a3ful), mk_sl_cui_uint32_c(0xa710186aul), mk_sl_cui_uint32_c(0x6359d395ul), mk_sl_cui_uint32_c(0xe4a551c0ul), mk_sl_cui_uint32_c(0xa6cb0826ul), mk_sl_cui_uint32_c(0x21378a73ul), mk_sl_cui_uint32_c(0xe57e418cul), mk_sl_cui_uint32_c(0x6282c3d9ul), mk_sl_cui_uint32_c(0x61a2f30dul), mk_sl_cui_uint32_c(0xe65e7158ul), mk_sl_cui_uint32_c(0x2217baa7ul), mk_sl_cui_uint32_c(0xa5eb38f2ul), mk_sl_cui_uint32_c(0xe7856114ul), mk_sl_cui_uint32_c(0x6079e341ul), mk_sl_cui_uint32_c(0xa43028beul), mk_sl_cui_uint32_c(0x23ccaaebul),
			mk_sl_cui_uint32_c(0xa270485bul), mk_sl_cui_uint32_c(0x258cca0eul), mk_sl_cui_uint32_c(0xe1c501f1ul), mk_sl_cui_uint32_c(0x663983a4ul), mk_sl_cui_uint32_c(0x2457da42ul), mk_sl_cui_uint32_c(0xa3ab5817ul), mk_sl_cui_uint32_c(0x67e293e8ul), mk_sl_cui_uint32_c(0xe01e11bdul), mk_sl_cui_uint32_c(0xe33e2169ul), mk_sl_cui_uint32_c(0x64c2a33cul), mk_sl_cui_uint32_c(0xa08b68c3ul), mk_sl_cui_uint32_c(0x2777ea96ul), mk_sl_cui_uint32_c(0x6519b370ul), mk_sl_cui_uint32_c(0xe2e53125ul), mk_sl_cui_uint32_c(0x26acfadaul), mk_sl_cui_uint32_c(0xa150788ful),
			mk_sl_cui_uint32_c(0xfb73ec2aul), mk_sl_cui_uint32_c(0x7c8f6e7ful), mk_sl_cui_uint32_c(0xb8c6a580ul), mk_sl_cui_uint32_c(0x3f3a27d5ul), mk_sl_cui_uint32_c(0x7d547e33ul), mk_sl_cui_uint32_c(0xfaa8fc66ul), mk_sl_cui_uint32_c(0x3ee13799ul), mk_sl_cui_uint32_c(0xb91db5ccul), mk_sl_cui_uint32_c(0xba3d8518ul), mk_sl_cui_uint32_c(0x3dc1074dul), mk_sl_cui_uint32_c(0xf988ccb2ul), mk_sl_cui_uint32_c(0x7e744ee7ul), mk_sl_cui_uint32_c(0x3c1a1701ul), mk_sl_cui_uint32_c(0xbbe69554ul), mk_sl_cui_uint32_c(0x7faf5eabul), mk_sl_cui_uint32_c(0xf853dcfeul),
			mk_sl_cui_uint32_c(0x79ef3e4eul), mk_sl_cui_uint32_c(0xfe13bc1bul), mk_sl_cui_uint32_c(0x3a5a77e4ul), mk_sl_cui_uint32_c(0xbda6f5b1ul), mk_sl_cui_uint32_c(0xffc8ac57ul), mk_sl_cui_uint32_c(0x78342e02ul), mk_sl_cui_uint32_c(0xbc7de5fdul), mk_sl_cui_uint32_c(0x3b8167a8ul), mk_sl_cui_uint32_c(0x38a1577cul), mk_sl_cui_uint32_c(0xbf5dd529ul), mk_sl_cui_uint32_c(0x7b141ed6ul), mk_sl_cui_uint32_c(0xfce89c83ul), mk_sl_cui_uint32_c(0xbe86c565ul), mk_sl_cui_uint32_c(0x397a4730ul), mk_sl_cui_uint32_c(0xfd338ccful), mk_sl_cui_uint32_c(0x7acf0e9aul),
			mk_sl_cui_uint32_c(0xb20605e2ul), mk_sl_cui_uint32_c(0x35fa87b7ul), mk_sl_cui_uint32_c(0xf1b34c48ul), mk_sl_cui_uint32_c(0x764fce1dul), mk_sl_cui_uint32_c(0x342197fbul), mk_sl_cui_uint32_c(0xb3dd15aeul), mk_sl_cui_uint32_c(0x7794de51ul), mk_sl_cui_uint32_c(0xf0685c04ul), mk_sl_cui_uint32_c(0xf3486cd0ul), mk_sl_cui_uint32_c(0x74b4ee85ul), mk_sl_cui_uint32_c(0xb0fd257aul), mk_sl_cui_uint32_c(0x3701a72ful), mk_sl_cui_uint32_c(0x756ffec9ul), mk_sl_cui_uint32_c(0xf2937c9cul), mk_sl_cui_uint32_c(0x36dab763ul), mk_sl_cui_uint32_c(0xb1263536ul),
			mk_sl_cui_uint32_c(0x309ad786ul), mk_sl_cui_uint32_c(0xb76655d3ul), mk_sl_cui_uint32_c(0x732f9e2cul), mk_sl_cui_uint32_c(0xf4d31c79ul), mk_sl_cui_uint32_c(0xb6bd459ful), mk_sl_cui_uint32_c(0x3141c7caul), mk_sl_cui_uint32_c(0xf5080c35ul), mk_sl_cui_uint32_c(0x72f48e60ul), mk_sl_cui_uint32_c(0x71d4beb4ul), mk_sl_cui_uint32_c(0xf6283ce1ul), mk_sl_cui_uint32_c(0x3261f71eul), mk_sl_cui_uint32_c(0xb59d754bul), mk_sl_cui_uint32_c(0xf7f32cadul), mk_sl_cui_uint32_c(0x700faef8ul), mk_sl_cui_uint32_c(0xb4466507ul), mk_sl_cui_uint32_c(0x33bae752ul),
	}}},
	{{{
			mk_sl_cui_uint32_c(0x00000000ul), mk_sl_cui_uint32_c(0x5ac1f387ul), mk_sl_cui_uint32_c(0xb4cfab43ul), mk_sl_cui_uint32_c(0xee0e58c4ul), mk_sl_cui_uint32_c(0x25d31b86ul), mk_sl_cui_uint32_c(0x7f12e801ul), mk_sl_cui_uint32_c(0x911cb0c5ul), mk_sl_cui_uint32_c(0xcbdd4342ul), mk_sl_cui_uint32_c(0x4aeb3641ul), mk_sl_cui_uint32_c(0x102ac5c6ul), mk_sl_cui_uint32_c(0xfe249d02ul), mk_sl_cui_uint32_c(0xa4e56e85ul), mk_sl_cui_uint32_c(0x6f382dc7ul), mk_sl_cui_uint32_c(0x35f9de40ul), mk_sl_cui_uint32_c(0xdbf78684ul), mk_sl_cui_uint32_c(0x81367503ul),
			mk_sl_cui_uint32_c(0x949b6c82ul), mk_sl_cui_uint32_c(0xce5a9f05ul), mk_sl_cui_uint32_c(0x2054c7c1ul), mk_sl_cui_uint32_c(0x7a953446ul), mk_sl_cui_uint32_c(0xb1487704ul), mk_sl_cui_uint32_c(0xeb898483ul), mk_sl_cui_uint32_c(0x0587dc47ul), mk_sl_cui_uint32_c(0x5f462fc0ul), mk_sl_cui_uint32_c(0xde705ac3ul), mk_sl_cui_uint32_c(0x84b1a944ul), mk_sl_cui_uint32_c(0x6abff180ul), mk_sl_cui_uint32_c(0x307e0207ul), mk_sl_cui_uint32_c(0xfba34145ul), mk_sl_cui_uint32_c(0xa162b2c2ul), mk_sl_cui_uint32_c(0x4f6cea06ul), mk_sl_cui_uint32_c(0x15ad1981ul),
			mk_sl_cui_uint32_c(0x657bd849ul), mk_sl_cui_uint32_c(0x3fba2bceul), mk_sl_cui_uint32_c(0xd1b4730aul), mk_sl_cui_uint32_c(0x8b75808dul), mk_sl_cui_uint32_c(0x40a8c3cful), mk_sl_cui_uint32_c(0x1a693048ul), mk_sl_cui_uint32_c(0xf467688cul), mk_sl_cui_uint32_c(0xaea69b0bul), mk_sl_cui_uint32_c(0x2f90ee08ul), mk_sl_cui_uint32_c(0x75511d8ful), mk_sl_cui_uint32_c(0x9b5f454bul), mk_sl_cui_uint32_c(0xc19eb6ccul), mk_sl_cui_uint32_c(0x0a43f58eul), mk_sl_cui_uint32_c(0x50820609ul), mk_sl_cui_uint32_c(0xbe8c5ecdul), mk_sl_cui_uint32_c(0xe44dad4aul),
			mk_sl_cui_uint32_c(0xf1e0b4cbul), mk_sl_cui_uint32_c(0xab21474cul), mk_sl_cui_uint32_c(0x452f1f88ul), mk_sl_cui_uint32_c(0x1feeec0ful), mk_sl_cui_uint32_c(0xd433af4dul), mk_sl_cui_uint32_c(0x8ef25ccaul), mk_sl_cui_uint32_c(0x60fc040eul), mk_sl_cui_uint32_c(0x3a3df789ul), mk_sl_cui_uint32_c(0xbb0b828aul), mk_sl_cui_uint32_c(0xe1ca710dul), mk_sl_cui_uint32_c(0x0fc429c9ul), mk_sl_cui_uint32_c(0x5505da4eul), mk_sl_cui_uint32_c(0x9ed8990cul), mk_sl_cui_uint32_c(0xc4196a8bul), mk_sl_cui_uint32_c(0x2a17324ful), mk_sl_cui_uint32_c(0x70d6c1c8ul),
			mk_sl_cui_uint32_c(0xcaf6fd92ul), mk_sl_cui_uint32_c(0x90370e15ul), mk_sl_cui_uint32_c(0x7e3956d1ul), mk_sl_cui_uint32_c(0x24f8a556ul), mk_sl_cui_uint32_c(0xef25e614ul), mk_sl_cui_uint32_c(0xb5e41593ul), mk_sl_cui_uint32_c(0x5bea4d57ul), mk_sl_cui_uint32_c(0x012bbed0ul), mk_sl_cui_uint32_c(0x801dcbd3ul), mk_sl_cui_uint32_c(0xdadc3854ul), mk_sl_cui_uint32_c(0x34d26090ul), mk_sl_cui_uint32_c(0x6e139317ul), mk_sl_cui_uint32_c(0xa5ced055ul), mk_sl_cui_uint32_c(0xff0f23d2ul), mk_sl_cui_uint32_c(0x11017b16ul), mk_sl_cui_uint32_c(0x4bc08891ul),
			mk_sl_cui_uint32_c(0x5e6d9110ul), mk_sl_cui_uint32_c(0x04ac6297ul), mk_sl_cui_uint32_c(0xeaa23a53ul), mk_sl_cui_uint32_c(0xb063c9d4ul), mk_sl_cui_uint32_c(0x7bbe8a96ul), mk_sl_cui_uint32_c(0x217f7911ul), mk_sl_cui_uint32_c(0xcf7121d5ul), mk_sl_cui_uint32_c(0x95b0d252ul), mk_sl_cui_uint32_c(0x1486a751ul), mk_sl_cui_uint32_c(0x4e4754d6ul), mk_sl_cui_uint32_c(0xa0490c12ul), mk_sl_cui_uint32_c(0xfa88ff95ul), mk_sl_cui_uint32_c(0x3155bcd7ul), mk_sl_cui_uint32_c(0x6b944f50ul), mk_sl_cui_uint32_c(0x859a1794ul), mk_sl_cui_uint32_c(0xdf5be413ul),
			mk_sl_cui_uint32_c(0xaf8d25dbul), mk_sl_cui_uint32_c(0xf54cd65cul), mk_sl_cui_uint32_c(0x1b428e98ul), mk_sl_cui_uint32_c(0x41837d1ful), mk_sl_cui_uint32_c(0x8a5e3e5dul), mk_sl_cui_uint32_c(0xd09fcddaul), mk_sl_cui_uint32_c(0x3e91951eul), mk_sl_cui_uint32_c(0x64506699ul), mk_sl_cui_uint32_c(0xe566139aul), mk_sl_cui_uint32_c(0xbfa7e01dul), mk_sl_cui_uint32_c(0x51a9b8d9ul), mk_sl_cui_uint32_c(0x0b684b5eul), mk_sl_cui_uint32_c(0xc0b5081cul), mk_sl_cui_uint32_c(0x9a74fb9bul), mk_sl_cui_uint32_c(0x747aa35ful), mk_sl_cui_uint32_c(0x2ebb50d8ul),
			mk_sl_cui_uint32_c(0x3b164959ul), mk_sl_cui_uint32_c(0x61d7badeul), mk_sl_cui_uint32_c(0x8fd9e21aul), mk_sl_cui_uint32_c(0xd518119dul), mk_sl_cui_uint32_c(0x1ec552dful), mk_sl_cui_uint32_c(0x4404a158ul), mk_sl_cui_uint32_c(0xaa0af99cul), mk_sl_cui_uint32_c(0xf0cb0a1bul), mk_sl_cui_uint32_c(0x71fd7f18ul), mk_sl_cui_uint32_c(0x2b3c8c9ful), mk_sl_cui_uint32_c(0xc532d45bul), mk_sl_cui_uint32_c(0x9ff327dcul), mk_sl_cui_uint32_c(0x542e649eul), mk_sl_cui_uint32_c(0x0eef9719ul), mk_sl_cui_uint32_c(0xe0e1cfddul), mk_sl_cui_uint32_c(0xba203c5aul),
			mk_sl_cui_uint32_c(0xd9a1b769ul), mk_sl_cui_uint32_c(0x836044eeul), mk_sl_cui_uint32_c(0x6d6e1c2aul), mk_sl_cui_uint32_c(0x37afefadul), mk_sl_cui_uint32_c(0xfc72aceful), mk_sl_cui_uint32_c(0xa6b35f68ul), mk_sl_cui_uint32_c(0x48bd07acul), mk_sl_cui_uint32_c(0x127cf42bul), mk_sl_cui_uint32_c(0x934a8128ul), mk_sl_cui_uint32_c(0xc98b72aful), mk_sl_cui_uint32_c(0x27852a6bul), mk_sl_cui_uint32_c(0x7d44d9ecul), mk_sl_cui_uint32_c(0xb6999aaeul), mk_sl_cui_uint32_c(0xec586929ul), mk_sl_cui_uint32_c(0x025631edul), mk_sl_cui_uint32_c(0x5897c26aul),
			mk_sl_cui_uint32_c(0x4d3adbebul), mk_sl_cui_uint32_c(0x17fb286cul), mk_sl_cui_uint32_c(0xf9f570a8ul), mk_sl_cui_uint32_c(0xa334832ful), mk_sl_cui_uint32_c(0x68e9c06dul), mk_sl_cui_uint32_c(0x322833eaul), mk_sl_cui_uint32_c(0xdc266b2eul), mk_sl_cui_uint32_c(0x86e798a9ul), mk_sl_cui_uint32_c(0x07d1edaaul), mk_sl_cui_uint32_c(0x5d101e2dul), mk_sl_cui_uint32_c(0xb31e46e9ul), mk_sl_cui_uint32_c(0xe9dfb56eul), mk_sl_cui_uint32_c(0x2202f62cul), mk_sl_cui_uint32_c(0x78c305abul), mk_sl_cui_uint32_c(0x96cd5d6ful), mk_sl_cui_uint32_c(0xcc0caee8ul),
			mk_sl_cui_uint32_c(0xbcda6f20ul), mk_sl_cui_uint32_c(0xe61b9ca7ul), mk_sl_cui_uint32_c(0x0815c463ul), mk_sl_cui_uint32_c(0x52d437e4ul), mk_sl_cui_uint32_c(0x990974a6ul), mk_sl_cui_uint32_c(0xc3c88721ul), mk_sl_cui_uint32_c(0x2dc6dfe5ul), mk_sl_cui_uint32_c(0x77072c62ul), mk_sl_cui_uint32_c(0xf6315961ul), mk_sl_cui_uint32_c(0xacf0aae6ul), mk_sl_cui_uint32_c(0x42fef222ul), mk_sl_cui_uint32_c(0x183f01a5ul), mk_sl_cui_uint32_c(0xd3e242e7ul), mk_sl_cui_uint32_c(0x8923b160ul), mk_sl_cui_uint32_c(0x672de9a4ul), mk_sl_cui_uint32_c(0x3dec1a23ul),
			mk_sl_cui_uint32_c(0x284103a2ul), mk_sl_cui_uint32_c(0x7280f025ul), mk_sl_cui_uint32_c(0x9c8ea8e1ul), mk_sl_cui_uint32_c(0xc64f5b66ul), mk_sl_cui_uint32_c(0x0d921824ul), mk_sl_cui_uint32_c(0x5753eba3ul), mk_sl_cui_uint32_c(0xb95db367ul), mk_sl_cui_uint32_c(0xe39c40e0ul), mk_sl_cui_uint32_c(0x62aa35e3ul), mk_sl_cui_uint32_c(0x386bc664ul), mk_sl_cui_uint32_c(0xd6659ea0ul), mk_sl_cui_uint32_c(0x8ca46d27ul), mk_sl_cui_uint32_c(0x47792e65ul), mk_sl_cui_uint32_c(0x1db8dde2ul), mk_sl_cui_uint32_c(0xf3b68526ul), mk_sl_cui_uint32_c(0xa97776a1ul),
			mk_sl_cui_uint32_c(0x13574afbul), mk_sl_cui_uint32_c(0x4996b97cul), mk_sl_cui_uint32_c(0xa798e1b8ul), mk_sl_cui_uint32_c(0xfd59123ful), mk_sl_cui_uint32_c(0x3684517dul), mk_sl_cui_uint32_c(0x6c45a2faul), mk_sl_cui_uint32_c(0x824bfa3eul), mk_sl_cui_uint32_c(0xd88a09b9ul), mk_sl_cui_uint32_c(0x59bc7cbaul), mk_sl_cui_uint32_c(0x037d8f3dul), mk_sl_cui_uint32_c(0xed73d7f9ul), mk_sl_cui_uint32_c(0xb7b2247eul), mk_sl_cui_uint32_c(0x7c6f673cul), mk_sl_cui_uint32_c(0x26ae94bbul), mk_sl_cui_uint32_c(0xc8a0cc7ful), mk_sl_cui_uint32_c(0x92613ff8ul),
			mk_sl_cui_uint32_c(0x87cc2679ul), mk_sl_cui_uint32_c(0xdd0dd5feul), mk_sl_cui_uint32_c(0x33038d3aul), mk_sl_cui_uint32_c(0x69c27ebdul), mk_sl_cui_uint32_c(0xa21f3dfful), mk_sl_cui_uint32_c(0xf8dece78ul), mk_sl_cui_uint32_c(0x16d096bcul), mk_sl_cui_uint32_c(0x4c11653bul), mk_sl_cui_uint32_c(0xcd271038ul), mk_sl_cui_uint32_c(0x97e6e3bful), mk_sl_cui_uint32_c(0x79e8bb7bul), mk_sl_cui_uint32_c(0x232948fcul), mk_sl_cui_uint32_c(0xe8f40bbeul), mk_sl_cui_uint32_c(0xb235f839ul), mk_sl_cui_uint32_c(0x5c3ba0fdul), mk_sl_cui_uint32_c(0x06fa537aul),
			mk_sl_cui_uint32_c(0x762c92b2ul), mk_sl_cui_uint32_c(0x2ced6135ul), mk_sl_cui_uint32_c(0xc2e339f1ul), mk_sl_cui_uint32_c(0x9822ca76ul), mk_sl_cui_uint32_c(0x53ff8934ul), mk_sl_cui_uint32_c(0x093e7ab3ul), mk_sl_cui_uint32_c(0xe7302277ul), mk_sl_cui_uint32_c(0xbdf1d1f0ul), mk_sl_cui_uint32_c(0x3cc7a4f3ul), mk_sl_cui_uint32_c(0x66065774ul), mk_sl_cui_uint32_c(0x88080fb0ul), mk_sl_cui_uint32_c(0xd2c9fc37ul), mk_sl_cui_uint32_c(0x1914bf75ul), mk_sl_cui_uint32_c(0x43d54cf2ul), mk_sl_cui_uint32_c(0xaddb1436ul), mk_sl_cui_uint32_c(0xf71ae7b1ul),
			mk_sl_cui_uint32_c(0xe2b7fe30ul), mk_sl_cui_uint32_c(0xb8760db7ul), mk_sl_cui_uint32_c(0x56785573ul), mk_sl_cui_uint32_c(0x0cb9a6f4ul), mk_sl_cui_uint32_c(0xc764e5b6ul), mk_sl_cui_uint32_c(0x9da51631ul), mk_sl_cui_uint32_c(0x73ab4ef5ul), mk_sl_cui_uint32_c(0x296abd72ul), mk_sl_cui_uint32_c(0xa85cc871ul), mk_sl_cui_uint32_c(0xf29d3bf6ul), mk_sl_cui_uint32_c(0x1c936332ul), mk_sl_cui_uint32_c(0x465290b5ul), mk_sl_cui_uint32_c(0x8d8fd3f7ul), mk_sl_cui_uint32_c(0xd74e2070ul), mk_sl_cui_uint32_c(0x394078b4ul), mk_sl_cui_uint32_c(0x63818b33ul),
	}}},
	{{{
			mk_sl_cui_uint32_c(0x00000000ul), mk_sl_cui_uint32_c(0x58471e5aul), mk_sl_cui_uint32_c(0xb08e3cb4ul), mk_sl_cui_uint32_c(0xe8c922eeul), mk_sl_cui_uint32_c(0x2d517825ul), mk_sl_cui_uint32_c(0x7516667ful), mk_sl_cui_uint32_c(0x9ddf4491ul), mk_sl_cui_uint32_c(0xc5985acbul), mk_sl_cui_uint32_c(0x5aa2f04aul), mk_sl_cui_uint32_c(0x02e5ee10ul), mk_sl_cui_uint32_c(0xea2cccfeul), mk_sl_cui_uint32_c(0xb26bd2a4ul), mk_sl_cui_uint32_c(0x77f3886ful), mk_sl_cui_uint32_c(0x2fb49635ul), mk_sl_cui_uint32_c(0xc77db4dbul), mk_sl_cui_uint32_c(0x9f3aaa81ul),
			mk_sl_cui_uint32_c(0xb409ad94ul), mk_sl_cui_uint32_c(0xec4eb3ceul), mk_sl_cui_uint32_c(0x04879120ul), mk_sl_cui_uint32_c(0x5cc08f7aul), mk_sl_cui_uint32_c(0x9958d5b1ul), mk_sl_cui_uint32_c(0xc11fcbebul), mk_sl_cui_uint32_c(0x29d6e905ul), mk_sl_cui_uint32_c(0x7191f75ful), mk_sl_cui_uint32_c(0xeeab5ddeul), mk_sl_cui_uint32_c(0xb6ec4384ul), mk_sl_cui_uint32_c(0x5e25616aul), mk_sl_cui_uint32_c(0x06627f30ul), mk_sl_cui_uint32_c(0xc3fa25fbul), mk_sl_cui_uint32_c(0x9bbd3ba1ul), mk_sl_cui_uint32_c(0x7374194ful), mk_sl_cui_uint32_c(0x2b330715ul),
			mk_sl_cui_uint32_c(0x25121765ul), mk_sl_cui_uint32_c(0x7d55093ful), mk_sl_cui_uint32_c(0x959c2bd1ul), mk_sl_cui_uint32_c(0xcddb358bul), mk_sl_cui_uint32_c(0x08436f40ul), mk_sl_cui_uint32_c(0x5004711aul), mk_sl_cui_uint32_c(0xb8cd53f4ul), mk_sl_cui_uint32_c(0xe08a4daeul), mk_sl_cui_uint32_c(0x7fb0e72ful), mk_sl_cui_uint32_c(0x27f7f975ul), mk_sl_cui_uint32_c(0xcf3edb9bul), mk_sl_cui_uint32_c(0x9779c5c1ul), mk_sl_cui_uint32_c(0x52e19f0aul), mk_sl_cui_uint32_c(0x0aa68150ul), mk_sl_cui_uint32_c(0xe26fa3beul), mk_sl_cui_uint32_c(0xba28bde4ul),
			mk_sl_cui_uint32_c(0x911bbaf1ul), mk_sl_cui_uint32_c(0xc95ca4abul), mk_sl_cui_uint32_c(0x21958645ul), mk_sl_cui_uint32_c(0x79d2981ful), mk_sl_cui_uint32_c(0xbc4ac2d4ul), mk_sl_cui_uint32_c(0xe40ddc8eul), mk_sl_cui_uint32_c(0x0cc4fe60ul), mk_sl_cui_uint32_c(0x5483e03aul), mk_sl_cui_uint32_c(0xcbb94abbul), mk_sl_cui_uint32_c(0x93fe54e1ul), mk_sl_cui_uint32_c(0x7b37760ful), mk_sl_cui_uint32_c(0x23706855ul), mk_sl_cui_uint32_c(0xe6e8329eul), mk_sl_cui_uint32_c(0xbeaf2cc4ul), mk_sl_cui_uint32_c(0x56660e2aul), mk_sl_cui_uint32_c(0x0e211070ul),
			mk_sl_cui_uint32_c(0x4a242ecaul), mk_sl_cui_uint32_c(0x12633090ul), mk_sl_cui_uint32_c(0xfaaa127eul), mk_sl_cui_uint32_c(0xa2ed0c24ul), mk_sl_cui_uint32_c(0x677556eful), mk_sl_cui_uint32_c(0x3f3248b5ul), mk_sl_cui_uint32_c(0xd7fb6a5bul), mk_sl_cui_uint32_c(0x8fbc7401ul), mk_sl_cui_uint32_c(0x1086de80ul), mk_sl_cui_uint32_c(0x48c1c0daul), mk_sl_cui_uint32_c(0xa008e234ul), mk_sl_cui_uint32_c(0xf84ffc6eul), mk_sl_cui_uint32_c(0x3dd7a6a5ul), mk_sl_cui_uint32_c(0x6590b8fful), mk_sl_cui_uint32_c(0x8d599a11ul), mk_sl_cui_uint32_c(0xd51e844bul),
			mk_sl_cui_uint32_c(0xfe2d835eul), mk_sl_cui_uint32_c(0xa66a9d04ul), mk_sl_cui_uint32_c(0x4ea3bfeaul), mk_sl_cui_uint32_c(0x16e4a1b0ul), mk_sl_cui_uint32_c(0xd37cfb7bul), mk_sl_cui_uint32_c(0x8b3be521ul), mk_sl_cui_uint32_c(0x63f2c7cful), mk_sl_cui_uint32_c(0x3bb5d995ul), mk_sl_cui_uint32_c(0xa48f7314ul), mk_sl_cui_uint32_c(0xfcc86d4eul), mk_sl_cui_uint32_c(0x14014fa0ul), mk_sl_cui_uint32_c(0x4c4651faul), mk_sl_cui_uint32_c(0x89de0b31ul), mk_sl_cui_uint32_c(0xd199156bul), mk_sl_cui_uint32_c(0x39503785ul), mk_sl_cui_uint32_c(0x611729dful),
			mk_sl_cui_uint32_c(0x6f3639aful), mk_sl_cui_uint32_c(0x377127f5ul), mk_sl_cui_uint32_c(0xdfb8051bul), mk_sl_cui_uint32_c(0x87ff1b41ul), mk_sl_cui_uint32_c(0x4267418aul), mk_sl_cui_uint32_c(0x1a205fd0ul), mk_sl_cui_uint32_c(0xf2e97d3eul), mk_sl_cui_uint32_c(0xaaae6364ul), mk_sl_cui_uint32_c(0x3594c9e5ul), mk_sl_cui_uint32_c(0x6dd3d7bful), mk_sl_cui_uint32_c(0x851af551ul), mk_sl_cui_uint32_c(0xdd5deb0bul), mk_sl_cui_uint32_c(0x18c5b1c0ul), mk_sl_cui_uint32_c(0x4082af9aul), mk_sl_cui_uint32_c(0xa84b8d74ul), mk_sl_cui_uint32_c(0xf00c932eul),
			mk_sl_cui_uint32_c(0xdb3f943bul), mk_sl_cui_uint32_c(0x83788a61ul), mk_sl_cui_uint32_c(0x6bb1a88ful), mk_sl_cui_uint32_c(0x33f6b6d5ul), mk_sl_cui_uint32_c(0xf66eec1eul), mk_sl_cui_uint32_c(0xae29f244ul), mk_sl_cui_uint32_c(0x46e0d0aaul), mk_sl_cui_uint32_c(0x1ea7cef0ul), mk_sl_cui_uint32_c(0x819d6471ul), mk_sl_cui_uint32_c(0xd9da7a2bul), mk_sl_cui_uint32_c(0x311358c5ul), mk_sl_cui_uint32_c(0x6954469ful), mk_sl_cui_uint32_c(0xaccc1c54ul), mk_sl_cui_uint32_c(0xf48b020eul), mk_sl_cui_uint32_c(0x1c4220e0ul), mk_sl_cui_uint32_c(0x44053ebaul),
			mk_sl_cui_uint32_c(0x94485cd9ul), mk_sl_cui_uint32_c(0xcc0f4283ul), mk_sl_cui_uint32_c(0x24c6606dul), mk_sl_cui_uint32_c(0x7c817e37ul), mk_sl_cui_uint32_c(0xb91924fcul), mk_sl_cui_uint32_c(0xe15e3aa6ul), mk_sl_cui_uint32_c(0x09971848ul), mk_sl_cui_uint32_c(0x51d00612ul), mk_sl_cui_uint32_c(0xceeaac93ul), mk_sl_cui_uint32_c(0x96adb2c9ul), mk_sl_cui_uint32_c(0x7e649027ul), mk_sl_cui_uint32_c(0x26238e7dul), mk_sl_cui_uint32_c(0xe3bbd4b6ul), mk_sl_cui_uint32_c(0xbbfccaecul), mk_sl_cui_uint32_c(0x5335e802ul), mk_sl_cui_uint32_c(0x0b72f658ul),
			mk_sl_cui_uint32_c(0x2041f14dul), mk_sl_cui_uint32_c(0x7806ef17ul), mk_sl_cui_uint32_c(0x90cfcdf9ul), mk_sl_cui_uint32_c(0xc888d3a3ul), mk_sl_cui_uint32_c(0x0d108968ul), mk_sl_cui_uint32_c(0x55579732ul), mk_sl_cui_uint32_c(0xbd9eb5dcul), mk_sl_cui_uint32_c(0xe5d9ab86ul), mk_sl_cui_uint32_c(0x7ae30107ul), mk_sl_cui_uint32_c(0x22a41f5dul), mk_sl_cui_uint32_c(0xca6d3db3ul), mk_sl_cui_uint32_c(0x922a23e9ul), mk_sl_cui_uint32_c(0x57b27922ul), mk_sl_cui_uint32_c(0x0ff56778ul), mk_sl_cui_uint32_c(0xe73c4596ul), mk_sl_cui_uint32_c(0xbf7b5bccul),
			mk_sl_cui_uint32_c(0xb15a4bbcul), mk_sl_cui_uint32_c(0xe91d55e6ul), mk_sl_cui_uint32_c(0x01d47708ul), mk_sl_cui_uint32_c(0x59936952ul), mk_sl_cui_uint32_c(0x9c0b3399ul), mk_sl_cui_uint32_c(0xc44c2dc3ul), mk_sl_cui_uint32_c(0x2c850f2dul), mk_sl_cui_uint32_c(0x74c21177ul), mk_sl_cui_uint32_c(0xebf8bbf6ul), mk_sl_cui_uint32_c(0xb3bfa5acul), mk_sl_cui_uint32_c(0x5b768742ul), mk_sl_cui_uint32_c(0x03319918ul), mk_sl_cui_uint32_c(0xc6a9c3d3ul), mk_sl_cui_uint32_c(0x9eeedd89ul), mk_sl_cui_uint32_c(0x7627ff67ul), mk_sl_cui_uint32_c(0x2e60e13dul),
			mk_sl_cui_uint32_c(0x0553e628ul), mk_sl_cui_uint32_c(0x5d14f872ul), mk_sl_cui_uint32_c(0xb5ddda9cul), mk_sl_cui_uint32_c(0xed9ac4c6ul), mk_sl_cui_uint32_c(0x28029e0dul), mk_sl_cui_uint32_c(0x70458057ul), mk_sl_cui_uint32_c(0x988ca2b9ul), mk_sl_cui_uint32_c(0xc0cbbce3ul), mk_sl_cui_uint32_c(0x5ff11662ul), mk_sl_cui_uint32_c(0x07b60838ul), mk_sl_cui_uint32_c(0xef7f2ad6ul), mk_sl_cui_uint32_c(0xb738348cul), mk_sl_cui_uint32_c(0x72a06e47ul), mk_sl_cui_uint32_c(0x2ae7701dul), mk_sl_cui_uint32_c(0xc22e52f3ul), mk_sl_cui_uint32_c(0x9a694ca9ul),
			mk_sl_cui_uint32_c(0xde6c7213ul), mk_sl_cui_uint32_c(0x862b6c49ul), mk_sl_cui_uint32_c(0x6ee24ea7ul), mk_sl_cui_uint32_c(0x36a550fdul), mk_sl_cui_uint32_c(0xf33d0a36ul), mk_sl_cui_uint32_c(0xab7a146cul), mk_sl_cui_uint32_c(0x43b33682ul), mk_sl_cui_uint32_c(0x1bf428d8ul), mk_sl_cui_uint32_c(0x84ce8259ul), mk_sl_cui_uint32_c(0xdc899c03ul), mk_sl_cui_uint32_c(0x3440beedul), mk_sl_cui_uint32_c(0x6c07a0b7ul), mk_sl_cui_uint32_c(0xa99ffa7cul), mk_sl_cui_uint32_c(0xf1d8e426ul), mk_sl_cui_uint32_c(0x1911c6c8ul), mk_sl_cui_uint32_c(0x4156d892ul),
			mk_sl_cui_uint32_c(0x6a65df87ul), mk_sl_cui_uint32_c(0x3222c1ddul), mk_sl_cui_uint32_c(0xdaebe333ul), mk_sl_cui_uint32_c(0x82acfd69ul), mk_sl_cui_uint32_c(0x4734a7a2ul), mk_sl_cui_uint32_c(0x1f73b9f8ul), mk_sl_cui_uint32_c(0xf7ba9b16ul), mk_sl_cui_uint32_c(0xaffd854cul), mk_sl_cui_uint32_c(0x30c72fcdul), mk_sl_cui_uint32_c(0x68803197ul), mk_sl_cui_uint32_c(0x80491379ul), mk_sl_cui_uint32_c(0xd80e0d23ul), mk_sl_cui_uint32_c(0x1d9657e8ul), mk_sl_cui_uint32_c(0x45d149b2ul), mk_sl_cui_uint32_c(0xad186b5cul), mk_sl_cui_uint32_c(0xf55f7506ul),
			mk_sl_cui_uint32_c(0xfb7e6576ul), mk_sl_cui_uint32_c(0xa3397b2cul), mk_sl_cui_uint32_c(0x4bf059c2ul), mk_sl_cui_uint32_c(0x13b74798ul), mk_sl_cui_uint32_c(0xd62f1d53ul), mk_sl_cui_uint32_c(0x8e680309ul), mk_sl_cui_uint32_c(0x66a121e7ul), mk_sl_cui_uint32_c(0x3ee63fbdul), mk_sl_cui_uint32_c(0xa1dc953cul), mk_sl_cui_uint32_c(0xf99b8b66ul), mk_sl_cui_uint32_c(0x1152a988ul), mk_sl_cui_uint32_c(0x4915b7d2ul), mk_sl_cui_uint32_c(0x8c8ded19ul), mk_sl_cui_uint32_c(0xd4caf343ul), mk_sl_cui_uint32_c(0x3c03d1adul), mk_sl_cui_uint32_c(0x6444cff7ul),
			mk_sl_cui_uint32_c(0x4f77c8e2ul), mk_sl_cui_uint32_c(0x1730d6b8ul), mk_sl_cui_uint32_c(0xfff9f456ul), mk_sl_cui_uint32_c(0xa7beea0cul), mk_sl_cui_uint32_c(0x6226b0c7ul), mk_sl_cui_uint32_c(0x3a61ae9dul), mk_sl_cui_uint32_c(0xd2a88c73ul), mk_sl_cui_uint32_c(0x8aef9229ul), mk_sl_cui_uint32_c(0x15d538a8ul), mk_sl_cui_uint32_c(0x4d9226f2ul), mk_sl_cui_uint32_c(0xa55b041cul), mk_sl_cui_uint32_c(0xfd1c1a46ul), mk_sl_cui_uint32_c(0x3884408dul), mk_sl_cui_uint32_c(0x60c35ed7ul), mk_sl_cui_uint32_c(0x880a7c39ul), mk_sl_cui_uint32_c(0xd04d6263ul),
	}}},
	{{{
			mk_sl_cui_uint32_c(0x00000000ul), mk_sl_cui_uint32_c(0xdbaec658ul), mk_sl_cui_uint32_c(0xfb11c1b0ul), mk_sl_cui_uint32_c(0x20bf07e8ul), mk_sl_cui_uint32_c(0xbb22cf2dul), mk_sl_cui_uint32_c(0x608c0975ul), mk_sl_cui_uint32_c(0x40330e9dul), mk_sl_cui_uint32_c(0x9b9dc8c5ul), mk_sl_cui_uint32_c(0x3b44d35aul), mk_sl_cui_uint32_c(0xe0ea1502ul), mk_sl_cui_uint32_c(0xc05512eaul), mk_sl_cui_uint32_c(0x1bfbd4b2ul), mk_sl_cui_uint32_c(0x80661c77ul), mk_sl_cui_uint32_c(0x5bc8da2ful), mk_sl_cui_uint32_c(0x7b77ddc7ul), mk_sl_cui_uint32_c(0xa0d91b9ful),
			mk_sl_cui_uint32_c(0x7688ebb4ul), mk_sl_cui_uint32_c(0xad262decul), mk_sl_cui_uint32_c(0x8d992a04ul), mk_sl_cui_uint32_c(0x5637ec5cul), mk_sl_cui_uint32_c(0xcdaa2499ul), mk_sl_cui_uint32_c(0x1604e2c1ul), mk_sl_cui_uint32_c(0x36bbe529ul), mk_sl_cui_uint32_c(0xed152371ul), mk_sl_cui_uint32_c(0x4dcc38eeul), mk_sl_cui_uint32_c(0x9662feb6ul), mk_sl_cui_uint32_c(0xb6ddf95eul), mk_sl_cui_uint32_c(0x6d733f06ul), mk_sl_cui_uint32_c(0xf6eef7c3ul), mk_sl_cui_uint32_c(0x2d40319bul), mk_sl_cui_uint32_c(0x0dff3673ul), mk_sl_cui_uint32_c(0xd651f02bul),
			mk_sl_cui_uint32_c(0xec5d9b25ul), mk_sl_cui_uint32_c(0x37f35d7dul), mk_sl_cui_uint32_c(0x174c5a95ul), mk_sl_cui_uint32_c(0xcce29ccdul), mk_sl_cui_uint32_c(0x577f5408ul), mk_sl_cui_uint32_c(0x8cd19250ul), mk_sl_cui_uint32_c(0xac6e95b8ul), mk_sl_cui_uint32_c(0x77c053e0ul), mk_sl_cui_uint32_c(0xd719487ful), mk_sl_cui_uint32_c(0x0cb78e27ul), mk_sl_cui_uint32_c(0x2c0889cful), mk_sl_cui_uint32_c(0xf7a64f97ul), mk_sl_cui_uint32_c(0x6c3b8752ul), mk_sl_cui_uint32_c(0xb795410aul), mk_sl_cui_uint32_c(0x972a46e2ul), mk_sl_cui_uint32_c(0x4c8480baul),
			mk_sl_cui_uint32_c(0x9ad57091ul), mk_sl_cui_uint32_c(0x417bb6c9ul), mk_sl_cui_uint32_c(0x61c4b121ul), mk_sl_cui_uint32_c(0xba6a7779ul), mk_sl_cui_uint32_c(0x21f7bfbcul), mk_sl_cui_uint32_c(0xfa5979e4ul), mk_sl_cui_uint32_c(0xdae67e0cul), mk_sl_cui_uint32_c(0x0148b854ul), mk_sl_cui_uint32_c(0xa191a3cbul), mk_sl_cui_uint32_c(0x7a3f6593ul), mk_sl_cui_uint32_c(0x5a80627bul), mk_sl_cui_uint32_c(0x812ea423ul), mk_sl_cui_uint32_c(0x1ab36ce6ul), mk_sl_cui_uint32_c(0xc11daabeul), mk_sl_cui_uint32_c(0xe1a2ad56ul), mk_sl_cui_uint32_c(0x3a0c6b0eul),
			mk_sl_cui_uint32_c(0x95ba7b4aul), mk_sl_cui_uint32_c(0x4e14bd12ul), mk_sl_cui_uint32_c(0x6eabbafaul), mk_sl_cui_uint32_c(0xb5057ca2ul), mk_sl_cui_uint32_c(0x2e98b467ul), mk_sl_cui_uint32_c(0xf536723ful), mk_sl_cui_uint32_c(0xd58975d7ul), mk_sl_cui_uint32_c(0x0e27b38ful), mk_sl_cui_uint32_c(0xaefea810ul), mk_sl_cui_uint32_c(0x75506e48ul), mk_sl_cui_uint32_c(0x55ef69a0ul), mk_sl_cui_uint32_c(0x8e41aff8ul), mk_sl_cui_uint32_c(0x15dc673dul), mk_sl_cui_uint32_c(0xce72a165ul), mk_sl_cui_uint32_c(0xeecda68dul), mk_sl_cui_uint32_c(0x356360d5ul),
			mk_sl_cui_uint32_c(0xe33290feul), mk_sl_cui_uint32_c(0x389c56a6ul), mk_sl_cui_uint32_c(0x1823514eul), mk_sl_cui_uint32_c(0xc38d9716ul), mk_sl_cui_uint32_c(0x58105fd3ul), mk_sl_cui_uint32_c(0x83be998bul), mk_sl_cui_uint32_c(0xa3019e63ul), mk_sl_cui_uint32_c(0x78af583bul), mk_sl_cui_uint32_c(0xd87643a4ul), mk_sl_cui_uint32_c(0x03d885fcul), mk_sl_cui_uint32_c(0x23678214ul), mk_sl_cui_uint32_c(0xf8c9444cul), mk_sl_cui_uint32_c(0x63548c89ul), mk_sl_cui_uint32_c(0xb8fa4ad1ul), mk_sl_cui_uint32_c(0x98454d39ul), mk_sl_cui_uint32_c(0x43eb8b61ul),
			mk_sl_cui_uint32_c(0x79e7e06ful), mk_sl_cui_uint32_c(0xa2492637ul), mk_sl_cui_uint32_c(0x82f621dful), mk_sl_cui_uint32_c(0x5958e787ul), mk_sl_cui_uint32_c(0xc2c52f42ul), mk_sl_cui_uint32_c(0x196be91aul), mk_sl_cui_uint32_c(0x39d4eef2ul), mk_sl_cui_uint32_c(0xe27a28aaul), mk_sl_cui_uint32_c(0x42a33335ul), mk_sl_cui_uint32_c(0x990df56dul), mk_sl_cui_uint32_c(0xb9b2f285ul), mk_sl_cui_uint32_c(0x621c34ddul), mk_sl_cui_uint32_c(0xf981fc18ul), mk_sl_cui_uint32_c(0x222f3a40ul), mk_sl_cui_uint32_c(0x02903da8ul), mk_sl_cui_uint32_c(0xd93efbf0ul),
			mk_sl_cui_uint32_c(0x0f6f0bdbul), mk_sl_cui_uint32_c(0xd4c1cd83ul), mk_sl_cui_uint32_c(0xf47eca6bul), mk_sl_cui_uint32_c(0x2fd00c33ul), mk_sl_cui_uint32_c(0xb44dc4f6ul), mk_sl_cui_uint32_c(0x6fe302aeul), mk_sl_cui_uint32_c(0x4f5c0546ul), mk_sl_cui_uint32_c(0x94f2c31eul), mk_sl_cui_uint32_c(0x342bd881ul), mk_sl_cui_uint32_c(0xef851ed9ul), mk_sl_cui_uint32_c(0xcf3a1931ul), mk_sl_cui_uint32_c(0x1494df69ul), mk_sl_cui_uint32_c(0x8f0917acul), mk_sl_cui_uint32_c(0x54a7d1f4ul), mk_sl_cui_uint32_c(0x7418d61cul), mk_sl_cui_uint32_c(0xafb61044ul),
			mk_sl_cui_uint32_c(0x6739f694ul), mk_sl_cui_uint32_c(0xbc9730ccul), mk_sl_cui_uint32_c(0x9c283724ul), mk_sl_cui_uint32_c(0x4786f17cul), mk_sl_cui_uint32_c(0xdc1b39b9ul), mk_sl_cui_uint32_c(0x07b5ffe1ul), mk_sl_cui_uint32_c(0x270af809ul), mk_sl_cui_uint32_c(0xfca43e51ul), mk_sl_cui_uint32_c(0x5c7d25ceul), mk_sl_cui_uint32_c(0x87d3e396ul), mk_sl_cui_uint32_c(0xa76ce47eul), mk_sl_cui_uint32_c(0x7cc22226ul), mk_sl_cui_uint32_c(0xe75feae3ul), mk_sl_cui_uint32_c(0x3cf12cbbul), mk_sl_cui_uint32_c(0x1c4e2b53ul), mk_sl_cui_uint32_c(0xc7e0ed0bul),
			mk_sl_cui_uint32_c(0x11b11d20ul), mk_sl_cui_uint32_c(0xca1fdb78ul), mk_sl_cui_uint32_c(0xeaa0dc90ul), mk_sl_cui_uint32_c(0x310e1ac8ul), mk_sl_cui_uint32_c(0xaa93d20dul), mk_sl_cui_uint32_c(0x713d1455ul), mk_sl_cui_uint32_c(0x518213bdul), mk_sl_cui_uint32_c(0x8a2cd5e5ul), mk_sl_cui_uint32_c(0x2af5ce7aul), mk_sl_cui_uint32_c(0xf15b0822ul), mk_sl_cui_uint32_c(0xd1e40fcaul), mk_sl_cui_uint32_c(0x0a4ac992ul), mk_sl_cui_uint32_c(0x91d70157ul), mk_sl_cui_uint32_c(0x4a79c70ful), mk_sl_cui_uint32_c(0x6ac6c0e7ul), mk_sl_cui_uint32_c(0xb16806bful),
			mk_sl_cui_uint32_c(0x8b646db1ul), mk_sl_cui_uint32_c(0x50caabe9ul), mk_sl_cui_uint32_c(0x7075ac01ul), mk_sl_cui_uint32_c(0xabdb6a59ul), mk_sl_cui_uint32_c(0x3046a29cul), mk_sl_cui_uint32_c(0xebe864c4ul), mk_sl_cui_uint32_c(0xcb57632cul), mk_sl_cui_uint32_c(0x10f9a574ul), mk_sl_cui_uint32_c(0xb020beebul), mk_sl_cui_uint32_c(0x6b8e78b3ul), mk_sl_cui_uint32_c(0x4b317f5bul), mk_sl_cui_uint32_c(0x909fb903ul), mk_sl_cui_uint32_c(0x0b0271c6ul), mk_sl_cui_uint32_c(0xd0acb79eul), mk_sl_cui_uint32_c(0xf013b076ul), mk_sl_cui_uint32_c(0x2bbd762eul),
			mk_sl_cui_uint32_c(0xfdec8605ul), mk_sl_cui_uint32_c(0x2642405dul), mk_sl_cui_uint32_c(0x06fd47b5ul), mk_sl_cui_uint32_c(0xdd5381edul), mk_sl_cui_uint32_c(0x46ce4928ul), mk_sl_cui_uint32_c(0x9d608f70ul), mk_sl_cui_uint32_c(0xbddf8898ul), mk_sl_cui_uint32_c(0x66714ec0ul), mk_sl_cui_uint32_c(0xc6a8555ful), mk_sl_cui_uint32_c(0x1d069307ul), mk_sl_cui_uint32_c(0x3db994eful), mk_sl_cui_uint32_c(0xe61752b7ul), mk_sl_cui_uint32_c(0x7d8a9a72ul), mk_sl_cui_uint32_c(0xa6245c2aul), mk_sl_cui_uint32_c(0x869b5bc2ul), mk_sl_cui_uint32_c(0x5d359d9aul),
			mk_sl_cui_uint32_c(0xf2838ddeul), mk_sl_cui_uint32_c(0x292d4b86ul), mk_sl_cui_uint32_c(0x09924c6eul), mk_sl_cui_uint32_c(0xd23c8a36ul), mk_sl_cui_uint32_c(0x49a142f3ul), mk_sl_cui_uint32_c(0x920f84abul), mk_sl_cui_uint32_c(0xb2b08343ul), mk_sl_cui_uint32_c(0x691e451bul), mk_sl_cui_uint32_c(0xc9c75e84ul), mk_sl_cui_uint32_c(0x126998dcul), mk_sl_cui_uint32_c(0x32d69f34ul), mk_sl_cui_uint32_c(0xe978596cul), mk_sl_cui_uint32_c(0x72e591a9ul), mk_sl_cui_uint32_c(0xa94b57f1ul), mk_sl_cui_uint32_c(0x89f45019ul), mk_sl_cui_uint32_c(0x525a9641ul),
			mk_sl_cui_uint32_c(0x840b666aul), mk_sl_cui_uint32_c(0x5fa5a032ul), mk_sl_cui_uint32_c(0x7f1aa7daul), mk_sl_cui_uint32_c(0xa4b46182ul), mk_sl_cui_uint32_c(0x3f29a947ul), mk_sl_cui_uint32_c(0xe4876f1ful), mk_sl_cui_uint32_c(0xc43868f7ul), mk_sl_cui_uint32_c(0x1f96aeaful), mk_sl_cui_uint32_c(0xbf4fb530ul), mk_sl_cui_uint32_c(0x64e17368ul), mk_sl_cui_uint32_c(0x445e7480ul), mk_sl_cui_uint32_c(0x9ff0b2d8ul), mk_sl_cui_uint32_c(0x046d7a1dul), mk_sl_cui_uint32_c(0xdfc3bc45ul), mk_sl_cui_uint32_c(0xff7cbbadul), mk_sl_cui_uint32_c(0x24d27df5ul),
			mk_sl_cui_uint32_c(0x1ede16fbul), mk_sl_cui_uint32_c(0xc570d0a3ul), mk_sl_cui_uint32_c(0xe5cfd74bul), mk_sl_cui_uint32_c(0x3e611113ul), mk_sl_cui_uint32_c(0xa5fcd9d6ul), mk_sl_cui_uint32_c(0x7e521f8eul), mk_sl_cui_uint32_c(0x5eed1866ul), mk_sl_cui_uint32_c(0x8543de3eul), mk_sl_cui_uint32_c(0x259ac5a1ul), mk_sl_cui_uint32_c(0xfe3403f9ul), mk_sl_cui_uint32_c(0xde8b0411ul), mk_sl_cui_uint32_c(0x0525c249ul), mk_sl_cui_uint32_c(0x9eb80a8cul), mk_sl_cui_uint32_c(0x4516ccd4ul), mk_sl_cui_uint32_c(0x65a9cb3cul), mk_sl_cui_uint32_c(0xbe070d64ul),
			mk_sl_cui_uint32_c(0x6856fd4ful), mk_sl_cui_uint32_c(0xb3f83b17ul), mk_sl_cui_uint32_c(0x93473cfful), mk_sl_cui_uint32_c(0x48e9faa7ul), mk_sl_cui_uint32_c(0xd3743262ul), mk_sl_cui_uint32_c(0x08daf43aul), mk_sl_cui_uint32_c(0x2865f3d2ul), mk_sl_cui_uint32_c(0xf3cb358aul), mk_sl_cui_uint32_c(0x53122e15ul), mk_sl_cui_uint32_c(0x88bce84dul), mk_sl_cui_uint32_c(0xa803efa5ul), mk_sl_cui_uint32_c(0x73ad29fdul), mk_sl_cui_uint32_c(0xe830e138ul), mk_sl_cui_uint32_c(0x339e2760ul), mk_sl_cui_uint32_c(0x13212088ul), mk_sl_cui_uint32_c(0xc88fe6d0ul),
	}}},
	{{{
			mk_sl_cui_uint32_c(0x00000000ul), mk_sl_cui_uint32_c(0x9e3d68dbul), mk_sl_cui_uint32_c(0x717ad0fbul), mk_sl_cui_uint32_c(0xef47b820ul), mk_sl_cui_uint32_c(0xe2f4edbbul), mk_sl_cui_uint32_c(0x7cc98560ul), mk_sl_cui_uint32_c(0x938e3d40ul), mk_sl_cui_uint32_c(0x0db3559bul), mk_sl_cui_uint32_c(0x89a5973bul), mk_sl_cui_uint32_c(0x1798ffe0ul), mk_sl_cui_uint32_c(0xf8df47c0ul), mk_sl_cui_uint32_c(0x66e22f1bul), mk_sl_cui_uint32_c(0x6b517a80ul), mk_sl_cui_uint32_c(0xf56c125bul), mk_sl_cui_uint32_c(0x1a2baa7bul), mk_sl_cui_uint32_c(0x8416c2a0ul),
			mk_sl_cui_uint32_c(0x5f076376ul), mk_sl_cui_uint32_c(0xc13a0badul), mk_sl_cui_uint32_c(0x2e7db38dul), mk_sl_cui_uint32_c(0xb040db56ul), mk_sl_cui_uint32_c(0xbdf38ecdul), mk_sl_cui_uint32_c(0x23cee616ul), mk_sl_cui_uint32_c(0xcc895e36ul), mk_sl_cui_uint32_c(0x52b436edul), mk_sl_cui_uint32_c(0xd6a2f44dul), mk_sl_cui_uint32_c(0x489f9c96ul), mk_sl_cui_uint32_c(0xa7d824b6ul), mk_sl_cui_uint32_c(0x39e54c6dul), mk_sl_cui_uint32_c(0x345619f6ul), mk_sl_cui_uint32_c(0xaa6b712dul), mk_sl_cui_uint32_c(0x452cc90dul), mk_sl_cui_uint32_c(0xdb11a1d6ul),
			mk_sl_cui_uint32_c(0xbe0ec6ecul), mk_sl_cui_uint32_c(0x2033ae37ul), mk_sl_cui_uint32_c(0xcf741617ul), mk_sl_cui_uint32_c(0x51497eccul), mk_sl_cui_uint32_c(0x5cfa2b57ul), mk_sl_cui_uint32_c(0xc2c7438cul), mk_sl_cui_uint32_c(0x2d80fbacul), mk_sl_cui_uint32_c(0xb3bd9377ul), mk_sl_cui_uint32_c(0x37ab51d7ul), mk_sl_cui_uint32_c(0xa996390cul), mk_sl_cui_uint32_c(0x46d1812cul), mk_sl_cui_uint32_c(0xd8ece9f7ul), mk_sl_cui_uint32_c(0xd55fbc6cul), mk_sl_cui_uint32_c(0x4b62d4b7ul), mk_sl_cui_uint32_c(0xa4256c97ul), mk_sl_cui_uint32_c(0x3a18044cul),
			mk_sl_cui_uint32_c(0xe109a59aul), mk_sl_cui_uint32_c(0x7f34cd41ul), mk_sl_cui_uint32_c(0x90737561ul), mk_sl_cui_uint32_c(0x0e4e1dbaul), mk_sl_cui_uint32_c(0x03fd4821ul), mk_sl_cui_uint32_c(0x9dc020faul), mk_sl_cui_uint32_c(0x728798daul), mk_sl_cui_uint32_c(0xecbaf001ul), mk_sl_cui_uint32_c(0x68ac32a1ul), mk_sl_cui_uint32_c(0xf6915a7aul), mk_sl_cui_uint32_c(0x19d6e25aul), mk_sl_cui_uint32_c(0x87eb8a81ul), mk_sl_cui_uint32_c(0x8a58df1aul), mk_sl_cui_uint32_c(0x1465b7c1ul), mk_sl_cui_uint32_c(0xfb220fe1ul), mk_sl_cui_uint32_c(0x651f673aul),
			mk_sl_cui_uint32_c(0x311cc195ul), mk_sl_cui_uint32_c(0xaf21a94eul), mk_sl_cui_uint32_c(0x4066116eul), mk_sl_cui_uint32_c(0xde5b79b5ul), mk_sl_cui_uint32_c(0xd3e82c2eul), mk_sl_cui_uint32_c(0x4dd544f5ul), mk_sl_cui_uint32_c(0xa292fcd5ul), mk_sl_cui_uint32_c(0x3caf940eul), mk_sl_cui_uint32_c(0xb8b956aeul), mk_sl_cui_uint32_c(0x26843e75ul), mk_sl_cui_uint32_c(0xc9c38655ul), mk_sl_cui_uint32_c(0x57feee8eul), mk_sl_cui_uint32_c(0x5a4dbb15ul), mk_sl_cui_uint32_c(0xc470d3ceul), mk_sl_cui_uint32_c(0x2b376beeul), mk_sl_cui_uint32_c(0xb50a0335ul),
			mk_sl_cui_uint32_c(0x6e1ba2e3ul), mk_sl_cui_uint32_c(0xf026ca38ul), mk_sl_cui_uint32_c(0x1f617218ul), mk_sl_cui_uint32_c(0x815c1ac3ul), mk_sl_cui_uint32_c(0x8cef4f58ul), mk_sl_cui_uint32_c(0x12d22783ul), mk_sl_cui_uint32_c(0xfd959fa3ul), mk_sl_cui_uint32_c(0x63a8f778ul), mk_sl_cui_uint32_c(0xe7be35d8ul), mk_sl_cui_uint32_c(0x79835d03ul), mk_sl_cui_uint32_c(0x96c4e523ul), mk_sl_cui_uint32_c(0x08f98df8ul), mk_sl_cui_uint32_c(0x054ad863ul), mk_sl_cui_uint32_c(0x9b77b0b8ul), mk_sl_cui_uint32_c(0x74300898ul), mk_sl_cui_uint32_c(0xea0d6043ul),
			mk_sl_cui_uint32_c(0x8f120779ul), mk_sl_cui_uint32_c(0x112f6fa2ul), mk_sl_cui_uint32_c(0xfe68d782ul), mk_sl_cui_uint32_c(0x6055bf59ul), mk_sl_cui_uint32_c(0x6de6eac2ul), mk_sl_cui_uint32_c(0xf3db8219ul), mk_sl_cui_uint32_c(0x1c9c3a39ul), mk_sl_cui_uint32_c(0x82a152e2ul), mk_sl_cui_uint32_c(0x06b79042ul), mk_sl_cui_uint32_c(0x988af899ul), mk_sl_cui_uint32_c(0x77cd40b9ul), mk_sl_cui_uint32_c(0xe9f02862ul), mk_sl_cui_uint32_c(0xe4437df9ul), mk_sl_cui_uint32_c(0x7a7e1522ul), mk_sl_cui_uint32_c(0x9539ad02ul), mk_sl_cui_uint32_c(0x0b04c5d9ul),
			mk_sl_cui_uint32_c(0xd015640ful), mk_sl_cui_uint32_c(0x4e280cd4ul), mk_sl_cui_uint32_c(0xa16fb4f4ul), mk_sl_cui_uint32_c(0x3f52dc2ful), mk_sl_cui_uint32_c(0x32e189b4ul), mk_sl_cui_uint32_c(0xacdce16ful), mk_sl_cui_uint32_c(0x439b594ful), mk_sl_cui_uint32_c(0xdda63194ul), mk_sl_cui_uint32_c(0x59b0f334ul), mk_sl_cui_uint32_c(0xc78d9beful), mk_sl_cui_uint32_c(0x28ca23cful), mk_sl_cui_uint32_c(0xb6f74b14ul), mk_sl_cui_uint32_c(0xbb441e8ful), mk_sl_cui_uint32_c(0x25797654ul), mk_sl_cui_uint32_c(0xca3ece74ul), mk_sl_cui_uint32_c(0x5403a6aful),
			mk_sl_cui_uint32_c(0x6238cf67ul), mk_sl_cui_uint32_c(0xfc05a7bcul), mk_sl_cui_uint32_c(0x13421f9cul), mk_sl_cui_uint32_c(0x8d7f7747ul), mk_sl_cui_uint32_c(0x80cc22dcul), mk_sl_cui_uint32_c(0x1ef14a07ul), mk_sl_cui_uint32_c(0xf1b6f227ul), mk_sl_cui_uint32_c(0x6f8b9afcul), mk_sl_cui_uint32_c(0xeb9d585cul), mk_sl_cui_uint32_c(0x75a03087ul), mk_sl_cui_uint32_c(0x9ae788a7ul), mk_sl_cui_uint32_c(0x04dae07cul), mk_sl_cui_uint32_c(0x0969b5e7ul), mk_sl_cui_uint32_c(0x9754dd3cul), mk_sl_cui_uint32_c(0x7813651cul), mk_sl_cui_uint32_c(0xe62e0dc7ul),
			mk_sl_cui_uint32_c(0x3d3fac11ul), mk_sl_cui_uint32_c(0xa302c4caul), mk_sl_cui_uint32_c(0x4c457ceaul), mk_sl_cui_uint32_c(0xd2781431ul), mk_sl_cui_uint32_c(0xdfcb41aaul), mk_sl_cui_uint32_c(0x41f62971ul), mk_sl_cui_uint32_c(0xaeb19151ul), mk_sl_cui_uint32_c(0x308cf98aul), mk_sl_cui_uint32_c(0xb49a3b2aul), mk_sl_cui_uint32_c(0x2aa753f1ul), mk_sl_cui_uint32_c(0xc5e0ebd1ul), mk_sl_cui_uint32_c(0x5bdd830aul), mk_sl_cui_uint32_c(0x566ed691ul), mk_sl_cui_uint32_c(0xc853be4aul), mk_sl_cui_uint32_c(0x2714066aul), mk_sl_cui_uint32_c(0xb9296eb1ul),
			mk_sl_cui_uint32_c(0xdc36098bul), mk_sl_cui_uint32_c(0x420b6150ul), mk_sl_cui_uint32_c(0xad4cd970ul), mk_sl_cui_uint32_c(0x3371b1abul), mk_sl_cui_uint32_c(0x3ec2e430ul), mk_sl_cui_uint32_c(0xa0ff8cebul), mk_sl_cui_uint32_c(0x4fb834cbul), mk_sl_cui_uint32_c(0xd1855c10ul), mk_sl_cui_uint32_c(0x55939eb0ul), mk_sl_cui_uint32_c(0xcbaef66bul), mk_sl_cui_uint32_c(0x24e94e4bul), mk_sl_cui_uint32_c(0xbad42690ul), mk_sl_cui_uint32_c(0xb767730bul), mk_sl_cui_uint32_c(0x295a1bd0ul), mk_sl_cui_uint32_c(0xc61da3f0ul), mk_sl_cui_uint32_c(0x5820cb2bul),
			mk_sl_cui_uint32_c(0x83316afdul), mk_sl_cui_uint32_c(0x1d0c0226ul), mk_sl_cui_uint32_c(0xf24bba06ul), mk_sl_cui_uint32_c(0x6c76d2ddul), mk_sl_cui_uint32_c(0x61c58746ul), mk_sl_cui_uint32_c(0xfff8ef9dul), mk_sl_cui_uint32_c(0x10bf57bdul), mk_sl_cui_uint32_c(0x8e823f66ul), mk_sl_cui_uint32_c(0x0a94fdc6ul), mk_sl_cui_uint32_c(0x94a9951dul), mk_sl_cui_uint32_c(0x7bee2d3dul), mk_sl_cui_uint32_c(0xe5d345e6ul), mk_sl_cui_uint32_c(0xe860107dul), mk_sl_cui_uint32_c(0x765d78a6ul), mk_sl_cui_uint32_c(0x991ac086ul), mk_sl_cui_uint32_c(0x0727a85dul),
			mk_sl_cui_uint32_c(0x53240ef2ul), mk_sl_cui_uint32_c(0xcd196629ul), mk_sl_cui_uint32_c(0x225ede09ul), mk_sl_cui_uint32_c(0xbc63b6d2ul), mk_sl_cui_uint32_c(0xb1d0e349ul), mk_sl_cui_uint32_c(0x2fed8b92ul), mk_sl_cui_uint32_c(0xc0aa33b2ul), mk_sl_cui_uint32_c(0x5e975b69ul), mk_sl_cui_uint32_c(0xda8199c9ul), mk_sl_cui_uint32_c(0x44bcf112ul), mk_sl_cui_uint32_c(0xabfb4932ul), mk_sl_cui_uint32_c(0x35c621e9ul), mk_sl_cui_uint32_c(0x38757472ul), mk_sl_cui_uint32_c(0xa6481ca9ul), mk_sl_cui_uint32_c(0x490fa489ul), mk_sl_cui_uint32_c(0xd732cc52ul),
			mk_sl_cui_uint32_c(0x0c236d84ul), mk_sl_cui_uint32_c(0x921e055ful), mk_sl_cui_uint32_c(0x7d59bd7ful), mk_sl_cui_uint32_c(0xe364d5a4ul), mk_sl_cui_uint32_c(0xeed7803ful), mk_sl_cui_uint32_c(0x70eae8e4ul), mk_sl_cui_uint32_c(0x9fad50c4ul), mk_sl_cui_uint32_c(0x0190381ful), mk_sl_cui_uint32_c(0x8586fabful), mk_sl_cui_uint32_c(0x1bbb9264ul), mk_sl_cui_uint32_c(0xf4fc2a44ul), mk_sl_cui_uint32_c(0x6ac1429ful), mk_sl_cui_uint32_c(0x67721704ul), mk_sl_cui_uint32_c(0xf94f7fdful), mk_sl_cui_uint32_c(0x1608c7fful), mk_sl_cui_uint32_c(0x8835af24ul),
			mk_sl_cui_uint32_c(0xed2ac81eul), mk_sl_cui_uint32_c(0x7317a0c5ul), mk_sl_cui_uint32_c(0x9c5018e5ul), mk_sl_cui_uint32_c(0x026d703eul), mk_sl_cui_uint32_c(0x0fde25a5ul), mk_sl_cui_uint32_c(0x91e34d7eul), mk_sl_cui_uint32_c(0x7ea4f55eul), mk_sl_cui_uint32_c(0xe0999d85ul), mk_sl_cui_uint32_c(0x648f5f25ul), mk_sl_cui_uint32_c(0xfab237feul), mk_sl_cui_uint32_c(0x15f58fdeul), mk_sl_cui_uint32_c(0x8bc8e705ul), mk_sl_cui_uint32_c(0x867bb29eul), mk_sl_cui_uint32_c(0x1846da45ul), mk_sl_cui_uint32_c(0xf7016265ul), mk_sl_cui_uint32_c(0x693c0abeul),
			mk_sl_cui_uint32_c(0xb22dab68ul), mk_sl_cui_uint32_c(0x2c10c3b3ul), mk_sl_cui_uint32_c(0xc3577b93ul), mk_sl_cui_uint32_c(0x5d6a1348ul), mk_sl_cui_uint32_c(0x50d946d3ul), mk_sl_cui_uint32_c(0xcee42e08ul), mk_sl_cui_uint32_c(0x21a39628ul), mk_sl_cui_uint32_c(0xbf9efef3ul), mk_sl_cui_uint32_c(0x3b883c53ul), mk_sl_cui_uint32_c(0xa5b55488ul), mk_sl_cui_uint32_c(0x4af2eca8ul), mk_sl_cui_uint32_c(0xd4cf8473ul), mk_sl_cui_uint32_c(0xd97cd1e8ul), mk_sl_cui_uint32_c(0x4741b933ul), mk_sl_cui_uint32_c(0xa8060113ul), mk_sl_cui_uint32_c(0x363b69c8ul),
	}}},
	{{{
			mk_sl_cui_uint32_c(0x00000000ul), mk_sl_cui_uint32_c(0x0319e59eul), mk_sl_cui_uint32_c(0x06328771ul), mk_sl_cui_uint32_c(0x052b62eful), mk_sl_cui_uint32_c(0x0c6443e2ul), mk_sl_cui_uint32_c(0x0f7da67cul), mk_sl_cui_uint32_c(0x0a56c493ul), mk_sl_cui_uint32_c(0x094f210dul), mk_sl_cui_uint32_c(0x18c88689ul), mk_sl_cui_uint32_c(0x1bd16317ul), mk_sl_cui_uint32_c(0x1efa01f8ul), mk_sl_cui_uint32_c(0x1de3e466ul), mk_sl_cui_uint32_c(0x14acc56bul), mk_sl_cui_uint32_c(0x17b520f5ul), mk_sl_cui_uint32_c(0x129e421aul), mk_sl_cui_uint32_c(0x1187a784ul),
			mk_sl_cui_uint32_c(0x30dd415ful), mk_sl_cui_uint32_c(0x33c4a4c1ul), mk_sl_cui_uint32_c(0x36efc62eul), mk_sl_cui_uint32_c(0x35f623b0ul), mk_sl_cui_uint32_c(0x3cb902bdul), mk_sl_cui_uint32_c(0x3fa0e723ul), mk_sl_cui_uint32_c(0x3a8b85ccul), mk_sl_cui_uint32_c(0x39926052ul), mk_sl_cui_uint32_c(0x2815c7d6ul), mk_sl_cui_uint32_c(0x2b0c2248ul), mk_sl_cui_uint32_c(0x2e2740a7ul), mk_sl_cui_uint32_c(0x2d3ea539ul), mk_sl_cui_uint32_c(0x24718434ul), mk_sl_cui_uint32_c(0x276861aaul), mk_sl_cui_uint32_c(0x22430345ul), mk_sl_cui_uint32_c(0x215ae6dbul),
			mk_sl_cui_uint32_c(0x60f782beul), mk_sl_cui_uint32_c(0x63ee6720ul), mk_sl_cui_uint32_c(0x66c505cful), mk_sl_cui_uint32_c(0x65dce051ul), mk_sl_cui_uint32_c(0x6c93c15cul), mk_sl_cui_uint32_c(0x6f8a24c2ul), mk_sl_cui_uint32_c(0x6aa1462dul), mk_sl_cui_uint32_c(0x69b8a3b3ul), mk_sl_cui_uint32_c(0x783f0437ul), mk_sl_cui_uint32_c(0x7b26e1a9ul), mk_sl_cui_uint32_c(0x7e0d8346ul), mk_sl_cui_uint32_c(0x7d1466d8ul), mk_sl_cui_uint32_c(0x745b47d5ul), mk_sl_cui_uint32_c(0x7742a24bul), mk_sl_cui_uint32_c(0x7269c0a4ul), mk_sl_cui_uint32_c(0x7170253aul),
			mk_sl_cui_uint32_c(0x502ac3e1ul), mk_sl_cui_uint32_c(0x5333267ful), mk_sl_cui_uint32_c(0x56184490ul), mk_sl_cui_uint32_c(0x5501a10eul), mk_sl_cui_uint32_c(0x5c4e8003ul), mk_sl_cui_uint32_c(0x5f57659dul), mk_sl_cui_uint32_c(0x5a7c0772ul), mk_sl_cui_uint32_c(0x5965e2ecul), mk_sl_cui_uint32_c(0x48e24568ul), mk_sl_cui_uint32_c(0x4bfba0f6ul), mk_sl_cui_uint32_c(0x4ed0c219ul), mk_sl_cui_uint32_c(0x4dc92787ul), mk_sl_cui_uint32_c(0x4486068aul), mk_sl_cui_uint32_c(0x479fe314ul), mk_sl_cui_uint32_c(0x42b481fbul), mk_sl_cui_uint32_c(0x41ad6465ul),
			mk_sl_cui_uint32_c(0xc0a34931ul), mk_sl_cui_uint32_c(0xc3baacaful), mk_sl_cui_uint32_c(0xc691ce40ul), mk_sl_cui_uint32_c(0xc5882bdeul), mk_sl_cui_uint32_c(0xccc70ad3ul), mk_sl_cui_uint32_c(0xcfdeef4dul), mk_sl_cui_uint32_c(0xcaf58da2ul), mk_sl_cui_uint32_c(0xc9ec683cul), mk_sl_cui_uint32_c(0xd86bcfb8ul), mk_sl_cui_uint32_c(0xdb722a26ul), mk_sl_cui_uint32_c(0xde5948c9ul), mk_sl_cui_uint32_c(0xdd40ad57ul), mk_sl_cui_uint32_c(0xd40f8c5aul), mk_sl_cui_uint32_c(0xd71669c4ul), mk_sl_cui_uint32_c(0xd23d0b2bul), mk_sl_cui_uint32_c(0xd124eeb5ul),
			mk_sl_cui_uint32_c(0xf07e086eul), mk_sl_cui_uint32_c(0xf367edf0ul), mk_sl_cui_uint32_c(0xf64c8f1ful), mk_sl_cui_uint32_c(0xf5556a81ul), mk_sl_cui_uint32_c(0xfc1a4b8cul), mk_sl_cui_uint32_c(0xff03ae12ul), mk_sl_cui_uint32_c(0xfa28ccfdul), mk_sl_cui_uint32_c(0xf9312963ul), mk_sl_cui_uint32_c(0xe8b68ee7ul), mk_sl_cui_uint32_c(0xebaf6b79ul), mk_sl_cui_uint32_c(0xee840996ul), mk_sl_cui_uint32_c(0xed9dec08ul), mk_sl_cui_uint32_c(0xe4d2cd05ul), mk_sl_cui_uint32_c(0xe7cb289bul), mk_sl_cui_uint32_c(0xe2e04a74ul), mk_sl_cui_uint32_c(0xe1f9afeaul),
			mk_sl_cui_uint32_c(0xa054cb8ful), mk_sl_cui_uint32_c(0xa34d2e11ul), mk_sl_cui_uint32_c(0xa6664cfeul), mk_sl_cui_uint32_c(0xa57fa960ul), mk_sl_cui_uint32_c(0xac30886dul), mk_sl_cui_uint32_c(0xaf296df3ul), mk_sl_cui_uint32_c(0xaa020f1cul), mk_sl_cui_uint32_c(0xa91bea82ul), mk_sl_cui_uint32_c(0xb89c4d06ul), mk_sl_cui_uint32_c(0xbb85a898ul), mk_sl_cui_uint32_c(0xbeaeca77ul), mk_sl_cui_uint32_c(0xbdb72fe9ul), mk_sl_cui_uint32_c(0xb4f80ee4ul), mk_sl_cui_uint32_c(0xb7e1eb7aul), mk_sl_cui_uint32_c(0xb2ca8995ul), mk_sl_cui_uint32_c(0xb1d36c0bul),
			mk_sl_cui_uint32_c(0x90898ad0ul), mk_sl_cui_uint32_c(0x93906f4eul), mk_sl_cui_uint32_c(0x96bb0da1ul), mk_sl_cui_uint32_c(0x95a2e83ful), mk_sl_cui_uint32_c(0x9cedc932ul), mk_sl_cui_uint32_c(0x9ff42cacul), mk_sl_cui_uint32_c(0x9adf4e43ul), mk_sl_cui_uint32_c(0x99c6abddul), mk_sl_cui_uint32_c(0x88410c59ul), mk_sl_cui_uint32_c(0x8b58e9c7ul), mk_sl_cui_uint32_c(0x8e738b28ul), mk_sl_cui_uint32_c(0x8d6a6eb6ul), mk_sl_cui_uint32_c(0x84254fbbul), mk_sl_cui_uint32_c(0x873caa25ul), mk_sl_cui_uint32_c(0x8217c8caul), mk_sl_cui_uint32_c(0x810e2d54ul),
			mk_sl_cui_uint32_c(0xcd0b9262ul), mk_sl_cui_uint32_c(0xce1277fcul), mk_sl_cui_uint32_c(0xcb391513ul), mk_sl_cui_uint32_c(0xc820f08dul), mk_sl_cui_uint32_c(0xc16fd180ul), mk_sl_cui_uint32_c(0xc276341eul), mk_sl_cui_uint32_c(0xc75d56f1ul), mk_sl_cui_uint32_c(0xc444b36ful), mk_sl_cui_uint32_c(0xd5c314ebul), mk_sl_cui_uint32_c(0xd6daf175ul), mk_sl_cui_uint32_c(0xd3f1939aul), mk_sl_cui_uint32_c(0xd0e87604ul), mk_sl_cui_uint32_c(0xd9a75709ul), mk_sl_cui_uint32_c(0xdabeb297ul), mk_sl_cui_uint32_c(0xdf95d078ul), mk_sl_cui_uint32_c(0xdc8c35e6ul),
			mk_sl_cui_uint32_c(0xfdd6d33dul), mk_sl_cui_uint32_c(0xfecf36a3ul), mk_sl_cui_uint32_c(0xfbe4544cul), mk_sl_cui_uint32_c(0xf8fdb1d2ul), mk_sl_cui_uint32_c(0xf1b290dful), mk_sl_cui_uint32_c(0xf2ab7541ul), mk_sl_cui_uint32_c(0xf78017aeul), mk_sl_cui_uint32_c(0xf499f230ul), mk_sl_cui_uint32_c(0xe51e55b4ul), mk_sl_cui_uint32_c(0xe607b02aul), mk_sl_cui_uint32_c(0xe32cd2c5ul), mk_sl_cui_uint32_c(0xe035375bul), mk_sl_cui_uint32_c(0xe97a1656ul), mk_sl_cui_uint32_c(0xea63f3c8ul), mk_sl_cui_uint32_c(0xef489127ul), mk_sl_cui_uint32_c(0xec5174b9ul),
			mk_sl_cui_uint32_c(0xadfc10dcul), mk_sl_cui_uint32_c(0xaee5f542ul), mk_sl_cui_uint32_c(0xabce97adul), mk_sl_cui_uint32_c(0xa8d77233ul), mk_sl_cui_uint32_c(0xa198533eul), mk_sl_cui_uint32_c(0xa281b6a0ul), mk_sl_cui_uint32_c(0xa7aad44ful), mk_sl_cui_uint32_c(0xa4b331d1ul), mk_sl_cui_uint32_c(0xb5349655ul), mk_sl_cui_uint32_c(0xb62d73cbul), mk_sl_cui_uint32_c(0xb3061124ul), mk_sl_cui_uint32_c(0xb01ff4baul), mk_sl_cui_uint32_c(0xb950d5b7ul), mk_sl_cui_uint32_c(0xba493029ul), mk_sl_cui_uint32_c(0xbf6252c6ul), mk_sl_cui_uint32_c(0xbc7bb758ul),
			mk_sl_cui_uint32_c(0x9d215183ul), mk_sl_cui_uint32_c(0x9e38b41dul), mk_sl_cui_uint32_c(0x9b13d6f2ul), mk_sl_cui_uint32_c(0x980a336cul), mk_sl_cui_uint32_c(0x91451261ul), mk_sl_cui_uint32_c(0x925cf7fful), mk_sl_cui_uint32_c(0x97779510ul), mk_sl_cui_uint32_c(0x946e708eul), mk_sl_cui_uint32_c(0x85e9d70aul), mk_sl_cui_uint32_c(0x86f03294ul), mk_sl_cui_uint32_c(0x83db507bul), mk_sl_cui_uint32_c(0x80c2b5e5ul), mk_sl_cui_uint32_c(0x898d94e8ul), mk_sl_cui_uint32_c(0x8a947176ul), mk_sl_cui_uint32_c(0x8fbf1399ul), mk_sl_cui_uint32_c(0x8ca6f607ul),
			mk_sl_cui_uint32_c(0x0da8db53ul), mk_sl_cui_uint32_c(0x0eb13ecdul), mk_sl_cui_uint32_c(0x0b9a5c22ul), mk_sl_cui_uint32_c(0x0883b9bcul), mk_sl_cui_uint32_c(0x01cc98b1ul), mk_sl_cui_uint32_c(0x02d57d2ful), mk_sl_cui_uint32_c(0x07fe1fc0ul), mk_sl_cui_uint32_c(0x04e7fa5eul), mk_sl_cui_uint32_c(0x15605ddaul), mk_sl_cui_uint32_c(0x1679b844ul), mk_sl_cui_uint32_c(0x1352daabul), mk_sl_cui_uint32_c(0x104b3f35ul), mk_sl_cui_uint32_c(0x19041e38ul), mk_sl_cui_uint32_c(0x1a1dfba6ul), mk_sl_cui_uint32_c(0x1f369949ul), mk_sl_cui_uint32_c(0x1c2f7cd7ul),
			mk_sl_cui_uint32_c(0x3d759a0cul), mk_sl_cui_uint32_c(0x3e6c7f92ul), mk_sl_cui_uint32_c(0x3b471d7dul), mk_sl_cui_uint32_c(0x385ef8e3ul), mk_sl_cui_uint32_c(0x3111d9eeul), mk_sl_cui_uint32_c(0x32083c70ul), mk_sl_cui_uint32_c(0x37235e9ful), mk_sl_cui_uint32_c(0x343abb01ul), mk_sl_cui_uint32_c(0x25bd1c85ul), mk_sl_cui_uint32_c(0x26a4f91bul), mk_sl_cui_uint32_c(0x238f9bf4ul), mk_sl_cui_uint32_c(0x20967e6aul), mk_sl_cui_uint32_c(0x29d95f67ul), mk_sl_cui_uint32_c(0x2ac0baf9ul), mk_sl_cui_uint32_c(0x2febd816ul), mk_sl_cui_uint32_c(0x2cf23d88ul),
			mk_sl_cui_uint32_c(0x6d5f59edul), mk_sl_cui_uint32_c(0x6e46bc73ul), mk_sl_cui_uint32_c(0x6b6dde9cul), mk_sl_cui_uint32_c(0x68743b02ul), mk_sl_cui_uint32_c(0x613b1a0ful), mk_sl_cui_uint32_c(0x6222ff91ul), mk_sl_cui_uint32_c(0x67099d7eul), mk_sl_cui_uint32_c(0x641078e0ul), mk_sl_cui_uint32_c(0x7597df64ul), mk_sl_cui_uint32_c(0x768e3afaul), mk_sl_cui_uint32_c(0x73a55815ul), mk_sl_cui_uint32_c(0x70bcbd8bul), mk_sl_cui_uint32_c(0x79f39c86ul), mk_sl_cui_uint32_c(0x7aea7918ul), mk_sl_cui_uint32_c(0x7fc11bf7ul), mk_sl_cui_uint32_c(0x7cd8fe69ul),
			mk_sl_cui_uint32_c(0x5d8218b2ul), mk_sl_cui_uint32_c(0x5e9bfd2cul), mk_sl_cui_uint32_c(0x5bb09fc3ul), mk_sl_cui_uint32_c(0x58a97a5dul), mk_sl_cui_uint32_c(0x51e65b50ul), mk_sl_cui_uint32_c(0x52ffbeceul), mk_sl_cui_uint32_c(0x57d4dc21ul), mk_sl_cui_uint32_c(0x54cd39bful), mk_sl_cui_uint32_c(0x454a9e3bul), mk_sl_cui_uint32_c(0x46537ba5ul), mk_sl_cui_uint32_c(0x4378194aul), mk_sl_cui_uint32_c(0x4061fcd4ul), mk_sl_cui_uint32_c(0x492eddd9ul), mk_sl_cui_uint32_c(0x4a373847ul), mk_sl_cui_uint32_c(0x4f1c5aa8ul), mk_sl_cui_uint32_c(0x4c05bf36ul),
	}}},
}}};


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_rnd_t(mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pct const schedule, mk_sl_cui_uint32_prct const xa, mk_sl_cui_uint32_prct const xb, mk_lang_types_sint_t const ir, mk_sl_cui_uint32_prt const fa, mk_sl_cui_uint32_prt const fb) mk_lang_noexcept
{
	mk_lib_crypto_alg_twofish_base_inl_defd_uint328_data_t tu mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuca mk_lang_constexpr_init;
	mk_lang_types_uchar_t tucb mk_lang_constexpr_init;
	mk_lang_types_uchar_t tucc mk_lang_constexpr_init;
	mk_lang_types_uchar_t tucd mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tfa mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tfb mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(xa);
	mk_lang_assert(xb);
	mk_lang_assert(ir >= 0 && ir < mk_lib_crypto_alg_twofish_base_inl_defd_nr);
	mk_lang_assert(fa);
	mk_lang_assert(fb);
	mk_lang_assert(xa != xb);
	mk_lang_assert(xa != fa);
	mk_lang_assert(xa != fb);
	mk_lang_assert(xb != fa);
	mk_lang_assert(xb != fb);
	mk_lang_assert(fa != fb);

	mk_sl_uint_32_to_8_le(xa, &tu.m_uint8s[0]);
	mk_sl_cui_uint8_to_bi_uchar(&tu.m_uint8s[0], &tuca);
	mk_sl_cui_uint8_to_bi_uchar(&tu.m_uint8s[1], &tucb);
	mk_sl_cui_uint8_to_bi_uchar(&tu.m_uint8s[2], &tucc);
	mk_sl_cui_uint8_to_bi_uchar(&tu.m_uint8s[3], &tucd);
	mk_sl_cui_uint32_xor3(&schedule->m_data.m_rks_sboxs.m_sboxs.m_sboxs[0].m_uint32s[tuca], &schedule->m_data.m_rks_sboxs.m_sboxs.m_sboxs[1].m_uint32s[tucb], &ta);
	mk_sl_cui_uint32_xor3(&schedule->m_data.m_rks_sboxs.m_sboxs.m_sboxs[2].m_uint32s[tucc], &schedule->m_data.m_rks_sboxs.m_sboxs.m_sboxs[3].m_uint32s[tucd], &tb);
	mk_sl_cui_uint32_xor3(&ta, &tb, &tfa);
	mk_sl_uint_32_to_8_le(xb, &tu.m_uint8s[0]);
	mk_sl_cui_uint8_to_bi_uchar(&tu.m_uint8s[0], &tuca);
	mk_sl_cui_uint8_to_bi_uchar(&tu.m_uint8s[1], &tucb);
	mk_sl_cui_uint8_to_bi_uchar(&tu.m_uint8s[2], &tucc);
	mk_sl_cui_uint8_to_bi_uchar(&tu.m_uint8s[3], &tucd);
	mk_sl_cui_uint32_xor3(&schedule->m_data.m_rks_sboxs.m_sboxs.m_sboxs[0].m_uint32s[tucd], &schedule->m_data.m_rks_sboxs.m_sboxs.m_sboxs[1].m_uint32s[tuca], &ta);
	mk_sl_cui_uint32_xor3(&schedule->m_data.m_rks_sboxs.m_sboxs.m_sboxs[2].m_uint32s[tucb], &schedule->m_data.m_rks_sboxs.m_sboxs.m_sboxs[3].m_uint32s[tucc], &tb);
	mk_sl_cui_uint32_xor3(&ta, &tb, &tfb);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&tfa, &tfb);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&tfb, &tfa);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&tfb, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[2 * ir + 9]);
	mk_sl_cui_uint32_add2_wrap_cid_cod(&tfa, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[2 * ir + 8]);
	*fa = tfa;
	*fb = tfb;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_rnd_enc_a(mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pct const schedule, mk_sl_cui_uint32_prct const xa, mk_sl_cui_uint32_prct const xb, mk_sl_cui_uint32_prt const xc, mk_sl_cui_uint32_prt const xd, mk_lang_types_sint_t const ir) mk_lang_noexcept
{
	mk_sl_cui_uint32_t fa mk_lang_constexpr_init;
	mk_sl_cui_uint32_t fb mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(xa);
	mk_lang_assert(xb);
	mk_lang_assert(xc);
	mk_lang_assert(xd);
	mk_lang_assert(ir >= 0 && ir < mk_lib_crypto_alg_twofish_base_inl_defd_nr);
	mk_lang_assert(xa != xb);
	mk_lang_assert(xa != xc);
	mk_lang_assert(xa != xd);
	mk_lang_assert(xb != xc);
	mk_lang_assert(xb != xd);
	mk_lang_assert(xc != xd);

	mk_lib_crypto_alg_twofish_base_inl_defd_rnd_t(schedule, xa, xb, ir, &fa, &fb);
	mk_sl_cui_uint32_xor2(&fa, xc);
	mk_sl_cui_uint32_rotr3(&fa, 1, xc);
	mk_sl_cui_uint32_rotl3(xd, 1, &fa);
	mk_sl_cui_uint32_xor3(&fa, &fb, xd);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_rnd_enc_b(mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pct const schedule, mk_sl_cui_uint32_prt const xa, mk_sl_cui_uint32_prt const xb, mk_sl_cui_uint32_prct const xc, mk_sl_cui_uint32_prct const xd, mk_lang_types_sint_t const ir) mk_lang_noexcept
{
	mk_sl_cui_uint32_t fa mk_lang_constexpr_init;
	mk_sl_cui_uint32_t fb mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(xa);
	mk_lang_assert(xb);
	mk_lang_assert(xc);
	mk_lang_assert(xd);
	mk_lang_assert(ir >= 0 && ir < mk_lib_crypto_alg_twofish_base_inl_defd_nr);
	mk_lang_assert(xa != xb);
	mk_lang_assert(xa != xc);
	mk_lang_assert(xa != xd);
	mk_lang_assert(xb != xc);
	mk_lang_assert(xb != xd);
	mk_lang_assert(xc != xd);

	mk_lib_crypto_alg_twofish_base_inl_defd_rnd_t(schedule, xc, xd, ir, &fa, &fb);
	mk_sl_cui_uint32_xor2(&fa, xa);
	mk_sl_cui_uint32_rotr3(&fa, 1, xa);
	mk_sl_cui_uint32_rotl3(xb, 1, &fa);
	mk_sl_cui_uint32_xor3(&fa, &fb, xb);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_rnd_dec_a(mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pct const schedule, mk_sl_cui_uint32_prct const xa, mk_sl_cui_uint32_prct const xb, mk_sl_cui_uint32_prt const xc, mk_sl_cui_uint32_prt const xd, mk_lang_types_sint_t const ir) mk_lang_noexcept
{
	mk_sl_cui_uint32_t fa mk_lang_constexpr_init;
	mk_sl_cui_uint32_t fb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(xa);
	mk_lang_assert(xb);
	mk_lang_assert(xc);
	mk_lang_assert(xd);
	mk_lang_assert(ir >= 0 && ir < mk_lib_crypto_alg_twofish_base_inl_defd_nr);
	mk_lang_assert(xa != xb);
	mk_lang_assert(xa != xc);
	mk_lang_assert(xa != xd);
	mk_lang_assert(xb != xc);
	mk_lang_assert(xb != xd);
	mk_lang_assert(xc != xd);

	mk_lib_crypto_alg_twofish_base_inl_defd_rnd_t(schedule, xa, xb, ir, &fa, &fb);
	mk_sl_cui_uint32_rotl3(xc, 1, &ta);
	mk_sl_cui_uint32_xor3(&ta, &fa, xc);
	mk_sl_cui_uint32_xor2(&fb, xd);
	mk_sl_cui_uint32_rotr3(&fb, 1, xd);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_rnd_dec_b(mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pct const schedule, mk_sl_cui_uint32_prt const xa, mk_sl_cui_uint32_prt const xb, mk_sl_cui_uint32_prct const xc, mk_sl_cui_uint32_prct const xd, mk_lang_types_sint_t const ir) mk_lang_noexcept
{
	mk_sl_cui_uint32_t fa mk_lang_constexpr_init;
	mk_sl_cui_uint32_t fb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(xa);
	mk_lang_assert(xb);
	mk_lang_assert(xc);
	mk_lang_assert(xd);
	mk_lang_assert(ir >= 0 && ir < mk_lib_crypto_alg_twofish_base_inl_defd_nr);
	mk_lang_assert(xa != xb);
	mk_lang_assert(xa != xc);
	mk_lang_assert(xa != xd);
	mk_lang_assert(xb != xc);
	mk_lang_assert(xb != xd);
	mk_lang_assert(xc != xd);

	mk_lib_crypto_alg_twofish_base_inl_defd_rnd_t(schedule, xc, xd, ir, &fa, &fb);
	mk_sl_cui_uint32_rotl3(xa, 1, &ta);
	mk_sl_cui_uint32_xor3(&ta, &fa, xa);
	mk_sl_cui_uint32_xor2(&fb, xb);
	mk_sl_cui_uint32_rotr3(&fb, 1, xb);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_one_enc(mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_twofish_base_inl_defd_msg_pct const input, mk_lib_crypto_alg_twofish_base_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_sl_cui_uint32_t xa mk_lang_constexpr_init;
	mk_sl_cui_uint32_t xb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t xc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t xd mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_crypto_alg_twofish_base_inl_defd_nr % 2 == 0);

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_sl_uint_32_from_8_le(&xa, &input->m_data.m_uint8s[0 * 4]);
	mk_sl_uint_32_from_8_le(&xb, &input->m_data.m_uint8s[1 * 4]);
	mk_sl_uint_32_from_8_le(&xc, &input->m_data.m_uint8s[2 * 4]);
	mk_sl_uint_32_from_8_le(&xd, &input->m_data.m_uint8s[3 * 4]);
	mk_sl_cui_uint32_xor2(&xa, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[0]);
	mk_sl_cui_uint32_xor2(&xb, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[1]);
	mk_sl_cui_uint32_xor2(&xc, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[2]);
	mk_sl_cui_uint32_xor2(&xd, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[3]);
	n = mk_lib_crypto_alg_twofish_base_inl_defd_nr / 2;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_alg_twofish_base_inl_defd_rnd_enc_a(schedule, &xa, &xb, &xc, &xd, 2 * i + 0);
		mk_lib_crypto_alg_twofish_base_inl_defd_rnd_enc_b(schedule, &xa, &xb, &xc, &xd, 2 * i + 1);
	}
	mk_sl_cui_uint32_xor2(&xc, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[4]);
	mk_sl_cui_uint32_xor2(&xd, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[5]);
	mk_sl_cui_uint32_xor2(&xa, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[6]);
	mk_sl_cui_uint32_xor2(&xb, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[7]);
	mk_sl_uint_32_to_8_le(&xc, &output->m_data.m_uint8s[0 * 4]);
	mk_sl_uint_32_to_8_le(&xd, &output->m_data.m_uint8s[1 * 4]);
	mk_sl_uint_32_to_8_le(&xa, &output->m_data.m_uint8s[2 * 4]);
	mk_sl_uint_32_to_8_le(&xb, &output->m_data.m_uint8s[3 * 4]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_one_dec(mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_twofish_base_inl_defd_msg_pct const input, mk_lib_crypto_alg_twofish_base_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_sl_cui_uint32_t xa mk_lang_constexpr_init;
	mk_sl_cui_uint32_t xb mk_lang_constexpr_init;
	mk_sl_cui_uint32_t xc mk_lang_constexpr_init;
	mk_sl_cui_uint32_t xd mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_crypto_alg_twofish_base_inl_defd_nr % 2 == 0);

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_sl_uint_32_from_8_le(&xa, &input->m_data.m_uint8s[0 * 4]);
	mk_sl_uint_32_from_8_le(&xb, &input->m_data.m_uint8s[1 * 4]);
	mk_sl_uint_32_from_8_le(&xc, &input->m_data.m_uint8s[2 * 4]);
	mk_sl_uint_32_from_8_le(&xd, &input->m_data.m_uint8s[3 * 4]);
	mk_sl_cui_uint32_xor2(&xa, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[4]);
	mk_sl_cui_uint32_xor2(&xb, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[5]);
	mk_sl_cui_uint32_xor2(&xc, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[6]);
	mk_sl_cui_uint32_xor2(&xd, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[7]);
	n = mk_lib_crypto_alg_twofish_base_inl_defd_nr / 2;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_alg_twofish_base_inl_defd_rnd_dec_a(schedule, &xa, &xb, &xc, &xd, (2 * n - 1) - (2 * i + 0));
		mk_lib_crypto_alg_twofish_base_inl_defd_rnd_dec_b(schedule, &xa, &xb, &xc, &xd, (2 * n - 1) - (2 * i + 1));
	}
	mk_sl_cui_uint32_xor2(&xc, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[0]);
	mk_sl_cui_uint32_xor2(&xd, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[1]);
	mk_sl_cui_uint32_xor2(&xa, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[2]);
	mk_sl_cui_uint32_xor2(&xb, &schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[3]);
	mk_sl_uint_32_to_8_le(&xc, &output->m_data.m_uint8s[0 * 4]);
	mk_sl_uint_32_to_8_le(&xd, &output->m_data.m_uint8s[1 * 4]);
	mk_sl_uint_32_to_8_le(&xa, &output->m_data.m_uint8s[2 * 4]);
	mk_sl_uint_32_to_8_le(&xb, &output->m_data.m_uint8s[3 * 4]);
}

#if mk_lib_crypto_alg_twofish_base_inl_defd_keylen == 128 || 1
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_expand_128(mk_lib_crypto_alg_twofish_base_inl_defd_key_pct const key, mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lib_crypto_alg_twofish_base_inl_defd_uint328_data_t ts[mk_lib_crypto_alg_twofish_base_inl_filec_sbox_words] mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_uchar_t tucs[8] mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32s[mk_lang_countof(tucs) / 2] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint32_pct ptu32s[mk_lang_countof(mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables)] mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t a mk_lang_constexpr_init;
	mk_sl_cui_uint32_t b mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	n = mk_lang_countof(ts);
	for(i = 0; i != n; ++i)
	{
		m = mk_lang_countof(tucs);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_to_bi_uchar(&key->m_data.m_uint8s[i * m + j], &tucs[j]);
		}
		m = mk_lang_countof(tu32s);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint32_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs.m_data.m_tables[j * 2 + 0].m_data.m_uint32s[tucs[2 * j + 0]], &mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs.m_data.m_tables[j * 2 + 1].m_data.m_uint32s[tucs[2 * j + 1]], &tu32s[j]);
		}
		m = mk_lang_countof(tu32s) / 2;
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint32_xor2(&tu32s[2 * j + 0], &tu32s[2 * j + 1]);
		}
		mk_sl_cui_uint32_xor2(&tu32s[2 * 0], &tu32s[2 * 1]);
		mk_sl_uint_32_to_8_le(&tu32s[2 * 0], &ts[i].m_uint8s[0]);
	}
	n = mk_lang_countof(schedule->m_data.m_rks_sboxs.m_sboxs.m_sboxs[0].m_uint32s);
	for(i = 0; i != n; ++i)
	{
		m = mk_lang_countof(mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[j        & 0x1].m_data.m_uint8s[  i], &ts[(0 * 4 + j) / mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes].m_uint8s[(0 * 4 + j) % mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(j >> 1) & 0x1].m_data.m_uint8s[tsi], &ts[(1 * 4 + j) / mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes].m_uint8s[(1 * 4 + j) % mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			schedule->m_data.m_rks_sboxs.m_sboxs.m_sboxs[j].m_uint32s[i] = mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables[j].m_data.m_uint32s[tsi];
		}
	}
	n = mk_lang_countof(schedule->m_data.m_rks_sboxs.m_rks.m_uint32s) / 2;
	for(i = 0; i != n; ++i)
	{
		m = mk_lang_countof(mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[j        & 0x1].m_data.m_uint8s[2 * i + 0], &key->m_data.m_uint8s[2 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(j >> 1) & 0x1].m_data.m_uint8s[      tsi], &key->m_data.m_uint8s[0 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			ptu32s[j] = &mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables[j].m_data.m_uint32s[tsi];
		}
		mk_sl_cui_uint32_xor3(ptu32s[0], ptu32s[1], &ta);
		mk_sl_cui_uint32_xor3(ptu32s[2], ptu32s[3], &a);
		mk_sl_cui_uint32_xor2(&a, &ta);
		m = mk_lang_countof(mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[j        & 0x1].m_data.m_uint8s[2 * i + 1], &key->m_data.m_uint8s[3 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(j >> 1) & 0x1].m_data.m_uint8s[      tsi], &key->m_data.m_uint8s[1 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			ptu32s[j] = &mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables[j].m_data.m_uint32s[tsi];
		}
		mk_sl_cui_uint32_xor3(ptu32s[0], ptu32s[1], &ta);
		mk_sl_cui_uint32_xor3(ptu32s[2], ptu32s[3], &b);
		mk_sl_cui_uint32_xor2(&b, &ta);
		mk_sl_cui_uint32_rotl2(&b, 8);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&a, &b);
		schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[2 * i + 0] = a;
		mk_sl_cui_uint32_add2_wrap_cid_cod(&a, &b);
		mk_sl_cui_uint32_rotl2(&a, 9);
		schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[2 * i + 1] = a;
	}
}
#endif

#if mk_lib_crypto_alg_twofish_base_inl_defd_keylen == 192
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_expand_192(mk_lib_crypto_alg_twofish_base_inl_defd_key_pct const key, mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lib_crypto_alg_twofish_base_inl_defd_uint328_data_t ts[mk_lib_crypto_alg_twofish_base_inl_filec_sbox_words] mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_uchar_t tucs[8] mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32s[mk_lang_countof(tucs) / 2] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint32_pct ptu32s[mk_lang_countof(mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables)] mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t a mk_lang_constexpr_init;
	mk_sl_cui_uint32_t b mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	n = mk_lang_countof(ts);
	for(i = 0; i != n; ++i)
	{
		m = mk_lang_countof(tucs);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_to_bi_uchar(&key->m_data.m_uint8s[i * m + j], &tucs[j]);
		}
		m = mk_lang_countof(tu32s);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint32_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs.m_data.m_tables[j * 2 + 0].m_data.m_uint32s[tucs[2 * j + 0]], &mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs.m_data.m_tables[j * 2 + 1].m_data.m_uint32s[tucs[2 * j + 1]], &tu32s[j]);
		}
		m = mk_lang_countof(tu32s) / 2;
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint32_xor2(&tu32s[2 * j + 0], &tu32s[2 * j + 1]);
		}
		mk_sl_cui_uint32_xor2(&tu32s[2 * 0], &tu32s[2 * 1]);
		mk_sl_uint_32_to_8_le(&tu32s[2 * 0], &ts[i].m_uint8s[0]);
	}
	n = mk_lang_countof(schedule->m_data.m_rks_sboxs.m_sboxs.m_sboxs[0].m_uint32s);
	for(i = 0; i != n; ++i)
	{
		m = mk_lang_countof(mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(((j >> 1) & 0x1) ^ 0x1) & 0x1].m_data.m_uint8s[  i], &ts[(0 * 4 + j) / mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes].m_uint8s[(0 * 4 + j) % mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[j                        & 0x1].m_data.m_uint8s[tsi], &ts[(1 * 4 + j) / mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes].m_uint8s[(1 * 4 + j) % mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(j >> 1)                 & 0x1].m_data.m_uint8s[tsi], &ts[(2 * 4 + j) / mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes].m_uint8s[(2 * 4 + j) % mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			schedule->m_data.m_rks_sboxs.m_sboxs.m_sboxs[j].m_uint32s[i] = mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables[j].m_data.m_uint32s[tsi];
		}
	}
	n = mk_lang_countof(schedule->m_data.m_rks_sboxs.m_rks.m_uint32s) / 2;
	for(i = 0; i != n; ++i)
	{
		m = mk_lang_countof(mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(((j >> 1) & 0x1) ^ 0x1) & 0x1].m_data.m_uint8s[2 * i + 0], &key->m_data.m_uint8s[4 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[j                        & 0x1].m_data.m_uint8s[      tsi], &key->m_data.m_uint8s[2 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(j >> 1)                 & 0x1].m_data.m_uint8s[      tsi], &key->m_data.m_uint8s[0 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			ptu32s[j] = &mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables[j].m_data.m_uint32s[tsi];
		}
		mk_sl_cui_uint32_xor3(ptu32s[0], ptu32s[1], &ta);
		mk_sl_cui_uint32_xor3(ptu32s[2], ptu32s[3], &a);
		mk_sl_cui_uint32_xor2(&a, &ta);
		m = mk_lang_countof(mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(((j >> 1) & 0x1) ^ 0x1) & 0x1].m_data.m_uint8s[2 * i + 1], &key->m_data.m_uint8s[5 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[j                        & 0x1].m_data.m_uint8s[      tsi], &key->m_data.m_uint8s[3 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(j >> 1)                 & 0x1].m_data.m_uint8s[      tsi], &key->m_data.m_uint8s[1 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			ptu32s[j] = &mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables[j].m_data.m_uint32s[tsi];
		}
		mk_sl_cui_uint32_xor3(ptu32s[0], ptu32s[1], &ta);
		mk_sl_cui_uint32_xor3(ptu32s[2], ptu32s[3], &b);
		mk_sl_cui_uint32_xor2(&b, &ta);
		mk_sl_cui_uint32_rotl2(&b, 8);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&a, &b);
		schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[2 * i + 0] = a;
		mk_sl_cui_uint32_add2_wrap_cid_cod(&a, &b);
		mk_sl_cui_uint32_rotl2(&a, 9);
		schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[2 * i + 1] = a;
	}
}
#endif

#if mk_lib_crypto_alg_twofish_base_inl_defd_keylen == 256
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_expand_256(mk_lib_crypto_alg_twofish_base_inl_defd_key_pct const key, mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lib_crypto_alg_twofish_base_inl_defd_uint328_data_t ts[mk_lib_crypto_alg_twofish_base_inl_filec_sbox_words] mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_uchar_t tucs[8] mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32s[mk_lang_countof(tucs) / 2] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint32_pct ptu32s[mk_lang_countof(mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables)] mk_lang_constexpr_init;
	mk_sl_cui_uint32_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint32_t a mk_lang_constexpr_init;
	mk_sl_cui_uint32_t b mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	n = mk_lang_countof(ts);
	for(i = 0; i != n; ++i)
	{
		m = mk_lang_countof(tucs);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_to_bi_uchar(&key->m_data.m_uint8s[i * m + j], &tucs[j]);
		}
		m = mk_lang_countof(tu32s);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint32_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs.m_data.m_tables[j * 2 + 0].m_data.m_uint32s[tucs[2 * j + 0]], &mk_lib_crypto_alg_twofish_base_inl_defd_tables_rs.m_data.m_tables[j * 2 + 1].m_data.m_uint32s[tucs[2 * j + 1]], &tu32s[j]);
		}
		m = mk_lang_countof(tu32s) / 2;
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint32_xor2(&tu32s[2 * j + 0], &tu32s[2 * j + 1]);
		}
		mk_sl_cui_uint32_xor2(&tu32s[2 * 0], &tu32s[2 * 1]);
		mk_sl_uint_32_to_8_le(&tu32s[2 * 0], &ts[i].m_uint8s[0]);
	}
	n = mk_lang_countof(schedule->m_data.m_rks_sboxs.m_sboxs.m_sboxs[0].m_uint32s);
	for(i = 0; i != n; ++i)
	{
		m = mk_lang_countof(mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[((((j >> 0) & 0x1) ^ ((j >> 1) & 0x1)) ^ 0x1) & 0x1].m_data.m_uint8s[  i], &ts[(0 * 4 + j) / mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes].m_uint8s[(0 * 4 + j) % mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(((j >> 1) & 0x1) ^ 0x1)                      & 0x1].m_data.m_uint8s[tsi], &ts[(1 * 4 + j) / mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes].m_uint8s[(1 * 4 + j) % mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[j                                             & 0x1].m_data.m_uint8s[tsi], &ts[(2 * 4 + j) / mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes].m_uint8s[(2 * 4 + j) % mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(j >> 1)                                      & 0x1].m_data.m_uint8s[tsi], &ts[(3 * 4 + j) / mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes].m_uint8s[(3 * 4 + j) % mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			schedule->m_data.m_rks_sboxs.m_sboxs.m_sboxs[j].m_uint32s[i] = mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables[j].m_data.m_uint32s[tsi];
		}
	}
	n = mk_lang_countof(schedule->m_data.m_rks_sboxs.m_rks.m_uint32s) / 2;
	for(i = 0; i != n; ++i)
	{
		m = mk_lang_countof(mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[((((j >> 0) & 0x1) ^ ((j >> 1) & 0x1)) ^ 0x1) & 0x1].m_data.m_uint8s[2 * i + 0], &key->m_data.m_uint8s[6 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(((j >> 1) & 0x1) ^ 0x1)                      & 0x1].m_data.m_uint8s[      tsi], &key->m_data.m_uint8s[4 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[j                                             & 0x1].m_data.m_uint8s[      tsi], &key->m_data.m_uint8s[2 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(j >> 1)                                      & 0x1].m_data.m_uint8s[      tsi], &key->m_data.m_uint8s[0 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			ptu32s[j] = &mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables[j].m_data.m_uint32s[tsi];
		}
		mk_sl_cui_uint32_xor3(ptu32s[0], ptu32s[1], &ta);
		mk_sl_cui_uint32_xor3(ptu32s[2], ptu32s[3], &a);
		mk_sl_cui_uint32_xor2(&a, &ta);
		m = mk_lang_countof(mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[((((j >> 0) & 0x1) ^ ((j >> 1) & 0x1)) ^ 0x1) & 0x1].m_data.m_uint8s[2 * i + 1], &key->m_data.m_uint8s[7 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(((j >> 1) & 0x1) ^ 0x1)                      & 0x1].m_data.m_uint8s[      tsi], &key->m_data.m_uint8s[5 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[j                                             & 0x1].m_data.m_uint8s[      tsi], &key->m_data.m_uint8s[3 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			mk_sl_cui_uint8_xor3(&mk_lib_crypto_alg_twofish_base_inl_defd_tables_q.m_data.m_tables[(j >> 1)                                      & 0x1].m_data.m_uint8s[      tsi], &key->m_data.m_uint8s[1 * 4 + j], &tu8); mk_sl_cui_uint8_to_bi_sint(&tu8, &tsi);
			ptu32s[j] = &mk_lib_crypto_alg_twofish_base_inl_defd_tables_mdsq.m_data.m_tables[j].m_data.m_uint32s[tsi];
		}
		mk_sl_cui_uint32_xor3(ptu32s[0], ptu32s[1], &ta);
		mk_sl_cui_uint32_xor3(ptu32s[2], ptu32s[3], &b);
		mk_sl_cui_uint32_xor2(&b, &ta);
		mk_sl_cui_uint32_rotl2(&b, 8);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&a, &b);
		schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[2 * i + 0] = a;
		mk_sl_cui_uint32_add2_wrap_cid_cod(&a, &b);
		mk_sl_cui_uint32_rotl2(&a, 9);
		schedule->m_data.m_rks_sboxs.m_rks.m_uint32s[2 * i + 1] = a;
	}
}
#endif

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_expand(mk_lib_crypto_alg_twofish_base_inl_defd_key_pct const key, mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
#if mk_lib_crypto_alg_twofish_base_inl_defd_keylen == 128
	mk_lib_crypto_alg_twofish_base_inl_defd_expand_128(key, schedule);
#elif mk_lib_crypto_alg_twofish_base_inl_defd_keylen == 192
	mk_lib_crypto_alg_twofish_base_inl_defd_expand_192(key, schedule);
#elif mk_lib_crypto_alg_twofish_base_inl_defd_keylen == 256
	mk_lib_crypto_alg_twofish_base_inl_defd_expand_256(key, schedule);
#else
#error xxxxxxxxxx
#endif
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_schedule_encrypt(mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_twofish_base_inl_defd_msg_pct const input, mk_lib_crypto_alg_twofish_base_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
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
		mk_lib_crypto_alg_twofish_base_inl_defd_one_enc(schedule, &input[i], &output[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_schedule_decrypt(mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pct const schedule, mk_lib_crypto_alg_twofish_base_inl_defd_msg_pct const input, mk_lib_crypto_alg_twofish_base_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
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
		mk_lib_crypto_alg_twofish_base_inl_defd_one_dec(schedule, &input[i], &output[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_expand_enc(mk_lib_crypto_alg_twofish_base_inl_defd_key_pct const key, mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_twofish_base_inl_defd_expand(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_expand_dec(mk_lib_crypto_alg_twofish_base_inl_defd_key_pct const key, mk_lib_crypto_alg_twofish_base_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_alg_twofish_base_inl_defd_expand(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_encrypt(mk_lib_crypto_alg_twofish_base_inl_defd_key_pct const key, mk_lib_crypto_alg_twofish_base_inl_defd_msg_pct const input, mk_lib_crypto_alg_twofish_base_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_twofish_base_inl_defd_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_twofish_base_inl_defd_expand_enc(key, &schedule);
	mk_lib_crypto_alg_twofish_base_inl_defd_schedule_encrypt(&schedule, input, output, 1);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_twofish_base_inl_defd_decrypt(mk_lib_crypto_alg_twofish_base_inl_defd_key_pct const key, mk_lib_crypto_alg_twofish_base_inl_defd_msg_pct const input, mk_lib_crypto_alg_twofish_base_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_twofish_base_inl_defd_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_twofish_base_inl_defd_expand_dec(key, &schedule);
	mk_lib_crypto_alg_twofish_base_inl_defd_schedule_decrypt(&schedule, input, output, 1);
}


#undef mk_lib_crypto_alg_twofish_base_inl_filec_word_bytes
#undef mk_lib_crypto_alg_twofish_base_inl_filec_key_words
#undef mk_lib_crypto_alg_twofish_base_inl_filec_msg_words
#undef mk_lib_crypto_alg_twofish_base_inl_filec_sbox_words


#include "mk_lib_crypto_alg_twofish_base_inl_defu.h"


#undef mk_lib_crypto_alg_twofish_base_t_name
#undef mk_lib_crypto_alg_twofish_base_t_keylen
