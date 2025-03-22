#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"


#include "mk_sl_uint_convert_inl_defd.h"


union mk_sl_uint_convert_inl_defd_converter_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_sl_uint_convert_inl_defd_big_size_bits_v / mk_lang_charbit];
	mk_sl_uint_convert_inl_defd_big_t m_big;
	mk_sl_uint_convert_inl_defd_sml_t m_smls[((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_big_size_bits_v)) / ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_sml_size_bits_v))];
};
typedef union mk_sl_uint_convert_inl_defd_converter_data_u mk_sl_uint_convert_inl_defd_converter_data_t;
struct mk_sl_uint_convert_inl_defd_converter_s
{
	mk_sl_uint_convert_inl_defd_converter_data_t m_data;
};
typedef struct mk_sl_uint_convert_inl_defd_converter_s mk_sl_uint_convert_inl_defd_converter_t;
typedef mk_sl_uint_convert_inl_defd_converter_t const mk_sl_uint_convert_inl_defd_converter_ct;
typedef mk_sl_uint_convert_inl_defd_converter_t* mk_sl_uint_convert_inl_defd_converter_pt;
typedef mk_sl_uint_convert_inl_defd_converter_t const* mk_sl_uint_convert_inl_defd_converter_pct;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_convert_inl_defd_to_sml(mk_sl_uint_convert_inl_defd_big_pct const big, mk_lang_static_param(mk_sl_uint_convert_inl_defd_sml_t, sml, mk_sl_uint_convert_inl_defd_big_size_bits_v / mk_sl_uint_convert_inl_defd_sml_size_bits_v)) mk_lang_noexcept
{
	mk_sl_uint_convert_inl_defd_converter_t converter mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_big_size_bits_v)) % ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_sml_size_bits_v)) == 0);

	mk_lang_assert(big);
	mk_lang_assert(sml);

	mk_sl_uint_convert_inl_defd_big_to_buis_uchar_le(big, &converter.m_data.m_uchars[0]);
	n = ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_big_size_bits_v)) / ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_sml_size_bits_v));
	for(i = 0; i != n; ++i)
	{
		#if mk_sl_uint_convert_inl_defd_endian == mk_lang_endian_little
		mk_sl_uint_convert_inl_defd_sml_from_buis_uchar_le(&sml[i], &converter.m_data.m_uchars[i * (mk_sl_uint_convert_inl_defd_sml_size_bits_v / mk_lang_charbit)]);
		#elif mk_sl_uint_convert_inl_defd_endian == mk_lang_endian_big
		mk_sl_uint_convert_inl_defd_sml_from_buis_uchar_le(&sml[i], &converter.m_data.m_uchars[(mk_lang_countof(converter.m_data.m_uchars) - 1) - i * (mk_sl_uint_convert_inl_defd_sml_size_bits_v / mk_lang_charbit)]);
		#else
		#error xxxxxxxxxx
		#endif
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_convert_inl_defd_to_big(mk_sl_uint_convert_inl_defd_big_pt const big, mk_lang_static_param(mk_sl_uint_convert_inl_defd_sml_ct, sml, mk_sl_uint_convert_inl_defd_big_size_bits_v / mk_sl_uint_convert_inl_defd_sml_size_bits_v)) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_uint_convert_inl_defd_converter_t converter mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_big_size_bits_v)) % ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_sml_size_bits_v)) == 0);

	mk_lang_assert(big);
	mk_lang_assert(sml);

	n = ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_big_size_bits_v)) / ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_sml_size_bits_v));
	for(i = 0; i != n; ++i)
	{
		#if mk_sl_uint_convert_inl_defd_endian == mk_lang_endian_little
		mk_sl_uint_convert_inl_defd_sml_to_buis_uchar_le(&sml[i], &converter.m_data.m_uchars[i * (mk_sl_uint_convert_inl_defd_sml_size_bits_v / mk_lang_charbit)]);
		#elif mk_sl_uint_convert_inl_defd_endian == mk_lang_endian_big
		mk_sl_uint_convert_inl_defd_sml_to_buis_uchar_le(&sml[i], &converter.m_data.m_uchars[(mk_lang_countof(converter.m_data.m_uchars) - 1) - i * (mk_sl_uint_convert_inl_defd_sml_size_bits_v / mk_lang_charbit)]);
		#else
		#error xxxxxxxxxx
		#endif
	}
	mk_sl_uint_convert_inl_defd_big_from_buis_uchar_le(big, &converter.m_data.m_uchars[0]);
}


#include "mk_sl_uint_convert_inl_defu.h"
