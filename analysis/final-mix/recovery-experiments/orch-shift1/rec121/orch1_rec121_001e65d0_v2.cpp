#include "../common/types.h"
extern "C" u32 D_00354648;
extern "C" u32 D_003591c8;
extern "C" u8 D_00354650[];
extern "C" u8 D_00354698[];
extern "C" void func_001e5990(u8*);
extern "C" void func_001e5610(u32);
extern "C" void func_001e5898(u32);
extern "C" void func_002f25a0(u32, u32);
extern "C" void func_002f3918(u32, u32);
extern "C" void func_003058a0(u32);

void func_001e65d0() {
    func_001e5990(D_00354698);
    func_001e5610(D_00354648);
    func_001e5898(D_00354648);
    func_002f25a0(0, 0);
    func_003058a0(0);
    func_002f3918(D_003591c8, (u32)D_00354650);
}