cp mkcc.c mkcc.cpp
em++ \
-std=c++20 \
-DNDEBUG \
-O3 \
-g0 \
-flto \
-fno-rtti \
-fno-exceptions \
--no-entry \
-Wall \
-Wextra \
-Wpedantic \
-sASSERTIONS=0 \
-sSTACK_OVERFLOW_CHECK=0 \
-sCHECK_NULL_WRITES=0 \
-sVERBOSE=1 \
-sINVOKE_RUN=0 \
-sSTACK_SIZE=64kB \
-sMALLOC="none" \
-sABORTING_MALLOC=0 \
-sINITIAL_MEMORY=1MB \
-sMAXIMUM_MEMORY=1MB \
-sALLOW_MEMORY_GROWTH=0 \
-sMEMORY_GROWTH_GEOMETRIC_STEP=0.0 \
-sMEMORY64=0 \
-sUSE_CLOSURE_COMPILER=1 \
-sFILESYSTEM=0 \
-sEXPORTED_FUNCTIONS=_mkcc_get_key_size_max,_mkcc_get_iv_size_max,_mkcc_get_msg_size_max,_mkcc_get_data_addr,_mkcc_get_data_size,_mkcc_get_names,_mkcc_init,_mkcc_encrypt_append,_mkcc_encrypt_finish,_mkcc_decrypt_append,_mkcc_decrypt_finish \
-sSTRICT=1 \
-sDYNAMIC_EXECUTION=0 \
-sWASM=1 \
-sSTANDALONE_WASM=1 \
-sBINARYEN_IGNORE_IMPLICIT_TRAPS=1 \
-sLEGALIZE_JS_FFI=0 \
-sSUPPORT_ERRNO=0 \
-sSUPPORT_LONGJMP=0 \
-sDEFAULT_TO_CXX=0 \
mkcc.cpp \
-o \
mkcc.wasm
