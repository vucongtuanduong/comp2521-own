#include "bst.h"
using namespace std;
static node *newNode(int val) {
    node *n = new node;
    n->value = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}
node *bstInsert(struct node *tree, int val) {
    if (tree == NULL) {
        return newNode(val);
    } else if (val < tree->value) {
        bstInsert(tree->left, val);
    } else if (val > tree->value) {
        bstInsert(tree->right, val);
    }
    return tree;
    
}
bool bstSearch(struct node *tree, int val) {
    if (tree == NULL) {
        return false;
    } else if (val < tree->value) {
        return bstSearch(tree->left, val);
    } else if (val > tree->value) {
        return bstSearch(tree->right, val);
    } else {
        return true;
    }
}
node *bstJoin(struct node *t1, struct node *t2) {
    if (t1 == NULL) {
        return t2;
    } else if (t2 == NULL) {
        return t1;
    }
    if (t2->left == NULL) {
        t2->left = t1;
        return t2;
    }
    node *min = t2;
    node *parent = NULL;
    while (min->left != NULL) {
        parent = min;
        min = min->left;
        
    }
    parent->left = min->right;

    min->left = t1;
    min->right = t2;
    return min;
}
node *bstDelete(struct node *tree, int val) {
    if (tree == NULL) {
        return NULL;
    } else if (val < tree->value) {
        tree->left = bstDelete(tree->left, val);
        return tree;
    } else if (val > tree->value) {
        tree->right = bstDelete(tree->right, val);
        return tree;
    } else {
        if (tree->left == NULL && tree->right == NULL) {
            free(tree);
            return NULL;
        } else if (tree->left == NULL) {
            node *temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            node *temp = tree->left;
            free(tree);
            return temp;
        } else {
            node *joined = bstJoin(tree->left, tree->right);
            free(tree);
            return joined;
        }
    }
}
void bstFree(struct node *tree) {
    if (tree == NULL) {
        return ;
    }
    
    bstFree(tree->left);
    bstFree(tree->right);
    free(tree);
}
int bstSize(struct node *tree) {
    if (tree == NULL) {
        return 0;
    }
    return 1 + bstSize(tree->left) + bstSize(tree->right);
}
int bstHeight(struct node *tree) {
    if (tree == NULL) {
        return -1;
    } else if (tree->left == NULL && tree->right == NULL) {
        return 0;
    } else {
        int leftHeight = bstHeight(tree->left);
        int rightHeight = bstHeight(tree->right);
        if (leftHeight > rightHeight) {
            return 1 + leftHeight;
        } else {
            return 1 + rightHeight;
        }
    }
}
node *bstPrune(struct node *tree, int lo, int hi) {
    if (tree == NULL) {
        return NULL;
    } else {
        tree->left = bstPrune(tree->left, lo, hi);
        tree->right = bstPrune(tree->right, lo, hi);

        if (tree->value >= lo && tree->value <= hi) {
            return tree;
        } else if (tree->value < lo) {
            node *temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->value > hi) {
            node *temp = tree->left;
            free(tree);
            return temp;
        }
    }
}