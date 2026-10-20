#include "../common/types.h"
extern "C" s32 D_0035dd08[];
void func_00226050(s32 value) {
 s32 index=0;
 s32* base=D_0035dd08;
 register s32* cursor asm("$12")=base; // why: original advances its cursor in t4
 s32 offset;
 do {
  s32 entry=*cursor;
  offset=index*4;
  ++cursor;
  ++index;
  asm("" : "+r"(cursor), "+r"(index)); // why: keeps cursor increment before loop bound comparison
  if (!entry) goto store;
 } while (index<64);
 offset=index*4;
store:
 *(s32*)(offset+(u8*)base)=value;
}
