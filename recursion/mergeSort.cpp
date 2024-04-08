#include<iostream>
using namespace std;

void print(int *arr,int size){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void merge(int *arr, int start, int end){
    int mid = (start+end)/2;

    int len1 = mid - start +1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainIndex = start;

    for(int i=0;i<len1;i++){
        first[i] = arr[mainIndex++];
    }

    mainIndex = mid + 1;

    for(int i=0;i<len2;i++){
        second[i] = arr[mainIndex++];
    }

    // merge array
    int index1 = 0;
    int index2 = 0;
    mainIndex = start;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainIndex++] = first[index1++];
        }
        else {
            arr[mainIndex++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[mainIndex++] = first[index1++];
    }

    while(index2 < len2){
        arr[mainIndex++] = second[index2++];
    }

    delete []first;
    delete[]second;
}

void mergeSort(int *arr,int start,int end){
    if(start >= end) return;

    int mid = (start + end)/2;

    mergeSort(arr , start , mid);

    mergeSort(arr, mid+1,end);

    merge(arr,start,end);
}


int main(){
    int arr[8] = {8,6,7,2,9,4,55,33};
    int size = 8;

    mergeSort(arr,0,size-1);

    print(arr,size);
    
    return 0;
}
