int countDigits(int n){
	// Write your code here.
	int count = 0;
	int nn = n;
	while(n!=0){
		int num = n%10;
		if(num !=0 && nn%num ==0) count++;
		n = n/10;
	}	
	return count;
}