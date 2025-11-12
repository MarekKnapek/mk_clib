@if "%1"=="inner" goto mk_inner
@cmd.exe /c "%~f0" inner %*
@exit /b %errorlevel%
@goto mk_end

:mk_inner
@if exist "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" goto mk_enterprise
@if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" goto mk_community
@exit /b 1
:mk_enterprise
@call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" amd64
@goto mk_next
:mk_community
@call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
@goto mk_next
:mk_next

@"%~dp0..\build\out\x64\DebugMSVC\mk_clib_fuzz.exe" "%~dp0corpus"
@if %errorlevel% neq 0 goto mk_bad

:mk_gud
@echo Gud.
@goto mk_end

:mk_bad
@echo Bad.
@exit /b %errorlevel%
@goto mk_end

:mk_end
