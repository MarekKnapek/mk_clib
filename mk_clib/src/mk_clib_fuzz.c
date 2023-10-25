#include "mk_clib_fuzz.h"

#if defined mk_clib_test_smol_want && mk_clib_test_smol_want == 1
#else
#include "mk_lang_bui_divmod_fuzz.h"
#endif
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_aes_fuzz.h"
#if defined mk_clib_test_smol_want && mk_clib_test_smol_want == 1
#else
#include "mk_sl_cui_fuzz.h"
#include "mk_sl_flt_fuzz.h"
#endif
#include "mk_sl_sort_merge_fuzz.h"


mk_lang_jumbo void mk_clib_fuzz(unsigned char const* const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	#if defined mk_clib_test_smol_want && mk_clib_test_smol_want == 1
	#else
	mk_lang_bui_divmod_fuzz(data, size);
	#endif
	mk_lib_crypto_aes_fuzz(data, size);
	#if defined mk_clib_test_smol_want && mk_clib_test_smol_want == 1
	#else
	mk_sl_cui_fuzz(data, size);
	mk_sl_flt_fuzz(data, size);
	#endif
	mk_sl_sort_merge_fuzz(data, size);
}
