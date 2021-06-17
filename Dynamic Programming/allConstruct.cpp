//
// Created by disha on 16-06-2021.
//

/* Write a function
 * allConstruct(target, wordBank)
 * that accepts a target string and an array of strings.
 * The function should return a 2D array containing all of the ways that the 'target' can
 * be constructed by concatenating elements of the 'wordBank' array.
 * You may reuse elements of 'wordBank' as many times as needed.
 * */

#include <bits/stdc++.h>
using namespace std;

vector<string> allConstructRecur(string target, vector<string> wordBank, vector<vector<string>> &ways, vector<string> &currWay);
vector<vector<string>> allConstructTab(string target, vector<string> wordBank);


void printVector(vector<vector<string>> x){
    if(x.empty()){
        cout<<"There are no ways"<<endl;
    }
    else{
        for(auto i: x){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    cout<<endl;
}


void filler(string target, vector<string> wordBank){
    vector<vector<string>> ways;
    vector<string> currWay;
//    allConstructRecur(target, wordBank, ways, currWay);
    ways = allConstructTab(target, wordBank);
    cout<<"Ways of constructing '"<<target<<"': "<<endl;
    printVector(ways);
}


/* m - target.length - height of the tree
 * n - wordBank.length - the branching factor
 * Time - O(n^m)
 * Space - O(m)
 * */
vector<string> allConstructRecur(string target, vector<string> wordBank, vector<vector<string>> &ways, vector<string> &currWay){
    if(target.length() == 0){
        ways.push_back(currWay);
        return currWay;
    }
    for(auto word: wordBank) {
        if (target.substr(0, word.length()) == word) {
            string remainder = target.substr(word.length(), target.length());
            cout << target << " - " << word << " = " << remainder << endl;
            currWay.push_back(word);
            allConstructRecur(remainder, wordBank, ways, currWay);
            currWay.pop_back();
        }
    }
    return currWay;
}


/* m - target.length - height of the tree
 * n - wordBank.length - the branching factor
 * Time - O(n^m)
 * Space - O(n^m)
 * */
vector<vector<string>> allConstructTab(string target, vector<string> wordBank){
    unordered_map<int, vector<vector<string>>> memo;
    vector<string> s;
    memo[0].push_back(s);
    int n = target.length();
    for(int i = 0; i < n; i++){
        if(memo.count(i)){
            for(auto word: wordBank){
                int x = word.length();
                if(word == target.substr(i, x)){
                    cout<<target.substr(i)<<" - "<<word<<endl;
                    vector<vector<string>> curr = memo[i];
                    for(auto j : curr){
                        vector<string> temp = j;
                        temp.push_back(word);
                        memo[i + x].push_back(temp);
                    }

                }
            }
        }
    }
    return memo[n];
}


int main() {
    filler("abcdef", {"ab","abc","cd","def","abcd", "ef", "c"});
    filler("purple",{"purp","p","ur","le","purpl"});
    filler("skateboard", {"bo","rd","ate","t","ska","sk","boar"});
    filler("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"});
//    filler("aaaaaaaaaaaaaaaaaaaaaaaaaaaaz", {"a", "aa", "aaa", "aaaa", "aaaaa"});
}


/*
 * Ways of constructing 'abcdef':
ab cd ef
ab c def
abc def
abcd ef

 Ways of constructing 'purple':
purp le
p ur p le

Ways of constructing 'skateboard':
There are no ways

 Ways of constructing 'enterapotentpot':
enter a p ot ent p ot
enter a p ot ent p o t
enter a p o t ent p ot
enter a p o t ent p o t
*/