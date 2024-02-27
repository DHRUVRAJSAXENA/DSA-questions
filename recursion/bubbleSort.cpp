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
   if(n == 0 || n == 1) return;

   for(int i=0;i<n-1;i++){
    if(arr[i] > arr[i+1]){
        swap(arr[i],arr[i+1]);
    }

   }

   bubbleSort(arr,n-1);
}

int main(){
    int arr[5] = {5,4,3,2,1};
    int size = 5;

    bubbleSort(arr,size);

    print(arr,size);
    
    return 0;
}