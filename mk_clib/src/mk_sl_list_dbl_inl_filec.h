#include "mk_lang_check.h"
#include "mk_lang_bool.h"
#include "mk_lang_null.h"
#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_sl_list_dbl_inl_defd.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_sl_list_dbl_inl_defd_node_s
{
	mk_sl_list_dbl_inl_defd_node_pt m_prev;
	mk_sl_list_dbl_inl_defd_node_pt m_next;
	mk_sl_list_dbl_inl_defd_element_t m_element;
};
typedef struct mk_sl_list_dbl_inl_defd_node_s mk_sl_list_dbl_inl_defd_node_t;
mk_lang_typedef(mk_sl_list_dbl_inl_defd_node);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_list_dbl_inl_defd_prrw_check_invariants(mk_sl_list_dbl_inl_defd_pt const list) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;

	mk_lang_assert(list);

	gud = mk_lang_true;
	gud = gud && ((list->m_front && list->m_back) || (!list->m_front && !list->m_back));
	return gud;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_prrw_element_destroy(mk_sl_list_dbl_inl_defd_element_pt const element) mk_lang_noexcept
{
#if mk_sl_list_dbl_inl_defd_element_has_destroy
	mk_lang_types_sint_t err;

	mk_lang_assert(element);

	err = mk_sl_list_dbl_inl_defd_element_destroy(element); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(element);

	((mk_lang_types_void_t)(element));
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_prrw_element_construct_copy(mk_sl_list_dbl_inl_defd_element_pt const dst, mk_sl_list_dbl_inl_defd_element_pct const src) mk_lang_noexcept
{
#if mk_sl_list_dbl_inl_defd_element_has_construct_copy
	mk_lang_types_sint_t err;

	mk_lang_assert(dst);
	mk_lang_assert(src);

	err = mk_sl_list_dbl_inl_defd_element_construct_copy(dst, src); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_prrw_element_construct_move(mk_sl_list_dbl_inl_defd_element_pt const dst, mk_sl_list_dbl_inl_defd_element_pt const src) mk_lang_noexcept
{
#if mk_sl_list_dbl_inl_defd_element_has_construct_move
	mk_lang_types_sint_t err;

	mk_lang_assert(dst);
	mk_lang_assert(src);

	err = mk_sl_list_dbl_inl_defd_element_construct_move(dst, src); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_prrw_construct(mk_sl_list_dbl_inl_defd_pt const list) mk_lang_noexcept
{
	mk_lang_assert(list);

	list->m_front = mk_lang_null;
	list->m_back = mk_lang_null;

	mk_lang_assert(mk_sl_list_dbl_inl_defd_prrw_check_invariants(list));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_prrw_destroy(mk_sl_list_dbl_inl_defd_pt const list) mk_lang_noexcept
{
	mk_sl_list_dbl_inl_defd_node_pt curr;
	mk_sl_list_dbl_inl_defd_node_pt next;
	mk_lang_types_sint_t err;

	mk_lang_assert(list);
	mk_lang_assert(mk_sl_list_dbl_inl_defd_prrw_check_invariants(list));

	curr = list->m_front;
	while(curr)
	{
		next = curr->m_next;
		err = mk_sl_list_dbl_inl_defd_prrw_element_destroy(&curr->m_element); mk_lang_check_rereturn(err);
		err = mk_sl_list_dbl_inl_defd_mallocator_deallocate(curr, sizeof(*curr)); mk_lang_check_rereturn(err);
		curr = next;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_list_dbl_inl_defd_prrw_is_empty(mk_sl_list_dbl_inl_defd_pt const list) mk_lang_noexcept
{
	mk_lang_types_bool_t is;

	mk_lang_assert(list);
	mk_lang_assert(mk_sl_list_dbl_inl_defd_prrw_check_invariants(list));

	is = list->m_front == mk_lang_null && list->m_back == mk_lang_null;

	mk_lang_assert(mk_sl_list_dbl_inl_defd_prrw_check_invariants(list));
	return is;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_prrw_push_back_copy(mk_sl_list_dbl_inl_defd_pt const list, mk_sl_list_dbl_inl_defd_element_pct const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_list_dbl_inl_defd_node_pt node;
	mk_lang_types_void_pt mem;

	mk_lang_assert(list);
	mk_lang_assert(mk_sl_list_dbl_inl_defd_prrw_check_invariants(list));

	err = mk_sl_list_dbl_inl_defd_mallocator_allocate(sizeof(*node), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); node = ((mk_sl_list_dbl_inl_defd_node_pt)(mem)); mk_lang_assert(node);
	err = mk_sl_list_dbl_inl_defd_prrw_element_construct_copy(&node->m_element, element); mk_lang_check_rereturn(err);
	node->m_prev = list->m_back;
	node->m_next = mk_lang_null;
	if(list->m_back){ mk_lang_assert(!list->m_back->m_next); list->m_back->m_next = node; }
	if(!list->m_front){ list->m_front = node; }
	list->m_back = node;

	mk_lang_assert(mk_sl_list_dbl_inl_defd_prrw_check_invariants(list));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_prrw_push_back_move(mk_sl_list_dbl_inl_defd_pt const list, mk_sl_list_dbl_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_list_dbl_inl_defd_node_pt node;
	mk_lang_types_void_pt mem;

	mk_lang_assert(list);
	mk_lang_assert(mk_sl_list_dbl_inl_defd_prrw_check_invariants(list));

	err = mk_sl_list_dbl_inl_defd_mallocator_allocate(sizeof(*node), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); node = ((mk_sl_list_dbl_inl_defd_node_pt)(mem)); mk_lang_assert(node);
	err = mk_sl_list_dbl_inl_defd_prrw_element_construct_move(&node->m_element, element); mk_lang_check_rereturn(err);
	node->m_prev = list->m_back;
	node->m_next = mk_lang_null;
	if(list->m_back){ mk_lang_assert(!list->m_back->m_next); list->m_back->m_next = node; }
	if(!list->m_front){ list->m_front = node; }
	list->m_back = node;

	mk_lang_assert(mk_sl_list_dbl_inl_defd_prrw_check_invariants(list));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_prrw_pop_front_copy(mk_sl_list_dbl_inl_defd_pt const list, mk_sl_list_dbl_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_sl_list_dbl_inl_defd_node_pt node;
	mk_lang_types_sint_t err;

	mk_lang_assert(list);
	mk_lang_assert(mk_sl_list_dbl_inl_defd_prrw_check_invariants(list));
	mk_lang_assert(!mk_sl_list_dbl_inl_defd_prrw_is_empty(list));

	node = list->m_front;
	mk_lang_assert(list->m_front); list->m_front = list->m_front->m_next;
	if(list->m_front){ mk_lang_assert(!list->m_front->m_prev); list->m_front->m_prev = mk_lang_null; }
	if(!list->m_front){ list->m_back = mk_lang_null; }

	err = mk_sl_list_dbl_inl_defd_prrw_element_construct_copy(element, &node->m_element); mk_lang_check_rereturn(err);
	err = mk_sl_list_dbl_inl_defd_prrw_element_destroy(&node->m_element); mk_lang_check_rereturn(err);
	err = mk_sl_list_dbl_inl_defd_mallocator_deallocate(node, sizeof(*node)); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_list_dbl_inl_defd_prrw_check_invariants(list));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_prrw_pop_front_move(mk_sl_list_dbl_inl_defd_pt const list, mk_sl_list_dbl_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_sl_list_dbl_inl_defd_node_pt node;
	mk_lang_types_sint_t err;

	mk_lang_assert(list);
	mk_lang_assert(mk_sl_list_dbl_inl_defd_prrw_check_invariants(list));
	mk_lang_assert(!mk_sl_list_dbl_inl_defd_prrw_is_empty(list));

	node = list->m_front;
	mk_lang_assert(list->m_front); list->m_front = list->m_front->m_next;
	if(list->m_front){ mk_lang_assert(!list->m_front->m_prev); list->m_front->m_prev = mk_lang_null; }
	if(!list->m_front){ list->m_back = mk_lang_null; }

	err = mk_sl_list_dbl_inl_defd_prrw_element_construct_move(element, &node->m_element); mk_lang_check_rereturn(err);
	err = mk_sl_list_dbl_inl_defd_prrw_element_destroy(&node->m_element); mk_lang_check_rereturn(err);
	err = mk_sl_list_dbl_inl_defd_mallocator_deallocate(node, sizeof(*node)); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_list_dbl_inl_defd_prrw_check_invariants(list));
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_rw_construct(mk_sl_list_dbl_inl_defd_pt const list) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list);

	err = mk_sl_list_dbl_inl_defd_prrw_construct(list); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_rw_destroy(mk_sl_list_dbl_inl_defd_pt const list) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list);

	err = mk_sl_list_dbl_inl_defd_prrw_destroy(list); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_list_dbl_inl_defd_rw_is_empty(mk_sl_list_dbl_inl_defd_pt const list) mk_lang_noexcept
{
	mk_lang_types_bool_t is;

	mk_lang_assert(list);

	is = mk_sl_list_dbl_inl_defd_prrw_is_empty(list);
	return is;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_rw_push_back_copy(mk_sl_list_dbl_inl_defd_pt const list, mk_sl_list_dbl_inl_defd_element_pct const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list);
	mk_lang_assert(element);

	err = mk_sl_list_dbl_inl_defd_prrw_push_back_copy(list, element); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_rw_push_back_move(mk_sl_list_dbl_inl_defd_pt const list, mk_sl_list_dbl_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list);
	mk_lang_assert(element);

	err = mk_sl_list_dbl_inl_defd_prrw_push_back_move(list, element); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_rw_pop_front_copy(mk_sl_list_dbl_inl_defd_pt const list, mk_sl_list_dbl_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list);
	mk_lang_assert(element);

	err = mk_sl_list_dbl_inl_defd_prrw_pop_front_copy(list, element); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_list_dbl_inl_defd_rw_pop_front_move(mk_sl_list_dbl_inl_defd_pt const list, mk_sl_list_dbl_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list);
	mk_lang_assert(element);

	err = mk_sl_list_dbl_inl_defd_prrw_pop_front_move(list, element); mk_lang_check_rereturn(err);
	return 0;
}


#include "mk_sl_list_dbl_inl_defu.h"
