#include "../common/types.h"
extern "C" s32 D_00361f60;
extern "C" u8* func_002dc7c8(s32);
extern "C" f32 func_002deac0(f32*, f32, f32);
extern "C" void func_002deba0(u8*, u8*, f32, f32);
extern "C" void func_002def70(u8*, u8*);

void func_002df7d8(u8* object, u8* owner) {
    func_002def70(object, owner);
    s32 target = D_00361f60;
    func_002deac0((f32*)object, *(f32*)(func_002dc7c8(target) + 244), *(f32*)(func_002dc7c8(target) + 248));
    func_002deba0(object, owner, *(f32*)(func_002dc7c8(target) + 252), *(f32*)(func_002dc7c8(target) + 256));
}
