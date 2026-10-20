#include "../common/types.h"
extern "C" u64 func_0016a020(u32);
extern "C" void func_0019b0e8(f32,f32,void*,u64,s32);
extern "C" void func_0016ace0(u32,void*);
void func_00172928(s32* p) { u8 packet[16]; u32 source=*(u32*)(p[0]+4); u64 value=func_0016a020(source);
register s32 integer asm("$6"); register u64 argument asm("$5"); register f32 second asm("$f13");
asm volatile("lw %0,4(%3); move %1,%4; lwc1 %2,12(%3)" : "=r"(integer),"=r"(argument),"=f"(second) : "r"(p),"r"(value) : "memory");
func_0019b0e8(((f32*)p)[2],second,packet,argument,integer); func_0016ace0(source,packet); }
