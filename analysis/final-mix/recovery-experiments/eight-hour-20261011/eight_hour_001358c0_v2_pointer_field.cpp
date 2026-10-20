#include "../common/types.h"
struct Node{u32 table;u32 reserved;Node* next;};
extern "C" u8 D_00347d00;
extern "C" Node* D_00347cf0;
extern "C" void func_00135aa0(Node*);
void func_001358c0(Node* object)
{
 object->table=(u32)&D_00347d00;
 func_00135aa0(object);
 object->next=D_00347cf0;
 D_00347cf0=object;
}
