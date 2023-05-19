#include<iostream>
using namespace std;

//int fib(int n){
//	if(n==1){
//		return 0;
//	}
//	if(n==2){
//		return 1;
//	}
//	return fib(n-1)+fib(n-2);
//}
//
//int getNoOfBinaryStrings(int n){
//	if(n<=0){
//		return 0;
//	}
//	else if(n==1){
//		return 2;
//	}
//	else{
////		we have two choice for bit n either 0 or 1
////		for choice 1 the next choice has to be zero 			 getNoOfBinaryStrings(n-1)/2
////		for choice 2 the next choice can be both zero or one	 getNoOfBinaryStrings(n-1)		
//		return 2*getNoOfBinaryStrings(n-1) - fib(n);
//	}
//}


int getNoOfBinaryStrings(int n){
	if(n==1){
		return 2;
	}
	else if(n==2){
		return 2;
	}
	else{		
		return getNoOfBinaryStrings(n-1) + getNoOfBinaryStrings(n-1) ;
	}
}

int main(){
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<<"All possible distinct binary strings of length N such that there are no consecutive 1s :";
	cout<<getNoOfBinaryStrings(n);
}
