#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
	return a.first < b.first;
}

int minSwaps(vector<int> v){
	int n = v.size();
	
	vector<pair<int,int> >  temp(n);
	
	for(int i=0; i<n; i++){
		temp[i] = {v[i], i};
	}
	
	sort(temp.begin(), temp.end(), compare);
	
	int min_swaps = 0;
	vector<bool> visited(n,false);
	
	for(int i = 0; i<n ;i++){
		if(!visited[i]){
			visited[i] = true;
			
			int next_visit = temp[i].second;
			while(!visited[next_visit]){
				min_swaps++;
				visited[next_visit] = true;
//				 update the condition variable : INFINITE LOOP !!!
				next_visit = temp[next_visit].second;
			}
		}
	}
	
	
	return min_swaps;
	
}

int main(){
	vector<int> arr={10,11,5,4,3,2,1};
	cout<<minSwaps(arr);
}
