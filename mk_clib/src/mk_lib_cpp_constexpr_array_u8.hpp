#ifndef mk_include_guard_mk_lib_cpp_constexpr_array_u8
#define mk_include_guard_mk_lib_cpp_constexpr_array_u8


#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr_array.hpp"
#include "mk_sl_cui_uint8.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14


mk_lang_nodiscard mk_lang_constexpr mk_lang_types_bool_t operator==(mk_sl_cui_uint8_t const& a, mk_sl_cui_uint8_t const& b) mk_lang_noexcept
{
	mk_lang_types_bool_t res mk_lang_constexpr_init;

	res = mk_sl_cui_uint8_eq(&a, &b);
	return res;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_types_bool_t operator!=(mk_sl_cui_uint8_t const& a, mk_sl_cui_uint8_t const& b) mk_lang_noexcept
{
	return !(a == b);
}


template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr auto mk_lib_cpp_constexpr_array_u8_from_pchar_lit(mk_lang_types_pchar_t const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, str_lit_len - 1> res mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_len >= 1);

	n = str_lit_len - 1;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_from_bi_pchar(&res[i], &str_lit[i]);
	}
	return res;
}

template<>
mk_lang_nodiscard mk_lang_constexpr auto mk_lib_cpp_constexpr_array_u8_from_pchar_lit<1>(mk_lang_types_pchar_t const(&str_lit)[1]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, 0> res mk_lang_constexpr_init;

	((mk_lang_types_void_t)(str_lit));

	return res;
}

template<mk_lang_types_usize_t hex_lit_len>
mk_lang_nodiscard mk_lang_constexpr auto mk_lib_cpp_constexpr_array_u8_from_hex_lit(mk_lang_types_pchar_t const(&hex_lit)[hex_lit_len]) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (hex_lit_len - 1) / 2> res mk_lang_constexpr_init;

	mk_lang_static_assert(hex_lit_len >= 1);
	mk_lang_static_assert((hex_lit_len - 1) % 2 == 0);

	n = (hex_lit_len - 1) / 2;
	for(i = 0; i != n; ++i)
	{
		len = mk_sl_cui_uint8_from_str_hex_n(&res[i], &hex_lit[i * 2], 2); mk_lang_assert(len == 2);
	}
	return res;
}

template<mk_lang_types_usize_t arr_len>
mk_lang_nodiscard mk_lang_constexpr auto mk_lib_cpp_constexpr_array_u8_from_u8s(mk_sl_cui_uint8_t const(&arr)[arr_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, arr_len> res mk_lang_constexpr_init;

	mk_sl_cui_uint8_memcpy_fn(res.data(), &arr[0], arr_len);
	return res;
}


#endif


#endif
