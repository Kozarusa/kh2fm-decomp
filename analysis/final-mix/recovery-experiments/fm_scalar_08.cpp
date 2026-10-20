#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u64 func_00102448(...);
extern "C" u64 func_00104f58(...);
extern "C" u64 func_001050d8(...);
extern "C" u64 func_00105110(...);
extern "C" u64 func_00106a18(...);
extern "C" u64 func_00106a60(...);
extern "C" u64 func_00106f30(...);
extern "C" u64 func_00107368(...);
extern "C" u64 func_00107478(...);
extern "C" u64 func_00108398(...);
extern "C" u64 func_00138c10(...);
extern "C" u64 func_00168b38(...);
extern "C" u64 func_0016ac38(...);
extern "C" u64 func_0016bd60(...);
extern "C" u64 func_0016c028(...);
extern "C" u64 func_001780d8(...);
extern "C" u64 func_00178888(...);
extern "C" u64 func_00179b68(...);
extern "C" u64 func_00181500(...);
extern "C" u64 func_00184540(...);
extern "C" u64 func_00190140(...);
extern "C" u64 func_00198450(...);
extern "C" u64 func_001b6d70(...);
extern "C" u64 func_001b9bc8(...);
extern "C" u64 func_001bc778(...);
extern "C" u64 func_001bc780(...);
extern "C" u64 func_001c2b58(...);
extern "C" u64 func_001c3748(...);
extern "C" u64 func_001c3888(...);
extern "C" u64 func_001dc818(...);
extern "C" u64 func_002b6708(...);
extern "C" u64 func_002b6ab8(...);
extern "C" u64 func_002b6adc(...);
extern "C" u64 func_002b6e24(...);
extern "C" u64 func_002b6f28(...);
extern "C" u64 func_002b7010(...);
extern "C" u64 func_002b7078(...);
extern "C" u64 func_002b70b8(...);
extern "C" u64 func_002ba3e8(...);
extern "C" u64 func_002baa08(...);
extern "C" u64 func_002baa60(...);
extern "C" u64 func_002baa78(...);
extern "C" u64 func_002baf48(...);
extern "C" u64 func_002bb100(...);
extern "C" u64 func_002bb5a8(...);
extern "C" u64 func_002bb9b8(...);
extern "C" u64 func_002bbbc8(...);
extern "C" u64 func_002bbc90(...);
extern "C" u64 func_002bbda0(...);
extern "C" u64 func_002bbf68(...);
extern "C" u64 func_002bc0f0(...);
extern "C" u64 func_002bc188(...);
extern "C" u64 func_002bc470(...);
extern "C" u64 func_002bc608(...);
extern "C" u64 func_002bc988(...);
extern "C" u64 func_002bc9a8(...);
extern "C" u64 func_002bce10(...);
extern "C" u64 func_002bcfe8(...);
extern "C" u64 func_002bd030(...);
extern "C" u64 func_002bd078(...);
extern "C" u64 func_002bd0b8(...);
extern "C" u64 func_002bd100(...);
extern "C" u64 func_002bd140(...);
extern "C" u64 func_002be340(...);
extern "C" u64 func_002be4a0(...);
extern "C" u64 func_002bf650(...);
extern "C" u64 func_002c04c8(...);
extern "C" u64 func_002c1b48(...);
extern "C" u64 func_002c1b60(...);
extern "C" u64 func_002c6218(...);
extern "C" u64 func_002c6280(...);
extern "C" u64 func_002c6490(...);
extern "C" u64 func_002c6c60(...);
extern "C" u64 func_002c7060(...);
extern "C" u64 func_002cb890(...);
extern "C" u64 func_002cc620(...);
extern "C" u64 func_002cd428(...);
extern "C" u64 func_002cd878(...);
extern "C" u64 func_002cf2d0(...);
extern "C" u64 func_002d10a0(...);
extern "C" u64 func_002d1550(...);
extern "C" u64 func_002d24e8(...);
extern "C" u64 func_002dc4e0(...);
extern "C" u64 func_002dc7c8(...);
extern "C" u64 func_002e0d28(...);
extern "C" u64 func_002e20d8(...);
extern "C" u64 func_002e34d8(...);
extern "C" u64 func_002fee78(...);
extern "C" u64 func_002ff3fc(...);
extern "C" u64 func_00325320(...);

