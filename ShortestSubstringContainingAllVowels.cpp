// You are given two strings, s1 and s2, where s1 contains distinct lowercase vowels (a, e, i, o, u), 
// and s2 contains lowercase English letters. Your task is to find the length of the shortest contiguous 
// substring within s2 that contains all the vowels present in s1 at least once, in any order.
// Note: If there is no such substring in s2, return -1.

// Examples:

// Input: s1 = "ae", s2 = "acbaudeq"
// Output: 4
// Explanation: The shortest substring of "acbaudeq" that contains both vowels 'a' and 'e' from s1 = "ae" is "aude", which has length 4.
// Input: s1 = "iou", s2 = "iuixoiu"
// Output: 3
// Explanation: The shortest substring of "iuixoiu" that contains all vowels 'i', 'o', and 'u' from s1 = "iou" is "oiu", which has length 3.
// Input: s1 = "aeiou", s2 = "uoiee"
// Output: -1
// Explanation: The string s2 = "uoiee" is missing the vowel 'a' from s1 = "aeiou", so no substring can contain all required vowels, and the answer is -1.

#include<bits/stdc++.h>
using namespace std;

int substrWithVowels(string &s1, string &s2) {
    int n = s2.size();
    map<char,int>vowels;

    for(char c:s1){
        vowels[c]++;
    }

    int k = vowels.size();
    int i = 0;
    int j = 0;

    map<char,int>mp;
    int mini = INT_MAX;
    
    while(j < n){
        if(s2[j] == 'a' || s2[j] == 'e' || s2[j] == 'i' || s2[j] == 'o' || s2[j] == 'u'){
            if(vowels.find(s2[j]) != vowels.end()){
                mp[s2[j]]++;
            }
        }

        while(mp.size() == k && i <= j){
            mini = min(mini , j - i + 1);
            if(vowels.find(s2[i]) != vowels.end()){
                mp[s2[i]]--;
                if(mp[s2[i]] == 0){
                    mp.erase(s2[i]);
                }
            }
            i++;
        }
        j++;
    }   
    return mini == INT_MAX ? -1 : mini;
}

int main(){
    string s1 = "ae";
    string s2 = "acbaudeq";
    int ans = substrWithVowels(s1,s2);
    cout<<ans;
    return 0;
}