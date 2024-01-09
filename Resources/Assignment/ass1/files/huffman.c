// Implementation of the Huffman module

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Counter.h"
#include "File.h"
#include "huffman.h"

// Task 1
void decode(struct huffmanTree *tree, char *encoding, char *outputFilename) {
    FILE *outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Unable to open file %s\n", outputFilename);
        return;
    }

    struct huffmanTree *currentNode = tree;
    for (int i = 0; encoding[i] != '\0'; i++) {
        if (encoding[i] == '0') {
            currentNode = currentNode->left;
        } else if (encoding[i] == '1') {
            currentNode = currentNode->right;
        }

        if (currentNode->left == NULL && currentNode->right == NULL) {
            fprintf(outputFile, "%c", currentNode->token[0]);
            currentNode = tree;
        }
    }

    fclose(outputFile);
}

// Task 3
struct huffmanTree *createHuffmanTree(char *inputFilename) {
	return NULL;
}

// Task 4
char *encode(struct huffmanTree *tree, char *inputFilename) {
	return NULL;
}

