#include "../common/types.h"

struct Pair {
    s32 first;
    s32 second;
};

struct Node {
    s32 value;
    s32 words[8];
    s32 field24;
    s32 field28;
    s32 field2c;
    Pair pairs[4];
    Node* next;
};

extern "C" Node* D_01d49350[];

void func_001c0150(Node* node, s32 value) {
    s32 index;
    node->value = value;
    for (index = 0; index < 8; index++) {
        node->words[index] = 0;
    }
    node->field24 = 0;
    node->field28 = 0;
    node->field2c = 0;
    Pair* pair = node->pairs;
    index = 3;
    do {
        pair->first = 0;
        pair++;
    } while (index-- != 0);
    Node** list = D_01d49350;
    if (list[1] == 0) {
        list[1] = node;
        list[0] = node;
        node->next = 0;
        return;
    }
    list[1]->next = node;
    node->next = 0;
    list[1] = node;
}
