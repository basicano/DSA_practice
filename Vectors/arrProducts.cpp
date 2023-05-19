#include<iostream>
#include<vector>
using namespace std;

vector<int> arrProducts(vector<int> v){
	int n = v.size();	
	vector<int> result(n,1);
	for(int i=1;i<n; i++){
		result[i] = v[i-1]*result[i-1];
	}
	
	int prod = v[n-1];
	for(int i = n-2; i>=0; i--){
		result[i] *= prod;
		prod *= v[i];
	}
	
	return result;
}

int main(){
	vector<int> v{1,2,3,4,5};
	vector<int> result = arrProducts(v);
	for(int i=0; i<5; i++){
		cout<<result[i]<<" ";
	}
}
