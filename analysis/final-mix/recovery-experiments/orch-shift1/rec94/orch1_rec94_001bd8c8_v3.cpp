#include "../common/types.h"

extern "C" u32 func_001b8e88(u16);
extern "C" void func_001bd918(u8*, u32, u32);

void func_001bd8c8(u8* object) {
    s32* table = *(s32**)(object + 0x8c0);
    u8* base = (u8*)*table;
    u8* entry = (u8*)(*(s32*)(base + 0x6c) * 12) + (u32)base;
    u32 result = func_001b8e88(*(u16*)(entry + 0xe));
    func_001bd918(object, result, 0);
    asm volatile("" ::: "memory"); // why: prevents tail call, original uses jal plus epilogue
}
