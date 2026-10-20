#!/usr/bin/env python3
"""Emit compiler-behaviour variants for the remaining round-2 targets.

    python r2_gen2.py            # writes every variant + a probe list file

Every variant becomes its own source (one definition of func_<addr> per file)
under analysis/final-mix/recovery-experiments/fm_worker_b_round2_<addr>_vNN.cpp
and is appended to round-2/r2_list_gen2.txt for r2_probe_batch.sh.
"""
from pathlib import Path

ROOT = Path(r'C:/Users/KoZa/Documents/AGENTS/Codex')
EXP = ROOT / 'analysis/final-mix/recovery-experiments'
LIST = ROOT / 'analysis/final-mix/worker-coordination/worker-b/round-2/r2_list_gen2.txt'

HEAD = '#include "../common/types.h"\n'

# ---------------------------------------------------------------- 0017ee68
EE68_DECLS = """
extern "C" u32 func_001050c8(void);
extern "C" u32 func_00127c70(u32,u32,u32);
"""

EE68_BASE = """
void func_0017ee68(int param_1)
{
  u32 uVar1;
  u32 uVar2;
  uVar1 = *(u32 *)(*(int *)(param_1 + 8) + 0x670);
  if (*(int *)(param_1 + 0xd0) != 0) {
    uVar2 = func_001050c8();
    func_00127c70(uVar1,uVar2,*(u32 *)(param_1 + 0xd0));
    *(u32 *)(param_1 + 0xd0) = 0;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
    uVar2 = func_001050c8();
    func_00127c70(uVar1,uVar2,*(u32 *)(param_1 + 0xd4));
    *(u32 *)(param_1 + 0xd4) = 0;
  }
}
"""

EE68 = {
    'v01': EE68_DECLS + EE68_BASE,
    # void-returning callee
    'v02': """
extern "C" u32 func_001050c8(void);
extern "C" void func_00127c70(u32,u32,u32);
""" + EE68_BASE,
    # first argument inlined at each call site
    'v03': EE68_DECLS + """
void func_0017ee68(int param_1)
{
  u32 uVar2;
  if (*(int *)(param_1 + 0xd0) != 0) {
    uVar2 = func_001050c8();
    func_00127c70(*(u32 *)(*(int *)(param_1 + 8) + 0x670),uVar2,*(u32 *)(param_1 + 0xd0));
    *(u32 *)(param_1 + 0xd0) = 0;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
    uVar2 = func_001050c8();
    func_00127c70(*(u32 *)(*(int *)(param_1 + 8) + 0x670),uVar2,*(u32 *)(param_1 + 0xd4));
    *(u32 *)(param_1 + 0xd4) = 0;
  }
}
""",
    # third argument routed through a temp
    'v04': EE68_DECLS + """
void func_0017ee68(int param_1)
{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  uVar1 = *(u32 *)(*(int *)(param_1 + 8) + 0x670);
  if (*(int *)(param_1 + 0xd0) != 0) {
    uVar3 = *(u32 *)(param_1 + 0xd0);
    uVar2 = func_001050c8();
    func_00127c70(uVar1,uVar2,uVar3);
    *(u32 *)(param_1 + 0xd0) = 0;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
    uVar3 = *(u32 *)(param_1 + 0xd4);
    uVar2 = func_001050c8();
    func_00127c70(uVar1,uVar2,uVar3);
    *(u32 *)(param_1 + 0xd4) = 0;
  }
}
""",
    # no temp for the second argument
    'v05': EE68_DECLS + """
void func_0017ee68(int param_1)
{
  u32 uVar1;
  uVar1 = *(u32 *)(*(int *)(param_1 + 8) + 0x670);
  if (*(int *)(param_1 + 0xd0) != 0) {
    func_00127c70(uVar1,func_001050c8(),*(u32 *)(param_1 + 0xd0));
    *(u32 *)(param_1 + 0xd0) = 0;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
    func_00127c70(uVar1,func_001050c8(),*(u32 *)(param_1 + 0xd4));
    *(u32 *)(param_1 + 0xd4) = 0;
  }
}
""",
    # signed temp for the hoisted value
    'v06': EE68_DECLS + """
void func_0017ee68(int param_1)
{
  int iVar1;
  u32 uVar2;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x670);
  if (*(int *)(param_1 + 0xd0) != 0) {
    uVar2 = func_001050c8();
    func_00127c70(iVar1,uVar2,*(u32 *)(param_1 + 0xd0));
    *(u32 *)(param_1 + 0xd0) = 0;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
    uVar2 = func_001050c8();
    func_00127c70(iVar1,uVar2,*(u32 *)(param_1 + 0xd4));
    *(u32 *)(param_1 + 0xd4) = 0;
  }
}
""",
    # variadic-style callee declaration
    'v07': """
extern "C" u32 func_001050c8(...);
extern "C" u32 func_00127c70(...);
""" + EE68_BASE,
}

