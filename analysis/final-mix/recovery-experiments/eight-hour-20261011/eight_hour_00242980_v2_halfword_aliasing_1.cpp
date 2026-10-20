#include "../common/types.h"
extern "C" u8* func_001058e8();
void func_00242980(s32* first,s32* second)
{
 u8* context=func_001058e8();
 *(volatile s32*)first=*(volatile s16*)(context+0x41a0);
 *(volatile s32*)second=*(volatile s16*)(context+0x41a2);
}
