#include "../common/types.h"
extern "C" f32 D_003714c8;
void func_00239f78(u8* object, f32 value) {
    *(f32*)(object+316)=value;
    s32 flag=0;
    if (*(f32*)(object+308)!=D_003714c8 || *(f32*)(object+312)!=D_003714c8 || value!=D_003714c8) flag=1;
    *(u32*)(object+184)=(*(u32*)(object+184)&~2u)|(flag<<1);
}
