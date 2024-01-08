#include "Queue.h"
using namespace std;
Queue *QueueNew(void) {
    Queue *q = new Queue;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}
void QueueFree(Queue *q) {
    if (q->size == 0) {
        return ;
    }
    node *curr = q->head;
    while (curr != NULL) {
        node *temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete q;
}
node *newNode(Item it) {
    node *n = new node;
    n->item = it;
    n->next = NULL;
    return n;
}
void QueueEnqueue(Queue *q, Item it) {
    node *n = newNode(it);
    
    if (q->size == 0) {
        q->head = n;
    } else {
        q->tail->next = n;
    }
    q->tail = n;
    q->size++;
}
int QueueSize(Queue *q) {
    return q->size;
}
Item QueueDequeue(Queue *q) {
    Item it = q->head->item;
    node *temp = q->head;
    q->head = q->head->next;
    delete temp;
    q->size--;
    return it;

}
Item QueuePeek(Queue *q) {
    return q->head->item;
}