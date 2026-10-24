#include "../common/types.h"
extern "C" void* func_001e3650(void*);
extern "C" void* func_001e3660(void*, s32);
extern "C" void* func_001e3c98(void*, s32);
extern "C" void* func_001e3e48(void*, s32);
extern "C" void* func_001e4028(void*, s32);

void* func_001e41e0(u8* object) {
    void* pointer = *(void**)(object + 136);
    pointer = func_001e3650(pointer);
    pointer = func_001e3660(pointer, 2);
    pointer = func_001e3c98(pointer, *(s32*)(object + 140) + 192);
    pointer = func_001e3e48(pointer, *(s32*)(object + 140) + 208);
    pointer = func_001e4028(pointer, *(s32*)(object + 140) + 224);
    asm volatile("" ::: "memory"); // why: original calls with jal and returns, no tail jump
    return pointer;
}