# ---------------------------------------------------------------- 002f3bb8
F3_DECLS = """
extern "C" void func_002f3490(...);
"""

F3_BASE = """
u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  if (param_2 == 1) {
    uVar1 = *param_1 >> 8 & 1;
  } else {
    func_002f3490();
    uVar1 = 0;
  }
  return uVar1;
}
"""

F3 = {
    'v01': F3_DECLS + F3_BASE,
    # constant carried in the result variable
    'v02': F3_DECLS + """
u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  uVar1 = 1;
  if (param_2 == uVar1) {
    uVar1 = *param_1 >> 8;
    uVar1 &= 1;
  } else {
    func_002f3490();
    uVar1 = 0;
  }
  return uVar1;
}
""",
    # early return
    'v03': F3_DECLS + """
u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  if (param_2 != 1) {
    func_002f3490();
    return 0;
  }
  return *param_1 >> 8 & 1;
}
""",
    # local load then shift
    'v04': F3_DECLS + """
u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  if (param_2 == 1) {
    uVar1 = *param_1;
    uVar1 = uVar1 >> 8;
    uVar1 = uVar1 & 1;
  } else {
    func_002f3490();
    uVar1 = 0;
  }
  return uVar1;
}
""",
    # result defaulted before the branch
    'v05': F3_DECLS + """
u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  uVar1 = 0;
  if (param_2 == 1) {
    uVar1 = *param_1 >> 8 & 1;
  } else {
    func_002f3490();
  }
  return uVar1;
}
""",
    # reversed comparison
    'v06': F3_DECLS + """
u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  if (1 == param_2) {
    uVar1 = *param_1 >> 8 & 1;
  } else {
    func_002f3490();
    uVar1 = 0;
  }
  return uVar1;
}
""",
    # explicit else-if shape with a boolean result
    'v07': F3_DECLS + """
bool func_002f3bb8(u32 *param_1,s32 param_2)
{
  bool bVar1;
  bVar1 = false;
  if (param_2 == 1) {
    bVar1 = (*param_1 & 0x100) != 0;
  } else {
    func_002f3490();
  }
  return bVar1;
}
""",
    # pointer walked in two steps
    'v08': F3_DECLS + """
u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  if (param_2 == 1) {
    param_1 = (u32 *)((u32)param_1 + 1);
    uVar1 = *param_1;
    uVar1 = uVar1 >> 1;
    uVar1 = uVar1 & 1;
  } else {
    func_002f3490();
    uVar1 = 0;
  }
  return uVar1;
}
""",
}

# ---------------------------------------------------------------- 0019c0f8
C0F8_DECLS = """
extern "C" s32 func_0019c090(s32);
"""

