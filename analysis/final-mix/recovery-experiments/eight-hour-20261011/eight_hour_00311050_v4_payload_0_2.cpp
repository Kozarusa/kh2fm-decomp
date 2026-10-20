#include "../common/types.h"
extern "C" s32 func_00305a50(u64,void*);
void func_00311050(u32 value,s8 flag)
{
 s32 payload[2]={(s32)value,(s32)flag};
 func_00305a50(3,&payload);
}
