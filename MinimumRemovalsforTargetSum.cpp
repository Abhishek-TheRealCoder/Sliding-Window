// You are given an array of positive integers arr[] and an integer k. 
// In one operation, you can remove either the leftmost or the rightmost element from the array. 
// After each operation, the size of arr[] will be reduced by one.
// Your have to determine the minimum number of operations required to make the total sum of removed elements exactly equal to k. 
// If it is not possible to achieve this, return -1.

// Examples:

// Input: arr[] = [3, 4, 1, 3, 2], k = 5
// Output: 2
// Explanation: Removing 3 from left and 2 from right gives a sum of 5 in 2 operations.
// Input: arr[] = [5, 3, 4, 6, 2], k = 6
// Output: -1
// Explanation: It is impossible to achieve the sum of removed elements as 6.
// Input: arr[] = [1, 1, 3, 1, 2], k = 4
// Output: 3
// Explanation: Removing 1, 1 from left and 2 from right gives a sum of 4 in 3 operation.

// sol) Calculate totalsum of the array then subtract it with k to get a target value
// now question becomes calculate maxlength of subarray that sums to target

#include<bits/stdc++.h>
#include<numeric>
using namespace std;


int minRemovals(vector<int> &arr, int k) {
    int n = arr.size();
    int total = accumulate(arr.begin(),arr.end(),0);

    int target = total - k;
//question becomes calculate maxlen of subarray that sums to target
    int i = 0;
    int j = 0;
    int maxi = INT_MIN;
    int sum = 0;
    while(j < n){
        sum += arr[j];
        while(sum > target && i < j){
            sum -= arr[i];
            i++;
        }

        if(sum == target){
            maxi = max(maxi, j - i + 1);
        }
        j++;
    }
    return maxi == INT_MIN ? -1 : n - maxi;
}
int main(){
    vector<int>a = {3, 4, 1, 3, 2};
    int k = 5;
    int ans = minRemovals(a,k);
    cout<<ans;
    return 0;
}
