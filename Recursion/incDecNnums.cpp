#include<iostream>
using namespace std;

void printNinc(int n){
	if(n==0){
		return;
	}
	
	printNinc(n-1);
	// printing after returning from the base case
	cout<<n<<" ";
}

void printNdec(int n){
	if(n==0){
		return;
	}
//	printing before going towards the base case
	cout<<n<<" ";	
	printNdec(n-1);

}

int main(){
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<<" Numbers in increasing order are: ";
	printNinc(n);
	cout<<"\n";
	cout<<" Numbers in decreasing order are: ";
	printNdec(n);
}
