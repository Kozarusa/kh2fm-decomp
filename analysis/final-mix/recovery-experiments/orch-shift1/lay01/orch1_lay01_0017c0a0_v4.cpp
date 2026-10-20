#include "../common/types.h"
struct __attribute__((aligned(16))) FmStructureQuad { u32 words[4]; };
extern "C" FmStructureQuad func_0017c030(u32, void*, u32);
extern "C" void func_0017c4c8(u32, void*);
extern "C" void func_0017f488(f32, f32, s32, u32);

void func_0017c0a0(u64 unused, u32 object, u32 byteValue) {
    FmStructureQuad copy, extra;
    copy = func_0017c030(object, &extra, byteValue & 0xff);
    func_0017c4c8(object, &copy);
    func_0017f488(0.0f, 0.0f, (s32)object + 0x140, extra.words[0]);
    // why: binds the final constants to the original registers t7 and t6
    register u32 high asm("$15") = 5;
    // why: binds the final constants to the original registers t7 and t6
    register u32 low asm("$14") = 4;
    // why: keeps the constant order of the original final stores
    asm("" : "+r"(high)); asm("" : "+r"(low) : "r"(high)); *(u32*)(object+0x104)=high; *(u32*)(object+0x100)=low;
}
