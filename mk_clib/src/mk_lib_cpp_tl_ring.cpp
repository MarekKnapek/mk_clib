#include "mk_lib_cpp_tl_ring.hpp"

#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_14


#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"

#include <condition_variable>
#include <mutex>


template<typename t> mk::tl::ring_t<t>::ring_t() mk_lang_noexcept :
	m_mutex(),
	m_cv()
{
	construct();
}

template<typename t> mk_lang_nodiscard mk_lang_types_bool_t mk::tl::ring_t<t>::is_empty() const mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		return m_ring.is_empty();
	}
}

template<typename t> mk_lang_nodiscard mk_lang_types_bool_t mk::tl::ring_t<t>::is_full() const mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		return m_ring.is_full();
	}
}

template<typename t> mk_lang_nodiscard mk_lang_types_usize_t mk::tl::ring_t<t>::get_size() const mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		return m_ring.get_size();
	}
}

template<typename t> mk_lang_nodiscard mk_lang_types_usize_t mk::tl::ring_t<t>::get_capacity() const mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		return m_ring.get_capacity();
	}
}

template<typename t> mk_lang_nodiscard typename mk::tl::ring_t<t>::e_t const& mk::tl::ring_t<t>::get_elem(mk_lang_types_usize_t const idx) const mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		return *m_ring.get_elem(idx);
	}
}

template<typename t> mk_lang_nodiscard typename mk::tl::ring_t<t>::e_t const& mk::tl::ring_t<t>::get_head() const mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		return *m_ring.get_head();
	}
}

template<typename t> mk_lang_nodiscard typename mk::tl::ring_t<t>::e_t const& mk::tl::ring_t<t>::get_tail() const mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		return *m_ring.get_tail();
	}
}

template<typename t> mk_lang_nodiscard mk_lang_types_bool_t mk::tl::ring_t<t>::is_empty() mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		return m_ring.is_empty();
	}
}

template<typename t> mk_lang_nodiscard mk_lang_types_bool_t mk::tl::ring_t<t>::is_full() mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		return m_ring.is_full();
	}
}

template<typename t> mk_lang_nodiscard mk_lang_types_usize_t mk::tl::ring_t<t>::get_size() mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		return m_ring.get_size();
	}
}

template<typename t> mk_lang_nodiscard mk_lang_types_usize_t mk::tl::ring_t<t>::get_capacity() mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		return m_ring.get_capacity();
	}
}

template<typename t> mk_lang_nodiscard typename mk::tl::ring_t<t>::e_t& mk::tl::ring_t<t>::get_elem(mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		return *m_ring.get_elem(idx);
	}
}

template<typename t> mk_lang_nodiscard typename mk::tl::ring_t<t>::e_t& mk::tl::ring_t<t>::get_head() mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		return *m_ring.get_head();
	}
}

template<typename t> mk_lang_nodiscard typename mk::tl::ring_t<t>::e_t& mk::tl::ring_t<t>::get_tail() mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		return *m_ring.get_tail();
	}
}

template<typename t> void mk::tl::ring_t<t>::construct() mk_lang_noexcept
{
	{
		std::lock_guard<std::mutex> const grd{m_mutex};
		m_ring.construct();
	}
}

template<typename t> void mk::tl::ring_t<t>::push() mk_lang_noexcept
{
	{
		std::unique_lock<std::mutex> grd{m_mutex};
		if(m_ring.is_full())
		{
			auto const self = this;
			m_cv.wait(grd, [self](){ return !self->m_ring.is_full(); });
		}
		m_ring.push_void();
	}
	m_cv.notify_one();
}

template<typename t> void mk::tl::ring_t<t>::push(mk::tl::ring_t<t>::e_t const& elem) mk_lang_noexcept
{
	{
		std::unique_lock<std::mutex> grd{m_mutex};
		if(m_ring.is_full())
		{
			auto const self = this;
			m_cv.wait(grd, [self](){ return !self->m_ring.is_full(); });
		}
		m_ring.push_elem(&elem);
	}
	m_cv.notify_one();
}

template<typename t> mk_lang_nodiscard typename mk::tl::ring_t<t>::e_t mk::tl::ring_t<t>::pop() mk_lang_noexcept
{
	e_t r;
	{
		std::unique_lock<std::mutex> grd{m_mutex};
		if(m_ring.is_empty())
		{
			auto const self = this;
			m_cv.wait(grd, [self](){ return !self->m_ring.is_empty(); });
		}
		r = *m_ring.get_head();
		m_ring.pop();
	}
	m_cv.notify_one();
	return r;
}


#endif
