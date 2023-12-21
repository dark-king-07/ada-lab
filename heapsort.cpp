#include<iostream>
using namespace std;

class heapsort
{
    int smallest,left,right,i;
    public:
        void heapify(int array[],int n,int i);
        void sort(int array[],int n);
};

void heapsort::heapify(int array[],int n,int i)
{
    smallest=i;
    left=2*i+1;
    right=2*i+2;
    
    if(left<n && array[left]<array[smallest])
        smallest=left;
        
    if(right<n && array[right]<array[smallest])
        smallest=right;
        
    if(smallest!=i)
    {
        swap(array[i],array[smallest]); 
        heapify(array,n,smallest);
    }
}

void heapsort::sort(int array[],int n)
{
     for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);
 
    for (int i = n - 1; i >= 0; i--) {
        swap(array[0], array[i]);
 
        heapify(array, i, 0);
    }
}

int main()
{
    int size;
    cout<<"\nEnter the number of students:";
    cin>>size;
    
    int array[size];
    clock_t start= clock();
    cout<<"\nEnter the "<<size<<" student IDs in any order:\n";
    for(int i=0;i<size;i++)
    {
        cin>>array[i];
    }
    
    cout<<"\nThe Student IDs before sorting is:";
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<"\t";
    }
    
    heapsort object;
    
    object.sort(array,size);
    
    cout<<"\nThe Student IDs after sorting is:";
    for(int i=size-1;i>=0;i--)
    {
        cout<<array[i]<<"\t";
    }
    
    clock_t end=clock();
    double time=double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"\nEXECUTION TIME :"<<fixed<<time;
    return 0;
}