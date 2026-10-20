#include "../common/types.h"
extern "C" void func_00179f10(s32*);
extern "C" void func_001d6ab0(s32);

s32 func_00179f80(s32* object) {
    func_00179f10(object);
    func_001d6ab0(object[0x2cf]);
    s32* data = (s32*)object[0x123];
    typedef s32 (*Fn)(s32*, s32, s32, s32);
    Fn fn = (Fn)((s32*)object[0])[0x1e];
    return fn(object, data[1], 0, 0);
}