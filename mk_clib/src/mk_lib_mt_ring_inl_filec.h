#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_mt_cv.h"
#include "mk_lib_mt_mutex.h"
#include "mk_lib_mt_unique_lock.h"


#include "mk_lib_mt_ring_inl_defd.h"


#define mk_sl_ring_t_name mk_lib_mt_ring_inl_defd_ring_name
#define mk_sl_ring_t_element mk_lib_mt_ring_inl_defd_element
#define mk_sl_ring_t_count mk_lib_mt_ring_inl_defd_count
#include "mk_sl_ring_inl_filec.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_lib_mt_ring_inl_defd_st_capacity(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	ret = mk_lib_mt_ring_inl_defd_ring_st_capacity();
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_lib_mt_ring_inl_defd_ro_capacity(mk_lib_mt_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);

	((mk_lang_types_void_t)(ring));
	ret = mk_lib_mt_ring_inl_defd_st_capacity();
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_size(mk_lib_mt_ring_inl_defd_pct const ring, mk_lang_types_usize_pt const size) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_shared_t lock mk_lang_constexpr_init;
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(size);

	err = mk_lib_mt_unique_lock_shared_construct(&lock, ((mk_lib_mt_mutex_pt)(&ring->m_mutex))); mk_lang_check_rereturn(err);
	ret = mk_lib_mt_ring_inl_defd_ring_ro_size(&ring->m_ring);
	err = mk_lib_mt_unique_lock_shared_destruct(&lock); mk_lang_check_rereturn(err);
	*size = ret;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_free(mk_lib_mt_ring_inl_defd_pct const ring, mk_lang_types_usize_pt const free) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_shared_t lock mk_lang_constexpr_init;
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(free);

	err = mk_lib_mt_unique_lock_shared_construct(&lock, ((mk_lib_mt_mutex_pt)(&ring->m_mutex))); mk_lang_check_rereturn(err);
	ret = mk_lib_mt_ring_inl_defd_ring_ro_free(&ring->m_ring);
	err = mk_lib_mt_unique_lock_shared_destruct(&lock); mk_lang_check_rereturn(err);
	*free = ret;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_is_empty(mk_lib_mt_ring_inl_defd_pct const ring, mk_lang_types_bool_pt const is_empty) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_shared_t lock mk_lang_constexpr_init;
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(is_empty);

	err = mk_lib_mt_unique_lock_shared_construct(&lock, ((mk_lib_mt_mutex_pt)(&ring->m_mutex))); mk_lang_check_rereturn(err);
	ret = mk_lib_mt_ring_inl_defd_ring_ro_is_empty(&ring->m_ring);
	err = mk_lib_mt_unique_lock_shared_destruct(&lock); mk_lang_check_rereturn(err);
	*is_empty = ret;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_is_full(mk_lib_mt_ring_inl_defd_pct const ring, mk_lang_types_bool_pt const is_full) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_shared_t lock mk_lang_constexpr_init;
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(is_full);

	err = mk_lib_mt_unique_lock_shared_construct(&lock, ((mk_lib_mt_mutex_pt)(&ring->m_mutex))); mk_lang_check_rereturn(err);
	ret = mk_lib_mt_ring_inl_defd_ring_ro_is_full(&ring->m_ring);
	err = mk_lib_mt_unique_lock_shared_destruct(&lock); mk_lang_check_rereturn(err);
	*is_full = ret;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_wait_til_empty(mk_lib_mt_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_shared_t lock mk_lang_constexpr_init;

	mk_lang_assert(ring);

	err = mk_lib_mt_unique_lock_shared_construct(&lock, ((mk_lib_mt_mutex_pt)(&ring->m_mutex))); mk_lang_check_rereturn(err);
	while(!mk_lib_mt_ring_inl_defd_ring_ro_is_empty(&ring->m_ring))
	{
		err = mk_lib_mt_cv_wait_shared(((mk_lib_mt_cv_pt)(&ring->m_cv)), &lock); mk_lang_check_rereturn(err);
	}
	err = mk_lib_mt_unique_lock_shared_destruct(&lock); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_wait_til_non_empty(mk_lib_mt_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_shared_t lock mk_lang_constexpr_init;

	mk_lang_assert(ring);

	err = mk_lib_mt_unique_lock_shared_construct(&lock, ((mk_lib_mt_mutex_pt)(&ring->m_mutex))); mk_lang_check_rereturn(err);
	while(mk_lib_mt_ring_inl_defd_ring_ro_is_empty(&ring->m_ring))
	{
		err = mk_lib_mt_cv_wait_shared(((mk_lib_mt_cv_pt)(&ring->m_cv)), &lock); mk_lang_check_rereturn(err);
	}
	err = mk_lib_mt_unique_lock_shared_destruct(&lock); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_at(mk_lib_mt_ring_inl_defd_pct const ring, mk_lang_types_usize_t const idx, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_shared_t lock mk_lang_constexpr_init;
	mk_lib_mt_ring_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);

	err = mk_lib_mt_unique_lock_shared_construct(&lock, ((mk_lib_mt_mutex_pt)(&ring->m_mutex))); mk_lang_check_rereturn(err);
	ret = mk_lib_mt_ring_inl_defd_ring_ro_at(&ring->m_ring, idx);
	*element = *ret;
	err = mk_lib_mt_unique_lock_shared_destruct(&lock); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_front(mk_lib_mt_ring_inl_defd_pct const ring, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);

	err = mk_lib_mt_ring_inl_defd_ro_at(ring, 0, element); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_ro_back(mk_lib_mt_ring_inl_defd_pct const ring, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_shared_t lock mk_lang_constexpr_init;
	mk_lib_mt_ring_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);

	err = mk_lib_mt_unique_lock_shared_construct(&lock, ((mk_lib_mt_mutex_pt)(&ring->m_mutex))); mk_lang_check_rereturn(err);
	ret = mk_lib_mt_ring_inl_defd_ring_ro_back(&ring->m_ring);
	*element = *ret;
	err = mk_lib_mt_unique_lock_shared_destruct(&lock); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_lib_mt_ring_inl_defd_rw_capacity(mk_lib_mt_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(ring);

	ret = mk_lib_mt_ring_inl_defd_ro_capacity(ring);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_size(mk_lib_mt_ring_inl_defd_pt const ring, mk_lang_types_usize_pt const size) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(size);

	err = mk_lib_mt_ring_inl_defd_ro_size(ring, size);
	return err;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_free(mk_lib_mt_ring_inl_defd_pt const ring, mk_lang_types_usize_pt const free) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(free);

	err = mk_lib_mt_ring_inl_defd_ro_free(ring, free);
	return err;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_is_empty(mk_lib_mt_ring_inl_defd_pt const ring, mk_lang_types_bool_pt const is_empty) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(is_empty);

	err = mk_lib_mt_ring_inl_defd_ro_is_empty(ring, is_empty); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_is_full(mk_lib_mt_ring_inl_defd_pt const ring, mk_lang_types_bool_pt const is_full) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(is_full);

	err = mk_lib_mt_ring_inl_defd_ro_is_full(ring, is_full); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_wait_til_empty(mk_lib_mt_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;

	mk_lang_assert(ring);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, ((mk_lib_mt_mutex_pt)(&ring->m_mutex))); mk_lang_check_rereturn(err);
	while(!mk_lib_mt_ring_inl_defd_ring_rw_is_empty(&ring->m_ring))
	{
		err = mk_lib_mt_cv_wait_exclusive(&ring->m_cv, &lock); mk_lang_check_rereturn(err);
	}
	err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_wait_til_non_empty(mk_lib_mt_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;

	mk_lang_assert(ring);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, ((mk_lib_mt_mutex_pt)(&ring->m_mutex))); mk_lang_check_rereturn(err);
	while(mk_lib_mt_ring_inl_defd_ring_rw_is_empty(&ring->m_ring))
	{
		err = mk_lib_mt_cv_wait_exclusive(&ring->m_cv, &lock); mk_lang_check_rereturn(err);
	}
	err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_at(mk_lib_mt_ring_inl_defd_pt const ring, mk_lang_types_usize_t const idx, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(idx >= 0);
	mk_lang_assert(element);

	err = mk_lib_mt_ring_inl_defd_ro_at(ring, idx, element); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_front(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);

	err = mk_lib_mt_ring_inl_defd_ro_front(ring, element); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_back(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);

	err = mk_lib_mt_ring_inl_defd_ro_back(ring, element); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_construct(mk_lib_mt_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t err_b mk_lang_constexpr_init;

	mk_lang_assert(ring);

	err = mk_lib_mt_mutex_construct(&ring->m_mutex); mk_lang_check_rereturn(err);
	err_b = mk_lib_mt_cv_construct(&ring->m_cv);
	if(err_b != 0)
	{
		err = mk_lib_mt_mutex_destruct(&ring->m_mutex); mk_lang_check_rereturn(err);
		mk_lang_check_rereturn(err_b);
	}
	mk_lib_mt_ring_inl_defd_ring_rw_construct(&ring->m_ring);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_destroy(mk_lib_mt_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_sint_t err_a mk_lang_constexpr_init;
	mk_lang_types_sint_t err_b mk_lang_constexpr_init;

	mk_lang_assert(ring);

	err_a = mk_lib_mt_cv_destruct(&ring->m_cv);
	err_b = mk_lib_mt_mutex_destruct(&ring->m_mutex);
	mk_lang_check_rereturn(err_a);
	mk_lang_check_rereturn(err_b);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_push_back_one(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pct const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	while(mk_lib_mt_ring_inl_defd_ring_rw_is_full(&ring->m_ring))
	{
		err = mk_lib_mt_cv_wait_exclusive(&ring->m_cv, &lock); mk_lang_check_rereturn(err);
	}
	mk_lib_mt_ring_inl_defd_ring_rw_push_back_one(&ring->m_ring, element);
	err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
	err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_push_back_many(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pct const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	while(!(mk_lib_mt_ring_inl_defd_ring_rw_free(&ring->m_ring) >= count))
	{
		err = mk_lib_mt_cv_wait_exclusive(&ring->m_cv, &lock); mk_lang_check_rereturn(err);
	}
	mk_lib_mt_ring_inl_defd_ring_rw_push_back_many(&ring->m_ring, elements, count);
	err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
	err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_pop_back_void(mk_lib_mt_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;
	mk_lib_mt_ring_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(ring);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	while(mk_lib_mt_ring_inl_defd_ring_rw_is_empty(&ring->m_ring))
	{
		err = mk_lib_mt_cv_wait_exclusive(&ring->m_cv, &lock); mk_lang_check_rereturn(err);
	}
	item = mk_lib_mt_ring_inl_defd_ring_rw_pop_back(&ring->m_ring); ((mk_lang_types_void_t)(item));
	err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
	err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_pop_back_copy(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;
	mk_lib_mt_ring_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	while(mk_lib_mt_ring_inl_defd_ring_rw_is_empty(&ring->m_ring))
	{
		err = mk_lib_mt_cv_wait_exclusive(&ring->m_cv, &lock); mk_lang_check_rereturn(err);
	}
	item = mk_lib_mt_ring_inl_defd_ring_rw_pop_back(&ring->m_ring);
	*element = *item;
	err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
	err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_push_front(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pct const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	while(mk_lib_mt_ring_inl_defd_ring_rw_is_full(&ring->m_ring))
	{
		err = mk_lib_mt_cv_wait_exclusive(&ring->m_cv, &lock); mk_lang_check_rereturn(err);
	}
	mk_lib_mt_ring_inl_defd_ring_rw_push_front(&ring->m_ring, element);
	err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
	err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_pop_front_void(mk_lib_mt_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;
	mk_lib_mt_ring_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(ring);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	while(mk_lib_mt_ring_inl_defd_ring_rw_is_empty(&ring->m_ring))
	{
		err = mk_lib_mt_cv_wait_exclusive(&ring->m_cv, &lock); mk_lang_check_rereturn(err);
	}
	item = mk_lib_mt_ring_inl_defd_ring_rw_pop_front_one(&ring->m_ring); ((mk_lang_types_void_t)(item));
	err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
	err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_pop_front_copy(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;
	mk_lib_mt_ring_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	while(mk_lib_mt_ring_inl_defd_ring_rw_is_empty(&ring->m_ring))
	{
		err = mk_lib_mt_cv_wait_exclusive(&ring->m_cv, &lock); mk_lang_check_rereturn(err);
	}
	item = mk_lib_mt_ring_inl_defd_ring_rw_pop_front_one(&ring->m_ring);
	*element = *item;
	err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
	err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_try_push_back_one(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pct const element, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);
	mk_lang_assert(success);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	if(mk_lib_mt_ring_inl_defd_ring_rw_is_full(&ring->m_ring))
	{
		err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
		*success = mk_lang_false;
	}
	else
	{
		mk_lib_mt_ring_inl_defd_ring_rw_push_back_one(&ring->m_ring, element);
		err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
		err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
		*success = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_try_push_back_many(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pct const elements, mk_lang_types_usize_t const count, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(success);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	if(!(mk_lib_mt_ring_inl_defd_ring_rw_free(&ring->m_ring) >= count))
	{
		err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
		*success = mk_lang_false;
	}
	else
	{
		mk_lib_mt_ring_inl_defd_ring_rw_push_back_many(&ring->m_ring, elements, count);
		err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
		err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
		*success = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_try_pop_back_void(mk_lib_mt_ring_inl_defd_pt const ring, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(success);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	if(mk_lib_mt_ring_inl_defd_ring_rw_is_empty(&ring->m_ring))
	{
		err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
		*success = mk_lang_false;
	}
	else
	{
		mk_lib_mt_ring_inl_defd_ring_rw_pop_back(&ring->m_ring);
		err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
		err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
		*success = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_try_pop_back_copy(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pt const element, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;
	mk_lib_mt_ring_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);
	mk_lang_assert(success);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	if(mk_lib_mt_ring_inl_defd_ring_rw_is_empty(&ring->m_ring))
	{
		err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
		*success = mk_lang_false;
	}
	else
	{
		item = mk_lib_mt_ring_inl_defd_ring_rw_pop_back(&ring->m_ring);
		*element = *item;
		err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
		err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
		*success = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_try_push_front(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pct const element, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);
	mk_lang_assert(success);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	if(mk_lib_mt_ring_inl_defd_ring_rw_is_full(&ring->m_ring))
	{
		err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
		*success = mk_lang_false;
	}
	else
	{
		mk_lib_mt_ring_inl_defd_ring_rw_push_front(&ring->m_ring, element);
		err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
		err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
		*success = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_try_pop_front_void(mk_lib_mt_ring_inl_defd_pt const ring, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(success);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	if(mk_lib_mt_ring_inl_defd_ring_rw_is_empty(&ring->m_ring))
	{
		err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
		*success = mk_lang_false;
	}
	else
	{
		mk_lib_mt_ring_inl_defd_ring_rw_pop_front_one(&ring->m_ring);
		err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
		err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
		*success = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_try_pop_front_copy(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pt const element, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;
	mk_lib_mt_ring_inl_defd_element_pt item mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(element);
	mk_lang_assert(success);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	if(mk_lib_mt_ring_inl_defd_ring_rw_is_empty(&ring->m_ring))
	{
		err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
		*success = mk_lang_false;
	}
	else
	{
		item = mk_lib_mt_ring_inl_defd_ring_rw_pop_front_one(&ring->m_ring);
		*element = *item;
		err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
		err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
		*success = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_mt_ring_inl_defd_rw_try_pop_front_few_copy(mk_lib_mt_ring_inl_defd_pt const ring, mk_lib_mt_ring_inl_defd_element_pt const elements, mk_lang_types_usize_pt const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lib_mt_unique_lock_exclusive_t lock mk_lang_constexpr_init;
	mk_lang_types_usize_t cnt mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(elements || *count == 0);
	mk_lang_assert(count && *count >= 0);

	err = mk_lib_mt_unique_lock_exclusive_construct(&lock, &ring->m_mutex); mk_lang_check_rereturn(err);
	cnt = mk_lib_mt_ring_inl_defd_ring_rw_size(&ring->m_ring);
	cnt = mk_lang_min(cnt, *count);
	mk_lib_mt_ring_inl_defd_ring_rw_pop_front_many(&ring->m_ring, cnt, &elements[0]);
	err = mk_lib_mt_unique_lock_exclusive_destruct(&lock); mk_lang_check_rereturn(err);
	err = mk_lib_mt_cv_notify_one(&ring->m_cv); mk_lang_check_rereturn(err);
	*count = cnt;
	return 0;
}


#include "mk_lib_mt_ring_inl_defu.h"


#undef mk_lib_mt_ring_t_name
#undef mk_lib_mt_ring_t_element
#undef mk_lib_mt_ring_t_count
