// Given a string s, find the length of the longest substring without repeating characters.
// Input: s = "geeksforgeeks"
// Output: 7

// Input: s = "abdefgabef"
// Output: 6

#include<bits/stdc++.h>
using namespace std;

int longestUniqueSubstring(string &s) {
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
        
        maxi = max(maxi,j - i + 1);
        j++;
    }
    return maxi;
    
}

int main(){
    string s = "geeksforgeeks";
    int ans = longestUniqueSubstring(s);
    cout<<ans;
    return 0;
}
