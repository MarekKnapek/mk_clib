#include "mk_lang_concat.h"


#define mk_sl_cui_fuzz_inl_func_bi_func_inl_bi_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_for_bi_tn), _t)
#define mk_sl_cui_fuzz_inl_func_bi_func_inl_sizeof_bi_t mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_for_bi_tn), _t)
#define mk_sl_cui_fuzz_inl_func_bi_func_inl_fn mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_sl_cui_fuzz_, mk_sl_cui_inl_def_name), _fromto_), mk_lang_for_bi_tn)
#define mk_sl_cui_fuzz_inl_func_bi_func_inl_from mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _from_bi_), mk_lang_for_bi_tn)
#define mk_sl_cui_fuzz_inl_func_bi_func_inl_to mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _to_bi_), mk_lang_for_bi_tn)


mk_lang_jumbo void mk_sl_cui_fuzz_inl_func_bi_func_inl_fn(unsigned char const* const data, mk_lang_size_t const size)
{
	/* todo add the other direction (load random cui and convert to bi and back from bi to cui) */
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui;
	mk_sl_cui_fuzz_inl_func_bi_func_inl_bi_t bi1;
	mk_sl_cui_fuzz_inl_func_bi_func_inl_bi_t bi2;
	mk_sl_cui_fuzz_inl_func_bi_func_inl_bi_t bi3;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bi1));
	memcpy(&bi1, d, sizeof(bi1));
	advance(sizeof(bi1));
	bi2 = bi1;
	#if((mk_sl_cui_inl_def_count * mk_sl_cui_inl_def_base_bits) < (mk_sl_cui_fuzz_inl_func_bi_func_inl_sizeof_bi_t * mk_lang_charbit))
		bi2 =
		((mk_sl_cui_fuzz_inl_func_bi_func_inl_bi_t)(
			bi1 &
			((mk_sl_cui_fuzz_inl_func_bi_func_inl_bi_t)(
				((mk_sl_cui_fuzz_inl_func_bi_func_inl_bi_t)(
					((mk_sl_cui_fuzz_inl_func_bi_func_inl_bi_t)(1)) <<
					((int)(mk_sl_cui_inl_def_count * mk_sl_cui_inl_def_base_bits))
				)) -
				((mk_sl_cui_fuzz_inl_func_bi_func_inl_bi_t)(1))
			))
		));
	#endif
	mk_sl_cui_fuzz_inl_func_bi_func_inl_from(&cui, &bi1);
	mk_sl_cui_fuzz_inl_func_bi_func_inl_to(&cui, &bi3);
	test(bi3 == bi2);
}


#undef mk_sl_cui_fuzz_inl_func_bi_func_inl_bi_t
#undef mk_sl_cui_fuzz_inl_func_bi_func_inl_sizeof_bi_t
#undef mk_sl_cui_fuzz_inl_func_bi_func_inl_fn
#undef mk_sl_cui_fuzz_inl_func_bi_func_inl_from
#undef mk_sl_cui_fuzz_inl_func_bi_func_inl_to
