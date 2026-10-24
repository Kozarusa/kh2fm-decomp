#include "../common/types.h"
typedef struct LocalState {
    u32 words[16];
} LocalState;
extern "C" u32 D_0034d8a4;
extern "C" u32 D_0034d8a0;
extern "C" void func_0016c8f8(u32, u32, u32, u32);
extern "C" void func_001da458(u32, s32, u32, u32);
extern "C" u32 func_0016cd48(u32, u32);
extern "C" u32 func_0016cab8(u32);

u32 func_0016cc18(u32* object, s32 count, u32 first, u32 second, u32 other) {
    LocalState state;
    func_0016c8f8((u32)&state, object[0], object[13], object[14]);
    u32 saved_high = D_0034d8a4;
    u32 saved_low = D_0034d8a0;
    state.words[7] |= 1;
    if (count > 0) {
        func_001da458((u32)&state, count, first, second);
        register u32 target asm("$5") = other; // why: original selects other directly into a1 at the call
        if (other == 0) {
            target = (u32)object;
        }
        func_0016cd48((u32)&state, target);
    }
    D_0034d8a4 = saved_high;
    D_0034d8a0 = saved_low;
    return func_0016cab8((u32)&state);
}
