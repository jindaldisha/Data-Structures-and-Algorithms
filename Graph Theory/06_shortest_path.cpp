//
// Created by disha on 22-06-2021.
//

/*
 Shortest Path:
    Find the shortest path between two nodes using breadth first search.
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

    void bfs(T start, map<T, bool> &visited, map<T, T> &previous){
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
                    previous[i] = curr;
                }
            }
        }
    }
    void shortestPath(T start, T end){
        map<T, bool> visited;
        map<T, T> previous;
        for(auto i: adjList){
            visited[i.first] = false;
        }
        for(auto i: adjList){
            previous[i.first] = {};
        }
        bfs(start, visited, previous);

        cout<<"Shorted Path: ";
        T temp = end;
        cout<<temp;
        while(temp != T{}){
            cout<<" -> "<<previous[temp];
            temp = previous[temp];
            if(temp == start){
                return;
            }
        }
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
    g.shortestPath(2,11);
}