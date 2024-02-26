#include<iostream>
using namespace std;

bool binarySearch(int arr[],int key,int start,int end){
    if(start>end){
        return false;
    }

    int mid = (start+end)/2;

    if(arr[mid] == key) return true;
    else if (arr[mid]<key) return binarySearch(arr,key,mid+1,end);

    return binarySearch(arr,key,start,mid-1);
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int key = 5;
    int size = 5;

    bool ans = binarySearch(arr,key,0,size-1);

    cout<<ans<<endl;
     return 0;
}