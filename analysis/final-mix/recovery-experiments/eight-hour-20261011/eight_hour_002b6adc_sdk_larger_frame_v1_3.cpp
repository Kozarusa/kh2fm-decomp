#include "../common/types.h"
extern "C" u64 func_002b6708(s32,s32,...);
u64 func_002b6adc(u32 input0,u32 input1)
{
 u8 argumentArea[16];
 asm volatile("":"=m"(argumentArea));
 register void* frame asm("$30");
 asm volatile("daddu %0,$29,$0":"=r"(frame));
 volatile u32* payload=(volatile u32*)frame;
 payload[0]=input0;
 payload[1]=input1;
 register s32 count asm("$4");
 asm("addiu %0,$0,3":"=r"(count):"m"(payload[1]));
 register s32 operation asm("$5");
 asm volatile("addiu %0,$0,6":"=r"(operation):"r"(count));
 register u32 argument0 asm("$6")=payload[1];
 asm("":"+r"(argument0):"r"(operation));
 register u32 argument1 asm("$7")=payload[0];
 asm("":"+r"(argument1):"r"(argument0));
 register u64 result asm("$15")=func_002b6708(count,operation,argument0,argument1);
 asm("":"+r"(result));
 register u64 returned asm("$2")=result;
 asm("":"+r"(returned));
 asm("daddu $29,%0,$0"::"r"(__builtin_frame_address(0)),"r"(returned));
 return returned;
}
