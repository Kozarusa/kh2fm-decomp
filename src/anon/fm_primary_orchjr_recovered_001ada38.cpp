#include "../common/types.h"
extern "C" u64 D_0032f050;
extern "C" s32 D_0034f240;
extern "C" u8 D_0032bb30[];
extern "C" const void* D_0036d7a8[13];
extern "C" s32 func_001a1658(s32, s32);
extern "C" u32 func_001a17c8(...);
extern "C" void func_001adb80(u32, u32);
extern "C" u32 func_001adbc0();
extern "C" void func_001c9770(void);

void func_001ada38(u32 kind) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036d7a8
    static const void* targets[13] asm("fm_switch_table_001ada38") = {
        &&scan, &&check, &&start, &&scan, &&enable, &&mark, &&attach, &&scan,
        &&scan, &&scan, &&finish, &&reset, &&start};
    if (kind == 0) {
        return;
    }
    if (kind >= 13) goto scan;
    goto *D_0036d7a8[kind];
check:
    if ((D_0032f050 & 0xffff00000000ULL) == 0) {
        goto scan;
    }
start:
    func_001c9770();
finish:
    func_001adbc0();
scan: {
    u32 owner = kind;
    asm("" : "+r"(owner)); // why: keeps the loop copy of kind in its own register (s2) while kind stays in s0
    for (s32 index = 1; index < 16; index++) {
        s32 entry = func_001a1658(index, -1);
        func_001adb80(owner, entry);
        func_001a17c8(entry);
    }
    }
    return;
mark:
    D_0034f240 = D_0034f240 | 0x40000;
enable:
    if ((D_0032f050 & 0xffff00000000ULL) == 0) {
        return;
    }
attach:
    func_001c9770();
    func_001adbc0();
    return;
reset:
    if (D_0032bb30[13604] != 6) {
        return;
    }
    D_0032bb30[13604] = 0;
    func_001c9770();
}
