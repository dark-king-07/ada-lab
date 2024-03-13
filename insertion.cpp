#include<iostream>
using namespace std;
void Insertion (int A[], int n)
{
  int v, j;
  for(int i = 1; i < n; i++)
  {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v)
    {
       A[j+1] = A[j];
       j = j-1;
    }
    A[j+1] = v;
  }
}
int main()
{
  int A[]={5, 9, 2, 7, 1};
  int n =sizeof(A)/sizeof(A[0]);
  cout<<"Elements before swapping: ";
  for(int i = 0; i < n; i++)
    cout<<A[i]<<" ";
  Insertion(A, n);
  cout<<"\nElements after swapping: ";
  for(int i = 0; i < n; i++)
    cout<<A[i]<<" ";
}
