#ifndef mk_include_guard_win_kernel_atom
#define mk_include_guard_win_kernel_atom


#include "mk_lang_jumbo.h"
#include "mk_win_base.h"


typedef mk_win_base_word_t mk_win_kernel_atom_t;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_atom.c"
#endif
#endif
