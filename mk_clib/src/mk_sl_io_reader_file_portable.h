#ifndef mk_include_guard_mk_sl_io_reader_file_portable
#define mk_include_guard_mk_sl_io_reader_file_portable


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_io_transaction_portable.h"
#include "mk_sl_uint8.h"

#include <stdio.h> /* FILE */


typedef FILE* mk_sl_io_reader_file_portable_handle_t;

struct mk_sl_io_reader_file_portable_s
{
	mk_sl_io_reader_file_portable_handle_t m_file_handle;
};
typedef struct mk_sl_io_reader_file_portable_s mk_sl_io_reader_file_portable_t;
typedef mk_sl_io_reader_file_portable_t const mk_sl_io_reader_file_portable_ct;
typedef mk_sl_io_reader_file_portable_t* mk_sl_io_reader_file_portable_pt;
typedef mk_sl_io_reader_file_portable_t* mk_lang_restrict mk_sl_io_reader_file_portable_prt;
typedef mk_sl_io_reader_file_portable_t const* mk_sl_io_reader_file_portable_pct;
typedef mk_sl_io_reader_file_portable_t const* mk_lang_restrict mk_sl_io_reader_file_portable_prct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_open_n(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_pchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_open_w(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_wchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_open_tx_n(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_pchar_pct const name, mk_sl_io_transaction_portable_pt const tx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_open_tx_w(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_wchar_pct const name, mk_sl_io_transaction_portable_pt const tx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_read(mk_sl_io_reader_file_portable_pt const reader, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const read) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_seek_rel(mk_sl_io_reader_file_portable_pt const reader, mk_lang_types_slong_t const offset) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_reader_file_portable_close(mk_sl_io_reader_file_portable_pt const reader) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_io_reader_file_portable.c"
#endif
#endif
