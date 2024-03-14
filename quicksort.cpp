#include<iostream>
using namespace std;
int partition (int A[], int start, int end){
int pivot = A[end];
int i = start-1;
for (int j = start; j < end; j++){
if(A[j] < pivot){
i++;
swap(A[i],A[j]);
}
}
i++;
swap(A[i],A[end]);
return i;
}
void quickSort (int A[], int start, int end){
if (end <= start)
return;
int pivot = partition (A, start, end);
quickSort (A, start, pivot-1);
quickSort (A, pivot+1, end);
}
int main(){
int A[8]={5, 9, 2, 7, 1, 8, 3, 4};
int n = sizeof(A)/sizeof(A[0]);
cout<<"Elements before swapping: ";
for(int i = 0; i < n; i++)
cout<<A[i]<<" ";
quickSort(A, 0, 7);
cout<<"\nElements after swapping: ";
for(int i = 0; i < n; i++)
cout<<A[i]<<" ";
}
