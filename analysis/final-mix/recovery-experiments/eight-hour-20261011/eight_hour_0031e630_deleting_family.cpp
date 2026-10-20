#include "../common/types.h"

// The original range passes the same object to both helpers.
// C++ class identities and helper semantics remain provisional.
extern "C" u8 D_0034e8a8;
extern "C" void func_00239848(u32*);
extern "C" void func_00106420(u32*);

void func_0031e630(u32* object)
{
 *object=(u32)&D_0034e8a8;
 func_00239848(object);
 func_00106420(object);
}
