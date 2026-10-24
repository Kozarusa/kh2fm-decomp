#include "../common/types.h"
typedef void (*NotifyFn)(u8*, s32, s32);
struct Entry {
    s32 first;
    s32 count;
    s32 last;
};
extern "C" s32 func_0017e138(u8* object, s32 value);
extern "C" u32 func_001a1910(...);
extern "C" void func_0013def8(u8*);
extern "C" void func_0019d3f8(u8*, s32, u32);
extern "C" void func_0019d3b8(u8*, s32, u32);
extern "C" void func_00187818(u8*);

u32 func_00187520(u8* object, s32 value, s32 index, u8 flag) {
    Entry* entries = *(Entry**)(object + 0x48c);
    if (entries == 0 || entries[index].count == 0) {
        return 0;
    }
    if ((*(u32*)(object + 0x588) & 0x4000) && value > 0) {
        if (*(u32*)(object + 0x7f8) & 4) {
            value = func_0017e138(object, value);
        } else if (flag) {
            ((NotifyFn)(*(void***)object)[0x54 / 4])(object, 20, 0);
        }
    }
    if (*(u32*)(object + 0x7f8) & 4) {
        return 0;
    }
    u32 result = func_001a1910(*(Entry**)(object + 0x48c), value, index);
    if (value > 0) {
        func_0013def8(object);
        func_0019d3f8(object, index, result);
    } else {
        func_0019d3b8(object, index, result);
    }
    if (result == 0 && index == 0) {
        func_00187818(object);
    }
    return result;
}
