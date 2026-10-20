#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_0010cc80(...);
extern "C" bool func_00112720(...);
extern "C" bool func_00112d28(s64);
extern "C" bool func_0013ba50(...);
extern "C" bool func_00228378(void);
extern "C" f32 func_0017ce10(f32);
extern "C" s32 func_00106520(s32,s32);
extern "C" s32 func_001317a8(...);
extern "C" s32 func_0013d7e0(void);
extern "C" s32 func_001a35f8(u64,s64);
extern "C" s32 func_001b9bc8(s32);
extern "C" s64 func_00147050(u64,s64,u64,s32,u64);
extern "C" u16 func_0016a070(...);
extern "C" u32 func_001022e8(u64);
extern "C" u32 func_00102818(u64,u64,u64,u64,s32);
extern "C" u32 func_00102c80(void);
extern "C" u32 func_001069b8(u32);
extern "C" u32 func_00106a60(s8);
extern "C" u32 func_00109330(void);
extern "C" u32 func_00109340(void);
extern "C" u32 func_0010a800(void*,void*,void*);
extern "C" u32 func_00111e38(s32);
extern "C" u32 func_0011ac10(u64);
extern "C" u32 func_0011b6a8(void*);
extern "C" u32 func_0011cd80(u64,u64,u64,u64,u64,u64);
extern "C" u32 func_0011ee98(...);
extern "C" u32 func_0011ef70(...);
extern "C" u32 func_00127f40(...);
extern "C" u32 func_001316f0(...);
extern "C" u32 func_001320f0(...);
extern "C" u32 func_00132208(s64);
extern "C" u32 func_001325c8(u64,u32,u32);
extern "C" u32 func_00133570(...);
extern "C" u32 func_00133590(...);
extern "C" u32 func_00133ba0(...);
extern "C" u32 func_00133bb8(...);
extern "C" u32 func_00133c60(...);
extern "C" u32 func_00133ea8(void);
extern "C" u32 func_00133f20(...);
extern "C" u32 func_00133f60(void);
extern "C" u32 func_00134258(...);
extern "C" u32 func_00135ad0(s32);
extern "C" u32 func_00135c50(...);
extern "C" u32 func_001386e0(u64,u64,u64,u64,u64,u64);
extern "C" u32 func_00138c10(s32,u32);
extern "C" u32 func_00138d60(...);
extern "C" u32 func_001391a8(s32,void*);
extern "C" u32 func_001391c8(s32,u64,u32);
extern "C" u32 func_00139510(s32);
extern "C" u32 func_00139598(s32);
extern "C" u32 func_00139708(s32);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0013a7e8(s32);
extern "C" u32 func_0013efe8(void);
extern "C" u32 func_0013f030(void);
extern "C" u32 func_0013f558(u64);
extern "C" u32 func_0013fcd8(u64,void*);
extern "C" u32 func_00141928(s32,s8);
extern "C" u32 func_00143d10(u64,u64,void*,void*);
extern "C" u32 func_00144d90(void*,void*);
extern "C" u32 func_00145c68(s32,s8);
extern "C" u32 func_00147c78(...);
extern "C" u32 func_0014ed28(u64,u64);
extern "C" u32 func_0015ce90(void);
extern "C" u32 func_0015ced0(void);
extern "C" u32 func_0015cee0(void);
extern "C" u32 func_001688c8(...);
extern "C" u32 func_0016aef0(u64,u64);
extern "C" u32 func_0016bd60(u64,u64);
extern "C" u32 func_00170b30(...);
extern "C" u32 func_00176dd8(s32,s32,void*,u16);
extern "C" u32 func_00190140(...);
extern "C" u32 func_00190878(void*,u32,u32);
extern "C" u32 func_001a3868(...);
extern "C" u32 func_001dc5f0(s32);
extern "C" u32 func_002362b0(...);
extern "C" u32 func_002367c8(...);
extern "C" u32 func_002f8ad0(...);
extern "C" u32 func_00313b80(u32);
extern "C" u32 func_003142e0(u64,u64);
extern "C" u64 func_00102788(u64,u64,u64,u64);
extern "C" u64 func_001094e0(...);
extern "C" u64 func_0011f2f0(...);
extern "C" u64 func_00132c68(...);
extern "C" u64 func_00133f80(void);
extern "C" u64 func_0015cea0(u64);
extern "C" u64 func_0015ceb8(u64);
extern "C" u64 func_0016af58(u64,u64);
extern "C" u8 func_0015ce80(void);

