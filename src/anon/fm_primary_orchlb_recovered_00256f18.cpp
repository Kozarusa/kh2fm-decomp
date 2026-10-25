#include "../common/types.h"
extern "C" void func_00288e88(...);
extern "C" u32 func_002892f8(...);
extern "C" u32 func_0028acc8(...);
extern "C" s32 D_0035f01c;
extern "C" s32 D_0035f020;
extern "C" s32 D_0035f024;

void func_00256f18(void)
{
    s32 value1;
    s32 value2;
    if (D_0035f01c != 0)
    {
        value1 = func_002892f8(D_0035f01c);
        value2 = func_0028acc8(D_0035f01c);
        if ((value2 == 0) && value1)
        {
            func_00288e88(D_0035f01c);
        }
    }
    if (D_0035f020 != 0)
    {
        value1 = func_002892f8(D_0035f020);
        value2 = func_0028acc8(D_0035f020);
        if ((value2 == 0) && value1)
        {
            func_00288e88(D_0035f020);
        }
    }
    if (D_0035f024 != 0)
    {
        value1 = func_002892f8(D_0035f024);
        value2 = func_0028acc8(D_0035f024);
        if ((value2 == 0) && value1)
        {
            func_00288e88(D_0035f024);
        }
    }
}
