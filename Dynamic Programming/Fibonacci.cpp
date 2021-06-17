//
// Created by disha on 08-05-2021.
//

#include <bits/stdc++.h>
using namespace std;
//memoization - strategy to solve dp - store some duplicate sub problems and use those results later on
// problem of overlapping sub problems is known as dynamic programming
// we have some larger problem and we can break it down into smaller instances of the same problem

int fibRecursion(int n);
long long int fibTab(int n);
long long int fibMemo(int n, unordered_map<int, long long int> &memo);


void filler(int n){
    unordered_map<int, long long int> memo;
    cout<<"Recursion for " <<n<<": "<<fibRecursion(n)<<endl;
    cout<<"Tabulation for " <<n<<": "<<fibTab(n)<<endl;
    cout<<"Memoization for " <<n<<": "<<fibMemo(n, memo)<<endl;
}

// O(2^n) time
// O(n) space
//Recursive approach of Fibonacci
int fibRecursion(int n){
    if(n <= 2) return 1;
    return fibRecursion(n-1) + fibRecursion(n-2);
}

// O(n) time
// O(n) space
//We solve a dynamic program iteratively by building a table
long long int fibTab(int n){
    long long int memo[n+1];
    memo[0] = 0;
    memo[1] = 1;
    for(int i = 2; i <= n; i++){
        memo[i] = memo[i-1] + memo[i-2];
    }
    return memo[n];
}

// O(n) time
// O(n) space
//We solve the problem recursively by storing the values in a memo
long long int fibMemo(int n, unordered_map<int, long long int> &memo){
    /* if the fib of n is already in the memo,
     * we simply return it instead of making more calls*/
    if(memo.count(n)){
        return memo[n];
    }
    //base case
    if(n <= 0) return 0;
    if(n <= 2) return 1;
    memo[n] = fibMemo(n-1, memo) + fibMemo(n-2, memo);
    return memo[n];
}

int main() {
    filler(3);
    filler(34);
    filler(40);
    filler(12);
    filler(50);

}