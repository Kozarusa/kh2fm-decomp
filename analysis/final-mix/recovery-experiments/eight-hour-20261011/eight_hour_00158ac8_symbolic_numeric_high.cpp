#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { u32 value[4]; };
extern "C" Quad D_0034a9c0;
extern "C" Quad D_0034a9d0;
extern "C" f32 D_0034a9e0;
extern "C" f32 D_0034a9e4;
void func_00158ac8(u32 object)
{
  register u32 source asm("$14")=object+0x90;
  register u32 destination asm("$15");
  destination=(u32)&D_0034a9c0;
  asm("" : "+r"(destination));
  if(source!=destination) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source), "r"(destination), "m"(*(Quad *)source) : "$8");
  source=object+0x70;
  destination=0x00350000;
  asm("" : "+r"(destination));
  destination-=0x5630;
  if(source!=destination) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source), "r"(destination), "m"(*(Quad *)source) : "$8");
  D_0034a9e0=*(f32 *)(object+0x48);
  D_0034a9e4=*(f32 *)(object+0x50);
}
