#include "../common/types.h"
extern "C" s32 func_002fea18(void);
// Mix the external integer seed into the hardware VU random state.

void func_0020e138(void)
{
 register s32 seed asm("$15")=func_002fea18();
 asm volatile("qmtc2 %0,$vf31; vrxor R,$vf31x" : : "r"(seed) : "memory");
}
