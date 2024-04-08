#include<iostream>
using namespace std;

bool linearSearch(int arr[],int key,int size){
    if(size == 0){
        return false;
    }

    if(arr[0] == key){
        return true;
    }
    else{
        return linearSearch(arr+1,key,size-1);
    }

    
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int key = 8;
    int size = 5;

    bool ans = linearSearch(arr,key,size);

    cout<<ans<<endl;
     return 0;
}