#include "mk_lib_vc_test.hpp"
#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_crash.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr.hpp"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_lib_vc_test_data.h"
#include "mk_sl_uint8.h"

#define mk_lang_memcpy_obj_tn mk_lib_vc_test
#define mk_lang_memcpy_obj_t mk_sl_cui_uint8_t
#include "mk_lang_memcpy_obj_inl_fileh.h"
#include "mk_lang_memcpy_obj_inl_filec.h"


struct mk_lib_vc_test_reader_s
{
	mk_sl_cui_uint8_pct m_data;
	mk_lang_types_usize_t m_size;
	mk_lang_types_usize_t m_cursor;
};
typedef struct mk_lib_vc_test_reader_s mk_lib_vc_test_reader_t;
typedef mk_lib_vc_test_reader_t const mk_lib_vc_test_reader_ct;
typedef mk_lib_vc_test_reader_t* mk_lib_vc_test_reader_pt;
typedef mk_lib_vc_test_reader_t const* mk_lib_vc_test_reader_pct;

typedef mk_lang_types_sint_t(*mk_lib_vc_test_reader_seek_pt)(mk_lib_vc_test_reader_pt, mk_lang_types_ulong_t);
typedef mk_lang_types_usize_t(*mk_lib_vc_test_reader_read_pt)(mk_lib_vc_test_reader_pt, mk_lang_types_usize_t, mk_sl_cui_uint8_pt);

struct mk_lib_vc_test_writer_s
{
	mk_lib_crypto_hash_stream_sha1_t m_hasher;
};
typedef struct mk_lib_vc_test_writer_s mk_lib_vc_test_writer_t;
typedef mk_lib_vc_test_writer_t const mk_lib_vc_test_writer_ct;
typedef mk_lib_vc_test_writer_t* mk_lib_vc_test_writer_pt;
typedef mk_lib_vc_test_writer_t const* mk_lib_vc_test_writer_pct;

typedef mk_lang_types_usize_t(*mk_lib_vc_test_writer_write_pt)(mk_lib_vc_test_writer_pt, mk_lang_types_usize_t, mk_sl_cui_uint8_pct);


