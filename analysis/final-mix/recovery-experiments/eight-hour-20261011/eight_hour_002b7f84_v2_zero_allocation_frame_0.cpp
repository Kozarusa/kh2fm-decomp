#include "../common/types.h"
extern "C" u64 func_002b6708(s32,s32,...);
u64 func_002b7f84()
{
 __builtin_alloca(0);
 register u64 result asm("$15")=func_002b6708(1,49);
 asm("" : "+r"(result));
 register u64 returned asm("$2")=result;
 asm("" : "+r"(returned) : "r"(__builtin_frame_address(0)));
 return returned;
}
