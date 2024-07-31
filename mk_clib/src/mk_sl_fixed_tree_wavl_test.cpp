#include "mk_sl_fixed_tree_wavl_test.hpp"
#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_xof_stream_blake3.h"
#include "mk_sl_uint8.h"

#define mk_lang_memcpy_t_name mk_sl_fixed_tree_wavl_test_memcpy_pc
#define mk_lang_memcpy_t_type mk_lang_types_pchar_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"

#define mk_sl_fixed_vector_t_name mk_sl_fixed_tree_wavl_test_vec
#define mk_sl_fixed_vector_t_element mk_lang_types_sint_t
#define mk_sl_fixed_vector_t_count 1024
#include "mk_sl_fixed_vector_inl_fileh.h"
#include "mk_sl_fixed_vector_inl_filec.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

#include "mk_lib_cpp_constexpr.hpp"

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_tree_wavl_test_int_cmp(mk_lang_types_sint_pct const a, mk_lang_types_sint_pct const b, mk_lang_types_sint_pt const cmp) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(cmp);

	*cmp = *a - *b;
	return 0;
}

#define mk_sl_fixed_tree_wavl_validate_want 1

#define mk_sl_fixed_tree_wavl_t_name mk_sl_fixed_tree_wavl_test
#define mk_sl_fixed_tree_wavl_t_element_type mk_lang_types_sint_t
#define mk_sl_fixed_tree_wavl_t_elements_compare mk_sl_fixed_tree_wavl_test_int_cmp
#define mk_sl_fixed_tree_wavl_t_capacity 1024
#include "mk_sl_fixed_tree_wavl_inl_fileh.h"
#include "mk_sl_fixed_tree_wavl_inl_filec.h"

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_fixed_tree_wavl_test_date[] = __DATE__;
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_fixed_tree_wavl_test_time[] = __TIME__;

