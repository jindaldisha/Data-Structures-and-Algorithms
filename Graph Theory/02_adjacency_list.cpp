//
// Created by disha on 20-06-2021.
//

/*
An adjacency list is a way to represent a graph as a map from node to list of edges.
     Each node tracks all its outgoing edges.
     We only need to track two things:
        The Node we're going to.
        The Cost (Weight) of getting there.
     Pros:
        Space efficient for representing sparse graphs.
        Iterating over all edges is efficient.
     Cons:
        Less space efficient for denser graphs.
        Edge weight loookup is O(E).
        Slightly more complex graph representation.
*/

#include<bits/stdc++.h>
using namespace std;

template <class T>

class Graph{
    int V;
    map<T, map<T, int>> adjList;
public:
    Graph(int v){
        V = v;
    }
    void addEdge(T u, T v, int w, bool biDir = false){
        adjList[u][v] = w;
        if(biDir){
            adjList[v][u] = w;
        }
    }
    void printGraph(){
        for(auto i: adjList){
            cout<<i.first;
            for(auto j: i.second){
                cout<<" -> ("<<j.first<<", "<<j.second<<")";
            }
            cout<<endl;
        }
    }
};

template <class T>
void createGraph(Graph<T> &g){
    g.addEdge("A","B",4);
    g.addEdge("A","C",1);
    g.addEdge("A","D",9);
    g.addEdge("B","A",3);
    g.addEdge("B","C",6);
    g.addEdge("B","D",11);
    g.addEdge("C","A",4);
    g.addEdge("C","B",1);
    g.addEdge("C","D",2);
    g.addEdge("D","A",6);
    g.addEdge("D","B",5);
    g.addEdge("D","C",-4);
}

int main(){
    Graph<string> g(4);
    createGraph(g);
    g.printGraph();
}