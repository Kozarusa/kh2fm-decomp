#include "../common/types.h"
u32 func_0014f068(f32*object){if(0.0f<=object[1]){if(__builtin_expect(!(object[2]<=object[0]),0)){asm("":::"$2");return 1;}}else{if(__builtin_expect(!(object[0]<=object[2]),0)){asm("":::"$2");return 1;}}asm volatile(""::"m"(object[0]));object[0]=object[2];return 0;}


