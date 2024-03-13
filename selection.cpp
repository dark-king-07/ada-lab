#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min= i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min= j;
      }
    }
    swap(arr[i], arr[min]);
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
  selectionSort(a, s);
  cout << "Sorted array: ";
  printArray(a, s);
  return 0;
}
