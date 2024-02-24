#ifndef mk_include_guard_mk_win_buffered_writer
#define mk_include_guard_mk_win_buffered_writer


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


struct mk_win_buffered_writer_s
{
	mk_win_base_handle_t m_file;
	mk_win_base_void_pt m_buffer;
	mk_win_base_usize_t m_len;
	mk_win_base_usize_t m_pos;
};
typedef struct mk_win_buffered_writer_s mk_win_buffered_writer_t;
typedef mk_win_buffered_writer_t const mk_win_buffered_writer_ct;
typedef mk_win_buffered_writer_t* mk_win_buffered_writer_pt;
typedef mk_win_buffered_writer_t const* mk_win_buffered_writer_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_win_buffered_writer_ro_destroy(mk_win_buffered_writer_pct const bw) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_win_buffered_writer_rw_destroy(mk_win_buffered_writer_pt const bw) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_win_buffered_writer_rw_construct(mk_win_buffered_writer_pt const bw, mk_win_base_handle_t const file, mk_win_base_void_pt const buffer, mk_win_base_usize_t const len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_win_buffered_writer_rw_write(mk_win_buffered_writer_pt const bw, mk_win_base_void_pct const buff, mk_win_base_usize_t const len) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_buffered_writer.c"
#endif
#endif
