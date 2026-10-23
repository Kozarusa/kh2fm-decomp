#include "../common/types.h"
extern "C" u32 D_01d9e348[];
extern "C" void func_001de690(s32);
extern "C" void func_001dced0(void);

void func_001de910(void)
{
 func_001de690(0);
 register u32* cursor asm("$14")=D_01d9e348;
 asm("" : "+r"(cursor) : "m"(D_01d9e348[0]));
 D_01d9e348[0]=0;
 cursor[1]=0;
 func_001dced0();
}
