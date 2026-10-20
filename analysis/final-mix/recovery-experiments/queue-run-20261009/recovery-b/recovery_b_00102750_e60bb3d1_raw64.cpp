#include "../common/types.h"
extern "C" void func_00102730(void);
typedef void (*Method)(u64,u64);
void func_00102750(u64 p) { func_00102730(); ((Method)*(u32*)(*(u32*)p+4))(p,p); asm volatile("" ::: "memory"); }
