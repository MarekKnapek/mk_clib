#include "mk_lang_exception_out_of_memory.h"

#include "mk_lang_assert.h"
#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"


mk_lang_jumbo void mk_lang_exception_out_of_memory_make(mk_lang_exception_pt const ex, mk_lang_size_t const requested_bytes) mk_lang_noexcept
{
	mk_lang_exception_out_of_memory_pt out_of_memory;

	mk_lang_assert(ex);
	mk_lang_assert(requested_bytes != 0);

	ex->m_id = mk_lang_exception_id_e_out_of_memory;
	out_of_memory = ((mk_lang_exception_out_of_memory_pt)(&ex->m_data));
	out_of_memory->m_requested_bytes = requested_bytes;
}
