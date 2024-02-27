#include<iostream>
using namespace std;

void print(int *arr,int size){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void selectionSort(int *arr, int n){
    for(int i=0;i<n;i++){
        int mini = i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[mini]) mini = j;
        }
        swap(arr[mini] , arr[i]);
    }
}

int main(){
    int arr[5] = {5,4,3,2,1};
    int size = 5;

    selectionSort(arr,size);

    print(arr,size);
    
    return 0;
}