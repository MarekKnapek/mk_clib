#include "mk_sl_io_async_thread.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"
#include "mk_sl_io_async_reader_file.h"
#include "mk_sl_io_async_writer_file.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_create(mk_sl_io_async_thread_pt const thread) mk_lang_noexcept
{
#if mk_sl_io_async_thread_needs
	mk_lang_assert(thread);

	return mk_sl_io_async_thread_portable_create(&thread->m_thread);
#else
	mk_lang_assert(thread);

	((mk_lang_types_void_t)(thread));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_add_r(mk_sl_io_async_thread_pt const thread, mk_sl_io_async_reader_file_pt const reader, mk_sl_io_async_reader_file_iorp_pt const iorp) mk_lang_noexcept
{
#if mk_sl_io_async_thread_needs
	mk_lang_assert(thread);
	mk_lang_assert(reader);
	mk_lang_assert(iorp);

	return mk_sl_io_async_thread_portable_add_r(&thread->m_thread, &reader->m_reader, &iorp->m_iorp);
#else
	mk_lang_assert(thread);
	mk_lang_assert(reader);
	mk_lang_assert(iorp);

	((mk_lang_types_void_t)(thread));
	((mk_lang_types_void_t)(reader));
	((mk_lang_types_void_t)(iorp));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_add_w(mk_sl_io_async_thread_pt const thread, mk_sl_io_async_writer_file_pt const writer, mk_sl_io_async_writer_file_iorp_pt const iorp) mk_lang_noexcept
{
#if mk_sl_io_async_thread_needs
	mk_lang_assert(thread);
	mk_lang_assert(writer);
	mk_lang_assert(iorp);

	return mk_sl_io_async_thread_portable_add_w(&thread->m_thread, &writer->m_writer, &iorp->m_iorp);
#else
	mk_lang_assert(thread);
	mk_lang_assert(writer);
	mk_lang_assert(iorp);

	((mk_lang_types_void_t)(thread));
	((mk_lang_types_void_t)(writer));
	((mk_lang_types_void_t)(iorp));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_poke(mk_sl_io_async_thread_pt const thread) mk_lang_noexcept
{
#if mk_sl_io_async_thread_needs
	mk_lang_assert(thread);

	return mk_sl_io_async_thread_portable_poke(&thread->m_thread);
#else
	mk_lang_assert(thread);

	((mk_lang_types_void_t)(thread));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_flush(mk_sl_io_async_thread_pt const thread) mk_lang_noexcept
{
#if mk_sl_io_async_thread_needs
	mk_lang_assert(thread);

	return mk_sl_io_async_thread_portable_flush(&thread->m_thread);
#else
	mk_lang_assert(thread);

	((mk_lang_types_void_t)(thread));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_join(mk_sl_io_async_thread_pt const thread) mk_lang_noexcept
{
#if mk_sl_io_async_thread_needs
	mk_lang_assert(thread);

	return mk_sl_io_async_thread_portable_join(&thread->m_thread);
#else
	mk_lang_assert(thread);

	((mk_lang_types_void_t)(thread));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_async_thread_destroy(mk_sl_io_async_thread_pt const thread) mk_lang_noexcept
{
#if mk_sl_io_async_thread_needs
	mk_lang_assert(thread);

	return mk_sl_io_async_thread_portable_destroy(&thread->m_thread);
#else
	mk_lang_assert(thread);

	((mk_lang_types_void_t)(thread));
	return 0;
#endif
}
