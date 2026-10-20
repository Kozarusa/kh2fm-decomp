#!/usr/bin/env python3
"""Emit round-2 recovery variant sources for one target.

Each variant is a standalone translation unit holding a single `func_<address>`
definition so the pinned probe harness can link it at the original address and
compare the compiled bytes against the original ELF range.

    python r2_gen.py <target-address>

Writes analysis/final-mix/recovery-experiments/fm_worker_b_round2_<addr>_vNN.cpp
plus a companion list file consumed by r2_probe_batch.sh.
"""
import sys
from pathlib import Path

EXPERIMENTS = Path(r'C:/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments')

HEADER = '#include "../common/types.h"\n\n'


def write_variants(address: str, variants: list) -> list:
    written = []
    for index, (label, body) in enumerate(variants, start=1):
        stem = f'fm_worker_b_round2_{address}_v{index:02d}'
        text = HEADER + body.replace('@LABEL@', label) + '\n'
        path = EXPERIMENTS / f'{stem}.cpp'
        path.write_text(text, newline='\n')
        written.append(path)
    return written


TARGET_00180C88 = [
    ('float3_call5', '''
extern "C" u32 func_0017f488(s32,s32,float,float,s32);
extern "C" void func_001802d8(u32,u32,u32,u32,u32,u32);

void func_00180c88(u32 param_1,s32 param_2,float param_3)
{
  if (*(int *)(param_1 + 0x100) == 0) {
    func_0017f488(param_1,param_2,param_3,0.0f,param_2);
    return;
  }
  func_001802d8(*(u32 *)(param_1 + 0xfc),*(int *)(param_1 + 0x100),
               *(u32 *)(param_1 + 0xf0),*(u32 *)(param_1 + 8),param_2,0);
  return;
}
'''),
    ('float3_call4', '''
extern "C" u32 func_0017f488(s32,s32,float,float);
extern "C" void func_001802d8(u32,u32,u32,u32,u32,u32);

void func_00180c88(u32 param_1,s32 param_2,float param_3)
{
  if (*(int *)(param_1 + 0x100) == 0) {
    func_0017f488(param_1,param_2,param_3,0.0f);
    return;
  }
  func_001802d8(*(u32 *)(param_1 + 0xfc),*(int *)(param_1 + 0x100),
               *(u32 *)(param_1 + 0xf0),*(u32 *)(param_1 + 8),param_2,0);
  return;
}
'''),
    ('float34_call5', '''
extern "C" u32 func_0017f488(s32,s32,float,float,s32);
extern "C" void func_001802d8(u32,u32,u32,u32,u32,u32);

void func_00180c88(u32 param_1,s32 param_2,float param_3,float param_4)
{
  if (*(int *)(param_1 + 0x100) == 0) {
    func_0017f488(param_1,param_2,param_3,0.0f,param_2);
    return;
  }
  func_001802d8(*(u32 *)(param_1 + 0xfc),*(int *)(param_1 + 0x100),
               *(u32 *)(param_1 + 0xf0),*(u32 *)(param_1 + 8),param_2,0);
  return;
}
'''),
    ('float34_call4', '''
extern "C" u32 func_0017f488(s32,s32,float,float);
extern "C" void func_001802d8(u32,u32,u32,u32,u32,u32);

void func_00180c88(u32 param_1,s32 param_2,float param_3,float param_4)
{
  if (*(int *)(param_1 + 0x100) == 0) {
    func_0017f488(param_1,param_2,param_3,0.0f);
    return;
  }
  func_001802d8(*(u32 *)(param_1 + 0xfc),*(int *)(param_1 + 0x100),
               *(u32 *)(param_1 + 0xf0),*(u32 *)(param_1 + 8),param_2,0);
  return;
}
'''),
    ('float3_call6', '''
extern "C" u32 func_0017f488(s32,s32,float,float,s32,s32);
extern "C" void func_001802d8(u32,u32,u32,u32,u32,u32);

void func_00180c88(u32 param_1,s32 param_2,float param_3)
{
  if (*(int *)(param_1 + 0x100) == 0) {
    func_0017f488(param_1,param_2,param_3,0.0f,param_2,0);
    return;
  }
  func_001802d8(*(u32 *)(param_1 + 0xfc),*(int *)(param_1 + 0x100),
               *(u32 *)(param_1 + 0xf0),*(u32 *)(param_1 + 8),param_2,0);
  return;
}
'''),
    ('float3_pair', '''
extern "C" u32 func_0017f488(s32,s32,double,s32);
extern "C" void func_001802d8(u32,u32,u32,u32,u32,u32);

void func_00180c88(u32 param_1,s32 param_2,float param_3)
{
  if (*(int *)(param_1 + 0x100) == 0) {
    func_0017f488(param_1,param_2,0.0,param_2);
    return;
  }
  func_001802d8(*(u32 *)(param_1 + 0xfc),*(int *)(param_1 + 0x100),
               *(u32 *)(param_1 + 0xf0),*(u32 *)(param_1 + 8),param_2,0);
  return;
}
'''),
]

