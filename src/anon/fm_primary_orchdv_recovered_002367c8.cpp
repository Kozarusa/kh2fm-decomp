#include "../common/types.h"
extern "C" u32 func_002f2be0(...);

void func_002367c8(s32 object) {
 u64 flag = *(u64*)(object+48);
 if ((((s64)flag >> 32) & 1) == 0) {
 func_002f2be0(object+64, *(u32*)(object+56));
 flag = *(u64*)(object+48);
 }
 if (((u32)(flag >> 33) & 1) == 0) {
 func_002f2be0(object+160, *(u32*)(object+60));
 }
}
