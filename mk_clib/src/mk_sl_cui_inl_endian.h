#if defined mk_sl_cui_inl_file
#if mk_sl_cui_inl_file == 1
#include "mk_sl_cui_inl_file_h.h"
#elif mk_sl_cui_inl_file == 2
#include "mk_sl_cui_inl_file_c.h"
#elif mk_sl_cui_inl_file == 3
#include "mk_sl_cui_fuzz_inl_func.h"
#elif mk_sl_cui_inl_file == 4
#include "mk_sl_cui_fuzz_inl_call.h"
#endif
#endif


/*#undef mk_sl_cui_inl_file*/ /*todo msvc bug?*/
#undef mk_sl_cui_inl_endian
