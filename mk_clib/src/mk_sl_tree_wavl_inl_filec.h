#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#include "mk_sl_tree_wavl_inl_defd.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_sl_tree_wavl_inl_defd_node_s
{
	mk_sl_tree_wavl_inl_defd_node_pt m_left;
	mk_sl_tree_wavl_inl_defd_node_pt m_right;
	mk_sl_tree_wavl_inl_defd_node_pt m_parent;
	mk_lang_types_sint_t m_rank;
	mk_lang_types_sint_t m_ref_count;
	mk_sl_tree_wavl_inl_defd_element_t m_element;
};
#include "mk_lang_warning_msvc_pop.h"


struct mk_sl_tree_wavl_inl_defd_rule_tree_s
{
	mk_lang_types_usize_t m_count;
};
typedef struct mk_sl_tree_wavl_inl_defd_rule_tree_s mk_sl_tree_wavl_inl_defd_rule_tree_t;
typedef mk_sl_tree_wavl_inl_defd_rule_tree_t* mk_sl_tree_wavl_inl_defd_rule_tree_pt;

typedef mk_sl_tree_wavl_inl_defd_rule_tree_pt /* todo union of all pointer types */ mk_sl_tree_wavl_inl_defd_visitor_context_pt;
#if mk_lang_version_at_least_cpp_17
typedef mk_lang_types_sint_t(*mk_sl_tree_wavl_inl_defd_visitor_callback_t)(mk_sl_tree_wavl_inl_defd_visitor_context_pt const context, mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_visitor_callback_dummy(mk_sl_tree_wavl_inl_defd_visitor_context_pt const context, mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept;
typedef decltype(&mk_sl_tree_wavl_inl_defd_visitor_callback_dummy) mk_sl_tree_wavl_inl_defd_visitor_callback_t;
#else
typedef mk_lang_types_sint_t(*mk_sl_tree_wavl_inl_defd_visitor_callback_t)(mk_sl_tree_wavl_inl_defd_visitor_context_pt const context, mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept;
#endif


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_elements_compare_fn(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_element_pct const a, mk_sl_tree_wavl_inl_defd_element_pct const b, mk_lang_types_sint_pt const lt) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(lt);

	((mk_lang_types_void_t)(tree));
	err = mk_sl_tree_wavl_inl_defd_elements_compare(a, b, lt); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_element_copy_construct_memcopy(mk_sl_tree_wavl_inl_defd_element_pt const dst, mk_sl_tree_wavl_inl_defd_element_pct const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_element_move_construct_memcopy(mk_sl_tree_wavl_inl_defd_element_pt const dst, mk_sl_tree_wavl_inl_defd_element_pt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_element_destruct_void(mk_sl_tree_wavl_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_assert(element);

	((mk_lang_types_void_t)(element));
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_mallocatorg_allocate(mk_sl_tree_wavl_inl_defd_pt const tree, mk_lang_types_usize_t const size, mk_sl_tree_wavl_inl_defd_node_ppt const node) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt mem;

	mk_lang_assert(tree);
	mk_lang_assert(size == sizeof(**node));
	mk_lang_assert(node);

	((mk_lang_types_void_t)(tree));
	err = mk_sl_tree_wavl_inl_defd_base_mallocatorg_allocate(size, &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem);
	*node = ((mk_sl_tree_wavl_inl_defd_node_pt)(mem));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_mallocatorg_deallocate(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pt const node, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(node);
	mk_lang_assert(size == sizeof(*node));

	((mk_lang_types_void_t)(tree));
	err = mk_sl_tree_wavl_inl_defd_base_mallocatorg_deallocate(node, size); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_sl_tree_wavl_inl_defd_node_pct mk_sl_tree_wavl_inl_defd_prro_node_get_parent(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pct ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	((mk_lang_types_void_t)(tree));
	ret = node->m_parent;
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_tree_wavl_inl_defd_node_pct mk_sl_tree_wavl_inl_defd_prro_node_get_left(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pct ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	((mk_lang_types_void_t)(tree));
	ret = node->m_left;
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_tree_wavl_inl_defd_node_pct mk_sl_tree_wavl_inl_defd_prro_node_get_right(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pct ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	((mk_lang_types_void_t)(tree));
	ret = node->m_right;
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prro_node_get_rank(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	mk_lang_assert(tree);
	mk_lang_assert(node || !node);

	((mk_lang_types_void_t)(tree));
	if(node)
	{
		ret = node->m_rank;
	}
	else
	{
		ret = -1;
	}
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_tree_wavl_inl_defd_prro_node_is_root(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pct parent;
	mk_lang_types_bool_t ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	parent = mk_sl_tree_wavl_inl_defd_prro_node_get_parent(tree, node);
	ret = !parent;
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_tree_wavl_inl_defd_prro_node_is_leaf(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pct left;
	mk_sl_tree_wavl_inl_defd_node_pct right;
	mk_lang_types_bool_t ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	left = mk_sl_tree_wavl_inl_defd_prro_node_get_left(tree, node);
	right = mk_sl_tree_wavl_inl_defd_prro_node_get_right(tree, node);
	ret = !left && !right;
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_tree_wavl_inl_defd_prro_node_is_unary(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pct left;
	mk_sl_tree_wavl_inl_defd_node_pct right;
	mk_lang_types_bool_t ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	left = mk_sl_tree_wavl_inl_defd_prro_node_get_left(tree, node);
	right = mk_sl_tree_wavl_inl_defd_prro_node_get_right(tree, node);
	ret = (left && !right) || (!left && right);
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_tree_wavl_inl_defd_prro_node_is_binary(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pct left;
	mk_sl_tree_wavl_inl_defd_node_pct right;
	mk_lang_types_bool_t ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	left = mk_sl_tree_wavl_inl_defd_prro_node_get_left(tree, node);
	right = mk_sl_tree_wavl_inl_defd_prro_node_get_right(tree, node);
	ret = left && right;
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_tree_wavl_inl_defd_prro_node_is_internal(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_lang_types_bool_t is_leaf;
	mk_lang_types_bool_t ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	is_leaf = mk_sl_tree_wavl_inl_defd_prro_node_is_leaf(tree, node);
	ret = !is_leaf;
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_tree_wavl_inl_defd_prro_node_is_external(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_lang_types_bool_t is_leaf;
	mk_lang_types_bool_t ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	is_leaf = mk_sl_tree_wavl_inl_defd_prro_node_is_leaf(tree, node);
	ret = is_leaf;
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prro_node_get_rank_difference2(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node, mk_sl_tree_wavl_inl_defd_node_pct const parent) mk_lang_noexcept
{
	mk_lang_types_sint_t rp;
	mk_lang_types_sint_t rx;
	mk_lang_types_sint_t ret;

	mk_lang_assert(tree);
	mk_lang_assert(node || !node);
	mk_lang_assert(parent || !parent);
	mk_lang_assert(!parent || (parent->m_left == node || parent->m_right == node));

	rp = mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, parent);
	rx = mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, node);
	ret = rp - rx;
	mk_lang_assert(ret >= 0);
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prro_node_get_rank_difference(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pct parent;
	mk_lang_types_sint_t ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	parent = mk_sl_tree_wavl_inl_defd_prro_node_get_parent(tree, node);
	ret = mk_sl_tree_wavl_inl_defd_prro_node_get_rank_difference2(tree, node, parent);
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node, mk_lang_types_sint_t const i) mk_lang_noexcept
{
	mk_lang_types_sint_t rank_difference;
	mk_lang_types_bool_t ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);
	mk_lang_assert(!mk_sl_tree_wavl_inl_defd_prro_node_is_root(tree, node));

	rank_difference = mk_sl_tree_wavl_inl_defd_prro_node_get_rank_difference(tree, node);
	ret = rank_difference == i;
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node, mk_lang_types_sint_t const i, mk_lang_types_sint_t const j) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pct left;
	mk_sl_tree_wavl_inl_defd_node_pct right;
	mk_lang_types_sint_t lrd;
	mk_lang_types_sint_t rrd;
	mk_lang_types_bool_t ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	left = mk_sl_tree_wavl_inl_defd_prro_node_get_left(tree, node);
	right = mk_sl_tree_wavl_inl_defd_prro_node_get_right(tree, node);
	lrd = mk_sl_tree_wavl_inl_defd_prro_node_get_rank_difference2(tree, left, node);
	rrd = mk_sl_tree_wavl_inl_defd_prro_node_get_rank_difference2(tree, right, node);
	ret = (lrd == i && rrd == j) || (lrd == j && rrd == i);
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prro_node_get_size(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_sl_tree_wavl_inl_defd_node_pct curr;
	mk_sl_tree_wavl_inl_defd_node_pct left;
	mk_sl_tree_wavl_inl_defd_node_pct right;
	mk_sl_tree_wavl_inl_defd_node_pct parent;
	mk_sl_tree_wavl_inl_defd_node_pct sibling;
	mk_lang_types_sint_t ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	n = 1;
	curr = node;
	for(;;)
	{
		left = mk_sl_tree_wavl_inl_defd_prro_node_get_left(tree, curr);
		right = mk_sl_tree_wavl_inl_defd_prro_node_get_right(tree, curr);
		if(left)
		{
			++n;
			curr = left;
		}
		else if(right)
		{
			++n;
			curr = right;
		}
		else
		{
			for(;;)
			{
				parent = mk_sl_tree_wavl_inl_defd_prro_node_get_parent(tree, curr);
				if(parent)
				{
					sibling = mk_sl_tree_wavl_inl_defd_prro_node_get_right(tree, parent);
					if(sibling && sibling != curr)
					{
						++n;
						curr = sibling;
						break;
					}
					else
					{
						curr = parent;
					}
				}
				else
				{
					break;
				}
			}
			if(!parent)
			{
				break;
			}
		}
	}
	ret = n;
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prro_node_get_height(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_lang_types_sint_t depth;
	mk_lang_types_sint_t deepest;
	mk_sl_tree_wavl_inl_defd_node_pct curr;
	mk_sl_tree_wavl_inl_defd_node_pct left;
	mk_sl_tree_wavl_inl_defd_node_pct right;
	mk_sl_tree_wavl_inl_defd_node_pct parent;
	mk_sl_tree_wavl_inl_defd_node_pct sibling;
	mk_lang_types_sint_t ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	depth = 0;
	deepest = 0;
	curr = node;
	for(;;)
	{
		left = mk_sl_tree_wavl_inl_defd_prro_node_get_left(tree, curr);
		right = mk_sl_tree_wavl_inl_defd_prro_node_get_right(tree, curr);
		if(left)
		{
			++depth;
			deepest = mk_lang_max(deepest, depth);
			curr = left;
		}
		else if(right)
		{
			++depth;
			deepest = mk_lang_max(deepest, depth);
			curr = right;
		}
		else
		{
			for(;;)
			{
				parent = mk_sl_tree_wavl_inl_defd_prro_node_get_parent(tree, curr);
				if(parent)
				{
					sibling = mk_sl_tree_wavl_inl_defd_prro_node_get_right(tree, parent);
					if(sibling && sibling != curr)
					{
						curr = sibling;
						break;
					}
					else
					{
						--depth;
						curr = parent;
					}
				}
				else
				{
					break;
				}
			}
			if(!parent)
			{
				break;
			}
		}
	}
	ret = deepest;
	return ret;
}


mk_lang_nodiscard static mk_lang_inline mk_sl_tree_wavl_inl_defd_node_pt mk_sl_tree_wavl_inl_defd_prrw_node_get_parent(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	((mk_lang_types_void_t)(tree));
	ret = node->m_parent;
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_tree_wavl_inl_defd_node_pt mk_sl_tree_wavl_inl_defd_prrw_node_get_left(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	((mk_lang_types_void_t)(tree));
	ret = node->m_left;
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_tree_wavl_inl_defd_node_pt mk_sl_tree_wavl_inl_defd_prrw_node_get_right(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt ret;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	((mk_lang_types_void_t)(tree));
	ret = node->m_right;
	return ret;
}

static mk_lang_inline mk_lang_types_void_t mk_sl_tree_wavl_inl_defd_prrw_node_promote(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node) mk_lang_noexcept
{
	mk_lang_assert(tree);
	mk_lang_assert(node);

	((mk_lang_types_void_t)(tree));
	++node->m_rank;
}

static mk_lang_inline mk_lang_types_void_t mk_sl_tree_wavl_inl_defd_prrw_node_demote(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node) mk_lang_noexcept
{
	mk_lang_assert(tree);
	mk_lang_assert(node);

	((mk_lang_types_void_t)(tree));
	--node->m_rank;
}

static mk_lang_inline mk_lang_types_void_t mk_sl_tree_wavl_inl_defd_prrw_node_inc(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node) mk_lang_noexcept
{
	mk_lang_assert(tree);
	mk_lang_assert(node);

	((mk_lang_types_void_t)(tree));
	++node->m_ref_count;
}

static mk_lang_inline mk_lang_types_void_t mk_sl_tree_wavl_inl_defd_prrw_node_init(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node, mk_sl_tree_wavl_inl_defd_node_pt const parent) mk_lang_noexcept
{
	mk_lang_assert(tree);
	mk_lang_assert(node);
	mk_lang_assert(parent || !parent);

	((mk_lang_types_void_t)(tree));
	node->m_left = mk_lang_null;
	node->m_right = mk_lang_null;
	node->m_parent = parent;
	node->m_rank = 0;
	node->m_ref_count = 1;
	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, node, 1, 1));
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prrw_node_alloc_copy(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_ppt const node, mk_sl_tree_wavl_inl_defd_node_pt const parent, mk_sl_tree_wavl_inl_defd_element_pct const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_tree_wavl_inl_defd_node_pt target;

	mk_lang_assert(tree);
	mk_lang_assert(node);
	mk_lang_assert(element);

	err = mk_sl_tree_wavl_inl_defd_mallocatorg_allocate(tree, sizeof(*target), &target); mk_lang_check_rereturn(err); mk_lang_assert(target);
	mk_sl_tree_wavl_inl_defd_prrw_node_init(tree, target, parent);
	err = mk_sl_tree_wavl_inl_defd_element_copy_construct(&target->m_element, element); mk_lang_check_rereturn(err);
	*node = target;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prrw_node_alloc_move(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_ppt const node, mk_sl_tree_wavl_inl_defd_node_pt const parent, mk_sl_tree_wavl_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_tree_wavl_inl_defd_node_pt target;

	mk_lang_assert(tree);
	mk_lang_assert(node);
	mk_lang_assert(element);

	err = mk_sl_tree_wavl_inl_defd_mallocatorg_allocate(tree, sizeof(*target), &target); mk_lang_check_rereturn(err); mk_lang_assert(target);
	mk_sl_tree_wavl_inl_defd_prrw_node_init(tree, target, parent);
	err = mk_sl_tree_wavl_inl_defd_element_move_construct(&target->m_element, element); mk_lang_check_rereturn(err);
	*node = target;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prrw_node_dealloc(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	err = mk_sl_tree_wavl_inl_defd_element_destruct(&node->m_element); mk_lang_check_rereturn(err);
	err = mk_sl_tree_wavl_inl_defd_mallocatorg_deallocate(tree, node, sizeof(*node)); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prro_visit(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_visitor_callback_t const callback, mk_sl_tree_wavl_inl_defd_visitor_context_pt const context) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pct curr;
	mk_lang_types_sint_t err;
	mk_sl_tree_wavl_inl_defd_node_pct left;
	mk_sl_tree_wavl_inl_defd_node_pct right;
	mk_sl_tree_wavl_inl_defd_node_pct parent;
	mk_sl_tree_wavl_inl_defd_node_pct sibling;

	mk_lang_assert(tree);
	mk_lang_assert(callback);

	curr = tree->m_root;
	if(curr)
	{
		for(;;)
		{
			err = callback(context, tree, curr); mk_lang_check_rereturn(err);
			left = mk_sl_tree_wavl_inl_defd_prro_node_get_left(tree, curr);
			right = mk_sl_tree_wavl_inl_defd_prro_node_get_right(tree, curr);
			if(left)
			{
				curr = left;
			}
			else if(right)
			{
				curr = right;
			}
			else
			{
				for(;;)
				{
					parent = mk_sl_tree_wavl_inl_defd_prro_node_get_parent(tree, curr);
					if(parent)
					{
						sibling = mk_sl_tree_wavl_inl_defd_prro_node_get_right(tree, parent);
						if(sibling && sibling != curr)
						{
							curr = sibling;
							break;
						}
						else
						{
							curr = parent;
						}
					}
					else
					{
						break;
					}
				}
				if(!parent)
				{
					break;
				}
			}
		}
	}
	return 0;
}

#if mk_sl_tree_wavl_inl_defd_validate_want
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prro_rule_visit_tree(mk_sl_tree_wavl_inl_defd_visitor_context_pt const context, mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_rule_tree_pt ctx;
	mk_lang_types_sint_t cmp;

	mk_lang_assert(context);
	mk_lang_assert(tree);
	mk_lang_assert(node);

	mk_lang_assert(tree->m_nodes <= tree->m_elements);
	ctx = ((mk_sl_tree_wavl_inl_defd_rule_tree_pt)(context));
	++ctx->m_count; mk_lang_assert(ctx->m_count <= tree->m_nodes);
	mk_lang_assert((!node->m_parent && node == tree->m_root) || (node->m_parent->m_left == node || node->m_parent->m_right == node));
	mk_lang_assert(!node->m_left || node->m_left->m_parent == node);
	mk_lang_assert(!node->m_right || node->m_right->m_parent == node);
	mk_lang_assert((!node->m_left || !node->m_right) || node->m_left != node->m_right);
	mk_lang_assert(!node->m_left || (mk_sl_tree_wavl_inl_defd_elements_compare_fn(tree, &node->m_left->m_element, &node->m_element, &cmp) == 0 && cmp < 0));
	mk_lang_assert(!node->m_right || (mk_sl_tree_wavl_inl_defd_elements_compare_fn(tree, &node->m_element, &node->m_right->m_element, &cmp) == 0 && cmp < 0));
	mk_lang_assert(!node->m_left || ((mk_sl_tree_wavl_inl_defd_elements_compare_fn(tree, &node->m_left->m_element, &node->m_element, &cmp) == 0 && cmp < 0) && (mk_sl_tree_wavl_inl_defd_elements_compare_fn(tree, &node->m_element, &node->m_left->m_element, &cmp) == 0 && cmp > 0)));
	mk_lang_assert(!node->m_right || ((mk_sl_tree_wavl_inl_defd_elements_compare_fn(tree, &node->m_element, &node->m_right->m_element, &cmp) == 0 && cmp < 0) && (mk_sl_tree_wavl_inl_defd_elements_compare_fn(tree, &node->m_right->m_element, &node->m_element, &cmp) == 0 && cmp > 0)));
	mk_lang_assert(node->m_ref_count >= 1);
	mk_lang_assert(node->m_rank >= 0);
	return 0;
}
#endif

#if mk_sl_tree_wavl_inl_defd_validate_want
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prro_rule_check_tree(mk_sl_tree_wavl_inl_defd_pct const tree) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_rule_tree_t context;
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);

	mk_lang_assert(tree->m_nodes <= tree->m_elements);
	context.m_count = 0;
	err = mk_sl_tree_wavl_inl_defd_prro_visit(tree, &mk_sl_tree_wavl_inl_defd_prro_rule_visit_tree, &context); mk_lang_check_rereturn(err);
	mk_lang_assert(context.m_count == tree->m_nodes);
	return 0;
}
#endif

#if mk_sl_tree_wavl_inl_defd_validate_want
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prro_rule_visit_wavl(mk_sl_tree_wavl_inl_defd_visitor_context_pt const context, mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_node_pct const node) mk_lang_noexcept
{
	mk_lang_assert(!context);
	mk_lang_assert(tree);
	mk_lang_assert(node);

	((mk_lang_types_void_t)(context));
	mk_lang_assert(node == tree->m_root || (mk_sl_tree_wavl_inl_defd_prro_node_get_rank_difference(tree, node) == 1 || mk_sl_tree_wavl_inl_defd_prro_node_get_rank_difference(tree, node) == 2));
	mk_lang_assert(!mk_sl_tree_wavl_inl_defd_prro_node_is_leaf(tree, node) || mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, node) == 0);
	return 0;
}
#endif

#if mk_sl_tree_wavl_inl_defd_validate_want
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prro_rule_check_wavl(mk_sl_tree_wavl_inl_defd_pct const tree) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);

	err = mk_sl_tree_wavl_inl_defd_prro_visit(tree, &mk_sl_tree_wavl_inl_defd_prro_rule_visit_wavl, mk_lang_null); mk_lang_check_rereturn(err);
	return 0;
}
#endif

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prro_validate(mk_sl_tree_wavl_inl_defd_pct const tree) mk_lang_noexcept
{
#if mk_sl_tree_wavl_inl_defd_validate_want
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);

	err = mk_sl_tree_wavl_inl_defd_prro_rule_check_tree(tree); mk_lang_check_rereturn(err);
	err = mk_sl_tree_wavl_inl_defd_prro_rule_check_wavl(tree); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(tree);

	((mk_lang_types_void_t)(tree));
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_sl_tree_wavl_inl_defd_node_pt mk_sl_tree_wavl_inl_defd_prrw_find_smallest(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt curr;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	((mk_lang_types_void_t)(tree));
	curr = node;
	while(curr->m_left)
	{
		curr = curr->m_left;
	}
	return curr;
}

static mk_lang_inline mk_lang_types_void_t mk_sl_tree_wavl_inl_defd_prrw_rotate_left_single_at(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const x) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt z;
	mk_sl_tree_wavl_inl_defd_node_pt y;

	mk_lang_assert(tree);
	mk_lang_assert(x);
	mk_lang_assert(x == x->m_parent->m_left);

	z = x->m_parent;
	y = x->m_right;
	if(z->m_parent)
	{
		if(z == z->m_parent->m_left)
		{
			z->m_parent->m_left = x; x->m_parent = z->m_parent;
		}
		else
		{
			mk_lang_assert(z == z->m_parent->m_right);
			z->m_parent->m_right = x; x->m_parent = z->m_parent;
		}
	}
	else
	{
		tree->m_root = x; x->m_parent = mk_lang_null;
	}
	x->m_right = z; z->m_parent = x;
	z->m_left = y; if(y){ y->m_parent = z; }
}

static mk_lang_inline mk_lang_types_void_t mk_sl_tree_wavl_inl_defd_prrw_rotate_right_single_at(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const x) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt z;
	mk_sl_tree_wavl_inl_defd_node_pt y;

	mk_lang_assert(tree);
	mk_lang_assert(x);
	mk_lang_assert(x == x->m_parent->m_right);

	z = x->m_parent;
	y = x->m_left;
	if(z->m_parent)
	{
		if(z == z->m_parent->m_left)
		{
			z->m_parent->m_left = x; x->m_parent = z->m_parent;
		}
		else
		{
			mk_lang_assert(z == z->m_parent->m_right);
			z->m_parent->m_right = x; x->m_parent = z->m_parent;
		}
	}
	else
	{
		tree->m_root = x; x->m_parent = mk_lang_null;
	}
	x->m_left = z; z->m_parent = x;
	z->m_right = y; if(y){ y->m_parent = z; }
}

static mk_lang_inline mk_lang_types_void_t mk_sl_tree_wavl_inl_defd_prrw_rotate_left_double_at(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const y) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt z;
	mk_sl_tree_wavl_inl_defd_node_pt x;

	mk_lang_assert(tree);
	mk_lang_assert(y);
	mk_lang_assert(y == y->m_parent->m_right);
	mk_lang_assert(y->m_parent == y->m_parent->m_parent->m_left);

	x = y->m_parent;
	z = x->m_parent;
	if(z->m_parent)
	{
		if(z == z->m_parent->m_left)
		{
			z->m_parent->m_left = y; y->m_parent = z->m_parent;
		}
		else
		{
			mk_lang_assert(z == z->m_parent->m_right);
			z->m_parent->m_right = y; y->m_parent = z->m_parent;
		}
	}
	else
	{
		tree->m_root = y; y->m_parent = mk_lang_null;
	}
	x->m_right = y->m_left; if(y->m_left){ y->m_left->m_parent = x; }
	z->m_left = y->m_right; if(y->m_right){ y->m_right->m_parent = z; }
	y->m_left = x; x->m_parent = y;
	y->m_right = z; z->m_parent = y;
}

static mk_lang_inline mk_lang_types_void_t mk_sl_tree_wavl_inl_defd_prrw_rotate_right_double_at(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const y) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt z;
	mk_sl_tree_wavl_inl_defd_node_pt x;

	mk_lang_assert(tree);
	mk_lang_assert(y);
	mk_lang_assert(y == y->m_parent->m_left);
	mk_lang_assert(y->m_parent == y->m_parent->m_parent->m_right);

	x = y->m_parent;
	z = x->m_parent;
	if(z->m_parent)
	{
		if(z == z->m_parent->m_left)
		{
			z->m_parent->m_left = y; y->m_parent = z->m_parent;
		}
		else
		{
			mk_lang_assert(z == z->m_parent->m_right);
			z->m_parent->m_right = y; y->m_parent = z->m_parent;
		}
	}
	else
	{
		tree->m_root = y; y->m_parent = mk_lang_null;
	}
	x->m_left = y->m_right; if(y->m_right){ y->m_right->m_parent = x; }
	z->m_right = y->m_left; if(y->m_left){ y->m_left->m_parent = z; }
	y->m_right = x; x->m_parent = y;
	y->m_left = z; z->m_parent = y;
}

static mk_lang_inline mk_lang_types_void_t mk_sl_tree_wavl_inl_defd_prrw_rebalance_insert(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt z;
	mk_sl_tree_wavl_inl_defd_node_pt y;

	mk_lang_assert(tree);
	mk_lang_assert(node);
	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, node, 0));

	if(node == node->m_parent->m_left)
	{
		z = node->m_parent;
		y = node->m_right;
		if(!y || mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, y, 2))
		{
			mk_sl_tree_wavl_inl_defd_prrw_rotate_left_single_at(tree, node);
			mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, z);
		}
		else if(mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, y, 1))
		{
			mk_sl_tree_wavl_inl_defd_prrw_rotate_left_double_at(tree, y);
			mk_lang_assert(y->m_left == node);
			mk_lang_assert(y->m_right == z);
			mk_sl_tree_wavl_inl_defd_prrw_node_promote(tree, y);
			mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, node);
			mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, z);
		}
		else
		{
			mk_lang_assert(mk_lang_false);
		}
	}
	else
	{
		mk_lang_assert(node == node->m_parent->m_right);
		z = node->m_parent;
		y = node->m_left;
		if(!y || mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, y, 2))
		{
			mk_sl_tree_wavl_inl_defd_prrw_rotate_right_single_at(tree, node);
			mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, z);
		}
		else if(mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, y, 1))
		{
			mk_sl_tree_wavl_inl_defd_prrw_rotate_right_double_at(tree, y);
			mk_lang_assert(y->m_right == node);
			mk_lang_assert(y->m_left == z);
			mk_sl_tree_wavl_inl_defd_prrw_node_promote(tree, y);
			mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, node);
			mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, z);
		}
		else
		{
			mk_lang_assert(mk_lang_false);
		}
	}
}

