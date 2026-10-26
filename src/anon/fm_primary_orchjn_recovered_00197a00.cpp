#include "../common/types.h"
extern "C" u32 D_0035037c;
extern "C" s32 D_01c61b40;
extern "C" void func_001024a8(u32);
extern "C" u32 func_00105110(...);
extern "C" void func_00196e00(u32);
extern "C" u32 func_00197028(u32);
extern "C" s32 func_001991a8(s32, s32);

void func_00197a00(u32 value) {
    if (D_0035037c != 0) {
        if (func_00197028(D_0035037c) != 0) {
            return;
        }
        u32 object = D_0035037c;
        u16 half = *(u16*)(*(u8**)(object + 0x3c) + 2);
        u8 flag = half & 1;
        if (object != 0) {
            func_00196e00(object);
            func_00105110(object);
        }
        if (flag) {
            s32 count = D_01c61b40;
            s32 previous = count;
            count = count + 1;
            D_01c61b40 = count;
            if (func_001991a8(0x4c, previous) != 0) {
                return;
            }
        }
    }
    func_001024a8(value);
}


