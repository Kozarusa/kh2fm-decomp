#include "../common/types.h"
typedef void (*Callback)(u32*);
extern "C" void func_00228918(u32*);
void func_002289c0(u32* object)
{
 register u32* saved asm("$16")=object;
 asm("" : "+r"(saved));
 ((Callback*)*object)[7](object);
 func_00228918(saved);
}
