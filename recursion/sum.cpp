#include<iostream>
using namespace std;

int Sum(int arr[] , int size){
    if(size == 0){
        return 0;
    }
    
    int sum = arr[0] + Sum(arr+1 , size-1);

    return sum;

}

int main(){
    int arr[] = {6,2,3,4,5};
    int size = 5;

    int sum = Sum(arr,size);

    cout<<sum<<endl;
    return 0;
}