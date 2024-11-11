#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int height;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
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

int getBalance(struct node *node) {
    if (node==NULL)
        return 0;
    return height(node->left)-height(node->right);
}

void updateHeight(struct node *node) {
    if (node!=NULL){
        int leftHeight=height(node->left);
        int rightHeight=height(node->right);
        if (leftHeight>rightHeight){
            node->height=leftHeight+1;
        }
        else{
            node->height = rightHeight + 1;
        }
    }
}

struct node *rightRotate(struct node *y){
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

struct node *leftRotate(struct node *x){
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left=x;
    x->right=T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

struct node *insert(struct node *node, int data){
    if(node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    updateHeight(node);
    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void inOrderTraversal(struct node *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main(){
    struct node *root = NULL;
    int i, n, value;
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter node %d value: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("In-order traversal of the AVL tree:\n");
    inOrderTraversal(root);
    printf("\n");
    return 0;
}