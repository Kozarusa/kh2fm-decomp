#include "../common/types.h"
extern "C" u64 func_002b6708(s32,s32,...);
// Native frame setup and restoration are retained as ABI primitives.

// Preserve original registry aliases.
u64 func_002b99c8() asm("_Z13func_002b99c8Pv");

u64 func_002b99c8()
{
 register void* frame asm("$30");
 asm volatile("daddu %0,$29,$0" : "=r"(frame));
 register u64 result asm("$15")=func_002b6708(1,41);
 asm("" : "+r"(result));
 register u64 returned asm("$2")=result;
 asm("" : "+r"(returned));
 asm ("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)),"r"(returned));
 return returned;
}
