#include "../common/types.h"
// why: no recovered call site defines this; a0 carries the layout handle and the result is dereferenced at +0x28
extern "C" u8* func_0023f1b0(s32 layout);
extern "C" u32 func_0023c4b8(u32, s32);
extern "C" s32 func_00236ca8(s32,s32);
extern "C" u32 func_00192048(u64);
// why: no recovered definition; seven word arguments a0..t2 are set before the jal and its tail into a store-only callee leaves no result
extern "C" void func_00138d60(u8* object, s32 kind, u32 unit, s32 image, s32 style, u32 message, s32 extra);

// Preserve original registry aliases.
void func_0028d980(u8* object, s32 kind, s32 sequence, s32 imageId, s32 layout, s32 style, s32 mode, s32 messageId, s32 extra) asm("_ZN2Tz10MenuCursor6CreateEz");

void func_0028d980(u8* object, s32 kind, s32 sequence, s32 imageId, s32 layout, s32 style, s32 mode, s32 messageId, s32 extra) {
    u32 unit = func_0023c4b8((u32)func_0023f1b0(layout), sequence);
    s32 image = func_00236ca8(*(s32*)(func_0023f1b0(layout) + 0x28), imageId);
    u32 message = 0;
    if (messageId >= 0) {
        message = func_00192048(messageId);
    }
    func_00138d60(object, kind, unit, image, style, message, extra);
    *(s32*)(object + 0x188) = mode;
    *(s32*)(object + 0x1ac) = 1;
}
