// Given an array of positive integers nums and a positive integer target, 
// return the minimal length of a subarray whose sum is greater than or equal to target. 
// If there is no such subarray, return 0 instead.


// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0
 
#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    int j = 0;
    int sum = 0;
    int mini = INT_MAX;

    while(j < n){
        sum += arr[j];

        while(sum >= target && i <= j){
            mini = min(mini,j - i + 1);
            sum -= arr[i];
            i++;
        }

        j++;
    }
    return mini == INT_MAX ? 0 : mini;
}

int main(){
    vector<int>arr = {1,4,4};
    int target = 4;
    int ans = minSubArrayLen(target,arr);
    cout<<ans;
    return 0;
}
