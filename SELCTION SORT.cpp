#include <iostream>
#include <string>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

class linkedList
{
    node *head;
    public:
  void create(){
    node *new_node=NULL,*temp=new_node;
    int data;
    head=NULL;
    cout<<"\n==============Selection sorting using linked list============\nEnter -1 to terminate\n";
    while(1){
       cout<<"Enter a number: ";
       cin>>data;
       if(data==-1)
	 break;
       else{
	   new_node = new node;
	   new_node->data=data;
	   if(head==NULL)
	      head=new_node;
	   else
	    temp->next=new_node;
	   temp=new_node;
	   temp->next=NULL;
       }
    }
}
void display(){
	node *ptr;
	ptr=head;
	while(ptr!=NULL){
	   cout<<ptr->data<<"\n"; 
	   ptr=ptr->next;
	}
}
     void selectionSort()
{
	node *i, *j;
	int temp;
	for(i=head;i!=NULL;i=i->next){
	   for(j=i->next;j!=NULL;j=j->next){
	       if(i->data > j->data){
		  temp    =  i->data;
		  i->data = j->data;
		  j->data = temp;
	       }
	   }
	}
}
};


int main()
{
    linkedList list;
	list.create();
	cout<<"List before sorting "<<endl;
	list.display();
	list.selectionSort();
	cout<<"List after sorting "<<endl;
	list.display();	
  return 0;
}
