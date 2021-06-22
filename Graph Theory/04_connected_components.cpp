//
// Created by disha on 22-06-2021.
//
/*
Connected Components: Sometimes a graph is split into multiple components.
It is useful to be able to identify and count these components.
We can use DFS to identify components.
First make sure all the nodesl are labeled from [0, n), where n is the number of nodes.
Algorithm: Start a DFS at every node (except if it's already been visited)
and mark all the reachable nodes as being part of the same component.
 */
#include <bits/stdc++.h>
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

    void dfs(int node, vector<int> &component, vector<bool> &visited, int num){
        visited[node] = true;
        component[node] = num;
        for(auto i: adjList[node]){
            if(!visited[i]){
                dfs(i, component, visited, num);
            }
        }
    }

    void connectedComponents(){
        vector<int> component(V, -1); //Array with component number of all vertices
        vector<bool> visited(V, false);
        int num = -1; // Current Component Number
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                num++;
                dfs(i, component, visited, num);
            }
        }
        for(int i = 0; i < V; i++){
            cout<<i<<"- > "<<component[i]<<endl;
        }
    }
};

template<class T>
void createGraph(Graph<T> &g){
    g.addEdge(0,8);
    g.addEdge(1,5);
    g.addEdge(2,9);
    g.addEdge(3,9);
    g.addEdge(4,0);
    g.addEdge(5,16);
    g.addEdge(6,11);
    g.addEdge(7,6);
    g.addEdge(8,14);
    g.addEdge(9,15);
    g.addEdge(11,7);
    g.addEdge(13,0);
    g.addEdge(14,0);
    g.addEdge(14,13);
    g.addEdge(15,2);
    g.addEdge(15,10);

}

int main(){
    Graph<int> g(17, true);
    createGraph(g);
    g.printGraph();
    g.connectedComponents();
}