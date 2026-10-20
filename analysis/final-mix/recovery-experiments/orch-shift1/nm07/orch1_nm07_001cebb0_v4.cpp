#include "../common/types.h"
extern "C" u32 D_003521d0;
extern "C" u8 D_001cec08;
extern "C" u8 D_001cec28[];
extern "C" u32 func_001050d8(u64);
extern "C" void func_001ce8b8(u32);
extern "C" u8* func_00102c18(u32, u32, u8*);

void func_001cebb0() {
    u32 object = func_001050d8(60);
    func_001ce8b8(object);
    D_003521d0 = object;
    u32 kind = 1;
    asm("" : "+r"(kind)); // why: materializes the first argument before the callback address low half
    u8* task = func_00102c18(kind, 14001, &D_001cec08);
    *(u8**)(task + 0x30) = D_001cec28;
}