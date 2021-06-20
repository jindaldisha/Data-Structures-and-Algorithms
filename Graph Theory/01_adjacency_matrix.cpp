//
// Created by disha on 20-06-2021.
//

/*
 * An adjacency matrix m is a very simple way to represent a graph.
 * The idea is that the cell m[i][j] represents the edge weight of going from node i to node j.
 * It is often assumed that the edge of going from a node to itself has a cost of zero.
 *
 * Pros: Space efficient for representing dense graphs.
 *        Edge weight lookup is O(1)
 *        Simplest Graph Representation
 * Cons: Requires O(V^2) space
 *       Iterating over all edges takes O(V^2) time
*/
#include <bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    int adjMat[50][50];
public:
    Graph(int v){
        V = v;
    }
    void addEdge(int u, int v, int w, bool biDir = false){
        adjMat[u][v] = w;
        if(biDir){
            adjMat[v][u] = w;
        }
    }
    void printAdjMat(){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                cout<<adjMat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void printGraph(){
        for(int i = 0; i < V; i++){
            cout<<i;
            for(int j = 0; j < V; j++){
                if(adjMat[i][j] != 0){
                    cout<<" -> ("<<j<<", "<<adjMat[i][j]<<")";
                }
            }
            cout<<endl;
        }
    }
};

void createGraph(Graph &g){
    g.addEdge(0,1,4);
    g.addEdge(0,2,1);
    g.addEdge(0,3,9);
    g.addEdge(1,0,3);
    g.addEdge(1,2,6);
    g.addEdge(1,3,11);
    g.addEdge(2,0,4);
    g.addEdge(2,1,1);
    g.addEdge(2,3,2);
    g.addEdge(3,0,6);
    g.addEdge(3,1,5);
    g.addEdge(3,2,-4);
}

int main(){
    Graph g = Graph(4);
    createGraph(g);
    g.printAdjMat();
    g.printGraph();
}