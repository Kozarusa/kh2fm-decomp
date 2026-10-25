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

u64 func_001aaea8(Texture* texture, s32 value) {
    s32 width_log = texture->width_log;
    s32 width_count = (1 << width_log) / texture->width_div;
    s32 height_log = texture->height_log;
    s32 count = value / (width_count * ((1 << height_log) / texture->height_div));
    s32 size = 36;
    if (count >= 2) {
        size = 44;
    }
    s32 mode = 8 + (count & 1);
    switch (texture->format) {
    case 0:
    case 1:
    case 2:
    case 5:
        break;
    case 3:
        mode += 2;
        break;
    case 4:
        mode += 4;
        break;
    }
    // GS TEX0 packing: tbp0, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld
    return (u64)texture->base | (u64)((1 << width_log) / 64) << 14 | (u64)size << 20 |
           (u64)width_log << 26 | (u64)height_log << 30 | (u64)1 << 34 |
           (u64)0x3ffc << 37 | (u64)mode << 56;
}