void func_001025f8(int param_1,int param_2)

{
  int iVar1;
  u32 uVar2;
  
  if (param_2 == *(int *)(param_1 + 0x110)) {
    if (param_2 == 0) {
      uVar2 = *(u32 *)(param_1 + 8);
    }
    else {
      uVar2 = *(u32 *)(param_2 + 0x38);
    }
    *(u32 *)(param_1 + 0x110) = uVar2;
    iVar1 = *(int *)(param_2 + 0x3c);
  }
  else {
    iVar1 = *(int *)(param_2 + 0x3c);
  }
  if (iVar1 == 0) {
    *(u32 *)(param_1 + 8) = *(u32 *)(param_2 + 0x38);
  }
  else {
    *(u32 *)(iVar1 + 0x38) = *(u32 *)(param_2 + 0x38);
  }
  if (*(int *)(param_2 + 0x38) == 0) {
    *(u32 *)(param_1 + 0xc) = *(u32 *)(param_2 + 0x3c);
  }
  else {
    *(u32 *)(*(int *)(param_2 + 0x38) + 0x3c) = *(u32 *)(param_2 + 0x3c);
  }
  *(u32 *)(param_2 + 0x3c) = 0;
  *(u32 *)(param_2 + 0x38) = 0;
  func_001022e8(param_2);
  return;
}

void func_00108600(u32 *param_1)

{
  *param_1 = 0;
  *(u8 *)((int)param_1 + 7) = 0x80;
  *(u8 *)((int)param_1 + 6) = 0x80;
  *(u8 *)((int)param_1 + 5) = 0x80;
  *(u8 *)(param_1 + 1) = 0x80;
  func_0010a800(param_1 + 2,(int)param_1 + 9,(int)param_1 + 10);
  *(u8 *)((int)param_1 + 0x29) = 0x80;
  *(u8 *)((int)param_1 + 0xb) = 0xff;
  *(u8 *)((int)param_1 + 0x2b) = 0x80;
  *(u8 *)((int)param_1 + 0x2a) = 0x80;
  *(u64 *)(param_1 + 4) = 0x800d8;
  *(u64 *)(param_1 + 6) = 0x31000070;
  param_1[0xd] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *(u8 *)(param_1 + 10) = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  return;
}

void func_00108698(u32 *param_1)

{
  *param_1 = 0;
  *(u8 *)((int)param_1 + 7) = 0x80;
  *(u8 *)((int)param_1 + 6) = 0x80;
  *(u8 *)((int)param_1 + 5) = 0x80;
  *(u8 *)(param_1 + 1) = 0x80;
  func_0010a800(param_1 + 2,(int)param_1 + 9,(int)param_1 + 10);
  *(u8 *)((int)param_1 + 0x29) = 0x80;
  *(u8 *)((int)param_1 + 0xb) = 0xff;
  *(u8 *)((int)param_1 + 0x2b) = 0x80;
  *(u8 *)((int)param_1 + 0x2a) = 0x80;
  *(u64 *)(param_1 + 4) = 0x800d8;
  *(u64 *)(param_1 + 6) = 0x31000070;
  param_1[0xd] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *(u8 *)(param_1 + 10) = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  return;
}

void func_00109690(u32 param_1)

