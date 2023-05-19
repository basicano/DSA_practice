#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printIntersection(int *a, int n, int *b, int m){	
	for(int i=0, j=0; i<n && j<m; ){
		if(a[i]==b[j]){
			cout<<a[i]<<" ";
			i++;
			j++;
		}
		else if(a[i]<b[j]){
			i++;
		}
		else{
			j++;
		}
	}
	return;
}

void print(int *arr, int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	return ;
}

int main(){
	int n, m; 
	
	cout<<" Enter the size of first array :";
	cin>>n;
	cout<<" Enter the elements of first array (sorted) :";
	int *a = new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	cout<<" Enter the size of second array : ";
	cin>>m;	
	cout<<" Enter the elements of second array (sorted) : ";
	int *b = new int[m];
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	
	cout<<" Entered arrays are =>\n Array a: ";
	print(a,n);
	cout<<endl<<" Array b: ";
	print(b,n);
	cout<<"\n Intersection of a and b: ";
	printIntersection(a, n, b, m);
	
}
