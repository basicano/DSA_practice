#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int count_triplets(vector<int> v, int r){
	unordered_map<int,int> left, right;
//	 initialize both maps
	for(int i=0; i<v.size(); i++){
		right[v[i]]++;
        left[v[i]] = 0;
	}
	int count = 0;
	for(int i=0; i<v.size();i++){
//		let v[i] be a .. then search for a/r in left and ar in right
		right[ v[i] ]--;	
		if( left.find(v[i]/r) != left.end() && left[v[i]/r]!=0 && right.find( v[i]*r )!= right.end() && right[v[i]*r]!=0 ){
//			FORGOT TO COUNT all possible pairings
			count += left[v[i]/r]*right[v[i]*r];
		}
		left[v[i]]++;
	}
	
	return count;
}

int main() {
    
    vector<int> arr{4,2,10,4,8,20,40};

    cout<<count_triplets(arr,2);

    return 0;
}
