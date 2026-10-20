#include "../common/types.h"
extern "C" u32 D_0032dedc[];
bool func_001a8450(u8*object){bool result=false;if(object){u16 index=*(u16*)(object+10);if(index)result=(D_0032dedc[index>>5]&((u32)1<<(index&31)))!=0;}return result;}
