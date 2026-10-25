#include "../common/types.h"
// why: declaration copied from the accepted call site in fm_primary_close_recovered.cpp, whose result is used here; extern "C" because the isolated probe linker script defines only the plain symbol
extern "C" u32 func_00139d78(void);
// why: declaration copied from the recovered call site in fm_primary_orchlh_recovered_0028b520.cpp (same use); extern "C" because the isolated probe linker script defines only the plain symbol
extern "C" u8* func_0023f1b0(u32);
// why: accepted definition in fm_primary_orchkw_recovered_0023c3e0.cpp returns u8* from (Object0023c3e0*, s32, s32); that struct is not shared here, so the object is u8* as in fm_primary_orchlh_recovered_0028b520.cpp; extern "C" because the isolated probe linker script defines only the plain symbol
extern "C" u8* func_0023c3e0(u8*, s32, s32);

u8* func_0028dbf8(u32 object, s16* keys, u8* values) {
    if (func_00139d78() == 0) {
        return 0;
    }
    int found = -1;
    int key = *(s32*)(func_0023f1b0(object) + 0x4c);
    s16* cursor = keys;
    s32 index = 0;
    do {
        s32 offset = index * 2;
        if (key == *cursor) {
            // why: integer address sum (offset first) keeps the original t4 + s2 operand order and register choice; the pointer form (v2) does not
            found = *(s16*)(offset + (u32) values);
            break;
        }
        index += 1;
        cursor += 1;
    } while (index < 3);
    if (found < 0) {
        return 0;
    }
    return func_0023c3e0(func_0023f1b0(object), found, 0);
}
