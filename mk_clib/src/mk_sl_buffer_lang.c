#include "mk_sl_buffer_lang.h"

#include "mk_sl_mallocator_lang.h"


#if \
	!defined mk_sl_buffer_t_name && \
	!defined mk_sl_buffer_t_mallocator
#define mk_sl_buffer_t_name lang
#define mk_sl_buffer_t_mallocator mk_sl_mallocator_lang
#endif
#include "mk_sl_buffer_inl_filec.h"
