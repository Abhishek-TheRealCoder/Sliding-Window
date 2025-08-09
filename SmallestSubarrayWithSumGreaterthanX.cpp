// Given a number x and an array of integers arr, find the smallest subarray with sum greater than the given value.
// If such a subarray do not exist return 0 in that case.

// Input: x = 51, arr[] = [1, 4, 45, 6, 0, 19]
// Output: 3

// Input: x = 100, arr[] = [1, 10, 5, 2, 7]
// Output: 0

#include<bits/stdc++.h>
using namespace std;

int smallestSubWithSum(int x, vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    int j = 0;
    int sum = 0;
    int mini = INT_MAX;

    while(j < n){
        sum += arr[j];

        if(arr[j] >= x) return 1;
        
        while(sum > x && i < j){
            mini = min(mini , j - i + 1);
            sum -= arr[i];
            i++;
        }
        j++;
    }
    if(mini == INT_MAX) return 0;
    return mini;
}

int main(){
    vector<int>arr = {1, 4, 45, 6, 0, 19};
    int x = 51;
    int ans = smallestSubWithSum(x,arr);
    cout<<ans;
    return 0;
}