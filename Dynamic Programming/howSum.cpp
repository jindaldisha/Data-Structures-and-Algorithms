//
// Created by disha on 20-05-2021.
//
// Write a function howSum(targetSum, numbers) that takes in a targetSum and an array of numbers as an arguments.
// The function should return an array containing any combination of elements that add up to exactly the targetSum.
// You may use an element of the array as many times as you need.
// You may assume that all input numbers are non-negative.

#include <bits/stdc++.h>
using namespace std;
vector<int> howSumRecur(vector<int> numbers, int targetSum, vector<int> &ans);
vector<int> howSumMemo(int targetSum, vector<int> numbers, vector<int> &ans, unordered_map<int, vector<int>> &memo);
vector<int> howSumTab(int targetSum, vector<int> numbers);


void filler(vector<int> numbers, int targetSum){
    vector<int> ans;
    unordered_map<int,vector<int>> memo;
//    howSumMemo(targetSum, numbers, ans, memo);
//    howSumRecur(numbers, targetSum, ans);
    ans = howSumTab(targetSum, numbers);
    if(ans.empty()){
        cout<<"EMPTY"<<endl;
    }
    else{
        cout<<"FINAL: ";
        for(int j : ans){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}



//m -> targetSum
//n -> size of the array
// Time Complexity: O(n^m*m)
//Space Complexity: O(m)
vector<int> howSumRecur(vector<int> numbers, int targetSum, vector<int> &ans){
    for(int i = 0; i < numbers.size(); i++){
        int remainder = targetSum - numbers[i];
        cout<<targetSum<<" - "<<numbers[i]<<" = "<<remainder<<endl;
        if(remainder == 0){
            ans.push_back(numbers[i]);
            return ans;
        }
        else if(remainder > 0){
            howSumRecur(numbers, remainder, ans);
            if(!ans.empty()){
                ans.push_back(numbers[i]);
                return ans;
            }
        }
    }
    return ans;
}


//m -> targetSum
//n -> size of the array
// Time Complexity: O(n*m*m)
//Space Complexity: O(m*m)
vector<int> howSumMemo(int targetSum, vector<int> numbers, vector<int> &ans, unordered_map<int, vector<int>> &memo){
    if(memo.count(targetSum)) {
        cout<<"Memo has value for: "<<targetSum<<endl;
        return memo[targetSum];
    }
    for(int i = 0; i < numbers.size(); i++){
        int remainder = targetSum - numbers[i];
        cout<<targetSum<<" - "<<numbers[i]<<" = "<<remainder<<endl;
        if(remainder == 0){
            ans.push_back(numbers[i]);
            memo[targetSum] = ans;
            return memo[targetSum];
        }
        else if(remainder > 0){
            howSumMemo(remainder, numbers, ans, memo);
            if(!ans.empty()){
                ans.push_back(numbers[i]);
                memo[targetSum] = ans;
                return memo[targetSum];
            }
        }
    }
    memo[targetSum] = ans;
    return memo[targetSum];
}

//m -> targetSum
//n -> size of the array
// Time Complexity: O(n*m*m) extra m for copying an array of length m
//Space Complexity: O(m*m)
vector<int> howSumTab(int targetSum, vector<int> numbers){
    unordered_map<int, vector<int>> memo;
    memo[0];
    for(int i = 0; i <= targetSum; i++){
        if(memo.count(i)){
            for(int j : numbers){
                int curr = i + j;
                if(curr <= targetSum){
                    memo[curr] = memo[i];
                    memo[curr].push_back(j);
                }
            }
        }
        if(!memo[targetSum].empty()){
            return memo[targetSum];
        }
    }
    return memo[targetSum];
}

int main() {
    filler({2,3},7);
    filler({5,3,4},7);
    filler({2,4},7);
    filler({2,3,5},8);
    filler({7,14},300);

}