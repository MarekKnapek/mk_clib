#include "mk_lang_strlen.h"

#include "mk_lang_types.h"


#define mk_lang_strlen_t_name mk_lang_strlen_n
#define mk_lang_strlen_t_type mk_lang_types_pchar_t
#include "mk_lang_strlen_inl_filec.h"

#define mk_lang_strlen_t_name mk_lang_strlen_w
#define mk_lang_strlen_t_type mk_lang_types_wchar_t
#include "mk_lang_strlen_inl_filec.h"
