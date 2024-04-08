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
  

   selectionSort(arr,n-1);
}

int main(){
    int arr[5] = {5,4,3,2,1};
    int size = 5;

    selectionSort(arr,size);

    print(arr,size);
    
    return 0;
}
