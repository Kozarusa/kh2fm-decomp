# Byte-store and float forwarding at 001b1bb8

The original routine preserves incoming f12 and the object in a0 when tail
transferring to 001b1be0. The child moves the scalar to f14, supplies zero in
f12 and a bound in f13, and forwards object+8 to 001ad990. Separate exact
child proofs now exist; the parent remains unaccepted.

The 40-byte parent writes four low-byte values at offsets 20, 23, 21 and 22.
An explicit register-15 cursor with the correct float/object helper signature
matches the prologue but rotates the final three byte stores. Cursor lifetime
outputs recover all three store positions but swap the first store with the
stack adjustment and the cursor address with the ra save. Volatile cursor,
precise first-byte store, memory inputs, and volatile first-store descriptions
do not match the entire original range. Byte-valued formal parameters add
four narrowing instructions and produce 56 bytes; retain the word-valued
transport hypothesis rather than repeating that profile.

The adjacent evidence JSON binds all source/proof hashes and complete-range
differences. No unsuccessful parent source is registered. No compiler
impossibility is established. A new experiment must coordinate prologue timing
with byte-store order without broad memory barriers or the tested cursor
markers. Original source parameter meanings remain provisional.
