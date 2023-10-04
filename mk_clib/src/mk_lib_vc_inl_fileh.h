#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


typedef void mk_lib_vc_logger_ctx_t;
typedef mk_lib_vc_logger_ctx_t const mk_lib_vc_logger_ctx_ct;
typedef mk_lib_vc_logger_ctx_t* mk_lib_vc_logger_ctx_pt;
typedef mk_lib_vc_logger_ctx_t const* mk_lib_vc_logger_ctx_pct;

typedef mk_lang_types_sint_t(mk_lib_vc_logger_fnc_t)(mk_lib_vc_logger_ctx_pt, mk_lang_types_pchar_pct);
typedef mk_lib_vc_logger_fnc_t* mk_lib_vc_logger_fnc_pt;


#include "mk_lib_vc_inl_defd.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_vc_inl_defd_decrypt(mk_lib_vc_inl_defd_reader_pt const reader_ctx, mk_lib_vc_inl_defd_reader_seek_pt const reader_seek, mk_lib_vc_inl_defd_reader_read_pt const reader_read, mk_sl_cui_uint8_pct const password, mk_lang_types_sint_t const password_len, mk_lang_types_ulong_t const pim, mk_lib_vc_logger_ctx_pt const logger_ctx, mk_lib_vc_logger_fnc_pt const logger_fnc, mk_lib_vc_inl_defd_writer_pt const writer_ctx, mk_lib_vc_inl_defd_writer_write_pt const writer_write) mk_lang_noexcept;


#include "mk_lib_vc_inl_defu.h"
