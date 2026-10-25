#include "../common/types.h"
extern "C" u32 func_00102c80(void);
extern "C" u32 func_00104190(void);
extern "C" s32 func_00102180(void*);
extern "C" u32 func_001e02f8(u32);
extern "C" u32 func_001de8a8(u64,u64,u64,u64);

// why: void per DEVIATIONS #36: the skip exit leaves func_00102180's count in v0 (direct); both call exits end in func_001de8a8, whose accepted definition (fm_primary_orchcz_recovered_001de8a8.cpp) is void (stale-b); its result is discarded here

void func_001de808(void) {
    // why: directives emit nothing and keep gas from moving the s2 save into the first jal delay slot (as accepted 001e75a8); the ra clobber (ra is saved anyway) keeps the scheduler's normal ra-first prologue order
    asm volatile(".set noreorder; .set reorder" ::: "$31");
    u32 fieldMode = func_00102c80();
    u32 battleMode = func_00104190();
    u32 list[4];
    func_00102180(list);
    u32 entry = list[0];
    if (entry == fieldMode) {
        func_001e02f8(1);
        func_001de8a8(*(s32*)(entry + 4), 9, 20300, 92000);
    } else if (entry == battleMode) {
        func_001e02f8(2);
        func_001de8a8(*(s32*)(battleMode + 4), 1, 31000, 72000);
    }
}
