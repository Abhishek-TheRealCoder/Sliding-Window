// Given a string s, find the length of longest Substring without duplicate characters
// Input: s = "abcabcbb"
// Output: 3

// Input: s = "bbbbb"
// Output: 1

// Input: s = "pwwkew"
// Output: 3

#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string& s){
    int n = s.size();
    int i = 0;
    int j = 0;
    map<char,int>mp;
    int maxi = 0;
    while(j < n){
        mp[s[j]]++;

        while(mp[s[j]] > 1 && i < j){
            mp[s[i]]--;
            if(mp[s[i]] == 0){
                mp.erase(s[i]);
            }
            i++;
        }
        
        maxi = max(maxi,j-i+1);
        j++;
    }
    return maxi;
}

int main(){
    string s = "abcabcbb";
    int ans = lengthOfLongestSubstring(s);
    cout<<ans;
    return 0;
}

