#include "../common/types.h"
extern "C" s32 D_00361f60;
extern "C" u8* func_002dc7c8(s32);
extern "C" f32 func_002deac0(f32*, f32, f32);
extern "C" void func_002deba0(f32*, u8*, f32, f32);
extern "C" void func_002def70(f32*, u8*);

void func_002df470(f32* object, u8* other) {
    func_002def70(object, other);
    s32 target = D_00361f60;
    func_002deac0(object, *(f32*)(func_002dc7c8(target) + 220), *(f32*)(func_002dc7c8(target) + 224));
    // why: the original ends with a tail jump into func_002deba0, which has no recovered definition
    // and no used call site; its own paths leave v0 unset on the early exit, so no typed return is invented
    func_002deba0(object, other, *(f32*)(func_002dc7c8(target) + 228), *(f32*)(func_002dc7c8(target) + 232));
}
