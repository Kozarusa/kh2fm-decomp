#include "../common/types.h"
extern "C" u32 func_00287bc0(void);
// why: the accepted asm-label form failed the isolated link in v1; the probe linker script defines only the plain symbol
extern "C" s32 func_0028b040(s16* object);
extern "C" s32 func_002570a0(s32);
extern "C" void func_0027aed8(s32 value, u32* flag, s32* output);
extern "C" bool func_0027bf20(int arg1);
extern "C" s16* D_0035f01c;
extern "C" s8* D_0035f230;

bool func_0027c3e0(s32 index) {
    u32 mode = func_00287bc0();
    s32 data = func_0028b040(D_0035f01c);
    u32 flag;
    s32 output;
    if (mode == 15) {
        return 1;
    }
    if (mode != 16) {
        return 1;
    }
    func_0027aed8(func_002570a0(15), &flag, &output);
    if (index == -7) {
        return 1;
    }
    if (index == -6) {
        return func_0027bf20(data);
    }
    if ((u32)(index + 11) < 2) {
        s32 low = D_0035f230[6] < 2;
        return low == 0;
    }
    if (index == -5) {
        return 1;
    }
    if (D_0035f230[index * 8 + 17] != 0 && flag == 0) {
        return func_0027bf20(data);
    }
    return 0;
}
