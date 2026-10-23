#include "../common/types.h"
extern "C" u8 D_0036b600[];
extern "C" u32 func_002ff2e8(u8*, u8*);
extern "C" void func_002feee8(u8*, u8*);
extern "C" s32 func_002ff3fc(u8*);
extern "C" s8 func_002ffbe0(s32);
extern "C" s32 func_0030e770(u8*, u32, u32);

// Preserve original registry aliases.
s32 func_00167358(u8* name, u32 mode, u32 flags) asm("_Z16wtarget_00167358jjjj");

s32 func_00167358(u8* name, u32 mode, u32 flags) {
    s8 buffer[256];
    u8* base = D_0036b600;
    func_002ff2e8((u8*)buffer, base);
    func_002feee8((u8*)buffer, name);
    // why: original keeps the index in s0, which first held the base address
    register s32 index asm("$16") = func_002ff3fc(base);
    s32 length = func_002ff3fc((u8*)buffer);
    for (; index < length; index++) {
        if (buffer[index] == '/') {
            buffer[index] = '\\';
        } else {
            buffer[index] = func_002ffbe0(buffer[index]);
        }
    }
    s32 result;
    do {
        result = func_0030e770((u8*)buffer, mode, flags);
    } while (result < 0);
    return result;
}