C0F8 = {
    # Ghidra "assign zero in the dead branch" shape
    'v01': C0F8_DECLS + """
s32 func_0019c0f8(s32 param_1)
{
  s32 lVar1;
  lVar1 = func_0019c090(0);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else if ((*(u32 *)(param_1 + 0x160) & 0x20) == 0) {
    lVar1 = (*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0;
  }
  return lVar1;
}
""",
    # same shape, no explicit zero store
    'v02': C0F8_DECLS + """
s32 func_0019c0f8(s32 param_1)
{
  s32 lVar1;
  lVar1 = func_0019c090(0);
  if (lVar1 != 0) {
    if ((*(u32 *)(param_1 + 0x160) & 0x20) == 0) {
      lVar1 = (*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0;
    }
  }
  return lVar1;
}
""",
    # pointer parameter
    'v03': C0F8_DECLS + """
s32 func_0019c0f8(int *param_1)
{
  s32 lVar1;
  lVar1 = func_0019c090(0);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else if ((param_1[0x58] & 0x20) == 0) {
    lVar1 = (*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0;
  }
  return lVar1;
}
""",
    # boolean return
    'v04': C0F8_DECLS + """
bool func_0019c0f8(s32 param_1)
{
  bool bVar1;
  s32 lVar1;
  lVar1 = func_0019c090(0);
  if (lVar1 == 0) {
    bVar1 = false;
  }
  else if ((*(u32 *)(param_1 + 0x160) & 0x20) == 0) {
    bVar1 = (*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}
""",
    # unsigned result register
    'v05': C0F8_DECLS + """
u32 func_0019c0f8(u32 param_1)
{
  u32 uVar1;
  uVar1 = func_0019c090(0);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else if ((*(u32 *)(param_1 + 0x160) & 0x20) == 0) {
    uVar1 = (*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0;
  }
  return uVar1;
}
""",
}

# ---------------------------------------------------------------- 002bc2e8
E8_DECLS = """
extern "C" s32 func_002bc158(void);
extern "C" void func_002bb310(s32,u32,u32,u32);
"""

E8_BASE = """
u32 func_002bc2e8(u32 param_1,u32 param_2,u32 param_3)
{
  u32 uVar1;
  s32 lVar2;
  lVar2 = func_002bc158();
  uVar1 = 0;
  if (lVar2 != 0) {
    func_002bb310(lVar2,param_1,param_2,param_3);
    uVar1 = *(u32 *)((int)lVar2 + 0x14);
  }
  return uVar1;
}
"""

E8 = {
    'v05': E8_DECLS + E8_BASE.replace(
        '  u32 uVar1;\n',
        '  u32 uVar1;\n\n  asm("" : "+r"(param_2));\n'),
    'v06': E8_DECLS + E8_BASE.replace(
        '  u32 uVar1;\n',
        '  u32 uVar1;\n\n  asm("" : "+r"(param_1));\n'),
    'v07': E8_DECLS + E8_BASE.replace(
        '  u32 uVar1;\n',
        '  u32 uVar1;\n  u32 uVar2;\n  u32 uVar3;\n\n'
        '  uVar2 = param_2;\n  uVar3 = param_1;\n  asm("" : "+r"(uVar2), "+r"(uVar3));\n'
    ).replace('func_002bb310(lVar2,param_1,param_2,param_3)',
              'func_002bb310(lVar2,uVar3,uVar2,param_3)'),
    'v08': E8_DECLS + E8_BASE.replace(
        '  u32 uVar1;\n',
        '  u32 uVar1;\n  u32 uVar2;\n  u32 uVar3;\n\n'
        '  uVar3 = param_1;\n  uVar2 = param_2;\n  asm("" : "+r"(uVar3), "+r"(uVar2));\n'
    ).replace('func_002bb310(lVar2,param_1,param_2,param_3)',
              'func_002bb310(lVar2,uVar3,uVar2,param_3)'),
    # mark the third argument first, then the second
    'v09': E8_DECLS + E8_BASE.replace(
        '  u32 uVar1;\n',
        '  u32 uVar1;\n\n  asm("" : "+r"(param_2), "+r"(param_1), "+r"(param_3));\n'),
    'v10': E8_DECLS + E8_BASE.replace(
        '  u32 uVar1;\n',
        '  u32 uVar1;\n\n  asm("" : "+r"(param_1), "+r"(param_2), "+r"(param_3));\n'),
}

TARGETS = {'0017ee68': EE68, '002f3bb8': F3, '0019c0f8': C0F8, '002bc2e8': E8}


def main() -> int:
    paths = []
    for address, variants in TARGETS.items():
        for name, body in sorted(variants.items()):
            path = EXP / f'fm_worker_b_round2_{address}_{name}.cpp'
            path.write_text(HEAD + body.lstrip('\n'))
            paths.append(path)
    LIST.write_text('\n'.join(f'/mnt/c/{p.as_posix()[3:]}' for p in paths) + '\n')
    print(f'wrote {len(paths)} variants')
    for p in paths:
        print(' ', p.name)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
