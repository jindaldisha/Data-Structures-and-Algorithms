//
// Created by disha on 15-05-2021.
//

// Write a function canSum(targetSum, numbers) that takes in a targetSum and an array of numbers as an arguments.
// The function should return a boolean indicating whether or not it is possible to generate the targetSum using numbers from the array.
// You may use an element of the array as many times as you need.
// You may assume that all input numbers are non-negative.

#include <bits/stdc++.h>
using namespace std;

bool canSumRecur(int targetSum, vector<int> &numbers);
bool canSumMemo(int targetSum, vector<int> &numbers, unordered_map<int, bool> &memo);
bool canSumTab(int targetSum, vector<int> numbers);


void filler(vector<int> numbers, int targetSum){
    unordered_map<int, bool> memo;
    bool ans = canSumMemo(targetSum, numbers, memo);
//    bool ans = canSumRecur(targetSum, numbers);
    bool ans2 = canSumTab(targetSum, numbers);
    cout<<"Memo: "<<(ans ? "YES" : "NO")<<endl;
    cout<<"Tab: "<<(ans2 ? "YES" : "NO")<<endl;
    cout<<endl;

}


// O(n^m) time
// O(m) space
//Brute Force Recursive Solution
bool canSumRecur(int targetSum, vector<int> &numbers){
//    cout<<"Target Sum: "<<targetSum<<endl;
    if(targetSum == 0) return true;
    for(int i = 0; i < numbers.size(); i++){
        int remainder = targetSum - numbers[i];
//        cout<<targetSum<<" - "<<numbers[i]<<" = "<<remainder<<endl;
        if(remainder >= 0){
            if(canSumRecur(remainder, numbers)) return true;
        }
    }
    return false;
}


// O(n*m) time
// O(m) space
//Dynamic Approach (Memoization)
bool canSumMemo(int targetSum, vector<int> &numbers, unordered_map<int, bool> &memo){
//    cout<<"Target Sum: "<<targetSum<<endl;
    if(memo.count(targetSum)) {
//        cout<<"Memo has value for "<<targetSum<<endl;
        return memo[targetSum];
    }
    if(targetSum == 0) return true;
    for(int i = 0; i < numbers.size(); i++){
        int remainder = targetSum - numbers[i];
//        cout<<targetSum<<" - "<<numbers[i]<<" = "<<remainder<<endl;
        if(remainder >= 0){
            if(canSumMemo(remainder, numbers, memo)) {
                memo[targetSum] = true;
                return true;
            }
        }
    }
    memo[targetSum] = false;
    return false;
}

// n - numbers.length
// m - targetSum
// O(n*m) time
// O(m) space
//Dynamic Approach (Tabulation)
bool canSumTab(int targetSum, vector<int> numbers){
    vector<bool> memo(targetSum + 1, false);
    memo[0] = true;
    for(int i = 0; i <= targetSum; i++){
        if(memo[i]){
            for(auto j : numbers){
                if(i + j <= targetSum){
//                    cout<<i<<" + "<<j<<" = "<<i+j<<endl;
                    memo[i + j] = true;
                }
            }
        }
        if(memo[targetSum]) return true;
    }
    return memo[targetSum];
}

int main() {
    filler({2,3},7);
    filler({14,7},300);
    filler({2,4},7);
    filler({2,3,5},8);
    filler({7,14},300);
}