{
  u64 *puVar1;
  
  puVar1 = (u64 *)func_00133ba0(param_1,2,0x13000000);
  puVar1[2] = 0;
  *(u32 *)puVar1 = 0;
  *(u32 *)((int)puVar1 + 4) = 0;
  *(u32 *)(puVar1 + 1) = 0;
  *(u32 *)((int)puVar1 + 0xc) = 0;
  puVar1[1] = puVar1[1] & 0xfffffffffffffff0 | 0xe;
  *puVar1 = *puVar1 & 0xfffffffffff8000 | 0x1000000000008001;
  puVar1[3] = 0x3f;
  return;
}

bool func_00109788(u32 param_1,u32 param_2)

{
  s64 lVar1;
  
  lVar1 = func_001094e0(param_2);
  if (lVar1 == 0) {
    func_00133c60(param_1,param_2,0,0,0);
  }
  return lVar1 == 0;
}

u64 func_00109e30(char param_1)

{
  u64 uVar1;
  
  if (param_1 == '\0') {
    uVar1 = func_00133f60();
  }
  else {
    uVar1 = func_00133f80();
  }
  func_00133ea8();
  func_00109330();
  func_00109340();
  return uVar1;
}

void func_0010cbc8(u32 param_1,u32 param_2,int param_3,u32 param_4)

{
  u64 uVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if (param_3 != 0) {
    *(u32 *)(iVar2 + 0xb78) = 0;
    if (*(int *)(iVar2 + 0x9f4) != param_3) {
      func_00190878(iVar2 + 0x9f4,param_3,0);
    }
    uVar1 = func_001a3868(param_2);
    func_00176dd8(param_1,uVar1,iVar2 + 0x9f4,param_4);
    return;
  }
  return;
}

s64 func_0010cce0(s32 param_1)

{
  s64 lVar1;
  
  do {
    param_1 = func_001b9bc8(param_1);
    if (param_1 == 0) {
      return 0;
    }
    lVar1 = func_00112d28(param_1);
  } while (lVar1 == 0);
  return param_1;
}

bool func_0010f748(int param_1,u32 param_2)

{
  int iVar1;
  bool bVar2;
  u64 uVar3;
  s64 lVar4;
  
  bVar2 = false;
  if ((*(int *)(param_1 + 0xc) != 0) &&
     (((iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 4), iVar1 == 0 || (iVar1 == 0x1f)) &&
      (bVar2 = false, (*(u32 *)(param_1 + 0x160) & 4) != 0)))) {
    uVar3 = func_0016a070();
    lVar4 = func_001a35f8(param_2,uVar3);
    bVar2 = 0 < lVar4;
  }
  return bVar2;
}

void func_0010f918(int param_1)

{
  if (*(int *)(*(int *)(param_1 + 0xc) + 4) != 0x20) {
    *(u32 *)(param_1 + 0xb7c) = *(u32 *)(param_1 + 0xb7c) & 0xffffbfff;
    return;
  }
  func_0016bd60(param_1,0x1f);
  return;
}

void func_0010f960(int param_1)

{
  if (*(int *)(*(int *)(param_1 + 0xc) + 4) != 0x1f) {
    *(u32 *)(param_1 + 0xb7c) = *(u32 *)(param_1 + 0xb7c) | 0x4000;
    return;
  }
  func_0016bd60(param_1,0x20);
  return;
}

int func_0010fea0(int param_1)

{
  s64 lVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  lVar1 = func_00112720();
  if (lVar1 == 0) {
    piVar2 = (int *)(param_1 + 0xc58);
    iVar3 = 1;
    iVar4 = *piVar2;
    while (piVar2 = piVar2 + 1, *(int *)(param_1 + 0xc54) == iVar4) {
      iVar3 = iVar3 + 1;
      if (2 < iVar3) {
        return *(int *)(param_1 + 0xc54);
      }
      iVar4 = *piVar2;
    }
  }
  return 0;
}

u64 func_00112d90(int *param_1)