mk_lang_constexpr static mk_lang_inline void mk_lib_vc_test_reader_construct(mk_lib_vc_test_reader_pt const reader, mk_sl_cui_uint8_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_assert(reader);
	mk_lang_assert(data || size == 0);

	reader->m_data = data;
	reader->m_size = size;
	reader->m_cursor = 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_vc_test_reader_seek(mk_lib_vc_test_reader_pt const reader, mk_lang_types_ulong_t const pos) mk_lang_noexcept
{
	mk_lang_assert(reader);

	reader->m_cursor = ((mk_lang_types_usize_t)(pos));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_usize_t mk_lib_vc_test_reader_read(mk_lib_vc_test_reader_pt const reader, mk_lang_types_usize_t const size, mk_sl_cui_uint8_pt const dst) mk_lang_noexcept
{
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t to_read mk_lang_constexpr_init;

	mk_lang_assert(reader);
	mk_lang_assert(dst);

	rem = reader->m_size - reader->m_cursor;
	to_read = mk_lang_min(rem, size);
	mk_lang_memcpy_obj_mk_lib_vc_test(dst, reader->m_data + reader->m_cursor, to_read);
	reader->m_cursor += to_read;
	return to_read;
}

mk_lang_constexpr static mk_lang_inline void mk_lib_vc_test_writer_construct(mk_lib_vc_test_writer_pt const writer) mk_lang_noexcept
{
	mk_lang_assert(writer);

	mk_lib_crypto_hash_stream_sha1_init(&writer->m_hasher);
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_usize_t mk_lib_vc_test_writer_write(mk_lib_vc_test_writer_pt const writer, mk_lang_types_usize_t const size, mk_sl_cui_uint8_pct const src) mk_lang_noexcept
{
	mk_lang_assert(writer);
	mk_lang_assert(src);

	mk_lib_crypto_hash_stream_sha1_append_u8(&writer->m_hasher, src, size);
	return size;
}


#define mk_lib_vc_t_name tested
#define mk_lib_vc_t_reader mk_lib_vc_test_reader
#define mk_lib_vc_t_writer mk_lib_vc_test_writer
#include "mk_lib_vc_inl_fileh.h"
#include "mk_lib_vc_inl_filec.h"


#define test(x) do{ if(!(x)){ mk_lang_unlikely mk_lang_crash(); } }while(0)


#define mk_lib_vc_test_password "abc"
#define mk_lib_vc_test_password_len ((mk_lang_types_sint_t)(sizeof(mk_lib_vc_test_password) / sizeof(mk_lib_vc_test_password[0]) - 1))
#define mk_lib_vc_test_pim 1234
#define mk_lib_vc_test_digest "5fc788b6f0623fed6dbf80073715e6b5c367b16d"


mk_lang_constexpr static mk_lang_inline void mk_lib_vc_test_get_digest(mk_lib_crypto_hash_block_sha1_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_vc_test_reader_t reader mk_lang_constexpr_init;
	mk_lib_vc_test_writer_t writer mk_lang_constexpr_init;
	mk_lib_vc_test_reader_pt reader_ctx mk_lang_constexpr_init;
	mk_lib_vc_test_reader_seek_pt reader_seek mk_lang_constexpr_init;
	mk_lib_vc_test_reader_read_pt reader_read mk_lang_constexpr_init;
	mk_sl_cui_uint8_t password[mk_lib_vc_test_password_len] mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_vc_test_writer_pt writer_ctx mk_lang_constexpr_init;
	mk_lib_vc_test_writer_write_pt writer_write mk_lang_constexpr_init;

	mk_lang_assert(digest);

	mk_lib_vc_test_reader_construct(&reader, &s_mk_lib_vc_test_data_tiny.m_data.m_uint8s[0], mk_lib_vc_test_data_tiny_size);
	mk_lib_vc_test_writer_construct(&writer);
	reader_ctx = &reader;
	reader_seek = &mk_lib_vc_test_reader_seek;
	reader_read = &mk_lib_vc_test_reader_read;
	for(i = 0; i != mk_lib_vc_test_password_len; ++i){ mk_sl_cui_uint8_from_bi_pchar(&password[i], &mk_lib_vc_test_password[i]); }
	writer_ctx = &writer;
	writer_write = &mk_lib_vc_test_writer_write;
	mk_lib_vc_tested_decrypt(reader_ctx, reader_seek, reader_read, &password[0], mk_lib_vc_test_password_len, mk_lib_vc_test_pim, mk_lang_null, mk_lang_null, writer_ctx, writer_write);
	mk_lib_crypto_hash_stream_sha1_finish(&writer.m_hasher, digest);
}

#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline auto mk_lib_vc_test_get_digest_cpp() mk_lang_noexcept
{
	mk_lib_crypto_hash_block_sha1_digest_t digest mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_hash_block_sha1_digest_len> ret mk_lang_constexpr_init;

	mk_lib_vc_test_get_digest(&digest);
	for(i = 0; i != mk_lib_crypto_hash_block_sha1_digest_len; ++i){ ret[i] = digest.m_uint8s[i]; }
	return ret;
}
#endif


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
/*mk_lang_constexpr_static_inline auto const s_digest = mk_lib_vc_test_get_digest_cpp();*/
#endif


mk_lang_extern_c void mk_lib_vc_test(void) mk_lang_noexcept
{
	mk_lib_vc_test_reader_t reader;
	mk_lib_vc_test_writer_t writer;
	mk_lang_types_sint_t i;
	mk_sl_cui_uint8_t password[mk_lib_vc_test_password_len];
	mk_lang_types_sint_t tsi;
	mk_lib_crypto_hash_block_sha1_digest_t digest;
	mk_lang_types_uchar_t hi;
	mk_lang_types_uchar_t lo;
	mk_lang_types_uchar_t byte;
	mk_lang_types_uchar_t tuc;

	mk_lib_vc_test_reader_construct(&reader, &s_mk_lib_vc_test_data_tiny.m_data.m_uint8s[0], mk_lib_vc_test_data_tiny_size);
	mk_lib_vc_test_writer_construct(&writer);
	for(i = 0; i != mk_lib_vc_test_password_len; ++i)
	{
		mk_sl_cui_uint8_from_bi_pchar(&password[i], &mk_lib_vc_test_password[i]);
	}
	tsi = mk_lib_vc_tested_decrypt(&reader, &mk_lib_vc_test_reader_seek, &mk_lib_vc_test_reader_read, &password[0], mk_lib_vc_test_password_len, mk_lib_vc_test_pim, mk_lang_null, mk_lang_null, &writer, &mk_lib_vc_test_writer_write); test(tsi == 0);
	mk_lib_crypto_hash_stream_sha1_finish(&writer.m_hasher, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_sha1_digest_len; ++i)
	{
		hi = mk_lib_cpp_constexpr_char_to_nibble(mk_lib_vc_test_digest[i * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
		lo = mk_lib_cpp_constexpr_char_to_nibble(mk_lib_vc_test_digest[i * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
		byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
		mk_sl_cui_uint8_to_bi_uchar(&digest.m_uint8s[i], &tuc);
		test(tuc == byte);
	}
	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
	for(i = 0; i != mk_lib_crypto_hash_block_sha1_digest_len; ++i)
	{
		hi = mk_lib_cpp_constexpr_char_to_nibble(mk_lib_vc_test_digest[i * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
		lo = mk_lib_cpp_constexpr_char_to_nibble(mk_lib_vc_test_digest[i * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
		byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
		/*mk_sl_cui_uint8_to_bi_uchar(&s_digest[i], &tuc);*/
		/*test(tuc == byte);*/
	}
	#endif
}
