#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
  int V;
  vector<list<int> > adj;
  
  public:
    Graph(int V);
    void addEdge(int v,int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
  this->V=V;
  adj.resize(V);
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    vector<bool> visited;
    visited.resize(V,false);
    
    list<int> queue;
    
    visited[s]=true;
    queue.push_back(s);
    
    while(!queue.empty())
    {
        s=queue.front();
        cout<<"\t"<<s;
        queue.pop_front();
        
        for(auto adjacent: adj[s])
        {
            if(!visited[adjacent])
            {
                visited[adjacent]=true;
                queue.push_back(adjacent);
                
            }
        }
    }
}

int main()
{
    int nodes,n,edge1,edge2,bfs;
    cout<<"\nEnter the number of nodes in the graph:";
    cin>>nodes;
    Graph g(nodes);
    cout<<"\nNow define the number of edges of nodes from 0 to "<<nodes-1<<" :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEdge "<<i+1<<" :";
        cin>>edge1>>edge2;
        g.addEdge(edge1,edge2);
    }
    
    cout<<"\nEnter the node number from where you want to do BFS:";
    cin>>bfs;
    cout<<"\nBreadth First Search starting from "<<bfs<<" is:\n";
    g.BFS(bfs);
    return 0;
}