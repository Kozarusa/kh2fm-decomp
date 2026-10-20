#include "../common/types.h"

// The original range passes the same object to both helpers.
// C++ class identities and helper semantics remain provisional.
extern "C" u8 D_0035eaf8;
extern "C" void func_00237238(u32*);
extern "C" void func_00106420(u32*);

void func_00239898(u32* object)
{
 *object=(u32)&D_0035eaf8;
 func_00237238(object);
 func_00106420(object);
}
