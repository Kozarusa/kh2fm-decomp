#include "../common/types.h"
struct State { u32 table, zero; u8 tag; u8 pad[3]; u32 reserved, unknown, enabled, count, clear1, clear2, clear3, limit; };
extern "C" u8 D_0032b930[];
extern "C" State D_0032b9a0;

// Preserve original registry aliases.
void func_00103080(s32 value, s32 flag) asm("_Z16wtarget_00103080jjjj");

void func_00103080(s32 value, s32 flag) {
    if ((flag == 0xffff && value == 1))
    {
        State * object = & D_0032b9a0;
        object->table = (u32)D_0032b930;
        object->limit = 0x1000;
        object->count = 130000;
        object->enabled = value;
        object->tag = 0x54;
        object->clear1 = 0;
        object->clear2 = 0;
        object->clear3 = 0;
        object->zero = 0;
    }
}
