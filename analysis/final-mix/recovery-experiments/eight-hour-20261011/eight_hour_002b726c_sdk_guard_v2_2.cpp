#include "../common/types.h"
extern "C" u64 func_002b6708(s32,s32,...);
u64 func_002b726c(u32 input0,u32 input1,u32 input2,u32 input3,u32 input4)
{
 u8 argumentArea[32];
 asm volatile("":"=m"(argumentArea));
 register void* frame asm("$30");
 asm volatile("daddu %0,$29,$0":"=r"(frame));
 volatile u32* payload=(volatile u32*)frame;
 payload[0]=input0;
 payload[1]=input1;
 payload[2]=input2;
 payload[3]=input3;
 payload[4]=input4;
 register s32 smaller asm("$15")=(s32)payload[3]<14848;
 asm("":"+r"(smaller));
 if (!smaller) {
 register u32 replacement asm("$15")=64;
 asm("":"+r"(replacement):"r"(smaller));
 payload[4]=replacement;
 }
 register s32 count asm("$4");
 asm("addiu %0,$0,6":"=r"(count):"m"(payload[4]));
 register s32 operation asm("$5");
 asm volatile("addiu %0,$0,19":"=r"(operation):"r"(count));
 register u64 result asm("$15")=func_002b6708(count,operation,payload[0],payload[1],payload[2],payload[3],payload[4]);
 asm("":"+r"(result));
 register u64 returned asm("$2")=result;
 asm("":"+r"(returned));
 asm("daddu $29,%0,$0"::"r"(__builtin_frame_address(0)),"r"(returned));
 return returned;
}
