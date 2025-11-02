call mk_clib_float_analyzer_b128.bat || goto mk_bad
call mk_clib_float_analyzer_b16.bat || goto mk_bad
call mk_clib_float_analyzer_b32.bat || goto mk_bad
call mk_clib_float_analyzer_b64.bat || goto mk_bad
call mk_clib_hasher.bat || goto mk_bad
call mk_clib_info.bat || goto mk_bad
goto mk_gud
:mk_bad
echo Bad.
exit /b 1
:mk_gud
echo Gud.
