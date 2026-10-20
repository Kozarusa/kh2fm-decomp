#include "../common/types.h"
void func_001d4dc0(u32* object,u32 second,u32 third,u32 fourth)
{
 object[0x8e]=second;
 register u32 sentinel asm("$14")=9999;
 asm("" : "+r"(sentinel));
 object[6]=sentinel;
 object[0x8f]=third;
 object[0x90]=fourth;
 object[11]=0;
 typedef void (*Callback)(u32*);
 ((Callback)((u32*)*object)[1])(object);
}
