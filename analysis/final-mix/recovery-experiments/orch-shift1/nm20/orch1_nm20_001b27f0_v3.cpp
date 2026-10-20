#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Frame {
    Quad packet;
    Quad copy;
    s32 result[4];
};
extern "C" u32 func_0017c030(void*, u8*, s32*, u8);
extern "C" u32 func_001b6dd0(u8*, void*);
extern "C" void func_0017f488(u32, s32, f32, f32);

void func_001b27f0(u32 unused, u8* object, u8 flag) {
    Frame frame;
    register void* packet asm("$4") = &frame.packet; // why: original materializes packet in a0 before result in a2
    s32* result = frame.result;
    func_0017c030(packet, object, result, flag);
    asm volatile("lq $8,0(%1); sq $8,%0" : "=m"(frame.copy) : "r"(&frame.packet) : "$8", "memory"); // why: original copies the quad with lq/sq through t0; prior plain copies failed
    func_001b6dd0(object, &frame.copy);
    object[0x514] = 4;
    func_0017f488((u32)object + 0x140, frame.result[0], 0.0f, 0.0f);
    *(s32*)(object + 0x104) = 5;
    *(s32*)(object + 0x100) = 4;
}
