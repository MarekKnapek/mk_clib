#include "mk_lang_bool.h"
#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"


#include "mk_sl_buffer_inl_defd.h"


typedef void mk_lang_void_t;
typedef mk_lang_void_t* mk_lang_void_pt;
typedef mk_lang_void_t const* mk_lang_void_pct; /* todo move away */


struct mk_sl_buffer_inl_defd_buffer_s
{
	mk_lang_void_pt m_data;
	mk_lang_size_t m_size;
};
typedef struct mk_sl_buffer_inl_defd_buffer_s mk_sl_buffer_inl_defd_buffer_t;
typedef mk_sl_buffer_inl_defd_buffer_t const mk_sl_buffer_inl_defd_buffer_ct;
typedef mk_sl_buffer_inl_defd_buffer_t* mk_sl_buffer_inl_defd_buffer_pt;
typedef mk_sl_buffer_inl_defd_buffer_t const* mk_sl_buffer_inl_defd_buffer_pct;


mk_lang_jumbo void mk_sl_buffer_inl_defd_buffer_ro_destroy(mk_sl_buffer_inl_defd_buffer_pct const buffer) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_void_pct mk_sl_buffer_inl_defd_buffer_ro_get_data(mk_sl_buffer_inl_defd_buffer_pct const buffer) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_size_t mk_sl_buffer_inl_defd_buffer_ro_get_size(mk_sl_buffer_inl_defd_buffer_pct const buffer) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_buffer_inl_defd_buffer_ro_is_empty(mk_sl_buffer_inl_defd_buffer_pct const buffer) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_void_pct mk_sl_buffer_inl_defd_buffer_ro_get_data_at(mk_sl_buffer_inl_defd_buffer_pct const buffer, mk_lang_size_t const idx) mk_lang_noexcept;

mk_lang_jumbo void mk_sl_buffer_inl_defd_buffer_rw_construct(mk_sl_buffer_inl_defd_buffer_pt const buffer) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_buffer_inl_defd_buffer_rw_destroy(mk_sl_buffer_inl_defd_buffer_pt const buffer) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_void_pt mk_sl_buffer_inl_defd_buffer_rw_get_data(mk_sl_buffer_inl_defd_buffer_pt const buffer) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_size_t mk_sl_buffer_inl_defd_buffer_rw_get_size(mk_sl_buffer_inl_defd_buffer_pt const buffer) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_buffer_inl_defd_buffer_rw_is_empty(mk_sl_buffer_inl_defd_buffer_pct const buffer) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_void_pt mk_sl_buffer_inl_defd_buffer_rw_get_data_at(mk_sl_buffer_inl_defd_buffer_pt const buffer, mk_lang_size_t const idx) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_buffer_inl_defd_buffer_rw_resize(mk_sl_buffer_inl_defd_buffer_pt const buffer, mk_lang_exception_pt const ex, mk_lang_size_t const size) mk_lang_noexcept;


#include "mk_sl_buffer_inl_defu.h"
