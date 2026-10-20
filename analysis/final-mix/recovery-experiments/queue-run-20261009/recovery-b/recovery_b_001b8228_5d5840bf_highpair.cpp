#include "../common/types.h"
extern "C" u8 D_003a99f0[];
extern "C" u8* volatile D_01d48cb8;
extern "C" u8* volatile D_003511bc;
extern "C" u8* volatile D_003511b8;
extern "C" volatile u8 D_003511c2;
void func_001b8228(void) { register u32 high asm("$15")=0x350000;asm("" :: "r"(high));register u8* p asm("$13")=D_003a99f0;register u8* q asm("$12")=p+0x4000;asm("" : "+r"(q) : "r"(p),"r"(high));D_01d48cb8=p;*(u8* volatile*)(high+0x11bc)=q;D_003511b8=p;D_003511c2=0; }
