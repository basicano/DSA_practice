#include<iostream>
using namespace std;

// try making a recursion tree
// path from root to leaf is one method

int getNoOfWaysToTile(int num){
	if(num<0){
		return 0;
	}
	else if(num==1||num==0){
		return 1;
	}
	else{
		return getNoOfWaysToTile(num-1)+getNoOfWaysToTile(num-2);
	}
}


int main(){
	int n;
	cout<<"Enter the value of n for the 2Xn matrix: ";
	cin>>n;
	cout<<getNoOfWaysToTile(n);
	
	
}
