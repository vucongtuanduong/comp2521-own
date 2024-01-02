#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node {
	int value;
	struct node *next;
};

struct node *shift(struct node *list, int n);

struct node *readList(int size);
struct node *newNode(int value);
void printList(struct node *list);
void freeList(struct node *list);

int main(void) {
	freopen("input.txt", "r", stdin);
	printf("Enter list size: ");
	int size = 0;
	if (scanf("%d", &size) != 1) {
		fprintf(stderr, "error: failed to read list size\n");
		exit(EXIT_FAILURE);
	} else if (size < 0) {
		fprintf(stderr, "error: invalid list size\n");
		exit(EXIT_FAILURE);
	}

	if (size > 0) {
		printf("Enter list values: ");
	}

	struct node *list = readList(size);

	printf("List: ");
	printList(list);

	printf("Enter shift: ");
	int n = 0;
	if (scanf("%d", &n) != 1) {
		fprintf(stderr, "error: failed to read shift\n");
		exit(EXIT_FAILURE);
	} else if (n < 0) {
		fprintf(stderr, "error: invalid shift\n");
		exit(EXIT_FAILURE);
	}

	list = shift(list, n);
	printf("List after shifting %d time(s): ", n);
	printList(list);

	freeList(list);
	return EXIT_SUCCESS;
}

// !!! DO NOT MODIFY THE CODE ABOVE !!!
////////////////////////////////////////////////////////////////////////
// Your task

struct node *shift(struct node *list, int n) {
	// TODO
	node *temp = list;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	int x = n % count;
	int y = count - x;
	if (x == 0) {
		return list;

	} else {
		node *curr = list;
		node *prev = list;
		for (int i = 0; i < y - 1; i++) {
			curr = curr->next;
		}
		list = curr->next;
		curr->next = NULL;
		curr = list;
        //go to the last node
		while (curr->next != NULL) {
			curr = curr->next;
		}
        //connect the last node to the first node
		curr->next = prev;
		return list;
	}
}

////////////////////////////////////////////////////////////////////////
// !!! DO NOT MODIFY THE CODE BELOW !!!

struct node *readList(int size) {
	struct node *list = NULL;
	struct node *curr = NULL;
	for (int i = 0; i < size; i++) {
		int value = 0;
		if (scanf("%d", &value) != 1) {
			fprintf(stderr, "error: failed to read list value\n");
			exit(EXIT_FAILURE);
		}

		struct node *newP = newNode(value);
		if (list == NULL) {
			list = newP;
		} else {
			curr->next = newP;
		}
		curr = newP;
	}
	return list;
}

struct node *newNode(int value) {
	struct node *newP = new node;
	if (newP == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	newP->value = value;
	newP->next = NULL;
	return newP;
}

void printList(struct node *list) {
	printf("[");
	for (struct node *curr = list; curr != NULL; curr = curr->next) {
		printf("%d", curr->value);
		if (curr->next != NULL) {
			printf(", ");
		}
	}
	printf("]\n");
}

void freeList(struct node *list) {
	struct node *curr = list;
	while (curr != NULL) {
		struct node *temp = curr;
		curr = curr->next;
		free(temp);
	}
}
