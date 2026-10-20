#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { u32 value[4]; };
extern "C" Quad D_0034a9c0;
extern "C" Quad D_0034a9d0;
extern "C" u32 D_0034a9e0;
extern "C" u32 D_0034a9e4;
void func_00158ac8(u32 object)
{
  u32 source=object+0x90;
  u32 destination=(u32)&D_0034a9c0;
  if(source!=destination) asm volatile("lq $8,0(%1); sq $8,%0" : "=m"(D_0034a9c0) : "r"(source), "m"(*(Quad *)source) : "$8");
  source=object+0x70;
  destination=(u32)&D_0034a9d0;
  if(source!=destination) asm volatile("lq $8,0(%1); sq $8,%0" : "=m"(D_0034a9d0) : "r"(source), "m"(*(Quad *)source) : "$8");
  D_0034a9e0=*(u32 *)(object+0x48);
  D_0034a9e4=*(u32 *)(object+0x50);
}
