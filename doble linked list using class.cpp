#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

class double_linked_list
{
private:
    node *head,*temp;
public:
    double_linked_list()
    {
        head = NULL;
        temp = NULL;
    }

    void add_node(int n)
    {
        node *newnode = new node;
        newnode->data = n;
         newnode->prev = NULL;   
          newnode->next = NULL;
         if(head == NULL)
        {
            head = temp=newnode;
        }
        else
        {
        	temp->next=newnode;
           newnode->prev=temp;
            temp=newnode;
        }
    }

    void display()
    {
        node *tmp;
        tmp = head;
        cout <<"double linked list:"<<endl;
        while (tmp != NULL)
        {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
};

int main()
{
    double_linked_list a;
    a.add_node(0);
    a.add_node(2);
    a.add_node(7);
    a.display();
    return 0;
}
