#include "../common/types.h"
extern "C" u8 D_00363828;
extern "C" void func_002edf28(u32*);
extern "C" void func_001ad330(u32*,u64);
void func_002ee5d8(u32* object,u64 payload)
{
 func_002edf28(object);
 object[10]=(u32)payload;
 object[9]=0;
 *(volatile u32*)object=(u32)&D_00363828;
 func_001ad330(object+11,payload);
}
