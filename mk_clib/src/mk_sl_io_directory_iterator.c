#ifndef mk_include_guard_mk_sl_io_directory_iterator_c
#define mk_include_guard_mk_sl_io_directory_iterator_c
#include "mk_sl_io_directory_iterator.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#define mk_sl_io_directory_iterator_impl_rw_construct_void mk_lang_concat(mk_lang_concat(mk_sl_io_directory_iterator_, mk_sl_io_directory_iterator_prefix), _rw_construct_void)
#define mk_sl_io_directory_iterator_impl_rw_construct mk_lang_concat(mk_lang_concat(mk_sl_io_directory_iterator_, mk_sl_io_directory_iterator_prefix), _rw_construct)
#define mk_sl_io_directory_iterator_impl_rw_destroy mk_lang_concat(mk_lang_concat(mk_sl_io_directory_iterator_, mk_sl_io_directory_iterator_prefix), _rw_destroy)
#define mk_sl_io_directory_iterator_impl_rw_reset mk_lang_concat(mk_lang_concat(mk_sl_io_directory_iterator_, mk_sl_io_directory_iterator_prefix), _rw_reset)
#define mk_sl_io_directory_iterator_impl_rw_get_name mk_lang_concat(mk_lang_concat(mk_sl_io_directory_iterator_, mk_sl_io_directory_iterator_prefix), _rw_get_name)
#define mk_sl_io_directory_iterator_impl_rw_next mk_lang_concat(mk_lang_concat(mk_sl_io_directory_iterator_, mk_sl_io_directory_iterator_prefix), _rw_next)
#define mk_sl_io_directory_iterator_impl_rw_is_end mk_lang_concat(mk_lang_concat(mk_sl_io_directory_iterator_, mk_sl_io_directory_iterator_prefix), _rw_is_end)


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_rw_construct_void(mk_sl_io_directory_iterator_pt const directory_iterator) mk_lang_noexcept
{
	mk_lang_assert(directory_iterator);

	return mk_sl_io_directory_iterator_impl_rw_construct_void(&directory_iterator->m_base);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_rw_construct(mk_sl_io_directory_iterator_pt const directory_iterator, mk_lang_types_pchar_pct const path) mk_lang_noexcept
{
	mk_lang_assert(directory_iterator);

	return mk_sl_io_directory_iterator_impl_rw_construct(&directory_iterator->m_base, path);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_rw_destroy(mk_sl_io_directory_iterator_pt const directory_iterator) mk_lang_noexcept
{
	mk_lang_assert(directory_iterator);

	return mk_sl_io_directory_iterator_impl_rw_destroy(&directory_iterator->m_base);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_rw_reset(mk_sl_io_directory_iterator_pt const directory_iterator) mk_lang_noexcept
{
	mk_lang_assert(directory_iterator);

	return mk_sl_io_directory_iterator_impl_rw_reset(&directory_iterator->m_base);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_rw_get_name(mk_sl_io_directory_iterator_pt const directory_iterator, mk_lang_types_pchar_ppct const name) mk_lang_noexcept
{
	mk_lang_assert(directory_iterator);

	return mk_sl_io_directory_iterator_impl_rw_get_name(&directory_iterator->m_base, name);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_rw_next(mk_sl_io_directory_iterator_pt const directory_iterator) mk_lang_noexcept
{
	mk_lang_assert(directory_iterator);

	return mk_sl_io_directory_iterator_impl_rw_next(&directory_iterator->m_base);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_io_directory_iterator_rw_is_end(mk_sl_io_directory_iterator_pt const directory_iterator, mk_lang_types_bool_pt const is) mk_lang_noexcept
{
	mk_lang_assert(directory_iterator);

	return mk_sl_io_directory_iterator_impl_rw_is_end(&directory_iterator->m_base, is);
}


#endif
