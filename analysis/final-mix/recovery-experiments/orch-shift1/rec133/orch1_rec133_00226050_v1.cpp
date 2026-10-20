#include "../common/types.h"
extern "C" s32 D_0035dd08[];
void func_00226050(s32 value) {
 s32 index=0;
 s32* cursor=D_0035dd08;
 s32 offset;
 do {
  s32 entry=*cursor;
  offset=index*4;
  ++index;
  ++cursor;
  if (!entry) break;
 } while (index<64);
 if (index>=64 && cursor[-1]) offset=index*4;
 *(s32*)((u8*)D_0035dd08+offset)=value;
}
