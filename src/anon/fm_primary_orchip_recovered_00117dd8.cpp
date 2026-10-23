// func_00117dd8: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
// func_00117dd8: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
struct Slot { u8 data[64]; };
struct Scope { ~Scope() {} };
extern "C" u8 D_003476f0[];
extern "C" u32 func_00113668(u32*);
extern "C" u64 func_0018f028(...);
extern "C" u32 func_001dc920(s32);
extern "C" s32 func_00117910(u8*, s32);

u32 func_00117dd8(u8* value_object) {
    u32 result;
    Scope scope;
    register u8* object asm("$18") = value_object; // why: original keeps object in s2 after the loop
    *(u8**)(object + 0) = D_003476f0;
    s32* pointer = (s32*)(object + 40);
    for (s32 index = 0; index < 24; index++) {
        s32 value = *pointer;
        pointer += 16;
        if (value != 0) {
            func_001dc920(value);
        }
        func_00117910(object, index);
    }
    s32 entry = *(s32*)(object + 1568);
    if (entry != 0) {
        func_0018f028(entry);
        *(s32*)(object + 1568) = 0;
    }
    Slot* begin = (Slot*)(object + 32);
    if (begin != 0) {
        Slot* slot = (Slot*)(object + 1568);
        do {
        } while (begin != slot && (--slot, 1));
    }
    result = func_00113668((u32*)object);

    return result;
}
