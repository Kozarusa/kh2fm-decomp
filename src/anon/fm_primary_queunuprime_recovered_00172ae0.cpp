#include "../common/types.h"
typedef u32 (*VirtualWordCall)(u32*,u32,u32,bool);

// Preserve original registry aliases.
void func_00172ae0(u32*record) asm("_ZN2YS15trap_obj_add_hpEP8BD_VALUE");

void func_00172ae0(u32*record){u32*object=(u32*)(*(u32*)(record[0]+4));VirtualWordCall callback=((VirtualWordCall*)object[0])[30];record[0]=callback(object,record[1],record[2],record[3]!=0);}
