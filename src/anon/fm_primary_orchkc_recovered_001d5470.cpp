#include "../common/types.h"
extern "C" u32 func_00168b38(...);
extern "C" u32 func_001d5370(void*,u64,s32);

// why: the original masks every read of byte 5 again (lbu + andi), as a bitfield read does
struct Info {
    u32 pad0;
    u32 kind : 8;
    u32 count : 8;
    u32 value : 16;
};

u32 func_001d5470(s32* object, u64 owner, Info* data) {
    u32 entry = func_00168b38(owner, -1, ((u8*)data)[4]);
    object[1] = *(s32*)(entry + 8);
    object[2] = data->value;
    if (data->count == 0) {
        return entry;
    }
    if (object[0] == 12) {
        object[0] = 13;
    }
    return func_001d5370(object + 3, owner, data->count - 1);
}
