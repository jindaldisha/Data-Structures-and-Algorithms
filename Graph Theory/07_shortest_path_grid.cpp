//
// Created by disha on 22-06-2021.
//

/*
Shorted Path in Grid: Many problems in graph theory can be represented using a grid.
                          Grids are a form of implicit graph because we can determine
                          a node's neighbours based on our location within the grid.
                          A common approach to solving graph theory problems on grids is
                          to first convert the grid to a familiar format such as an adjacency list/matrix.
                          Assume the grid is unweighted and cells connect left, right, up and down.
                          However, transformations between graph representations can usually be avoided due to the structure of a grid.


*/

#include<bits/stdc++.h>
using namespace std;

char grid[50][50];
void printGrid(int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void createGrid(int rows, int columns){

    string gridString = "S..#..."
                        ".#...#."
                        ".#....."
                        "..##..."
                        "#.#E.#.";
    int x = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            grid[i][j] = gridString[x];
            x++;
        }
    }
}

void shortestPathGrid(int rows, int columns){
    bool visited[rows][columns];
    //Creating seperate queues for x and y
    queue<int> qx;
    queue<int> qy;
    int px[rows][columns];
    int py[rows][columns];
    //Define direction vectors
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    //Push the first point on the grid into the queue and marking it as visited
    qx.push(0);
    qy.push(0);
    visited[0][0] = true;
    while(!qx.empty()){
        //Accessing the front value of the queue
        int cx = qx.front();
        int cy = qy.front();
        if(grid[cx][cy] == 'E'){
            int bx = px[cx][cy];
            int by = py[cx][cy];
            while(grid[bx][by] != 'S'){
                cout<<"("<<bx<<", "<<by<<") <- ";
                grid[bx][by] = '@';
                int temp = bx;
                bx = px[bx][by];
                by = py[temp][by];
            }
            cout<<endl;
            return;
        }
        qx.pop();
        qy.pop();
        for(int i = 0; i < 4; i++){
            int rx = dr[i] + cx;
            int ry = dc[i] + cy;
            if(rx >= 0 && ry >= 0 && rx < rows && ry < columns && !visited[rx][ry] && grid[rx][ry] != '#'){
                qx.push(rx);
                qy.push(ry);
                px[rx][ry] = cx;
                py[rx][ry] = cy;
//                cout<<rx<<" "<<ry<<" -> "<<cx<<" "<<cy<<endl;
                visited[rx][ry] = true;
            }
        }
    }
    cout<<"There is no path"<<endl;
    return;
}

int main(){
    int rows = 5, columns = 7;
    createGrid(rows, columns);
    printGrid(rows, columns);
    shortestPathGrid(rows, columns);
    printGrid(rows, columns);

}