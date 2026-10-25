#include "../common/types.h"
extern "C" u8* func_002dc7c8(void);

f32 func_002dc248(void)
{
 u8* object=func_002dc7c8();

 return (-300.0f)-*(f32*)(object+112);
}
