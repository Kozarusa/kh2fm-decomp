#include "../common/types.h"
extern "C" s32 D_0035f620;
extern "C" s32 D_0035f628;
extern "C" s32 D_0035f62c;
extern "C" u32 func_00294000(u32);
extern "C" s32 func_002a99c8(void*);

// why: every exit leaves a direct callee v0 (00294000 when the count is not positive, else the last 002a99c8), so the last-computed value is returned

u32 func_002ad6e8(void) {
    u32 index = 0;
    u32 object = func_00294000(8);
    u32 result = object;
    D_0035f628 += *(s32*)(object + 8);
    u8* entries = (u8*)(object + 16);
    if (*(s32*)(object + 8) > 0) {
        u8* cursor = entries;
        // why: original keeps the loop copy of the object pointer in s5 (move s5,v0)
        register u32 header asm("$21") = object;
        asm("" : "+r"(header)); // why: original copies the object pointer into its loop register only inside the count test (move s5,v0)
        do {
            s32 state = func_002a99c8(cursor);
            u32 word = index >> 5;
            u32 shift = index & 0x1f;
            result = state;
            index++;
            if (state == 2) {
                u32* flags = (u32*)(D_0035f620 + 0x94 + word * 4);
                *flags |= 1 << shift;
                D_0035f62c++;
            }
            cursor += 16;
        } while ((s32)index < *(s32*)(header + 8));
    }
    return result;
}
