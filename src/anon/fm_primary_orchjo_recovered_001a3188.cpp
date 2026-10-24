#include "../common/types.h"
struct Info {
    u8 pad[2];
    u8 type;
    u8 flags;
    u8 pad2[14];
    u16 index;
};
extern "C" u8 D_0032e020[];
extern "C" Info* func_001a80c8(...);
extern "C" s32 func_001a3018(u32, u32, s32);
extern "C" void func_001a32c8(u32, s32);
extern "C" s32 func_00188fe0(...);
extern "C" void func_00188a28(s32, u32);
extern "C" void func_00188b68(s32, u32, bool);
extern "C" void func_001a39c8(u32);

u32 func_001a3188(u32 id, u32 value, bool flag) {
    Info* info = func_001a80c8(id);
    u8* base = D_0032e020;
    s32 kind = func_001a3018(id, value, 1);
    if (kind == 0) {
        return 0;
    }
    u32 flags = info->flags;
    u32 locked = flags & 1;
    if (locked != 0 || kind == 100) {
        func_001a32c8(id, 1);
    } else {
        s32 record = func_00188fe0(base, kind);
        u8 type = info->type;
        if (type != 0) {
            if (type == 19) {
                func_00188b68(record, id, flag);
            }
        } else {
            func_00188a28(record, id);
            if (kind == 1 || kind == 14) {
                func_001a39c8(id);
            }
        }
    }
    flags = info->flags;
    if ((flags & 1) == 0) {
        u32 index = info->index;
        u32* bits = (u32*)(base + 6296);
        bits[index >> 5] |= 1 << (index & 31);
    }
    return 1;
}
