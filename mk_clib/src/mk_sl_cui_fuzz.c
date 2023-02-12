#include "mk_sl_cui_fuzz.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_sizet.h"
#include "mk_sl_cui.h"


#undef mk_sl_cui_inl_file /*todo msvc bug?*/
#define mk_sl_cui_inl_file 3
#include "mk_sl_cui_inl_types.h"


mk_lang_jumbo void mk_sl_cui_fuzz(unsigned char const* const data, mk_lang_size_t const size)
{
#undef mk_sl_cui_inl_file /*todo msvc bug?*/
#define mk_sl_cui_inl_file 4
#include "mk_sl_cui_inl_types.h"
}
