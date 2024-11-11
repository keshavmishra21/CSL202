#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int height;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data){
    struct node *tmp=malloc(sizeof(struct node));
    tmp->data=data;
    tmp->height=1;
    tmp->left=tmp->right=NULL;
    return tmp;
}

int height(struct node *node){
    if(node == NULL)
        return 0;
    return node->height;
}

void updateHeight(struct node *node){
    if(node == NULL)
        return;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    if(leftHeight>rightHeight){
        node->height = leftHeight+1;
    }
    else{
        node->height = rightHeight+1;
    }
}

int isBalanced(struct node *node){
    if (node == NULL)
        return 1;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    if (abs(leftHeight - rightHeight) > 1)
        return 0;
    return isBalanced(node->left) && isBalanced(node->right);
}

struct node *insert(struct node *node, int key){
    if (node==NULL)
        return createNode(key);
    if (key<node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    updateHeight(node);
    return node;
}
int main() {
    struct node *root = NULL;
    int n, value, i;
    printf("Enter the number of nodes in the BST: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter node %d value: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }
    if (isBalanced(root)) {
        printf("The tree is an AVL tree.\n");
    } else {
        printf("The tree is not an AVL tree.\n");
    }
    return 0;
}