#include "../common/types.h"
extern "C" f32 D_00349e10;
extern "C" void func_00161598(u8*);
extern "C" void func_00161668(u8*, f32);
extern "C" u32 func_0011ea40(f32, u32);

u32 func_00160430(u8* object) {
    func_00161598(object + 0x110);
    func_00161668(object + 0x110, D_00349e10);
    return func_0011ea40(D_00349e10, *(u32*)(object + 0x1c0));
}