{
  bool bVar1;
  s64 lVar2;
  u64 uVar3;
  
  bVar1 = false;
  lVar2 = func_00190140();
  uVar3 = 0;
  if (lVar2 != 0) {
    bVar1 = *param_1 != 0;
  }
  if (bVar1) {
    uVar3 = func_00112d28(*param_1);
  }
  return uVar3;
}

void func_001168c0(int param_1)

{
  u64 uVar1;
  s64 lVar2;
  u32 uVar3;
  float fVar4;
  
  uVar1 = func_00313b80(*(u32 *)(param_1 + 0x660));
  lVar2 = func_003142e0(uVar1,0);
  if (lVar2 == 0) {
    uVar1 = func_00313b80(*(u32 *)(param_1 + 0x664));
    lVar2 = func_003142e0(uVar1,0);
    if (lVar2 == 0) {
      return;
    }
    fVar4 = *(float *)(param_1 + 0x664);
  }
  else {
    fVar4 = *(float *)(param_1 + 0x664);
  }
  uVar3 = func_002f8ad0(*(u32 *)(param_1 + 0x660),-fVar4);
  *(u32 *)(param_1 + 0x65c) = uVar3;
  return;
}

void func_0011b038(u32 param_1)

{
  u64 uVar1;
  int iVar2;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  uVar1 = func_00111e38(0);
  func_0011ac10(param_1);
  iVar2 = func_00106a60(1);
  uStack_28 = *(u32 *)(iVar2 + 0x38);
  uStack_30 = *(u32 *)(iVar2 + 0x18);
  uStack_24 = 0;
  uStack_2c = 0;
  func_0016aef0(uVar1,&uStack_30);
  return;
}

u64 func_00127d40(u32 param_1)

{
  u64 uVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0x90) == 0) {
    func_00127f40(iVar2,iVar2 + 0x90);
    uVar1 = param_1;
  }
  else {
    uVar1 = 0;
    if (*(int *)(iVar2 + 0x90) == 1) {
      func_001316f0(iVar2,iVar2 + 0x90);
      uVar1 = param_1;
    }
  }
  return uVar1;
}

u32 func_00131918(int param_1,u32 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  u32 uVar10;
  u32 uVar11;
  u32 uVar12;
  u32 uVar13;
  u32 uVar14;
  u32 uVar15;
  u32 uVar16;
  u32 uVar17;
  u32 uVar18;
  u32 *puVar19;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 0x2c);
  if (iVar2 == 0) {
    func_0011b6a8(param_2);
    uVar4 = 1;
  }
  else {
    iVar3 = func_001317a8();
    puVar19 = (u32 *)(iVar1 + iVar2 + iVar3 * 0x40);
    if (param_2 == puVar19) {
      uVar4 = 0;
    }
    else {
      uVar4 = puVar19[1];
      uVar5 = puVar19[2];
      uVar6 = puVar19[3];
      uVar7 = puVar19[4];
      uVar8 = puVar19[5];
      uVar9 = puVar19[6];
      uVar10 = puVar19[7];
      uVar11 = puVar19[8];
      uVar12 = puVar19[9];
      uVar13 = puVar19[10];
      uVar14 = puVar19[0xb];
      uVar15 = puVar19[0xc];
      uVar16 = puVar19[0xd];
      uVar17 = puVar19[0xe];
      uVar18 = puVar19[0xf];
      *param_2 = *puVar19;
      param_2[1] = uVar4;
      param_2[2] = uVar5;
      param_2[3] = uVar6;
      param_2[4] = uVar7;
      param_2[5] = uVar8;
      param_2[6] = uVar9;
      param_2[7] = uVar10;
      param_2[8] = uVar11;
      param_2[9] = uVar12;
      param_2[10] = uVar13;
      param_2[0xb] = uVar14;
      param_2[0xc] = uVar15;
      param_2[0xd] = uVar16;
      param_2[0xe] = uVar17;
      param_2[0xf] = uVar18;
      uVar4 = 0;
    }
  }
  return uVar4;
}

int func_00132130(int param_1)

