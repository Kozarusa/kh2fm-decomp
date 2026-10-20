#include "../common/types.h"
struct Object { u32 pc,base1,base2,array; union { u32 word; struct { u64 sorted:1,from_array:1,mixed:1,encoding:8,count:21; } bits; } flags; Object* next; };
extern "C" u32 func_0030edb0(void);
extern "C" void func_0030ee00(void);
extern "C" u32 D_0037aa2c;
extern "C" Object* D_0037aa30;
void func_00100700(u32 a,Object* p,u32 c,u32 d) { p->flags.word=0; p->pc=0xffffffff; p->base1=c; p->base2=d; p->flags.bits.from_array=1; p->flags.bits.encoding=255; p->array=a; u32 value=func_0030edb0(); D_0037aa2c=value; p->next=D_0037aa30; D_0037aa30=p; if(value) func_0030ee00(); asm volatile("" ::: "memory"); }
