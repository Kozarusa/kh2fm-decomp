#include "../common/types.h"
bool func_0028b1c0(const u8* object,u32 index)
{
 u32 bits=*(const u32*)(object+32);
 if(!bits)return false;
 u32 mask=1u<<index;
 return (bits&mask)!=0;
}