{
  int iVar1;
  s64 lVar2;
  
  iVar1 = func_001320f0();
  param_1 = param_1 + iVar1 + 8;
  lVar2 = func_00132208(param_1);
  if (lVar2 == 0) {
    param_1 = 0;
  }
  return param_1;
}

void func_00132720(int param_1,int param_2)

{
  u64 uVar1;
  float fVar2;
  
  if (*(int *)(param_1 + 0x278) != param_2) {
    if (param_2 == 0) {
      *(u32 *)(param_1 + 0x278) = 0;
    }
    else {
      *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 1;
      uVar1 = func_00106520(*(u16 *)(param_2 + 2),*(u16 *)(param_2 + 4) + 1);
      if ((s64)uVar1 < 0) {
        fVar2 = (float)(uVar1 & 0xffffffff);
      }
      else {
        fVar2 = (float)(int)uVar1;
      }
      *(float *)(param_1 + 0x280) = fVar2;
      *(u32 *)(param_1 + 0x284) = 0;
      *(int *)(param_1 + 0x278) = param_2;
    }
    *(int *)(param_1 + 0x27c) = param_2;
  }
  return;
}

void func_00132ec0(u32 param_1,u32 param_2)

{
  int iVar1;
  s64 lVar2;
  
  lVar2 = func_00132c68();
  iVar1 = (int)lVar2;
  if (lVar2 != 0) {
    lVar2 = func_001325c8(param_1,0xffff,param_2);
    if (-1 < lVar2) {
      *(int *)((int)param_1 + 0x274) =
           iVar1 + *(int *)((int)lVar2 * 4 + iVar1 + *(int *)(iVar1 + 0x1c));
    }
  }
  return;
}

void func_00132f38(u32 param_1)

{
  int iVar1;
  s64 lVar2;
  
  iVar1 = func_00132c68();
  lVar2 = func_001325c8(param_1,0,*(u32 *)(iVar1 + 0x24));
  if (-1 < lVar2) {
    *(int *)((int)param_1 + 0x274) =
         iVar1 + *(int *)((int)lVar2 * 4 + iVar1 + *(int *)(iVar1 + 0x1c));
  }
  return;
}

void func_001344b8(u32 param_1)

{
  func_00133bb8(0x347c88,0,param_1 | 0x3000000,0x400U - (int)param_1 >> 1 | 0x2000000);
  return;
}

void func_00134508(int param_1,s32 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    func_00133570(0x347c88);
  }
  if ((param_2 == 0xffff) && (param_1 == 0)) {
    func_00133590(0x347c88);
    return;
  }
  return;
}

void func_00135bd0(u32 param_1,u32 param_2)

{
  int iVar1;
  int iVar2;
  
  func_00135c50();
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 0xc);
  if (iVar1 == 0x20) {
    func_00135ad0(param_1);
    iVar1 = *(int *)(iVar2 + 0xc);
    if (iVar1 == 0x20) {
      func_00135c50(param_1,*(u32 *)(iVar2 + 0x10));
      iVar1 = *(int *)(iVar2 + 0xc);
    }
  }
  *(u32 *)(iVar1 * 4 + iVar2 + 0x10) = param_2;
  *(int *)(iVar2 + 0xc) = iVar1 + 1;
  return;
}

int func_001362a0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = param_1;
  if (0 < iVar1) {
    do {
      if (*(int *)(iVar2 + 0x10) == param_2) {
        iVar1 = func_001dc5f0(param_2);
        if (*(int *)(iVar2 + 0x14) == iVar1) {
          return iVar3;
        }
        iVar1 = *(int *)(param_1 + 0xc);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 8;
    } while (iVar3 < iVar1);
  }
  return -1;
}

void func_001374c8(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                 u32 param_5)

