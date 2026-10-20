#include "../common/types.h"
struct State { u32 value,zero; u8* first; u8* last; u8 data[1]; };
extern "C" State D_01e352c0;
State* func_00306900(u32 a) { State* p=&D_01e352c0; p->value=a; p->first=p->data; p->zero=0; asm volatile("" ::: "memory"); p->last=p->data; return p; }
