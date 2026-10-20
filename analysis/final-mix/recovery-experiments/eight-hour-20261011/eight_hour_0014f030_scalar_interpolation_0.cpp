#include "../common/types.h"
extern "C" f32 D_0036b210;
void func_0014f030(f32 start,f32 end,f32 duration,f32* output)
{
 if(duration==0.0f)
 {
  duration=D_0036b210;
 }
 f32 difference=end-start;
 output[0]=start;
 output[2]=end;
 output[1]=difference/duration;
}
