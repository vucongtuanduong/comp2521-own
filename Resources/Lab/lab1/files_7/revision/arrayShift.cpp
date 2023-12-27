#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

void shift(int *arr, int size, int n);

void printArray(int *arr, int size);

int main(void) {
	printf("Enter array size: ");
	int size = 0;
	if (scanf("%d", &size) != 1) {
		fprintf(stderr, "error: failed to read array size\n");
		exit(EXIT_FAILURE);
	} else if (size < 0) {
		fprintf(stderr, "error: invalid array size\n");
		exit(EXIT_FAILURE);
	}

	int *arr = new int[size];
	if (arr == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	if (size > 0) {
		printf("Enter array values: ");
	}
	for (int i = 0; i < size; i++) {
		if (scanf("%d", &arr[i]) != 1) {
			fprintf(stderr, "error: failed to read array value\n");
			exit(EXIT_FAILURE);
		}
	}

	printf("Array: ");
	printArray(arr, size);

	printf("Enter shift: ");
	int n = 0;
	if (scanf("%d", &n) != 1) {
		fprintf(stderr, "error: failed to read shift\n");
		exit(EXIT_FAILURE);
	} else if (n < 0) {
		fprintf(stderr, "error: invalid shift\n");
		exit(EXIT_FAILURE);
	}

	shift(arr, size, n);
	printf("Array after shifting %d time(s): ", n);
	printArray(arr, size);

	free(arr);
	return EXIT_SUCCESS;
}

// !!! DO NOT MODIFY THE CODE ABOVE !!!
////////////////////////////////////////////////////////////////////////
// Your task

void shift(int *arr, int size, int n) {
	// TODO
	
	int *b = new int[size];
	for (int i = 0; i < size; i++) {
		b[i] = arr[i];
	}
	int x = n % size;
	if (x == 0) {
		return;
	}
	int t = size - x;
	int j = 0;
	for (int i = t; i < size; i++) {
		arr[j++] = b[i];
	}
	for (int i = 0; i < t; i++) {
		arr[j++] = b[i];
	}
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
