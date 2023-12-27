#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void insertOrdered(int *arr, int size, int value);

void printArray(int *arr, int size);

int main(void) {
	freopen("input.txt", "r", stdin);
	printf("Enter array size: ");
	int size = 0;
	if (scanf("%d", &size) != 1) {
		fprintf(stderr, "error: failed to read array size\n");
		exit(EXIT_FAILURE);
	} else if (size < 0) {
		fprintf(stderr, "error: invalid array size\n");
		exit(EXIT_FAILURE);
	}

	int *arr = new int[size + 1];
	if (arr == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	if (size > 0) {
		printf("Enter array values (must be in ascending order): ");
	}
	for (int i = 0; i < size; i++) {
		if (scanf("%d", &arr[i]) != 1) {
			fprintf(stderr, "error: failed to read array value\n");
			exit(EXIT_FAILURE);
		} else if (i > 0 && arr[i] < arr[i - 1]) {
			fprintf(stderr, "error: array is not in ascending order\n");
			exit(EXIT_FAILURE);
		}
	}

	printf("Array: ");
	printArray(arr, size);

	printf("Enter value to insert: ");
	int value = 0;
	if (scanf("%d", &value) != 1) {
		fprintf(stderr, "error: failed to read value\n");
		exit(EXIT_FAILURE);
	}

	insertOrdered(arr, size, value);
	printf("Array after inserting %d: ", value);
	printArray(arr, size + 1);

	free(arr);
	return EXIT_SUCCESS;
}

// !!! DO NOT MODIFY THE CODE ABOVE !!!
////////////////////////////////////////////////////////////////////////
// Your task

void insertOrdered(int *arr, int size, int value) {
	// TODO
	arr[size] = value;
	sort(arr, arr + size + 1);
	
}

////////////////////////////////////////////////////////////////////////
// !!! DO NOT MODIFY THE CODE BELOW !!!

void printArray(int *arr, int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		if (i > 0) {
			printf(", ");
		}
		printf("%d", arr[i]);
	}
	printf("]\n");
}

