#include "mk_clib_app_vc.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_exe_name.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_os.h"
#include "mk_lang_pow2.h"
#include "mk_lang_types.h"
#include "mk_lib_fmt.h"
#include "mk_lib_text_encoding.h"
#include "mk_lib_vc.h"
#include "mk_sl_io_console.h"
#include "mk_sl_io_reader_file.h"
#include "mk_sl_io_writer_file.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"

#define mk_sl_io_reader_buffered_t_name mk_clib_app_vc_reader
#define mk_sl_io_reader_buffered_t_base mk_sl_io_reader_file
#include "mk_sl_io_reader_buffered_inl_fileh.h"
#include "mk_sl_io_reader_buffered_inl_filec.h"

#define mk_sl_io_writer_buffered_t_name mk_clib_app_vc_writer
#define mk_sl_io_writer_buffered_t_base mk_sl_io_writer_file
#include "mk_sl_io_writer_buffered_inl_fileh.h"
#include "mk_sl_io_writer_buffered_inl_filec.h"

#define mk_lang_memset_t_name mk_clib_app_vc_memsetu8
#define mk_lang_memset_t_base mk_sl_cui_uint8
#include "mk_lang_memset_inl_fileh.h"
#include "mk_lang_memset_inl_filec.h"

#define mk_lang_strlen_t_name mk_clib_app_vc_strlenpc
#define mk_lang_strlen_t_base mk_lang_types_pchar
#include "mk_lang_strlen_inl_fileh.h"
#include "mk_lang_strlen_inl_filec.h"

#define mk_lang_strlen_t_name mk_clib_app_vc_strlenwc
#define mk_lang_strlen_t_base mk_lang_types_wchar
#include "mk_lang_strlen_inl_fileh.h"
#include "mk_lang_strlen_inl_filec.h"


struct mk_lib_vc_block_oversized2_data_s
{
	mk_sl_cui_uint8_t m_uint8s[(mk_lib_vc_block_len + mk_lib_vc_salt_len) + (mk_lib_vc_block_len + mk_lib_vc_salt_len - 1)];
};
typedef struct mk_lib_vc_block_oversized2_data_s mk_lib_vc_block_oversized2_data_t;

struct mk_lib_vc_block_oversized2_s
{
	mk_lib_vc_block_oversized2_data_t m_data;
};
typedef struct mk_lib_vc_block_oversized2_s mk_lib_vc_block_oversized2_t;


static mk_sl_cui_uint8_t g_mk_clib_app_vc_buf[(2ul * 64ul * 1024ul) + ((64ul * 1024ul) - 1ul)];


