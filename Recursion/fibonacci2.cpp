#include<iostream>
using namespace std;

int fibonacciSeries(int n){
	if( n==0 || n==1||n==2){
		return 1;
	}
	else{		
		return fibonacciSeries(n-1)+fibonacciSeries(n-2)+fibonacciSeries(n-3);
	}
}



int main(){
	int n;
	cin>>n;
	cout<<"F["<<n<<"] = "<<fibonacciSeries(n);
	
}
