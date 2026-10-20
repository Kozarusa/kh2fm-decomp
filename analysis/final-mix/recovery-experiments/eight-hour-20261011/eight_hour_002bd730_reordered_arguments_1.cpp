#include "../common/types.h"
extern "C" u32 D_003617f0;
extern "C" u32 D_003617ec;
extern "C" void func_002b8824(u32,u64,u32,u64,u64);
void func_002bd730(u32 value,u64 b,u64 c,u64 d)
{
 (*(volatile u32*)&D_003617f0)=value;
 func_002b8824(D_003617ec,b,64,c,d);
}
