#include "../common/types.h"
extern "C" u32 func_00316d08(void);

s32 func_00305ce0(void)
{
 register s32* pointer asm("$2")=(s32*)func_00316d08(); // why: accepted sibling 00305e48 retains callee result in v0 through store
 register s32 value asm("$3") = 5; // why: C constant replaces forbidden emitted addiu asm while preserving original v1 allocation
 *(u32*)pointer=value;
 return -1;
}
