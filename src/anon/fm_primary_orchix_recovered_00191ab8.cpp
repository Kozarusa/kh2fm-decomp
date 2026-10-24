#include "../common/types.h"
extern "C" u32 func_00176b20(...);
extern "C" u32 func_00185ac0(...);
extern "C" u32 func_0019ba60(...);

u32 func_00191ab8(void) {
    s32 index;
    s32 member;
    s32 object;
    s32 result;
    s32* cursor;
    s32 slot;

    index = 0;
    do {
        object = func_00176b20(index);
        result = func_0019ba60(object);
        if (result != 0) {
            slot = 0;
            cursor = (s32*)(object + 0xaf8);
            while (1) {
                member = *cursor;
                result = func_0019ba60(member);
                cursor += 1;
                if (result != 0 && func_00185ac0(member) == 0) {
                    return 1;
                }
                slot += 1;
                if (slot > 1) {
                    break;
                }
            }
        }
        index += 1;
        if (index > 2) {
            return 0;
        }
    } while (1);
}
