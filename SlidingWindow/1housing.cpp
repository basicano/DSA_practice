#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int> > housing(vector<int> v, int k){
	int n = v.size();
	vector< pair<int,int> > result;
//	unordered_map<int,int> uo_map;
	int cur_sum;		// sum of the current window
	int i=0;
	for(int j=0; j<n; j++){
//		 expand
		cur_sum += v[j];
		
		if(cur_sum >k){
//			 contract
			while(i<=j && cur_sum > k){
				cur_sum -= v[i];
				i++;
			}
		}
		
		if(cur_sum == k){
			result.push_back({i,j});
		}		
	}
	return result;
}

int main(){
	vector<int> v{1,3,2,1,4,1,3,2,1,1,2};
	vector< pair<int,int> > result = housing(v, 8);
	for(int i=0 ;i<result.size(); i++){
		cout<<result[i].first<<","<<result[i].second<<endl;
	}
}
