#include "../common/types.h"

extern "C" u8 D_0036ef58[];
extern "C" u8 D_0036efc8[];
extern "C" u8 D_0036ef88[];
extern "C" u8 D_0036ef98[];
extern "C" u32 func_002fdfc8(...);
extern "C" void func_001e7878(void*);
extern "C" void func_001e8ac8(void*);
extern "C" void func_001e8330(void*);

void func_001e8bb8(void* object) {
    if (object == 0) {
        func_002fdfc8(D_0036ef58, D_0036efc8);
        u8* file = D_0036ef88;
        u8* message = D_0036ef98;
        func_002fdfc8(message, file, 982);
        __builtin_trap();
    }
    func_001e7878(object);
    func_001e8ac8(object);
    func_001e8330(object);
    asm volatile("" ::: "memory"); // why: stops tail call
}