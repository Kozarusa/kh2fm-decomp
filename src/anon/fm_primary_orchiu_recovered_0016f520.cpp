#include "../common/types.h"
extern "C" u8 D_004f6400[];
extern "C" char D_0036c460[];
extern "C" char D_0036c468[];
extern "C" char D_0036c478[];
extern "C" s32 func_0016f460();
extern "C" s32 func_0016f770(void*);
extern "C" s32 func_0016f7a0(void*);
extern "C" s32 func_00170978(char*);
extern "C" void func_002fee78(char*, const char*, u8*);
extern "C" char* func_002ff8b0(char*, s32);
extern "C" void func_002ff2e8(char*, const char*);

char* func_0016f520(u8* object, void* entry, char* buffer) {
    if (buffer == 0) {
        buffer = (char*)D_004f6400;
    }
    if (func_0016f460()) {
        func_002fee78(buffer, D_0036c460, object + 40);
        if (func_0016f7a0(entry) != 0 ||
            (func_0016f770(entry) != 0 && object[4] != 0 && func_00170978(buffer) < 2)) {
            func_002ff2e8(func_002ff8b0(buffer, 46), D_0036c468);
        }
    } else {
        if (func_0016f7a0(entry)) {
            func_002fee78(buffer, D_0036c478, object + 8);
        } else {
            buffer = 0;
        }
    }
    return buffer;
}
