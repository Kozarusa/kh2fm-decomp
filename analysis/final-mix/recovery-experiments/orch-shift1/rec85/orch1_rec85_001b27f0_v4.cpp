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
    func_0017c030(&frame.packet, object, frame.result, flag);
    Quad* copy = &frame.copy;
    *copy = frame.packet;
    func_001b6dd0(object, copy);
    object[0x514] = 4;
    func_0017f488((u32)object + 0x140, frame.result[0], 0.0f, 0.0f);
    *(s32*)(object + 0x104) = 5;
    *(s32*)(object + 0x100) = 4;
}

