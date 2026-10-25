#include "../common/types.h"
extern "C" u32 func_00294000(u32);
extern "C" u32 func_002941a8(void*);
extern "C" u32 func_00276c18(void);

s32 func_002952f8(s32 target) {
    s32 index = 0;
    s32 found = -1;
    s32 result = -1;
    u32 object = func_00294000(0);
    s32 count = *(s32*)(object + 8);
    s8* entries = (s8*)(object + 16);
    if (count > 0) {
        s8* cursor = entries;
        do {
            if (*cursor < 20) {
                if (func_002941a8(cursor) != 0 || func_00276c18() != 0) {
                    found++;
                    if (*cursor == target) {
                        result = found;
                        break;
                    }
                }
                count = *(s32*)(object + 8);
            }
            index++;
            cursor += 16;
        } while (index < count);
    }
    return result;
}
