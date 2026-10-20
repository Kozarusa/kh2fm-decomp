#include "../common/types.h"
u32 func_0016f770(u64 value)
{
 register s32 shifted asm("$2")=(s32)value>>29;
 asm("" : "+r"(shifted));
 if(value>792 && (value<795 || value==1006))return 1;
 return shifted&1;
}
