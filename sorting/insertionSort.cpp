#include<iostream>
using namespace std;

void print(int *arr,int size){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void insertionSort(int *arr, int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

int main(){
    int arr[5] = {5,4,3,2,1};
    int size = 5;

    insertionSort(arr,size);

    print(arr,size);
    
    return 0;
}