u64 func_002b7108(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x12,param_1);
  return uVar1;
}

u64
func_002b726c(u32 param_1,u32 param_2,u32 param_3,int param_4,u32 param_5
            )

{
  u64 uVar1;
  u32 uStack_20;
  
  uStack_20 = param_5;
  if (0x39ff < param_4) {
    uStack_20 = 0x40;
  }
  uVar1 = func_002b6708(6,0x13,param_1,param_2,param_3,param_4,uStack_20);
  return uVar1;
}

u64 func_002b72e4(u32 param_1,u32 param_2,u32 param_3)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(4,0x14,param_1,param_2,param_3);
  return uVar1;
}

u64
func_002b7334(u32 param_1,u32 param_2,u32 param_3,int param_4,u32 param_5
            )

{
  u64 uVar1;
  u32 uStack_20;
  
  uStack_20 = param_5;
  if (0x39ff < param_4) {
    uStack_20 = 0x40;
  }
  uVar1 = func_002b6708(6,0x15,param_1,param_2,param_3,param_4,uStack_20);
  return uVar1;
}

u64
func_002b73ac(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
            u32 param_5)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(6,0x16,param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}

u64 func_002b740c(void)

{
  return 0;
}

u64 func_002b788c(u32 param_1,u32 param_2,u32 param_3,u32 param_4)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(7,0x19,param_1,param_2,param_3,param_4,1,1);
  return uVar1;
}

u64 func_002b78ec(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x1a,param_1);
  return uVar1;
}

u64 func_002b792c(u32 param_1,u32 param_2,u32 param_3)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(4,0x1b,param_1,param_2,param_3);
  return uVar1;
}

u64 func_002b797c(u32 param_1,u32 param_2,u32 param_3)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(4,0x1c,param_1,param_2,param_3);
  return uVar1;
}

u64 func_002b7c34(u32 param_1,u32 param_2,int param_3,u32 param_4)

{
  u64 uVar1;
  u32 uStack_14;
  
  uStack_14 = param_4;
  if (0x39ff < param_3) {
    uStack_14 = 0x40;
  }
  uVar1 = func_002b6708(5,0x1d,param_1,param_2,param_3,uStack_14);
  return uVar1;
}

u64 func_002b7ca4(u32 param_1,u32 param_2)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(3,0x1e,param_1,param_2);
  return uVar1;
}

u64 func_002b7cec(u32 param_1,u32 param_2,int param_3,u32 param_4)

{
  u64 uVar1;
  u32 uStack_14;
  
  uStack_14 = param_4;
  if (0x39ff < param_3) {
    uStack_14 = 0x40;
  }
  uVar1 = func_002b6708(5,0x1f,param_1,param_2,param_3,uStack_14);
  return uVar1;
}

u64 func_002b7d5c(u32 param_1,u32 param_2,u32 param_3,u32 param_4)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(5,0x20,param_1,param_2,param_3,param_4);
  return uVar1;
}

u64
func_002b7db4(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
            u32 param_5,u32 param_6)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(9,0x2b,param_1,param_2,param_3,param_4,param_5,param_6);
  return uVar1;
}

u64 func_002b7e34(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x2c,param_1);
  return uVar1;
}

u64 func_002b7e74(u32 param_1,u32 param_2)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(3,0x2d,param_2,param_1);
  return uVar1;
}

u64 func_002b7ebc(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x2e,param_1);
  return uVar1;
}

u64 func_002b7efc(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x2f,param_1);
  return uVar1;
}

u64 func_002b7f3c(u32 param_1,u32 param_2)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(3,0x30,param_1,param_2);
  return uVar1;
}

u64 func_002b7f84(void)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(1,0x31);
  return uVar1;
}

u64 func_002b7fbc(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x32,param_1);
  return uVar1;
}

u64 func_002b7ffc(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x33,param_1);
  return uVar1;
}

u64 func_002b803c(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x34,param_1);
  return uVar1;
}

u64 func_002b81b8(void)

{
  return 0;
}

u64 func_002b81ec(void)

{
  return 0;
}

u64 func_002b8214(void)

{
  return 0;
}

u64 func_002b8374(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x24,param_1);
  return uVar1;
}

u64 func_002b83b4(void)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(1,0x27);
  return uVar1;
}

