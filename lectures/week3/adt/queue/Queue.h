#pragma once
#include <bits/stdc++.h>
using namespace std;
typedef int Item;
struct node {
    Item item;
    node *next;
};
struct Queue{
    node *head;
    node *tail;
    int size;
};
node *newNode(Item it);
/**
 * Creates a new, empty Queue
 */
Queue *QueueNew(void);

/**
 * Frees memory allocated to a Queue
 */
void QueueFree(Queue *q);

/**
 * Adds an item to the end of a Queue
 */
void QueueEnqueue(Queue *q, Item it);

/**
 * Removes an item from the front of a Queue
 * Assumes that the Queue is not empty
 */
Item QueueDequeue(Queue *q);

/**
 * Gets the number of items in a Queue
 */
int QueueSize(Queue *q);

/**
 * Gets the item at the front of a Queue without removing it
 * Assumes that the Queue is not empty
 */
Item QueuePeek(Queue *q);