#include "../common/types.h"
extern "C" s32 D_0035dd08[];
void func_00226050(s32 value) {
 register s32 index asm("$13")=0; // why: original keeps the loop index in t5
 s32* base=D_0035dd08;
 register s32* cursor asm("$12")=base; // why: original advances its cursor in t4
 register s32 offset asm("$11"); // why: original keeps the initialized byte offset in t3
 do {
  register s32 entry asm("$15")=*cursor; // why: original loads each entry into t7
  offset=index*4;
  ++cursor;
  ++index;
  asm("" : "+r"(cursor), "+r"(index)); // why: keeps cursor increment before loop bound comparison
  if (!entry) goto store;
 } while (index<64);
 offset=index*4;
 asm("" : "+r"(offset), "+r"(index)); // why: keeps the final initialized offset in t3 while preserving the distinct t5 index
store:
 register u8* destination asm("$15")=offset+(u8*)base; // why: original forms the final store address in t7
 *(s32*)destination=value;
}
