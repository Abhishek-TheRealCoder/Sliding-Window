// Given a string S consisting of the characters 0, 1 and 2. 
// Your task is to find the length of the smallest substring of string S that contains all the three 
// characters 0, 1 and 2. If no such substring exists, then return -1.

// Example 1:

// Input:
// S = 10212
// Output:
// 3
// Explanation:
// The substring 102 is the smallest substring
// that contains the characters 0, 1 and 2.

// Example 2:

// Input: 
// S = 12121
// Output:
// -1
// Explanation: 
// As the character 0 is not present in the
// string S, therefor no substring containing
// all the three characters 0, 1 and 2
// exists. Hence, the answer is -1 in this case.

#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;

int smallestSubstring(string s) {
    // Code here
    int n = s.size();
    int i = 0;
    int j = 0;
    map<char,int>mp;
    int mini = INT_MAX;

    while(j < n){
        if(s[j] == '0' || s[j] == '1' || s[j] == '2'){
            mp[s[j]]++;
        }

        while(mp.size() == 3 && i < j){
            mini = min(mini,j - i + 1);
            mp[s[i]]--;
            if(mp[s[i]] == 0){
                mp.erase(s[i]);
            }
            i++;
        }

        j++;
    }

    return mini == INT_MAX ? -1 : mini;
}

int main(){
    string s = "1212";
    int ans = smallestSubstring(s);
    cout<<ans;
    return 0;
}