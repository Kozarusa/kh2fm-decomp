#include "../common/types.h"
extern "C" u32 D_0032bb1c;
extern "C" u64 func_00170b30(void);
extern "C" u64 func_00106178(u64,u64);
extern "C" void func_001091c8(u64,u64,u64);
void func_00105370(u64 size,u64 flags){u64 base=func_00170b30();base=func_00106178(base,size);D_0032bb1c=base;func_001091c8(base,0x100,flags);}
