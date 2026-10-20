#include "../common/types.h"
typedef void (*Callback)(u32);

void func_00173270(u32* owner)
{
 register u32 object asm("$4")=*owner;
 register u32 table asm("$14")=*(u32*)object;
 register Callback callback asm("$15")=*(Callback*)(table+32);
 callback(object);
}
