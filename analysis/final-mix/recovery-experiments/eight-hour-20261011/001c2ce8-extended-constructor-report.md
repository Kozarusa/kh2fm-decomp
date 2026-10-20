# Extended constructor investigation: 001c2ce8

The best complete 76-byte proposal still swaps only the final table and mode stores. Restoring both forwarded payload arguments preserves that residual and confirms that omitted arguments are not the cause. Precise dependencies and volatile stores perturb additional preceding instructions. Next investigate canonical field aliasing across the final table and mode writes, rather than repeat argument restoration or broad memory barriers. No unsuccessful source is registered.

`001c2ce8-extended-constructor-evidence.json` binds 13 complete source/proof pairs. Types and higher-level identities remain provisional. No compiler-impossibility claim is made.
