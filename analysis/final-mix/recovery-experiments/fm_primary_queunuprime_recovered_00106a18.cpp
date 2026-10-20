#include "../common/types.h"
extern "C" u8 D_0033cc44;
extern "C" s32 D_0033cc40;
extern "C" u8 D_003a7d70[],D_003a7b70[];

u8* func_00106a18(u8 input) { if (input!=0 || D_0033cc44!=0) return D_003a7b70+D_0033cc40*256; return D_003a7d70+D_0033cc40*256; }
