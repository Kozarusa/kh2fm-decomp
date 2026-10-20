#include "../common/types.h"
extern "C" u64 func_002b6708(s32,s32,...);
u64 func_002b7f84()
{
 register void* frame asm("$30");
 asm volatile("daddu %0,$29,$0" : "=r"(frame));
 register s32 count asm("$4");
 asm("addiu %0,$0,1" : "=r"(count) : "r"(frame));
 register u64 result asm("$15")=func_002b6708(count,49);
 asm("" : "+r"(result));
 register u64 returned asm("$2")=result;
 asm("" : "+r"(returned));
 asm volatile ("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)),"r"(returned));
 return returned;
}
