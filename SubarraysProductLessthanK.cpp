// Given an array of positive numbers, the task is to find the number of possible contiguous subarrays 
// having product less than a given number k.

// Input:
// n = 4, k = 10
// a[] = [1, 2, 3, 4]
// Output : 
// 7

// Input:
// n = 7 , k = 100
// a[] = [1, 9, 2, 8, 6, 4, 3]
// Output:
// 16

// Input:
// n = 3 ,k = 1
// a[] = [1,1,1]
// Output:
// 0

#include<bits/stdc++.h>
using namespace std;

long long countSubArrayProductLessThanK(const vector<int>& arr, int k){
    int n = arr.size();
    int i = 0;
    int j = 0;
    long long prod = 1;
    long long count = 0;

    while(j < n){
        prod *= arr[j];

        while(prod >= k && i <= j){
            prod /= arr[i];
            i++;
        }

        if(prod < k){
            count += j - i + 1;
        }
        j++;
    }
    return count;
}

int main(){
    vector<int>a = {1, 9, 2, 8, 6, 4, 3};
    int k = 100;
    int ans = countSubArrayProductLessThanK(a , k);
    cout<<ans;
    return 0;
}