// Given an array arr[] consisting of positive integers, your task is to find the length of the 
// longest subarray that contains at most two distinct integers.
// Input: arr[] = [2, 1, 2]
// Output: 3

// Input: arr[] = [3, 1, 2, 2, 2, 2]
// Output: 5

#include<bits/stdc++.h>
using namespace std;

int totalElements(vector<int> &arr) {
    int n = arr.size();
    int i = 0;
    int j = 0;
    map<int,int>mp;
    int maxi = 0;

    while(j < n){
        mp[arr[j]]++;

        while(mp.size() > 2 && i < j){
            mp[arr[i]]--;
            if(mp[arr[i]] == 0){
                mp.erase(arr[i]);
            }
            i++;
        }
        if(mp.size() <= 2) {
            maxi = max(maxi,j - i + 1); 
        }
        j++;
    }
    return maxi;
        
}

int main(){
    vector<int>arr = {3, 1, 2, 2, 2, 2};
    int ans =  totalElements(arr);
    cout << ans;
    return 0;
}