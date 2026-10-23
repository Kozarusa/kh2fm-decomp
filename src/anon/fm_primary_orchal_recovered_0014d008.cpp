#include "../common/types.h"
extern "C" s32 D_0032b91c;
extern "C" u8 D_0014cf18[];
extern "C" u8 D_0014cf88[];
extern "C" void func_0014cfc8();
extern "C" void func_0014c908();
extern "C" void func_002f33f0(u8*);
extern "C" void func_0014d308();
extern "C" u32 func_00102788(s32,s32,s32,u8*);

// Preserve original registry aliases.
void func_0014d008() asm("_Z16u_tail0_0014d008v");

void func_0014d008() {
    func_0014cfc8();
    func_0014c908();
    func_002f33f0(D_0014cf18);
    func_0014d308();
    func_00102788(D_0032b91c, 0, 800000, D_0014cf88);
}
