//
// Created by disha on 26-06-2021.
//
/*
 Topological Sort: Many real world situations can be modelled as a graph with directed edges where some events must occur before others.
                              An example of this is program build dependencies. A program cannot be built unless its dependencies are first built.
                              A topological ordering is an ordering of the nodes in a directed graph where for each directed edge from node A to node B,
                              node A appears before node B in the ordering.
                              The topological sort algorithm can find a topological ordering in O(V+E) time.
                              Note: Topological orderings are not unique.
                              Not every graph can have a topological ordering.
                              A graph whic contains a cycle cannot have a valid ordering.
                              It only work on Directed Acyclic Graphs (DAG).
                              These are graphs with directed edges and no cycles.
                              We can verify wheter our graph has a cycle or not by using Tarjan's strongly connected component algorithm whihc can be used to find these cycles.
                              By definition, all rooted trees have a topological ordering since they do not contain any cycles.
                              Generally:
                                        - Pick an unvisited node
                                        - Beginning with the selected node, do a Depth First Search (DFS) exploring only unvisited nodes.
                                        - On the recursive callback of the DFS, add the current node to the topological ordering in reverse order.
 * */
#include <bits/stdc++.h>
using namespace std;

template<class T>
class Graph{
    int V;
    map<T,vector<T>> adjList;
    vector<T> verList;
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
    void addVertex(vector<T> vertex){
        verList = vertex;
    }

    void dfs(T node, map<T, bool> &visited, vector<T> &topSort){
        for(auto i: adjList[node]){
            if(!visited[i]){
                dfs(i, visited, topSort);
                visited[i] = true;
            }
        }
        topSort.insert(topSort.begin(),node);
    }
    void topologicalSort(){
        map<T, bool> visited;
        //Initialize visited to false
        for(int i = 0; i < V; i++){
            visited[verList[i]] = false;
        }
        vector<T> topSort;
        for(auto i: visited){
            if(!i.second){
                visited[i.first] = true;
                dfs(i.first, visited, topSort);

            }
        }
        cout<<"Topological Ordering: ";
        for(auto i: topSort){
            cout<<i<<" ";
        }
        cout<<endl;
    }


};

template<class T>
void createGraph(Graph<T> &g){
    g.addVertex({'A','B','C','D','E','F','G','H','I','J','K','L','M'});
    g.addEdge('A','D');
    g.addEdge('B', 'D');
    g.addEdge('C', 'A');
    g.addEdge('C', 'B');
    g.addEdge('D', 'G');
    g.addEdge('D', 'H');
    g.addEdge('E', 'A');
    g.addEdge('E', 'D');
    g.addEdge('E', 'F');
    g.addEdge('F', 'J');
    g.addEdge('F', 'K');
    g.addEdge('G', 'I');
    g.addEdge('H', 'I');
    g.addEdge('H', 'J');
    g.addEdge('I', 'L');
    g.addEdge('J', 'L');
    g.addEdge('J', 'M');
    g.addEdge('K', 'J');
}

int main(){
    Graph<char> g(13, false);
    createGraph(g);
    g.printGraph();
    g.topologicalSort();
}