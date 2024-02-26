#include <bits/stdc++.h> 

void reverse(string &str,int start,int end){
	if(start>=end) return;

	swap(str[start], str[end]);

	reverse(str,start+1 ,end-1);
}

string reverseString(string str)
{
	// Write your code here.
	reverse(str,0,str.length() - 1);

	return str;

}