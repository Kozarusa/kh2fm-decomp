# nm30 report
Status: done
Worker: orch1-nm30, model GPT-6 inherited. Started 2026-10-17T21:03:38Z, ended 2026-10-17T21:05:35Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 0028b078 | 100 | blocked:register-allocation | 4 | 5 | orch1_nm30_0028b078_v1.cpp |

Totals: 0 submitted, 1 blocked, 0 released.
Problems: Initial v2 save used unsupported Set-Content -NoNewline; source was absent and probe performed no compilation. Corrected with supported Set-Content before the successful v2 probe. No evidence overwritten. Strict streak3 reached after 22, 22, 15 words; unchanged v1 remains earliest best at 5 words.

## Failed v2 probe sequence addendum
The probe was invoked against the missing v2 source before supported Set-Content created it. The command batch did not stop after the save error. The same batch also invoked diff against the nonexistent proof. No compilation or verification proof resulted from that failed invocation. The subsequent batch created v2 with supported Set-Content, invoked its successful probe, then generated its diff. The original four-version accounting omitted the failed invocation; under conservative per-invocation counting it is a nonimprovement after v1, followed by successful v2 (22 words) and v3 (22 words), reaching strict streak3 at v3. Therefore v4 was beyond that conservatively counted limit. No further recovery work performed.

Exact relevant commands from the failed batch:
```powershell
$baseline = Get-Content -Raw 'Codex/analysis/final-mix/recovery-experiments/orch-shift1/nm30/orch1_nm30_0028b078_v1.cpp'; $candidate = $baseline.Replace('u16 count','u32 count'); Compare-Object ($baseline -split "`n") ($candidate -split "`n"); Set-Content -NoNewline 'Codex/analysis/final-mix/recovery-experiments/orch-shift1/nm30/orch1_nm30_0028b078_v2.cpp' $candidate
python Public/tools/kh2-audit/recovery_queue.py heartbeat --address 0028b078 --token b1fc7337d06b423a8f44a2131ec7d01a
python -I Codex/orchestration/tools/kh2w.py probe 'C:/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/orch-shift1/nm30/orch1_nm30_0028b078_v2.cpp'
python -I Codex/orchestration/tools/kh2w.py diff 'Codex/analysis/final-mix/recovery-experiments/orch-shift1/nm30/orch1_nm30_0028b078_v2.verification.json' 'Codex/analysis/final-mix/recovery-experiments/orch-shift1/nm30/orch1_nm30_0028b078_v2.diff.txt'
```
The batch also appended the intended v2 change note to PROGRESS.md after the failed save and before heartbeat/probe. Its exact text remains in that file.

Exact returned errors:
```text
Set-Content:
A parameter cannot be found that matches parameter name 'NoNewline'.
Traceback (most recent call last):
  File "/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py", line 26, in <module>
    text = source.read_text().replace('#include "../common/types.h"',
           ^^^^^^^^^^^^^^^^^^
  File "/usr/lib/python3.12/pathlib.py", line 1029, in read_text
    with self.open(mode='r', encoding=encoding, errors=errors) as f:
         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/usr/lib/python3.12/pathlib.py", line 1015, in open
    return io.open(self, mode, buffering, encoding, errors, newline)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
FileNotFoundError: [Errno 2] No such file or directory: '/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/orch-shift1/nm30/orch1_nm30_0028b078_v2.cpp'
Traceback (most recent call last):
  File "C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\tools\kh2w.py", line 304, in <module>
    diff(sys.argv[2], sys.argv[3] if len(sys.argv) > 3 else None)
  File "C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\tools\kh2w.py", line 223, in diff
    data = json.loads(proof_path.read_text())
  File "C:\Python314\Lib\pathlib\__init__.py", line 787, in read_text
    with self.open(mode='r', encoding=encoding, errors=errors, newline=newline) as f:
  File "C:\Python314\Lib\pathlib\__init__.py", line 771, in open
    return io.open(self, mode, buffering, encoding, errors, newline)
FileNotFoundError: [Errno 2] No such file or directory: 'C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\nm30\\orch1_nm30_0028b078_v2.verification.json'
```
