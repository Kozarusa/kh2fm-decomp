#include "../common/types.h"
// why: no accepted call site or definition carries a type; the one word argument is read from a0 and the
// original has no jr ra (it ends in a jal to never-returning code), so it is declared noreturn; extern "C"
// because the callee has no recovered C++ definition to mangle against.
extern "C" void func_00315418(u32) __attribute__((noreturn));
// why: no accepted declaration; a0 is the only argument read. Declared void because this function discards
// its result (the tail call carries no return value here under ruling #36, see the report).
extern "C" void func_00316658(void*);

// why: void under ruling #36: the single tail exit into func_00316658 reaches stale-a (callback result
// crossed by the later tail calls), entry (no callback) and direct integer results of the final callees;
// no float is left in $f0 anywhere in the chain.

void func_003154a8(s32 mode, u8* context) {
    u8* base = context - 48;
    if (mode != 1) {
        func_00315418(*(u32*)(base + 12));
    }
    void (*callback)(void*) = *(void (**)(void*))(base + 4);
    if (callback != 0) {
        callback(context + 32);
    }
    func_00316658(context + 32);
}
