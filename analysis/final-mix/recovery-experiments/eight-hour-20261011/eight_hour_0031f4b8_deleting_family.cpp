#include "../common/types.h"

// The original range passes the same object to both helpers.
// C++ class identities and helper semantics remain provisional.
extern "C" u8 D_00350bf0;
extern "C" void func_001ac5b8(u32*);
extern "C" void func_00105110(u32*);

void func_0031f4b8(u32* object)
{
 *object=(u32)&D_00350bf0;
 func_001ac5b8(object);
 func_00105110(object);
}
