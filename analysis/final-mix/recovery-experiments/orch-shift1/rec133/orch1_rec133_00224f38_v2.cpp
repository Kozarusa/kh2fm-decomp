#include "../common/types.h"
extern "C" u32 func_00102c18(u64,u64,u64);
extern "C" u32 func_0022a368(u64);
extern "C" u8 D_0022b108[];
extern "C" u8 D_00224f08[];
u32 func_00224f38(u64 value,u32* output,u32* result,u64 object) {
 u32 task=func_00102c18(1,value,(u32)D_0022b108);
 *output=task;
 *(u32*)(task+48)=(u32)D_00224f08;
 u32 answer=func_0022a368(object);
 *result=answer;
 return answer;
}
