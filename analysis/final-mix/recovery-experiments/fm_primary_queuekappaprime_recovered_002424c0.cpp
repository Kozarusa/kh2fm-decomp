#include "../common/types.h"
extern "C" u32* func_001058e8();

bool func_002424c0(u32 value)
{
 u32* context=func_001058e8();
 u32 total=context[0x910]+value;
 return total<1000000U;
}
