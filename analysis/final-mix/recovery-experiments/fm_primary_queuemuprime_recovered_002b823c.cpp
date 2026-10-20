#include "../common/types.h"
extern "C" u64 func_002b6708(s32,s32,...);
extern "C" u32 D_00378adc;

u64 func_002b823c()
{
 register void* frame asm("$30");
 asm volatile("daddu %0,$29,$0" : "=r"(frame));
 func_002b6708(1,33);
 register u64 result asm("$15");
 register const u8* globalBase asm("$28");
 asm("":"=r"(globalBase));
 asm volatile("lw %0,-7460(%1)":"=r"(result):"r"(globalBase),"m"(*(const u32*)(globalBase-7460)));
 asm("" : "+r"(result));
 register u64 returned asm("$2")=result;
 asm("" : "+r"(returned));
 asm ("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)),"r"(returned));
 return returned;
}
