"""Save original disassembly for fresh candidates; no compiler mutation."""
from pathlib import Path
import subprocess
base=Path(__file__).resolve().parent
for address in ('00105da8','0010c7f0','0011c4b0','0011f238','00137c50','001394d8','0014f030','0015b4c0','00262730','0027d450','002cb7c8','002cba50','003206f0'):
 result=subprocess.run(['docker','run','--rm','--platform','linux/amd64','-v','/root/kh2fm-build:/work:ro','-w','/work','kh2-local/ps2-compiler:3.2-ee-040921-objdiff','/opt/ps2/gcc/bin/ee-objdump','-d',f'--start-address=0x{address}',f'--stop-address=0x{int(address,16)+56:x}','SLPM_666.75'],capture_output=True,text=True,check=True)
 path=base/f'{address}-fresh56-original.txt';assert not path.exists();path.write_text(result.stdout)
 print(result.stdout)
