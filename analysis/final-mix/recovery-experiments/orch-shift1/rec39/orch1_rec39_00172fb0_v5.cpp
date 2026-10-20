#include "../common/types.h"
struct Block {
    u8 a;
    u8 b;
    u8 c;
    u8 pad;
    u16 d;
    u16 e;
    u16 f;
};
extern "C" u32 func_00104f58(void*, s32, s64, u8, s64);

void func_00172fb0(u8* param) {
    Block local;
    local.b = *param;
    local.c = param[4];
    local.f = 0xffff;
    local.a = 0xff;
    local.d = 0xffff;
    local.e = 0xffff;
    func_00104f58(&local, *(s32*)(param + 8), 0, 0, 0);
}