#include "../common/types.h"
extern "C" u32 func_002fdfc8(...);
extern "C" void func_001e7cc0(...);

extern "C" u8 D_0036e978[];
extern "C" u8 D_0036e998[];
extern "C" u8 D_0036e9c0[];
extern "C" u8 D_0036e9d0[];

void func_001e2c00(s32 object) {
    if (object == 0) {
        func_002fdfc8(D_0036e978, D_0036e9c0);
        u8* message = D_0036e9d0;
        asm("" : "+r"(message)); // why: materializes the second argument address before the first one like the original
        s32 line = 357;
        asm("" : "+r"(line)); // why: loads the constant into a2 before the first argument finishes, like the original
        func_002fdfc8(D_0036e998, message, line);
        __builtin_trap();
    }
    func_001e7cc0(object);
    asm volatile("" ::: "memory"); // why: stops the compiler from turning the last call into a tail call
}
