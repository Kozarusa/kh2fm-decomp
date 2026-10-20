#include "../common/types.h"
#include <stdarg.h>
extern "C" char func_00307ee8;
extern "C" void func_003071d0(s32,u32*,u32,u32,va_list);
void func_00308018(u32 first,u64 second,u64 third,...) {
 u32 stack[4];
 va_list args;
 stack[0] = first;
 va_start(args,third);
 func_003071d0((s32)(long)&func_00307ee8,stack,second,third,args);
 va_end(args);
}
