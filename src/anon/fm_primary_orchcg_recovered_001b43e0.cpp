#include "../common/types.h"
extern "C" u32 D_01d48cb0;
extern "C" void func_001b5460(u32);
extern "C" void func_001b4f40(u32);
extern "C" void func_00105110(u32);

void func_001b43e0() {
    if (D_01d48cb0 != 0) {
        func_001b5460(D_01d48cb0);
        u32 object = D_01d48cb0;
        if (object != 0) {
            func_001b4f40(object);
            func_00105110(object);
            // why: prevents tail call, original uses jal and shared epilogue
            asm volatile("" ::: "memory");
        }
    }
}
