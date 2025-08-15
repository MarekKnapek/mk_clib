@if "%1"=="inner" goto mk_inner
@cmd.exe /c "%~f0" inner %* || goto mk_fail
@goto mk_end

:mk_inner
@echo off
if "%2"=="" goto mk_all
if "%2"=="32" goto mk_32
if "%2"=="64" goto mk_64
exit /b 1
goto mk_end

:mk_all
cmd.exe /c "%~f0 32" || goto mk_fail
cmd.exe /c "%~f0 64" || goto mk_fail
goto mk_end

:mk_32
set path=%~dp0..\..\..\..\..\programy\tcc32;%path% || goto mk_fail
cmd.exe /c "%~dp0build_hasher_win_i386.bat" > nul || goto mk_fail
cmd.exe /c "%~dp0build_info_win_i386.bat" > nul || goto mk_fail
cmd.exe /c "%~dp0build_test_win_i386.bat" > nul || goto mk_fail
goto mk_end

:mk_64
set path=%~dp0..\..\..\..\..\programy\tcc64;%path% || goto mk_fail
cmd.exe /c "%~dp0build_hasher_win_amd64.bat" > nul || goto mk_fail
cmd.exe /c "%~dp0build_info_win_amd64.bat" > nul || goto mk_fail
cmd.exe /c "%~dp0build_test_win_amd64.bat" > nul || goto mk_fail
goto mk_end

:mk_fail
@exit /b %errorlevel%
@goto mk_end

:mk_end
