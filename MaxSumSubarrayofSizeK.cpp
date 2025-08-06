// Given an array of integers arr[] and a number k. Return the maximum sum of a subarray of size k
// Input: arr[] = [100, 200, 300, 400] , k = 2
// Output: 700

// Input: arr[] = [100, 200, 300, 400] , k = 4
// Output: 1000

#include<bits/stdc++.h>
using namespace std;

int maximumSumSubarray(vector<int>&arr,int k){
    int n = arr.size();
    int i = 0;
    int j = 0;
    int maxi = 0;
    int sum = 0;
    while(j < n){
        sum += arr[j];

        while(j - i + 1 > k && i < j){
            sum -= arr[i];
            i++;
        }
        
        if(j - i + 1 >= k){
            maxi = max(maxi,sum);
        }
        ++j;
    }
    return maxi;

}

int main(){
    vector<int>arr={100, 200, 300, 400};
    int k = 2;
    int ans = maximumSumSubarray(arr,k);
    cout<<ans;
    return 0;
}