u64 func_002b83ec(u32 param_1,u32 param_2)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(3,0x26,param_1,param_2);
  return uVar1;
}

u64 func_002b8984(int param_1,u32 param_2,u32 param_3)

{
  *(u32 *)(param_1 + 0x4801c) = param_2;
  *(u32 *)(param_1 + 0x48020) = param_3;
  return 0;
}

u64 func_002b9968(void)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(1,0x18);
  return uVar1;
}

u64 func_002b99c8(void)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(1,0x29);
  return uVar1;
}

u64 func_002b9a00(void)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(1,0x2a);
  return uVar1;
}

u64 func_002b9a38(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x35,param_1);
  return uVar1;
}

u64 func_002b9a78(u32 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002b6708(2,0x36,param_1);
  return uVar1;
}

void func_002b9b78(void)

{
  func_002bc9a8(0x1e2a410,2,0);
  func_002bce10(0x1e2a410,2);
  func_002bc9a8(0x1e2a410,3,999);
  func_002bce10(0x1e2a410,3);
  return;
}

void func_002b9ed0(void)

{
  func_002baa78();
  func_002bcfe8(0x1e2a410);
  func_002bd030(0x1e2a410);
  func_002bd078(0x1e2a410);
  func_002bd0b8(0x1e2a410);
  func_002bd100(0x1e2a410);
  func_002bd140(0x1e2a410);
  return;
}

void func_002ba040(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  func_002bcfe8(0x1e2a410);
  func_002bd030(0x1e2a410);
  iVar1 = 0x14;
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 1;
    func_002b6adc(2,iVar1);
    func_002b6adc(0,iVar1);
    iVar1 = iVar2 + 0x15;
    iVar2 = iVar3;
  } while (iVar3 < 2);
  return;
}

u64 func_002ba0b0(u64 param_1)

{
  func_002fee78(0x1e2a568,0x374f70,param_1);
  func_002ff3fc(0x1e2a568);
  return 0x1e2a568;
}

u64 func_002ba0f8(u64 param_1)

{
  func_002fee78(0x1e2a5a8,0x374f80,param_1);
  func_002ff3fc(0x1e2a5a8);
  return 0x1e2a5a8;
}

void func_002ba140(u64 param_1,u64 param_2,u64 param_3)

{
  func_002bc608();
  func_002b6f28(param_1,param_2,param_3);
  return;
}

void func_002ba1b8(u64 param_1,u64 param_2,u64 param_3)

{
  func_002bc470();
  func_002b6e24(param_1,param_2,param_3);
  return;
}

void func_002ba220(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5,u64 param_6)

