#include "../common/types.h"
typedef u64 (*VirtualWordCall)(u32*,u64,u64,bool);
void func_00172ae0(u32*record){u32*object=(u32*)(*(u32*)(record[0]+4));VirtualWordCall callback=((VirtualWordCall*)object[0])[30];record[0]=callback(object,record[1],record[2],record[3]!=0);}
