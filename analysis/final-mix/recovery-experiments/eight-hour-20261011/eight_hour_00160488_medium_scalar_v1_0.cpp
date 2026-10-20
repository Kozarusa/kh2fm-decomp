#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell{u32 word;f32 value;Quad*quad;u8*object;};
void func_00160488(u8*object,u8 red,u8 green,u8 blue){object[0x2aa]=(blue*object[0x1a6])>>7;object[0x2a9]=(green*object[0x1a5])>>7;object[0x2a8]=(red*object[0x1a4])>>7;}
