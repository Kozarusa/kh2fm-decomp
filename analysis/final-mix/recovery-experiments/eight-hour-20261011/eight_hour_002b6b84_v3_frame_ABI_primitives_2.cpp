#include "../common/types.h"
extern "C" u64 func_002b6708(s32,s32,...);
u64 func_002b6b84(u32 input)
{
 u8 argumentArea[16];
 asm volatile("" : "=m"(argumentArea));
 register void* frame asm("$30");
 asm volatile("daddu %0,$29,$0" : "=r"(frame));
 volatile u32* payload=(volatile u32*)frame;
 payload[0]=input;
 register u64 result asm("$15")=func_002b6708(2,8,payload[0]);
 asm("" : "+r"(result));
 register u64 returned asm("$2")=result;
 asm("" : "+r"(returned));
 asm volatile ("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)),"r"(returned));
 return returned;
}
