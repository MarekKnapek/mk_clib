@if "%~1"=="inner" goto mk_inner
@cmd.exe /c ""%~f0" "inner" %*"
@if %errorlevel% neq 0 goto mk_outer_bad
@goto mk_outer_gud

:mk_inner
@echo off

set mk_project=%~2
set mk_compiler=%~3
set mk_config=%~4
set mk_arch=%~5
if "%mk_compiler%"=="MSVC" goto mk_compiler_gud
if "%mk_compiler%"=="Clang" goto mk_compiler_gud
goto mk_fail
:mk_compiler_gud
if "%mk_config%"=="Debug" goto mk_config_gud
if "%mk_config%"=="Release" goto mk_config_gud
goto mk_fail
:mk_config_gud
if "%mk_arch%"=="x86-32bit" goto mk_arch_gud
if "%mk_arch%"=="x86-64bit" goto mk_arch_gud
goto mk_fail
:mk_arch_gud
if "%mk_arch%"=="x86-32bit" set mk_platform=Win32
if "%mk_arch%"=="x86-64bit" set mk_platform=x64

if "%mk_arch%"=="x86-32bit" goto mk_find_msvs_x86_32bit
if "%mk_arch%"=="x86-64bit" goto mk_find_msvs_x86_64bit
goto mk_fail

:mk_find_msvs_x86_64bit
if exist "c:\Program Files\Microsoft Visual Studio\18\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" goto mk_enterprise_amd64_amd64
if exist "c:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" goto mk_community_amd64_amd64
goto mk_fail

:mk_enterprise_amd64_amd64
call "c:\Program Files\Microsoft Visual Studio\18\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" amd64
@echo off
goto mk_next

:mk_community_amd64_amd64
call "c:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
@echo off
goto mk_next

:mk_find_msvs_x86_32bit
if exist "c:\Program Files\Microsoft Visual Studio\18\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" goto mk_enterprise_amd64_i386
if exist "c:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" goto mk_community_amd64_i386
goto mk_fail

:mk_enterprise_amd64_i386
call "c:\Program Files\Microsoft Visual Studio\18\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" amd64_x86
@echo off
goto mk_next

:mk_community_amd64_i386
call "c:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64_x86
@echo off
goto mk_next

:mk_next
devenv.com "%~dp0..\mk_clib.slnx" /Build "%mk_compiler%-%mk_config%-S|%mk_arch%-S" /Project "%mk_project%" /ProjectConfig "%mk_compiler%-%mk_config%-P|%mk_platform%" /Out "%~dp0%mk_project%-%mk_compiler%-%mk_config%-%mk_arch%.txt"
if %errorlevel% neq 0 goto mk_bad
goto mk_gud

:mk_fail
exit /b 1
goto mk_end

:mk_bad
exit /b %errorlevel%
goto mk_end

:mk_gud
goto mk_end

:mk_outer_gud
@echo Gud.
@goto mk_end

:mk_outer_bad
@echo Bad.
@exit /b %errorlevel%
@goto mk_end

:mk_end
