#include "../common/types.h"
extern "C" u32 D_0033cafc,D_0033caf0,D_0033caf4;
extern "C" u32 D_0033cb00;
void func_00105af8(s64 mode)
{
 register u32* table asm("$12")=&D_0033cb00;
 asm("" : "+r"(table));
 D_0033cafc=(u32)mode;
 D_0033caf0=table[(s32)mode-1];
 if(mode==3) D_0033caf4=table[1];
 else if(mode==8) D_0033caf4=table[0];
 else D_0033caf4=D_0033caf0;
}
