#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


#include "mk_sl_io_reader_buffered_inl_defd.h"


struct mk_sl_io_reader_buffered_inl_defd_s
{
	mk_sl_io_reader_buffered_inl_defd_base_pt m_base;
	mk_sl_cui_uint8_pt m_buf;
	mk_lang_types_usize_t m_buf_len;
	mk_lang_types_usize_t m_cursor;
	mk_lang_types_usize_t m_end;
};
typedef struct mk_sl_io_reader_buffered_inl_defd_s mk_sl_io_reader_buffered_inl_defd_t;
typedef mk_sl_io_reader_buffered_inl_defd_t const mk_sl_io_reader_buffered_inl_defd_ct;
typedef mk_sl_io_reader_buffered_inl_defd_t* mk_sl_io_reader_buffered_inl_defd_pt;
typedef mk_sl_io_reader_buffered_inl_defd_t* mk_lang_restrict mk_sl_io_reader_buffered_inl_defd_prt;
typedef mk_sl_io_reader_buffered_inl_defd_t const* mk_sl_io_reader_buffered_inl_defd_pct;
typedef mk_sl_io_reader_buffered_inl_defd_t const* mk_lang_restrict mk_sl_io_reader_buffered_inl_defd_prct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_buffered_inl_defd_init(mk_sl_io_reader_buffered_inl_defd_pt const reader, mk_sl_io_reader_buffered_inl_defd_base_pt const base, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const buf_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_buffered_inl_defd_read(mk_sl_io_reader_buffered_inl_defd_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const read) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_buffered_inl_defd_seek_rel(mk_sl_io_reader_buffered_inl_defd_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept;


#include "mk_sl_io_reader_buffered_inl_defu.h"
