#include "../common/types.h"
u32 func_0014f068(f32*object){
 f32 terminal;
 if(0.0f<=object[1]){terminal=object[2];if(!(terminal<=object[0]))goto failure;}
 else{terminal=object[2];if(!(object[0]<=terminal))goto failure;}
 object[0]=terminal;return 0;
 failure:asm("":::"$2");return 1;
}