static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_chs_from_bytes(mk_sl_cui_uint32_pct const bytes, mk_sl_cui_uint8_pt const a, mk_sl_cui_uint8_pt const b, mk_sl_cui_uint8_pt const c) mk_lang_noexcept
{
	mk_sl_cui_uint32_t blocks;
	mk_lang_types_ulong_t tul;
	mk_sl_cui_uint32_t tu32a;
	mk_sl_cui_uint32_t tu32b;
	mk_sl_cui_uint32_t cylinders;
	mk_sl_cui_uint32_t heads;
	mk_sl_cui_uint32_t sectors;
	mk_lang_types_uchar_t tuc;
	mk_sl_cui_uint8_t tu8a;
	mk_sl_cui_uint8_t tu8b;

	mk_lang_assert(bytes);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert((mk_sl_cui_uint32_shl3(bytes, 32 - 9, &blocks), mk_sl_cui_uint32_is_zero(&blocks)));
	mk_lang_assert((mk_sl_cui_uint32_shr3(bytes, 9, &blocks), mk_sl_cui_uint32_to_bi_ulong(&blocks, &tul), mk_lang_pow2_is(tul)));

	mk_sl_cui_uint32_shr3(bytes, 9, &blocks);
	tul = 255; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_div3_wrap(&blocks, &tu32a, &tu32b);
	tul = 63; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_div3_wrap(&tu32b, &tu32a, &cylinders);
	mk_lang_assert((mk_sl_cui_uint32_shr3(&cylinders, 10, &tu32a), mk_sl_cui_uint32_is_zero(&tu32a)));
	tul = 63; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_mul3_wrap_lo(&cylinders, &tu32a, &tu32b);
	tul = 255; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_mul3_wrap_lo(&tu32b, &tu32a, &tu32b);
	mk_sl_cui_uint32_sub2_wrap_cid_cod(&blocks, &tu32b);
	mk_lang_assert((mk_sl_cui_uint32_to_bi_ulong(&blocks, &tul), tul < 255 * 63));
	tul = 63; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_div3_wrap(&blocks, &tu32a, &heads);
	mk_lang_assert((mk_sl_cui_uint32_to_bi_ulong(&heads, &tul), tul < 255));
	tul = 63; mk_sl_cui_uint32_from_bi_ulong(&tu32a, &tul);
	mk_sl_cui_uint32_mul3_wrap_lo(&heads, &tu32a, &tu32b);
	mk_sl_cui_uint32_sub3_wrap_cid_cod(&blocks, &tu32b, &sectors);
	mk_lang_assert((mk_sl_cui_uint32_to_bi_ulong(&sectors, &tul), tul < 63));
	mk_sl_cui_uint32_inc1(&sectors);
	mk_sl_cui_uint32_to_bi_uchar(&heads, &tuc);
	mk_sl_cui_uint8_from_bi_uchar(a, &tuc);
	mk_sl_cui_uint32_to_bi_uchar(&cylinders, &tuc);
	mk_sl_cui_uint8_from_bi_uchar(c, &tuc);
	mk_sl_cui_uint32_to_bi_uchar(&sectors, &tuc);
	mk_sl_cui_uint8_from_bi_uchar(&tu8a, &tuc);
	mk_sl_cui_uint32_shr2(&cylinders, 8);
	mk_sl_cui_uint32_shl2(&cylinders, 6);
	mk_sl_cui_uint32_to_bi_uchar(&cylinders, &tuc);
	mk_sl_cui_uint8_from_bi_uchar(&tu8b, &tuc);
	mk_sl_cui_uint8_or3(&tu8a, &tu8b, b);
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_mbr_header_generate(mk_lib_vc_block_pt const block, mk_sl_cui_uint64_pct const volume_len, mk_sl_cui_uint32_pct const align) mk_lang_noexcept
{
	mk_sl_cui_uint64_t tu64;
	mk_lang_types_ulong_t tul;
	mk_lang_types_sint_t ptr;
	mk_sl_cui_uint8_t chs[3];
	mk_sl_cui_uint8_t tu8;
	mk_lang_types_uchar_t tuc;
	mk_sl_cui_uint32_t tu32;

	mk_lang_assert(block);
	mk_lang_assert(volume_len);
	mk_lang_assert(align);
	mk_lang_assert((mk_sl_cui_uint64_shl3(volume_len, 64 - 9, &tu64), mk_sl_cui_uint64_is_zero(&tu64))); /* aligned to whole 512 B blocks */
	mk_lang_assert((mk_sl_cui_uint64_shr3(volume_len, 32 + 9, &tu64), mk_sl_cui_uint64_is_zero(&tu64))); /* max 2^32 512 B blocks == 2 TB */
	mk_lang_assert((mk_sl_cui_uint32_to_bi_ulong(align, &tul), mk_lang_pow2_is(tul) && tul <= 64ul * 1024ul * 1024ul)); /* max align in 64 MB */

	ptr = 0;
	mk_clib_app_vc_chs_from_bytes(align, &chs[0], &chs[1], &chs[2]);
	mk_sl_cui_uint8_set_zero(&tu8); mk_clib_app_vc_memsetu8_fn(&block->m_data.m_uint8s[ptr], &tu8, 446); ptr += 446; /* bootstrap code */
	tuc = 0; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* status or physical drive */
	block->m_data.m_uint8s[ptr++] = chs[0]; /* h */
	block->m_data.m_uint8s[ptr++] = chs[1]; /* cs */
	block->m_data.m_uint8s[ptr++] = chs[2]; /* c */
	tuc = 0x06; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* partition type */
	tuc = 0xff; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* h */
	tuc = 0xff; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* cs */
	tuc = 0xff; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* c */
	mk_sl_cui_uint32_shr3(align, 9, &tu32); mk_sl_uint_32_to_8_le(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* partition start lba */
	mk_sl_cui_uint64_shr3(volume_len, 9, &tu64); mk_sl_cui_uint64_to_bi_ulong(&tu64, &tul); mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_le(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* partition len blocks */
	mk_sl_cui_uint8_set_zero(&tu8); mk_clib_app_vc_memsetu8_fn(&block->m_data.m_uint8s[ptr], &tu8, mk_lib_vc_block_len - ptr - 2); ptr += (mk_lib_vc_block_len - ptr - 2);
	tuc = 0x55; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8;
	tuc = 0xaa; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* boot signature */
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_vhd_footer_chs(mk_lang_types_ulong_t const blocks, mk_lang_types_ulong_pt const out_c, mk_lang_types_ulong_pt const out_h, mk_lang_types_ulong_pt const out_s) mk_lang_noexcept
{
	mk_lang_types_ulong_t b;
	mk_lang_types_ulong_t s;
	mk_lang_types_ulong_t h;
	mk_lang_types_ulong_t ch;
	mk_lang_types_ulong_t c;

	mk_lang_assert(out_c);
	mk_lang_assert(out_h);
	mk_lang_assert(out_s);
	mk_lang_assert(out_c != out_h);
	mk_lang_assert(out_c != out_s);
	mk_lang_assert(out_h != out_s);

	b = blocks;
	b = mk_lang_min(b, 65535ul * 16ul * 255ul);
	if(b >= 65535ul * 16ul * 63ul)
	{
		s = 255ul;
		h = 16ul;
		ch = b / s;
	}
	else
	{
		s = 17ul;
		ch = b / s;
		h = (ch + 1023ul) / 1024ul;
		h = mk_lang_max(h, 4);
		if(ch >= (h * 1024ul) || h > 16ul)
		{
			s = 31ul;
			h = 16ul;
			ch = b / s;
		}
		if(ch >= (h * 1024ul))
		{
			s = 63ul;
			h = 16ul;
			ch = b / s;
		}
	}
	c = ch / h;
	*out_c = c;
	*out_h = h;
	*out_s = s;
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_vhd_footer_checksum(mk_lib_vc_block_pt const block) mk_lang_noexcept
{
	mk_sl_cui_uint32_t checksum;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_uchar_t tuc;
	mk_sl_cui_uint32_t tu32;

	mk_lang_assert(block);

	mk_sl_cui_uint32_set_zero(&checksum);
	n = mk_lib_vc_block_len;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_uchar(&block->m_data.m_uint8s[i], &tuc);
		mk_sl_cui_uint32_from_bi_uchar(&tu32, &tuc);
		mk_sl_cui_uint32_add2_wrap_cid_cod(&checksum, &tu32);
	}
	mk_sl_cui_uint32_not1(&checksum);
	mk_sl_uint_32_to_8_be(&checksum, &block->m_data.m_uint8s[64]);
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_vc_vhd_footer_generate(mk_lib_vc_block_pt const block, mk_sl_cui_uint64_pct const disk_len) mk_lang_noexcept
{
	mk_sl_cui_uint64_t tu64;
	mk_lang_types_ulong_t blocks;
	mk_lang_types_ulong_t c;
	mk_lang_types_ulong_t h;
	mk_lang_types_ulong_t s;
	mk_lang_types_sint_t ptr;
	mk_lang_types_pchar_t tpc;
	mk_sl_cui_uint8_t tu8;
	mk_lang_types_ulong_t tul;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_ushort_t tus;
	mk_sl_cui_uint16_t tu16;
	mk_lang_types_uchar_t tuc;

	mk_lang_assert(block);
	mk_lang_assert(disk_len);
	mk_lang_assert((mk_sl_cui_uint64_shl3(disk_len, 64 - 9, &tu64), mk_sl_cui_uint64_is_zero(&tu64))); /* aligned to whole 512 B blocks */
	mk_lang_assert((mk_sl_cui_uint64_shr3(disk_len, 9 + 32, &tu64), mk_sl_cui_uint64_is_zero(&tu64))); /* max 2^32 512 B blocks == 2 TB */

	mk_sl_cui_uint64_shr3(disk_len, 9, &tu64);
	mk_sl_cui_uint64_to_bi_ulong(&tu64, &blocks);
	mk_clib_app_vc_vhd_footer_chs(blocks, &c, &h, &s);
	ptr = 0;
	tpc = 'c'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'o'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'n'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'e'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'c'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 't'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'i'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'x'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8; /* cookie */
	tul = 0x2ul; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* features */
	tul = ((1ul & 0xfffful) << 16) | ((0ul & 0xfffful) << 0); mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* file format version */
	mk_sl_cui_uint64_set_max(&tu64); mk_sl_uint_64_to_8_be(&tu64, &block->m_data.m_uint8s[ptr]); ptr += 8; /* data offset */
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* time stamp */
	tpc = 'v'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'p'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'c'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = ' '; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8; /* creator application */
	tul = ((1ul & 0xfffful) << 16) | ((0ul & 0xfffful) << 0); mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* creator version */
	tpc = 'W'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'i'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = '2'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8;
	tpc = 'k'; mk_sl_cui_uint8_from_bi_pchar(&tu8, &tpc); block->m_data.m_uint8s[ptr++] = tu8; /* creator host OS */
	mk_sl_uint_64_to_8_be(disk_len, &block->m_data.m_uint8s[ptr]); ptr += 8; /* original size */
	mk_sl_uint_64_to_8_be(disk_len, &block->m_data.m_uint8s[ptr]); ptr += 8; /* current size */
	tus = ((mk_lang_types_ushort_t)(c)); mk_sl_cui_uint16_from_bi_ushort(&tu16, &tus); mk_sl_uint_16_to_8_be(&tu16, &block->m_data.m_uint8s[ptr]); ptr += 2; /* cylinders */
	tuc = ((mk_lang_types_uchar_t)(h)); mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* heads */
	tuc = ((mk_lang_types_uchar_t)(s)); mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* sectors */ /* disk geometry */
	tul = 0x2ul; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* disk type */
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* checksum */
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4;
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4;
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4;
	tul = 0; mk_sl_cui_uint32_from_bi_ulong(&tu32, &tul); mk_sl_uint_32_to_8_be(&tu32, &block->m_data.m_uint8s[ptr]); ptr += 4; /* unique id */
	tuc = 0; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); block->m_data.m_uint8s[ptr++] = tu8; /* saved state */
	mk_sl_cui_uint8_set_zero(&tu8); mk_clib_app_vc_memsetu8_fn(&block->m_data.m_uint8s[ptr], &tu8, mk_lib_vc_block_len - ptr); /* reserved */
	mk_clib_app_vc_vhd_footer_checksum(block);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_arg_write_vhd(mk_lang_types_bool_t const wide, mk_clib_app_vc_reader_pt const reader, mk_lib_vc_seqid_t const seqid, mk_lib_vc_seq_schedules_pct const schedules, mk_sl_cui_uint64_pt const block_id, mk_sl_cui_uint64_pct const max_block_id, mk_sl_cui_uint64_pct const volume_len, mk_lib_vc_block_pt const block, mk_lang_types_pchar_pct const str_output) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_io_writer_file_t writer;
	mk_sl_cui_uint8_pt buf;
	mk_clib_app_vc_writer_t buffered;
	mk_lang_types_ulong_t tul;
	mk_sl_cui_uint32_t align;
	mk_lang_types_usize_t written;
	mk_sl_cui_uint8_t tu8;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_ulong_t n;
	mk_lang_types_ulong_t i;
	mk_lang_types_usize_t read;
	mk_sl_cui_uint64_t tu64;
	mk_sl_cui_uint64_t disk_len;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(reader);
	mk_lang_assert(seqid >= 0 && seqid < mk_lib_vc_seqid_e_dummy);
	mk_lang_assert(schedules);
	mk_lang_assert(block_id);
	mk_lang_assert(max_block_id);
	mk_lang_assert(volume_len);
	mk_lang_assert(block);
	mk_lang_assert(str_output);

	err = wide ? mk_sl_io_writer_file_open_w(&writer, ((mk_lang_types_wchar_pct)(str_output))) : mk_sl_io_writer_file_open_n(&writer, str_output); mk_lang_check_rereturn(err);
	buf = ((mk_sl_cui_uint8_pt)(((((mk_lang_types_uintptr_t)(&g_mk_clib_app_vc_buf[0])) + ((64ul * 1024ul) - 1ul)) / (64ul * 1024ul)) * (64ul * 1024ul))) + (1ul * 64ul * 1024ul);
	mk_clib_app_vc_writer_init(&buffered, &writer, buf, 64ul * 1024ul);
	do
	{
		tul = 1ul * 1024ul * 1024ul; mk_sl_cui_uint32_from_bi_ulong(&align, &tul);
		mk_clib_app_vc_mbr_header_generate(block, volume_len, &align);
		err = mk_clib_app_vc_writer_write(&buffered, &block->m_data.m_uint8s[0], mk_lang_countof(block->m_data.m_uint8s), &written); mk_lang_check_rebreak(err); err = mk_lang_check_line; mk_lang_check_break(written == mk_lang_countof(block->m_data.m_uint8s)); err = 0;
		mk_sl_cui_uint8_set_zero(&tu8); mk_clib_app_vc_memsetu8_fn(&block->m_data.m_uint8s[0], &tu8, mk_lib_vc_block_len);
		mk_sl_cui_uint32_shr3(&align, 9, &tu32);
		mk_sl_cui_uint32_to_bi_ulong(&tu32, &tul);
		n = tul - 1;
		for(i = 0; i != n; ++i)
		{
			err = mk_clib_app_vc_writer_write(&buffered, &block->m_data.m_uint8s[0], mk_lang_countof(block->m_data.m_uint8s), &written); mk_lang_check_rebreak(err); err = mk_lang_check_line; mk_lang_check_break(written == mk_lang_countof(block->m_data.m_uint8s)); err = 0;
		}
		mk_lang_check_rebreak(err);
		for(; mk_sl_cui_uint64_ne(block_id, max_block_id); mk_sl_cui_uint64_inc1(block_id))
		{
			err = mk_clib_app_vc_reader_read(reader, &block->m_data.m_uint8s[0], mk_lang_countof(block->m_data.m_uint8s), &read); mk_lang_check_rebreak(err); err = mk_lang_check_line; mk_lang_check_break(read == mk_lang_countof(block->m_data.m_uint8s)); err = 0;
			mk_lib_vc_seq_decrypt_block(seqid, schedules, block_id, block, block);
			err = mk_clib_app_vc_writer_write(&buffered, &block->m_data.m_uint8s[0], mk_lang_countof(block->m_data.m_uint8s), &written); mk_lang_check_rebreak(err); err = mk_lang_check_line; mk_lang_check_break(written == mk_lang_countof(block->m_data.m_uint8s)); err = 0;
		}
		mk_lang_check_rebreak(err);
		mk_sl_cui_uint32_to_bi_ulong(&align, &tul);
		mk_sl_cui_uint64_from_bi_ulong(&tu64, &tul);
		mk_sl_cui_uint64_add3_wrap_cid_cod(volume_len, &tu64, &disk_len);
		mk_clib_app_vc_vhd_footer_generate(block, &disk_len);
		err = mk_clib_app_vc_writer_write(&buffered, &block->m_data.m_uint8s[0], mk_lang_countof(block->m_data.m_uint8s), &written); mk_lang_check_rebreak(err); err = mk_lang_check_line; mk_lang_check_break(written == mk_lang_countof(block->m_data.m_uint8s)); err = 0;
		err = mk_clib_app_vc_writer_flush(&buffered); mk_lang_check_rereturn(err);
	}while(mk_lang_false);
	err_b = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err_b);
	mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_password_to_utf8(mk_lang_types_bool_t const wide, mk_lang_types_pchar_pct const str_password, mk_sl_cui_uint8_pt const password_utf8_buf, mk_lang_types_sint_t const password_utf8_buf_len, mk_sl_cui_uint8_pct* const password_utf8, mk_lang_types_sint_pt const password_len) mk_lang_noexcept
{
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t err;

	mk_lang_assert(str_password);
	mk_lang_assert(password_utf8_buf);
	mk_lang_assert(password_utf8_buf_len >= 64);
	mk_lang_assert(password_utf8);
	mk_lang_assert(password_len);

	if(!wide)
	{
		mk_lang_assert(mk_clib_app_vc_strlenpc_fn(((mk_lang_types_pchar_pct)(str_password))) <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
		len = ((mk_lang_types_sint_t)(mk_clib_app_vc_strlenpc_fn(((mk_lang_types_pchar_pct)(str_password))))); mk_lang_check_return(len <= password_utf8_buf_len);
		*password_utf8 = ((mk_sl_cui_uint8_pct)(str_password));
		*password_len = len;
	}
	else
	{
		mk_lang_assert(mk_clib_app_vc_strlenwc_fn(((mk_lang_types_wchar_pct)(str_password))) <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
		len = ((mk_lang_types_sint_t)(mk_clib_app_vc_strlenwc_fn(((mk_lang_types_wchar_pct)(str_password)))));
		err = mk_lib_text_encoding_wide_to_utf8(((mk_lang_types_wchar_pct)(str_password)), len, ((mk_lang_types_pchar_pt)(password_utf8_buf)), password_utf8_buf_len, password_len); mk_lang_check_rereturn(err);
		*password_utf8  = &password_utf8_buf[0];
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_arg_work(mk_lang_types_bool_t const wide, mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_pchar_pct str_input;
	mk_lang_types_pchar_pct str_password;
	mk_lang_types_pchar_pct str_pim;
	mk_lang_types_pchar_pct str_output;
	mk_sl_cui_uint8_t password_utf8_buf[512];
	mk_sl_cui_uint8_pct password_utf8;
	mk_lang_types_sint_t password_len;
	mk_lang_types_sint_t err;
	mk_lang_types_ulong_t cost;
	mk_lib_vc_block_pt block;
	mk_lib_vc_block_oversized2_t block_oversized;
	mk_sl_io_reader_file_t reader;
	mk_sl_cui_uint8_pt buf;
	mk_clib_app_vc_reader_t buffered;
	mk_lang_types_usize_t read;
	mk_lib_vc_salt_pt salt;
	mk_lib_vc_seqid_t seqid;
	mk_lib_vc_seq_schedules_t schedules;
	mk_sl_cui_uint64_t volume_len;
	mk_lang_types_sint_t tsi;
	mk_sl_cui_uint64_t block_id;
	mk_sl_cui_uint64_t max_block_id;
	mk_lang_types_sint_t err_b;

	mk_lang_assert(argc == 5);
	mk_lang_assert
	(
		(!wide && mk_clib_app_vc_strlenpc_fn(argv[2]) <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max))) ||
		(wide && mk_clib_app_vc_strlenwc_fn(((mk_lang_types_wchar_pct)(argv[2]))) <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)))
	);

	str_input = argv[1];
	str_password = argv[2];
	str_pim = argv[3];
	str_output = argv[4];
	err = mk_clib_app_vc_password_to_utf8(wide, str_password, &password_utf8_buf[0], mk_lang_countof(password_utf8_buf), &password_utf8, &password_len); mk_lang_check_rereturn(err);
	err = mk_lib_vc_parse_cost(wide, str_pim, &cost); mk_lang_check_rereturn(err);
	block = ((mk_lib_vc_block_pt)(((((mk_lang_types_uintptr_t)(&block_oversized)) + (sizeof(*block) - 1)) / sizeof(*block)) * sizeof(*block)));
	err = wide ? mk_sl_io_reader_file_open_w(&reader, ((mk_lang_types_wchar_pct)(str_input))) : mk_sl_io_reader_file_open_n(&reader, str_input); mk_lang_check_rereturn(err);
	buf = ((mk_sl_cui_uint8_pt)(((((mk_lang_types_uintptr_t)(&g_mk_clib_app_vc_buf[0])) + ((64ul * 1024ul) - 1ul)) / (64ul * 1024ul)) * (64ul * 1024ul))) + (0ul * 64ul * 1024ul);
	err = mk_clib_app_vc_reader_init(&buffered, &reader, buf, 64ul * 1024ul); mk_lang_check_rereturn(err);
	do
	{
		err = mk_clib_app_vc_reader_read(&buffered, &block->m_data.m_uint8s[0], mk_lang_countof(block->m_data.m_uint8s), &read); mk_lang_check_rebreak(err); err = mk_lang_check_line; mk_lang_check_break(read == mk_lang_countof(block->m_data.m_uint8s)); err = 0;
		salt = ((mk_lib_vc_salt_pt)(block));
		block = ((mk_lib_vc_block_pt)(((mk_lang_types_uintptr_t)(block)) + mk_lib_vc_salt_len));
		err = mk_lib_vc_try_decrypt_header(mk_lib_vc_kdfid_e_dummy, password_utf8, password_len, salt, cost, block, &seqid, &schedules, &volume_len); mk_lang_check_rebreak(err);
		block = ((mk_lib_vc_block_pt)(((mk_lang_types_uintptr_t)(block)) - mk_lib_vc_salt_len));
		err = mk_clib_app_vc_reader_seek_rel(&buffered, mk_lib_vc_offsets_volume - mk_lib_vc_block_len); mk_lang_check_rebreak(err);
		tsi = mk_lib_vc_offsets_volume / mk_lib_vc_block_len; mk_sl_cui_uint64_from_bi_sint(&block_id, &tsi);
		mk_sl_cui_uint64_shr3(&volume_len, 9, &max_block_id); mk_sl_cui_uint64_add2_wrap_cid_cod(&max_block_id, &block_id);
		err = mk_clib_app_vc_arg_write_vhd(wide, &buffered, seqid, &schedules, &block_id, &max_block_id, &volume_len, block, str_output); mk_lang_check_rebreak(err);
	}while(mk_lang_false);
	err_b = mk_sl_io_reader_file_close(&reader); mk_lang_check_rereturn(err_b);
	mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_arg_readme_n(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_pchar_pct fmt;
	mk_lang_types_pchar_pct exe_name;
	mk_lang_types_pchar_t buf[512];
	mk_lang_types_sint_t tsi;

	((mk_lang_types_void_t)(argc));

	fmt = "Example usage: %s <input_file> <password> <pim> <output_file>\n";
	exe_name = mk_lang_exe_name_get_n(argv[0]);
	tsi = mk_lib_fmt_n_snprintf(&buf[0], mk_lang_countof(buf), fmt, exe_name); mk_lang_check_return(tsi > 0);
	tsi = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(&buf[0])), tsi); mk_lang_check_rereturn(tsi);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_arg_readme_w(mk_lang_types_sint_t const argc, mk_lang_types_wchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_wchar_pct fmt;
	mk_lang_types_wchar_pct exe_name;
	mk_lang_types_wchar_t buf[512];
	mk_lang_types_sint_t tsi;

	((mk_lang_types_void_t)(argc));

	fmt = L"Example usage: %s <input_file> <password> <pim> <output_file>\n";
	exe_name = mk_lang_exe_name_get_w(argv[0]);
	tsi = mk_lib_fmt_w_snprintf(&buf[0], mk_lang_countof(buf), fmt, exe_name); mk_lang_check_return(tsi > 0);
	tsi = mk_sl_io_console_write_w(((mk_sl_cui_uint8_pct)(&buf[0])), tsi); mk_lang_check_rereturn(tsi);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_vc_arg_readme(mk_lang_types_bool_t const wide, mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	if(!wide)
	{
		return mk_clib_app_vc_arg_readme_n(argc, ((mk_lang_types_pchar_pcpct)(argv)));
	}
	else
	{
		return mk_clib_app_vc_arg_readme_w(argc, ((mk_lang_types_wchar_pcpct)(argv)));
	}
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_vc_arg(mk_lang_types_bool_t const wide, mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;

	mk_lang_check_return(argc >= 1);
	mk_lang_check_return(argv);
	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_check_return(argv[i]);
		mk_lang_check_return((!wide && ((mk_lang_types_pchar_pcpct)(argv))[i][0] != '\0') || (wide && ((mk_lang_types_wchar_pcpct)(argv))[i][0] != L'\0'));
	}
	if(argc == 5)
	{
		mk_lang_cpuid_init();
		err = mk_clib_app_vc_arg_work(wide, argc, argv); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mk_clib_app_vc_arg_readme(wide, argc, argv); mk_lang_check_rereturn(err);
	}
	return 0;
}
