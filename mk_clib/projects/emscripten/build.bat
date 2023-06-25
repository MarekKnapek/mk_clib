emcc ^
-DNDEBUG ^
-O3 ^
-g0 ^
-fno-rtti ^
-fno-exceptions ^
--no-entry ^
-flto ^
-sASSERTIONS=0 ^
-sSTACK_OVERFLOW_CHECK=0 ^
-sCHECK_NULL_WRITES=0 ^
-sVERBOSE=1 ^
-sINVOKE_RUN=0 ^
-sSTACK_SIZE=64kB ^
-sMALLOC="none" ^
-sABORTING_MALLOC=0 ^
-sINITIAL_MEMORY=2MB ^
-sMAXIMUM_MEMORY=2MB ^
-sALLOW_MEMORY_GROWTH=0 ^
-sMEMORY_GROWTH_GEOMETRIC_STEP=0.0 ^
-sMEMORY64=0 ^
-sUSE_CLOSURE_COMPILER=1 ^
-sFILESYSTEM=0 ^
-sEXPORTED_FUNCTIONS=_mkch_get_alg_name_addr,_mkch_get_alg_name_size,_mkch_get_msg_addr,_mkch_get_msg_size,_mkch_get_digest_addr,_mkch_get_digest_size,_mkch_get_alg_count,_mkch_get_alg_name,_mkch_get_alg_pretty_name,_mkch_init,_mkch_append,_mkch_finish,_mkch ^
-sSTRICT=1 ^
-sDYNAMIC_EXECUTION=0 ^
-sWASM=1 ^
-sSTANDALONE_WASM=1 ^
-sBINARYEN_IGNORE_IMPLICIT_TRAPS=1 ^
-sLEGALIZE_JS_FFI=0 ^
-sSUPPORT_ERRNO=0 ^
-sSUPPORT_LONGJMP=0 ^
-sDEFAULT_TO_CXX=0 ^
mkch.c ^
-o ^
mkch.wasm

REM -sEXIT_RUNTIME=0 ^
REM -sMEMORY_GROWTH_GEOMETRIC_CAP=2MB ^
REM -sMEMORY_GROWTH_LINEAR_STEP=16MB ^
REM -sGLOBAL_BASE=1024 ^