{
  func_002b7078();
  func_002b7010(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

void func_002ba3b8(void)

{
  func_002ba3e8();
  return;
}

void func_002ba5d0(u64 param_1,u64 param_2)

{
  func_002baf48(10,1,param_1,param_2,0,0);
  return;
}

void func_002ba948(void)

{
  func_002b70b8(0,0x3000,0xf0);
  func_002b70b8(1,0x3000,0xf0);
  return;
}

void func_002bb070(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5)

{
  func_002baf48(param_1,3,param_2,param_3,param_4,param_5);
  return;
}

void func_002bb3f0(u64 param_1,u32 param_2,u32 param_3,u64 param_4,
                 u16 param_5)

{
  int iVar1;
  
  func_002bb100(param_1,1,6);
  func_002bb5a8(param_1,param_4);
  iVar1 = (int)param_1;
  *(u16 *)(iVar1 + 0x2a) = param_5;
  *(u32 *)(iVar1 + 0x18) = param_2;
  *(u32 *)(iVar1 + 0x10) = param_3;
  return;
}

void func_002bbd58(int param_1)

{
  if (*(char *)(param_1 + 0x31) == '\x05') {
    func_002bbbc8();
    return;
  }
  if (*(char *)(param_1 + 0x31) != '\x06') {
    func_002bb9b8();
    return;
  }
  func_002bbc90();
  return;
}

u64 func_002bc158(s64 param_1)

{
  u64 uVar1;
  
  if ((param_1 != 0) && (-1 < param_1)) {
    uVar1 = func_002bc0f0();
    return uVar1;
  }
  return 0;
}

void func_002bc358(u64 param_1,u64 param_2)

{
  s64 lVar1;
  
  lVar1 = func_002bbda0();
  if (lVar1 != 0) {
    func_002bbf68(lVar1,param_2);
    return;
  }
  return;
}

void func_002bc398(u64 param_1,u64 param_2)

{
  s64 lVar1;
  
  lVar1 = func_002bbda0();
  if (lVar1 != 0) {
    func_002bb5a8(lVar1,param_2);
    *(u32 *)((int)lVar1 + 0x24) = *(u32 *)((int)lVar1 + 0x24) & 0xfffffff7;
  }
  return;
}

int func_002bca10(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  piVar1 = param_1;
  while ((iVar2 != param_2 || (*piVar1 != param_3))) {
    if ((int)(param_1 + 0x21) <= (int)(piVar1 + 3)) {
      return -1;
    }
    iVar2 = piVar1[4];
    piVar1 = piVar1 + 3;
  }
  return param_3;
}

void func_002bcbf0(u64 param_1,u64 param_2,u64 param_3,u32 *param_4,
                 u32 *param_5)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = func_002bc988(param_2);
  *param_5 = uVar1;
  iVar2 = (int)param_1;
  uVar1 = *(u32 *)(iVar2 + 0x14c);
  *param_4 = uVar1;
  func_002bc9a8(param_1,uVar1,*param_5);
  uVar1 = 0x15;
  if (*(int *)(iVar2 + 0x14c) != 0x14) {
    uVar1 = 0x14;
  }
  *(u32 *)(iVar2 + 0x14c) = uVar1;
  return;
}

void func_002bd188(u64 param_1,u64 param_2)

{
  func_002b6adc(2);
  func_002b6adc(0,param_2);
  func_002b6ab8();
  return;
}

u64 func_002bd260(u64 param_1)

{
  func_002fee78(0x1e2bba0,0x374fa8,param_1);
  func_002ff3fc(0x1e2bba0);
  return 0x1e2bba0;
}

void func_002be568(int param_1,u64 param_2)

{
  int iVar1;
  
  func_002baa60();
  iVar1 = func_00168b38(*(u32 *)(param_1 + 0x68),0xffffffffffffffff,param_2);
  func_002baa08(*(u32 *)(iVar1 + 8),*(u32 *)(iVar1 + 0xc),0x3fff,0x40);
  return;
}

s64 func_002be908(s64 param_1)

{
  do {
    param_1 = func_001b9bc8(param_1);
    if (param_1 == 0) {
      return 0;
    }
  } while ((*(u32 *)((int)param_1 + 0x588) & 0x40000000) == 0);
  return param_1;
}

u64 func_002bec38(u64 param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_3 + 300);
  func_00184540(*(u32 *)(iVar1 + 0x28),*(u32 *)(iVar1 + 0x2c),param_1,param_3);
  return param_1;
}

void func_002bf5a0(u64 param_1)

{
  int iVar1;
  
  iVar1 = func_001b6d70(*(u8 *)(*(int *)((int)param_1 + 0xaf8) + 4));
  if (((*(u8 *)((int)param_1 + 0xae7) & 1) == 0) && ((*(u8 *)(iVar1 + 3) & 1) != 0)) {
    func_0016ac38(param_1,0,1,0,0);
    return;
  }
  return;
}

void func_002bf618(u64 param_1)

{
  u64 uVar1;
  
  uVar1 = func_001b6d70(*(u8 *)(*(int *)((int)param_1 + 0xaf8) + 4));
  func_002bf650(param_1,uVar1);
  return;
}

void func_002bfd48(u32 *param_1,u64 param_2)

{
  s64 lVar1;
  
  func_002be340(param_2);
  while (lVar1 = func_002be4a0(), lVar1 != 0) {
    func_00102448(*param_1,0);
  }
  return;
}

bool func_002c0470(u64 param_1)

{
  s64 lVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  lVar1 = func_00190140(iVar2 + 100);
  if (lVar1 != 0) {
    func_002c04c8(param_1,iVar2 + 0x30,iVar2 + 0x40);
    func_002c6490(param_1);
  }
  return lVar1 != 0;
}

void func_002c0700(void)

{
  u64 uVar1;
  
  uVar1 = func_002c6218();
  func_002c6280(uVar1,1);
  return;
}

void func_002c14a8(int param_1)

