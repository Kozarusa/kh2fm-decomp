#include "../common/types.h"
extern "C" u32 func_00106450(s64);

void func_002e7058(s32 object) {
    register s32 array asm("$4"); // why: original keeps the array pointer in a0
    s32 end;

    array = *(s32*)(object + 4);
    if (array != 0) {
        end = array + *(s32*)(array + -4) * 0x40;
        for (;;) {
            if (array == end) {
                break;
            }
            end = end + -0x40;
        }
        func_00106450((s64)(array + -0x10));
        return;
    }
    return;
}
