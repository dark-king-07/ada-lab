#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;
void heapify(int a[], int n, int i)
{
   int lar = i;
   int l = 2 * i + 1;
   int r = 2 * i + 2;
   if(l < n && a[l] > a[lar])
     lar = l;
   if(r < n && a[r] > a[lar])
     lar = r;
   if(lar != i)
   {
     swap(a[lar], a[i]);
     heapify(a, n, lar);
   }
}
void heapSort(int a[], int n)
{
   for (int i = n/2 - 1; i >= 0; i--)
     heapify (a, n, i);
   for (int i = n - 1; i >= 0; i--)
   {
      swap(a[0], a[i]);
      heapify(a, i, 0);
   }
}
int main()
{
   int n;
   cout<<"\n How many student?: ";
   cin>>n;
   int a[n];
   cout<<"\n Enter "<<n<<" student id's in any order: ";
   for (int i = 0; i < n; i++)
     cin >> a[i];
   auto start = high_resolution_clock :: now();
   heapSort(a, n);
   auto endt = high_resolution_clock :: now();
   cout<<"\n Students id after sorting are :";
   for (int i = 0; i < n; i++)
     cout<<a[i]<<" ";
   auto duration = duration_cast <microseconds> (endt - start);
   cout<<"\nTime complexity : "<<duration.count()<<" ms";
   return 0;
}
