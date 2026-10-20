#include "../common/types.h"
extern "C" u8 D_00349b28;
extern "C" void func_0014b638(u32*);
extern "C" void func_0014a988(u32*);

void func_0014a950(u32* object)
{
 func_0014b638(object);
 *(u32*)object=(u32)&D_00349b28;
 func_0014a988(object);
}
