#include<iostream>
using namespace std;

int main(){
	
	int n;
	cout<<" Enter the number of rows: ";
	cin>>n;
	int **arr = new int*[n];
	
	int m;
	for(int i=0; i<n; i++){
		cout<<" Enter the number of cols for row "<<i+1<<": ";
		cin>>m;
		arr[i] = new int[m+1];
		arr[i][0] = m;
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<arr[i][0];j++){
			cout<<i+j<<" ";
		}
		cout<<"\n";
	}
		
}
