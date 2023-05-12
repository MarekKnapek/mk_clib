#include "mk_sl_buffer_win_main_heap.h"

#include "mk_sl_mallocator_win_main_heap.h"


#if \
	!defined mk_sl_buffer_t_name && \
	!defined mk_sl_buffer_t_mallocator
#define mk_sl_buffer_t_name win_main_heap
#define mk_sl_buffer_t_mallocator mk_sl_mallocator_win_main_heap
#endif
#include "mk_sl_buffer_inl_filec.h"
