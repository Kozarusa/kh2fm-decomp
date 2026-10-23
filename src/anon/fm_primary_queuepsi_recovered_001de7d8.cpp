#include "../common/types.h"
extern "C" u32 D_01d9e348[];
extern "C" u32 D_01d9e340;
extern "C" void func_001dcdb8(void);
extern "C" void func_001de808(void);

void func_001de7d8(u32 value)
{
 D_01d9e340=value;
 func_001dcdb8();
 register u32* cursor asm("$14")=D_01d9e348;
 asm("" : "+r"(cursor) : "m"(D_01d9e348[0]));
 D_01d9e348[0]=0;
 cursor[1]=0;
 func_001de808();
}
