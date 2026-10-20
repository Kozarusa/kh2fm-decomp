#include "../common/types.h"
extern "C" u32 D_0033cafc,D_0033caf4;
extern "C" u32 D_0033caf0;
extern "C" u32 D_0033cb00;
void func_00105af8(s64 mode)
{
 u32 low;asm("" : "=r"(low) : "0"(mode));
 u32* table=&D_0033cb00;
 D_0033cafc=low;
 D_0033caf0=table[(s32)low-1];
 u32 selected;
 if(mode==3) selected=table[1];
 else {selected=*(volatile u32*)&D_0033cb00;if(mode!=8) selected=D_0033caf0;}
 D_0033caf4=selected;
}
