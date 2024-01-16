#include "mk_clib_fuzz.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_serpent_fuzz.h"

#if defined mk_clib_test_smol_want && mk_clib_test_smol_want == 1
#else
#endif


mk_lang_jumbo void mk_clib_fuzz(unsigned char const* const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lib_crypto_serpent_fuzz(data, size);

	#if defined mk_clib_test_smol_want && mk_clib_test_smol_want == 1
	#else
	#endif
}
