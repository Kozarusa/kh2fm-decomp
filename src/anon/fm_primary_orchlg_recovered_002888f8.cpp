#include "../common/types.h"
// why: types copied from the recovered definition in fm_resume_recovered_09.cpp; extern "C" because the
// C++ form fails the isolated link (v1: the probe linker script defines only the plain symbol, which
// functions.tsv also registers as func_00288c58)
extern "C" void func_00288c58(int, int);
extern "C" u32 func_00288f48(s32,u16,u16,u16,u16);
extern "C" u64 func_0028af18(s32,u64);
extern "C" void func_0028b1b0(u8* select, u32 mask);

// why: a1 arrives as a full word (stored raw, sign-extended only for the call), so count is s32

void func_002888f8(u8* object, s32 count, u8 loop) {
    *(s16*)(object + 0) = 0;
    *(s16*)(object + 16) = count;
    *(s16*)(object + 2) = -1;
    *(s16*)(object + 28) = 1;
    *(u8*)(object + 36) = loop;
    *(s16*)(object + 20) = -1;
    *(s16*)(object + 4) = 0;
    *(s16*)(object + 18) = 0;
    *(s16*)(object + 22) = 0;
    *(s16*)(object + 24) = 0;
    *(s16*)(object + 26) = 0;
    *(u8*)(object + 37) = 0;
    *(u8*)(object + 38) = 0;
    *(u8*)(object + 39) = 0;
    func_00288c58((s32)object, (s16)count);
    func_00288f48((s32)object, 16, 32, 0, 0);
    for (s32 index = 0; index < *(s16*)(object + 16); index++) {
        for (s32 slot = 0; slot < 4; slot++) {
            // why: the original reloads both table pointers before every store, and stores the first
            // table entry before reloading the second pointer
            (*(volatile s16* volatile*)(object + 44))[index * 4 + slot] = -1;
            // why: the original reloads both table pointers before every store
            (*(s16* volatile*)(object + 48))[index * 4 + slot] = -1;
        }
    }
    *(s16*)(object + 14) = 0;
    func_0028af18((s32)object, 115);
    func_0028b1b0(object, 0);
}
