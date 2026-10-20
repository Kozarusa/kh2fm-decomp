#!/usr/bin/env python3
"""Read-only treemap of main-executable code coverage. Run: python -I treemap.py [output.svg]

Each outer cell is a 64 KiB address block of SLPM_666.75; each inner cell is one declared code range,
sized by bytes. Green ranges are accepted C++ (exact symbol match); grey ranges are still original-byte fallback.
Prints the totals it drew so the README can quote the same numbers.
"""
import json
import sys
from collections import defaultdict
from html import escape

ROOT = r"C:\Users\KoZa\Documents\AGENTS"
LAYOUT = ROOT + r"\Public\tools\kh2-reference\layout.tsv"
RANGES = ROOT + r"\Codex\analysis\final-mix\native-build\compiler-range-verification.json"
OUT_DEFAULT = ROOT + r"\Codex\docs\progress.svg"

WIDTH, HEIGHT = 1200, 640
BLOCK = 0x10000
ACCEPTED, FALLBACK, FRAME, TEXT = "#2da44e", "#57606a", "#0d1117", "#e6edf3"


def read_layout():
    rows = []
    with open(LAYOUT, "r", encoding="utf-8") as handle:
        for line in handle:
            line = line.rstrip("\r\n")
            if not line or line.startswith("#"):
                continue
            parts = line.split("\t")
            if parts[0] == "addr":
                continue
            rows.append((parts[0], int(parts[2])))
    return rows


def squarify(items, x, y, w, h):
    """items: list of (weight, payload) sorted descending. Returns list of (payload, x, y, w, h)."""
    out = []
    total = sum(weight for weight, _ in items)
    if not items or total <= 0 or w <= 0 or h <= 0:
        return out
    scale = w * h / total
    queue = [(weight * scale, payload) for weight, payload in items]
    while queue:
        short = min(w, h)
        row, area = [], 0.0
        best = float("inf")
        while queue:
            candidate = row + [queue[0]]
            candidate_area = area + queue[0][0]
            side = candidate_area / short
            worst = max(max(side * side / a, a / (side * side)) for a, _ in candidate)
            if row and worst > best:
                break
            row, area, best = candidate, candidate_area, worst
            queue.pop(0)
        side = area / short if short else 0
        offset = 0.0
        for cell_area, payload in row:
            length = cell_area / side if side else 0
            if w >= h:
                out.append((payload, x, y + offset, side, length))
            else:
                out.append((payload, x + offset, y, length, side))
            offset += length
        if w >= h:
            x, w = x + side, w - side
        else:
            y, h = y + side, h - side
    return out


def main():
    target = sys.argv[1] if len(sys.argv) > 1 else OUT_DEFAULT
    layout = read_layout()
    with open(RANGES, "r", encoding="utf-8") as handle:
        accepted = {r["address"] for r in json.load(handle) if r.get("unmodified_compiled_symbol_match")}

    blocks = defaultdict(list)
    for address, size in layout:
        blocks[int(address, 16) // BLOCK].append((address, size, address in accepted))

    block_items = []
    for key, funcs in blocks.items():
        done = sum(size for _, size, ok in funcs if ok)
        whole = sum(size for _, size, _ in funcs)
        block_items.append((whole, (key, sorted(funcs, key=lambda f: -f[1]), done, whole)))
    block_items.sort(key=lambda item: -item[0])

    total = sum(size for _, size in layout)
    done_total = sum(size for address, size in layout if address in accepted)

    svg = [f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 {WIDTH} {HEIGHT + 40}" width="{WIDTH}" role="img" '
           f'aria-label="Code coverage treemap: {done_total:,} of {total:,} declared code bytes recovered">',
           f'<rect width="{WIDTH}" height="{HEIGHT + 40}" fill="{FRAME}"/>',
           f'<text x="8" y="22" fill="{TEXT}" font-family="sans-serif" font-size="15">SLPM_666.75 declared code by 64 KiB address block: '
           f'<tspan fill="{ACCEPTED}">green</tspan> = accepted C++, <tspan fill="#8b949e">grey</tspan> = original-byte fallback '
           f'({done_total / total * 100:.1f}% of {total:,} bytes accepted)</text>']

    for (payload, bx, by, bw, bh) in squarify(block_items, 0, 34, WIDTH, HEIGHT):
        key, funcs, done, whole = payload
        title = f"{key * BLOCK:08x}: {done / whole * 100:.1f}% of {whole:,} bytes accepted"
        svg.append(f'<g><title>{escape(title)}</title>')
        svg.append(f'<rect x="{bx:.1f}" y="{by:.1f}" width="{bw:.1f}" height="{bh:.1f}" fill="{FRAME}"/>')
        inner = squarify([(size, (address, size, ok)) for address, size, ok in funcs], bx + 1.5, by + 1.5, bw - 3, bh - 3)
        for (address, size, ok), fx, fy, fw, fh in inner:
            if fw < 0.4 or fh < 0.4:
                continue
            svg.append(f'<rect x="{fx:.1f}" y="{fy:.1f}" width="{fw:.1f}" height="{fh:.1f}" '
                       f'fill="{ACCEPTED if ok else FALLBACK}" stroke="{FRAME}" stroke-width="0.4"><title>{address} ({size} bytes)</title></rect>')
        if bw > 70 and bh > 24:
            svg.append(f'<text x="{bx + 5:.1f}" y="{by + 14:.1f}" fill="{TEXT}" font-family="monospace" font-size="11" '
                       f'stroke="{FRAME}" stroke-width="2.5" paint-order="stroke">{key * BLOCK:08x} {done / whole * 100:.0f}%</text>')
        svg.append('</g>')
    svg.append('</svg>')

    with open(target, "w", encoding="utf-8", newline="\n") as handle:
        handle.write("\n".join(svg) + "\n")
    print(f"wrote {target}: {len(layout):,} ranges, {len(accepted):,} accepted, "
          f"{done_total:,}/{total:,} bytes ({done_total / total * 100:.1f}%)")


if __name__ == "__main__":
    main()
