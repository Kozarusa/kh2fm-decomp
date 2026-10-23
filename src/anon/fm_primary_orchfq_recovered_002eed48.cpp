#include "../common/types.h"
typedef void (*SlotFn)(u32*, u32, u32);
extern "C" u32 D_00363860[];
extern "C" u32 D_003637e0[];
extern "C" u32* func_001a93e8(u32*);
extern "C" void func_00106ac8(u32*);
extern "C" u32 func_001a9350(u32*);
extern "C" u32 func_00106420(u32*);

u32 func_002eed48(u32* object) {
    object[0] = (u32)D_00363860;
    u32* target = func_001a93e8(object + 11);
    ((SlotFn)(((u32*)target[0])[10]))(target, object[10], object[17]);
    func_00106ac8(object + 20);
    func_001a9350(object + 11);
    object[0] = (u32)D_003637e0;
    return func_00106420(object);
}
