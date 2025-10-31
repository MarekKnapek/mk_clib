#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


#include "mk_sl_bui_inl_defd.h"


union mk_sl_bui_inl_defd_convertor_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_sl_bui_inl_defd_count];
	mk_sl_cui_uint8_t m_uint8s[mk_sl_bui_inl_defd_count];
	mk_sl_bui_inl_defd_base_t m_bui;
};
typedef union mk_sl_bui_inl_defd_convertor_data_u mk_sl_bui_inl_defd_convertor_data_t;
struct mk_sl_bui_inl_defd_convertor_s
{
	mk_sl_bui_inl_defd_convertor_data_t m_data;
};
typedef struct mk_sl_bui_inl_defd_convertor_s mk_sl_bui_inl_defd_convertor_t;


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_bui_inl_defd_pr_from_uint8s_le(mk_sl_bui_inl_defd_base_pt const bui, mk_lang_static_param(mk_sl_cui_uint8_ct, uint8s, mk_sl_bui_inl_defd_count)) mk_lang_noexcept
{
	mk_sl_bui_inl_defd_convertor_t convertor mk_lang_constexpr_init;

	mk_lang_assert(bui);
	mk_lang_assert(uint8s);

	mk_sl_cui_uint8_to_bi_uchar_many(&uint8s[0], &convertor.m_data.m_uchars[0], mk_sl_bui_inl_defd_count);
	mk_sl_bui_inl_defd_base_from_buis_uchar_le(bui, &convertor.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_bui_inl_defd_pr_from_uint8s_be(mk_sl_bui_inl_defd_base_pt const bui, mk_lang_static_param(mk_sl_cui_uint8_ct, uint8s, mk_sl_bui_inl_defd_count)) mk_lang_noexcept
{
	mk_sl_bui_inl_defd_convertor_t convertor mk_lang_constexpr_init;

	mk_lang_assert(bui);
	mk_lang_assert(uint8s);

	mk_sl_cui_uint8_to_bi_uchar_many(&uint8s[0], &convertor.m_data.m_uchars[0], mk_sl_bui_inl_defd_count);
	mk_sl_bui_inl_defd_base_from_buis_uchar_be(bui, &convertor.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_bui_inl_defd_pr_from_uint8s_ne(mk_sl_bui_inl_defd_base_pt const bui, mk_lang_static_param(mk_sl_cui_uint8_ct, uint8s, mk_sl_bui_inl_defd_count)) mk_lang_noexcept
{
	mk_sl_bui_inl_defd_convertor_t convertor mk_lang_constexpr_init;

	mk_lang_assert(bui);
	mk_lang_assert(uint8s);

	mk_sl_cui_uint8_to_bi_uchar_many(&uint8s[0], &convertor.m_data.m_uchars[0], mk_sl_bui_inl_defd_count);
	mk_sl_bui_inl_defd_base_from_buis_uchar_ne(bui, &convertor.m_data.m_uchars[0]);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_bui_inl_defd_from_uint8s_le(mk_sl_bui_inl_defd_base_pt const bui, mk_lang_static_param(mk_sl_cui_uint8_ct, uint8s, mk_sl_bui_inl_defd_count)) mk_lang_noexcept
{
	mk_sl_bui_inl_defd_pr_from_uint8s_le(bui, uint8s);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_bui_inl_defd_from_uint8s_be(mk_sl_bui_inl_defd_base_pt const bui, mk_lang_static_param(mk_sl_cui_uint8_ct, uint8s, mk_sl_bui_inl_defd_count)) mk_lang_noexcept
{
	mk_sl_bui_inl_defd_pr_from_uint8s_be(bui, uint8s);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_bui_inl_defd_from_uint8s_ne(mk_sl_bui_inl_defd_base_pt const bui, mk_lang_static_param(mk_sl_cui_uint8_ct, uint8s, mk_sl_bui_inl_defd_count)) mk_lang_noexcept
{
	mk_sl_bui_inl_defd_pr_from_uint8s_ne(bui, uint8s);
}


#include "mk_sl_bui_inl_defu.h"
