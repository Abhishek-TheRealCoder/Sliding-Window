// Given an array of integers arr[]  and a number k. Return the maximum xor of a subarray of size k.

// Note: A subarray is a contiguous part of any given array.
// [2, 5, 8, 1, 1, 3] , k = 3
// output = 15

#include<bits/stdc++.h>
using namespace std;


int maximumXorSubarray(vector<int>& arr, int k) {
    // code here
    int n = arr.size();
    int i = 0;
    int j = 0;
    int x = 0;
    int maxi = INT_MIN;
    
    while(j < n){
        x ^= arr[j];
        
        while(j - i + 1 > k){
            x ^= arr[i];
            i++;
        }
        
        if(j - i + 1 == k){
            maxi = max(maxi,x);
        }
        j++;
    }
    return maxi;
    
}
int main(){
    vector<int>a = {2, 5, 8, 1, 1, 3};
    int k = 3;
    int ans = maximumXorSubarray(a,k);
    cout<<ans;
    return 0;
}