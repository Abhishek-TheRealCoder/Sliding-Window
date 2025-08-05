// Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray 
// (a contiguous sequence of elements) whose sum equals a specified value target. 
// You need to return the 1-based indices of the leftmost and rightmost elements of this subarray.
// You need to find the first subarray whose sum is equal to the target.
// Note: If no such array is possible then, return [-1,-1].
// Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], target = 15
// Output: [1, 5]
// Explanation: The sum of elements from 1st to 5th position is 15.
#include<bits/stdc++.h>
using namespace std;

vector<int>subArraySum(vector<int>&arr,int n){
    
}

int main(){
    vector<int>arr={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = arr.size();
    int target = 15;
    vector<int>ans = subArraySum(arr,n);
    cout<<ans[0]<<" "<<ans[1];
}