{
  u64 uVar1;
  u64 uVar2;
  int iVar3;
  
  uVar1 = func_0013a7e8(1);
  uVar2 = func_0013d7e0();
  func_00138d60(param_2,0x2b5c,uVar1,uVar2,param_3,param_4,0xd);
  iVar3 = (int)param_2;
  *(u32 *)(iVar3 + 0x1b8) = param_5;
  *(u32 *)(iVar3 + 0x1b4) = param_1;
  *(u32 *)(iVar3 + 0x1a8) = 0x10;
  return;
}

void func_00137c50(int param_1)

{
  *(u32 *)(param_1 + 0x29c8) = 0;
  *(u32 *)(param_1 + 0x29c0) = 1;
  *(u32 *)(param_1 + 0x20) = 1;
  *(u32 *)(param_1 + 0x30) = 0;
  *(u32 *)(param_1 + 0x34) = 0;
  *(u32 *)(param_1 + 0x29c4) = 0;
  func_001391c8(param_1,0x2b5c,0);
  return;
}

u32 func_0013b9e0(int param_1,s32 param_2)

{
  s64 lVar1;
  u32 uVar2;
  
  lVar1 = func_0013ba50();
  uVar2 = 0;
  if (((lVar1 == 0) &&
      (((param_2 != 0 || (uVar2 = 1, *(int *)(param_1 + 0xec) != 6)) && (uVar2 = 0, param_2 == 6))))
     && (uVar2 = 1, *(int *)(param_1 + 0xec) != 0)) {
    uVar2 = 0;
  }
  return uVar2;
}

void func_0013e2d8(u32 param_1,u32 param_2,u32 param_3)

{
  u64 uVar1;
  int iVar2;
  
  *(int *)((int)param_1 + 0x1b4) = (int)param_2;
  iVar2 = (int)param_1 + 0x1c0;
  uVar1 = func_0013a7e8(0);
  func_001386e0(param_1,4000,uVar1,param_3,param_2,0x11);
  uVar1 = func_0013a7e8(0);
  func_001386e0(iVar2,4000,uVar1,param_3,0x14,0x11);
  func_00139598(iVar2);
  func_00139708(iVar2);
  return;
}

void func_0013e3b0(u32 param_1,u32 *param_2)

{
  s64 lVar1;
  int iVar2;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  uStack_30 = *param_2;
  uStack_2c = param_2[1];
  uStack_28 = param_2[2];
  uStack_24 = param_2[3];
  iVar2 = (int)param_1 + 0x1c0;
  func_001391a8(param_1,&uStack_30);
  lVar1 = func_00139d78(iVar2);
  if (lVar1 != 0) {
    uStack_30 = *param_2;
    uStack_2c = param_2[1];
    uStack_28 = param_2[2];
    uStack_24 = param_2[3];
    func_001391a8(iVar2,&uStack_30);
  }
  return;
}

void func_0013e4b8(u32 param_1)

{
  s64 lVar1;
  int iVar2;
  
  iVar2 = (int)param_1 + 0x1c0;
  lVar1 = func_00139d78();
  if (lVar1 != 0) {
    func_00138c10(param_1,*(int *)((int)param_1 + 0x184) + -1);
    lVar1 = func_00139d78(iVar2);
    if (lVar1 != 0) {
      func_00139510(iVar2);
      return;
    }
  }
  return;
}

void func_0013f498(void)

{
  int iVar1;
  
  func_0013efe8();
  iVar1 = func_00102c80();
  func_00102788(*(u32 *)(iVar1 + 4),0,300000,0x13f428);
  return;
}

void func_0013f4d8(void)

{
  int iVar1;
  
  func_0013f030();
  iVar1 = func_00102c80();
  func_00102818(*(u32 *)(iVar1 + 4),1,300000,0x13f450,0x1000);
  return;
}

void func_0013f608(int param_1)

{
  u32 uVar1;
  
  *(u32 *)(param_1 + 0xa4) = *(u32 *)(param_1 + 0x34);
  *(u32 *)(param_1 + 0xa0) = *(u32 *)(param_1 + 0x30);
  uVar1 = func_0017ce10(*(u32 *)(param_1 + 0x34));
  *(u32 *)(param_1 + 0xa4) = uVar1;
  return;
}

