#include "../common/types.h"
void func_002376d8(s32 object,s32 index) {
 if (index < *(s32*)(object+60)) {
 *(s32*)(object+104)=index;
 s32 base=*(s32*)(object+12);
 // why: original table cursor uses register 12.
 register u16* pointer asm("$12") = 0;
 pointer=(u16*)(base+index*4);
 *(u32*)(object+20)=*(s32*)(object+8)+(u32)pointer[0]*20;
 *(u32*)(object+24)=pointer[1];
 }
}
