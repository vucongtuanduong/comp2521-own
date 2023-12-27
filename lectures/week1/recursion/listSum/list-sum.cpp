#include <bits/stdc++.h>
using namespace std;

struct node {
    int value;
    node *next;
}
int listSum(node *list) {
    if (list == NULL) {
        return 0;
    } else {
        return list->value + listSum(list->next);
    }
}
int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}