#include<iostream>
using namespace std;
int n, c[20][20], i, j, visited[20];
void prim()
{
  int min, a, b, k, count = 0, cost = 0;
  min = 99;
  visited[1] = 1;
  while (count < n - 1)
  {
    min = 99;
    for(i = 1;i<=n; i++)
      for(j = 1; j<=n; j++)
        if(visited[i] && !visited[j] && min > c[i][j])
         {
           min = c[i][j];
           a = i;
           b = j;
         }
   cout<<a<<"--->"<<b<<"="<<c[a][b]<<endl; /*displaying the edges and their respective
   weights of the MST*/
   cost = cost + c[a][b]; //for calculating MST values
   visited[b] = 1;
   count++;
  }
cout<<"\nTotal cost of MST is "<<cost;
}
int main()
{
   cout<<"How many vertices? ";
   cin>>n;
   cout<<"\nEnter cost matrix: ";
   for(i = 1; i<=n; i++)
   {
     for(j = 1; j<=n; j++)
       cin>>c[i][j];
       visited[i] = 0;
   }
   prim();
}
