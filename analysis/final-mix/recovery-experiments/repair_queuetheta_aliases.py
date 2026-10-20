"""Restore two explicit external aliases omitted by grouped declarations.

Preserve the first failed link and bind the narrow registry repair to original
bytes, independently compiled proposals, and the previous registry hash.
"""
import hashlib
import json
from pathlib import Path
import shutil

workspace = Path(__file__).resolve().parents[3]
reference = workspace.parent / "Public/tools/kh2-reference"
build = workspace / "analysis/final-mix/native-build"
experiments = Path(__file__).resolve().parent
registry = reference / "functions.tsv"

def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

assert digest(reference / "SLPM_666.75") == "d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87"
receipt = experiments / "queuetheta-external-alias-repair.json"
assert not receipt.exists()
old_text = registry.read_text()
rows = [line.split("\t") for line in old_text.splitlines() if line and not line.startswith("#")]
aliases = [("func_00103100", "00103100", "00103480"), ("func_00104a48", "00104a48", "00104da0")]
evidence = []
for symbol, address, caller in aliases:
    assert not any(row[0] == symbol or row[1].lower() == address for row in rows)
    source = experiments / f"fm_primary_queuetheta_recovered_{caller}.cpp"
    proof_path = source.with_suffix(".verification.json")
    proof = json.loads(proof_path.read_text())
    assert symbol in source.read_text()
    assert proof["source_sha256"] == digest(source)
    assert len(proof["rows"]) == 1 and proof["rows"][0]["exact_match"]
    evidence.append(dict(symbol=symbol, original_address=address,
                         caller=caller, source_sha256=digest(source),
                         independent_proof_sha256=digest(proof_path)))
old_hash = digest(registry)
failed_log = build / "primary-queuetheta-make-verify.log"
saved_log = experiments / "queuetheta-first-full-link-failure.log"
assert not saved_log.exists()
shutil.copy2(failed_log, saved_log)
saved_registry = experiments / "queuetheta-before-external-alias-repair.tsv"
assert not saved_registry.exists()
shutil.copy2(registry, saved_registry)
registry.write_text(old_text + "".join(f"{symbol}\t{address}\n" for symbol, address, _ in aliases))
manifest = build / "primary-queuetheta-external-alias-sync-inputs.json"
assert not manifest.exists()
manifest.write_text(json.dumps([dict(file="functions.tsv", expected_stage_sha256=old_hash)], indent=2) + "\n")
receipt.write_text(json.dumps(dict(reason="Grouped declarations omit two externally referenced function addresses from automatic alias collection.",
                                  original_registry_sha256=old_hash,
                                  repaired_registry_sha256=digest(registry),
                                  preserved_failure_sha256=digest(saved_log), aliases=evidence), indent=2) + "\n")
print("Preserved failed link; added two original-address aliases. Source and compiler flags unchanged.")
