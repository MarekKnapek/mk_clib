#ifndef mk_include_guard_mk_sl_io_writer_file_windows
#define mk_include_guard_mk_sl_io_writer_file_windows


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_sl_io_transaction_windows.h"
#include "mk_sl_uint8.h"
#include "mk_win_kernel_files.h"


typedef mk_win_base_handle_t mk_sl_io_writer_file_windows_handle_t;

struct mk_sl_io_writer_file_windows_s
{
	mk_sl_io_writer_file_windows_handle_t m_file_handle;
};
typedef struct mk_sl_io_writer_file_windows_s mk_sl_io_writer_file_windows_t;
typedef mk_sl_io_writer_file_windows_t const mk_sl_io_writer_file_windows_ct;
typedef mk_sl_io_writer_file_windows_t* mk_sl_io_writer_file_windows_pt;
typedef mk_sl_io_writer_file_windows_t* mk_lang_restrict mk_sl_io_writer_file_windows_prt;
typedef mk_sl_io_writer_file_windows_t const* mk_sl_io_writer_file_windows_pct;
typedef mk_sl_io_writer_file_windows_t const* mk_lang_restrict mk_sl_io_writer_file_windows_prct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_windows_open_n(mk_sl_io_writer_file_windows_pt const writer, mk_lang_types_pchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_windows_open_w(mk_sl_io_writer_file_windows_pt const writer, mk_lang_types_wchar_pct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_windows_open_tx_n(mk_sl_io_writer_file_windows_pt const writer, mk_lang_types_pchar_pct const name, mk_sl_io_transaction_windows_pt const tx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_windows_open_tx_w(mk_sl_io_writer_file_windows_pt const writer, mk_lang_types_wchar_pct const name, mk_sl_io_transaction_windows_pt const tx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_windows_write(mk_sl_io_writer_file_windows_pt const writer, mk_sl_cui_uint8_pct const buf, mk_lang_types_usize_t const len, mk_lang_types_usize_pt const written) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_writer_file_windows_close(mk_sl_io_writer_file_windows_pt const writer) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_io_writer_file_windows.c"
#endif
#endif
