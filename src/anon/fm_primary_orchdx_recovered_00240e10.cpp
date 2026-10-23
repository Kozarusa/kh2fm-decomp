#include "../common/types.h"
extern "C" void func_00240360();
extern "C" void func_00234590(u64,u64,u64,u64,u64);
extern "C" s8* D_0035ec94;
extern "C" s32 D_0035ec9c;
extern "C" s32 D_0035ec88;

void func_00240e10() {
    func_00240360();
    func_00234590(*D_0035ec94, D_0035ec9c, 99, D_0035ec88, 0);
}
