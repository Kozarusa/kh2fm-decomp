#include "../common/types.h"
extern "C" s32 D_01e2bfa4;
extern "C" u8* D_01e2bfa0;
extern "C" void func_002e93a0(u8*);

u8* func_002e9850() {
    D_01e2bfa4 = D_01e2bfa4 + 1;
    u8* base = D_01e2bfa0;
    s32 index = *(s32*)(base + 0x7f8) - 1;
    *(s32*)(base + 0x7f8) = index;
    register u32 slot asm("$14") = index * 4; // why: original forms the slot address in t6
    slot += (u32)base;
    u8* result = base + ((u32)*(s32*)(slot + 0x780) << 6);
    func_002e93a0(result);
    return result;
}
