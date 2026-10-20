#include "../common/types.h"
extern "C" u64 func_0016a020(u32);
extern "C" void func_0019b0e8(f32,f32,void*,u64,s32);
extern "C" void func_0016ace0(u32,void*);
void func_00172928(s32* p) { u8 packet[16]; u32 source=*(u32*)(p[0]+4); u64 value=func_0016a020(source);
s32 integer=p[1]; register f32 second asm("$f13");
asm ("lwc1 %0,12(%1)" : "=f"(second) : "r"(p) : "memory");
register void* destination asm("$4"); asm("move %0,$sp" : "=r"(destination) : : "memory");
func_0019b0e8(((f32*)p)[2],second,destination,value,integer); func_0016ace0(source,packet); }
