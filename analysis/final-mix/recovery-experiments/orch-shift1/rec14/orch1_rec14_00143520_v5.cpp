#include "../common/types.h"

typedef unsigned int Quad __attribute__((mode(TI)));

struct Local {
    u8 pad0[0x30];
    Quad vec;
    u8 padv[0x20];
    u16 half0;
    u16 half1;
    u16 half2;
    u8 pad1[6];
    f32 value;
    u8 pad2[0x08];
    s32 word;
    u8 pad3[0x14];
};

extern "C" f32 D_0036af3c;
extern "C" void func_0031b9e0(void*);
extern "C" void func_00143648(void*, s32);

void func_00143520(Quad* source, s32 argument) {
    Local local;
    func_0031b9e0(&local);
    if (&local.vec != source) {
        local.vec = *(volatile Quad*)source;
    }
    local.word = 0;
    local.half1 = 0xffff;
    local.value = D_0036af3c;
    local.half0 = 0xffff;
    local.half2 = 0xffff;
    func_00143648(&local, argument);
}
