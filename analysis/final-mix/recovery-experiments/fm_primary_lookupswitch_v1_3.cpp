#include "../common/types.h"
extern const void *D_0036b2c4[5];
extern const void *D_0036b2ec[5];
s32 func_00155ee8(u32 object)
{
  static const void *targets[5] asm("fm_switch_table_00155ee8")={&&fallback,&&fallback,&&case2,&&case3,&&case4};
  u32 child=*(u32 *)(object+0x34);
  if(!child) goto fallback;
  u32 index=*(u8 *)(*(u32 *)(child+0x48c)+0x1af);
  if(index>=5) goto fallback;
  goto *D_0036b2c4[index];
case4: return 0x12;
fallback: return 0x15;
case2: return 0x32;
case3: return 0x8c;
}
s32 func_00155fc0(u32 object)
{
  static const void *targets[5] asm("fm_switch_table_00155fc0")={&&fallback,&&fallback,&&case2,&&case3,&&fallback};
  u32 child=*(u32 *)(object+0x34);
  if(!child) goto fallback;
  u32 index=*(u8 *)(*(u32 *)(child+0x48c)+0x1af);
  if(index>=5) goto fallback;
  goto *D_0036b2ec[index];
case2: return 0x31;
case3: return 0x8b;
fallback: return 0x19;
}
