#include "mk_win_gdi_object.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_win_base_dll_import mk_win_gdi_object_t mk_win_base_stdcall GetStockObject(int) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall DeleteObject(mk_win_gdi_object_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_gdi_object_t mk_win_gdi_object_get_stock(mk_win_gdi_object_stock_id_t const id) mk_lang_noexcept
{
	mk_win_gdi_object_t object;

	object = GetStockObject(((int)(id)));
	return object;
}

mk_lang_jumbo mk_win_base_bool_t mk_win_gdi_object_delete(mk_win_gdi_object_t const object) mk_lang_noexcept
{
	mk_win_base_bool_t deleted;

	deleted = DeleteObject(object);
	return deleted;
}