{
  if (*(int *)(param_1 + 0x244) != 0x4d) {
    func_00138c10(param_1 + 0xc0,0x4d);
    *(u32 *)(param_1 + 0x248) = 0xffffffff;
  }
  return;
}

void func_002c1860(u64 param_1,u64 param_2)

{
  func_002c7060((int)param_2 + 0xb70);
  if (0.0 < *(float *)((int)param_2 + 0xbc4)) {
    return;
  }
  func_0016bd60(param_2,0x2f);
  return;
}

void func_002c1ae8(u64 param_1)

{
  u64 uVar1;
  int iVar2;
  
  iVar2 = func_002c1b48();
  *(int *)((int)param_1 + 0xae4) = iVar2 * 3 + 0x375515;
  uVar1 = func_002c1b48(param_1);
  uVar1 = func_001c2b58(uVar1);
  func_002c1b60(param_1,uVar1);
  func_00198450(param_1);
  return;
}

void func_002c1c50(u64 param_1)

{
  u64 uVar1;
  
  uVar1 = func_002c1b48();
  uVar1 = func_001c2b58(uVar1);
  func_002c1b60(param_1,uVar1);
  return;
}

int func_002c22f0(int param_1)

{
  short sVar1;
  s64 lVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  
  psVar3 = (short *)(param_1 + 4);
  iVar4 = 2;
  iVar5 = 0;
  sVar1 = *psVar3;
  while( true ) {
    psVar3 = psVar3 + 2;
    if (sVar1 != 0) {
      lVar2 = func_00181500(sVar1);
      if (lVar2 != 0) {
        iVar5 = iVar5 + 1;
      }
    }
    iVar4 = iVar4 + -1;
    if (iVar4 < 0) break;
    sVar1 = *psVar3;
  }
  return iVar5;
}

u64 func_002c2688(u64 param_1,int param_2)

{
  s64 lVar1;
  u64 uVar2;
  int iVar3;
  
  lVar1 = 0;
  iVar3 = 0;
  while( true ) {
    lVar1 = func_001c3748(param_1,lVar1);
    if (lVar1 == 0) {
      return 0;
    }
    if (iVar3 == param_2) break;
    iVar3 = iVar3 + 1;
  }
  uVar2 = func_001c3888(lVar1);
  return uVar2;
}

void func_002c5460(u64 param_1)

{
  func_00104f58(param_1,1,0,0,0);
  return;
}

void func_002c58c8(u64 param_1)

{
  func_001780d8();
  func_0016bd60(param_1,0x2f);
  func_002c6c60(param_1,*(u32 *)((int)param_1 + 0xb38));
  return;
}

void func_002c5900(u64 param_1)

{
  s64 lVar1;
  u32 uVar2;
  int iVar3;
  
  iVar3 = *(int *)((int)param_1 + 0xb44) + 0x4ac;
  func_001bc778(iVar3);
  lVar1 = func_00190140(*(int *)((int)param_1 + 0xb40) + 4);
  uVar2 = 0x246;
  if (lVar1 == 0) {
    uVar2 = 0x247;
  }
  iVar3 = func_001bc780(iVar3,uVar2,0,1);
  *(u8 *)(iVar3 + 6) = 4;
  func_00178888(param_1);
  return;
}

void func_002c6420(int param_1)

{
  u64 uVar1;
  u32 uVar2;
  
  *(u32 *)(param_1 + 0x54) = 0;
  uVar1 = func_00106a60(1);
  func_00107368(uVar1,param_1 + 0x10);
  func_00107478(uVar1,param_1 + 0x20);
  uVar1 = func_00106a18(1);
  uVar2 = func_00106f30(uVar1,0);
  *(u32 *)(param_1 + 0x58) = 0;
  *(u32 *)(param_1 + 0x50) = uVar2;
  return;
}

void func_002cb160(void)

{
  u64 uVar1;
  
  uVar1 = func_002c6218();
  func_002c6280(uVar1,2);
  return;
}

void func_002cb708(u64 param_1)

{
  func_00105110(*(u32 *)((int)param_1 + 0x80));
  func_00325320(0x1e2be18,param_1);
  return;
}

u64 func_002cb7c8(u64 param_1,u64 param_2,u64 param_3)

