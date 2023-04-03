#include "mk_sl_cui_fuzz_inl_tofrom_bi_inl_defd.h"


mk_lang_jumbo void mk_sl_cui_fuzz_inl_tofrom_bi_inl_defd_fn(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	mk_sl_cui_fuzz_inl_tofrom_bi_inl_defd_bi_t bi;
	mk_sl_cui_fuzz_inl_tofrom_bi_inl_defd_bi_t bir1;
	mk_sl_cui_fuzz_inl_tofrom_bi_inl_defd_bi_t bir2;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(bi));
	memcpy(&bi, d, sizeof(bi));
	advance(sizeof(bi));
	check_data(sizeof(bir1));
	memcpy(&bir1, d, sizeof(bir1));
	advance(sizeof(bir1));
	check_data(sizeof(bir2));
	memcpy(&bir2, d, sizeof(bir2));
	advance(sizeof(bir2));
	mk_sl_cui_fuzz_inl_tofrom_bi_inl_defd_cui_from_bi(&cui, &bi);
	mk_sl_cui_fuzz_inl_tofrom_bi_inl_defd_bui_from_bi(&bui, &bi);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_tofrom_bi_inl_defd_cui_to_bi(&cui, &bir1);
	mk_sl_cui_fuzz_inl_tofrom_bi_inl_defd_bui_to_bi(&bui, &bir2);
	test(bir1 == bir2);
}


#include "mk_sl_cui_fuzz_inl_tofrom_bi_inl_defu.h"
