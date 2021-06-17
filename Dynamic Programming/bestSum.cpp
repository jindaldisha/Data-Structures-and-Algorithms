//
// Created by disha on 26-05-2021.
//

#include <bits/stdc++.h>
using namespace std;

//returns the shortest combination of numbers that add exactly to the targetSum
vector<int> bestSumRecur(int targetSum, vector<int> numbers, vector<int> &ans, vector<int> &shortestCombination);
vector<int> bestSumRecur2(int targetSum, vector<int> numbers, vector<int> ans, vector<int> &shortestCombination);
vector<int> bestSumTab(int targetSum, vector<int> numbers);


void print_vector(vector<int> &x){
    for(int i = 0; i < x.size(); i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void Filler(vector<int> numbers, int targetSum){
    vector<int> ans;
    vector<int> shortest;
//    bestSumRecur2(targetSum, numbers, ans, shortest);
//    bestSumRecur(targetSum, numbers, ans, shortest);
    shortest = bestSumTab(targetSum, numbers);
    if(shortest.empty()){
        cout<<"EMPTY"<<endl;
    }
    else{
        cout<<"Best Sum for "<<targetSum<<": ";
        print_vector(shortest);
    }
}


// m - targeSum
// n - numbers.size
// O(n^m * m) time    (branching factor ^ height of the tree)
// O(m*m) space
//Recursive Approach
vector<int> bestSumRecur(int targetSum, vector<int> numbers, vector<int> &ans, vector<int> &shortestCombination){
    for(int number : numbers){
        int remainder = targetSum - number;
//        cout<<targetSum<<" - "<<number<<" = "<<remainder<<endl;
//        print_vector(ans);
        if(remainder == 0){
            ans.push_back(number);
//            print_vector(ans);
            if(shortestCombination.empty() || ans.size() < shortestCombination.size()){
                shortestCombination = ans;
//                cout<<"Shortest Combination: ";
//                print_vector(shortestCombination);
            }
            ans.pop_back();
        }
        else if(remainder > 0){
            ans.push_back(number);
            bestSumRecur(remainder, numbers, ans, shortestCombination);
        }
    }
    ans.pop_back();
    return shortestCombination;
}

vector<int> bestSumRecur2(int targetSum, vector<int> numbers, vector<int> ans, vector<int> &shortestCombination){
    for(int number: numbers){
        int remainder = targetSum - number;
        cout<<targetSum<<" - "<<number<<" = "<<remainder<<endl;

        if(remainder == 0){
            ans.push_back(number);
            return ans;
        }
        if(remainder > 0){
            vector<int> currAns;
            currAns = bestSumRecur2(remainder, numbers, currAns, shortestCombination);
            if(!currAns.empty()){
                currAns.push_back(number);
                return currAns;
            }
        }
    }
}

// m - targeSum
// n - numbers.size
// O(n*m * m) time
// O(m*m) space
// Tabulation
vector<int> bestSumTab(int targetSum, vector<int> numbers){
    unordered_map<int, vector<int>> memo;
    memo[0];
    for(int i = 0; i <= targetSum; i++){
        if(memo.count(i)){
            for(int j: numbers){
                int curr = i + j;
                if(curr <= targetSum){
                    if((memo[curr].empty()) || (memo[curr].size() > (memo[i].size() + 1))){
                        memo[curr] = memo[i];
                        memo[curr].push_back(j);
                    }
                }
            }
        }
    }
    return memo[targetSum];
}


int main() {
    Filler({5,3, 4, 7},7);
    Filler({2,3,5},8);
    Filler({1,4,5},8);
    Filler({1,2,5,25},100);
}