#include <iostream> 
using namespace std;

void swap(int* a, int* b)
 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) 
  {
    if (arr[j] <= pivot) 
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high) 
{
  if (low < high) 
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArray(int arr[], int size) 
{
  for (int i = 0; i < size; i++) 
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() 
{
  cout<<"enter the size\n";
  int s;
  cin>>s;
  int a[s];
  cout<<"Enter "<<s<<" elements\n";
  for(int i=0;i<s;i++)
   {
    cin>>a[i];
   }
  cout<<"Unsorted array: ";
  printArray(a, s);
  quickSort(a, 0, s - 1);
  cout << "Sorted array: ";
  printArray(a, s);
  return 0;
}