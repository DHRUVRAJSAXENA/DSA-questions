#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// maximum points from cards

int maxPoint(int arr[] , int k , int size){
    int lsum = 0 , rsum = 0 , maxSum = 0, rIndex = size - 1;

    for(int i=0;i<k;i++){
        lsum += arr[i];
    }  
    maxSum = lsum;

    for(int i = k-1; i>=0;i--){
        lsum = lsum - arr[i];
        rsum = rsum + arr[rIndex];
        rIndex--;

        maxSum = max(maxSum , lsum+rsum);
    }

    return maxSum;

}

// longest substring without repeating




int main(){
    int size = 7;
    int arr[size] = {1,2,3,4,5,6,1};

    int maxPoints = maxPoint(arr,3,size);
    cout<<endl<<maxPoints<<" are the max points"<<endl;
    
    return 0;
}