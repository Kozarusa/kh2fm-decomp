#include "../common/types.h"

extern "C" void func_001bd5b0(u8*, s32, s32);
extern "C" void func_001bd668(u8*);

void func_001befd8(u8* object, s32 first, s32 second) {
    *(s32*)(object + 0xaa8) = first;
    *(s32*)(object + 0xaac) = second;
    func_001bd668(object);
    func_001bd5b0(object, 10, 0);
}
