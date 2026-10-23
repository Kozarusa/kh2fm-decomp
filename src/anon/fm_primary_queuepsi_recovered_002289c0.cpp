#include "../common/types.h"
typedef void (*Callback)(u32*);
extern "C" void func_00228918(u32*);

void func_002289c0(u32* object)
{
 u32* saved=object;
 ((Callback*)*object)[7](object);
 func_00228918(saved);
}
