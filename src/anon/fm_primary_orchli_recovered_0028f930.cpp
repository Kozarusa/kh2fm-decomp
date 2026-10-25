#include "../common/types.h"
// why: declaration copied from the testing call site in fm_primary_orcheh_recovered_00276a90.cpp
extern "C" u32 func_00139d78(u8*);
// why: declaration copied from the call site in fm_primary_oneword_recovered_002908f0.cpp
extern "C" u32 func_0028d6e8(u32 light);
extern "C" u8* D_0035f480;

s32 func_0028f930(s32 slot) {
    s32 index = 0;
    s32 offset = 0;
    s32 result = 0;
    do {
        if (slot < 0 || slot == index) {
            if (func_00139d78(D_0035f480 + offset) != 0) {
                result = 1;
                break;
            }
            if (func_0028d6e8((u32)(D_0035f480 + offset + 436)) != 0) {
                result = 1;
                break;
            }
        }
        index++;
        offset += 884;
    } while (index < 4);
    return result;
}
