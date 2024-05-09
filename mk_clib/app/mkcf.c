#include "../src/mk_clib_app_fuzz.h"
#include "../src/mk_lang_cpp.h"
#include "../src/mk_lang_nodiscard.h"
#include "../src/mk_lang_noexcept.h"
#include "../src/mk_lang_types.h"


mk_lang_extern_c mk_lang_nodiscard mk_lang_types_usize_t LLVMFuzzerMutate(mk_lang_types_uchar_pt const data, mk_lang_types_usize_t const size, mk_lang_types_usize_t const size_max) mk_lang_noexcept;


mk_lang_extern_c mk_lang_nodiscard mk_lang_types_usize_t LLVMFuzzerCustomMutator(mk_lang_types_uchar_pt const data, mk_lang_types_usize_t const size, mk_lang_types_usize_t const size_max, mk_lang_types_uint_t const seed) mk_lang_noexcept
{
	mk_lang_types_usize_t s;

	if(size != 0 && seed % 64 == 0)
	{
		return size - 1;
	}
	else
	{
		s = LLVMFuzzerMutate(data, size, size_max);
		return s;
	}
}


mk_lang_extern_c mk_lang_nodiscard mk_lang_types_sint_t LLVMFuzzerTestOneInput(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	return mk_clib_app_fuzz(data, size);
}
