#include "../common/types.h"
extern "C" u32 D_003617e4;
extern "C" u32 D_003617e0;
extern "C" u8 D_003617e8;
extern "C" u32 func_002b823c(void);

void func_002bd538(void)
{
    D_003617e4 = 0;
    D_003617e0 = func_002b823c();
    D_003617e8 = 1;
}
