# Recovery B batch 2: store scheduling residuals

Targets 001668f8 and 00166930 remain unregistered. Live layout sizes are 52 bytes for both. Their prior proof has only the two halfword store offsets swapped. New barrier-after-first, all-volatile, and combined assembly-store probes all compile to 52 bytes but do not match. Sources and complete hash-bound proofs are preserved alongside this report.

New hypothesis: constrain the final store to remain after the byte store while maintaining original return-address restore scheduling. The successful earlier 0014dbc8 experiment suggests a memory barrier immediately before the final volatile store may provide the needed dependency. Inspect complete differing offsets before trying this pattern. All probes are now idle for primary integration.
