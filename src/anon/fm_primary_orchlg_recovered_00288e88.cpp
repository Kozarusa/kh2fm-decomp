#include "../common/types.h"
extern "C" u64 func_0028af18(s32,u64);
extern "C" void func_0028b1b0(u8* select, u32 mask);
// why: types copied from the recovered definition fm_primary_orchem_recovered_0028b218.cpp; extern "C"
// because the C++ form fails the isolated link (probe linker script defines only the plain symbol, see
// 002888f8 v1), and functions.tsv registers the plain symbol func_0028b218
extern "C" void func_0028b218(u8* object, u8 flag);
// why: no recovered call site; the 8-byte original is `jr ra; sh a1,28(a0)` (a0 object, a1 value, store only,
// writes no v0); plain symbol func_0028b248 is registered in functions.tsv
extern "C" void func_0028b248(u8* object, u32 value);

void func_00288e88(u8* object) {
    for (s32 index = 0; index < *(s16*)(object + 4); index++) {
        (*(u32**)(object + 40))[index] = 0;
        for (s32 slot = 0; slot < 4; slot++) {
            // why: the original reloads both table pointers before every store, and stores the first
            // table entry before reloading the second pointer
            (*(volatile s16* volatile*)(object + 44))[index * 4 + slot] = -1;
            // why: the original reloads both table pointers before every store
            (*(s16* volatile*)(object + 48))[index * 4 + slot] = -1;
        }
        asm volatile("" ::: "memory"); // why: the original reloads the word table pointer each outer iteration
    }
    *(s16*)(object + 4) = 0;
    *(s16*)(object + 22) = 0;
    *(s16*)(object + 18) = 0;
    *(s16*)(object + 14) = 0;
    func_0028af18((s32)object, 115);
    func_0028b1b0(object, 0);
    func_0028b218(object, 0);
    func_0028b248(object, 1);
}
