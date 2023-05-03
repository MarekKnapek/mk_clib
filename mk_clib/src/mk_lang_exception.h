#ifndef mk_include_guard_lang_exception
#define mk_include_guard_lang_exception


#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"


enum mk_lang_exception_id_e
{
	mk_lang_exception_id_e_none,
	mk_lang_exception_id_e_out_of_memory,
	mk_lang_exception_id_e_dummy_end
};
typedef enum mk_lang_exception_id_e mk_lang_exception_id_t;


struct mk_lang_exception_s
{
	mk_lang_exception_id_t m_id;
	unsigned long int m_data[2];
};
typedef struct mk_lang_exception_s mk_lang_exception_t;
typedef mk_lang_exception_t const mk_lang_exception_ct;
typedef mk_lang_exception_t* mk_lang_exception_pt;
typedef mk_lang_exception_t const* mk_lang_exception_pct;


#define mk_lang_exception_if_is_return(x) if(mk_lang_exception_is(ex)) return;


mk_lang_jumbo void mk_lang_exception_test(void) mk_lang_noexcept;
mk_lang_jumbo void mk_lang_exception_make_none(mk_lang_exception_pt const ex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_exception_is(mk_lang_exception_pct const ex) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lang_exception.c"
#endif
#endif
