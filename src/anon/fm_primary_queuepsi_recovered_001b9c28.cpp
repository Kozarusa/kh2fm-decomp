#include "../common/types.h"
extern "C" u32 D_01d48db8[];

// Preserve original registry aliases.
void func_001b9c28(u32 index) asm("_ZN2YS3OBJ10ControlOffEi");

void func_001b9c28(u32 index)
{
 D_01d48db8[index>>5]|=1u<<(index&31);
}
