#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { u32 value[4]; };

void func_00140850(u32 object)
{
  register u32 destination asm("$14")=object+0x90;
  register u32 source asm("$15")=object+0x80;
  asm volatile("" : "+r"(destination), "+r"(source));
  if(destination!=source) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source),"r"(destination),"m"(*(Quad *)source) : "$8");
  destination=object+0x70;
  source=object+0x60;
  asm volatile("" : "+r"(destination), "+r"(source));
  if(destination!=source) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source),"r"(destination),"m"(*(Quad *)source) : "$8");
  source=object+0xa0;
  asm volatile("" : "+r"(source) : "r"(object));
  register u32 final_destination asm("$4")=object+0xb0;
  asm volatile("" : "+r"(final_destination) : "r"(source));
  if(final_destination!=source) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)final_destination) : "r"(source),"r"(final_destination),"m"(*(Quad *)source) : "$8");
}
