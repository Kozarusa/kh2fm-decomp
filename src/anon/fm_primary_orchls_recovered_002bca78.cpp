#include "../common/types.h"
// Declarations copied from accepted callers (002bcbf0, 002ba140) and the accepted definition of 002bc9d8.
extern "C" u16 func_002bc988(s32);
extern "C" u32 func_002bc9a8(void*,s32,s32);
// why: extern "C" because the probe linker script defines only the plain symbol (C++ form failed to link in v1); the full build resolves the plain name via build_elf.py aliases
extern "C" s32 func_002bc9d8(u8* object, s32 key);
// why: no recovered use; a0 is the source passed in by the caller, v0 is used as a count
extern "C" s32 func_002bc978(s32 source);
// why: no recovered use; a0 is the object, a1 the slot index computed in the loop
extern "C" void func_002bcda8(u8* object, s32 slot);
// why: no recovered use; a0 is the object, a1 the slot index computed in the loop
extern "C" void func_002bd188(u8* object, s32 slot);

s32 func_002bca78(u8* object, s32 key, s32 source, s32* slot, s32* id) {
    *id = func_002bc988(key);
    s32 found = func_002bc9d8(object, *id);
    *slot = found;
    if (found == -1) {
        *slot = *(s32*)(object + 0x148);
        func_002bc9a8(object, *slot, *id);
        s32 count = func_002bc978(source);
        for (s32 i = 0; i < count - 1; i++) {
            s32 index = *(s32*)(object + 0x148) + i + 1;
            func_002bcda8(object, index);
            func_002bd188(object, index);
        }
        *(s32*)(object + 0x148) += count;
        return 1;
    }
    return 0;
}
