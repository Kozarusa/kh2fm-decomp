#include "../common/types.h"
extern "C" u32 D_0033cae8[];
bool func_002f1ae0(u32 index)
{
 return (D_0033cae8[index>>5]&(1u<<(index&31)))!=0;
}
