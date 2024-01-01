#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
}; // Added semicolon here

node *create_node(int data, node *next);
node *add_node_end_of_list(int data, node *head); // Added int type for data parameter
node *insert_at_tail(int data, node *head);
node *insert_at_loc(int data, int location, node *head);
void print_list(node *head);
void insert_middle(int data, node *head, int position);
int list_size(node *head);
node *delete_node (node *head, int value);
node *delete_node_from_tail(node *head);
node *delete_at_pos(node *head, int position);
int main () {
    // node *head = NULL;
    node *head = NULL;
    head = create_node(1,NULL);
    print_list(head);
    head=  insert_at_loc(2,1,head);
    print_list(head);
    head = insert_at_loc(3,1, head);
    print_list(head);
    head = insert_at_loc(4,0, head);
    print_list(head);
}
node *delete_at_pos(node *head, int position) {
    if (head == NULL) {
        return head;
    }
    node *curr = head;
    node *prev = NULL;
    int count = 0;
    //to the final node
    while (curr->next != NULL) {
        if (count == position) {
            //we want to delete
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
        //the actual traversal
        prev = curr;
        curr = curr->next;
        count++;
    }

    
}
node *delete_node_from_tail(node *head) {
    node *curr = head;
    node *prev = NULL;
    if (head == NULL) {
        return head;
    }
    //get to the final node
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    //now , curr is the last node
    delete curr;
    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = NULL;
    }
    return head;
}
node *insert_at_loc(int data, int location, node *head) {
    if (head == NULL) {
        return head;
    }
    node *curr = head;
    int count = 1;
    while (curr != NULL) {
        if (count == location) {
            node *new_node = create_node(data, NULL);
            new_node->next = curr->next;
            curr->next = new_node;
            return head;
        }
        count++;
        curr = curr->next;
    }
    return head;
}
node *insert_at_tail(int data, node *head) {
    node *curr = head;
    if (head == NULL ) {
        head = create_node(data, NULL);
        return head;
    }
    //traverse the list until we get to the last node
    while (curr->next != NULL) {
        curr = curr->next;
    }
    //curr should be pointing at the last node in the list atm
    curr->next = create_node(data,NULL);
    return head;
}
node *delete_node (node *head, int value) {
    node *curr = head;
    node *prev = NULL;
    //1. Empty list?
    if (curr == NULL) {
        return head;
    }
    //2.delete the head of the list?
    if (curr->data == value) {
        head = curr->next;
        delete curr;
        return head;
    }
    //perfect case?
    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        return head;
    } else if (curr->data == value) {
        prev->next = curr->next;
        delete curr;
        
    }
    return head;
}
void insert_middle(int data, node *head, int position) {
    node *new_node = create_node(data, NULL);
    int count = 1;
    node *curr = head;
    while (curr != NULL && count != position) {
        curr = curr->next;
        count++;
    }
    if (count == position) {
        new_node->next = curr->next;
        curr->next = new_node;
    }
}
int list_size(node *head) {
    int count = 0;
    node *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}
void print_list(node *head) {
    node *curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

node *create_node(int data, node *next) {
    node *new_node = new node;
    new_node -> data = data;
    new_node->next = next;
    return new_node;
}

node *add_node_end_of_list(int data, node *head) { // Added int type for data parameter
    if (head == NULL) {
        return create_node(data, NULL);
    }
    node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = create_node(data, NULL);
    return head;
}