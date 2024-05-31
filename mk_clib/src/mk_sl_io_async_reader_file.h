#ifndef mk_include_guard_mk_sl_io_async_reader_file
#define mk_include_guard_mk_sl_io_async_reader_file


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


struct mk_sl_io_transaction_s;
typedef struct mk_sl_io_transaction_s mk_sl_io_transaction_t;
typedef mk_sl_io_transaction_t const mk_sl_io_transaction_ct;
typedef mk_sl_io_transaction_t* mk_sl_io_transaction_pt;
typedef mk_sl_io_transaction_t const* mk_sl_io_transaction_pct;

struct mk_sl_io_async_thread_s;
typedef struct mk_sl_io_async_thread_s mk_sl_io_async_thread_t;
typedef mk_sl_io_async_thread_t const mk_sl_io_async_thread_ct;
typedef mk_sl_io_async_thread_t* mk_sl_io_async_thread_pt;
typedef mk_sl_io_async_thread_t const* mk_sl_io_async_thread_pct;


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows
#include "mk_sl_io_async_reader_file_windows.h"
typedef mk_sl_io_async_reader_file_windows_t mk_sl_io_async_reader_file_impl_t;
typedef mk_sl_io_async_reader_file_iorp_windows_t mk_sl_io_async_reader_file_iorp_impl_t;
#elif mk_lang_platform == mk_lang_platform_portable || mk_lang_platform == mk_lang_platform_linux
#include "mk_sl_io_async_reader_file_portable.h"
typedef mk_sl_io_async_reader_file_portable_t mk_sl_io_async_reader_file_impl_t;
typedef mk_sl_io_async_reader_file_iorp_portable_t mk_sl_io_async_reader_file_iorp_impl_t;
#else
#error xxxxxxxxxx todo
#endif


struct mk_sl_io_async_reader_file_s
{
	mk_sl_io_async_reader_file_impl_t m_reader;
};
typedef struct mk_sl_io_async_reader_file_s mk_sl_io_async_reader_file_t;
typedef mk_sl_io_async_reader_file_t const mk_sl_io_async_reader_file_ct;
typedef mk_sl_io_async_reader_file_t* mk_sl_io_async_reader_file_pt;
typedef mk_sl_io_async_reader_file_t const* mk_sl_io_async_reader_file_pct;

struct mk_sl_io_async_reader_file_iorp_s
{
	mk_sl_io_async_reader_file_iorp_impl_t m_iorp;
};
typedef struct mk_sl_io_async_reader_file_iorp_s mk_sl_io_async_reader_file_iorp_t;
typedef mk_sl_io_async_reader_file_iorp_t const mk_sl_io_async_reader_file_iorp_ct;
typedef mk_sl_io_async_reader_file_iorp_t* mk_sl_io_async_reader_file_iorp_pt;
typedef mk_sl_io_async_reader_file_iorp_t const* mk_sl_io_async_reader_file_iorp_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_open_n(mk_sl_io_async_reader_file_pt const reader, mk_lang_types_pchar_pct const name, mk_sl_io_async_thread_pt const thread) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_open_w(mk_sl_io_async_reader_file_pt const reader, mk_lang_types_wchar_pct const name, mk_sl_io_async_thread_pt const thread) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_open_tx_n(mk_sl_io_async_reader_file_pt const reader, mk_lang_types_pchar_pct const name, mk_sl_io_transaction_pt const tx, mk_sl_io_async_thread_pt const thread) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_open_tx_w(mk_sl_io_async_reader_file_pt const reader, mk_lang_types_wchar_pct const name, mk_sl_io_transaction_pt const tx, mk_sl_io_async_thread_pt const thread) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_request_read(mk_sl_io_async_reader_file_pt const reader, mk_sl_io_async_reader_file_iorp_pt const iorp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_close(mk_sl_io_async_reader_file_pt const reader) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_construct_void(mk_sl_io_async_reader_file_iorp_pt const iorp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_construct_args(mk_sl_io_async_reader_file_iorp_pt const iorp, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_sl_cui_uint64_pct const pos) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_reconstruct(mk_sl_io_async_reader_file_iorp_pt const iorp, mk_sl_cui_uint8_pt const buf, mk_lang_types_usize_t const len, mk_sl_cui_uint64_pct const pos) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_buf(mk_sl_io_async_reader_file_iorp_pt const iorp, mk_sl_cui_uint8_pt* const buf) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_len(mk_sl_io_async_reader_file_iorp_pt const iorp, mk_lang_types_usize_pt const len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_pos(mk_sl_io_async_reader_file_iorp_pt const iorp, mk_sl_cui_uint64_pt const pos) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_reader_file_iorp_destroy(mk_sl_io_async_reader_file_iorp_pt const iorp) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_io_async_reader_file.c"
#endif
#endif
