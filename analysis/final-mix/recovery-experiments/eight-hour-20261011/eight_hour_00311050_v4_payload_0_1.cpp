#include "../common/types.h"
extern "C" s32 func_00305a50(s32,void*);
void func_00311050(u32 value,s8 flag)
{
 s32 payload[2]={(s32)value,(s32)flag};
 register s32 operation asm("$4");
 asm("li %0,3" : "=r"(operation) : "m"(payload));
 func_00305a50(operation,&payload);
}
