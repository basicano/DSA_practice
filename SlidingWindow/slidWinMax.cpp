#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> maxInWin(vector<int> v, int k){
	int n = v.size();
	
	vector<int> result;
	
	deque<int> store_max;
	
	for(int i=0; i<k; i++){
		while(!store_max.empty() && v[i]>store_max.back()){
			store_max.pop_back();
		}
		store_max.push_back(v[i]);
	}
//	push max for window 0 to k-1
	result.push_back(store_max.front());
	
//	start next window from 1 
	int win_start = 1;
	
	for(int win_end=k; win_end<n; win_end++, win_start++){		
		// shift window by one
		while( !store_max.empty() && v[win_end]>store_max.back() ){
			store_max.pop_back();
		}
		store_max.push_back(v[win_end]);
		result.push_back(store_max.front());
		
		if(store_max.front() == v[win_start]){
			store_max.pop_front();
		}
	}
	
	return result;
}

int main(){
	vector<int> vec{1,2,3,1,4,5,2,3,5};
	for(int i=0; i< vec.size(); i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	maxInWin(vec,3);
	
	vector<int> r = maxInWin(vec,3);
	
	for(int i=0; i< r.size(); i++){
		cout<<r[i]<<" ";
	}
}
