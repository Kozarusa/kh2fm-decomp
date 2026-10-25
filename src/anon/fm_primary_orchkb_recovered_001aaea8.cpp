#include "../common/types.h"
struct Texture {
    s32 format;
    s32 base;
    s32 width_log;
    s32 height_log;
    u8 pad[2];
    u8 width_div;
    u8 height_div;
};
extern "C" const void* D_0036d758[6];

u64 func_001aaea8(Texture* texture, s32 value) {
    s32 width_log = texture->width_log;
    // why: the dispatch jumps through extern D_0036d758 (lw t5 from the table, jr t5, as in the original); this named table only takes the label addresses so the wide/wider blocks stay reachable (pattern of accepted fm_primary_orchiy_recovered_001815d0.cpp); without it the case blocks are dropped (pfix2 v2: 224/240 bytes, 40 words)
    static const void* targets[6] asm("fm_switch_table_001aaea8") = {
        &&done, &&done, &&done, &&wide, &&wider, &&done};
    s32 width_count = (1 << width_log) / texture->width_div;
    s32 height_log = texture->height_log;
    s32 count = value / (width_count * ((1 << height_log) / texture->height_div));
    s32 size = 36;
    if (count >= 2) {
        size = 44;
    }
    s32 mode = 8 + (count & 1);
    s32 format = texture->format;
    if ((u32)format >= 6) goto done;
    goto *D_0036d758[format];
wide:
    mode += 2;
    goto done;
wider:
    mode += 4;
done:
    // GS TEX0 packing: tbp0, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld
    return (u64)texture->base | (u64)((1 << width_log) / 64) << 14 | (u64)size << 20 |
           (u64)width_log << 26 | (u64)height_log << 30 | (u64)1 << 34 | (u64)0 << 35 |
           (u64)0x3ffc << 37 | (u64)0 << 51 | (u64)0 << 55 | (u64)mode << 56 | (u64)0 << 61;
}
