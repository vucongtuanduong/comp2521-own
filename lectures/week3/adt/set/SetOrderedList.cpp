#include "Set.h"
using namespace std;
#define DEFAULT_CAPACITY 64
struct Set{
    node *elems;
    int size;

};
struct node {
    int data;
    node *next;
};

static struct node *listInsert(struct node *list, int elem, bool *inserted);
static struct node *newNode(int elem);
static struct node *listDelete(struct node *list, int elem, bool *deleted);

/*
*/
Set *SetNew(void) {
    Set *s = new Set;
    s->elems = NULL;
    s->size = 0;
    return s;
}
void SetFree(Set *s) {
    node *curr = s->elems;
    while (curr != NULL) {
        node *temp = curr;
        curr  = curr->next;
        delete temp;
    }
    delete s;
}
bool SetContains(Set *s, int elem) {
    node *curr = s->elems;
    for (; curr != NULL && elem >= curr->elem; curr = curr->next) {
        if (elem == curr->elem) {
            return true;
        }
    }
    return false;
}
void SetInsert(Set *s, int elem) {
    bool inserted = false;
    s->elems = listInsert(s->elems, elem, &inserted);
    if (inserted) {
        s->size++;
    }   

    
    
}
void SetDelete(Set *s, int elem) {
    bool deleted = false;
    s->elems = listDelete(s->elems, elem, &deleted);
    if (deleted) {
        s->size--;
    }
}
int SetSize(Set *s) {
    return s->size;

}
void SetShow(Set *s) {
    for (int i = 0; i < s->size; i++) {
        cout << s->elems[i] << " ";
    }
    cout << endl;
}
static struct node *listInsert(struct node *list, int elem, bool *inserted) {
    if (list == NULL || elem < list->elem) {
        node *n = newNode(elem);
        new->next = list;
        *inserted = true;
        return n;
    } else if (elem == list->elem) {
        return list;
    } else {
        list->next = listInsert(list->next, elem, inserted);
        return list;
    }
}
static struct node *newNode(int elem) {
    node *n = new node;
    n->data = elem;
    n->next = NULL;
    return n;
}
static struct node *listDelete(struct node *list, int elem, bool *deleted) {
    if (list == NULL || elem < list->elem) {
		return list;
	} else if (elem == list->elem) {
		struct node *temp = list->next;
		free(list);
		*deleted = true;
		return temp;
	} else {
		list->next = listDelete(list->next, elem, deleted);
		return list;
	}
}