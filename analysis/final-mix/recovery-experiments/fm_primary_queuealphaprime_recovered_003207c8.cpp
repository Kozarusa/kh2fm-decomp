#include "../common/types.h"

// The original range passes the same object to both helpers.
// C++ class identities and helper semantics remain provisional.
extern "C" u8 D_003512e8;
extern "C" void func_0016a358(u32*);
extern "C" void func_00105110(u32*);

void func_003207c8(u32* object)
{
 *object=(u32)&D_003512e8;
 func_0016a358(object);
 func_00105110(object);
}