static mk_lang_inline mk_lang_types_void_t mk_sl_tree_wavl_inl_defd_prrw_swap_in(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pct const old, mk_sl_tree_wavl_inl_defd_node_pt const neu) mk_lang_noexcept
{
	mk_lang_assert(tree);
	mk_lang_assert(old);
	mk_lang_assert(neu);

	neu->m_parent = old->m_parent;
	if(old->m_parent)
	{
		if(old->m_parent->m_left == old)
		{
			old->m_parent->m_left = neu;
		}
		else
		{
			mk_lang_assert(old->m_parent->m_right == old);
			old->m_parent->m_right = neu;
		}
	}
	else
	{
		tree->m_root = neu;
	}
	neu->m_right = old->m_right; if(old->m_right){ old->m_right->m_parent = neu; }
	neu->m_left = old->m_left; if(old->m_left){ old->m_left->m_parent = neu; }
	neu->m_rank = old->m_rank;
}

static mk_lang_inline mk_lang_types_void_t mk_sl_tree_wavl_inl_defd_prrw_rebalance_remove_3child(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const n, mk_sl_tree_wavl_inl_defd_node_pt const pn) mk_lang_noexcept
{
	mk_lang_types_bool_t creates_3_node;
	mk_lang_types_bool_t done;
	mk_sl_tree_wavl_inl_defd_node_pt x;
	mk_sl_tree_wavl_inl_defd_node_pt px;
	mk_sl_tree_wavl_inl_defd_node_pt ppx;
	mk_sl_tree_wavl_inl_defd_node_pt y;
	mk_lang_types_bool_t y_rank_parity;
	mk_sl_tree_wavl_inl_defd_node_pt z;
	mk_sl_tree_wavl_inl_defd_node_pt w;
	mk_sl_tree_wavl_inl_defd_node_pt v;

	mk_lang_assert(tree);
	mk_lang_assert(n || !n);
	mk_lang_assert(pn);

	creates_3_node = mk_lang_false;
	done = mk_lang_true;
	x = n;
	px = pn;
	do
	{
		ppx = px->m_parent;
		y = px->m_left == x ? px->m_right : px->m_left;
		creates_3_node = ppx && (mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, px) % 2 != 0) == (mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, ppx) % 2 != 0);
		if(mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, y, 2))
		{
			mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, px);
		}
		else
		{
			y_rank_parity = mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, y) % 2 != 0;
			if(y_rank_parity == (mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, y->m_left) % 2 != 0) && y_rank_parity == (mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, y->m_right) % 2 != 0))
			{
				mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, px);
				mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, y);
			}
			else
			{
				done = mk_lang_false;
				break;
			}
		}
		x = px;
		px = ppx;
	}while(px && creates_3_node);
	if(!done)
	{
		z = px;
		if(x == px->m_left)
		{
			w = y->m_right;
			if((mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, w) % 2 != 0) != (mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, y) % 2 != 0))
			{
				mk_sl_tree_wavl_inl_defd_prrw_rotate_right_single_at(tree, y);
				mk_sl_tree_wavl_inl_defd_prrw_node_promote(tree, y);
				mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, z);
				if(mk_sl_tree_wavl_inl_defd_prro_node_is_leaf(tree, z))
				{
					mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, z);
				}
			}
			else
			{
				v = y->m_left;
				mk_lang_assert((mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, y) % 2 != 0) != (mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, v) % 2 != 0));
				mk_sl_tree_wavl_inl_defd_prrw_rotate_right_double_at(tree, v);
				mk_sl_tree_wavl_inl_defd_prrw_node_promote(tree, v);
				mk_sl_tree_wavl_inl_defd_prrw_node_promote(tree, v);
				mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, y);
				mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, z);
				mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, z);
			}
		}
		else
		{
			w = y->m_left;
			if((mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, w) % 2 != 0) != (mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, y) % 2 != 0))
			{
				mk_sl_tree_wavl_inl_defd_prrw_rotate_left_single_at(tree, y);
				mk_sl_tree_wavl_inl_defd_prrw_node_promote(tree, y);
				mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, z);
				if(mk_sl_tree_wavl_inl_defd_prro_node_is_leaf(tree, z))
				{
					mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, z);
				}
			}
			else
			{
				v = y->m_right;
				mk_lang_assert((mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, y) % 2 != 0) != (mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, v) % 2 != 0));
				mk_sl_tree_wavl_inl_defd_prrw_rotate_left_double_at(tree, v);
				mk_sl_tree_wavl_inl_defd_prrw_node_promote(tree, v);
				mk_sl_tree_wavl_inl_defd_prrw_node_promote(tree, v);
				mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, y);
				mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, z);
				mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, z);
			}
		}
	}
}

