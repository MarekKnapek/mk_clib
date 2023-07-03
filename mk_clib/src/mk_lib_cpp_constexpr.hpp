#ifndef mk_include_guard_mk_lib_cpp_constexpr
#define mk_include_guard_mk_lib_cpp_constexpr


#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


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


template<typename t, mk_lang_types_usize_t n>
class mk_lib_cpp_constexpr_array_t
{
public:
	typedef t type_t;
	static mk_lang_types_usize_t const s_size = n;

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

private:
	t m_data[n];
};


template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_cpp_constexpr_hex_str_lit_to_bytes(char const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_lang_types_usize_t const s_len = str_lit_len - 1;

	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t hi mk_lang_constexpr_init;
	mk_lang_types_uchar_t lo mk_lang_constexpr_init;
	mk_lang_types_uchar_t byte mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, s_len / 2> ret mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_len >= 1);
	mk_lang_static_assert(s_len % 2 == 0);

	for(i = 0; i != s_len / 2; ++i)
	{
		hi = mk_lib_cpp_constexpr_char_to_nibble(str_lit[i * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
		lo = mk_lib_cpp_constexpr_char_to_nibble(str_lit[i * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
		byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
		ret[i] = byte;
	}
	return ret;
}


#endif


#endif
