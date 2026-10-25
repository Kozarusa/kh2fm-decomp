#include "../common/types.h"
extern "C" void* func_0026b850();
extern "C" s32 func_002570a0(...);
// why: extern "C" because the accepted C++ declaration fails the isolated link (v1); the probe linker script defines only the plain symbol
extern "C" void func_0027aed8(s32 value, u32* flag, s32* output);
extern "C" u32 func_00281140(u32, s32);
extern "C" u32 func_00192048(...);
extern "C" u32 D_0035f010;
extern "C" s16* D_0035f230;

u32 func_0027b5d0(void) {
    u32 result = 0;
    u16* table = (u16*)func_0026b850();
    u32 flag;
    s32 index;
    func_0027aed8(func_002570a0(15), &flag, &index);
    if (flag == 0) {
        result = func_00281140(D_0035f010, index);
    } else {
        u16* cursor = table;
        s32 count = 0;
        for (s32 slot = 0; slot < 16; slot++, cursor++) {
            if (slot == 6) continue;
            if ((u8)(((*D_0035f230 >> slot) ^ 1) & 1)) continue;
            if (index == count) {
                u16 name = 0xb2ec;
                if (slot != 7) name = *cursor;
                result = func_00192048(name);
                break;
            }
            count++;
        }
    }
    return result;
}
