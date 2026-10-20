#include "../common/types.h"
extern "C" u32 D_0035f6cc;
extern "C" s32 func_00240ba0();
extern "C" void func_002b4dd0(s32);
extern "C" void func_002b5108(s32,s32);
extern "C" void func_0028f4d8(u32,u16,u32);
extern "C" void func_00287d20(s32);
extern "C" u32 func_00234570(s32,void*);
u32 func_002b4c10() {
    s32 slot = func_00240ba0();
    func_002b4dd0(-1);
    func_002b5108(0x8a89, slot);
    func_0028f4d8(1, *(u16*)(((u32)slot * 36 + *(u32*)D_0035f6cc) + 18), 0);
    func_00287d20(0);
    return func_00234570(slot, 0);
}
