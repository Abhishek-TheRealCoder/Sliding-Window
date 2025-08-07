// Given an integer array arr[] and a number k.
// Find the count of distinct elements in every window of size k in the array.
// Input: arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
// Output:  [3, 4, 4, 3]

// Input: arr[] = [4, 1, 1], k = 2
// Output: [2, 1]

// Input: arr[] = [1, 1, 1, 1, 1], k = 3
// Output: [1, 1, 1]

#include<bits/stdc++.h>
using namespace std;

vector<int> countDistinct(vector<int> &arr, int k) {
    int n = arr.size();
    int i = 0;
    int j = 0;
    map<int,int>mp;
    vector<int>ans;
    
    while(j < n){
        mp[arr[j]]++;
        
        while(j - i + 1 > k && i < j){
            mp[arr[i]]--;
            if(mp[arr[i]] == 0){
                mp.erase(arr[i]);
            }
            i++;
        }

        if(j - i + 1 == k){
            ans.emplace_back(mp.size());
        }
        j++;
    }
    return ans;
}

int main(){
    vector<int>arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    vector<int>ans =  countDistinct(arr,k);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}