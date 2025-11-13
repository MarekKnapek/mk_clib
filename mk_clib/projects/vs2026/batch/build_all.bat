@echo build_cryptor_msvc_debug_x86_32bit
@call build_cryptor_msvc_debug_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_cryptor_msvc_debug_x86_64bit
@call build_cryptor_msvc_debug_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_forwarder_tcp_msvc_debug_x86_32bit
@call build_forwarder_tcp_msvc_debug_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_forwarder_tcp_msvc_debug_x86_64bit
@call build_forwarder_tcp_msvc_debug_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_fuzz_msvc_debug_x86_32bit
@call build_fuzz_msvc_debug_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_fuzz_msvc_debug_x86_64bit
@call build_fuzz_msvc_debug_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_hasher_msvc_debug_x86_32bit
@call build_hasher_msvc_debug_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_hasher_msvc_debug_x86_64bit
@call build_hasher_msvc_debug_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_hosts_msvc_debug_x86_32bit
@call build_hosts_msvc_debug_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_hosts_msvc_debug_x86_64bit
@call build_hosts_msvc_debug_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_i2cp_msvc_debug_x86_32bit
@call build_i2cp_msvc_debug_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_i2cp_msvc_debug_x86_64bit
@call build_i2cp_msvc_debug_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_iip_msvc_debug_x86_32bit
@call build_iip_msvc_debug_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_iip_msvc_debug_x86_64bit
@call build_iip_msvc_debug_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_info_msvc_debug_x86_32bit
@call build_info_msvc_debug_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_info_msvc_debug_x86_64bit
@call build_info_msvc_debug_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_order_msvc_debug_x86_32bit
@call build_order_msvc_debug_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_order_msvc_debug_x86_64bit
@call build_order_msvc_debug_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_test_msvc_debug_x86_32bit
@call build_test_msvc_debug_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_test_msvc_debug_x86_64bit
@call build_test_msvc_debug_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_cryptor_msvc_release_x86_32bit
@call build_cryptor_msvc_release_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_cryptor_msvc_release_x86_64bit
@call build_cryptor_msvc_release_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_forwarder_tcp_msvc_release_x86_32bit
@call build_forwarder_tcp_msvc_release_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_forwarder_tcp_msvc_release_x86_64bit
@call build_forwarder_tcp_msvc_release_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_hasher_msvc_release_x86_32bit
@call build_hasher_msvc_release_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_hasher_msvc_release_x86_64bit
@call build_hasher_msvc_release_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_hosts_msvc_release_x86_32bit
@call build_hosts_msvc_release_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_hosts_msvc_release_x86_64bit
@call build_hosts_msvc_release_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_i2cp_msvc_release_x86_32bit
@call build_i2cp_msvc_release_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_i2cp_msvc_release_x86_64bit
@call build_i2cp_msvc_release_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_iip_msvc_release_x86_32bit
@call build_iip_msvc_release_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_iip_msvc_release_x86_64bit
@call build_iip_msvc_release_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_info_msvc_release_x86_32bit
@call build_info_msvc_release_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_info_msvc_release_x86_64bit
@call build_info_msvc_release_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_order_msvc_release_x86_32bit
@call build_order_msvc_release_x86_32bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@echo build_order_msvc_release_x86_64bit
@call build_order_msvc_release_x86_64bit.bat > nul
@if %errorlevel% neq 0 goto mk_bad

@goto mk_gud

:mk_bad
@exit /b %errorlevel%

:mk_gud
