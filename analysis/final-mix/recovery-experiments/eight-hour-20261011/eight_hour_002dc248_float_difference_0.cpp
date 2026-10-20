#include "../common/types.h"
extern "C" u8* func_002dc7c8(void);
extern "C" f32 D_00375d44;
f32 func_002dc248(void)
{
 u8* object=func_002dc7c8();
 return D_00375d44-*(f32*)(object+112);
}
