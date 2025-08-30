// Given a binary array nums, you should delete one element from it.
// Return the size of the longest non-empty subarray containing only 1's in the resulting array. 
// Return 0 if there is no such subarray.

// Example 1:
// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

// Example 2:
// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

// Example 3:
// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.

#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = 0;
    map<int,int>mp;
    int maxi = -1;

    while(j < n){
        mp[nums[j]]++;
        while(mp[0] > 1 && i < j){
            mp[nums[i]]--;
            if(mp[nums[i]] == 0){
                mp.erase(nums[i]);
            }
            i++;
        } 
        maxi = max(maxi,j - i + 1);
        j++;
    }
    return maxi == -1 ? 0 : maxi - 1;
}

int main(){
    vector<int>arr = {0,1,1,1,0,1,1,0,1};
    int ans = longestSubarray(arr);
    cout<<ans;
    return 0;
}