#include <bits/stdc++.h>
using namespaces std;
struct node {
    int value;
    node *next;

};
struct list {
	struct node *head;
};
int listLength(struct node *l);
int listCountOdds(struct node *l);
bool listIsSorted(struct node *l);
 node *listDelete(struct node *l, int value);
int main () {


    return 0;
}
 node *listDelete(struct node *l, int value) {
    if (l == NULL) {
        return l;
    }
    if (l->value == value) {
        node *temp = l->next;
        delete l;
        return temp;
    }
    l->next = listDelete(l->next, value);
    return l;
}
int listLength(struct node *l) {
    if (l == NULL) {
        return 0;
    }
    return 1 + listLength(l->next);
}
int listCountOdds(struct node *l) {
    if (l == NULL) {
        return 0;
    }
    if (l->value % 2 == 1) {
        return 1 + listCountOdds(l->next);
    } else {
        return listCountOdds(l->next);
    }
}
bool listIsSorted(struct node *l) {
    //ascending order
    if (l == NULL || l->next == NULL) {
        return true;
    }
    if (l->value > l->next->value) {
        return false;
    }
    return listIsSorted(l->next);
}