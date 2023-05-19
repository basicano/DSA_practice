#include<iostream>
using namespace std;

int palindrome(string num, int n){
	if(n==1||n==0){
		return 1;
	}
	else{
		if(num[0]==num[n-1]){
			num = num.substr(1,n-2);
			return palindrome(num, n-2);
		}
		else{
			return 0;
		}
	}
	
}

int main(){
	string n;
	cout<<"Enter the number :";
	cin>>n;
	
	if(palindrome( n, n.length())){
		cout<<"Palindrome";
	}
	else{
		cout<<"Not Palindrome";
	}
	
}
