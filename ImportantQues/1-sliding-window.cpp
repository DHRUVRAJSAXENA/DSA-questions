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

int lengthOfLongestSubstring(string s){
    int l=0, r=0, maxLen = 0, SIZE=256;
    int hash[SIZE];
    fill(hash,hash+SIZE,-1);

    while(r<s.size()){
        if(hash[s[r]] != -1){
            if(hash[s[r]] >= l){
                l = hash[s[r]] + 1;
            }
        }

        int len = r - l +1;
        maxLen = max(maxLen , len);

        hash[s[r]] = r;
        r++;
    }

    return maxLen;

}




int main(){
    // int size = 7;
    // int arr[size] = {1,2,3,4,5,6,1};

    // int maxPoints = maxPoint(arr,3,size);
    // cout<<endl<<maxPoints<<" are the max points"<<endl;

    string s = "abcabcbb";
    cout<<endl<<lengthOfLongestSubstring(s)<<endl;
    
    return 0;
}