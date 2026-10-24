#include "../common/types.h"
extern "C" u32 func_00190140(s32);
extern "C" u64 func_002c04c8(...);
extern "C" u32 func_002c6490(s32);

u32 func_002c0470(s32 object) {
    u32 exists = func_00190140(object + 100);
    u32 result = 0;
    if (exists != 0) {
        func_002c04c8(object, object + 48, object + 64);
        func_002c6490(object);
        result = 1;
    }
    return result;
}
