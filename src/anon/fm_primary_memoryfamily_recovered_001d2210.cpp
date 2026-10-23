#include "../common/types.h"

// Preserve original registry aliases.
void func_001d2210(u32* object) asm("_Z16u_call4_001d2210jjjj");
// Complete original-memory/register recovery proposal.
typedef void (*Call)(void);

void func_001d2210(u32* object) { asm volatile("" ::: "memory"); if(object[3]&4) (*(Call*)(object[0]+8))(); }
