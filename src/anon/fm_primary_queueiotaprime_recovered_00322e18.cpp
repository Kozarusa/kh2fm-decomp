#include "../common/types.h"
extern "C" u8 D_00347f98;
extern "C" u32 D_00347f80;

void func_00322e18(u32* object)
{
 *object=(u32)&D_00347f98;
 u32* control=(u32*)D_00347f80;
 u32* receiver=(u32*)control[5];
 typedef void (*Callback)(u32*,u32*);
 ((Callback)((u32*)*receiver)[1])(receiver,object);
}
