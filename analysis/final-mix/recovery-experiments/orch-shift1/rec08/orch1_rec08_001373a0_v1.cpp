#include "../common/types.h"

extern "C" u8 D_00347d54;
extern "C" u8 D_00347d55;
extern "C" u8 D_00347d56;
extern "C" void func_002ba848(s32);
extern "C" void func_00136a18();

void func_001373a0() {
    D_00347d55 = 0;
    D_00347d56 = D_00347d54;
    D_00347d54 = 0;
    func_002ba848(960);
    func_00136a18();
}