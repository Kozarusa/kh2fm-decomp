#include "../common/types.h"
extern "C" u32 func_00102a38(s32,s32);
extern "C" u32 func_00103eb0(void);
extern "C" u8 D_002933b8[];
extern "C" s16* D_0035f4e8;
s32 func_00293668(void) {
    s32 result = 0;
    u32 object = func_00103eb0();
    if (func_00102a38(*(s32*)(object + 4), (s32)D_002933b8) == 0) {
        s32 index = 0;
        s16* pointer = D_0035f4e8;
        do {
            s16 item = *pointer;
            pointer += 3;
            if (item >= 0) {
                result = 1;
                break;
            }
            ++index;
        } while (index < 8);
    } else {
        result = 1;
    }
    return result;
}