static mk_lang_inline mk_lang_types_void_t mk_sl_tree_wavl_inl_defd_prrw_rebalance_remove_2_2_leaf(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node) mk_lang_noexcept
{
	mk_lang_assert(tree);
	mk_lang_assert(node);

	if((mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, node) % 2 == 0) == (mk_sl_tree_wavl_inl_defd_prro_node_get_rank(tree, node->m_parent) % 2 == 0))
	{
		mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, node);
		if(tree->m_nodes >= 2)
		{
			mk_sl_tree_wavl_inl_defd_prrw_rebalance_remove_3child(tree, node, node->m_parent);
		}
	}
	else
	{
		mk_sl_tree_wavl_inl_defd_prrw_node_demote(tree, node);
	}
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_rw_construct(mk_sl_tree_wavl_inl_defd_pt const tree mk_sl_tree_wavl_inl_defd_mallocator_param) mk_lang_noexcept
{
	mk_lang_assert(tree);
	mk_sl_tree_wavl_inl_defd_mallocator_assert();

	tree->m_root = mk_lang_null;
	tree->m_nodes = 0;
	tree->m_elements = 0;
	mk_sl_tree_wavl_inl_defd_mallocator_assign();
	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_rw_destruct(mk_sl_tree_wavl_inl_defd_pt const tree) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt curr;
	mk_sl_tree_wavl_inl_defd_node_pt next;
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);

	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	curr = tree->m_root;
	while(curr)
	{
		if(!curr->m_left && !curr->m_right)
		{
			next = curr->m_parent;
			if(next)
			{
				if(next->m_left == curr)
				{
					next->m_left = mk_lang_null;
				}
				else
				{
					mk_lang_assert(next->m_right == curr);
					next->m_right = mk_lang_null;
				}
			}
			err = mk_sl_tree_wavl_inl_defd_prrw_node_dealloc(tree, curr); mk_lang_check_rereturn(err);
			curr = next;
		}
		else if(curr->m_left)
		{
			curr = curr->m_left;
		}
		else
		{
			mk_lang_assert(curr->m_right);
			curr = curr->m_right;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_rw_insert_element_copy(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_element_pct const element, mk_sl_tree_wavl_inl_defd_node_ppt const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt curr;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t cmp;
	mk_lang_types_bool_t insert;
	mk_lang_types_bool_t rebalance;
	mk_sl_tree_wavl_inl_defd_node_ppt target;
	mk_lang_types_bool_t dbga;
	mk_lang_types_bool_t dbgb;

	mk_lang_assert(tree);
	mk_lang_assert(element);
	mk_lang_assert(node);

	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	curr = tree->m_root;
	if(!curr)
	{
		err = mk_sl_tree_wavl_inl_defd_prrw_node_alloc_copy(tree, &curr, mk_lang_null, element); mk_lang_check_rereturn(err); mk_lang_assert(curr);
		++tree->m_nodes;
		++tree->m_elements;
		tree->m_root = curr;
		*node = curr;
	}
	else
	{
		for(;;)
		{
			err = mk_sl_tree_wavl_inl_defd_elements_compare_fn(tree, element, &curr->m_element, &cmp); mk_lang_check_rereturn(err);
			if(cmp < 0)
			{
				if(curr->m_left)
				{
					curr = curr->m_left;
				}
				else
				{
					insert = mk_lang_true;
					rebalance = !curr->m_right;
					target = &curr->m_left;
					break;
				}
			}
			else if(cmp > 0)
			{
				if(curr->m_right)
				{
					curr = curr->m_right;
				}
				else
				{
					insert = mk_lang_true;
					rebalance = !curr->m_left;
					target = &curr->m_right;
					break;
				}
			}
			else
			{
				insert = mk_lang_false;
				++tree->m_elements;
				mk_sl_tree_wavl_inl_defd_prrw_node_inc(tree, curr);
				*node = curr;
				break;
			}
		}
		if(insert)
		{
			mk_lang_assert
			(
				(dbga = (mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 1, 2) && mk_sl_tree_wavl_inl_defd_prro_node_is_unary(tree, curr))) |
				(dbgb = (mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 1, 1) && mk_sl_tree_wavl_inl_defd_prro_node_is_leaf(tree, curr)))
			);
			#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
			mk_lang_clobber(&target);
			err = mk_sl_tree_wavl_inl_defd_prrw_node_alloc_copy(tree, target, curr, element); mk_lang_check_rereturn(err); mk_lang_assert(*target);
			#include "mk_lang_warning_clang_pop.h"
			++tree->m_nodes;
			++tree->m_elements;
			*node = *target;
			mk_lang_assert
			(
				(dbga && mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 1, 1) && mk_sl_tree_wavl_inl_defd_prro_node_is_binary(tree, curr)) |
				(dbgb && mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 0, 1) && mk_sl_tree_wavl_inl_defd_prro_node_is_unary(tree, curr))
			);
			mk_lang_assert(dbga || (!dbgb || (mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, *target, 0))));
			((mk_lang_types_void_t)(dbga));
			((mk_lang_types_void_t)(dbgb));
			#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
			mk_lang_clobber(&rebalance);
			if(rebalance)
			#include "mk_lang_warning_clang_pop.h"
			{
				curr = *target;
				while(curr->m_parent && mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr->m_parent, 0, 1))
				{
					mk_sl_tree_wavl_inl_defd_prrw_node_promote(tree, curr->m_parent);
					curr = curr->m_parent;
				}
				mk_lang_assert(!curr->m_parent || (!mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr->m_parent, 0, 2) || mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, curr, 0)));
				mk_lang_assert(!curr->m_parent || (!mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, curr, 0) || mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr->m_parent, 0, 2)));
				if(curr->m_parent && mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, curr, 0))
				{
					mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 1, 2));
					mk_sl_tree_wavl_inl_defd_prrw_rebalance_insert(tree, curr);
				}
			}
		}
	}
	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_rw_insert_element_move(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_element_pt const element, mk_sl_tree_wavl_inl_defd_node_ppt const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt curr;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t cmp;
	mk_lang_types_bool_t insert;
	mk_lang_types_bool_t rebalance;
	mk_sl_tree_wavl_inl_defd_node_ppt target;
	mk_lang_types_bool_t dbga;
	mk_lang_types_bool_t dbgb;

	mk_lang_assert(tree);
	mk_lang_assert(element);
	mk_lang_assert(node);

	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	curr = tree->m_root;
	if(!curr)
	{
		err = mk_sl_tree_wavl_inl_defd_prrw_node_alloc_move(tree, &curr, mk_lang_null, element); mk_lang_check_rereturn(err); mk_lang_assert(curr);
		++tree->m_nodes;
		++tree->m_elements;
		tree->m_root = curr;
		*node = curr;
	}
	else
	{
		for(;;)
		{
			err = mk_sl_tree_wavl_inl_defd_elements_compare_fn(tree, element, &curr->m_element, &cmp); mk_lang_check_rereturn(err);
			if(cmp < 0)
			{
				if(curr->m_left)
				{
					curr = curr->m_left;
				}
				else
				{
					insert = mk_lang_true;
					rebalance = !curr->m_right;
					target = &curr->m_left;
					break;
				}
			}
			else if(cmp > 0)
			{
				if(curr->m_right)
				{
					curr = curr->m_right;
				}
				else
				{
					insert = mk_lang_true;
					rebalance = !curr->m_left;
					target = &curr->m_right;
					break;
				}
			}
			else
			{
				insert = mk_lang_false;
				++tree->m_elements;
				mk_sl_tree_wavl_inl_defd_prrw_node_inc(tree, curr);
				*node = curr;
				break;
			}
		}
		if(insert)
		{
			mk_lang_assert
			(
				(dbga = (mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 1, 2) && mk_sl_tree_wavl_inl_defd_prro_node_is_unary(tree, curr))) |
				(dbgb = (mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 1, 1) && mk_sl_tree_wavl_inl_defd_prro_node_is_leaf(tree, curr)))
			);
			#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
			mk_lang_clobber(&target);
			err = mk_sl_tree_wavl_inl_defd_prrw_node_alloc_move(tree, target, curr, element); mk_lang_check_rereturn(err); mk_lang_assert(*target);
			#include "mk_lang_warning_clang_pop.h"
			++tree->m_nodes;
			++tree->m_elements;
			*node = *target;
			mk_lang_assert
			(
				(dbga && mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 1, 1) && mk_sl_tree_wavl_inl_defd_prro_node_is_binary(tree, curr)) |
				(dbgb && mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 0, 1) && mk_sl_tree_wavl_inl_defd_prro_node_is_unary(tree, curr))
			);
			mk_lang_assert(dbga || (!dbgb || (mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, *target, 0))));
			((mk_lang_types_void_t)(dbga));
			((mk_lang_types_void_t)(dbgb));
			#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
			mk_lang_clobber(&rebalance);
			if(rebalance)
			#include "mk_lang_warning_clang_pop.h"
			{
				curr = *target;
				while(curr->m_parent && mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr->m_parent, 0, 1))
				{
					mk_sl_tree_wavl_inl_defd_prrw_node_promote(tree, curr->m_parent);
					curr = curr->m_parent;
				}
				mk_lang_assert(!curr->m_parent || (!mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr->m_parent, 0, 2) || mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, curr, 0)));
				mk_lang_assert(!curr->m_parent || (!mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, curr, 0) || mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr->m_parent, 0, 2)));
				if(curr->m_parent && mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, curr, 0))
				{
					mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 1, 2));
					mk_sl_tree_wavl_inl_defd_prrw_rebalance_insert(tree, curr);
				}
			}
		}
	}
	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_rw_insert_node(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt curr;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t cmp;
	mk_lang_types_bool_t insert;
	mk_lang_types_bool_t rebalance;
	mk_sl_tree_wavl_inl_defd_node_ppt target;
	mk_lang_types_bool_t dbga;
	mk_lang_types_bool_t dbgb;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	curr = tree->m_root;
	if(!curr)
	{
		curr = node;
		mk_sl_tree_wavl_inl_defd_prrw_node_init(tree, curr, mk_lang_null);
		++tree->m_nodes;
		++tree->m_elements;
		tree->m_root = curr;
	}
	else
	{
		for(;;)
		{
			err = mk_sl_tree_wavl_inl_defd_elements_compare_fn(tree, &node->m_element, &curr->m_element, &cmp); mk_lang_check_rereturn(err);
			if(cmp < 0)
			{
				if(curr->m_left)
				{
					curr = curr->m_left;
				}
				else
				{
					insert = mk_lang_true;
					rebalance = !curr->m_right;
					target = &curr->m_left;
					break;
				}
			}
			else if(cmp > 0)
			{
				if(curr->m_right)
				{
					curr = curr->m_right;
				}
				else
				{
					insert = mk_lang_true;
					rebalance = !curr->m_left;
					target = &curr->m_right;
					break;
				}
			}
			else
			{
				mk_lang_assert(mk_lang_false);
			}
		}
		if(insert)
		{
			mk_lang_assert
			(
				(dbga = (mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 1, 2) && mk_sl_tree_wavl_inl_defd_prro_node_is_unary(tree, curr))) |
				(dbgb = (mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 1, 1) && mk_sl_tree_wavl_inl_defd_prro_node_is_leaf(tree, curr)))
			);
			*target = ((mk_sl_tree_wavl_inl_defd_node_pt)(node));
			mk_sl_tree_wavl_inl_defd_prrw_node_init(tree, *target, curr);
			++tree->m_nodes;
			++tree->m_elements;
			mk_lang_assert
			(
				(dbga && mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 1, 1) && mk_sl_tree_wavl_inl_defd_prro_node_is_binary(tree, curr)) |
				(dbgb && mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 0, 1) && mk_sl_tree_wavl_inl_defd_prro_node_is_unary(tree, curr))
			);
			mk_lang_assert(dbga || (!dbgb || (mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, *target, 0))));
			((mk_lang_types_void_t)(dbga));
			((mk_lang_types_void_t)(dbgb));
			if(rebalance)
			{
				curr = *target;
				while(curr->m_parent && mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr->m_parent, 0, 1))
				{
					mk_sl_tree_wavl_inl_defd_prrw_node_promote(tree, curr->m_parent);
					curr = curr->m_parent;
				}
				mk_lang_assert(!curr->m_parent || (!mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr->m_parent, 0, 2) || mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, curr, 0)));
				mk_lang_assert(!curr->m_parent || (!mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, curr, 0) || mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr->m_parent, 0, 2)));
				if(curr->m_parent && mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, curr, 0))
				{
					mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_node_is_ijnode(tree, curr, 1, 2));
					mk_sl_tree_wavl_inl_defd_prrw_rebalance_insert(tree, curr);
				}
			}
		}
	}
	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_ro_find_node(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_element_pct const element, mk_sl_tree_wavl_inl_defd_node_ppt const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt curr;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t cmp;

	mk_lang_assert(tree);
	mk_lang_assert(element);
	mk_lang_assert(node);

	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	curr = tree->m_root;
	if(!curr)
	{
		*node = mk_lang_null;
	}
	else
	{
		do
		{
			err = mk_sl_tree_wavl_inl_defd_elements_compare_fn(tree, element, &curr->m_element, &cmp); mk_lang_check_rereturn(err);
			if(cmp < 0)
			{
				curr = curr->m_left;
			}
			else if(cmp > 0)
			{
				curr = curr->m_right;
			}
			else
			{
				break;
			}
		}while(curr);
		*node = curr;
	}
	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_rw_remove_node(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node) mk_lang_noexcept
{
	mk_lang_types_bool_t is2child;
	mk_sl_tree_wavl_inl_defd_node_pt y;
	mk_sl_tree_wavl_inl_defd_node_pt x;
	mk_sl_tree_wavl_inl_defd_node_pt p;

	mk_lang_assert(tree);
	mk_lang_assert(node);
	mk_lang_assert(node->m_ref_count == 1);

	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	--tree->m_nodes;
	--tree->m_elements;
	is2child = mk_lang_false;
	if(!node->m_left || !node->m_right)
	{
		y = node;
		x = node->m_left ? node->m_left : node->m_right;
	}
	else
	{
		y = mk_sl_tree_wavl_inl_defd_prrw_find_smallest(tree, node->m_right); mk_lang_assert(y);
		x = y->m_right;
	}
	mk_lang_assert(y);
	p = y->m_parent;
	if(x){ x->m_parent = p; }
	if(p)
	{
		is2child = mk_sl_tree_wavl_inl_defd_prro_node_is_ichild(tree, y, 2);
		if(p->m_left == y)
		{
			p->m_left = x;
		}
		else
		{
			mk_lang_assert(p->m_right == y);
			p->m_right = x;
		}
	}
	else
	{
		tree->m_root = x;
	}
	if(y != node)
	{
		mk_sl_tree_wavl_inl_defd_prrw_swap_in(tree, node, y);
		if(p == node)
		{
			p = y;
		}
	}
	if(p)
	{
		if(is2child)
		{
			mk_sl_tree_wavl_inl_defd_prrw_rebalance_remove_3child(tree, x, p);
		}
		else if(!x && p->m_left == p->m_right)
		{
			mk_sl_tree_wavl_inl_defd_prrw_rebalance_remove_2_2_leaf(tree, p);
		}
	}
	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_prrw_dec_node(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt x;
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	x = node;
	--x->m_ref_count;
	if(x->m_ref_count == 0)
	{
		++x->m_ref_count;
		err = mk_sl_tree_wavl_inl_defd_rw_remove_node(tree, x); mk_lang_check_rereturn(err);
		err = mk_sl_tree_wavl_inl_defd_prrw_node_dealloc(tree, x); mk_lang_check_rereturn(err);
	}
	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_rw_decrement_node(mk_sl_tree_wavl_inl_defd_pt const tree, mk_sl_tree_wavl_inl_defd_node_pt const node) mk_lang_noexcept
{
	mk_sl_tree_wavl_inl_defd_node_pt x;
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(node);

	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	x = ((mk_sl_tree_wavl_inl_defd_node_pt)(node));
	--x->m_ref_count;
	if(x->m_ref_count == 0)
	{
		++x->m_ref_count;
		err = mk_sl_tree_wavl_inl_defd_rw_remove_node(tree, x); mk_lang_check_rereturn(err);
		err = mk_sl_tree_wavl_inl_defd_prrw_node_dealloc(tree, x); mk_lang_check_rereturn(err);
	}
	else
	{
		--tree->m_elements;
	}
	mk_lang_assert(mk_sl_tree_wavl_inl_defd_prro_validate(tree) == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_ro_walk(mk_sl_tree_wavl_inl_defd_pct const tree, mk_sl_tree_wavl_inl_defd_callback_t const fnc, mk_lang_types_uintptr_t const ctx) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(tree);
	mk_lang_assert(fnc);
	mk_lang_assert(ctx || !ctx);

	#include "mk_lang_warning_clang_push_cast_qual.h"
	err = mk_sl_tree_wavl_inl_defd_prro_visit(tree, *((mk_sl_tree_wavl_inl_defd_visitor_callback_t*)(&fnc)), ((mk_sl_tree_wavl_inl_defd_visitor_context_pt)(ctx))); mk_lang_check_rereturn(err); /* todo, casts */
	#include "mk_lang_warning_clang_pop.h"
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_ro_node_get_element(mk_sl_tree_wavl_inl_defd_node_pct const node, mk_sl_tree_wavl_inl_defd_element_ppct const element) mk_lang_noexcept
{
	mk_lang_assert(node);
	mk_lang_assert(element);

	*element = &node->m_element;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_tree_wavl_inl_defd_rw_node_get_element(mk_sl_tree_wavl_inl_defd_node_pt const node, mk_sl_tree_wavl_inl_defd_element_ppt const element) mk_lang_noexcept
{
	mk_lang_assert(node);
	mk_lang_assert(element);

	*element = &node->m_element;
	return 0;
}


#include "mk_sl_tree_wavl_inl_defu.h"
