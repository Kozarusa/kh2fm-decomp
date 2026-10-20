#include "../common/types.h"
extern "C" s32* func_00316d08(void);
s32 func_00305ce0(void) { s32* p=func_00316d08(); *(volatile s32*)p=5; return -1; }
