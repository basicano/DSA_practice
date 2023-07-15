#include<iostream>
#include<vector>
using namespace std;



int helper(vector<int> v, int k,int start, int end, vector<int> &prefix){
	if(start>end) return 0;
	int max_result = INT_MIN;
	
	for(int i=0; i<=k; i++){
		int result = INT_MAX;
		for(int j=0; j<=k; j++){
//			when i picked from start and k-i picked from end => start = start+i, end = end-k+i
//			player 2 picks j coins from start and k-j coins from end
			result = prefix[start+i] - prefix[start] + prefix[end] - prefix[end-k-i]+ min(result, helper(v, k, start+i+j, end-k+i-k+j, prefix));
//			player 2 picks k-j coins from start and j coins from end
			result = prefix[start+k-j] - prefix[start] + prefix[end-j] - prefix[end-k-i] + min(result, helper(v, k, start+i+k-j, end-k+i-j, prefix));
		}
		max_result = max(max_result,result);
	}
	return max_result;
}
int gameOFGreedwKmoves(vector<int> v, int k){
	vector<int> prefix(v.size());
	prefix[0] = v[0];
	for(int i=1; i<n; i++){
		prefix[i] += prefix[i-1] + v[i];
	}
	return	helper(v, k, 0, v.size()-1, prefix);
}
int main(){
	
}
