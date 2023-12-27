#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node {
    int value;
    struct node *next;
};

int listSum(struct node *list);
struct node *newNode(int value);
void printList(struct node *list);
void freeList(struct node *list);
node *listAppend1(node *list, int value);
node *listAppend(node *list, int value);

int main(void) {
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    struct node *list = NULL;

    int value = 0;
    while (scanf("%d", &value) == 1) {
        list = listAppend(list, value);
    }

    printf("List: ");
    printList(list);

    printf("Sum: %d\n", listSum(list));

    freeList(list);
}

node *listAppend1(node *list, int value) {
    if (list == NULL) {
        return newNode(value);
    } else if (list->next == NULL) {
        list->next = newNode(value);
        return list;
    }
     else {
        listAppend(list->next, value);
        return list;
    }
    return NULL;
    //works but not very elegant, as it repeats the call to newNode and repeats `return list`
}

node *listAppend(node *list, int value) {
    if (list == NULL) {
        return newNode(value);
    } else {
        list->next = listAppend(list->next, value);
        return list;
    }
}
int listSum(struct node *list) {
    if (list == NULL) {
        return 0;
    } else {
        return list->value + listSum(list->next);
    }
}

struct node *newNode(int value) {
    struct node *n = new node;
    if (n == NULL) {
        fprintf(stderr, "error: out of memory\n");
        exit(EXIT_FAILURE);
    }

    n->value = value;
    n->next = NULL;
    return n;
}

void printList(struct node *list) {
    printf("[");
    for (node *curr = list; curr != NULL; curr = curr->next) {
        cout << curr->value ;
        if (curr->next != NULL) {
            cout << ",";
        }
    }

    printf("]\n");
}

void freeList(struct node *list) {
    node *curr = list;
    while (curr != NULL) {
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    
}