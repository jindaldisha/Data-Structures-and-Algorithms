//
// Created by disha on 15-06-2021.
//
/* Write a function
 * countConstruct(target, wordBank)
 * that accepts a target string and an array of strings.
 * The function should return the number of ways that the 'target' can
 * be constructed by concatenating elements of the 'wordBank' array.
 * You may reuse elements of 'wordBank' as many times as needed.
 * */

#include <bits/stdc++.h>
using namespace std;

int countConstructRecur(string target, vector<string> wordBank, int ways);
int countConstructMemo(string target, vector<string> wordBank, unordered_map<string, int> &memo);
int countConstructTab(string target, vector<string> wordBank);


void filler(string target, vector<string> wordBank){
    unordered_map<string, int> memo;
    int ans = 0;
    int ways = 0;
//    ans = countConstructRecur(target, wordBank, ways);
//    ans = countConstructMemo(target, wordBank, memo);
    ans = countConstructTab(target, wordBank);
    cout<<"Total Number of Ways for string \""<<target<<"\": "<<ans<<endl;
    cout<<endl;
}


/* Recursive Approach
 * m - target.length - height of the tree
 * n - wordBank.length - the branching factor
 * Time - O(n^m * m)
 * Space - O(m*m)
 * */
int countConstructRecur(string target, vector<string> wordBank, int ways){
    if(target.length() == 0) {
        return ways + 1;
    }
    for(auto word: wordBank){
        if(target.substr(0, word.length()) == word){
            string remainder = target.substr(word.length(), target.length());
            cout<<target<<" - "<<word<<" = "<<remainder<<endl;
            ways = countConstructRecur(remainder, wordBank, ways);
        }
    }
    return ways;
}


/* Memoization Approach
 * m - target.length - height of the tree
 * n - wordBank.length - the branching factor
 * Time - O(n*m * m)
 * Space - O(m*m)
 * */
int countConstructMemo(string target, vector<string> wordBank, unordered_map<string, int> &memo){
    if(memo.count(target)){
//        cout<<"Memo has value for: "<<target<<endl;
        return memo[target];
    }
    if(target.length() == 0) {
        return 1;
    }
    int totalCount = 0;
    for(auto word: wordBank){
        if(target.substr(0, word.length()) == word){
            string remainder = target.substr(word.length(), target.length());
//            cout<<target<<" - "<<word<<" = "<<remainder<<endl;
            int z = countConstructMemo(remainder, wordBank, memo);
            totalCount += z;
        }
    }
    memo[target] = totalCount;
    return totalCount;
}


/* Tabulation Approach
 * m - target.length - height of the tree
 * n - wordBank.length - the branching factor
 * Time - O(n*m * m)
 * Space - O(m)
 * */
int countConstructTab(string target, vector<string> wordBank){
    int n = target.length();
    vector<int> memo(n+1, 0);
    memo[0] = 1;
    for(int i = 0; i <= n; i++){
        if(memo[i] > 0){
            for(auto word: wordBank){
                int x = word.length();
                if(word == target.substr(i, x)){
                    cout<<target.substr(i)<<" - "<<word<<endl;
                    memo[i + x] += memo[i];
                }
            }
        }
    }
    return memo[n];
}

int main() {
    filler("abcdef", {"ab","abc","cd","def","abcd"}); //1
    filler("purple",{"purp","p","ur","le","purpl"}); //2
    filler("skateboard", {"bo","rd","ate","t","ska","sk","boar"}); //0
    filler("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}); //4
    filler("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e","ee","eee","eeee","eeeee", "eeeeee"}); //0
}