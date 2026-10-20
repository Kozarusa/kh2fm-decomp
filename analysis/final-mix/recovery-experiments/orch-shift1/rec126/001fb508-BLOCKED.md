# 001fb508 blocked
- Range: 001fb508, 76 bytes. Versions tried: 4. Best: v1 with 9 differing words (76/76 bytes).
- First difference of the best version: !! 001fb518: 0000282d  move	a1,zero | 001fb518: afad0010  sw	t5,16(sp)
- Changes tried: v1 local struct Args{object,second,table,scale,inner} (9); v2 C10a source store reorder (9, identical output); v3 C10d memory barrier (17); v4 temporaries for inner/second/scale (9, identical).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10c volatile struct stores, or C11 binding inner pointer to $13 / change struct field types so the sw 16(sp) schedules after swc1 12(sp).
