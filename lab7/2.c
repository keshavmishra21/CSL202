#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int height;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data){
    struct node *tmp = malloc(sizeof(struct node));
    tmp->data=data;
    tmp->height=1;
    tmp->left=tmp->right=NULL;
    return tmp;
}

struct node *insert(struct node *node, int key){
    if (node==NULL){
        return createNode(key);
    }
    if (key<node->data){
        node->left=insert(node->left, key);
    } else if(key>node->data){
        node->right = insert(node->right, key);
    }
    return node;
}

int updateHeight(struct node *node) {
    if(node==NULL){
        return 0;
    }
    int leftHeight=updateHeight(node->left);
    int rightHeight=updateHeight(node->right);
    if(leftHeight>rightHeight){
        node->height=leftHeight + 1;
    }
    else{
    node->height=rightHeight + 1;
    }
    printf("Node %d has height %d\n", node->data, node->height);
    return node->height;
}

int main(){
    struct node *root=NULL;
    int i, n, value;
    printf("Enter the number of nodes in the AVL tree: ");
    scanf("%d",&n);
    for (i=0; i<n; i++){
        printf("Enter node %d value: ",i+1);
        scanf("%d", &value);
        root=insert(root, value);
    }
    printf("Height of each node in the AVL tree:\n");
    updateHeight(root);
    return 0;
}