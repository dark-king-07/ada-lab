#include<iostream>
using namespace std;
void floyd(int a[][20], int n){
for(int k = 0; k < n; k++)
for(int i = 0; i < n; i++)
for(int j = 0; j < n; j++)
if(a[i][j] > a[i][k] + a[k][j])
a[i][j] = a[i][k] + a[k][j];
cout<<"\nAll pairs shortest path: "<<endl;
for(int i = 0; i < n; i++){
for(int j = 0; j < n; j++)
cout<<a[i][j]<<"\t";
cout<<endl;
}
}
int main(){
int n, a[20][20];
cout<<"No. of vertices: ";
cin>>n;
cout<<"\nCost adjacency matrix (999 for no edge and 0 for self loop):";
for(int i = 0; i < n; i++)
for(int j = 0; j < n; j++)
cin>>a[i][j];
floyd(a, n);
return 0;
}
