#include "../common/types.h"
extern "C" u32 func_00167f18(...);
// why: no recovered caller; a0 is the stack object the function fills, a1 the GetInputState result
extern "C" void func_00323af8(void*, u32);
// why: accepted definition is u32 Tz::MenuBase::isSavePad(); the probe linker script defines only the plain symbol
extern "C" u32 func_00288040();
// why: no recovered caller; its v0 is dereferenced with ld, so it returns a pointer to a 64-bit pad word
extern "C" u64* func_00288008();

struct PadSlot {
    u8 bytes[16];
    // why: user-declared empty destructor; the original keeps the compiler-generated array destructor loop (null test plus empty loop)
    ~PadSlot() {}
};

struct PadState {
    u64 state[4];
    PadSlot slots[2];
    // why: the original frame reserves 80 bytes below the saved registers for this object (s0 saved at sp+80)
    u8 rest[16];
};

s32 func_0028b258(u32 mask) {
    PadState pad;
    func_00323af8(&pad, func_00167f18(0));
    if (func_00288040() != 0) {
        pad.state[0] |= *func_00288008();
    }
    return (pad.state[0] & (u64)mask) != 0;
}
