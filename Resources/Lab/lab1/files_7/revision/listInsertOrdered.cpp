#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;	
struct node {
	int value;
	struct node *next;
};

struct node *insertOrdered(struct node *list, int value);

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
		printf("Enter list values (must be in ascending order): ");
	}

	struct node *list = readList(size);

	printf("List: ");
	printList(list);

	printf("Enter value to insert: ");
	int value = 0;
	if (scanf("%d", &value) != 1) {
		fprintf(stderr, "error: failed to read value\n");
		exit(EXIT_FAILURE);
	}

	list = insertOrdered(list, value);
	printf("List after inserting %d: ", value);
	printList(list);

	freeList(list);
	return EXIT_SUCCESS;
}

// !!! DO NOT MODIFY THE CODE ABOVE !!!
////////////////////////////////////////////////////////////////////////
// Your task

struct node *insertOrdered(struct node *list, int value) {
	// TODO
	node *temp = list;
	node *curr = list;
	while (temp->value < value && temp->next != NULL) {
		curr = temp;
		temp  = temp->next;
	}
	if (temp->value < value) {
		temp->next = newNode(value);
	}
	else {
		node *newNodes = new node;
		newNodes->value = value;
		newNodes->next = temp;
		if (temp == list) {
			list = newNodes;
		}
		else {
			curr->next = newNodes;
		}
	}
	return list;
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
		} else if (curr != NULL && value < curr->value) {
			fprintf(stderr, "error: list is not in ascending order\n");
			exit(EXIT_FAILURE);
		}

		struct node *newN = newNode(value);
		if (list == NULL) {
			list = newN;
		} else {
			curr->next = newN;
		}
		curr = newN;
	}
	return list;
}

struct node *newNode(int value) {
	struct node *newN = new node;
	if (newN == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	newN->value = value;
	newN->next = NULL;
	return newN;
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

