#include "../common/types.h"
// Complete-range register/address correction proposal.
extern "C" u32 D_00365c48; extern "C" char D_003785f8; extern "C" void func_00316d18(u32,u32); extern "C" void func_00315440(void) __attribute__((noreturn));

void func_003155c0(void) { func_00316d18((u32)&D_003785f8,*(u32*)(D_00365c48+12)); func_00315440(); }
