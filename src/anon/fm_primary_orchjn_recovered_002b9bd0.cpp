#include "../common/types.h"

extern "C" void func_002b691c(u32);
extern "C" void func_002bbde0();
extern "C" void func_002bacc0();
extern "C" void func_002b9ad0();
extern "C" void func_002b9c80();
extern "C" void func_002bd538();
extern "C" u32 func_00102788(s32,s32,s32,u8*);
extern "C" s32 D_0032b91c;
extern "C" u8 D_002b9c60[];

// Preserve original registry aliases.
u32 func_002b9bd0() asm("_Z16wtarget_002b9bd0jjjj");

u32 func_002b9bd0()
{
    func_002b691c(0);
    func_002bbde0();
    func_002bacc0();
    func_002b9ad0();
    func_002b9c80();
    func_002bd538();
    return func_00102788(D_0032b91c, 0, 0x7a12a, D_002b9c60);
}
