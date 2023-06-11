#include "mk_clib_fuzz.h"

#include "mk_lang_bui_divmod_fuzz.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"
#include "mk_sl_cui_fuzz.h"
#include "mk_sl_flt_fuzz.h"
#include "mk_sl_sort_merge_fuzz.h"


mk_lang_jumbo void mk_clib_fuzz(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_lang_bui_divmod_fuzz(data, size);
	mk_sl_cui_fuzz(data, size);
	mk_sl_flt_fuzz(data, size);
	mk_sl_sort_merge_fuzz(data, size);
}
