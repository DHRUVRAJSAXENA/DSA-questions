#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

void reverse(string& str , int start,int end){
    if(start >= end){
        return;
    }
    swap(str[start],str[end]);
    reverse(str,start+1,end-1);

}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    // Approches for reversing an array
    // approch 1 use second array of same size and paste the element in it
    
    // space complexity : O(n)
    // time complexity : O(n)

    // int arr2[10];
    // for(int i=0;i<10;i++){
    //     arr2[i] = arr[10-i-1];
    // }
    // for(int i=0;i<10;i++){
    //     cout<<arr2[i]<<" ";
    // }

    // approch 2 use two pointer approch and swap them
    
    // space complexity : O(1)
    // time complexity : O(n)
    // for(int i=0;i<10/2;i++){
    //     swap(arr[i],arr[10-i-1]);
    // }
    // for(int i=0;i<10;i++){
    //     cout<<arr[i]<<" ";
    // }

    // ?

    // approch 3 use reverse function of algorithm
    // space complexity : O(1)
    // time complexity : O(n)
    // reverse(arr,arr+10);
    // for(int i=0;i<10;i++){
    //     cout<<arr[i]<<" ";
    //     }

    // ?

    // Approches for reversing a string
    // approch 1 use second array of same size and paste the element in it
    // space complexity : O(n)
    // time complexity : O(n)
    string str = "hello";
    // string str2;
    // for(int i=0;i<str.length();i++){
    //     str2 += str[str.length()-i-1];
    // }
    // cout<<str2<<endl;

    // approch 2 use two pointer approch and swap them
    // space complexity : O(1)
    // time complexity : O(n)

    // for(int i=0;i<str.length()/2;i++){
    //     swap(str[i],str[str.length()-i-1]);
    // }
    // cout<<str<<endl;

    // approch 3 recussion
    // space complexity : O(n)
    // time complexity : O(n)
    reverse(str,0,str.length()-1);
    cout<<str<<endl;

    
    

    return 0;
}