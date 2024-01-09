#include "bst.h"
using namespace std;
struct node {
    int value;
    node *left;
    node *right;
};
static node *newNode(int val);
static void showBstNode(node *tree);
node *bstInsert(node *tree, int val) {
    if (tree == NULL) {
        return newNode(val);
    } else if (val < tree->value) {
        tree->left = bstInsert(tree->left, val);
    } else if (val > tree->value) {
        tree->right = bstInsert(tree->right, val);
    }
    return tree;
}
static node *newNode(int val) {
    node *n = new node;
    n->value = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}
bool bstSearch(struct node *tree, int val) {
    if (tree == NULL) {
        return false;
    }
    if (val < tree->value) {
        if (tree->left == NULL) {
            return false;
        } else {
            return bstSearch(tree->left, val);
        }
    } else if (val > tree->value) {
        if (tree->right == NULL) {
            return false;
        } else {
            return bstSearch(tree->right, val);
        }
    } else {
        return true;
    }
}
static void showBstNode(node *tree) {
    if (tree == NULL) {
        return;
    }
    cout << tree->value << " ";
}
void bstInOrder(node *tree) {
    if (tree == NULL) {
        return;
    }
    bstInOrder(tree->left);
    showBstNode(tree);
    bstInOrder(tree->right);
}
void bstPreOrder(node *tree) {
    if (tree == NULL) {
        return;
    }
    showBstNode(tree);
    bstPreOrder(tree->left);
    bstPreOrder(tree->right);
}
void bstPostOrder(node *tree) {
    if (tree == NULL) {
        return;
    }
    bstPostOrder(tree->left);
    bstPostOrder(tree->right);
    showBstNode(tree);
}
node *bstJoin(node *t1, node *t2) {
    //max t1 < min t2
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
node *bstDelete(node *tree, int val) {
    if (tree == NULL) {
        return NULL;
    } else if (val < tree->value) {
        tree->left = bstDelete(tree->left, val);
        return tree;
    } else if (val > tree->value) {
        tree->right = bstDelete(tree->right, val);
        return tree;
    } else {
        //if t is a leaf
        if (tree->left == NULL && tree->right == NULL) {
            delete tree;
            return NULL;
        } else if (tree->left == NULL) {
            node *temp = tree->right;
            delete tree;
            return temp;
        } else if (tree->right == NULL) {
            node *temp = tree->left;
            delete tree;
            return temp;
        } else {
            node *joined = bstJoin(tree->left, tree->right);
            delete tree;
            return joined;
        }
        
        
    }
}
void bstFree(node *tree) {
    if (tree == NULL) {
        return ;
    }
    bstFree(tree->left);
    bstFree(tree->right);
    delete tree;
}
int bstSize(node *tree) {
    if (tree == NULL) {
        return 0;
    }
    return 1 + bstSize(tree->left) + bstSize(tree->right);
}
int bstHeight(node *tree) {
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
node *bstPrune(node *tree, int lo, int hi) {
    //delete all the value not in the range from lo to hi
    if (tree == NULL) {
        return NULL;
    } else {
        tree->left = bstPrune(tree->left, lo, hi);
        tree->right = bstPrune(tree->right,lo,hi);

        if (tree->value >= lo && tree->value <= hi) {
            return tree;
        } else if (tree->value < lo) {
            node *temp = tree->right;
            delete tree;
            return temp;
        } else {
            node *temp = tree->left;
            delete tree;
            return temp;
        }

    }
}