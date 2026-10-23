#include "../common/types.h"
extern "C" u8 D_01c6cae0[];
extern "C" s32 D_01c6cafc;
extern "C" void func_001de450(void*);
extern "C" u32 func_001dde40(void*);
extern "C" u32 func_00170950(...);

// Preserve original registry aliases.
void func_001a3b08() asm("_ZN2YS6EFFECT6EnsureEv");

void func_001a3b08() {
    func_001de450(D_01c6cae0);
    func_001dde40(D_01c6cae0);
    func_00170950(D_01c6cafc);
}
