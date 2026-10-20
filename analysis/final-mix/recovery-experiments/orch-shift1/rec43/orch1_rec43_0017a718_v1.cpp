#include "../common/types.h"
extern "C" u16 D_0036c4e8[];
extern "C" u8 D_0036c4f0[];
extern "C" s32 func_001a35f8(...);
extern "C" void func_00194070(u32, u32);

void func_0017a718(u32 object) {
    s32 index = 0;
    s32 count = 2;
    u16* pointer = D_0036c4e8;
    do {
        count--;
        s32 result = func_001a35f8(*pointer, 100);
        pointer++;
        index += (0 < result);
    } while (count >= 0);
    func_00194070(object, D_0036c4f0[index]);
}