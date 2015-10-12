//
//  Graphs.h
//  Algorithms
//
//  Created by Preethish Shetty on 10/8/15.
//  Copyright © 2015 Preethish Shetty. All rights reserved.
//

#include <list>
#include<iostream>
using namespace std;


class Graph
{
    int V;
    list<int> *adj;
    
    public :
    Graph(int V)
    {
        this->V=V;
        adj = new list<int>[V];
    }
    
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    
    void BFS(int s);
    void DFS(int s,bool *visited);
    void DFSUtil();
};


/*  Time Complexity : O(V+E)
    V1 + [edges incident to V1] + V2 + [edges incident to V2] + .... + Vn + [edges incident to Vn]
 
*/
void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
    list<int> queue;
    
    visited[s]=true;
    queue.push_back(s);
    
    list<int>::iterator i;
    
    while(!queue.empty())
    {
        int r = queue.front();
        cout<<"\nVisiting Node : "<<r;
        
        queue.pop_front();
        
        
        for(i=adj[r].begin();i!=adj[r].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
    }

}


void Graph::DFS(int s,bool *visited)
{
    //DFS
    visited[s]=true;
    cout<<"\nVisiting Node : "<<s;
    list<int>::iterator i;
    
    for(i=adj[s].begin();i!=adj[s].end();i++)
    {
        if(!visited[*i])
        {
            visited[*i]=true;
            DFS(*i,visited);
        }
    }
}

void Graph::DFSUtil()
{
    bool *visited= new bool[4];
    for(int i=0;i<4;i++)
        visited[i]=false;

    DFS(2,visited);
}




void GraphTestConsole()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    
    cout<<"\nBFS : ";
    g.BFS(2);
    
    cout<<"\nDFS : ";
    g.DFSUtil();
}
