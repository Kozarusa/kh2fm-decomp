#include "../common/types.h"
extern "C" u32 func_00287bc0(void);
extern "C" int func_0028b040(...);
extern "C" int func_002a6368(int);
extern "C" bool func_002944d0(void*);
extern "C" s32 D_0035f200;
extern "C" s8* D_0035f5ec;

bool func_002a6878(s32 value) {
    if (value < 0) return true;
    u32 mode = func_00287bc0();
    bool result = true;
    if (mode != 37) {
        if (mode != 38) result = false;
    } else {
        s32 index = func_0028b040(D_0035f200);
        u32 enabled = func_002944d0((void*)func_002a6368(D_0035f5ec[index + 6]));
        result = enabled != 0;
    }
    return result;
}
