#include "../common/types.h"

extern u32 D_003677a8, D_003677ac;
extern "C" void func_00315440(void) __attribute__((noreturn));
void func_00315458(void (*callback)(void)) __attribute__((noreturn));

// Original callback wrappers call the existing nonreturning termination chain.
void func_00315458(void (*callback)(void)) {
    callback();
    func_00315440();
}
void func_00315470(void) {
    func_00315458((void (*)(void))D_003677ac);
}
u32 func_00315488(u32 callback) {
    u32 previous = D_003677a8;
    D_003677a8 = callback;
    return previous;
}
