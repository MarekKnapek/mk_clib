#ifndef mk_include_guard_mk_lang_exception
#define mk_include_guard_mk_lang_exception


#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


enum mk_lang_exception_id_e
{
	mk_lang_exception_id_e_none,
	mk_lang_exception_id_e_out_of_memory,
	mk_lang_exception_id_e_dummy_end
};
typedef enum mk_lang_exception_id_e mk_lang_exception_id_t;
typedef mk_lang_exception_id_t const mk_lang_exception_id_ct;
typedef mk_lang_exception_id_t* mk_lang_exception_id_pt;
typedef mk_lang_exception_id_t const* mk_lang_exception_id_pct;


struct mk_lang_exception_s
{
	mk_lang_exception_id_t m_id;
	mk_lang_types_ulong_t m_data[2];
};
typedef struct mk_lang_exception_s mk_lang_exception_t;
typedef mk_lang_exception_t const mk_lang_exception_ct;
typedef mk_lang_exception_t* mk_lang_exception_pt;
typedef mk_lang_exception_t const* mk_lang_exception_pct;


mk_lang_jumbo void mk_lang_exception_make_none(mk_lang_exception_pt const ex) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_exception_is(mk_lang_exception_pct const ex) mk_lang_noexcept;


#define mk_lang_exception_if_is_return(x) if(mk_lang_exception_is(x)) mk_lang_unlikely return; ((void)(0))
#define mk_lang_exception_if_is_break(x) if(mk_lang_exception_is(x)) mk_lang_unlikely break; ((void)(0))
#define mk_lang_exception_if_is_goto_exret(x) if(mk_lang_exception_is(x)) mk_lang_unlikely goto exret; ((void)(0))
#define mk_lang_exception_if_is_goto_label(x, label) if(mk_lang_exception_is(x)) mk_lang_unlikely goto label; ((void)(0))


#if mk_lang_jumbo_want == 1
#include "mk_lang_exception.c"
#endif
#endif
