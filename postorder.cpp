#include<stdio.h>
#include<stdlib.h>
struct node{
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
// A utility function to do inorder traversal of BST
void inorder(struct node *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

void postorder(struct node *root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d \n", root->key);
    }
}
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key){
    
    /* If the tree is empty, return a new node */
    if (node == NULL) 
        return newNode(key);
    
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    
    else if (key > node->key)
       node->right = insert(node->right, key);
    
    /* return the (unchanged) node pointer */
    return node;
}
// Driver Program to test above functions
int main(){
/* Let us create following BST
                      
                            500
                    /               \
                250                   1000
            /       \              /        \
         200         300         700        1200 
        /   \      /    \       /   \       /   \
      100   225   270   350   600   800   1100   1500
                             /     /   \      \
                           550   750  850     1150
*/
    struct node *root = NULL;
    root = insert(root, 500);
    insert(root, 250);
    insert(root, 200);
    insert(root, 100);
    insert(root, 225);
    insert(root, 300);
    insert(root, 270);
    insert(root, 350);
    insert(root, 1000);
    insert(root, 1200);
    insert(root, 1500);
    insert(root, 1100);
    insert(root, 1150);
    insert(root, 700);
    insert(root, 600);
    insert(root, 550);
    insert(root, 800);
    insert(root, 750);
    insert(root, 850);
    // print postoder traversal of the BST
    postorder(root);
    return 0;
}
