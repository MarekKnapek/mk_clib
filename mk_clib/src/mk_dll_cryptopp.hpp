#ifndef mk_include_guard_mk_dll_cryptopp_hpp
#define mk_include_guard_mk_dll_cryptopp_hpp


#include "mk_lang_jumbo.h"
#include "mk_lang_external_cryptopp.h"
#if mk_lang_external_cryptopp_have


#include "mk_lang_extern.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_bytes.h"


struct mk_dll_cryptopp_auto_seeded_random_pool_s
{
	mk_lib_iip_cp_bytes_128_t m_opaque;
};
typedef struct mk_dll_cryptopp_auto_seeded_random_pool_s mk_dll_cryptopp_auto_seeded_random_pool_t;
mk_lang_typedef(mk_dll_cryptopp_auto_seeded_random_pool);


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_dll_cryptopp_auto_seeded_random_pool_rw_construct(mk_dll_cryptopp_auto_seeded_random_pool_pt const auto_seeded_random_pool) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_dll_cryptopp.cpp"
#endif
#endif
