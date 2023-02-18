#include "mk_sl_cui_fuzz_inl_tofrom_buis_inl_defd.h"


mk_lang_jumbo void mk_sl_cui_fuzz_inl_tofrom_buis_inl_defd_fn(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	mk_sl_cui_fuzz_inl_tofrom_buis_inl_defd_bui_t buis[mk_sl_cui_fuzz_inl_tofrom_buis_inl_defd_count];
	mk_sl_cui_fuzz_inl_tofrom_buis_inl_defd_bui_t buis1r[mk_sl_cui_fuzz_inl_tofrom_buis_inl_defd_count];
	mk_sl_cui_fuzz_inl_tofrom_buis_inl_defd_bui_t buis2r[mk_sl_cui_fuzz_inl_tofrom_buis_inl_defd_count];

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(buis));
	memcpy(&buis, d, sizeof(buis));
	advance(sizeof(buis));
	check_data(sizeof(buis1r));
	memcpy(&buis1r, d, sizeof(buis1r));
	advance(sizeof(buis1r));
	check_data(sizeof(buis2r));
	memcpy(&buis2r, d, sizeof(buis2r));
	advance(sizeof(buis2r));
	mk_sl_cui_fuzz_inl_tofrom_buis_inl_defd_cui_from_buis(&cui, &buis[0]);
	mk_sl_cui_fuzz_inl_tofrom_buis_inl_defd_bui_from_buis(&bui, &buis[0]);
	mk_sl_cui_fuzz_inl_tofrom_buis_inl_defd_cui_to_buis(&cui, &buis1r[0]);
	mk_sl_cui_fuzz_inl_tofrom_buis_inl_defd_bui_to_buis(&bui, &buis2r[0]);
	test(memcmp(buis1r, buis2r, sizeof(buis1r)) == 0);
}


#include "mk_sl_cui_fuzz_inl_tofrom_buis_inl_defu.h"
