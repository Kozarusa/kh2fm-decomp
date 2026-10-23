#include "../common/types.h"
extern "C" u64 func_002b6708(s32,s32,...);

// Preserve original registry aliases.
u64 func_002b70b8(u32 input0,u32 input1,u32 input2) asm("_Z16wtarget_002b70b8jjjj");

u64 func_002b70b8(u32 input0,u32 input1,u32 input2)
{
 u8 argumentArea[16];
 asm volatile("":"=m"(argumentArea));
 register void* frame asm("$30");
 asm volatile("daddu %0,$29,$0":"=r"(frame));
 volatile u32* payload=(volatile u32*)frame;
 payload[0]=input0;
 payload[1]=input1;
 payload[2]=input2;
 register s32 count asm("$4");
 asm("addiu %0,$0,4":"=r"(count):"m"(payload[2]));
 register s32 operation asm("$5");
 asm volatile("addiu %0,$0,17":"=r"(operation):"r"(count));
 register u64 result asm("$15")=func_002b6708(count,operation,payload[0],payload[1],payload[2]);
 asm("":"+r"(result));
 register u64 returned asm("$2")=result;
 asm("":"+r"(returned));
 asm("daddu $29,%0,$0"::"r"(__builtin_frame_address(0)),"r"(returned));
 return returned;
}
