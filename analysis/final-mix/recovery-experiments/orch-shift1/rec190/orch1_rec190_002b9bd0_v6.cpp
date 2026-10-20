#include "../common/types.h"

extern "C" void func_002b691c(u32);
extern "C" void func_002bbde0();
extern "C" void func_002bacc0();
extern "C" void func_002b9ad0();
extern "C" void func_002b9c80();
extern "C" void func_002bd538();
extern "C" u64 func_00102788(u64, u64, u64, u64);
extern "C" s32 D_0032b91c;
extern "C" u8 D_002b9c60[];

u64 func_002b9bd0()
{
    func_002b691c(0);
    func_002bbde0();
    func_002bacc0();
    func_002b9ad0();
    func_002b9c80();
    func_002bd538();
    // why: original begins the third argument before the fourth
    register u64 third asm("$6") = 0x7a12a;
    asm volatile("" : "+r"(third));
    // why: original transports the fourth argument in a3
    register u64 fourth asm("$7") = (s32)D_002b9c60;
    asm("" : "+r"(fourth));
    // why: original transports zero in a1
    register u64 second asm("$5") = 0;
    asm("" : "+r"(second));
    return func_00102788(D_0032b91c, second, third, fourth);
}
