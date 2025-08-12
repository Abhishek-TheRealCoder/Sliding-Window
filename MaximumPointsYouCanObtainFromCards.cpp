// There are several cards arranged in a row, and each card has an associated number of points. 
// The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
// Output: 12

// Input: cardPoints = [9,7,7,9,7,7,9], k = 7
// Output: 55

#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int lsum , rsum = 0;
    int n = cardPoints.size();
    
    for(int i = 0;i < k;i++){
        lsum += cardPoints[i];
    }
    for(int i = n-k; i < n ;i++){
        rsum += cardPoints[i];
    }

    if(n == k){
        return lsum;
    }
    int maxi = 0;
    if(rsum > lsum){
        int i = 0;
        int j = n - k;
        maxi = rsum;
        while(j < n - 1 && i < k-1){
            rsum -= cardPoints[j];
            j++;
            rsum += cardPoints[i];
            i++;
            maxi = max(maxi , rsum);
        }
    }else{
        int i = k - 1;
        int j = n - 1;
        maxi = lsum;
        while(j > n - k  && i > 0){
            lsum -= cardPoints[i];
            i--;
            lsum += cardPoints[j];
            j--;
            maxi = max(maxi,lsum);
        }
    }
    return maxi;
}

int main(){
    vector<int>a = {1,2,3,4,5,6,1};
    int  k = 3;
    int ans = maxScore(a , k);
    cout<<ans;
    return 0;
}