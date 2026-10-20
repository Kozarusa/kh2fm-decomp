#include "../common/types.h"
extern "C" f32 D_003714c8;
void func_00239f78(u8* object, f32 value) {
    f32* pointer=&D_003714c8;
    asm("" : "+r"(pointer)); // why: keeps original global address materialized
    f32 first=*(volatile f32*)(object+308);
    *(volatile f32*)(object+316)=value;
    s32 flag=0;
    if (first!=*pointer || *(f32*)(object+312)!=*pointer || value!=*pointer) flag=1;
    *(u32*)(object+184)=(*(u32*)(object+184)&~2u)|(flag<<1);
}



