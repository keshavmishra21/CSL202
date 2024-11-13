#include <stdio.h>
#include <stdlib.h>
struct node{
    int key;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *newNode(int key){
    struct node *tmp;
    tmp=malloc(sizeof(struct node));
    tmp->key=key;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
struct node *insert(struct node *root, int key) {
    if(root == NULL) {
        return newNode(key);
    }
    if(key < root->key) {
        root->left = insert(root->left, key);
    }
    else if(key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

struct node *findMax(struct node* root) {
    while(root&&root->right!=NULL) {
        root=root->right;
    }
    return root;
}
struct node *findMin(struct node *root){
    while(root&&root->left!=NULL){
        root=root->left;
    }
    return root;
}
void preorderTraversal(struct node *root){
    if(root!=NULL){
        printf("%d ",root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(struct node *root){
    if(root!=NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}
void inorderTraversal(struct node *root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d ",root->key);
        inorderTraversal(root->right);
    }
}
struct node *deleteNode(struct node *root, int key){
    if(root == NULL){
        return root;
    }
    if(key<root->key){
        root->left = deleteNode(root->left, key);
    }
    else if(key>root->key){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->left == NULL){
            struct node *tmp = root->right;
            free(root);
            return tmp;
        }
        else if(root->right == NULL){
            struct node* tmp = root->left;
            free(root);
            return tmp;
        }
        struct node *tmp = findMin(root->right);
        root->key = tmp->key;
        root->right = deleteNode(root->right, tmp->key);
    }
    return root;
}
int findHeight(struct node *root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    if(leftHeight>rightHeight){
        return leftHeight+1;
    }
    else{
        return rightHeight+1;
    }
}
struct node *findSuccessor(struct node *root, int key){
    struct node *current = root;
    struct node *successor = NULL;
    while(current != NULL){
        if(key < current->key){
            successor = current;
            current = current->left;
        }
        else if(key > current->key){
            current = current->right;
        }
        else{
            if(current->right != NULL){
                return findMin(current->right);
            }
            break;
        }
    }
    return successor;
}

int main() {
    int n, i, key, choice, exitloop=0;
    printf("Enter the number of elements in the BST: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &key);
        root = insert(root, key);
    }

    while(1){
        printf("\nMenu:\n");
        printf("1. Find the minimum element\n");
        printf("2. Find the maximum element\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Inorder traversal\n");
        printf("6. Insert an element\n");
        printf("7. Delete an element\n");
        printf("8. Find the successor of an element\n");
        printf("9. Find the height of the BST\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Minimum element: %d\n",findMin(root)->key);
            break;
            case 2:
            printf("Maximum element: %d\n",findMax(root)->key);
            break;
            case 3:
            printf("Preorder traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;
            case 4:
            printf("Postorder traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;
            case 5:
            printf("Inorder traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
            case 6:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
            case 7:
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            root=deleteNode(root, key);
            break;
            case 8:
            printf("Enter the key to find its successor: ");
            scanf("%d",&key);
            struct node *successor = findSuccessor(root, key);
                if(successor!=NULL){
                    printf("Successor of %d is %d\n", key, successor->key);
                }
                else{
                    printf("No successor found for %d\n", key);
                }
            break;
            case 9:
            printf("Height of the BST: %d\n", findHeight(root));
            break;
            case 10:
            exitloop=1;
            break;
            default:
            printf("Invalid choice");
        }
        if(exitloop==1){
            break;
        }
    }
    return 0;
}