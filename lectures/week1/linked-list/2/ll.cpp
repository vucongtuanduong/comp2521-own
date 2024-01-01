#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *next;
};
node *create_node (int value, node *next);
node *insert_node(int value, int position, node *head);
node *delete_node(int position, node *head);
void print_list(node *head);
int main () {
    node *head = NULL;
    head = create_node(1,head);
    print_list(head);
    head=  insert_node(2,0,head);
    print_list(head);
    head = insert_node(3,1, head);
    print_list(head);
    head = insert_node(4,2, head);
    print_list(head);
    return 0;

}
void print_list(node *head) {
    node *curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
node *create_node (int value, node *next) {
    node *new_node = new node;
    new_node->data = value;
    new_node->next = next;
    return new_node;
}
node *insert_node(int value, int position, node *head) {
    if (head == NULL) {
        return create_node(value, NULL);
    }
    node *curr = head;
    int count = 0;
    while (curr != NULL) {
        if (count == position) {
            node *new_node = create_node(value, NULL);
            new_node->next = curr->next;
            curr->next = new_node;
            return head;
        }
        count++;
        curr = curr->next;
    }
    return head;
}
node *delete_node(int position, node *head) {
    if (head == NULL) {
        return head;
    }
    node *curr = head;
    node *prev = NULL;
    int count = 0;
    while (curr->next != NULL) {
        if (count == position) {
            if (prev == NULL) {
                head = NULL;
            } else {
                if (curr != NULL) {
                    prev->next = curr->next;
                } else {
                    prev->next = NULL;
                }
            }

        delete curr;
        return head;
        }
        count++;
        prev = curr;
        curr = curr->next;
    }
    return head;
}