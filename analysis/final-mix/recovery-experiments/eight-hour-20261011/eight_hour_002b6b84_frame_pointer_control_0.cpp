#include "../common/types.h"
extern "C" u64 func_002b6708(s32,s32,...);
u64 func_002b6b84(u32 input)
{
 volatile u32 payload=input;
 void* frame=__builtin_frame_address(0);
 register u64 result asm("$15")=func_002b6708(2,8,payload);
 asm("" : "+r"(result));
 asm volatile("" : : "r"(frame));
 return result;
}
