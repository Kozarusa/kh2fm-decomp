#include "../common/types.h"
extern "C" u8* func_00176fb0(u8*, s32);
extern "C" s32 func_001a0920(u8*, u8*);
extern "C" void func_00177008(u8*, u8*, u8*);
extern "C" u64 func_001b9d40(...);

s32 func_001790c0(u8* object) {
    s32 result;
    u8* party = func_00176fb0(object, 11);
    if (party != 0 && func_001a0920(party, object) != 0 && func_001b9d40(object) != 0) {
        func_00177008(object, party, *(u8**)(object + 0xb40) + 4);
        // why: VU macro zero-fill of a 16-byte vector, copied from accepted sibling func_00178570
        asm volatile(
            "vsub.xyzw $vf1,$vf0,$vf0;"
            "sqc2 $vf1,0(%0)" : : "r"(object + 0x10) : "memory");
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
