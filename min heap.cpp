
#include <iostream>
#include <conio.h>
int size =5;
using namespace std;
void min_heapify(int a[],int i)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= size)
    {
        if (j < size && a[j+1] < a[j])
            j = j + 1;
        if (temp < a[j])
            break;
        else if (temp >= a[j])
        {
            a[j/2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    return;
}
void swap(int *a, int *b)
{
  int t = *b;
  *b = *a;
  *a = t;
}

void deleteRoot(int a[], int num)
{
  int i,temp;
  for (i = 0; i < size; i++)
  {
    if (num == a[i])
    
    break;
  }

  swap(&a[i], &a[size - 1]);
  size --;
  for (int i = size / 2 ; i >= 0; i--)
  {
   min_heapify(a, i);
  }
}
void insert(int a[])
{
    int i;
    for(i = size/2; i >= 1; i--)
    {
        min_heapify(a,i);
    }
}
int main()
{
    int i, x;
    int a[size];
    for (i = 1; i <= size; i++)
    {
        cout<<"enter element"<<(i)<<endl;
        cin>>a[i];
    }
    insert(a);
    cout<<"Min Heap\n";
    for (i = 1; i <= size; i++)
    {
        cout<<a[i]<<endl;
    }
    printf("Enter to delete:");
scanf("%d",&x);
  deleteRoot(a, x);
  for (i = 0; i < size; i++)
    {
        cout<<a[i]<<endl;
    }
    getch();
}
