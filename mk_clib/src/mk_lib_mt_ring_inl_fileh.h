#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_mutex.h"
#include "mk_lib_mt_cv.h"


#include "mk_lib_mt_ring_inl_defd.h"


#define mk_sl_ring_t_name mk_lib_mt_ring_inl_defd_ring_name
#define mk_sl_ring_t_element mk_lib_mt_ring_inl_defd_element
#define mk_sl_ring_t_count mk_lib_mt_ring_inl_defd_count
#include "mk_sl_ring_inl_fileh.h"
#undef mk_sl_ring_t_name
#undef mk_sl_ring_t_element
#undef mk_sl_ring_t_count

typedef mk_lib_mt_ring_inl_defd_ring_element_t mk_lib_mt_ring_inl_defd_element_t;
typedef mk_lib_mt_ring_inl_defd_element_t const mk_lib_mt_ring_inl_defd_element_ct;
typedef mk_lib_mt_ring_inl_defd_element_t* mk_lib_mt_ring_inl_defd_element_pt;
typedef mk_lib_mt_ring_inl_defd_element_t const* mk_lib_mt_ring_inl_defd_element_pct;

enum mk_lib_mt_ring_inl_defd_len_e{ mk_lib_mt_ring_inl_defd_len_v = mk_lib_mt_ring_inl_defd_ring_len_v };
typedef enum mk_lib_mt_ring_inl_defd_len_e mk_lib_mt_ring_inl_defd_len_t;

struct mk_lib_mt_ring_inl_defd_s
{
	mk_lib_mt_mutex_t m_mutex;
	mk_lib_mt_cv_t m_cv;
	mk_lib_mt_ring_inl_defd_ring_t m_ring;
};
typedef struct mk_lib_mt_ring_inl_defd_s mk_lib_mt_ring_inl_defd_t;
typedef mk_lib_mt_ring_inl_defd_t const mk_lib_mt_ring_inl_defd_ct;
typedef mk_lib_mt_ring_inl_defd_t* mk_lib_mt_ring_inl_defd_pt;
typedef mk_lib_mt_ring_inl_defd_t const* mk_lib_mt_ring_inl_defd_pct;


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_lib_mt_ring_inl_defd_st_capacity(mk_lang_types_void_t) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_lib_mt_ring_inl_defd_ro_capacity(mk_lib_mt_ring_inl_defd_pct const ring) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_size(mk_lib_mt_ring_inl_defd_pct const ring, mk_lang_types_usize_pt const size) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_is_empty(mk_lib_mt_ring_inl_defd_pct const ring, mk_lang_types_bool_pt const is_empty) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_is_full(mk_lib_mt_ring_inl_defd_pct const ring, mk_lang_types_bool_pt const is_full) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_at(mk_lib_mt_ring_inl_defd_pct const ring, mk_lang_types_usize_t const idx, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_front(mk_lib_mt_ring_inl_defd_pct const ring, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_back(mk_lib_mt_ring_inl_defd_pct const ring, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_lib_mt_ring_inl_defd_rw_capacity(mk_lib_mt_ring_inl_defd_pt const ring) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_size(mk_lib_mt_ring_inl_defd_pt const ring, mk_lang_types_usize_pt const size) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_is_empty(mk_lib_mt_ring_inl_defd_pt const ring, mk_lang_types_bool_pt const is_empty) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_is_full(mk_lib_mt_ring_inl_defd_pt const ring, mk_lang_types_bool_pt const is_full) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_at(mk_lib_mt_ring_inl_defd_pt const ring, mk_lang_types_usize_t const idx, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_front(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_back(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_construct(mk_lib_mt_ring_inl_defd_pt const ring) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_destroy(mk_lib_mt_ring_inl_defd_pt const ring) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_push_back(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pct const element) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_pop_back_void(mk_lib_mt_ring_inl_defd_pt const ring) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_pop_back_copy(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_push_front(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pct const element) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_pop_front_void(mk_lib_mt_ring_inl_defd_pt const ring) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_pop_front_copy(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_try_push_back(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pct const element, mk_lang_types_bool_pt const success) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_try_pop_back_void(mk_lib_mt_ring_inl_defd_pt const ring, mk_lang_types_bool_pt const success) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_try_pop_back_copy(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pt const element, mk_lang_types_bool_pt const success) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_try_push_front(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pct const element, mk_lang_types_bool_pt const success) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_try_pop_front_void(mk_lib_mt_ring_inl_defd_pt const ring, mk_lang_types_bool_pt const success) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_try_pop_front_copy(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pt const element, mk_lang_types_bool_pt const success) mk_lang_noexcept;


#include "mk_lib_mt_ring_inl_defu.h"