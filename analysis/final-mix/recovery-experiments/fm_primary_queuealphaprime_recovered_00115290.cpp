#include "../common/types.h"

// The original range passes the same object to both helpers.
// C++ class identities and helper semantics remain provisional.
extern "C" u8 D_00346e80;
extern "C" void func_00113668(u32*);
extern "C" void func_00105110(u32*);

void func_00115290(u32* object)
{
 *object=(u32)&D_00346e80;
 func_00113668(object);
 func_00105110(object);
}
