#include<iostream>
#include<vector>
using namespace std;

int upperBound(vector<int> v, int key){
	int n = v.size();
	if(key > v[n-1]){
		return -1;
	}
	if(key == v[n-1]){
		return v[n-1];
	}
	
	int first = 0, last = n-1;
	int mid;
	
	while(first<last){
		mid = (first+last)/2;
//		cout<<mid<<" ";
		if(v[mid] == key) return v[mid];
		else if( key >= v[mid] ){
			first = mid+1;
		}
		else{
			last = mid;
		}
	}
	
	if(mid==n-1) return v[mid];
	else return v[last];
}

//int main(){
//	vector<int> v{1,2,3,5,6,7};
//	cout<<upperBound(v, 4);
//	return 0;
//}
