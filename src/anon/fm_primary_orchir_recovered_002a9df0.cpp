#include "../common/types.h"
extern "C" u32 func_00294000(u32);
extern "C" void func_00294020(s32);
extern "C" s32 func_002a9d68(void);
extern "C" s32 D_0035f610;

u32 func_002a9df0() {
    s32 sram;
    u32 data;
    s32 count;
    s32 index;
    u32 offset;
    u32* word;
    u32 bits;
    u32 mask;
    s32 base;
    sram = func_002a9d68();
    func_00294020(D_0035f610);
    data = func_00294000(3);
    count = *(s32*)(data + 8);
    index = 0;
    if (count > 0) {
        do {
            base = D_0035f610;
            offset = ((u32)index >> 5) * 4;
            word = (u32*)(offset + base);
            bits = *word;
            mask = 1 << (index & 0x1f);
            index++;
            if ((bits & mask) != 0 && (*(u32*)(offset + sram) & mask) != 0) {
                *word = bits & ~mask;
                count = *(s32*)(data + 8);
            }
        } while (index < count);
    }
    return data;
}
