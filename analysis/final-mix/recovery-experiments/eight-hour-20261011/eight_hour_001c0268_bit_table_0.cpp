#include "../common/types.h"
bool func_001c0268(u32 object,u32 other)
{
 u32 index=*(u32*)(other+28);
 return (*(u32*)(object+(index>>5)*4+4)&(1u<<(index&31)))==0;
}
