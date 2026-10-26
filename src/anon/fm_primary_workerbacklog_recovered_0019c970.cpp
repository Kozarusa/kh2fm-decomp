#include "../common/types.h"
extern "C" u32 D_00350444;
extern "C" void func_0019cc20(void);

void func_0019c970(u32 value)
{
    func_0019cc20();
    if (D_00350444 == value) {
        D_00350444 = 0;
    }
}
