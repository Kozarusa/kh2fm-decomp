#include "../common/types.h"
struct Result { s32 value; }; extern "C" Result* func_00316d08(void);
s32 func_00305e20() { Result* pointer=func_00316d08(); register s32 value asm("$3")=5; asm volatile("" : "+r"(value)); ((volatile Result*)pointer)->value=value; return -1; }
