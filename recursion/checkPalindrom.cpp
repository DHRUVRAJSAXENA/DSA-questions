#include<iostream>
using namespace std;

bool pal(string str,int start,int end){
    if(start >= end) return true;

    if(str[start] != str[end]) return false;

    bool ans = pal(str , start + 1, end - 1);

    return ans;
}

int main(){
    
    string str = "dhruvvurhd";
    int n = str.length() - 1;

    bool ans = pal(str,0,n);

    cout<<ans<<endl;

    return 0;
}