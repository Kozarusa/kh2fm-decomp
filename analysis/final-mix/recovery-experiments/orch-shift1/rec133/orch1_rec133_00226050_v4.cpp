#include "../common/types.h"
extern "C" s32 D_0035dd08[];
void func_00226050(s32 value) {
 s32 index=0;
 s32* base=D_0035dd08;
 s32* cursor=base;
 s32 offset;
 do {
  s32 entry=*cursor;
  offset=index*4;
  ++cursor;
  ++index;
  if (!entry) goto store;
 } while (index<64);
 offset=index*4;
store:
 *(s32*)((u8*)base+offset)=value;
}
