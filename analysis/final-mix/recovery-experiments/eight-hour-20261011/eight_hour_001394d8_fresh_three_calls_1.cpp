#include "../common/types.h"
extern "C" void func_00139768();
extern "C" void func_001394c0(u64);
extern "C" void func_00102750(u32);
extern "C" u32* D_00347f80;
void func_001394d8(u64 payload)
{
 func_00139768();
 func_001394c0(payload);
 func_00102750(*D_00347f80);
}
