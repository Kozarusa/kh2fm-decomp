"""Generate analysis/final-mix/worker-coordination/worker-b/round-4/batch1.targets.json.

Recomputes each range's SHA256 straight from tools/kh2-reference/SLPM_666.75 and
binds it with the layout.tsv size/end, so the round-4 evidence is self-verifying.
"""
import hashlib
import json
from pathlib import Path

ROOT = Path(r"C:/Users/KoZa/Documents/AGENTS/Codex")
TOOLS = Path(r"C:/Users/KoZa/Documents/AGENTS/Public/tools")
ELF = TOOLS / "kh2-reference/SLPM_666.75"
LTS = TOOLS / "kh2-reference/layout.tsv"
OUT = ROOT / "analysis/final-mix/worker-coordination/worker-b/round-4/batch1.targets.json"

ADDRESSES = "0030f690 0030a300 002f1e00 00150de0 002e8290 00229d40 001ac700 0017dec0".split()


def addr_to_offset(address):
    return address - 0x100000 + 0x1000


def main():
    blob = ELF.read_bytes()
    elf_sha = hashlib.sha256(blob).hexdigest()
    assert elf_sha == "d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87"

    layout = {}
    with LTS.open(encoding="utf-8", errors="replace") as f:
        for line in f:
            if line.startswith("#"):
                continue
            parts = line.strip().split("\t")
            if len(parts) < 3 or len(parts[0]) != 8:
                continue
            try:
                layout[parts[0]] = (int(parts[2]), parts[1])
            except ValueError:
                pass
    print("layout ranges:", len(layout))

    doc = {"original_elf_sha256": elf_sha, "targets": []}
    for a in ADDRESSES:
        size, end = layout[a]
        off = addr_to_offset(int(a, 16))
        data = blob[off:off + size]
        sha = hashlib.sha256(data).hexdigest()
        doc["targets"].append({"address": a, "size": size, "end": end,
                               "original_range_sha256": sha})
        print(a, size, end, sha[:16])

    OUT.write_text(json.dumps(doc, indent=2) + "\n", newline="\n")
    print("wrote", OUT)


if __name__ == "__main__":
    main()
