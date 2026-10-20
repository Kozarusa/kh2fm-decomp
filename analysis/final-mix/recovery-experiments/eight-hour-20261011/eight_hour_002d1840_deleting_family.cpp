#include "../common/types.h"

// The original range passes the same object to both helpers.
// C++ class identities and helper semantics remain provisional.
extern "C" u8 D_00362158;
extern "C" void func_002cea28(u32*);
extern "C" void func_00105110(u32*);

void func_002d1840(u32* object)
{
 *object=(u32)&D_00362158;
 func_002cea28(object);
 func_00105110(object);
}