void func_0013fd10(u32 param_1)

{
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  func_0016af58(&uStack_30,*(u32 *)((int)param_1 + 0x44));
  if (&uStack_40 != &uStack_30) {
    uStack_40 = uStack_30;
    uStack_3c = uStack_2c;
    uStack_38 = uStack_28;
    uStack_34 = uStack_24;
  }
  uStack_30 = uStack_40;
  uStack_2c = uStack_3c;
  uStack_28 = uStack_38;
  uStack_24 = uStack_34;
  func_0013fcd8(param_1,&uStack_30);
  return;
}

void func_00140480(u32 *param_1)

{
  s64 lVar1;
  u32 uStack_60;
  u32 uStack_5c;
  u32 uStack_58;
  u32 uStack_54;
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u32 uStack_44;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u8 auStack_30 [4];
  u32 auStack_2c [3];
  
  if (&uStack_60 != param_1) {
    uStack_60 = *param_1;
    uStack_5c = param_1[1];
    uStack_58 = param_1[2];
    uStack_54 = param_1[3];
  }
  if (&uStack_50 != param_1 + 4) {
    uStack_50 = param_1[4];
    uStack_4c = param_1[5];
    uStack_48 = param_1[6];
    uStack_44 = param_1[7];
  }
  auStack_2c[0] = 0;
  lVar1 = func_00143d10(&uStack_60,&uStack_40,auStack_30,auStack_2c);
  if ((lVar1 != 0) && (param_1 != &uStack_40)) {
    *param_1 = uStack_40;
    param_1[1] = uStack_3c;
    param_1[2] = uStack_38;
    param_1[3] = uStack_34;
  }
  return;
}

void func_001407d0(u32 *param_1)

{
  s64 lVar1;
  u32 uVar2;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  lVar1 = func_0015ce80();
  if (lVar1 != 0) {
    func_0015ceb8(&uStack_30);
    if (param_1 != &uStack_30) {
      *param_1 = uStack_30;
      param_1[1] = uStack_2c;
      param_1[2] = uStack_28;
      param_1[3] = uStack_24;
    }
    func_0015cea0(&uStack_30);
    if (param_1 + 4 != &uStack_30) {
      param_1[4] = uStack_30;
      param_1[5] = uStack_2c;
      param_1[6] = uStack_28;
      param_1[7] = uStack_24;
    }
    uVar2 = func_0015ced0();
    param_1[8] = uVar2;
    uVar2 = func_0015cee0();
    param_1[9] = uVar2;
    func_0015ce90();
  }
  return;
}

void func_00140ce8(void)

{
  int iVar1;
  
  func_0015ce90();
  func_001069b8(0);
  func_0013f558(0x348710);
  iVar1 = func_00102c80();
  func_00102788(*(u32 *)(iVar1 + 4),1,26000,0x140cc8);
  return;
}

void func_00141850(u32 param_1,u32 param_2)

{
  int iVar1;
  int iVar2;
  u64 uVar3;
  u64 uVar4;
  
  iVar2 = *(int *)((int)param_1 + 0x24);
  if (0 < iVar2) {
    iVar1 = 0;
    do {
      iVar2 = iVar2 + -1;
      *(u8 *)(iVar1 + *(int *)((int)param_1 + 8) + 0x10) = 0;
      iVar1 = iVar1 + 0x14;
    } while (iVar2 != 0);
  }
  uVar3 = 0;
  uVar4 = 1;
  while( true ) {
    if ((param_2 & uVar4) != 0) {
      func_00141928(param_1,uVar3 & 0xff);
    }
    uVar3 = (u64)((int)uVar3 + 1);
    if (0x3f < (s64)uVar3) break;
    uVar4 = 1L << uVar3;
  }
  return;
}

void func_00142bf8(int param_1)

