#include "../common/types.h"
extern u8 D_0032d7c0[];
// The original page/word indexing uses signed page transport, a signed-low address
// split, and separate scaling before the final bit-clear expression. Keep this
// narrow address calculation together to prevent compiler reassociation.
void func_001814b8(u32 param_1) {
 register u32 incoming asm("$4") = param_1;
 register u32 address asm("$13");
 asm volatile("sra %0,%1,10; lui $15,%%hi(D_0032d7c0); andi %1,%1,1023; addiu $15,$15,%%lo(D_0032d7c0); srl $14,%1,5; sll %0,%0,5; addu %0,%0,$15; sll $14,$14,2; addu %0,%0,$14" : "=&r"(address), "+r"(incoming) : : "$14", "$15");
 *(u32*)address &= ~(1u << (incoming & 31));
}
