#include "../common/types.h"
extern "C" u8 D_0034b268;
extern "C" u32 D_0034b278;
void func_0031e008(u32* object)
{
 *object=(u32)&D_0034b268;
 u32* receiver=(u32*)D_0034b278;
 typedef void (*Callback)(u32*,u32*);
 ((Callback)((u32*)*receiver)[1])(receiver,object);
}
