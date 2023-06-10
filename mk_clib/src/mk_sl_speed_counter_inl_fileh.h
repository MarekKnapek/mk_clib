#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


#include "mk_sl_speed_counter_inl_defd.h"


struct mk_sl_speed_counter_inl_defd_s
{
	mk_sl_speed_counter_inl_defd_item_t m_items_counts[mk_sl_speed_counter_inl_defd_time_granule_count];
	mk_sl_speed_counter_inl_defd_item_t m_curr_items_count;
	mk_sl_speed_counter_inl_defd_time_t m_curr_time_quantized;
};
typedef struct mk_sl_speed_counter_inl_defd_s mk_sl_speed_counter_inl_defd_t;
typedef mk_sl_speed_counter_inl_defd_t const mk_sl_speed_counter_inl_defd_ct;
typedef mk_sl_speed_counter_inl_defd_t* mk_sl_speed_counter_inl_defd_pt;
typedef mk_sl_speed_counter_inl_defd_t const* mk_sl_speed_counter_inl_defd_pct;


mk_lang_jumbo void mk_sl_speed_counter_inl_defd_construct(mk_sl_speed_counter_inl_defd_pt const counter) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_speed_counter_inl_defd_count(mk_sl_speed_counter_inl_defd_pt const counter, mk_sl_speed_counter_inl_defd_item_pct const how_many, mk_sl_speed_counter_inl_defd_time_pct const when) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_speed_counter_inl_defd_get_time_quantized(mk_sl_speed_counter_inl_defd_pct const counter, mk_sl_speed_counter_inl_defd_time_pt const time_quantized) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_speed_counter_inl_defd_get_speed(mk_sl_speed_counter_inl_defd_pct const counter, mk_sl_speed_counter_inl_defd_item_pt const speed) mk_lang_noexcept;


#include "mk_sl_speed_counter_inl_defu.h"
