#pragma once
#include <bits/stdc++.h>
using namespace std;
typedef int Item;
struct node {
    Item item;
    node *next;
};
struct Stack{
    node *head;
    int size;
};
/*
create a new, empty stack
*/
Stack *StackNew();

/*
free memory used by stack
*/
void StackFree(Stack *s);


/**
 * Adds an item to the top of a Stack
 */
void StackPush(Stack *s, Item item);

/**
 * Removes an item from the top of a Stack
 * Assumes that the Stack is not empty
 */
Item StackPop(Stack *s);

/**
 * Gets the number of items in a Stack
 */
int StackSize(Stack *s);

/**
 * Gets the item at the top of a Stack without removing it
 * Assumes that the Stack is not empty
 */
Item StackPeek(Stack *s);