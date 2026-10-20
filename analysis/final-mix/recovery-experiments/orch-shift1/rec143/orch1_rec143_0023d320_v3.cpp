#include "../common/types.h"
extern "C" void func_0014ce20(u32);
extern "C" void func_0014ce30(u32);
extern "C" u8 D_00349e20;
extern "C" u32 D_00349e1c;
extern "C" volatile u8 D_0035eb50;
extern "C" volatile u32 D_0035eb54;
void func_0023d320() {
    u32 flag=D_00349e20==0;
    D_0035eb54=D_00349e1c;
    D_0035eb50=flag;
    if(flag) func_0014ce20(1);
    func_0014ce30(0);
}

