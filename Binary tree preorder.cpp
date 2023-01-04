#include<iostream>
#include <stdlib.h>
using namespace std;
struct node {
   int data;
   struct node *left;
   struct node *right;
};
struct node *createNode(int val) {
   struct node *new_node = (struct node *)malloc(sizeof(struct node));
   new_node->data = val;
   new_node->left = new_node->right = NULL;
   return new_node;
}
void preorder(struct node *root) {
   if (root != NULL) {
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
   }
}
struct node* insertNode(struct node* new_node, int val) {
   if (new_node == NULL) return createNode(val);
   if (val < new_node->data)
   new_node->left = insertNode(new_node->left, val);
   else if (val > new_node->data)
   new_node->right = insertNode(new_node->right, val);
   return new_node;
    
}
int main() {
   struct node *root = NULL;
   root = insertNode(root, 4);
   insertNode(root, 5);
   insertNode(root, 2);
   insertNode(root, 9);
   insertNode(root, 1);
   insertNode(root, 3);
   cout<<"Pre-Order traversal of the Binary Search Tree is: ";
   preorder(root);
   return 0;
}
