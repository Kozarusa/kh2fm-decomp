#include "../common/types.h"
extern "C" void func_00102730(void);
struct Object; typedef void (*Method)(Object*,Object*); struct Object { Method* table; };
void func_00102750(Object* p) { func_00102730(); p->table[1](p,p); asm volatile("" ::: "memory"); }
