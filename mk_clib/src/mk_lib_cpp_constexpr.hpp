#ifndef mk_include_guard_mk_lib_cpp_constexpr
#define mk_include_guard_mk_lib_cpp_constexpr


#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14


template<typename t, mk_lang_types_usize_t n>
class mk_lib_cpp_constexpr_array_t
{
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


#endif


#endif
