#include "../common/types.h"
extern "C" u16* func_001a8110(u16*);
// why: the original passes the entry id in a0 and compares v0 with the key; the accepted definition reads a0 through its own callee
extern "C" u32 func_001a3820(u32);

u16 func_00271870(u32 key) {
    u16 result = 0;
    u16* entry = 0;
    if (key == 0) {
        return 0;
    }
    while ((entry = func_001a8110(entry)) != 0) {
        u8 kind = ((u8*)entry)[2];
        if (kind == 18 || kind == 0) {
            if (func_001a3820(entry[0]) == key) {
                result = entry[0];
                break;
            }
        }
    }
    return result;
}
