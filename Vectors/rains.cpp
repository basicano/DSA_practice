#include<iostream>
#include<vector>
using namespace std;

int rains(vector<int> v){
	vector<int> max_h_lr;
	vector<int> max_h_rl;
	
	int n = v.size();
	int max = INT_MIN;
	for(int i=0; i<n; i++){
		if(v[i]>max){
			max = v[i];
		}
		max_h_lr.push_back(max);
	}
	
	max = INT_MIN;
	for(int i=n-1; i>=0; i--){
		if(v[i]>max){
			max = v[i];
		}
		max_h_rl.insert(max_h_rl.begin(), max);
	}
	
	int tot_water = 0;
	
	for(int i=0; i<n ; i++){
		int wat_cur = min(max_h_rl[i],max_h_lr[i])-v[i];
		if(wat_cur>0){
			tot_water += wat_cur;
		}
	}
	
	return tot_water;
}

int main(){
	vector<int> arr={0,1,0,2,1,0,1,3,2,1,2,1};
	cout<<rains(arr);
}
