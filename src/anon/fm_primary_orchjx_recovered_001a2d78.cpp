#include "../common/types.h"
extern "C" u32 func_001a80c8(...);
extern "C" u32 func_001a3888(...);
extern "C" s32 func_001a8bd0(s32);
extern "C" u8* func_001a8c10(s32, s32);
extern "C" s32 func_001a2e50(u32, u8*);

s32 func_001a2d78(u32 object, u8* part) {
    s32 result = 0;
    u32 owner = func_001a80c8();
    if (func_001a3888(object) == 0) {
        result = func_001a2e50(owner, part);
    } else {
        s32 member = func_001a8bd0(-1);
        for (s32 index = 0; index < 4; index++) {
            part = func_001a8c10(member, index);
            if (part != 0) {
                result = (result != 0 || func_001a2e50(owner, part) != 0);
            }
        }
    }
    return result;
}
