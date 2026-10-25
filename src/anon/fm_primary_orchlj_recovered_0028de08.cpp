#include "../common/types.h"
// why: format string "?" (bytes 3f 00 at 0x374470), the placeholder glyph repeated by this function
extern "C" const s8 D_00374470[];
extern "C" u32 func_00105c30(void);
extern "C" u32 func_00192048(u32);
// why: no recovered source calls this; a0 is the func_00192048 result and its v0 is used as the repeat count
extern "C" s32 func_00192a80(u32 message);
// why: copied from the recovered definition fm_primary_orchjq_recovered_00192cc0.cpp
extern "C" s8* func_00192cc0(s8* buffer, const s8* format, ...);
extern "C" s32 func_00192b30(s8*);
extern "C" void func_002fdd68(u8* dst, u8* src, s32 count);

u8* func_0028de08(u32 id, u8* output) {
    s32 count;
    // why: a 64-bit index compared and stepped through its low word lets the original share s0 between the
    // region flag and the index; an s32 index (pfix9 v3) moves both and differs by 36 words
    u64 index;
    // why: 32-byte stack buffer at sp+0 in the original 96-byte frame
    s8 buffer[32];
    u8* cursor;
    count = func_00192a80(func_00192048(id));
    s32 size;
    // why: the original keeps the region test as a flag (li s0,1 then movz on it); testing the condition
    // directly (pfix9 v4) loses the flag and differs by 53 words
    bool wide = false;
    index = 0;
    cursor = output;
    // why: the original calls the region getter twice (region 1 or 8 keeps the message count)
    if (1 == func_00105c30() || 8 == func_00105c30()) {
        wide = true;
    }
    if (!wide) {
        count = 5;
    }
    // why: func_00192cc0 formats "?" with no further arguments
    size = func_00192b30(func_00192cc0(buffer, D_00374470));
    while ((s32) index < count) {
        index = (u32) index + 1;
        // why: the last copy also takes the terminating zero byte
        if (!((s32) index < count)) {
            size = size + 1;
        }
        func_002fdd68(cursor, (u8*) buffer, size); // why: byte copy of the formatted text
        cursor = cursor + size;
    }
    return output;
}
