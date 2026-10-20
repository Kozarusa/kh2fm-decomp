#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
extern "C" u32*func_00168b38(u32*,u32,s32);
u32 func_00161548(u8*object,s32 index){if(index>=0){u32*list=*(u32**)(object+64);if(list){u32*item=func_00168b38(list,9,index);if(item)return item[2];}}return 0;}
