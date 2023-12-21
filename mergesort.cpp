#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) 
{
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];
  for (int i = 0; i < n1; i++) 
  {
    L[i] = arr[l + i];
  }
  for (int j = 0; j < n2; j++) 
  {
    R[j] = arr[m + 1 + j];
  }

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) 
  {
    if (L[i] <= R[j]) 
    {
      arr[k] = L[i];
      i++;
    } 
    else 
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) 
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) 
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) 
{
  if (l < r) 
  {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
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
  mergeSort(a, 0, s - 1);
  cout << "Sorted array: ";
  printArray(a, s);
  return 0;
}
