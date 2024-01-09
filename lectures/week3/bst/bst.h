#pragma once
#include <bits/stdc++.h>
using namespace std;
typedef struct node node;


/*
Given a BST t and a value v, insert v into the BST and return the root of the updated BST
*/
node *bstInsert(struct node *tree, int val);

bool bstSearch(struct node *tree, int val);

node *bstJoin(struct node *t1, struct node *t2);

node *bstDelete(struct node *tree, int val);

////////////////////////////////////////////////////////////////////////

void bstFree(struct node *tree);

int bstSize(struct node *tree);

int bstHeight(struct node *tree);

node *bstPrune(struct node *tree, int lo, int hi);

////////////////////////////////////////////////////////////////////////

void bstShow(struct node *tree);

void bstInOrder(struct node *tree);

void bstPreOrder(struct node *tree);

void bstPostOrder(struct node *tree);

////////////////////////////////////////////////////////////////////////