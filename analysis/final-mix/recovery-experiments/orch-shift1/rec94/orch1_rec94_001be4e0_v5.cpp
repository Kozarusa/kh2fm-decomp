#include "../common/types.h"

extern "C" void func_001bc730(u8*, s32);
extern "C" void func_001bd5b0(u8*, s32, s32);
extern "C" void func_001bd618(u8*, s32);

void func_001be4e0(u8* object, s32 index) {
    u8* entry = object + index * 0x74 + 0x24;
    *(s32*)(object + 0xaa4) = index;
    s32 field = *(s32*)(**(u8***)(object + 0x8c0) + 0x6c);
    func_001bc730(entry, field);
    func_001bd618(object, 0);
    func_001bd5b0(object, *(s32*)(object + 0xaa4), 0);
}
