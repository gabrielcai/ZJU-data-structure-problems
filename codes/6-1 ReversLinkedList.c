
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ?????? */
void Print( List L ); /* ?????? */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Reverse( List L){
    List prev , current , next;
    prev = NULL;
    current  = L;
    while(current != NULL){
        next = current->Next;
        current -> Next = prev;
        prev = current;
        current = next;
        }
    current = prev;
    return current;
    }
