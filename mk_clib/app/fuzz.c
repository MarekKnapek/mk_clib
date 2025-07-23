#include "../src/mk_clib_fuzz.h"
#include "../src/mk_lang_extern.h"
#include "../src/mk_lang_nodiscard.h"
#include "../src/mk_lang_noexcept.h"
#include "../src/mk_lang_null.h"
#include "../src/mk_lang_test.h"
#include "../src/mk_lang_types.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_usize_t LLVMFuzzerMutate(mk_lang_types_uchar_pt const data, mk_lang_types_usize_t const size, mk_lang_types_usize_t const size_max) mk_lang_noexcept;


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_usize_t LLVMFuzzerCustomMutator(mk_lang_types_uchar_pt const data, mk_lang_types_usize_t const size, mk_lang_types_usize_t const size_max, mk_lang_types_uint_t const seed) mk_lang_noexcept
{
	mk_lang_types_usize_t s;

	if(size != 0 && seed % 64 == 0)
	{
		s = size - 1;
	}
	else
	{
		s = LLVMFuzzerMutate(data, size, size_max);
	}
	return s;
}

mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t LLVMFuzzerInitialize(mk_lang_types_sint_pt const argc, mk_lang_types_pchar_pppt const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	((mk_lang_types_void_t)(argc));
	((mk_lang_types_void_t)(argv));
	err = mk_clib_fuzz_init_global(); mk_lang_test(err == 0);
 return 0;
}

mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t LLVMFuzzerTestOneInput(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_clib_fuzz(data, size, mk_lang_false, mk_lang_null); mk_lang_test(err == 0);
	return 0;
}
