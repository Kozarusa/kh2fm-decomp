#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_001688b8(void);
extern "C" bool func_0019ba60(u64);
extern "C" bool func_001c0cd8(s32);
extern "C" bool func_001d35e0(u64,void*,void*,u64);
extern "C" f32 func_0016b558(u64,u64);
extern "C" s32 func_0016b740(...);
extern "C" s32 func_0016c028(s32);
extern "C" s32 func_00170240(...);
extern "C" s32 func_00177860(...);
extern "C" s32 func_00188fe0(...);
extern "C" s32 func_00189200(s32,s32);
extern "C" s32 func_001b9bc8(s32);
extern "C" s64 func_0016bba8(...);
extern "C" s64 func_00170400(u64,s64,s64);
extern "C" u16 func_0016a070(s32);
extern "C" u16 func_0016bff0(s32);
extern "C" u32 func_00102c18(u64,u64,u64);
extern "C" u32 func_00104f58(void*,u64,s64,u8,s64);
extern "C" u32 func_0014d358(u32,u32,u32,u32);
extern "C" u32 func_00152508(u64,u64,u64,u64,u32);
extern "C" u32 func_00167d68(u64);
extern "C" u32 func_00167f18(s32);
extern "C" u32 func_0016a020(s32);
extern "C" u32 func_0016ace0(u64,void*);
extern "C" u32 func_0016adc8(...);
extern "C" u32 func_0016aeb8(...);
extern "C" u32 func_0016b010(s32,void*);
extern "C" u32 func_0016c018(s32,s32,u32);
extern "C" u32 func_0016c568(...);
extern "C" u32 func_00170c50(void);
extern "C" u32 func_00170e58(void);
extern "C" u32 func_00176db0(...);
extern "C" u32 func_00177998(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017d160(...);
extern "C" u32 func_0017f488(u32,u32,u64,u64);
extern "C" s32 func_00180378(f32,s32,s32,s32);
extern "C" u32 func_001846a0(...);
extern "C" u32 func_00185278(...);
extern "C" u32 func_00186a90(...);
extern "C" u32 func_00188b68(s32,u16,s8);
extern "C" u32 func_001891b8(s32,u16);
extern "C" u32 func_001945a0(u32,s32,u64,u64);
extern "C" u32 func_0019a1a0(s32,s64);
extern "C" u32 func_0019ae60(s32);
extern "C" u32 func_0019fdc0(...);
extern "C" u32 func_001a0710(...);
extern "C" u32 func_001a55a8(u64,u64);
extern "C" u32 func_001a7588(...);
extern "C" u32 func_001b0700(...);
extern "C" u32 func_001b0798(u32,void*,u64,u32);
extern "C" u32 func_001b2210(...);
extern "C" u32 func_001b6dd0(u64,void*);
extern "C" u32 func_001ce300(s32);
extern "C" u32 func_001ce328(u64);
extern "C" u32 func_001cfac0(f32,f32,f32,f32,s32);
extern "C" u32 func_001dc648(s32);
extern "C" u32 func_001dc670(s32);
extern "C" u32 func_002ba200(void);
extern "C" u32 func_002f8ad0(...);
extern "C" u32 func_002fee78(...);
extern "C" u64 func_0016bda8(u64,u64);
extern "C" u64 func_0017d050(u64,void*);
extern "C" u64 func_0017d0e8(...);
extern "C" u64 func_0019b0e8(u32,f32,u64,u64,u64);
extern "C" u8 func_0016a040(s32);
extern "C" u8 func_001c3618(s32,s32);

// Preserve the original load order and call-bank registers; types remain provisional.

void func_00172440(int *param_1) {
 register int *saved asm("$16") = param_1;
 register u32 source asm("$14");
 register u32 object asm("$15");
 register s32 third asm("$6");
 register s32 first asm("$4") = (s32)param_1;
 register f32 value asm("$f12");
 register s32 second asm("$5");
 asm volatile("lw %0,4(%3); lw %1,0(%3); lw %2,8(%6); lw %3,4(%1); lwc1 %4,12(%6); lw %5,4(%0)" : "=r"(source), "=r"(object), "=r"(third), "+r"(first), "=f"(value), "=r"(second) : "r"(saved) : "memory");
 *saved = func_00180378(value,first+0x140,second,third);
}
