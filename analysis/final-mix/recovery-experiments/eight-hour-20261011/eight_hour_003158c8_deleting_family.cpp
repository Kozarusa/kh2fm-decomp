#include "../common/types.h"

// The original range passes the same object to both helpers.
// C++ class identities and helper semantics remain provisional.
extern "C" u8 D_003677b8;
extern "C" void func_00315768(u32*);
extern "C" void func_00106420(u32*);

void func_003158c8(u32* object)
{
 *object=(u32)&D_003677b8;
 func_00315768(object);
 func_00106420(object);
}
