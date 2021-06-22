//
// Created by disha on 22-06-2021.
//
/*
 05 Breadth First Search (BFS):
      The Breadth First Search (BFS) is another fundamental search algorithm.
      It is used to explore nodes and edges of a graph.
      It runs with a time complexity of O(V+E).
      It is often used as a building block of other algorithms.
      It is particularly useful for finding shortest path on unweighted graphs.
      A BFS starts at some arbitrary node of a graph and explores the neighbour nodes first,
      before moving to the next level neighbours.
      It explores nodes in layers.
      The BFS algorithm uses a queue data structure to track which node to visit next.
      Upon reaching a new node the algorithm adds it to the queue to visit it later.
      The queue data structure works just like a real world queue such as a waiting ;ine at a restaurant.
      People can either enter the waiting line (enqueue) or get seated (dequeue).
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

    void bfs(T start, map<T, bool> &visited){
        visited[start] = true;
        vector<T> ans;
        queue<T> q;
        q.push(start);
        while(!q.empty()){
            T curr = q.front();
            ans.push_back(curr);
            q.pop();
            for(auto i: adjList[curr]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        for(auto i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    void bfsFiller(T start){
        map<T, bool> visited;
        for(auto i: adjList){
            visited[i.first] = false;
        }
        bfs(start, visited);
    }
};

template<class T>
void createGraph(Graph<T> &g){
    g.addEdge(0,7);
    g.addEdge(0,11);
    g.addEdge(0,9);
    g.addEdge(9,10);
    g.addEdge(7,6);
    g.addEdge(7,3);
    g.addEdge(6,5);
    g.addEdge(3,4);
    g.addEdge(3,2);
    g.addEdge(2,12);
    g.addEdge(12,8);
    g.addEdge(9,8);
    g.addEdge(1,8);
    g.addEdge(7,11);
    g.addEdge(1,10);
}

int main(){
    Graph<int> g(13, true);
    createGraph(g);
    g.printGraph();
    g.bfsFiller(0);
}