TARGET_002BC2E8 = [
    ('swap_args', '''
extern "C" s32 func_002bc158(void);
extern "C" void func_002bb310(s32,u32,u32,u32);

u32 func_002bc2e8(u32 param_1,u32 param_2,u32 param_3)
{
  s32 lVar2;
  u32 uVar1;
  lVar2 = func_002bc158();
  uVar1 = 0;
  if (lVar2 != 0) {
    func_002bb310(lVar2,param_2,param_1,param_3);
    uVar1 = *(u32 *)((int)lVar2 + 0x14);
  }
  return uVar1;
}
'''),
    ('swap_decl', '''
extern "C" s32 func_002bc158(void);
extern "C" void func_002bb310(s32,u32,u32,u32);

u32 func_002bc2e8(u32 param_2,u32 param_1,u32 param_3)
{
  s32 lVar2;
  u32 uVar1;
  lVar2 = func_002bc158();
  uVar1 = 0;
  if (lVar2 != 0) {
    func_002bb310(lVar2,param_1,param_2,param_3);
    uVar1 = *(u32 *)((int)lVar2 + 0x14);
  }
  return uVar1;
}
'''),
    ('temps', '''
extern "C" s32 func_002bc158(void);
extern "C" void func_002bb310(s32,u32,u32,u32);

u32 func_002bc2e8(u32 param_1,u32 param_2,u32 param_3)
{
  s32 lVar2;
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  lVar2 = func_002bc158();
  uVar2 = param_2;
  uVar3 = param_1;
  uVar1 = 0;
  if (lVar2 != 0) {
    func_002bb310(lVar2,uVar3,uVar2,param_3);
    uVar1 = *(u32 *)((int)lVar2 + 0x14);
  }
  return uVar1;
}
'''),
    ('early_call_order', '''
extern "C" s32 func_002bc158(void);
extern "C" void func_002bb310(s32,u32,u32,u32);

u32 func_002bc2e8(u32 param_1,u32 param_2,u32 param_3)
{
  s32 lVar2;
  u32 uVar1;
  lVar2 = func_002bc158();
  if (lVar2 != 0) {
    func_002bb310(lVar2,param_1,param_2,param_3);
    uVar1 = *(u32 *)((int)lVar2 + 0x14);
  } else {
    uVar1 = 0;
  }
  return uVar1;
}
'''),
]

TARGETS = {
    '00180c88': TARGET_00180C88,
    '002bc2e8': TARGET_002BC2E8,
}


def main(argv: list) -> int:
    address = argv[0]
    written = write_variants(address, TARGETS[address])
    listfile = Path(__file__).resolve().parent / f'r2_list_{address}.txt'
    lines = [path.as_posix().replace('C:/Users/KoZa/Documents/AGENTS/Codex',
                                    '/mnt/c/Users/KoZa/Documents/AGENTS/Codex')
             for path in written]
    listfile.write_text('\n'.join(lines) + '\n', newline='\n')
    print('\n'.join(str(path.name) for path in written))
    print(f'list: {listfile}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main(sys.argv[1:]))
