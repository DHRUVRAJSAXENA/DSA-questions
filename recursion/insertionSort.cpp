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
   

   insertionSort(arr,n-1);
}

int main(){
    int arr[5] = {5,4,3,2,1};
    int size = 5;

    insertionSort(arr,size);

    print(arr,size);
    
    return 0;
}