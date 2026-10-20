from pathlib import Path
ex=Path(__file__).resolve().parent
area=ex.parent
root=area.parents[1]
for path in [area/'README.md',root/'WORKER_BRIEF.md',area/'worker-coordination/primary-status.md']:
 text=path.read_text(encoding='utf-8')
 if path.name=='primary-status.md':
  text=text.replace('current checkpoint passed.', 'current checkpoint passed.',1).replace('both switches, finalization', 'all three switch batches, finalization',1)
 text+='\nThe lookup-switch batch recovers complete 88-byte 00155ee8 and 80-byte 00155fc0 plus independently proves their two 20-byte compiler-generated label tables. All three switch batches now cover five code ranges and five generated tables. The tables match in auxiliary linked data; function references resolve to original absolute table addresses, and the rebuilt ELF still retains original table bytes. This is not data integration or a source-only rebuild. The new native table checker consumes hash-bound current compiler records and directly compares linked code as well as data.\n'
 path.write_text(text,encoding='utf-8')
with (ex/'primary-fourhour-blockers.md').open('a',encoding='utf-8') as output:
 output.write('\n## Resolved lookup-switch blockers\n\n00155ee8 and 00155fc0 are now fully accepted at 88 and 80 bytes. GNU computed-goto sources with generated label tables reproduce the original bounded dispatch; all 40 table bytes match independently and in the full native link. The first source variants crossed initialized declarations with fallback jumps and were rejected by the compiler; moved index declarations before the jumps in new variants. The first full table-verifier attempt expected a legacy small-batch proof file not produced by the current curated-bundle workflow. Adapted only the new batch to current compiler records and direct linked-code comparisons; earlier two switch batches passed unchanged. All 89 bundles and three switch receipts now pass. The legacy inspect_fm_small_batch.py helper still contains a historical ChatGPT output path; it was read but not executed or edited. Use the current curated-bundle workflow instead. Original tables are retained in the rebuilt ELF, so full data integration remains outstanding.\n')
