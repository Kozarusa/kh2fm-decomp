#include "../common/types.h"
// why: global block pointer, held as a word as in func_00285910; the flag words are read through it
extern "C" u32 D_0035f2e4;
// why: declaration copied from fm_primary_orchek_recovered_002865d0.cpp; extern "C" because the isolated probe linker script defines only the plain symbol
extern "C" s32 func_002859a0(void);

// why: every exit returns a flag computed here (found, result, or constant 1), so the return is typed s32

s32 func_002864f8(s32 index) {
    s32 sram = func_002859a0();
    // why: declared before the branch because the original loads the constant 1 into v0 before bltz (moving it into the else branch was tried in v1 and is not exact)
    s32 result = 1;
    if (index >= 0) {
        u32 offset = ((u32) index >> 5) * 4;
        u32 mask = 1 << (index & 0x1f);
        s32 found = 0;
        if ((*(u32*)(D_0035f2e4 + offset + 200) & mask) != 0) {
            found = (*(u32*)(sram + offset + 204) & mask) != 0;
        }
        return found;
    } else {
        // why: the two word-array bases are held as integers; with u32* pointers (v1) the indexed loads are reordered and not exact
        u32 bits = sram + 204;
        u32 flags = D_0035f2e4 + 200;
        s32 count = 0;
        do {
            u32 offset = ((u32) count >> 5) * 4;
            u32 mask = 1 << (count & 0x1f);
            if ((*(u32*)(offset + flags) & mask) != 0) {
                result = (*(u32*)(offset + bits) & mask) != 0;
                if (result == 0) {
                    break;
                }
            }
            count++;
        } while (count < 9);
    }
    return result;
}
