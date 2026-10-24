#include "../common/types.h"
extern "C" const void* D_0036d0ac[7];
extern "C" u8 D_0032f054;
extern "C" u8* func_001a8b28();

u16 func_00198040(s32 mode) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036d0ac
    static const void* targets[7] asm("fm_switch_table_00198040") = {
        &&slot0, &&slot1, &&slot2, &&slot3, &&slot4, &&slot5, &&slot6};
    u8* entry = func_001a8b28();
    u16 result;
    if (mode == 1) {
        u32 slot = D_0032f054;
        if (slot >= 7) goto slot0;
        goto *D_0036d0ac[slot];
    slot1:
        result = *(u16*)(entry + 40);
        goto done;
    slot0:
        result = *(u16*)(entry + 38);
        goto done;
    slot2:
        result = *(u16*)(entry + 42);
        goto done;
    slot3:
        result = *(u16*)(entry + 44);
        goto done;
    slot4:
        result = *(u16*)(entry + 46);
        goto done;
    slot5:
        result = *(u16*)(entry + 48);
        goto done;
    slot6:
        result = *(u16*)(entry + 50);
    } else {
        result = 0;
    }
done:
    return result;
}
