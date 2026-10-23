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

u32 func_001819c0(void) {
    register u32 result asm("$16") = 0;
    asm("" : "+r"(result));
    if (func_00181500(0x817) == 0 || func_00181500(0x142b) != 0 || func_00181500(0x2001) != 0)
        result = 1;
    return result;
}

u32 func_00181a18(void) {
    register u32 result asm("$16") = 0;
    asm("" : "+r"(result));
    if (func_00181500(0x817) == 0 || func_00181500(0x142b) != 0 || func_00181500(0x2018) != 0)
        result = 1;
    return result;
}

void func_001cddb8(u64 object) {
    s32 iterator[8];
    FmStructurePacket packet;
    func_00190128(iterator);
    packet.input.words[3] = 0;
    s64 item = 0;
    while ((item = func_00190730(iterator, item)) != 0) {
        if ((*(u32*)(iterator[0] + 0x588) & 0x20000) != 0) {
            func_0018a818(&packet, iterator[0], item);
            func_001cdbc8(object, &packet, 2);
        }
    }
}
