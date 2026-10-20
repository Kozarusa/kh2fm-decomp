#include "../common/types.h"
extern "C" s32* func_00316d08(void);
s32 func_00305e20() { s32* pointer=func_00316d08(); *(volatile s32*)pointer=5; return -1; }
