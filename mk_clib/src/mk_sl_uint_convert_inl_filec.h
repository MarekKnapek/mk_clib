#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"


#include "mk_sl_uint_convert_inl_defd.h"


enum mk_sl_uint_convert_inl_defd_ratio_e { mk_sl_uint_convert_inl_defd_ratio_v = ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_big_size_bits_v)) / ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_sml_size_bits_v)) }; typedef enum mk_sl_uint_convert_inl_defd_ratio_e mk_sl_uint_convert_inl_defd_ratio_t;

union mk_sl_uint_convert_inl_defd_converter_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_sl_uint_convert_inl_defd_big_size_bits_v / mk_lang_charbit];
	mk_sl_uint_convert_inl_defd_big_t m_big;
	mk_sl_uint_convert_inl_defd_sml_t m_smls[mk_sl_uint_convert_inl_defd_ratio_v];
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


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_convert_inl_defd_to_sml(mk_sl_uint_convert_inl_defd_big_pct const big, mk_sl_uint_convert_inl_defd_sml_pt const sml) mk_lang_noexcept
{
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_big_size_bits_v)) > ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_sml_size_bits_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_big_size_bits_v)) % ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_sml_size_bits_v)) == 0);

	mk_lang_assert(big);
	mk_lang_assert(sml);

	#if mk_lang_endian_native == mk_lang_endian_little && mk_sl_uint_convert_inl_defd_endian == mk_lang_endian_little
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_sl_uint_convert_inl_defd_sml_size_bits_v == mk_lang_charbit && ((mk_lang_types_uintptr_t)(sml)) % sizeof(*big) == 0)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_string_memcpy_uc_fn(((mk_lang_types_uchar_pt)(sml)), ((mk_lang_types_uchar_pct)(big)), mk_sl_uint_convert_inl_defd_big_size_bytes_v);
	}
	else
	#endif
	{
		mk_sl_uint_convert_inl_defd_converter_t converter mk_lang_constexpr_init;
		mk_lang_types_sint_t n mk_lang_constexpr_init;
		mk_lang_types_sint_t i mk_lang_constexpr_init;

		mk_sl_uint_convert_inl_defd_big_to_buis_uchar_le(big, &converter.m_data.m_uchars[0]);
		n = mk_sl_uint_convert_inl_defd_ratio_v;
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
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_convert_inl_defd_to_big(mk_sl_uint_convert_inl_defd_big_pt const big, mk_sl_uint_convert_inl_defd_sml_pct const sml) mk_lang_noexcept
{
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_big_size_bits_v)) > ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_sml_size_bits_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_big_size_bits_v)) % ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_sml_size_bits_v)) == 0);

	mk_lang_assert(big);
	mk_lang_assert(sml);

	#if mk_lang_endian_native == mk_lang_endian_little && mk_sl_uint_convert_inl_defd_endian == mk_lang_endian_little
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_sl_uint_convert_inl_defd_sml_size_bits_v == mk_lang_charbit && ((mk_lang_types_uintptr_t)(sml)) % sizeof(*big) == 0)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_string_memcpy_uc_fn(((mk_lang_types_uchar_pt)(big)), ((mk_lang_types_uchar_pct)(sml)), mk_sl_uint_convert_inl_defd_big_size_bytes_v);
	}
	else
	#endif
	{
		mk_lang_types_sint_t n mk_lang_constexpr_init;
		mk_lang_types_sint_t i mk_lang_constexpr_init;
		mk_sl_uint_convert_inl_defd_converter_t converter mk_lang_constexpr_init;

		n = mk_sl_uint_convert_inl_defd_ratio_v;
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
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_convert_inl_defd_to_sml_multi(mk_sl_uint_convert_inl_defd_big_pct const big, mk_sl_uint_convert_inl_defd_sml_pt const sml, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_big_size_bits_v)) > ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_sml_size_bits_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_big_size_bits_v)) % ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_sml_size_bits_v)) == 0);

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(big || count == 0);
	mk_lang_assert(sml || count == 0);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	#if mk_lang_endian_native == mk_lang_endian_little && mk_sl_uint_convert_inl_defd_endian == mk_lang_endian_little
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_sl_uint_convert_inl_defd_sml_size_bits_v == mk_lang_charbit && ((mk_lang_types_uintptr_t)(sml)) % sizeof(*big) == 0)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_string_memcpy_uc_fn(((mk_lang_types_uchar_pt)(sml)), ((mk_lang_types_uchar_pct)(big)), count * mk_sl_uint_convert_inl_defd_big_size_bytes_v);
	}
	else
	#endif
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;

		n = count;
		for(i = 0; i != n; ++i)
		{
			mk_sl_uint_convert_inl_defd_to_sml(&big[i], &sml[i * mk_sl_uint_convert_inl_defd_ratio_v]);
		}
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_convert_inl_defd_to_big_multi(mk_sl_uint_convert_inl_defd_big_pt const big, mk_sl_uint_convert_inl_defd_sml_pct const sml, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_big_size_bits_v)) > ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_sml_size_bits_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_big_size_bits_v)) % ((mk_lang_types_sint_t)(mk_sl_uint_convert_inl_defd_sml_size_bits_v)) == 0);

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(big || count == 0);
	mk_lang_assert(sml || count == 0);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	#if mk_lang_endian_native == mk_lang_endian_little && mk_sl_uint_convert_inl_defd_endian == mk_lang_endian_little
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_sl_uint_convert_inl_defd_sml_size_bits_v == mk_lang_charbit && ((mk_lang_types_uintptr_t)(sml)) % sizeof(*big) == 0)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_string_memcpy_uc_fn(((mk_lang_types_uchar_pt)(big)), ((mk_lang_types_uchar_pct)(sml)), count * mk_sl_uint_convert_inl_defd_big_size_bytes_v);
	}
	else
	#endif
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;

		n = count;
		for(i = 0; i != n; ++i)
		{
			mk_sl_uint_convert_inl_defd_to_big(&big[i], &sml[i * mk_sl_uint_convert_inl_defd_ratio_v]);
		}
	}
}


#include "mk_sl_uint_convert_inl_defu.h"
