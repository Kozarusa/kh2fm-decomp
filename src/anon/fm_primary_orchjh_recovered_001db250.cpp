#include "../common/types.h"
extern "C" f32 D_0036e7a0;
extern "C" s32 D_0034e948;
extern "C" void func_0017d0e8(void*, f32);
extern "C" s32 func_0019c778(s32, void*);

s32 func_001db250(u8* object) {
    u32 buffer[4];
    register u8* entry asm("$15") = *(u8**)(object + 0x6c); // why: original loads the field pointer into t7 before the global address
    f32 angle = *(f32*)(entry + 0x20);
    register f32* pointer asm("$15") = &D_0036e7a0; // why: original reuses t7 for the global address after the field load
    asm("" : "+r"(pointer) : "f"(angle)); // why: original forms the global address in a register after the field load
    func_0017d0e8(buffer, *pointer - angle);
    return func_0019c778(D_0034e948, buffer);
}
