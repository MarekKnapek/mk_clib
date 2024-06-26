#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_sl_fixed_vector_inl_defd.h"


#define mk_sl_array_t_name mk_sl_fixed_vector_inl_defd_array_name
#define mk_sl_array_t_element mk_sl_fixed_vector_inl_defd_element
#define mk_sl_array_t_count mk_sl_fixed_vector_inl_defd_count
#include "mk_sl_array_inl_fileh.h"
#undef mk_sl_array_t_name
#undef mk_sl_array_t_element
#undef mk_sl_array_t_count

typedef mk_sl_fixed_vector_inl_defd_array_element_t mk_sl_fixed_vector_inl_defd_element_t;
typedef mk_sl_fixed_vector_inl_defd_element_t const mk_sl_fixed_vector_inl_defd_element_ct;
typedef mk_sl_fixed_vector_inl_defd_element_t* mk_sl_fixed_vector_inl_defd_element_pt;
typedef mk_sl_fixed_vector_inl_defd_element_t const* mk_sl_fixed_vector_inl_defd_element_pct;

enum mk_sl_fixed_vector_inl_defd_len_e{ mk_sl_fixed_vector_inl_defd_len_v = mk_sl_fixed_vector_inl_defd_array_len_v };
typedef enum mk_sl_fixed_vector_inl_defd_len_e mk_sl_fixed_vector_inl_defd_len_t;

struct mk_sl_fixed_vector_inl_defd_s
{
	mk_sl_fixed_vector_inl_defd_array_t m_array;
	mk_lang_types_usize_t m_size;
};
typedef struct mk_sl_fixed_vector_inl_defd_s mk_sl_fixed_vector_inl_defd_t;
typedef mk_sl_fixed_vector_inl_defd_t const mk_sl_fixed_vector_inl_defd_ct;
typedef mk_sl_fixed_vector_inl_defd_t* mk_sl_fixed_vector_inl_defd_pt;
typedef mk_sl_fixed_vector_inl_defd_t const* mk_sl_fixed_vector_inl_defd_pct;


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_st_capacity(mk_lang_types_void_t) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_ro_capacity(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_ro_size(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_ro_free(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_ro_is_empty(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_ro_is_full(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_ro_at(mk_sl_fixed_vector_inl_defd_pct const fixed_vector, mk_lang_types_usize_t const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_ro_data(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_ro_front(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_ro_back(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_rw_capacity(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_rw_size(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_rw_free(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_rw_is_empty(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_rw_is_full(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_at(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_data(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_front(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_back(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_fixed_vector_inl_defd_rw_construct(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_push_back_many(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_element_pct const elements, mk_lang_types_usize_t const count) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_push_back_one(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_element_pct const element) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_push_back_void(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_pop_back_one(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_pop_back_many(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept;


#include "mk_sl_fixed_vector_inl_defu.h"
