#include "../common/types.h"
struct Entry;
struct Unit;
extern "C" u8* func_0016e920(u32);
extern "C" u32 func_00199810(void*);
extern "C" s32 func_00199938(Entry*, Unit*);
extern "C" u32 func_0019ab30(Unit*, u32);

void func_00199f90(Unit* unit, Entry* entry) {
    struct Flags {
        u32 header;
        u32 hidden : 1;
    };
    if ((u8)((Flags*)unit)->hidden != 0) {
        return;
    }
    u8* data = func_0016e920(*(u32*)entry);
    if (func_00199810(entry) == 0) {
        return;
    }
    if (data[4] == 4 || data[4] == 21) {
        if (func_0019ab30(unit, *(u16*)((u8*)entry + 0x1e)) != 0) {
            func_00199938(entry, unit);
        }
    } else {
        s32 result = func_00199938(entry, unit);
        // why: the original keeps this call out of tail position (jal, then the shared epilogue)
        asm("" : "+r"(result));
    }
}
