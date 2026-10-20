#include "../common/types.h"
extern "C" s64 func_00181500(s32);
extern "C" s64 func_0018d940(void);
extern "C" u32 func_001c0320(s32, u64, void*);
extern "C" u32 func_0018da18(u64, u32, u32, u64);
extern "C" void func_0017c030(void*, u32, void*, u32);
extern "C" void func_0017c4c8(u32, void*);
extern "C" void func_0017f488(f32, f32, s32, u32);
extern "C" void func_00190128(void*);
extern "C" s64 func_00190730(void*, s64);
extern "C" void func_0018a818(void*, u32, s64);
extern "C" void func_001cdbc8(u64, void*, s32);
extern "C" s64 func_0016bc20(u32, s32, s64);
extern "C" void func_0016bda8(u32, u32, s64);
struct __attribute__((aligned(16))) FmStructureQuad { u32 words[4]; };
struct __attribute__((aligned(16))) FmStructurePacket { FmStructureQuad input, output; };

void func_0017c0a0(u64 unused, u32 object, u32 byteValue) {
    FmStructureQuad input, copy, extra;
    func_0017c030(&input, object, &extra, byteValue & 0xff);
    asm volatile("lq $8,0(%1); sq $8,0(%0)"
                 : : "r"(&copy), "r"(&input) : "$8", "memory");
    func_0017c4c8(object, &copy);
    func_0017f488(0.0f, 0.0f, (s32)object + 0x140, extra.words[0]);
    register u32 high asm("$15") = 5;
    register u32 low asm("$14") = 4;
    asm("sw %1,260(%2)" : "=m"(*(u32*)(object+0x104)) : "r"(high),"r"(object)); *(u32*)(object+0x100)=low;
}
