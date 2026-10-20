#include "../common/types.h"
extern "C" void* func_001e3650(void*);
extern "C" void* func_001e3660(void*, s32);
extern "C" void* func_001e3c98(void*, s32);
extern "C" void* func_001e3e48(void*, s32);
extern "C" void* func_001e4028(void*, s32);

void func_001e41e0(u8* object) {
    void* result = func_001e3650(*(void**)(object + 136));
    result = func_001e3660(result, 2);
    result = func_001e3c98(result, *(s32*)(object + 140) + 192);
    result = func_001e3e48(result, *(s32*)(object + 140) + 208);
    func_001e4028(result, *(s32*)(object + 140) + 224);
}