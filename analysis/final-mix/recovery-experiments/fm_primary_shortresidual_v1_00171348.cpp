#include "../common/types.h"
// Complete-range register/address correction proposal.
typedef void (*Call)(u32);
void func_00171348(u32 object) { u32 first=*(u32*)object; object=*(u32*)(first+4); register u32 table asm("$14")=*(u32*)object; asm("" : "+r"(table)); (*(Call*)(table+0x44))(object); }
