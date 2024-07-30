#include "mk_sl_tree_wavl_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_mallocatorg.h"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_tree_wavl_fuzz_int_cmp(mk_lang_types_sint_pct const a, mk_lang_types_sint_pct const b, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(cmp);

	*cmp = *a - *b;
	return 0;
}

#define mk_sl_tree_wavl_validate_want 1

#define mk_sl_tree_wavl_t_name mk_sl_tree_wavl_fuzz_test
#define mk_sl_tree_wavl_t_element_type mk_lang_types_sint_t
#define mk_sl_tree_wavl_t_elements_compare mk_sl_tree_wavl_fuzz_int_cmp
#define mk_sl_tree_wavl_t_mallocatorg_name mk_sl_mallocatorg
#define mk_sl_tree_wavl_t_constexpr_want 0
#include "mk_sl_tree_wavl_inl_fileh.h"
#include "mk_sl_tree_wavl_inl_filec.h"

#define mk_sl_vector_t_name mk_sl_tree_wavl_fuzz_vec
#define mk_sl_vector_t_element int
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"


mk_lang_jumbo mk_lang_types_void_t mk_sl_tree_wavl_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_sint_t err;
	mk_sl_tree_wavl_fuzz_test_t tree;
	mk_sl_tree_wavl_fuzz_vec_t vec;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t m;
	mk_lang_types_sint_t j;
	mk_lang_types_sint_t val;
	mk_sl_tree_wavl_fuzz_test_node_pct node;

	d = data;
	s = size;
	err = mk_sl_mallocatorg_init(); mk_lang_check_recrash(err);
	err = mk_sl_tree_wavl_fuzz_test_rw_construct(&tree); mk_lang_test(err == 0);
	err = mk_sl_tree_wavl_fuzz_vec_rw_construct(&vec); mk_lang_check_recrash(err);
	for(;;)
	{
		if(!(s >= 1)) break;
		n = *d; ++d; --s;
		for(i = 0; i != n; ++i)
		{
			if(!(s >= 1)) break;
			val = *d; ++d; --s;
			err = mk_sl_tree_wavl_fuzz_test_rw_insert_element(&tree, &val, &node); mk_lang_test(err == 0); mk_lang_test(node);
			err = mk_sl_tree_wavl_fuzz_vec_rw_push_back_one(&vec, &val); mk_lang_check_recrash(err);
		}
		m = ((mk_lang_types_sint_t)(mk_sl_tree_wavl_fuzz_vec_ro_size(&vec)));
		for(j = 0; j != m; ++j)
		{
			err = mk_sl_tree_wavl_fuzz_test_rw_find(&tree, mk_sl_tree_wavl_fuzz_vec_ro_at(&vec, j), &node); mk_lang_test(err == 0); mk_lang_test(node);
		}
		if(!(s >= 1)) break;
		n = *d; ++d; --s;
		for(i = 0; i != n; ++i)
		{
			if(!(s >= 1)) break;
			val = *d; ++d; --s;
			m = ((mk_lang_types_sint_t)(mk_sl_tree_wavl_fuzz_vec_ro_size(&vec)));
			for(j = 0; j != m; ++j)
			{
				if(val == *mk_sl_tree_wavl_fuzz_vec_ro_at(&vec, j))
				{
					break;
				}
			}
			if(j != m)
			{
				err = mk_sl_tree_wavl_fuzz_test_rw_find(&tree, &val, &node); mk_lang_test(err == 0); mk_lang_test(node);
				err = mk_sl_tree_wavl_fuzz_test_rw_decrement_node(&tree, node); mk_lang_test(err == 0);
				*mk_sl_tree_wavl_fuzz_vec_rw_at(&vec, j) = *mk_sl_tree_wavl_fuzz_vec_ro_back(&vec);
				err = mk_sl_tree_wavl_fuzz_vec_rw_shrink(&vec, 1); mk_lang_check_recrash(err);
			}
			else
			{
				err = mk_sl_tree_wavl_fuzz_test_rw_find(&tree, &val, &node); mk_lang_test(err == 0); mk_lang_test(!node);
			}
		}
	}
	err = mk_sl_tree_wavl_fuzz_vec_rw_destroy(&vec); mk_lang_check_recrash(err);
	err = mk_sl_tree_wavl_fuzz_test_rw_destroy(&tree); mk_lang_check_recrash(err);
	err = mk_sl_mallocatorg_deinit(); mk_lang_check_recrash(err);
}
