#include "mk_clib_app_float_analyzer.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_flt_analyzer_float.h"


mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_float_analyzer(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_flt_analyzer_float_t analyzer;

	mk_lang_assert(argc >= 1);
	mk_lang_assert(argv);

	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(argv[i]);
	}
	mk_lang_check_return(n == 1);
	mk_lib_flt_analyzer_float_analyze(&analyzer);
	return 0;
}
