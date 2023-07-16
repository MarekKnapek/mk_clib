#ifndef mk_include_guard_mk_lib_cpp_constexpr
#define mk_include_guard_mk_lib_cpp_constexpr


#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_sl_uint8.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t operator==(mk_sl_cui_uint8_t const& a, mk_sl_cui_uint8_t const& b) mk_lang_noexcept
{
	return mk_sl_cui_uint8_eq(&a, &b);
}


template<typename t, mk_lang_types_usize_t n>
class mk_lib_cpp_constexpr_array_t
{
public:
	typedef t type_t;
	typedef t(&arr_t)[n];
	typedef t const(&carr_t)[n];
	static mk_lang_constexpr mk_lang_types_usize_t const s_size = n;
public:
	mk_lang_constexpr mk_lib_cpp_constexpr_array_t() mk_lang_noexcept :
		m_data()
	{
	}
	mk_lang_constexpr mk_lang_types_bool_t operator==(mk_lib_cpp_constexpr_array_t<t, n> const& other) const mk_lang_noexcept
	{
		mk_lang_types_usize_t i mk_lang_constexpr_init;

		for(i = 0; i != n; ++i)
		{
			if(!(m_data[i] == other.m_data[i]))
			{
				return mk_lang_false;
			}
		}
		return mk_lang_true;
	}
	mk_lang_constexpr mk_lang_types_bool_t operator!=(mk_lib_cpp_constexpr_array_t<t, n> const& other) const mk_lang_noexcept
	{
		return !(*this == other);
	}
	mk_lang_constexpr t& operator[](mk_lang_types_usize_t const& idx) mk_lang_noexcept
	{
		mk_lang_assert(idx < n);

		return m_data[idx];
	}
	mk_lang_constexpr t const& operator[](mk_lang_types_usize_t const& idx) const mk_lang_noexcept
	{
		mk_lang_assert(idx < n);

		return m_data[idx];
	}
	mk_lang_constexpr t* data() mk_lang_noexcept
	{
		return m_data;
	}
	mk_lang_constexpr t const* data() const mk_lang_noexcept
	{
		return m_data;
	}
	mk_lang_constexpr mk_lang_types_usize_t size() const mk_lang_noexcept
	{
		return n;
	}
	mk_lang_constexpr arr_t arr() mk_lang_noexcept
	{
		return m_data;
	}
	mk_lang_constexpr carr_t arr() const mk_lang_noexcept
	{
		return m_data;
	}
private:
	t m_data[n];
};

template<typename t>
class mk_lib_cpp_constexpr_array_t<t, 0>
{
public:
	typedef t type_t;
	static mk_lang_constexpr mk_lang_types_usize_t const s_size = 0;
public:
	mk_lang_constexpr mk_lib_cpp_constexpr_array_t() mk_lang_noexcept
	{
	}
	mk_lang_constexpr mk_lang_types_bool_t operator==(mk_lib_cpp_constexpr_array_t<t, 0> const& other) const mk_lang_noexcept
	{
		return mk_lang_true;
	}
	mk_lang_constexpr mk_lang_types_bool_t operator!=(mk_lib_cpp_constexpr_array_t<t, 0> const& other) const mk_lang_noexcept
	{
		return !(*this == other);
	}
	mk_lang_constexpr t* data() mk_lang_noexcept
	{
		return mk_lang_null;
	}
	mk_lang_constexpr t const* data() const mk_lang_noexcept
	{
		return mk_lang_null;
	}
	mk_lang_constexpr mk_lang_types_usize_t size() const mk_lang_noexcept
	{
		return 0;
	}
};


#endif


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_uchar_t mk_lib_cpp_constexpr_char_to_nibble(char const ch) mk_lang_noexcept
{
	mk_lang_constexpr_static char const s_alphabet_lc[] = "0123456789abcdef";
	mk_lang_constexpr_static char const s_alphabet_uc[] = "0123456789ABCDEF";

	int i mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(s_alphabet_lc) == sizeof(s_alphabet_uc));

	for(i = 0; i != ((int)(sizeof(s_alphabet_lc))) - 1; ++i)
	{
		if(ch == s_alphabet_lc[i])
		{
			break;
		}
		if(ch == s_alphabet_uc[i])
		{
			break;
		}
	}
	return ((mk_lang_types_uchar_t)(i));
}


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14


template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo void mk_lib_cpp_constexpr_hex_str_lit_to_u8s_ptr(mk_sl_cui_uint8_pt const dst, char const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t hi mk_lang_constexpr_init;
	mk_lang_types_uchar_t lo mk_lang_constexpr_init;
	mk_lang_types_uchar_t byte mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_len >= 1);
	mk_lang_static_assert((str_lit_len - 1) % 2 == 0);

	mk_lang_assert(dst);

	for(i = 0; i != (str_lit_len - 1) / 2; ++i)
	{
		hi = mk_lib_cpp_constexpr_char_to_nibble(str_lit[i * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
		lo = mk_lib_cpp_constexpr_char_to_nibble(str_lit[i * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
		byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
		mk_sl_cui_uint8_from_bi_uchar(&dst[i], &byte);
	}
}

template<mk_lang_types_usize_t dst_len, mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo void mk_lib_cpp_constexpr_hex_str_lit_to_u8s_arr(mk_sl_cui_uint8_t(&dst)[dst_len], char const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lang_static_assert(dst_len >= 0);
	mk_lang_static_assert(str_lit_len >= 1);
	mk_lang_static_assert((str_lit_len - 1) % 2 == 0);
	mk_lang_static_assert(dst_len >= (str_lit_len - 1) / 2);

	mk_lib_cpp_constexpr_hex_str_lit_to_u8s_ptr(dst, str_lit);
}

template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_cpp_constexpr_hex_str_lit_to_u8s(char const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (str_lit_len - 1) / 2> ret;

	mk_lang_static_assert(str_lit_len >= 1);
	mk_lang_static_assert((str_lit_len - 1) % 2 == 0);

	mk_lib_cpp_constexpr_hex_str_lit_to_u8s_arr(ret.arr(), str_lit);
	return ret;
}

template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo void mk_lib_cpp_constexpr_str_lit_to_u8s_ptr(mk_sl_cui_uint8_pt const dst, char const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_len >= 1);

	mk_lang_assert(dst);

	for(i = 0; i != str_lit_len - 1; ++i)
	{
		mk_sl_cui_uint8_from_bi_pchar(&dst[i], &str_lit[i]);
	}
}

template<mk_lang_types_usize_t dst_len, mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo void mk_lib_cpp_constexpr_str_lit_to_u8s_arr(mk_sl_cui_uint8_t(&dst)[dst_len], char const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lang_static_assert(dst_len >= 0);
	mk_lang_static_assert(str_lit_len >= 1);
	mk_lang_static_assert(dst_len >= str_lit_len - 1);

	mk_lib_cpp_constexpr_str_lit_to_u8s_ptr(dst, str_lit);
}

template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_cpp_constexpr_str_lit_to_u8s(char const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, str_lit_len - 1> ret mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_len >= 1);

	mk_lib_cpp_constexpr_str_lit_to_u8s_arr(ret.arr(), str_lit);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_cpp_constexpr_str_lit_to_u8s(char const(&)[1]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, 0> ret mk_lang_constexpr_init;

	return ret;
}


#endif


#endif
