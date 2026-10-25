#include "../common/types.h"
// why: 8-byte table entries; word at +0 is passed on, byte at +7 holds the flags
struct KeyEntry {
    s32 text;
    u8 pad[3];
    u8 flags;
};
extern "C" KeyEntry D_003742c8[];
extern "C" s8 D_00374268[];
extern "C" u8 D_00374270[];
// why: a0 is passed through unchanged as the key object; v0 is read as a count
extern "C" s32 func_00283a58(u32);
// why: copied from the recovered call site in fm_primary_orchfh_recovered_002be4b0.cpp
extern "C" u32 func_002fee78(u32, u32, u32, u32);

u32 func_00283eb8(u32 object, s32 index) {
    u8 flags = D_003742c8[index].flags;
    s32 kind = func_00283a58(object);
    if ((flags & 0xfb) != 0) {
        if (kind == 1) {
            if ((flags & 2) == 0) {
                kind = 2;
            }
        }
    } else {
        kind = 2;
    }
    return func_002fee78(object, (u32)D_00374270, D_003742c8[index].text, D_00374268[kind]);
}
