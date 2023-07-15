#include<iostream>
#include<vector>
#include<queue>

using namespace std; 

int minAddCost(vector<int> ropes){
	int n = ropes.size();
	
	priority_queue<int, vector<int>, greater<int> > pq(ropes.begin(), ropes.end());
	
	int max_result = 0;
	while(!pq.empty()){
		int result = pq.top();
		pq.pop();
		if(!pq.empty()){
			result += pq.top();
			pq.pop();
			pq.push(result);
			max_result += result;
		} 
		else{
			return max_result;
		}
		
	}
	
}

int main(){
	vector<int> vec{4,3,2,6};
	cout<<minAddCost(vec);
}

