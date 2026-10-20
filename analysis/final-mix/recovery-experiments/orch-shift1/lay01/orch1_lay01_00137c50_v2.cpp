#include "../common/types.h"
extern "C" void func_001391c8(u32*,u32,u32);
void func_00137c50(u32* object)
{
 u32* fields=object;
 fields[0xa72]=0;
 fields[8]=1;
 fields[0xa70]=1;
 fields[12]=0;
 fields[13]=0;
 // why: keeps store order (the 0x29c4 store follows the group; non-volatile so the prologue is not pinned)
 asm("" : "+m"(fields[0xa72]) : "m"(fields[8]), "m"(fields[0xa70]), "m"(fields[12]), "m"(fields[13]), "m"(fields[0xa71]));
 fields[0xa71]=0;
 func_001391c8(object,0x2b5c,0);
}
