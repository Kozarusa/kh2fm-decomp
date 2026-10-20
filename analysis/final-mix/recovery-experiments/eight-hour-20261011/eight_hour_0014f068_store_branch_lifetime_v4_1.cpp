#include "../common/types.h"
u32 func_0014f068(f32*object){if(0.0f<=object[1]){if(object[2]<=object[0])goto finished;{asm("":::"$2");return 1;}}if(object[0]<=object[2])goto finished;{asm("":::"$2");return 1;}finished:asm volatile(""::"m"(object[0]));object[0]=object[2];return 0;}

