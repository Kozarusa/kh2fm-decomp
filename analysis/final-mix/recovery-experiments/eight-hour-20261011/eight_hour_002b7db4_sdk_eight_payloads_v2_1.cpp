#include "../common/types.h"
extern "C" u64 func_002b6708(s32,s32,...);
u64 func_002b7db4(u32 input0,u32 input1,u32 input2,u32 input3,u32 input4,u32 input5,u32 input6,u32 input7)
{
 u8 argumentArea[48];
 asm volatile("":"=m"(argumentArea));
 register void* frame asm("$30");
 asm volatile("daddu %0,$29,$0":"=r"(frame));
 volatile u32* payload=(volatile u32*)((u8*)frame+16);
 payload[0]=input0;
 payload[1]=input1;
 payload[2]=input2;
 payload[3]=input3;
 payload[4]=input4;
 payload[5]=input5;
 payload[6]=input6;
 payload[7]=input7;
 // Final two variadic words travel through the native outgoing stack slots.
 volatile u32* outgoing=(volatile u32*)frame;
 register u32 stackWord asm("$15")=payload[6];
 asm("sw %2,0($29)":"=m"(outgoing[0]):"r"(frame),"r"(stackWord));
 stackWord=payload[7];
 asm("sw %2,8($29)":"=m"(outgoing[2]):"r"(frame),"r"(stackWord));
 register s32 count asm("$4");
 asm("addiu %0,$0,9":"=r"(count):"m"(outgoing[0]),"m"(outgoing[2]));
 register s32 operation asm("$5");
 asm volatile("addiu %0,$0,43":"=r"(operation):"r"(count));
 register u64 result asm("$15")=func_002b6708(count,operation,payload[0],payload[1],payload[2],payload[3],payload[4],payload[5]);
 asm("":"+r"(result));
 register u64 returned asm("$2")=result;
 asm("":"+r"(returned));
 asm("daddu $29,%0,$0"::"r"(__builtin_frame_address(0)),"r"(returned));
 return returned;
}
