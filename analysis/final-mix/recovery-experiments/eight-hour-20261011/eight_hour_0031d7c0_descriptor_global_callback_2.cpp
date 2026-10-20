#include "../common/types.h"
extern "C" u8 D_00347f98;
extern "C" u32 D_00347f80;
void func_0031d7c0(u32* object)
{
 register u32 table asm("$15")=(u32)&D_00347f98;
 asm("" : "+r"(table));
 *object=table;
 u32* control=(u32*)D_00347f80;
 u32* receiver=(u32*)control[5];
 typedef void (*Callback)(u32*,u32*);
 ((Callback)((u32*)*receiver)[1])(receiver,object);
}
