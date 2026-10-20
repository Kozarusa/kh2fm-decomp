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

u8* func_0018db38(u64 first, u32 object, u32 byteValue, u64 fourth) {
    u8 flags[16];
    s64 available = func_0018d940();
    u8* result = 0;
    if (available != 0) {
        result = func_001c0320((s32)object + 0xa50, first, flags);
        result = func_0018da18(first, object, result, fourth);
        *(u8*)(result + 0x24) = byteValue;
        if (flags[0] == 0) *(u32*)(result + 0x18) |= 3;
    }
    return result;
}

void func_0017c0a0(u64 unused, u32 object, u32 byteValue) {
    FmStructureQuad input, copy, extra;
    func_0017c030(&input, object, &extra, byteValue & 0xff);
    asm volatile("lq $8,0(%1); sq $8,0(%0)"
                 : : "r"(&copy), "r"(&input) : "$8", "memory");
    func_0017c4c8(object, &copy);
    func_0017f488(0.0f, 0.0f, (s32)object + 0x140, extra.words[0]);
    register u32 high asm("$15") = 5;
    register u32 low asm("$14") = 4;
    asm("" : : "r"(high), "r"(low));
    *(u32*)(object + 0x104) = high;
    *(u32*)(object + 0x100) = low;
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
