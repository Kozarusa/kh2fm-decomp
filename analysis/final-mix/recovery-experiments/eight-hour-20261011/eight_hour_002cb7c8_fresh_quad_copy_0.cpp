#include "../common/types.h"
struct Quad { u32 words[4]; };
extern "C" Quad* func_002cb890(u64,u64);
Quad* func_002cb7c8(Quad* output,u64 second,u64 third)
{
 Quad* input=func_002cb890(second,third);
 *output=*input;
 return output;
}
