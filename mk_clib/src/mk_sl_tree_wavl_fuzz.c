#ifndef mk_include_guard_mk_sl_tree_wavl_fuzz_c
#define mk_include_guard_mk_sl_tree_wavl_fuzz_c
#include "mk_sl_tree_wavl_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_sl_mallocator.h"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_fuzz_int_cmp(mk_lang_types_sint_pct const a, mk_lang_types_sint_pct const b, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(cmp);

	*cmp = *a - *b;
	return 0;
}


#define mk_sl_tree_wavl_t_name mk_sl_tree_wavl_fuzz_test
#define mk_sl_tree_wavl_t_element_type mk_lang_types_sint_t
#define mk_sl_tree_wavl_t_elements_compare mk_sl_tree_wavl_fuzz_int_cmp
#define mk_sl_tree_wavl_t_mallocatorg_name mk_sl_mallocator
#define mk_sl_tree_wavl_t_validate_want 1
#include "mk_sl_tree_wavl_inl_fileh.h"
#include "mk_sl_tree_wavl_inl_filec.h"
#include "mk_sl_tree_wavl_inl_fileu.h"

#define mk_sl_vector_t_name mk_sl_tree_wavl_fuzz_vec
#define mk_sl_vector_t_element_type mk_lang_types_sint_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocator
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_tree_wavl_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t tui;
	mk_lang_types_sint_t err;
	mk_sl_tree_wavl_fuzz_test_t tree;
	mk_sl_tree_wavl_fuzz_vec_t vec;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t m;
	mk_lang_types_sint_t j;
	mk_lang_types_sint_t val;
	mk_sl_tree_wavl_fuzz_test_node_pct node;
	mk_lang_types_sint_pct pval;

	d = data;
	s = size;
	err = mk_sl_tree_wavl_fuzz_test_rw_construct(&tree); mk_lang_check_rereturn(err);
	err = mk_sl_tree_wavl_fuzz_vec_rw_construct(&vec); mk_lang_check_rereturn(err);
	for(;;)
	{
		if(!(s >= mk_lang_bui_uint_size_bytes_v))
		{
			break;
		}
		mk_lang_bui_uint_from_buis_uchar_le(&tui, &d[0]);
		d += mk_lang_bui_uint_size_bytes_v;
		s -= mk_lang_bui_uint_size_bytes_v;
		tui = tui & 0xffffu;
		n = ((mk_lang_types_sint_t)(tui));
		for(i = 0; i != n; ++i)
		{
			if(!(s >= mk_lang_bui_uint_size_bytes_v))
			{
				break;
			}
			mk_lang_bui_uint_from_buis_uchar_le(&tui, &d[0]);
			d += mk_lang_bui_uint_size_bytes_v;
			s -= mk_lang_bui_uint_size_bytes_v;
			tui = tui & 0xffffu;
			val = ((mk_lang_types_sint_t)(tui));
			err = mk_sl_tree_wavl_fuzz_test_rw_insert_element_copy(&tree, &val, &node); mk_lang_check_rereturn(err); mk_lang_assert(node);
			err = mk_sl_tree_wavl_fuzz_vec_rw_push_back_copy_single(&vec, &val); mk_lang_check_rereturn(err);
		}
		m = ((mk_lang_types_sint_t)(mk_sl_tree_wavl_fuzz_vec_ro_size(&vec)));
		for(j = 0; j != m; ++j)
		{
			err = mk_sl_tree_wavl_fuzz_test_ro_find_node(&tree, mk_sl_tree_wavl_fuzz_vec_ro_at(&vec, ((mk_lang_types_usize_t)(j))), &node); mk_lang_check_rereturn(err);
			mk_lang_test(node);
			mk_lang_test(mk_sl_tree_wavl_fuzz_test_ro_node_get_element(node, &pval) == 0 && *pval == *mk_sl_tree_wavl_fuzz_vec_ro_at(&vec, ((mk_lang_types_usize_t)(j))));
		}
		if(!(s >= mk_lang_bui_uint_size_bytes_v))
		{
			break;
		}
		mk_lang_bui_uint_from_buis_uchar_le(&tui, &d[0]);
		d += mk_lang_bui_uint_size_bytes_v;
		s -= mk_lang_bui_uint_size_bytes_v;
		tui = tui & 0xffffu;
		n = ((mk_lang_types_sint_t)(tui));
		for(i = 0; i != n; ++i)
		{
			if(!(s >= mk_lang_bui_uint_size_bytes_v))
			{
				break;
			}
			mk_lang_bui_uint_from_buis_uchar_le(&tui, &d[0]);
			d += mk_lang_bui_uint_size_bytes_v;
			s -= mk_lang_bui_uint_size_bytes_v;
			tui = tui & 0xffffu;
			val = ((mk_lang_types_sint_t)(tui));
			m = ((mk_lang_types_sint_t)(mk_sl_tree_wavl_fuzz_vec_ro_size(&vec)));
			for(j = 0; j != m; ++j)
			{
				if(val == *mk_sl_tree_wavl_fuzz_vec_ro_at(&vec, ((mk_lang_types_usize_t)(j))))
				{
					break;
				}
			}
			if(j != m)
			{
				err = mk_sl_tree_wavl_fuzz_test_ro_find_node(&tree, &val, &node); mk_lang_check_rereturn(err);
				mk_lang_test(node);
				mk_lang_test(mk_sl_tree_wavl_fuzz_test_ro_node_get_element(node, &pval) == 0 && *pval == val);
				err = mk_sl_tree_wavl_fuzz_test_rw_decrement_node(&tree, node); mk_lang_check_rereturn(err);
				*mk_sl_tree_wavl_fuzz_vec_rw_at(&vec, ((mk_lang_types_usize_t)(j))) = *mk_sl_tree_wavl_fuzz_vec_ro_back(&vec);
				err = mk_sl_tree_wavl_fuzz_vec_rw_shrink_by(&vec, 1); mk_lang_check_rereturn(err);
			}
			else
			{
				err = mk_sl_tree_wavl_fuzz_test_ro_find_node(&tree, &val, &node); mk_lang_check_rereturn(err);
				mk_lang_test(!node);
			}
		}
	}
	err = mk_sl_tree_wavl_fuzz_vec_rw_destroy(&vec); mk_lang_check_rereturn(err);
	err = mk_sl_tree_wavl_fuzz_test_rw_destruct(&tree); mk_lang_check_rereturn(err);
	return 0;
}


#endif
