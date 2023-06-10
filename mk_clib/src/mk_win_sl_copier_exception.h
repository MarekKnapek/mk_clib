#ifndef include_guard_mk_win_sl_copier_exception
#define include_guard_mk_win_sl_copier_exception


#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


enum mk_win_sl_copier_exception_id_e
{
	mk_win_sl_copier_exception_id_e_cluster_size_not_even_multiple,
	mk_win_sl_copier_exception_id_e_read_failed,
	mk_win_sl_copier_exception_id_e_dummy_end

};
typedef enum mk_win_sl_copier_exception_id_e mk_win_sl_copier_exception_id_t;

struct mk_win_sl_copier_exception_s
{
	mk_win_sl_copier_exception_id_t m_id;
};
typedef struct mk_win_sl_copier_exception_s mk_win_sl_copier_exception_t;
typedef mk_win_sl_copier_exception_t const mk_win_sl_copier_exception_ct;
typedef mk_win_sl_copier_exception_t* mk_win_sl_copier_exception_pt;
typedef mk_win_sl_copier_exception_t const* mk_win_sl_copier_exception_pct;
typedef mk_win_sl_copier_exception_t mk_win_base_far* mk_win_sl_copier_exception_lpt;
typedef mk_win_sl_copier_exception_t mk_win_base_far const* mk_win_sl_copier_exception_lpct;
typedef mk_win_sl_copier_exception_t mk_win_base_near* mk_win_sl_copier_exception_npt;
typedef mk_win_sl_copier_exception_t mk_win_base_near const* mk_win_sl_copier_exception_npct;


mk_lang_jumbo void mk_win_sl_copier_exception_make(mk_lang_exception_pt const ex, mk_win_sl_copier_exception_id_t id) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_sl_copier_exception.c"
#endif
#endif
