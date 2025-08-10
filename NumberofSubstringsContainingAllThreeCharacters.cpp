// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
// Example 3:

// Input: s = "abc"
// Output: 1

#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int n = s.size();
    int count = 0;
    int i = 0;
    int j = 0;
    map<char,int>mp;
    while(j < n){
        if(s[j] == 'a' || s[j] == 'b' || s[j] == 'c'){
            mp[s[j]]++;
        }

        while(mp.size() == 3 && i < j){
            count += n - j;
            mp[s[i]]--;
            if(mp[s[i]] == 0){
                mp.erase(s[i]);
            }
            i++;
        }
        j++;
    }
    return count;
}

int main(){
    string s = "aaabc";
    int ans = numberOfSubstrings(s);
    cout<<ans;
    return 0;
}