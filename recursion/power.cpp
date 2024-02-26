#include<iostream>
using namespace std;

int power(int a,int b){
    if(b==0) return 1;
    if(b==1) return a;

    int ans = power(a,b/2);

    if(b%2 == 0) return ans * ans;
    else if(b%2 == 1) return a*ans*ans;

    return ans;
}

int main(){
    int a=8;
    int b=7;

    int ans = power(a,b);

    cout<<ans<<endl;
    return 0;
}