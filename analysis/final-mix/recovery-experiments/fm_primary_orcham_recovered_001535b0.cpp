#include "../common/types.h"
extern "C" u8* D_0034a778;
extern "C" void func_00153540(u32,u8,u8,u8,u8);

void func_001535b0(u32 object, s32 index) {
    u8* entry = (u8*)(index * 24) + (u32)D_0034a778;
    func_00153540(object + 0x20, entry[0x14], entry[0x15], entry[0x16], entry[0x17]);
}
