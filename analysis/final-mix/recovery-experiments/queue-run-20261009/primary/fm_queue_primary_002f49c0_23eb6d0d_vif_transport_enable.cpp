#include "../common/types.h"
struct __attribute__((aligned(16))) Quadword { u32 words[4]; };
extern "C" Quadword D_00363ce0[2];
// Reset VIF controls, enable the VU control flag, synchronize, then send the
// two original symbolic initialization quadwords through the hardware FIFO.
void func_002f49c0(void)
{
 register volatile u32* first asm("$2")=(volatile u32*)0x10003830;
 register volatile u32* second asm("$4")=(volatile u32*)0x10003820;
 asm("" : "+r"(first),"+r"(second));
 *first=0;
 register u32 thirdAddress asm("$3")=0x10000000;
 *second=0;
 asm("" : "+r"(thirdAddress) : : "memory");
 register volatile u32* third asm("$3")=(volatile u32*)(thirdAddress|0x3810);
 register u32 one asm("$2");
 // Keep the enable value after the complete control-register address.
 asm("addiu %0,$0,1" : "=r"(one) : "r"(third));
 *third=one;
 asm volatile("cfc2 $8,$28; ori $8,$8,2; ctc2 $8,$28; sync.p" : : : "$8","memory");
 register const Quadword* commands asm("$4");
 register volatile Quadword* fifo asm("$5");
 asm("lui %0,%%hi(D_00363ce0); lui %1,0x1000; addiu %0,%0,%%lo(D_00363ce0); ori %1,%1,0x4000" : "=r"(commands),"=r"(fifo));
 asm volatile("lq $2,0(%0); sq $2,0(%1); lq $3,16(%0); sq $3,0(%1)"
              : : "r"(commands),"r"(fifo) : "$2","$3","memory");
}
