#include "../common/types.h"
typedef void (*Method)(s32, u16, u8, s32, s32);
extern "C" s32 func_00186078(s32);
extern "C" s32 func_0016bba8(...);

s32 func_001a4388() {
    s32 object = 0;
    while ((object = func_00186078(object)) != 0) {
        if ((*(u32*)((u8*)object + 268) & 0x100000) != 0) {
            continue;
        }
        s32 entry = 0;
        while ((entry = func_0016bba8(object, 13, entry)) != 0) {
            Method method = *(Method*)(*(u8**)object + 80);
            method(object, *(u16*)((u8*)entry + 2), *(u8*)entry, object, 0);
        }
    }
    return object;
}
