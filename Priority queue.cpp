#include <iostream>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct node // node declaration
{
  int priority;
  int data;
  struct node *next;
};
class Priority_Queue
{
private:
  node *front;

public:
  Priority_Queue()
  {

    front = NULL;
  }
  void insert(int i, int p)
  {
    node *temp, *rear;
    temp = new node;
    temp->data = i;
    temp->priority = p;
    if (front == NULL || p < front->priority)
    {
      temp->next = front;
      front = temp;
    }
    else
    {
      rear = front;
      while (rear->next != NULL && rear->next->priority <= p)
        rear = rear->next;
      temp->next = rear->next;
      rear->next = temp;
    }
  }
  void qdelete()
  {
    node *temp;
    if (front == NULL)
      cout << "Queue is empty\n";
    else
    {
      temp = front;
      cout << "Deleted item is: " << temp->data << endl;
      front = front->next;
      free(temp);
    }
  }
  void show() //print queue {
  {
    node *ptr;
    ptr = front;
    if (front == NULL)
      cout << "Queue is empty\n";
    else
    {
      cout << "Queue is :\n";
      cout << "Priority Item\n";
      while (ptr != NULL)
      {
        cout << ptr->priority << " " << ptr->data << endl;
        ptr = ptr->next;
      }
    }
  }
};
int main()
{
  int c, i, p;
  Priority_Queue pq;
  do
  {
    cout << "1.Insert\n";
    cout << "2.Delete\n";
    cout << "3.Display\n";
    cout << "4.Exit\n";
    cout << "Enter your choice : ";
    cin >> c;
    switch (c)
    {
    case 1:
      cout << "Input the item value to be added in the queue : ";
      cin >> i;
      cout << "Enter its priority : ";
      cin >> p;
      pq.insert(i, p);
      break;
    case 2:
      pq.qdelete();
      break;
    case 3:
      pq.show();
      break;
    case 4:
      break;
    default:
      cout << "Wrong choice\n";
    }
  } while (c != 4);

  return 0;
}
