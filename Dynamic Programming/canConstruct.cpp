//
// Created by disha on 15-06-2021.
//
/* Write a function
 * canConstruct(target, wordBank)
 * that accepts a target string and an array of strings.
 * The function should return a boolean indicating whether or not the 'target' can
 * be constructed by concatenating elements of the 'wordBank' array.
 * You may reuse elements of 'wordBank' as many times as needed.
 * */

#include <bits/stdc++.h>
using namespace std;

bool canConstructRecur(string target, vector<string> &wordBank);
bool canConstructMemo(string target, vector<string> &wordBank, unordered_map<string, bool> &memo);
bool canConstructTab(string target, vector<string> wordBank);


void filler(string target, vector<string> wordBank){
    unordered_map<string, bool> memo;
    bool ans;
//    ans = canConstructRecur(target, wordBank);
    ans = canConstructTab(target, wordBank);
//    ans = canConstructMemo(target, wordBank, memo);
    cout<<(ans ? "YES" : "NO")<<endl;
}


/* Recursive Approach
 * m - target.length - height of the tree
 * n - wordBank.length - the branching factor
 * Time - O(n^m * m)
 * Space - O(m*m)
 * */
bool canConstructRecur(string target, vector<string> &wordBank){
    if(target.length() == 0) {
        return true;
    }
    for(auto word: wordBank){
        if(target.substr(0, word.length()) == word){
            string remainder = target.substr(word.length(), target.length());
            cout<<target<<" - "<<word<<" = "<<remainder<<endl;
            if(canConstructRecur(remainder, wordBank)){
                return true;
            };
        }
    }
    return false;
}


/* Memoization Approach
 * m - target.length - height of the tree
 * n - wordBank.length - the branching factor
 * Time - O(n*m * m)
 * Space - O(m*m)
 * */
bool canConstructMemo(string target, vector<string> &wordBank, unordered_map<string, bool> &memo){
    if(memo.count(target)){
        cout<<"Memo has value for: "<<target<<endl;
        return memo[target];
    }
    if(target.length() == 0) {
        memo[target] = true;
        return true;
    }
    for(auto word: wordBank){
        if(target.substr(0, word.length()) == word){
            string remainder = target.substr(word.length(), target.length());
            cout<<target<<" - "<<word<<" = "<<remainder<<endl;
            if(canConstructMemo(remainder, wordBank, memo) ){
                memo[target] = true;
                return true;
            };
        }
    }
    memo[target] = false;
    return false;
}


/* Tabulation Approach
 * m - target.length - height of the tree
 * n - wordBank.length - the branching factor
 * Time - O(n*m * m)
 * Space - O(m)
 * */
bool canConstructTab(string target, vector<string> wordBank){
    int n = target.length();
     vector<bool> memo(n + 1, false);
     memo[0] = true;
     for(int i = 0; i <= n; i++){
         if(memo[i]){
             for(auto word: wordBank){
                 int x = word.length();
                if(word == target.substr(i, x)){
                    cout<<target.substr(i)<<" - "<<word<<endl;
                    memo[i + x] = true;
                }
             }
         }
         if(memo[n]){
             return true;
         }
     }
     return memo[n];
}


int main() {
    filler("abcdef", {"ab","abc","cd","def","abcd"});
    filler("skateboard", {"bo","rd","ate","t","ska","sk","boar"});
    filler("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"});
    filler("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e","ee","eee","eeee","eeeee", "eeeeee"});
}