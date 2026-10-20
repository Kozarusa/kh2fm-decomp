#include "../common/types.h"
extern "C" s64 func_00181500(s32);
extern "C" s64 func_0018d940(void);
extern "C" u8* func_001c0320(s32, u64, void*);
extern "C" u8* func_0018da18(u64, u32, u8*, u64);
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

u32 func_0016c2b0(u32 destination, u32 object) {
    FmStructurePacket packet;
    packet.input.words[3] = 0;
    register FmStructureQuad* output asm("$18") = &packet.output;
    asm("" : "+r"(output));
    s64 item = func_0016bc20(object, 0x11, -1);
    register u32 callObject asm("$5");
    asm volatile("move %0,%1" : "=r"(callObject) : "r"(object));
    register s64 callItem asm("$6") = item;
    asm("" : "+r"(callItem));
    if (item != 0) {
        func_0018a818(&packet, callObject, callItem);
        asm volatile("lq $8,0(%1); sq $8,0(%0)"
                     : : "r"(destination), "r"(output) : "$8", "memory");
    } else {
        func_0016bda8(destination, callObject, callItem);
    }
    return destination;
}
