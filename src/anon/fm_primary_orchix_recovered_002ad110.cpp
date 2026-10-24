#include "../common/types.h"
extern "C" u32 func_00294000(u32);
extern "C" void func_00294020(s32);
extern "C" s32 D_0035f620;
extern "C" s32 D_0035f628;
extern "C" s32 D_0035f62c;

u32 func_002ad110(void) {
    u32 data;
    u32 index;
    s32 count;
    u32 bit;
    u32 word;

    func_00294020(D_0035f620);
    data = func_00294000(3);
    D_0035f628 = D_0035f628 + *(s32*)(data + 8);
    count = *(s32*)(data + 8);
    index = 0;
    if (count > 0) {
        do {
            bit = index & 0x1f;
            word = index >> 5;
            index = index + 1;
            if ((*(u32*)(word * 4 + D_0035f620) & (1 << bit)) != 0) {
                D_0035f62c = D_0035f62c + 1;
                count = *(s32*)(data + 8);
            }
        } while ((s32)index < count);
    }
    return data;
}
