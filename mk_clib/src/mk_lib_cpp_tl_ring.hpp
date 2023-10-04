#ifndef mk_include_guard_mk_lib_cpp_tl_ring
#define mk_include_guard_mk_lib_cpp_tl_ring


#include "mk_lang_jumbo.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_14


#include "mk_lang_constexpr.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include <condition_variable>
#include <mutex>


namespace mk
{
	namespace wrapper
	{
		template
		<
			typename t,
			typename e,
			mk_lang_types_bool_t(*ro_is_empty)(t const*) mk_lang_noexcept,
			mk_lang_types_bool_t(*ro_is_full)(t const*) mk_lang_noexcept,
			mk_lang_types_usize_t(*ro_get_size)(t const*) mk_lang_noexcept,
			mk_lang_types_usize_t(*ro_get_capacity)(t const*) mk_lang_noexcept,
			mk_lang_types_usize_t(*ro_get_free)(t const*) mk_lang_noexcept,
			e const*(*ro_get_elem)(t const*, mk_lang_types_usize_t) mk_lang_noexcept,
			e const*(*ro_get_head)(t const*) mk_lang_noexcept,
			e const*(*ro_get_tail)(t const*) mk_lang_noexcept,
			mk_lang_types_bool_t(*rw_is_empty)(t*) mk_lang_noexcept,
			mk_lang_types_bool_t(*rw_is_full)(t*) mk_lang_noexcept,
			mk_lang_types_usize_t(*rw_get_size)(t*) mk_lang_noexcept,
			mk_lang_types_usize_t(*rw_get_capacity)(t*) mk_lang_noexcept,
			mk_lang_types_usize_t(*rw_get_free)(t*) mk_lang_noexcept,
			e*(*rw_get_elem)(t*, mk_lang_types_usize_t) mk_lang_noexcept,
			e*(*rw_get_head)(t*) mk_lang_noexcept,
			e*(*rw_get_tail)(t*) mk_lang_noexcept,
			void(*rw_construct)(t*) mk_lang_noexcept,
			void(*rw_push_void)(t*) mk_lang_noexcept,
			void(*rw_push_elem)(t*, e const*) mk_lang_noexcept,
			void(*rw_pop)(t*) mk_lang_noexcept
		>
		class ring_t
		{
		public:
			typedef t t_t;
			typedef e e_t;
		public:
			mk_lang_nodiscard mk_lang_constexpr mk_lang_types_bool_t is_empty() const mk_lang_noexcept { return ro_is_empty(&m_wrapped); }
			mk_lang_nodiscard mk_lang_constexpr mk_lang_types_bool_t is_full() const mk_lang_noexcept { return ro_is_full(&m_wrapped); }
			mk_lang_nodiscard mk_lang_constexpr mk_lang_types_usize_t get_size() const mk_lang_noexcept { return ro_get_size(&m_wrapped); }
			mk_lang_nodiscard mk_lang_constexpr mk_lang_types_usize_t get_capacity() const mk_lang_noexcept { return ro_get_capacity(&m_wrapped); }
			mk_lang_nodiscard mk_lang_constexpr mk_lang_types_usize_t get_free() const mk_lang_noexcept { return ro_get_free(&m_wrapped); }
			mk_lang_nodiscard mk_lang_constexpr e const* get_elem(mk_lang_types_usize_t const idx) const mk_lang_noexcept { return ro_get_elem(&m_wrapped, idx); }
			mk_lang_nodiscard mk_lang_constexpr e const* get_head() const mk_lang_noexcept { return ro_get_head(&m_wrapped); }
			mk_lang_nodiscard mk_lang_constexpr e const* get_tail() const mk_lang_noexcept { return ro_get_tail(&m_wrapped); }
			mk_lang_nodiscard mk_lang_constexpr mk_lang_types_bool_t is_empty() mk_lang_noexcept { return rw_is_empty(&m_wrapped); }
			mk_lang_nodiscard mk_lang_constexpr mk_lang_types_bool_t is_full() mk_lang_noexcept { return rw_is_full(&m_wrapped); }
			mk_lang_nodiscard mk_lang_constexpr mk_lang_types_usize_t get_size() mk_lang_noexcept { return rw_get_size(&m_wrapped); }
			mk_lang_nodiscard mk_lang_constexpr mk_lang_types_usize_t get_capacity() mk_lang_noexcept { return rw_get_capacity(&m_wrapped); }
			mk_lang_nodiscard mk_lang_constexpr mk_lang_types_usize_t get_free() mk_lang_noexcept { return rw_get_free(&m_wrapped); }
			mk_lang_nodiscard mk_lang_constexpr e* get_elem(mk_lang_types_usize_t const idx) mk_lang_noexcept { return rw_get_elem(&m_wrapped, idx); }
			mk_lang_nodiscard mk_lang_constexpr e* get_head() mk_lang_noexcept { return rw_get_head(&m_wrapped); }
			mk_lang_nodiscard mk_lang_constexpr e* get_tail() mk_lang_noexcept { return rw_get_tail(&m_wrapped); }
			mk_lang_constexpr void construct() mk_lang_noexcept { rw_construct(&m_wrapped); }
			mk_lang_constexpr void push_void() mk_lang_noexcept { rw_push_void(&m_wrapped); }
			mk_lang_constexpr void push_elem(e const* const elem) mk_lang_noexcept { rw_push_elem(&m_wrapped, elem); }
			mk_lang_constexpr void pop() mk_lang_noexcept { rw_pop(&m_wrapped); }
		private:
			t m_wrapped;
		};
	}
}

