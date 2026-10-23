#include "../common/types.h"

// The original range passes the same object to both helpers.
// C++ class identities and helper semantics remain provisional.
extern "C" u8 D_00347bb0;
extern "C" void func_00124c08(u32*);
extern "C" void func_00106420(u32*);

void func_00128008(u32* object)
{
 *object=(u32)&D_00347bb0;
 func_00124c08(object);
 func_00106420(object);
}
