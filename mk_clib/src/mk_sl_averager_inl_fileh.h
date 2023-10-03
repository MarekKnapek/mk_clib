#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_types.h"
#include "mk_lang_noexcept.h"


#include "mk_sl_averager_inl_defd.h"


struct mk_sl_averager_inl_defd_s
{
	mk_sl_averager_inl_defd_counter_t m_buff[mk_sl_averager_inl_defd_history];
	mk_sl_averager_inl_defd_counter_t m_curr_cnt;
	mk_sl_averager_inl_defd_timer_t m_curr_time;
	mk_lang_types_uint_t m_idx;
};
typedef struct mk_sl_averager_inl_defd_s mk_sl_averager_inl_defd_t;
typedef mk_sl_averager_inl_defd_t const mk_sl_averager_inl_defd_ct;
typedef mk_sl_averager_inl_defd_t* mk_sl_averager_inl_defd_pt;
typedef mk_sl_averager_inl_defd_t const* mk_sl_averager_inl_defd_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_averager_inl_defd_st_round_time(mk_sl_averager_inl_defd_timer_pt const time) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_averager_inl_defd_ro_compute(mk_sl_averager_inl_defd_pt const averager, mk_sl_averager_inl_defd_counter_pt const count) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_averager_inl_defd_rw_construct(mk_sl_averager_inl_defd_pt const averager) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_averager_inl_defd_rw_add_one(mk_sl_averager_inl_defd_pt const averager, mk_sl_averager_inl_defd_timer_pct const time) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_averager_inl_defd_rw_add_n(mk_sl_averager_inl_defd_pt const averager, mk_sl_averager_inl_defd_timer_pct const time, mk_sl_averager_inl_defd_counter_pct const count) mk_lang_noexcept;


#include "mk_sl_vector_inl_defu.h"
