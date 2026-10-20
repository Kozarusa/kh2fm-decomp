#include "../common/types.h"
extern "C" u8 D_0035e440[];

void func_00236d60() {
 u8* pointer=D_0035e440;
 u8* end=pointer+1536;
 do {
 *pointer=0;
 *(u32*)(pointer+4)=0;
 pointer+=24;
 } while ((s32)pointer < (s32)end);
}
