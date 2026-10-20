#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_001a1de0(s32);
extern "C" f32 func_00166d10(s32,s32);
extern "C" s32 func_00132130(...);
extern "C" s32 func_0013d7e0(...);
extern "C" s32 func_0014e648(s32);
extern "C" s32 func_0016c028(s32);
extern "C" u32 func_001024a8(void*);
extern "C" u32 func_00102818(u64,u64,u64,u64,s32);
extern "C" u32 func_00102c18(u64,u64,u64);
extern "C" u32 func_00102c80(void);
extern "C" u32 func_001050c8(void);
extern "C" u32 func_001058e8(void);
extern "C" u32 func_0011c4b0(...);
extern "C" u32 func_0011c4e8(...);
extern "C" u32 func_001320b0(...);
extern "C" u32 func_00132208(...);
extern "C" u32 func_00138c10(s32,u32);
extern "C" u32 func_00138d60(...);
extern "C" u32 func_001391c8(s32,u64,u32);
extern "C" u32 func_0013a4c8(void);
extern "C" u32 func_0013a600(void);
extern "C" u32 func_0013a6d0(void);
extern "C" u32 func_0013a7d0(s32);
extern "C" u32 func_0013a7e8(s32);
extern "C" u32 func_0013a9e8(u8);
extern "C" u32 func_0013efe8(void);
extern "C" u32 func_0013f030(void);
extern "C" u32 func_0013f608(...);
extern "C" u32 func_0013f888(...);
extern "C" u32 func_0013fca8(s32);
extern "C" u32 func_00142940(...);
extern "C" u32 func_00144450(...);
extern "C" u32 func_00144908(void*,void*);
extern "C" u32 func_001492c8(s32);
extern "C" u32 func_001493b8(u64);
extern "C" u32 func_00149428(u64);
extern "C" u32 func_00149448(s32);
extern "C" u32 func_00149bd0(s32);
extern "C" u32 func_00149de0(u64);
extern "C" u32 func_0014a9a0(...);
extern "C" u32 func_0014aa80(s32,u64,u8);
extern "C" u32 func_0014aba8(void);
extern "C" u32 func_0014ae10(void);
extern "C" u32 func_0014b5e8(s32,u64,u64);
extern "C" u32 func_0014dd60(s32,u8,u8,u8);
extern "C" u32 func_0014f148(void);
extern "C" u32 func_0014f1e0(void);
extern "C" u32 func_0014f220(void);
extern "C" u32 func_0014f288(void);
extern "C" u32 func_00150be8(...);
extern "C" u32 func_00151d48(...);
extern "C" u32 func_00153c80(void);
extern "C" u32 func_00154408(...);
extern "C" u32 func_00154cd0(f32,s32,s32);
extern "C" u32 func_00155d58(s32,s32);
extern "C" u32 func_00155f40(...);
extern "C" u32 func_00156408(...);
extern "C" u32 func_001574a0(s32);
extern "C" u32 func_00159ce0(s32,s64);
extern "C" u32 func_0015a850(void);
extern "C" u32 func_0015eba8(u64,u64,u8,u64);
extern "C" u32 func_0015edb8(void);
extern "C" u32 func_001616d8(...);
extern "C" u32 func_00165968(void);
extern "C" u32 func_00166618(u64,u16,u16,s16,u16,u16,s32);
extern "C" u32 func_001666a0(...);
extern "C" u32 func_001666d0(void*,u16,u32,u16,u16);
extern "C" u32 func_001666f0(void*,u16,u32,u16,u16);
extern "C" u32 func_00166d38(s64);
extern "C" u32 func_00167658(void*,u64);
extern "C" u32 func_001676b0(void*,u64);
extern "C" u32 func_001678f0(u64);
extern "C" u32 func_00167e00(s32);
extern "C" u32 func_00168b38(void*,u32,s32);
extern "C" u32 func_0016b0d0(void);
extern "C" u32 func_0016cbc8(u64,u64,u64,u64);
extern "C" u32 func_0016cce8(u64,u64,u64,u64,u64);
extern "C" u32 func_0017df58(s32);
extern "C" u32 func_001a98e8(u64,u64,u32,u64,u32);
extern "C" u32 func_001a9ae8(u64,s32,s32,u32);
extern "C" u32 func_001b7e68(void*,s64);
extern "C" u32 func_001b7f30(void*);
extern "C" u32 func_001b80d8(u64);
extern "C" u32 func_001dc5f8(s32);
extern "C" u32 func_002362b0(s32,s32);
extern "C" u32 func_00239988(...);
extern "C" u32 func_00239bf8(s32,s32);
extern "C" u32 func_0023aa78(...);
extern "C" u32 func_00242b58(void);
extern "C" u32 func_002bea00(void);
extern "C" u32 func_002fee78(...);
extern "C" u64 func_00102788(u64,u64,u64,u64);
extern "C" u64 func_0014ca80(...);
extern "C" u64 func_0015c228(...);
extern "C" u64 func_00167cd0(...);
extern "C" u64 func_0016abf8(s32,u64,u64,u64);
extern "C" u64 func_0016d080(u64,u64);
extern "C" u64 func_00192cc0(...);

void func_0014b4b0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5)

{
  param_3 &= 0xffff; asm("" : : "r"(param_3));
  func_0014b5e8(param_1,(s64)(int)((param_2 & 0xffff) * 0x10 + 8) |
                       (s64)(int)((param_4 & 0xffff) * 0x10 + 8) << 0x10,
               (s64)(int)((param_3 & 0xffff) * 0x10 + 8) |
               (s64)(int)((param_5 & 0xffff) * 0x10 + 8) << 0x10);
  return;
}
