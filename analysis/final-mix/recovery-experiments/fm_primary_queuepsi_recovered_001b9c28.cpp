#include "../common/types.h"
extern "C" u32 D_01d48db8[];

void func_001b9c28(u32 index)
{
 D_01d48db8[index>>5]|=1u<<(index&31);
}
