# Object recovery investigation: 00315678

The original first helper reads its object argument: the export at 003167f8 writes the incoming object vtable, and 0028b8a0 writes fields of its incoming object. Making that input explicit as an address-width word or pointer is supported by the exports, but all four new compiler profiles retain the two-word return-address-save/vtable-store scheduling swap. These types remain provisional. The next experiment must address joint table-address and prologue scheduling rather than repeat these argument profiles.

`00315678-object-evidence.json` binds 4 complete new source/proof pairs. No unsuccessful proposal is registered and no compiler-impossibility claim is made.
