#include "../common/types.h"
// why: the original uses this callee's v0 as the node pointer, so it is declared returning u32 (form also listed in fm_primary_capacity_recovered_00303c48.cpp); the accepted definition is void, a discrepancy tracked separately
extern "C" u32 func_001e0188(...);

// why: every field is read and written through union members (alias set 0), so no access is reordered across another, as in the original
union Cell {
    s32 i;
    u32 u;
    f32 f;
    u16 h;
    u8 b;
    u8* p;
};

void func_001dec78(u8* object, s32 first, s32 second, u8* source, f32 scale) {
    u8* node;

    ((Cell*)(object + 0x40))->i = first;
    ((Cell*)(object + 0x44))->i = second;
    ((Cell*)(object + 0x50))->f = scale;
    ((Cell*)(object + 0x5c))->i = 1;
    ((Cell*)(object + 0x4c))->i = 0;
    ((Cell*)(object + 0x58))->p = 0;
    ((Cell*)(object + 0x48))->i = ((Cell*)(source + 0x30))->i;
    node = (u8*)func_001e0188(0x28);
    ((Cell*)(node + 2))->h = 0;
    ((Cell*)(object + 0x58))->p = node;
    ((Cell*)(node + 0))->h = ((Cell*)(source + 0x34))->h;
    ((Cell*)(((Cell*)(object + 0x58))->p + 0x04))->f = ((Cell*)(source + 0x00))->f;
    ((Cell*)(((Cell*)(object + 0x58))->p + 0x08))->f = ((Cell*)(source + 0x04))->f;
    ((Cell*)(((Cell*)(object + 0x58))->p + 0x0c))->f = ((Cell*)(source + 0x08))->f;
    ((Cell*)(((Cell*)(object + 0x58))->p + 0x10))->f = ((Cell*)(source + 0x10))->f;
    ((Cell*)(((Cell*)(object + 0x58))->p + 0x14))->f = ((Cell*)(source + 0x14))->f;
    ((Cell*)(((Cell*)(object + 0x58))->p + 0x18))->f = ((Cell*)(source + 0x18))->f;
    ((Cell*)(((Cell*)(object + 0x58))->p + 0x1c))->f = ((Cell*)(source + 0x20))->f;
    ((Cell*)(((Cell*)(object + 0x58))->p + 0x20))->f = ((Cell*)(source + 0x24))->f;
    ((Cell*)(((Cell*)(object + 0x58))->p + 0x24))->f = ((Cell*)(source + 0x28))->f;
    ((Cell*)(((Cell*)(object + 0x58))->p + 2))->h = 0;
    if (((Cell*)(source + 0x3c))->b != 0) {
        ((Cell*)(((Cell*)(object + 0x58))->p + 2))->h |= 1;
    }
    if (((Cell*)(source + 0x3d))->b != 0) {
        ((Cell*)(((Cell*)(object + 0x58))->p + 2))->h |= 2;
    }
    ((Cell*)(object + 0x5c))->u |= 8;
}
