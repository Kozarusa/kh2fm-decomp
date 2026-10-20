#include "../common/types.h"
void func_002376d8(s32 object,s32 index) {
 if (index < *(s32*)(object+60)) {
 u16* pointer=(u16*)(*(s32*)(object+12)+index*4);
 *(s32*)(object+104)=index;
 *(u32*)(object+20)=*(s32*)(object+8)+(u32)pointer[0]*20;
 *(u32*)(object+24)=pointer[1];
 }
}
