#include "../common/types.h"

// The original range passes the same object to both helpers.
// C++ class identities and helper semantics remain provisional.
extern "C" u8 D_003626a8;
extern "C" void func_002db530(u32*);
extern "C" void func_00105110(u32*);

void func_002db730(u32* object)
{
 *object=(u32)&D_003626a8;
 func_002db530(object);
 func_00105110(object);
}
