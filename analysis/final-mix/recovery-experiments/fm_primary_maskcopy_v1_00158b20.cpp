#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { u32 value[4]; };
extern "C" Quad D_0034a9c0;
extern "C" Quad D_0034a9d0;
extern "C" u32 D_0034a9e0;
extern "C" u32 D_0034a9e4;
void func_00158b20(u32 object)
{
  *(u32 *)(object+0x48)=D_0034a9e0;
  *(u32 *)(object+0x50)=D_0034a9e4;
  u32 source=(u32)&D_0034a9c0;
  u32 destination=object+0x90;
  if(source!=destination) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source), "r"(destination), "m"(D_0034a9c0) : "$8");
  source=(u32)&D_0034a9d0;
  destination=object+0x70;
  if(source!=destination) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source), "r"(destination), "m"(D_0034a9d0) : "$8");
}
