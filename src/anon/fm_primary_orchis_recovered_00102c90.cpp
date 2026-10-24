// func_00102c90: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
struct State { u32 table, zero; u8 tag; u8 pad[3]; u32 reserved, unknown, enabled, count, clear1, clear2, clear3, limit; };
extern "C" u8 D_0032b930[];
extern "C" State D_0032b968;

// Preserve original registry aliases.
void func_00102c90(s32 value, s32 flag) asm("_Z16wtarget_00102c90jjjj");

void func_00102c90(s32 value, s32 flag) {
    if ((flag == 0xffff && value == 1))
    {
        State * object = & D_0032b968;
        object->table = D_0032b930;
        object->limit = 0x3800;
        object->count = 130000;
        object->enabled = value;
        object->tag = 0x46;
        object->clear1 = 0;
        object->clear2 = 0;
        object->clear3 = 0;
        object->zero = 0;
    }
}
