#include<bits/stdc++.h>
#include<cmath>
using namespace std;


int is_prime(int n) {
    // implement your code here
    float x = sqrt(n);
    // cout<<x<<endl;
    for(int i=2; i<x; i++){
        if(n%i==0){
            return 1;
        }
    }
    return 0;
}

int main(){
	int N;
	int ch;
	do{
		cout<<"Enter number :";
		cin>>N;
		if(is_prime(N) ){
			cout<<"Not Prime"<<endl;
		}
		else{
			cout<<" Prime"<<endl;
		}
		cout<<"Do you want to enter number again? (1/0) :";
		cin>>ch;	
	}while (ch);
	
}
