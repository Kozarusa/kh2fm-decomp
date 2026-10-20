#include "../common/types.h"
extern "C" u64 func_002b6708(s32,s32,...);

u64 func_002b7f84()
{
 register void* frame asm("$30");
 asm volatile("daddu %0,$29,$0" : "=r"(frame));
 register u64 result asm("$15")=func_002b6708(1,49);
 asm("" : "+r"(result));
 register u64 returned asm("$2")=result;
 asm("" : "+r"(returned));
 asm ("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)),"r"(returned));
 return returned;
}
