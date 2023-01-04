// Max-Heap data structure in C

#include <stdio.h>
int size = 6;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("Single element in the heap");
  }
  else
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}
void insert(int array[])
{
  
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);

    }
  }

void deleteRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size --;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
int main()
{
  int array[5];
  int x;

  int  i;
 printf("\n========Array==========\n");
      for(i=0;i<size;i++)
      {
            printf("\nEnter element %d= ",i);
            scanf("%d",&array[i]);
            
        }
insert(array);
  printf("Max-Heap array: ");
  printArray(array, size);
printf("Enter to delete:");
scanf("%d",&x);
  deleteRoot(array, x);

  printf("After deleting an element: ");

  printArray(array, size);
}
