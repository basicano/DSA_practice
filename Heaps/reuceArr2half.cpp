#include<iostream>
#include<unordered_map>
using namespace std;

class compare{
	public:
		bool operator()(const pair<int,int> &a, const pair<int,int> &b){
			return a.second>b.second;
		}
};

int reduceArr2half(vector<int> vec){
	int n = vec.size();
	unordered_map<int, int> m;
	
	for(int i=0; i<n; i++){
		m[vec[i]]++;
	}
	
	vector< pair<int,int> > freq;
	for(auto p : m){
		freq.push_back(p);
	}
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, compare> min_heap;
	int count = 0;
	int reduction = 0;
	while(reduction<n/2){
		resuction += min_heap.top().second;
		min_heap.pop();
		count++;
	}
	
	return count;	
}

int main(){
	
}