mk_lang_nodiscard mk_lang_jumbo mk_lang_constexpr mk_lang_types_bool_t mk_sl_fixed_tree_wavl_test_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_sl_fixed_tree_wavl_test_t tree mk_lang_constexpr_init;
	mk_sl_fixed_tree_wavl_test_vec_t vec mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lang_types_sint_t val mk_lang_constexpr_init;
	mk_sl_fixed_tree_wavl_test_node_pct node mk_lang_constexpr_init;
	mk_lang_types_sint_pct pval mk_lang_constexpr_init;

	d = data;
	s = size;
	err = mk_sl_fixed_tree_wavl_test_rw_construct(&tree); mk_lang_test(err == 0);
	mk_sl_fixed_tree_wavl_test_vec_rw_construct(&vec);
	for(;;)
	{
		if(!(s >= 2)) break;
		n = ((mk_lang_types_sint_t)(((((mk_lang_types_uint_t)(mk_lang_types_uint_t)(d[0])) << 8)) | ((mk_lang_types_uint_t)(d[1])))); d += 2; s -= 2;
		for(i = 0; i != n; ++i)
		{
			if(!(s >= 2)) break;
			val = ((mk_lang_types_sint_t)(((((mk_lang_types_uint_t)(mk_lang_types_uint_t)(d[0])) << 8)) | ((mk_lang_types_uint_t)(d[1])))); d += 2; s -= 2;
			err = mk_sl_fixed_tree_wavl_test_rw_insert_element(&tree, &val, &node); mk_lang_test(err == 0); mk_lang_test(node);
			mk_sl_fixed_tree_wavl_test_vec_rw_push_back_one(&vec, &val);
		}
		m = ((mk_lang_types_sint_t)(mk_sl_fixed_tree_wavl_test_vec_ro_size(&vec)));
		for(j = 0; j != m; ++j)
		{
			err = mk_sl_fixed_tree_wavl_test_ro_find_node(&tree, mk_sl_fixed_tree_wavl_test_vec_ro_at(&vec, j), &node); mk_lang_test(err == 0); mk_lang_test(node); mk_lang_test(mk_sl_fixed_tree_wavl_test_ro_node_get_element(node, &pval) == 0 && *pval == *mk_sl_fixed_tree_wavl_test_vec_ro_at(&vec, j));
		}
		if(!(s >= 2)) break;
		n = ((mk_lang_types_sint_t)(((((mk_lang_types_uint_t)(mk_lang_types_uint_t)(d[0])) << 8)) | ((mk_lang_types_uint_t)(d[1])))); d += 2; s -= 2;
		for(i = 0; i != n; ++i)
		{
			if(!(s >= 2)) break;
			val = ((mk_lang_types_sint_t)(((((mk_lang_types_uint_t)(mk_lang_types_uint_t)(d[0])) << 8)) | ((mk_lang_types_uint_t)(d[1])))); d += 2; s -= 2;
			m = ((mk_lang_types_sint_t)(mk_sl_fixed_tree_wavl_test_vec_ro_size(&vec)));
			for(j = 0; j != m; ++j)
			{
				if(val == *mk_sl_fixed_tree_wavl_test_vec_ro_at(&vec, j))
				{
					break;
				}
			}
			if(j != m)
			{
				err = mk_sl_fixed_tree_wavl_test_ro_find_node(&tree, &val, &node); mk_lang_test(err == 0); mk_lang_test(node); mk_lang_test(mk_sl_fixed_tree_wavl_test_ro_node_get_element(node, &pval) == 0 && *pval == val);
				err = mk_sl_fixed_tree_wavl_test_rw_decrement_node(&tree, node); mk_lang_test(err == 0);
				*mk_sl_fixed_tree_wavl_test_vec_rw_at(&vec, j) = *mk_sl_fixed_tree_wavl_test_vec_ro_back(&vec);
				mk_sl_fixed_tree_wavl_test_vec_rw_shrink(&vec, 1);
			}
			else
			{
				err = mk_sl_fixed_tree_wavl_test_ro_find_node(&tree, &val, &node); mk_lang_test(err == 0); mk_lang_test(!node);
			}
		}
	}
	err = mk_sl_fixed_tree_wavl_test_rw_destruct(&tree); mk_lang_check_recrash(err);
	return mk_lang_true;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_constexpr mk_lang_types_bool_t mk_sl_fixed_tree_wavl_test_constexpr(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_pchar_t seed_raw[mk_lang_countstr(mk_sl_fixed_tree_wavl_test_date) + mk_lang_countstr(mk_sl_fixed_tree_wavl_test_time) + 1] mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lang_countof(seed_raw) - 1> seed_pro mk_lang_constexpr_init;
	mk_lib_crypto_xof_stream_blake3_t xofer mk_lang_constexpr_init;
	mk_sl_cui_uint8_t randomness_pro[512] mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t randomness_raw[mk_lang_countof(randomness_pro)] mk_lang_constexpr_init;

	mk_sl_fixed_tree_wavl_test_memcpy_pc_fn(&seed_raw[0 * mk_lang_countstr(mk_sl_fixed_tree_wavl_test_date)], &mk_sl_fixed_tree_wavl_test_date[0], mk_lang_countstr(mk_sl_fixed_tree_wavl_test_date));
	mk_sl_fixed_tree_wavl_test_memcpy_pc_fn(&seed_raw[1 * mk_lang_countstr(mk_sl_fixed_tree_wavl_test_date)], &mk_sl_fixed_tree_wavl_test_time[0], mk_lang_countstr(mk_sl_fixed_tree_wavl_test_time));
	seed_raw[mk_lang_countof(seed_raw) - 1] = '\0';
	mk_lib_cpp_constexpr_str_lit_to_u8s_arr(seed_pro.arr(), seed_raw);
	mk_lib_crypto_xof_stream_blake3_init(&xofer);
	mk_lib_crypto_xof_stream_blake3_append_u8(&xofer, seed_pro.data(), seed_pro.size());
	mk_lib_crypto_xof_stream_blake3_finish(&xofer);
	mk_lib_crypto_xof_stream_blake3_squeeze(&xofer, mk_lang_countof(randomness_pro), &randomness_pro[0]);
	n = mk_lang_countof(randomness_pro);
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_to_bi_uchar(&randomness_pro[i], &randomness_raw[i]);
	}
	return mk_sl_fixed_tree_wavl_test_fuzz(&randomness_raw[0], mk_lang_countof(randomness_raw));
}

mk_lang_static_assert(mk_sl_fixed_tree_wavl_test_constexpr());

#endif


mk_lang_jumbo mk_lang_types_void_t mk_sl_fixed_tree_wavl_test(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
	mk_lang_constexpr_static auto const res = mk_sl_fixed_tree_wavl_test_constexpr();

	mk_lang_static_assert(res);

	mk_lang_test(mk_sl_fixed_tree_wavl_test_constexpr());
#endif
}
