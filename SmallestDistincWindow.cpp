// Given a string str, your task is to find the length of the smallest window that contains all the 
// characters of the given string at least once.

// Example:

// Input: str = "aabcbcdbca"
// Output: 4
// Explanation: Sub-String "dbca" has the smallest length that contains all the characters of str.
// Input: str = "aaab"
// Output: 2
// Explanation: Sub-String "ab" has the smallest length that contains all the characters of str.
// Input: str = "aa"
// Output: 1

#include<bits/stdc++.h>
using namespace std;


int findSubString(string& s) {
    int n = s.size();
    map<char,int>ch;
    for(char c:s){
        ch[c]++;
    }
    int k = ch.size();

    //smallest substring of size k 
    int i = 0;
    int j = 0;
    map<char,int>mp;
    int mini = INT_MAX;
    while(j < n){
        mp[s[j]]++;
        while(mp.size() == k && i <= j){
            mini = min(mini,j - i + 1);
            mp[s[i]]--;
            if(mp[s[i]] == 0){
                mp.erase(s[i]);
            }
            i++;
        }

        j++;
    }
    if(mini == INT_MAX) return 0;

    return mini;
}
int main(){
    string str = "aabcbcdbca";
    int ans = findSubString(str);
    cout<<ans;
    return 0;
}