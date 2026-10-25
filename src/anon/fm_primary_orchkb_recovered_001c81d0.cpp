#include "../common/types.h"
extern "C" u8 D_00351e18[];
extern "C" u8 D_00345c08[];
extern "C" u8 D_0034ebc8[];
extern "C" u32 D_01d49960[];
extern "C" u32 D_01d49968;
extern "C" void func_00320fa8(u32*);
extern "C" u32 func_00105110(...);

u32 func_001c81d0(u32* object) {
    object[0] = (u32)D_00351e18;
    u32* entry = D_01d49960;
    // why: original keeps the live-entry count in t4 (register 12)
    register s32 count asm("$12") = 0;
    // why: original keeps the loop index in t5 (register 13)
    register s32 index asm("$13");
    for (index = 1; index >= 0; index--) {
        // why: original loads each table entry into t7 (register 15)
        register u32 value asm("$15") = *entry;
        if (value != 0) {
            if (value == (u32)object) {
                *entry = 0;
            } else {
                count++;
            }
        }
        entry++;
    }
    if (count == 0) {
        D_01d49968 = 0;
    }
    object[0] = (u32)D_00345c08;
    if ((s32)object != -3184) {
        // why: original keeps the loop cursor in t7 (register 15), as accepted 001a4060
        register u32* cursor asm("$15") = object + 0x334;
        // why: original keeps the loop end in t6 (register 14), as accepted 001a4060
        register u32* end asm("$14") = object + 0x31c;
        while (1) {
            if (end == cursor) {
                cursor = cursor - 4;
                break;
            }
            cursor = cursor - 4;
        }
    }
    object[0] = (u32)D_0034ebc8;
    func_00320fa8(object);
    return func_00105110(object);
}
