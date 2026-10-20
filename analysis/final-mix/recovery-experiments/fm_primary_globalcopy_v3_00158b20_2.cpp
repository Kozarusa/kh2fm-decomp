#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { u32 value[4]; };
extern "C" Quad D_0034a9c0;
extern "C" Quad D_0034a9d0;
extern "C" f32 D_0034a9e0;
extern "C" f32 D_0034a9e4;
void func_00158b20(u32 object)
{
  *(f32 *)(object+0x48)=D_0034a9e0;
  *(f32 *)(object+0x50)=D_0034a9e4;
  register u32 source asm("$15")=(u32)&D_0034a9c0;
  register u32 destination asm("$13")=object+0x90;
  if(source!=destination) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source), "r"(destination), "m"(D_0034a9c0) : "$8");
  source=(u32)&D_0034a9d0;
  asm("" : "+r"(source) : "r"(object));
  register u32 final_destination asm("$4")=object+0x70;
  if(final_destination!=source) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)final_destination) : "r"(source), "r"(final_destination), "m"(D_0034a9d0) : "$8");
}
