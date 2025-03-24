#ifndef mk_include_guard_mk_lib_cpp_constexpr_array
#define mk_include_guard_mk_lib_cpp_constexpr_array


#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14


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
	mk_lang_nodiscard mk_lang_constexpr mk_lang_types_bool_t eq(mk_lib_cpp_constexpr_array_t<t, n> const& other) const mk_lang_noexcept
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
	mk_lang_nodiscard mk_lang_constexpr mk_lang_types_bool_t ne(mk_lib_cpp_constexpr_array_t<t, n> const& other) const mk_lang_noexcept
	{
		return !eq(other);
	}
	mk_lang_nodiscard mk_lang_constexpr t const& at(mk_lang_types_usize_t const& idx) const mk_lang_noexcept
	{
		mk_lang_assert(idx < n);

		return m_data[idx];
	}
	mk_lang_nodiscard mk_lang_constexpr t& at(mk_lang_types_usize_t const& idx) mk_lang_noexcept
	{
		mk_lang_assert(idx < n);

		return m_data[idx];
	}
	mk_lang_nodiscard mk_lang_constexpr t const& cat(mk_lang_types_usize_t const& idx) const mk_lang_noexcept
	{
		mk_lang_assert(idx < n);

		return m_data[idx];
	}
	mk_lang_nodiscard mk_lang_constexpr mk_lang_types_bool_t operator==(mk_lib_cpp_constexpr_array_t<t, n> const& other) const mk_lang_noexcept
	{
		return eq(other);
	}
	mk_lang_nodiscard mk_lang_constexpr mk_lang_types_bool_t operator!=(mk_lib_cpp_constexpr_array_t<t, n> const& other) const mk_lang_noexcept
	{
		return ne(other);
	}
	mk_lang_nodiscard mk_lang_constexpr t const& operator[](mk_lang_types_usize_t const& idx) const mk_lang_noexcept
	{
		mk_lang_assert(idx < n);

		return at(idx);
	}
	mk_lang_nodiscard mk_lang_constexpr t& operator[](mk_lang_types_usize_t const& idx) mk_lang_noexcept
	{
		mk_lang_assert(idx < n);

		return at(idx);
	}
	mk_lang_nodiscard mk_lang_constexpr t const* data() const mk_lang_noexcept
	{
		return &m_data[0];
	}
	mk_lang_nodiscard mk_lang_constexpr t* data() mk_lang_noexcept
	{
		return &m_data[0];
	}
	mk_lang_nodiscard mk_lang_constexpr t const* cdata() const mk_lang_noexcept
	{
		return &m_data[0];
	}
	mk_lang_nodiscard mk_lang_constexpr mk_lang_types_usize_t size() const mk_lang_noexcept
	{
		return n;
	}
	mk_lang_nodiscard mk_lang_constexpr carr_t arr() const mk_lang_noexcept
	{
		return m_data;
	}
	mk_lang_nodiscard mk_lang_constexpr arr_t arr() mk_lang_noexcept
	{
		return m_data;
	}
	mk_lang_nodiscard mk_lang_constexpr carr_t carr() const mk_lang_noexcept
	{
		return m_data;
	}
	mk_lang_nodiscard mk_lang_constexpr mk_lib_cpp_constexpr_array_t<t, n> reverse() const mk_lang_noexcept
	{
		mk_lang_types_usize_t i mk_lang_constexpr_init;
		mk_lib_cpp_constexpr_array_t<t, n> ret mk_lang_constexpr_init;

		for(i = 0; i != n; ++i)
		{
			ret.at((n - 1) - i) = at(i);
		}
		return ret;
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
	mk_lang_nodiscard mk_lang_constexpr mk_lang_types_bool_t eq(mk_lib_cpp_constexpr_array_t<t, 0> const& other) const mk_lang_noexcept
	{
		((mk_lang_types_void_t)(other));
		return mk_lang_true;
	}
	mk_lang_nodiscard mk_lang_constexpr mk_lang_types_bool_t ne(mk_lib_cpp_constexpr_array_t<t, 0> const& other) const mk_lang_noexcept
	{
		return !eq(other);
	}
	mk_lang_nodiscard mk_lang_constexpr mk_lang_types_bool_t operator==(mk_lib_cpp_constexpr_array_t<t, 0> const& other) const mk_lang_noexcept
	{
		return eq(other);
	}
	mk_lang_nodiscard mk_lang_constexpr mk_lang_types_bool_t operator!=(mk_lib_cpp_constexpr_array_t<t, 0> const& other) const mk_lang_noexcept
	{
		return ne(other);
	}
	mk_lang_nodiscard mk_lang_constexpr t const* data() const mk_lang_noexcept
	{
		return mk_lang_null;
	}
	mk_lang_nodiscard mk_lang_constexpr t* data() mk_lang_noexcept
	{
		return mk_lang_null;
	}
	mk_lang_nodiscard mk_lang_constexpr t const* cdata() const mk_lang_noexcept
	{
		return mk_lang_null;
	}
	mk_lang_nodiscard mk_lang_constexpr mk_lang_types_usize_t size() const mk_lang_noexcept
	{
		return 0;
	}
	mk_lang_nodiscard mk_lang_constexpr mk_lib_cpp_constexpr_array_t<t, 0> reverse() const mk_lang_noexcept
	{
		mk_lib_cpp_constexpr_array_t<t, 0> ret mk_lang_constexpr_init;

		return ret;
	}
};


#endif


#endif
