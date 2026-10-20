#include "../common/types.h"
extern "C" u32 D_003617ec;
extern "C" volatile u8 D_003617f8;
extern "C" u32 D_003617f4;
extern "C" u32 D_0032b91c;
extern "C" char func_002bd870;
extern "C" void func_002b871c(void);
extern "C" u32 func_00102788(u32,u32,u32,s32);
void func_002bd788(u32 param_1) {
 D_003617ec = param_1;
 D_003617f8 = 0;
 func_002b871c();
 D_003617f4 = func_00102788(D_0032b91c,0,0x5cc60,(s32)(long)&func_002bd870);
}
