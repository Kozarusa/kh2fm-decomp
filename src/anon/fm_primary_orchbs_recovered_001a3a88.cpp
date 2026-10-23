#include "../common/types.h"
extern "C" s32 D_00350748;
extern "C" s32 D_01c6cafc;
extern "C" u8 D_01c6cae0[];
extern "C" s32 D_01c6cb00[];
extern "C" s32 D_01c6cb10;
extern "C" u32 func_001708f8(...);
extern "C" u8* func_00168b38(u32, s32, s32);
extern "C" u32 func_001dddd0(u32, u32);

void func_001a3a88() {
    u32 buffer = func_001708f8(D_00350748, -1);
    D_01c6cafc = buffer;
    u8* info = func_00168b38(buffer, 18, 0);
    func_001dddd0((u32)D_01c6cae0, *(u32*)(info + 8));
    s32 count = 3;
    s32* cursor = D_01c6cb00;
    do {
        *cursor = 0;
        count--;
        cursor++;
    } while (count >= 0);
    D_01c6cb10 = 0;
}
