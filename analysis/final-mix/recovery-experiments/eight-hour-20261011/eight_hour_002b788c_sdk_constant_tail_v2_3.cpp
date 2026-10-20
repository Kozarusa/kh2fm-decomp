#include "../common/types.h"
extern "C" u64 func_002b6708(s32,s32,...);
u64 func_002b788c(u32 input0,u32 input1,u32 input2,u32 input3)
{
 u8 argumentArea[16];
 asm volatile("":"=m"(argumentArea));
 register void* frame asm("$30");
 asm volatile("daddu %0,$29,$0":"=r"(frame));
 volatile u32* payload=(volatile u32*)frame;
 payload[0]=input0;
 payload[1]=input1;
 payload[2]=input2;
 payload[3]=input3;
 register s32 count asm("$4");
 asm("addiu %0,$0,7":"=r"(count):"m"(payload[3]));
 register s32 operation asm("$5");
 asm volatile("addiu %0,$0,25":"=r"(operation):"r"(count));
 register u32 argument0 asm("$6")=payload[0];
 register u32 argument1 asm("$7")=payload[1];
 register u32 argument2 asm("$8")=payload[2];
 register u32 argument3 asm("$9")=payload[3];
 register s32 firstOne asm("$10");
 asm("addiu %0,$0,1":"=r"(firstOne):"r"(argument3));
 register s32 lastOne asm("$11");
 asm("addiu %0,$0,1":"=r"(lastOne):"r"(firstOne));
 register u64 result asm("$15")=func_002b6708(count,operation,argument0,argument1,argument2,argument3,firstOne,lastOne);
 asm("":"+r"(result));
 register u64 returned asm("$2")=result;
 asm("":"+r"(returned));
 asm("daddu $29,%0,$0"::"r"(__builtin_frame_address(0)),"r"(returned));
 return returned;
}
