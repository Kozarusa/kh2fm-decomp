# 00292a58 source and domain audit

The complete v1/v2 source comparison changes exactly one line:

```diff
-    func_002fde18(D_0035f4d4, 0, D_0035f4bc << 4);
+    func_002fde18(D_0035f4d4, 0, (s32)((u32)D_0035f4bc << 4));
```

All other source lines match, including declarations, global signedness, operand placement, the preceding zero store, function signature and final tail return. v1 is the unchanged rejected baseline and is never submitted.

For every s32 source value x, conversion to u32 is defined modulo 2^32, preserving the 32-bit pattern even when x is negative. u32 is unsigned int on this pinned 32-bit-int target; it is not promoted to signed int. Shifting that unsigned value by constant 4 (less than width 32) is defined modulo 2^32. Thus y = ((x modulo 2^32) * 16) modulo 2^32 for all 2^32 source patterns; no signed left shift or signed overflow remains.

Conversion of y to s32 is implementation-defined for y >= 0x80000000, not undefined. The pinned ee-g++ target preserves the low word using its two's-complement signed conversion, yielding y when y < 2^31 and y - 2^32 otherwise. This target-specific conversion is intentional: the resulting variadic operand remains signed s32, retaining original signed word extension. Original sll sign-extends its 32-bit result on this MIPS target. The exact v2 proof confirms the same lw/sll argument sequence, without an unsigned zero-extension change. This is defined under the pinned implementation, not a claim of implementation-independent signed conversion.

Boundary examples: x=0 gives 0; x=-1 gives low word 0xfffffff0 and signed -16; x=0x08000000 gives low word 0x80000000 and signed -2147483648; x=0x10000000 gives 0; x=-2147483648 gives 0. The modular formula covers all remaining patterns.

R4.3: no entry argument registers are consumed before assignment. The sole exit is a tail jump to 00292998, whose result is returned literally through return func_00292998(). No invented result or unresolved exit exists.

R4.5: extern "C" u32 func_002fde18(...); matches packet-named capacity and close declarations exactly. Other listed accepted sources contain the typed alternative; this correction preserves the selected baseline declaration as required. 00292998 has no packet-named accepted declaration.

R8 audit: exactly one function, nothing after it, declarations before body, mandatory include, no forbidden names, no assembly, no bindings, no null arithmetic. Both probes are exact 56/56 bytes with zero differing words; only corrected v2 is eligible for submission.
