#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_0010cc80(...);
extern "C" bool func_00112720(...);
extern "C" bool func_00112d28(...);
extern "C" bool func_0013ba50(...);
extern "C" bool func_00228378(...);
extern "C" f32 func_0017ce10(...);
extern "C" s32 func_00106520(...);
extern "C" s32 func_001317a8(...);
extern "C" s32 func_0013d7e0(...);
extern "C" s32 func_001a35f8(...);
extern "C" s32 func_001b9bc8(...);
extern "C" s32 func_00147050(...);
extern "C" u16 func_0016a070(...);
extern "C" u32 func_001022e8(...);
extern "C" u32 func_00102818(...);
extern "C" u32 func_00102c80(...);
extern "C" u32 func_001069b8(...);
extern "C" u32 func_00106a60(...);
extern "C" u32 func_00109330(...);
extern "C" u32 func_00109340(...);
extern "C" u32 func_0010a800(...);
extern "C" u32 func_00111e38(...);
extern "C" u32 func_0011ac10(...);
extern "C" u32 func_0011b6a8(...);
extern "C" u32 func_0011cd80(...);
extern "C" u32 func_0011ee98(...);
extern "C" u32 func_0011ef70(...);
extern "C" u32 func_00127f40(...);
extern "C" u32 func_001316f0(...);
extern "C" u32 func_001320f0(...);
extern "C" u32 func_00132208(...);
extern "C" u32 func_001325c8(...);
extern "C" u32 func_00133570(...);
extern "C" u32 func_00133590(...);
extern "C" u32 func_00133ba0(...);
extern "C" u32 func_00133bb8(...);
extern "C" u32 func_00133c60(...);
extern "C" u32 func_00133ea8(...);
extern "C" u32 func_00133f20(...);
extern "C" u32 func_00133f60(...);
extern "C" u32 func_00134258(...);
extern "C" u32 func_00135ad0(...);
extern "C" u32 func_00135c50(...);
extern "C" u32 func_001386e0(...);
extern "C" u32 func_00138c10(...);
extern "C" u32 func_00138d60(...);
extern "C" u32 func_001391a8(...);
extern "C" u32 func_001391c8(...);
extern "C" u32 func_00139510(...);
extern "C" u32 func_00139598(...);
extern "C" u32 func_00139708(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0013a7e8(...);
extern "C" u32 func_0013efe8(...);
extern "C" u32 func_0013f030(...);
extern "C" u32 func_0013f558(...);
extern "C" u32 func_0013fcd8(...);
extern "C" u32 func_00141928(...);
extern "C" u32 func_00143d10(...);
extern "C" u32 func_00144d90(...);
extern "C" u32 func_00145c68(...);
extern "C" u32 func_00147c78(...);
extern "C" u32 func_0014ed28(...);
extern "C" u32 func_0015ce90(...);
extern "C" u32 func_0015ced0(...);
extern "C" u32 func_0015cee0(...);
extern "C" u32 func_001688c8(...);
extern "C" u32 func_0016aef0(...);
extern "C" u32 func_0016bd60(...);
extern "C" u32 func_00170b30(...);
extern "C" u32 func_00176dd8(...);
extern "C" u32 func_00190140(...);
extern "C" u32 func_00190878(...);
extern "C" u32 func_001a3868(...);
extern "C" u32 func_001dc5f0(...);
extern "C" u32 func_002362b0(...);
extern "C" u32 func_002367c8(...);
extern "C" u32 func_002f8ad0(...);
extern "C" u32 func_00313b80(...);
extern "C" u32 func_003142e0(...);
extern "C" u32 func_00102788(...);
extern "C" u32 func_001094e0(...);
extern "C" u32 func_0011f2f0(...);
extern "C" u32 func_00132c68(...);
extern "C" u32 func_00133f80(...);
extern "C" u32 func_0015cea0(...);
extern "C" u32 func_0015ceb8(...);
extern "C" u32 func_0016af58(...);
extern "C" u8 func_0015ce80(...);

u32 func_0010f748(int param_1,u32 param_2)

{
  int iVar1;
  bool bVar2;
  u32 uVar3;
  s32 lVar4;
  
  bVar2 = false;
  if ((*(int *)(param_1 + 0xc) != 0) &&
     (((iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 4), iVar1 == 0 || (iVar1 == 0x1f)) &&
      (bVar2 = false, (*(u32 *)(param_1 + 0x160) & 4) != 0)))) {
    asm volatile ("" : "+r"(bVar2) :: "memory");
    uVar3 = func_0016a070();
    lVar4 = func_001a35f8(param_2,uVar3);
    bVar2 = 0 < lVar4;
  }
  return bVar2;
}
