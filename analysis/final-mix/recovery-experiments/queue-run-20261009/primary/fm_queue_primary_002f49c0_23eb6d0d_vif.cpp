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
 register volatile u32* third asm("$3")=(volatile u32*)0x10003810;
 *second=0;
 asm("" : "+r"(third));
 *third=1;
 asm volatile("cfc2 $8,$28; ori $8,$8,2; ctc2 $8,$28; sync.p" : : : "$8","memory");
 register const Quadword* commands asm("$4")=D_00363ce0;
 register volatile Quadword* fifo asm("$5")=(volatile Quadword*)0x10004000;
 asm volatile("lq $2,0(%0); sq $2,0(%1); lq $3,16(%0); sq $3,0(%1)"
              : : "r"(commands),"r"(fifo) : "$2","$3","memory");
}
