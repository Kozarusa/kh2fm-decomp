#include "../common/types.h"
extern "C" void func_00305a50(s32,s32*);
void func_00311050(u32 value,s8 flag)
{
 s32 payload[2];
 payload[0]=value;
 payload[1]=flag;
 func_00305a50(3,payload);
}
