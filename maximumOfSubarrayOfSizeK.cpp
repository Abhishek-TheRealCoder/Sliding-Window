// Given an array arr[] of positive integers and an integer k.
// You hvae to find the maximum value for each contiguous subarray of size k. 
// The output should be an array of maximum values corresponding to each contiguous subarray.
// Input: arr[] = [8, 5, 10, 7, 9, 4, 15, 12], k = 4
// Output: [10, 10, 10, 15, 15]

// Input: arr[] = [33,38,46,24,26,6,42,28], k = 2
// Output: [38,46,46,26,26,42,42]

// Input: arr[] = [45,8,12,7], k = 2
// Output: [45,12,12]

#include<bits/stdc++.h>
using namespace std;

vector<int>maxOfSubarrays(vector<int>&arr,int n,int k){

    deque<int>dq;
    vector<int>res;
    int count = 0;
    for(int i = 0;i < n;i++){

        while(!dq.empty() && i - dq.front() >= k){
            dq.pop_front();
        }

        while(!dq.empty() && arr[i] > arr[dq.back()]){
            dq.pop_back();
        }

        dq.push_back(i);
        count++;

        if(count >= k){
            res.emplace_back(arr[dq.front()]);
        }
    }
    return res;
}

int main(){
    vector<int>arr = {33,38,46,24,26,6,42,28};
    int k = 2;
    int n = arr.size();
    vector<int>ans = maxOfSubarrays(arr,n,k);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}