{
  u32 *puVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 *puVar5;
  
  puVar1 = (u32 *)func_002cb890(param_2,param_3);
  uVar2 = puVar1[1];
  uVar3 = puVar1[2];
  uVar4 = puVar1[3];
  puVar5 = (u32 *)param_1;
  *puVar5 = *puVar1;
  puVar5[1] = uVar2;
  puVar5[2] = uVar3;
  puVar5[3] = uVar4;
  return param_1;
}

void func_002cd3e0(u64 param_1,u64 param_2)

{
  u32 *puVar1;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  
  puVar1 = (u32 *)func_0016c028(param_2);
  uStack_30 = *puVar1;
  uStack_2c = puVar1[1];
  uStack_28 = puVar1[2];
  uStack_24 = puVar1[3];
  func_002cd428(param_1,&uStack_30);
  return;
}

u64 func_002cd910(float param_1,u64 param_2)

{
  func_002cd878(param_1 - (float)(int)param_1);
  return param_2;
}

void func_002cff50(int param_1)

{
  func_002cf2d0(param_1 + 0xaf0);
  *(u32 *)(param_1 + 0xb0c) = 0;
  *(u32 *)(param_1 + 0xaf4) = 0;
  *(u32 *)(param_1 + 0xaf8) = 0;
  *(u32 *)(param_1 + 0xafc) = 0;
  *(u32 *)(param_1 + 0xb00) = 0;
  *(u32 *)(param_1 + 0xb04) = 0;
  *(u32 *)(param_1 + 0xb08) = 0;
  return;
}

void func_002d0cf0(int param_1)

{
  if (*(int *)(param_1 + 0xb0c) != 0) {
    func_001dc818(*(int *)(param_1 + 0xb0c));
    *(u32 *)(param_1 + 0xb0c) = 0;
  }
  *(u32 *)(param_1 + 0xb10) = 0;
  *(u32 *)(param_1 + 0x10c) = *(u32 *)(param_1 + 0x10c) | 0x80;
  *(u32 *)(param_1 + 0x108) = *(u32 *)(param_1 + 0x108) | 0x403;
  return;
}

void func_002d1270(u64 param_1,u64 param_2)

{
  u64 uVar1;
  
  uVar1 = func_001050d8(0x150);
  func_002d1550(uVar1,param_1,param_2);
  return;
}

void func_002d25f0(u64 param_1)

{
  s64 lVar1;
  
  lVar1 = 0;
  while (lVar1 = func_001b9bc8(lVar1), lVar1 != 0) {
    if ((*(u32 *)((int)lVar1 + 0x588) & 0x8000000) != 0) {
      func_002d24e8(param_1,lVar1);
    }
  }
  return;
}

u32 func_002d5588(int param_1)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 4);
  uVar2 = 0;
  if ((iVar1 == 0x38) || (iVar1 == 0x37)) {
    uVar2 = 1;
  }
  return uVar2;
}

u64 func_002d5bd8(int param_1)

{
  int iVar1;
  u64 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 4);
  uVar2 = 1;
  if ((iVar1 != 0x38) && (iVar1 != 0x37)) {
    uVar2 = func_00179b68();
  }
  return uVar2;
}

void func_002daa00(int param_1,int param_2)

{
  u64 uVar1;
  
  if (*(int *)(param_1 + 0xbf4) != 0) {
    uVar1 = func_0016c028(*(int *)(param_1 + 0xbf4));
    func_002bc188(param_2 + 0x56ab8,uVar1);
    return;
  }
  return;
}

void func_002db610(u64 param_1,int param_2)

{
  u32 uVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0xb0c) != 0) {
    if (*(int *)(iVar2 + 0xb14) == param_2) {
      return;
    }
    func_001dc818();
    *(u32 *)(iVar2 + 0xb0c) = 0;
  }
  if (-1 < param_2) {
    uVar1 = func_0016ac38(param_1,param_2,1,0,0);
    *(u32 *)(iVar2 + 0xb0c) = uVar1;
  }
  *(int *)(iVar2 + 0xb14) = param_2;
  return;
}

void func_002dc278(u64 param_1,u64 param_2)

{
  u64 uVar1;
  
  uVar1 = func_001050d8(0x80a0);
  func_002dc4e0(uVar1,param_1,param_2);
  return;
}

u32 func_002dc808(int param_1)

