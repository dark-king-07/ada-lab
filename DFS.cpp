#include <bits/stdc++.h>
#include<iostream>
using namespace std;
 
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
 
    void addEdge(int v, int w);
 
    void DFS(int v);
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
 
void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";
 
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
 

int main()
{
    
    int nodes,n,edge1,edge2,dfs;
    cout<<"\nEnter the number of nodes in the graph:";
    cin>>nodes;
    Graph g;
    cout<<"\nNow define the number of edges of nodes from 0 to "<<nodes-1<<" :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEdge "<<i+1<<" :";
        cin>>edge1>>edge2;
        g.addEdge(edge1,edge2);
    }
    
    cout<<"\nEnter the node number from where you want to do DFS:";
    cin>>dfs;
    cout<<"\nDepth First Search starting from "<<dfs<<" is:\n";
    g.DFS(dfs);
    return 0;
}