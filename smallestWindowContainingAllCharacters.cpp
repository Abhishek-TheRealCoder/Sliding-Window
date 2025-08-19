// Given two strings s1 and s2. Find the smallest window in the string s1 consisting of all the characters
// (including duplicates) of the string s2. return empty string in case no such window is present.
// If there are multiple such windows of the same length, return the one with the least starting index.
// Note: All characters are in lowercase letters. 
// Input: s1 = "timetopractice", s2 = "toc"
// Output: "toprac"

// Input: s1 = "zoomlazapzo", s2 = "oza"
// Output: "apzo"

#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string &s1, string &s2) {
    //  code here
    int n = s1.size();
    int i = 0;
    int j = 0;
    map<char,int>mp;
    for(auto x: s2){
        mp[x]++;
    }

    int requiredLength = s2.size();
    int mini = INT_MAX;
    int sp = -1;
    while(j < n){
        if(mp[s1[j]] > 0){
            requiredLength--;
        }
        mp[s1[j]]--;

        while(requiredLength == 0){
            int size = j - i + 1;
            if(size < mini){
                mini = size;
                sp = i;
            }

            mp[s1[i]]++;
            if(mp[s1[i]] > 0) requiredLength++;
            i++;
        }

        j++;
    }

    return mini == INT_MAX ? "-1" : s1.substr(sp,mini);


}

int main(){
    string s1 = "timetopractice";
    string s2 = "toc";
    string ans = smallestWindow(s1,s2);
    cout<<ans;
    return 0;
}