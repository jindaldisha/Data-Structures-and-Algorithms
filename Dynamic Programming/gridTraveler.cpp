//
// Created by disha on 15-05-2021.
//

// Say that you are a traveler on a 2d grid. you begin in the top left corner and your goal is to travel to the
// bottom-right corner. You may only move down or right.
// In how many ways can you travel to the goal on a grid with dimensions m*n.

#include <bits/stdc++.h>
using namespace std;

long long int gridTravellerMemo(int row, int column, unordered_map<string, long long int> &memo);
long long int gridTravellerRecur(int row, int column);
long long int gridTravellerTab(int row, int column);
long long int gridTravellerTab2(int row, int column);



void filler(int row, int column){
    unordered_map<string, long long int> memo;
    cout<<gridTravellerTab(row, column)<<endl;
    cout<<gridTravellerTab2(row, column)<<endl;
    cout<<gridTravellerMemo(row, column,memo)<<endl;
//    cout<<gridTravellerRecur(row,column)<<endl;

}

// O(n*m) time
// O(n*m) space
// Dynamic Programming (Memoization) - Storing key values in an array
long long int gridTravellerMemo(int row, int column, unordered_map<string, long long int> &memo){
    string key = to_string(row) + "," + to_string(column);
    string key2 = to_string(column) + "," + to_string(row);
    if(memo.count(key)) return memo[key];
    if(memo.count(key2)) return memo[key2];
    if(row == 1 || column == 1) return 1;
    if(row == 0 || column == 0) return 0;
    memo[key] = gridTravellerMemo(row-1, column, memo) + gridTravellerMemo(row, column-1, memo);
    memo[key2] = memo[key];
    return memo[key];
}


// O(2^(n+m)) time
// O(n+m) space
//Recursive Solution
long long int gridTravellerRecur(int row, int column){
    if (row == 1 || column == 1) return 1;
    return gridTravellerRecur(row - 1, column) + gridTravellerRecur(row, column - 1);
}

// O(n*m) time
// O(n*m) space
//Dynamic Programming Solution (Tabulation)
long long int gridTravellerTab(int row, int column){
    long long int memo[row+1][column+1];
    memo[1][1] = 1;
    for(int i = 1; i <= row; i++){
        memo[i][1] = 1;
    }
    for(int i = 0; i <= column; i++){
        memo[1][i] = 1;
    }
    for(int i = 2; i <= row; i++){
        for(int j = 2; j <= column; j++){
            memo[i][j] = memo[i-1][j] + memo[i][j-1];
        }
    }
    return memo[row][column];
}

/* visualize the problem as a table
 * size the table based on the inputs
 * initialize the table with default values
 * seed the trivial answer into the table
 * iterate through the table
 */
long long int gridTravellerTab2(int row, int column){
    long long int memo[row+2][column+2] = {0};
    memo[1][1] = 1;
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= column; j++){
            memo[i+1][j] += memo[i][j];
            memo[i][j+1] += memo[i][j];
        }
    }
    return memo[row][column];
}



int main() {
    filler(2,3);
    filler(3,3);
    filler(18,18);
}