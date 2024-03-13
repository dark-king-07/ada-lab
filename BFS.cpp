#include<iostream>
using namespace std;
int visited[20],a[20][20],r=-1,f=0,q[20],n,v;
void bfs(int v){
    for(int i=1;i<=n;i++){
        if(a[v][i] && !visited[i]){
            q[++r] = i;
        }
    }
    if(f<=r){
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}
int main()
{
 
 cout<<"Enter no of vertices: ";
 cin>>n;
 for(int i=1; i<=n; i++){
    q[i]=0;
    visited[i]=0;
 }
 cout<<"Enter graph data matrix: ";
 for(int i=1;i<=n;i++){
    for(int j=1; j<=n; j++){
        cin>>a[i][j];
    }
 }
 cout<<"Enter starting vertex: ";
 cin>>v;
 bfs(v);

 for(int i=1;i<=n;i++){
    if(visited[i]){
        cout<<i<<" "<<endl;
    }
    else{
        cout<<"BFS not possible. ";
    }
 }

 return 0;
}