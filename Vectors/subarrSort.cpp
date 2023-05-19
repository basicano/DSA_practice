#include<iostream>
#include<vector>
using namespace std;

bool out_of_order(vector<int> v, int idx){
	if(idx == 0){
		return v[idx]>v[idx+1];
	}
	if(idx == v.size()-1){
		return v[idx]<v[idx-1];
	}
	
	return v[idx]>v[idx+1] || v[idx]<v[idx-1];
}

pair<int,int> subarray_sort(vector<int> v){
	pair<int,int> p;
	
	int n = v.size();
	int min_rearr = INT_MAX, max_rearr = INT_MIN;
	int min_idx, max_idx;
	for(int i=0; i<n; i++){
		if(out_of_order(v,i)){
			if(v[i] < min_rearr){
				min_idx = i ;
				min_rearr = v[i];
			}
			if(v[i] > max_rearr){
				max_idx = i;
				max_rearr = v[i];
			}
		}
	}
	
	int min_pos = 0, max_pos = n-1;
	while(min_pos<n && v[min_idx]>=v[min_pos]){
		min_pos++;
	}
	p.first = min_pos;
	while(max_pos>0 && v[max_idx]<=v[max_pos]){
		max_pos--;
	}
	p.second = max_pos;
	
	return p;
}

int main(){
	vector<int> arr={1,2,3,4,5,8,6,7,9,10,11};
	pair<int,int> result=subarray_sort(arr);
	cout<<result.first<<" "<<result.second;
}
