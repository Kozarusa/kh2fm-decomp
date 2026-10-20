#include "../common/types.h"
extern "C" s32 D_0034d780;
extern "C" s32 D_004f5258[];
extern "C" void func_00167f38(s32);

void func_00168008() {
    D_0034d780 = D_0034d780 - 1;
    func_00167f38(D_004f5258[D_0034d780]);
}
