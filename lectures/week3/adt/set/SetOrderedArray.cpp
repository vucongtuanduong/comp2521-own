#include "Set.h"
using namespace std;
#define DEFAULT_CAPACITY 64
struct Set{
    int *elems;
    int size;
    int capacity;
};
static int getCeilingIndex(Set s, int elem) {
    //binary search
    int lo = 0;
    int hi = s->size - 1;
    int closest = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (elem < s->elems[mid]) {
            closest = mid;
            hi = mid - 1;
        } else if (elem > s->elems[mid]) {
            lo = mid + 1;
        } else {
            return mid;
        }
    }
    return closet;
}
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
    int index = getCeilingIndex(s, elem);
    if (index != -1 && s->elems[index] == elem) {
        return true;
    }
    return false;
}
void SetInsert(Set *s, int elem) {
    int index = getCeilingIndex(s, elem);
    if (index != -1 && s->elems[index] == elem) {
        return;
    }  
    if (s->size == s->capacity) {
        cout << "Set is full! \n";
        return ; 
    }
    int insertIndex = index;
    if (index == -1) {
        insertIndex = s->size;
    } 
    for (int i = s->size - 1; i >= insertIndex; i--) {
        s->elems[i + 1] = s->elems[i];
    }
    s->elems[insertIndex] = elem;
    s->size++;
    
    
}
void SetDelete(Set *s, int elem) {
    int index = getCeilingIndex(s, elem);
    if (index != -1 && s->elems[index] == elem) {
        for (int i = index; i < s->size - 1; i++) {
            s->elems[i] = s->elems[i + 1];
        
        }
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