namespace mk
{
	namespace tl
	{
		template<typename t>
		class ring_t
		{
		public:
			typedef t t_t;
			typedef typename t::e_t e_t;
		public:
			ring_t() mk_lang_noexcept;
			ring_t(mk::tl::ring_t<t> const&) mk_lang_noexcept = delete;
			ring_t(mk::tl::ring_t<t>&&) mk_lang_noexcept = delete;
			mk::tl::ring_t<t>& operator=(mk::tl::ring_t<t> const&) mk_lang_noexcept = delete;
			mk::tl::ring_t<t>& operator=(mk::tl::ring_t<t>&&) mk_lang_noexcept = delete;
		public:
			mk_lang_nodiscard mk_lang_types_bool_t is_empty() const mk_lang_noexcept;
			mk_lang_nodiscard mk_lang_types_bool_t is_full() const mk_lang_noexcept;
			mk_lang_nodiscard mk_lang_types_usize_t get_size() const mk_lang_noexcept;
			mk_lang_nodiscard mk_lang_types_usize_t get_capacity() const mk_lang_noexcept;
			mk_lang_nodiscard e_t const& get_elem(mk_lang_types_usize_t const idx) const mk_lang_noexcept;
			mk_lang_nodiscard e_t const& get_head() const mk_lang_noexcept;
			mk_lang_nodiscard e_t const& get_tail() const mk_lang_noexcept;
			mk_lang_nodiscard mk_lang_types_bool_t is_empty() mk_lang_noexcept;
			mk_lang_nodiscard mk_lang_types_bool_t is_full() mk_lang_noexcept;
			mk_lang_nodiscard mk_lang_types_usize_t get_size() mk_lang_noexcept;
			mk_lang_nodiscard mk_lang_types_usize_t get_capacity() mk_lang_noexcept;
			mk_lang_nodiscard e_t& get_elem(mk_lang_types_usize_t const idx) mk_lang_noexcept;
			mk_lang_nodiscard e_t& get_head() mk_lang_noexcept;
			mk_lang_nodiscard e_t& get_tail() mk_lang_noexcept;
			void construct() mk_lang_noexcept;
			void push() mk_lang_noexcept;
			void push(e_t const& elem) mk_lang_noexcept;
			mk_lang_nodiscard e_t pop() mk_lang_noexcept;
		private:
			std::mutex m_mutex;
			std::condition_variable_any m_cv;
			t m_ring;
		};
	}
}


#endif


#if mk_lang_jumbo_want == 1
#include "mk_lib_cpp_tl_ring.cpp"
#endif
#endif
