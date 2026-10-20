#include "../common/types.h"
extern "C" u32 D_0032dedc[];
bool func_001a8450(u8*object){if(!object)return false;u16 index=*(u16*)(object+10);if(!index)return false;return (D_0032dedc[index>>5]&((u32)1<<(index&31)))!=0;}