{
  int iVar1;
  u32 *puVar2;
  u32 uVar3;
  
  if (*(int *)(param_1 + 0x8070) == 0) {
    puVar2 = (u32 *)func_002dc7c8();
    uVar3 = *puVar2;
  }
  else {
    iVar1 = func_002dc7c8();
    uVar3 = *(u32 *)(iVar1 + 0xb4);
  }
  return uVar3;
}

void func_002dd790(int param_1)

{
  func_002d10a0();
  if ((u32 *)(param_1 + 0xbf0) != (u32 *)(param_1 + 0x540)) {
    *(u32 *)(param_1 + 0xbf0) = *(u32 *)(param_1 + 0x540);
    *(u32 *)(param_1 + 0xbf4) = *(u32 *)(param_1 + 0x544);
    *(u32 *)(param_1 + 0xbf8) = *(u32 *)(param_1 + 0x548);
    *(u32 *)(param_1 + 0xbfc) = *(u32 *)(param_1 + 0x54c);
  }
  return;
}

void func_002df160(int param_1)

{
  *(u32 *)(param_1 + 0x20) = 0;
  *(u32 *)(param_1 + 0x24) = *(u32 *)(param_1 + 0x18);
  *(u32 *)(param_1 + 0x2c) = *(u32 *)(param_1 + 0x20);
  *(u8 *)(param_1 + 0x30) = 0;
  *(u8 *)(param_1 + 0x31) = 0;
  *(u32 *)(param_1 + 0x1c) = *(u32 *)(param_1 + 0x18);
  *(u32 *)(param_1 + 0x28) = *(u32 *)(param_1 + 0x20);
  return;
}

void func_002e0bb0(u64 param_1)

{
  u64 uVar1;
  
  uVar1 = func_001050d8(0xf0);
  func_002e0d28(uVar1,param_1);
  return;
}

void func_002e0fa0(int param_1,u32 param_2)

{
  int *piVar1;
  int iVar2;
  
  *(u32 *)(param_1 + 0x74) = param_2;
  piVar1 = (int *)func_002e34d8(param_1 + 0x68);
  *(int **)(param_1 + 100) = piVar1;
  iVar2 = *piVar1;
  *(u8 *)(param_1 + 0x85) = 1;
  *(float *)(param_1 + 0x78) = (float)iVar2;
  return;
}

void func_002e1f40(u64 param_1)

{
  u64 uVar1;
  
  uVar1 = func_001050d8(0x140);
  func_002e20d8(uVar1,param_1);
  return;
}

void func_002e3c28(int *param_1)

{
  if (((*(int *)(*param_1 + 4) != 0) && (*(int *)(*(int *)(*param_1 + 4) + 0x508) != 0)) &&
     (*(int *)(param_1[1] + 4) != 0)) {
    func_002cc620();
    return;
  }
  return;
}

void func_002e4a90(int param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = param_1 + 0x4750;
  if (param_1 != -0x1180) {
    do {
      bVar1 = param_1 + 0x1180 != iVar2;
      iVar2 = iVar2 + -0x10;
    } while (bVar1);
  }
  if (param_1 != -0x10) {
    iVar2 = param_1 + 0xf70;
    do {
      bVar1 = param_1 + 0x10 != iVar2;
      iVar2 = iVar2 + -0x60;
    } while (bVar1);
  }
  return;
}

void func_002e5f70(int param_1)

{
  func_00108398(param_1 + 0x10);
  func_00108398(param_1 + 0x120);
  *(u64 *)(param_1 + 0x230) = 0;
  *(u32 *)(param_1 + 0x220) = 0;
  *(u32 *)(param_1 + 0x224) = 0;
  *(u32 *)(param_1 + 0x228) = 0;
  *(u32 *)(param_1 + 0x22c) = 0;
  return;
}

int func_002e64e8(char param_1,char param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  pcVar1 = (char *)(param_3 + 0x10);
  if (0 < *(int *)(param_3 + 0xc)) {
    do {
      if (*pcVar1 == param_1) {
        if (pcVar1[1] == param_2) {
          return iVar2;
        }
        iVar3 = *(int *)(pcVar1 + 0xc);
      }
      else {
        iVar3 = *(int *)(pcVar1 + 0xc);
      }
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + iVar3;
    } while (iVar2 < *(int *)(param_3 + 0xc));
  }
  return -1;
}
