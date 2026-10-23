#include "../common/types.h"
// Complete original-memory/register recovery proposal.
struct __attribute__((aligned(16))) Quad { u64 first,second; }; extern "C" u32 func_0016c028(u32);

u32 func_0018d808(u32 destination,u32 object) { u32 source=func_0016c028(*(u32*)(object+8)); asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad*)destination) : "r"(source),"r"(destination),"m"(*(Quad*)source) : "$8"); asm volatile("" ::: "memory"); return destination; }
