#ifndef mk_include_guard_mk_dll_cryptopp_cpp
#define mk_include_guard_mk_dll_cryptopp_cpp
#include "mk_dll_cryptopp.hpp"

#include "mk_lang_external_cryptopp.h"
#if mk_lang_external_cryptopp_have

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"

#include <new>


namespace CryptoPP
{
	class mk_win_base_dll_import AutoSeededRandomPool
	{
	public:
		AutoSeededRandomPool(mk_lang_types_bool_t const blocking, mk_lang_types_uint_t const seed_size) mk_lang_noexcept;
	};
}


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_dll_cryptopp_auto_seeded_random_pool_rw_construct(mk_dll_cryptopp_auto_seeded_random_pool_pt const auto_seeded_random_pool) mk_lang_noexcept
{
	mk_lang_types_void_pt place;
	CryptoPP::AutoSeededRandomPool* obj;

	mk_lang_assert(auto_seeded_random_pool);

	try
	{
		place = ((mk_lang_types_void_pt)(auto_seeded_random_pool));
		obj = ::new(place)CryptoPP::AutoSeededRandomPool(false, 32); mk_lang_assert(obj == place);
	}
	catch(...)
	{
		mk_lang_check_return(mk_lang_false);
	}
	return 0;
}


#else
static void mk_dll_cryptopp_dummy(void){}
#endif
#endif
