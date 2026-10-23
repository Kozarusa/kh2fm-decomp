#include "../common/types.h"

// The original range passes the same object to both helpers.
// C++ class identities and helper semantics remain provisional.
extern "C" u8 D_003622c0;
extern "C" void func_002d0f38(u32*);
extern "C" void func_00105110(u32*);

void func_00325408(u32* object)
{
 *object=(u32)&D_003622c0;
 func_002d0f38(object);
 func_00105110(object);
}
