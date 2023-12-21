#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) 
{
  for (int i = 1; i < n; i++) 
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) 
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
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
  insertionSort(a,s);
  cout << "Sorted array: ";
  printArray(a, s);
  return 0;
}