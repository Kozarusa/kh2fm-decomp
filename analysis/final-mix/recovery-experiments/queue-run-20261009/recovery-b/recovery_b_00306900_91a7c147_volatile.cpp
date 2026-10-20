#include "../common/types.h"
struct State { u32 value,zero; u8* first; u8* last; u8 data[1]; };
extern "C" State D_01e352c0;
State* func_00306900(u32 a) { volatile State* p=&D_01e352c0; p->value=a; p->first=(u8*)p->data; p->zero=0; p->last=(u8*)p->data; return (State*)p; }
