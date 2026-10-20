#include "../common/types.h"
extern "C" void func_001666a0(void);
void func_0014dc08(u32 p) { func_001666a0();
asm volatile("sb $0,0x1d9(%0); sw $0,0x1d0(%0); sh $0,0x1d4(%0); sb $0,0x1d6(%0); sb $0,0x1d7(%0); sb $0,0x1d8(%0)" :: "r"(p));
}