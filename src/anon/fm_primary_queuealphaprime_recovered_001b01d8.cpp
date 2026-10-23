#include "../common/types.h"

// The original range passes the same object to both helpers.
// C++ class identities and helper semantics remain provisional.
extern "C" u8 D_00350e78;
extern "C" void func_001b0330(u32*);
extern "C" void func_00106420(u32*);

void func_001b01d8(u32* object)
{
 *object=(u32)&D_00350e78;
 func_001b0330(object);
 func_00106420(object);
}
