#include "../common/types.h"
extern "C" u32* func_002cba88(f32,f32,u32*,u32*,u32*,u32*);

u32* func_002cba50(u32* output,u32* record,u32* first,u32* second)
{

 register f32 factor asm("$f13")=1.0f;
 asm("" : "+r"(record) : "f"(factor));

 func_002cba88(*(f32*)(record+9),factor,output,record,first,second);
 return output;
}
