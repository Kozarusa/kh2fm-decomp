#include "../common/types.h"
struct Item;
// Copied from the accepted call site fm_primary_orchlj_recovered_002969e0.cpp.
extern "C" u32 func_00276568(void);
extern "C" u32 func_00287bc0(void);
// Copied from the accepted call site fm_primary_orchlk_recovered_0029daa0.cpp.
extern "C" s32 func_0028afa8(s16* object);
extern "C" s16* D_0035f200;
// Signature of the accepted definition fm_primary_orchjf_recovered_0028afd0.cpp.
// why: extern "C" because the C++ declaration fails the isolated link (v1): the probe linker script defines only the plain symbol
extern "C" void func_0028afd0(Item* item, s32 value);
extern "C" s32* D_0035f608;

// why: the only exit is the tail call into 0028afd0, whose accepted definition is void (stale-b), so no value is returned

void func_002a9048() {
    s32 index;
    if (func_00287bc0() == 35) {
        index = 0;
    } else {
        s32 count = *D_0035f608;
        s8 kind = *(s8*)func_00276568();
        s32 position = 0;
        if (0 < count) {
            s8* entry = (s8*)D_0035f608;
            do {
                if (kind == entry[4] && entry[5] < 0) {
                    break;
                }
                position++;
                entry += 4;
            } while (position < count);
        }
        index = position;
        if (func_0028afa8(D_0035f200) <= index) {
            index = func_0028afa8(D_0035f200) - 1;
        }
    }
    func_0028afd0((Item*)D_0035f200, index);
}
