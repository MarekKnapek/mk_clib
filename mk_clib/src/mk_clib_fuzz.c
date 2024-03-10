#include "mk_clib_fuzz.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_num_longdivmod_fuzz_bui.h"
#include "mk_lang_num_longdivmod_fuzz_cui.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_aes_fuzz.h"
#include "mk_lib_crypto_des_fuzz.h"
#include "mk_lib_crypto_serpent_fuzz.h"
#include "mk_sl_sort_merge_fuzz.h"

#if defined mk_clib_test_smol_want && mk_clib_test_smol_want == 1
#else
#include "mk_sl_flt_fuzz.h"
#endif


mk_lang_jumbo void mk_clib_fuzz(unsigned char const* const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_num_longdivmod_fuzz_bui(data, size);
	mk_lang_num_longdivmod_fuzz_cui(data, size);
	mk_lib_crypto_aes_fuzz(data, size);
	mk_lib_crypto_des_fuzz(data, size);
	mk_lib_crypto_serpent_fuzz(data, size);
	mk_sl_sort_merge_fuzz(data, size);

	#if defined mk_clib_test_smol_want && mk_clib_test_smol_want == 1
	#else
	mk_sl_flt_fuzz(data, size);
	#endif
}