{
  u32 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x28);
  iVar4 = 0;
  if (0 < iVar2) {
    iVar3 = *(int *)(param_1 + 0xc);
    while( true ) {
      uVar1 = *(u32 *)(*(int *)(param_1 + 0x14) + (u32)*(u16 *)(iVar3 + iVar4 * 0x10 + 0xe) * 4
                       );
      if ((uVar1 & 0x60000) != 0) {
        func_0014ed28(uVar1 >> 0x11 & 3,iVar4);
        iVar2 = *(int *)(param_1 + 0x28);
      }
      iVar4 = iVar4 + 1;
      if (iVar2 <= iVar4) break;
      iVar3 = *(int *)(param_1 + 0xc);
    }
  }
  return;
}

void func_00145b90(u32 param_1,u32 param_2)

{
  int iVar1;
  int iVar2;
  u64 uVar3;
  u64 uVar4;
  
  iVar2 = *(int *)((int)param_1 + 0x14);
  if (0 < iVar2) {
    iVar1 = 0;
    do {
      iVar2 = iVar2 + -1;
      *(u8 *)(iVar1 + *(int *)((int)param_1 + 8)) = 0;
      iVar1 = iVar1 + 0x1c;
    } while (iVar2 != 0);
  }
  uVar3 = 0;
  uVar4 = 1;
  while( true ) {
    if ((param_2 & uVar4) != 0) {
      func_00145c68(param_1,uVar3 & 0xff);
    }
    uVar3 = (u64)((int)uVar3 + 1);
    if (0x3f < (s64)uVar3) break;
    uVar4 = 1L << uVar3;
  }
  return;
}

void func_00147140(u32 param_1,u32 param_2)

{
  u16 uVar1;
  s64 lVar2;
  int iVar3;
  u16 uVar4;
  u32 auStack_30 [4];
  
  iVar3 = (int)param_2;
  lVar2 = func_00144d90(*(int *)((int)param_1 + 4) + (u32)*(u16 *)(iVar3 + 0x118) * 0x30 + 0x10,
                       iVar3 + 0xd0);
  uVar1 = 0;
  uVar4 = 0;
  if (lVar2 == 0) {
    auStack_30[0] = 0;
  }
  else {
    uVar4 = *(u16 *)(iVar3 + 0x11a);
    uVar1 = *(u16 *)(iVar3 + 0x118);
    auStack_30[0] = (u32)uVar4;
  }
  uVar1 = func_00147050(param_1,uVar1,param_2,uVar4,auStack_30);
  *(u16 *)(iVar3 + 0x118) = uVar1;
  *(u16 *)(iVar3 + 0x11a) = (u16)auStack_30[0];
  return;
}

u32 func_00147240(float param_1,int param_2,int param_3)

{
  s64 lVar1;
  u32 uVar2;
  
  lVar1 = func_00228378();
  uVar2 = 0;
  if ((lVar1 != 0) ||
     (((*(char *)(param_2 + 0x778) != '\0' && ((*(u32 *)(param_3 + 0xf8) & 1) != 0)) &&
      (uVar2 = 1, *(float *)(param_2 + 0x774) <= param_1)))) {
    uVar2 = 0;
  }
  return uVar2;
}

void func_00148598(int param_1,u32 *param_2)

{
  u16 uStack_30;
  u16 uStack_2e;
  
  if ((*(char *)((int)param_2 + 0xeb) != '\0') && ((param_2[0x3e] & 4) != 0)) {
    func_00147c78();
    *(u8 *)((int)param_2 + *(int *)(param_1 + 0x536c) + 0x10e) = 0;
    *(u64 *)(param_2 + 8) = 0x31000070;
    *(u64 *)(param_2 + 6) = 0x800d8;
    uStack_30 = 0x8000;
    uStack_2e = 0xffff;
    func_0011cd80(*param_2,param_1 + 0x1b0,param_2 + 0x10,param_2 + 2,&uStack_30,0);
  }
  return;
}
