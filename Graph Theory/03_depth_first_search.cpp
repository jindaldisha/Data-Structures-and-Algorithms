//
// Created by disha on 20-06-2021.
//
/*
Depth First Search (DFS):
     The DFS is the most fundamental search algorithm used to explore nodes and edges of a graph.
     It runs with a time complexity of (V+E) and is often used as a building block of other algorithms.
     By itself the DFS isn't all that useful, but when augmented to perform other tasks such as
     count connected components, determine connectivity, or find bridges/ articulation points, the DFS shines.

     The DFS plunges depth first into a graph without regard for which edge it takes next.
 * */
#include<bits/stdc++.h>
using namespace std;

template<class T>
class Graph{
    int V;
    map<T,vector<T>> adjList;
    bool biDir;
public:
    Graph(int v, bool bi){
        V = v;
        biDir = bi;
    }
    void addEdge(T u, T v){
        adjList[u].push_back(v);
        if(biDir){
            adjList[v].push_back(u);
        }
    }
    void printGraph(){
        for(auto i: adjList){
            cout<<"Node "<<i.first;
            for(auto j: i.second){
                cout<<" -> "<<j;
            }
            cout<<endl;
        }
    }

    void dfs(T start, map<T, bool> &visited){
        visited[start] = true;
        cout<<start<<" ";
        for(auto i: adjList[start]){
            if(!visited[i]){
                dfs(i, visited);
            }
        }
    }
    void dfsFiller(T start){
        map<T, bool> visited;
        for(auto i: adjList){
            visited[i.first] = false;
        }
        dfs(start, visited);
    }
};
template<class T>
void createGraph(Graph<T> &g){
    g.addEdge(0,9);
    g.addEdge(1,0);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,3);
    g.addEdge(7,10);
    g.addEdge(8,1);
    g.addEdge(8,7);
    g.addEdge(9,8);
    g.addEdge(10,11);
    g.addEdge(11,7);
}

int main(){
    Graph<int> g(13, true);
    createGraph(g);
    g.printGraph();
    g.dfsFiller(0);
}