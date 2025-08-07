// You are given a string consisting of lowercase characters and an integer k,
// You have to count all possible substrings that have exactly k distinct characters. 
// Input: s = "aba", k = 2
// Output: 3

// Input: s = "aa", k = 1
// Output: 3

// Input: s = "zatpvvsnhx", k = 1
// Output: 11

// Solution idea
// atmost means - zyada se zyada or we can say maximum limit
// Substrings with K Distinct = substring with atmost(k) distinct - substring with atmost(k-1) distinct
// example k = 3
// atmost(3) = substring with 1 distinct + substring with 2 distinct + substring with 3 distinct
// atmost(2) = substrings with 1 distinct + substring with 2 distinct
// Substrings with 3 Distinct = substring with 1 distinct + substring with 2 distinct + substring with 3 distinct - (substring with 1 distinct + substring with 2 distinct)
// which results to 
// Substrings with 3 Distinct = substrings with 3 distinct

#include<bits/stdc++.h>
using namespace std;

int solve (string& s, int k) {
        // code here.
        int n = s.size();
        map<char,int>mp;
        int i = 0;
        int count = 0;
        int j = 0;
        while(j < n){
            mp[s[j]]++;
            while(mp.size() > k && i < j){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            
            if(mp.size() <= k){
                count += j - i + 1;
            }
            j++;
        }
        return count;
    }
int countSubstr(string &s, int k){
    return solve(s,k) - solve(s,k-1);
}

int main(){
    string s =  "zatpvvsnhx";
    int k = 1;
    int ans = countSubstr(s,k);
    cout<<ans;
    return 0;
}