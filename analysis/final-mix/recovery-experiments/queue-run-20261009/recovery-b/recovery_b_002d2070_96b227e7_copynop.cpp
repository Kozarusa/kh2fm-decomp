#include "../common/types.h"
struct __attribute__((packed,aligned(2))) Record { u64 first; s16 second; };
extern "C" Record D_0032bae0;
extern "C" void func_00195750(void);
extern "C" void func_00104f58(Record*,u32,u32,u32,u32);
void func_002d2070(void) { Record r=D_0032bae0;asm volatile("nop" :: "m"(r) : "memory");func_00195750();func_00104f58(&r,1,0,0,0); }
