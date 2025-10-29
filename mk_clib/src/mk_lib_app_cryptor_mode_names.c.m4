include(`mk_mm_strings.m')dnl
include(`mk_lib_app_cryptor_mode_stream.m')dnl
mk_mm_strings_generate_source(`mk_lib_app_cryptor_mode_names', mk_lib_app_cryptor_mode_stream_mm_for_modes_all(`$1, $2, '))dnl
