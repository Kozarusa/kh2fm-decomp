#include "../common/types.h"
extern "C" const void* D_0036cee4[7];

// Preserve original registry aliases.
void func_00194468(u8* object) asm("_Z16wtarget_00194468jjjj");

void func_00194468(u8* object) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036cee4
    static const void* targets[7] asm("fm_switch_table_00194468") = {
        &&set_flag, &&low_modes, &&low_modes, &&low_modes, &&high_modes, &&high_modes, &&high_modes};
    u32 mode = object[0x9ac];
    asm("" : "+r"(mode)); // why: original re-masks the loaded byte at each use
    u32 index = mode & 0xff;
    if (index >= 7) goto done;
    goto *D_0036cee4[index];
set_flag:
    *(u32*)(object + 0x10c) |= 0x200;
    return;
low_modes:
    switch ((s32)(u8)mode - 1) {
    case 0:
        *(u32*)(object + 0x768) &= ~0x200;
        *(u32*)(object + 0x768) &= ~0x400;
        break;
    case 1:
        *(u32*)(object + 0x768) |= 0x200;
        *(u32*)(object + 0x768) &= ~0x400;
        break;
    case 2:
        *(u32*)(object + 0x768) &= ~0x200;
        *(u32*)(object + 0x768) |= 0x400;
        break;
    }
    *(u32*)(object + 0x10c) &= ~0x200;
    return;
high_modes:
    switch ((s32)(u8)mode - 4) {
    case 0:
        *(u32*)(object + 0x768) &= ~0x200;
        *(u32*)(object + 0x768) &= ~0x400;
        break;
    case 1:
        *(u32*)(object + 0x768) |= 0x200;
        *(u32*)(object + 0x768) &= ~0x400;
        break;
    case 2:
        *(u32*)(object + 0x768) &= ~0x200;
        *(u32*)(object + 0x768) |= 0x400;
        break;
    }
    *(u32*)(object + 0x10c) |= 0x200;
done:
    return;
}
