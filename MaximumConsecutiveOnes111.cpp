// Given a binary array nums and an integer k, return the maximum number of
// consecutive 1's in the array if you can flip at most k 0's.

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Input: nums = [0,0,0,1], k = 4  //atmost zyada se zyada 4 zeroes 
// Output: 4

// sol) What if we convert this Question to calculate longest subarray with __atmost__  k  zeroes
#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& arr, int k) {
    int n = arr.size();
    int i = 0;
    int j = 0;
    map<int,int>mp;
    int maxi = 0;
    while(j < n){
        
        mp[arr[j]]++;
        
        while(mp[0] > k && i < j){
            mp[arr[i]]--;
            if(mp[arr[i]] == 0){
                mp.erase(arr[i]);
            }
            i++;
        }
         
        if(mp[0] <= k){
            maxi = max(maxi , j - i + 1);
        }

        j++;
    }

    return maxi == INT_MIN ? -1 : maxi;
}
int main(){
    vector<int>a = {0,0,0,1};
    int k = 3;
    int ans = longestOnes(a,k);
    cout<<ans;
    return 0;
}