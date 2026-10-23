#include "../common/types.h"
extern "C" u64 func_002b6708(s32,s32,...);
// Native frame setup and restoration are retained as ABI primitives.

u64 func_002b9a78(u32 input)
{
 u8 argumentArea[16];
 asm volatile("" : "=m"(argumentArea));
 register void* frame asm("$30");
 asm volatile("daddu %0,$29,$0" : "=r"(frame));
 volatile u32* payload=(volatile u32*)frame;
 payload[0]=input;
 register s32 count asm("$4");
 asm("addiu %0,$0,2" : "=r"(count) : "m"(payload[0]));
 register s32 operation asm("$5");
 asm volatile("addiu %0,$0,54" : "=r"(operation) : "r"(count));
 register u64 result asm("$15")=func_002b6708(count,operation,payload[0]);
 asm("" : "+r"(result));
 register u64 returned asm("$2")=result;
 asm("" : "+r"(returned));
 asm ("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)),"r"(returned));
 return returned;
}
