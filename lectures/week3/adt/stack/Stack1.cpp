#include "Stack.h"
using namespace std;

Stack *StackNew(void) {
    Stack *s = new Stack;
    s->head = NULL;
    s->size = 0;
    return s;
}
void StackFree(Stack *s) {
    node *curr = s->head;
    while (curr != NULL) {
        node *temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete(s);
}
void StackPush(Stack *s, Item item) {
    node *n = new node;
    n->item = item;
    n->next = s->head;
    s->head = n;
    s->size++;
}
Item StackPop(Stack *s) {
    if (s->size == 0) {
        cout << "Error: Stack is empty" << endl;
    }
    Item item = s->head->item;
    node *newHead = s->head->next;
    delete s->head;
    s->head = newHead;
    s->size--;
    return item;
}
int StackSize(Stack *s) {
    return s->size;
}
Item StackPeek(Stack *s) {
    if (s->size == 0) {
        cout << "Error: Stack is empty";
        return -1;
    }
    return s->head->item;
}