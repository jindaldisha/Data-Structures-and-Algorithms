//
// Created by disha on 26-06-2021.
//

/*
Directed Acyclic Graphs (DAG) is a graph with directed edges and no cycles.
By definition this means all trees are automatically DAGs since they do not contain cycles.

Single Source Shortest Path (SSSP) problem can be solved efficiently on a DAG in O(V+E) time.
This is due to the fact that nodes can be ordered in a  topological ordering via topsort and processed sequentially.

*/

#include <bits/stdc++.h>
using namespace std;

template<class T>
class Graph{
    int V;
    map<T,map<T, int>> adjList;
    vector<T> verList;
    bool biDir;
public:
    Graph(int v, bool bi){
        V = v;
        biDir = bi;
    }
    void addEdge(T u, T v, int w){
        adjList[u][v] = w;
        if(biDir){
            adjList[v][u] = w;
        }
    }
    void printGraph(){
        for(auto i: adjList){
            cout<<"Node "<<i.first;
            for(auto j: i.second){
                cout<<" -> ("<<j.first<<", "<<j.second<<")";
            }
            cout<<endl;
        }
    }
    void addVertex(vector<T> vertex){
        verList = vertex;
    }

    void DFS(T node, map<T, bool> &visited, vector<T> &topSort){
        for(auto i: adjList[node]){
            if(!visited[i.first]){
                visited[i.first] = true;
                DFS(i.first, visited, topSort);
            }
        }
        topSort.insert(topSort.begin(), node);
    }

    vector<T> topologicalSort(){
        map<T, bool> visited;
        for(auto i: verList){
            visited[i] = false;
        }
        vector<T> topSort;
        for(auto i: visited){
            if(!i.second){
                i.second = true;
                DFS(i.first, visited, topSort);
            }
        }
        return topSort;
    }

    void singleSourceShortestPath(){
        map<T, int>shortestDistance;
        for(auto i: verList){
            shortestDistance[i] = INT_MAX;
        }
        vector<T> topSort = topologicalSort();
        shortestDistance[topSort[0]] = 0;

//        cout<<"Topological Ordering: ";
//        for(auto i: topSort){
//            cout<<i<<" ";
//        }
//        cout<<endl;
        for(auto i: topSort){
            for(auto j: adjList[i]){
                shortestDistance[j.first] = min(shortestDistance[j.first], shortestDistance[i] + adjList[i][j.first]);
            }
        }

        for(auto i: shortestDistance){
            cout<<i.first<<" -> "<<i.second<<endl;
        }

    }
};

template<class T>
void createGraph(Graph<T> &g){
    g.addVertex({'A','B','C','D','E','F','G','H'});
    g.addEdge('A', 'B', 3);
    g.addEdge('A', 'C', 6);
    g.addEdge('B', 'C', 4);
    g.addEdge('B', 'D', 4);
    g.addEdge('B', 'E', 11);
    g.addEdge('C', 'D', 8);
    g.addEdge('C', 'G', 11);
    g.addEdge('D', 'E', -4);
    g.addEdge('D', 'F', 5);
    g.addEdge('D', 'G', 2);
    g.addEdge('E', 'H', 9);
    g.addEdge('F', 'H', 1);
    g.addEdge('G', 'H', 2);
}

int main(){
    Graph<char> g(8, false);
    createGraph(g);
    g.printGraph();
    g.singleSourceShortestPath();
}