#include<iostream>
using namespace std;

void print(int *arr,int size){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void bubbleSort(int *arr, int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[5] = {5,4,3,2,1};
    int size = 5;

    bubbleSort(arr,size);

    print(arr,size);
    
    return 0;
}