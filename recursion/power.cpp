#include<iostream>
using namespace std;

int power(int a,int b){
    if(b==1) return a;

    int ans = a * power(a,b-1);

    return ans;
}

int main(){
    int a=5;
    int b=2;

    int ans = power(a,b);

    cout<<ans<<endl;
    return 0;
}