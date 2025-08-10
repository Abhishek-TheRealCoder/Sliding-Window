// You are given a string 'str' and an integer ‘K’. 
// Your task is to find the length of the largest substring with at most ‘K’ 
// distinct characters.

// For example:
// You are given ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’].
// Hence the answer is 7.

// Input 1:
// s = "abbbbbbc" ,k = 2
// Output 7

// Input 2:
// s = "abcddefg" , k = 3
// Output 4

// Sol) Remember uestion says Atmost k distinct character
#include<bits/stdc++.h>
using namespace std;

int solve(int k,string s){
    int n = s.size();
    int i = 0;
    int j = 0;
    map<char,int>mp;
    int maxi = 0;
    while(j < n){
        mp[s[j]]++;
        while(mp.size() > k && i < j){
            mp[s[i]]--;
            if(mp[s[i]] == 0){
                mp.erase(s[i]);
            }
            i++;
        }
        
        if(mp.size() <= k) {
            maxi = max(maxi,j - i + 1);
        
        }
        j++;
    }
    return maxi;
}

int kDistinctChars(int k, string &str)
{
    // Write your code here
    return solve(k,str);
}

int main(){
    string s = "abbbbbbc";
    int k = 2;
    int ans = kDistinctChars(k,s);
    cout<<ans;
}

