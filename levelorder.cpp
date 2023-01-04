#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define V 4
using namespace std;
struct QNode {
    int data;
    QNode* next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
    struct node *left;
   struct node *right;
};
  struct QNode *createNode(int val) {
   struct QNode *new_node = (struct QNode *)malloc(sizeof(struct QNode));
   new_node->data = val;
   new_node->left = new_node->right = NULL;
   return new_node;
}
struct Queue {
    QNode *front, *rear,*root;
    Queue()
    {
        front = rear = NULL;
    }
  
    void enQueue(QNode * root)
    {
        QNode* temp = new QNode(root);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
  	int peek()
  	{
  		if(front != NULL)
  		return front->data;
	  }
	bool emtpy()
	{
		if(front == NULL)
		{
			return false;
			}	
		else
		 	return true;	
	}
    void deQueue()
    {
        if (front == NULL)
            return;
        QNode* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
          free(temp);
    }
};
void LevelOrder(QNode *root) {
	if(root == NULL) return;
	Queue Q;
	Q.enQueue(QNode *root);
	while(!Q.emtpy()) {
		Node* current = Q.front();
		Q.enqueue(); // removing the element at front
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
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
   struct QNode *root = NULL;
   root = insertNode(root, 4);
   insertNode(root, 5);
   insertNode(root, 2);
   insertNode(root, 9);
   insertNode(root, 1);
   insertNode(root, 3);
   cout<<"Pre-Order traversal of the Binary Search Tree is: ";
   LevelOrder(root);
   return 0;
}

