#ifndef mk_include_guard_mk_iip_cp_client_data_impl_c
#define mk_include_guard_mk_iip_cp_client_data_impl_c
#include "mk_iip_cp_client_data_impl.h"

#include "mk_iip_cp_mallocator_global.h"


#define mk_sl_ring_dynamic_t_name mk_iip_cp_client_data_impl_rrs
#define mk_sl_ring_dynamic_t_element mk_iip_cp_client_data_impl_rr_t
#define mk_sl_ring_dynamic_t_mallocatorg mk_iip_cp_mallocator_global
#include "mk_sl_ring_dynamic_inl_filec.h"
#include "mk_sl_ring_dynamic_inl_fileu.h"


#endif
