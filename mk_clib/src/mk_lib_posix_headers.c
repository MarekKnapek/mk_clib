#include "mk_lib_posix_headers.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if !mk_lib_posix_headers_have


#if !defined errno
mk_lang_types_sint_t errno;
#endif


#endif
