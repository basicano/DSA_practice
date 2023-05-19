#include<iostream>
#include<vector>
using namespace std; 

int lowerBound(vector<int> v, int key){
	int n = v.size();
	int first = 0, last = n-1;
	int mid;
	while(first<=last){
		mid = (first+last)/2;
		
		if(v[mid] == key){
			return key;
		}
		else if( key <= v[mid] ){
			last = mid-1;
		}
		else{
			first = mid+1;	
		}
	}
	
	if(mid==0){
		if(v[0]>key) return -1;
		else return v[0];
	}
	return v[mid-1];
}

//int main(){
//	vector<int> v{1,2,3,5,6,7};
//	cout<<lowerBound(v, 4);
//	return 0;
//}
