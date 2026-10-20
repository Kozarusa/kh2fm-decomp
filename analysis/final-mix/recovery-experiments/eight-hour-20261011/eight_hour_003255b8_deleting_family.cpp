#include "../common/types.h"

// The original range passes the same object to both helpers.
// C++ class identities and helper semantics remain provisional.
extern "C" u8 D_00362cc8;
extern "C" void func_002dea80(u32*);
extern "C" void func_00106420(u32*);

void func_003255b8(u32* object)
{
 *object=(u32)&D_00362cc8;
 func_002dea80(object);
 func_00106420(object);
}
