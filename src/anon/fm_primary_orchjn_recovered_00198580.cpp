#include "../common/types.h"
extern "C" s32 func_0016c028(s32);
extern "C" u32 func_002bc188(u64,u64);

u32 func_00198580(u8* object, s32 value) {
    u8* owner = 0;
    if (value / 1000 == 500) {
        u32 flags = *(u32*)(object + 1416);
        if (flags & 0x40) {
            owner = object;
        } else if (flags & 0x4) {
            owner = *(u8**)(object + 2808);
        }
        if (owner != 0) {
            u8* info = *(u8**)(owner + 2484);
            s32 index = -1;
            if (info != 0) {
                index = *(s16*)(info + 2);
            }
            if (index >= 0) {
                value = value % 1000 + index * 1000;
            }
        }
    }
    s32 handle = func_0016c028((s32)object);
    return func_002bc188(value, handle);
}
