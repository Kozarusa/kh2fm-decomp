#include "../common/types.h"
typedef void (*Callback)(u32*,u32*);
extern "C" u8 D_0034c720;
extern "C" u32* D_0034c738;
extern "C" void func_00160268(u32*);
void func_0031e110(u32* object)
{
 *(volatile u32*)object=(u32)&D_0034c720;
 func_00160268(object);
 u32* receiver=D_0034c738;
 ((Callback*)receiver[0])[1](receiver,object);
}
