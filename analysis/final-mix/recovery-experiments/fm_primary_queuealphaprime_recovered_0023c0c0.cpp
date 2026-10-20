#include "../common/types.h"

// The original range passes the same object to both helpers.
// C++ class identities and helper semantics remain provisional.
extern "C" u8 D_0035eb08;
extern "C" void func_0023c300(u32*);
extern "C" void func_00106420(u32*);

void func_0023c0c0(u32* object)
{
 *object=(u32)&D_0035eb08;
 func_0023c300(object);
 func_00106420(object);
}
