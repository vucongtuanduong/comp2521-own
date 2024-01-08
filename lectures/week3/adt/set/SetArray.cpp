#include "Set.h"
using namespace std;
#define DEFAULT_CAPACITY 64
struct Set{
    int *elems;
    int size;
    int capacity;
};
Set *SetNew(void) {
    Set *s = new Set;
    s->elems = new int[DEFAULT_CAPACITY];
    s->size = 0;
    s->capacity = DEFAULT_CAPACITY;
    return s;
}
void SetFree(Set *s) {
    delete[] s->elems;
    delete s;
}
bool SetContains(Set *s, int elem) {
    for (int i = 0; i < s->size; i++) {
        if (s->elems[i] == elem) {
            return true;
        }
    }
    return false;
}
void SetInsert(Set *s, int elem) {
    if (SetContains(s, elem)) {
        return;
    } else {
        if (s->size == s->capacity) {
            cout << "Error: Set is full !" << endl;
            return;
        } 
    }
    s->elems[s->size] = elem;
    s->size++;
}
void SetDelete(Set *s, int elem) {
    if (!SetContains(s, elem)) {
        return;
    }
    for (int i = 0; i < s->size; i++) {
        if (s->elems[i] == elem) {
            s->elems[i] = s->elems[s->size - 1];
            s->size--;
            return;
        }
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