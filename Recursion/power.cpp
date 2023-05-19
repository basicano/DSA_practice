#include<iostream>
#include<cmath>
using namespace std;


int pow(int n, int p){
	if(p==0){
		return 1;
	}
	else if(p==1){
		return n;
	}	
	else{
		return pow(n,floor(p/2.0))*pow(n,ceil(p/2.0));
	}
}

int main(){
	int n;
	cout<<"Enter the number: ";
	cin>> n;
	cout<<"Enter the power: ";
	int p;
	cin>>p;
	cout<<"Value of number raised to the power: "<<pow(n,p);
}
