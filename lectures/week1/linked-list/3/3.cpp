#include <bits/stdc++.h>
using namespace std;
struct node {
    int value;
    node *next;
};
struct List{
    node *head;
};
node *newNode(int value);
node *doListAppend(node *n, int value);
List *newList();
void ListAppend(List *l, int value);
void printList(List *l);
void freeList(List *l);
int main () {
    List *l = newList();

    int value;
    while (cin >> value) {
        ListAppend(l, value);
    }
    printList(l);
    freeList(l);
    return 0;
}
void freeList(List *l) {
    node *curr = l->head;
    while (curr != NULL) {
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }
}
void ListAppend(List *l, int value) {
    l->head = doListAppend(l->head, value);

}
node *doListAppend(node *n, int value) {
    if (n == NULL) {
        return newNode(value);
    } else {
        n->next = doListAppend(n->next, value);
        return n;
    }
}
void printList(List *l) {
    cout << "[";
    for (node *curr = l->head; curr != NULL; curr = curr->next) {
        cout << curr->value << " ";
    }
    cout << "]" << endl;
}
node *newNode(int value) {
    node *n = new node;
    n->value = value;
    n->next = NULL;
    return n;
}
List *newList() {
    List *l = new List;
    l->head = NULL;
    return l;
}