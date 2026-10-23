#include "../common/types.h"

s8* func_002ff918(s8* text, s8* pattern) {
    if (text[0] == 0) {
        if (pattern[0] != 0) return 0;
        return text;
    }
    s32 index = 0;
    while (text[0] != 0) {
        index = 0;
        while (1) {
            s8 pattern_char = pattern[index];
            if (pattern_char == 0) return text;
            s8 text_char = text[index];
            if (pattern_char == text_char) {
                index = index + 1;
            } else {
                text = text + 1;
                break;
            }
        }
    }
    return 0;
}
