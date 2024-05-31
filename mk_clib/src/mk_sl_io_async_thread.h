#ifndef mk_include_guard_mk_sl_io_async_thread
#define mk_include_guard_mk_sl_io_async_thread


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"


struct mk_sl_io_async_reader_file_s;
typedef struct mk_sl_io_async_reader_file_s mk_sl_io_async_reader_file_t;
typedef mk_sl_io_async_reader_file_t const mk_sl_io_async_reader_file_ct;
typedef mk_sl_io_async_reader_file_t* mk_sl_io_async_reader_file_pt;
typedef mk_sl_io_async_reader_file_t const* mk_sl_io_async_reader_file_pct;

struct mk_sl_io_async_reader_file_iorp_s;
typedef struct mk_sl_io_async_reader_file_iorp_s mk_sl_io_async_reader_file_iorp_t;
typedef mk_sl_io_async_reader_file_iorp_t const mk_sl_io_async_reader_file_iorp_ct;
typedef mk_sl_io_async_reader_file_iorp_t* mk_sl_io_async_reader_file_iorp_pt;
typedef mk_sl_io_async_reader_file_iorp_t const* mk_sl_io_async_reader_file_iorp_pct;

struct mk_sl_io_async_writer_file_s;
typedef struct mk_sl_io_async_writer_file_s mk_sl_io_async_writer_file_t;
typedef mk_sl_io_async_writer_file_t const mk_sl_io_async_writer_file_ct;
typedef mk_sl_io_async_writer_file_t* mk_sl_io_async_writer_file_pt;
typedef mk_sl_io_async_writer_file_t const* mk_sl_io_async_writer_file_pct;

struct mk_sl_io_async_writer_file_iorp_s;
typedef struct mk_sl_io_async_writer_file_iorp_s mk_sl_io_async_writer_file_iorp_t;
typedef mk_sl_io_async_writer_file_iorp_t const mk_sl_io_async_writer_file_iorp_ct;
typedef mk_sl_io_async_writer_file_iorp_t* mk_sl_io_async_writer_file_iorp_pt;
typedef mk_sl_io_async_writer_file_iorp_t const* mk_sl_io_async_writer_file_iorp_pct;


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows
#define mk_sl_io_async_thread_needs 0
typedef mk_lang_types_sint_t mk_sl_io_async_thread_impl_t;
#elif mk_lang_platform == mk_lang_platform_portable || mk_lang_platform == mk_lang_platform_linux
#define mk_sl_io_async_thread_needs 1
#include "mk_sl_io_async_thread_portable.h"
typedef mk_sl_io_async_thread_portable_t mk_sl_io_async_thread_impl_t;
#else
#error xxxxxxxxxx todo
#endif


struct mk_sl_io_async_thread_s
{
	mk_sl_io_async_thread_impl_t m_thread;
};
typedef struct mk_sl_io_async_thread_s mk_sl_io_async_thread_t;
typedef mk_sl_io_async_thread_t const mk_sl_io_async_thread_ct;
typedef mk_sl_io_async_thread_t* mk_sl_io_async_thread_pt;
typedef mk_sl_io_async_thread_t const* mk_sl_io_async_thread_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_create(mk_sl_io_async_thread_pt const thread) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_add_r(mk_sl_io_async_thread_pt const thread, mk_sl_io_async_reader_file_pt const reader, mk_sl_io_async_reader_file_iorp_pt const iorp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_add_w(mk_sl_io_async_thread_pt const thread, mk_sl_io_async_writer_file_pt const writer, mk_sl_io_async_writer_file_iorp_pt const iorp) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_poke(mk_sl_io_async_thread_pt const thread) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_flush(mk_sl_io_async_thread_pt const thread) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_join(mk_sl_io_async_thread_pt const thread) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_destroy(mk_sl_io_async_thread_pt const thread) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_io_async_thread.c"
#endif
#endif
