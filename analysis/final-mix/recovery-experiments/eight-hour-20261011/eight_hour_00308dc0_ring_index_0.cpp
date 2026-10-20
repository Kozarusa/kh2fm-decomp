#include "../common/types.h"
s32 func_00308dc0(s32* object)
{
 s32 index=object[9]%object[6];
 object[9]=index+1;
 return object[5]+index*64;
}
