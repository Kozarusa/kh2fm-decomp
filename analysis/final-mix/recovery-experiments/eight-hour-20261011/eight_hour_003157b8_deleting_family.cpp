#include "../common/types.h"

// The original range passes the same object to both helpers.
// C++ class identities and helper semantics remain provisional.
extern "C" u8 D_00367818;
extern "C" void func_003155e8(u32*);
extern "C" void func_00106420(u32*);

void func_003157b8(u32* object)
{
 *object=(u32)&D_00367818;
 func_003155e8(object);
 func_00106420(object);
}
