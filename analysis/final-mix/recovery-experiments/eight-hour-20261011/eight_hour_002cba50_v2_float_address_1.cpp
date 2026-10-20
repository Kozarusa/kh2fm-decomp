#include "../common/types.h"
extern "C" f32 D_0037589c;
extern "C" u64 func_002cba88(f32,f32,u64,u32*,u32*,u32*);
u64 func_002cba50(u64 output,u32* record,u32* first,u32* second)
{
 register f32* fallback asm("$15")=&D_0037589c;
 asm("" : "+r"(fallback));
 func_002cba88(*(f32*)(record+9),*fallback,output,record,first,second);
 return output;
}
