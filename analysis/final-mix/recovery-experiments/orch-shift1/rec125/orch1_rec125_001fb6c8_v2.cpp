#include "../common/types.h"

struct Frame {
    u8* object;
    s32 word;
    u8* table;
    f32 second;
    f32 first;
    u8* inner;
};

extern "C" u8 D_01d9e8c0[];
extern "C" s32 func_0021f620(Frame*, s32);

s32 func_001fb6c8(u8* object) {
    u8* self = object;
    Frame frame;
    frame.inner = object + 48;
    frame.first = *(f32*)(object + 64);
    frame.word = *(s32*)(object + 72);
    frame.second = *(f32*)(object + 68);
    frame.table = D_01d9e8c0;
    frame.object = self;
    return func_0021f620(&frame, 0);
}