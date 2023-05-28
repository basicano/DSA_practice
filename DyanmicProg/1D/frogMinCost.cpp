#include<iostream>
#include<vector>
using namespace std;

// RECURSIVE w/o DP
int frogMinCost(vector<int> heights, int n){
	if(n==0){
		return 0;
	}
	int pillar1 = INT_MAX;
	if(n-1 >= 0) pillar1 = frogMinCost(heights, n-1) +  abs(heights[n]-heights[n-1]);
	int pillar2 = INT_MAX;
	if(n-2 >= 0) pillar2 = frogMinCost(heights, n-2) +  abs(heights[n]-heights[n-2]);
//	cout<<pillar1<<" "<<pillar2<<endl;
	return min(pillar1, pillar2);
}

// TOP DOWN DP
int frogMinCostTD(vector<int> heights, int n, vector<int> &dp){
	if(n==0){
		return 0;
	}
	if(dp[n] != INT_MAX) return dp[n];
	int pillar1 = INT_MAX,pillar2 = INT_MAX;
	if(n-1 >= 0) pillar1 = frogMinCostTD(heights, n-1,dp) +  abs(heights[n]-heights[n-1]);
	if(n-2 >= 0) pillar2 = frogMinCostTD(heights, n-2,dp) +  abs(heights[n]-heights[n-2]);
	
	dp[n] = min(pillar1, pillar2);
	return dp[n];
}

//  BOTTOM UP DP
int frogMinCostBU(vector<int> heights, int n){
	vector<int> dp(n+1,INT_MAX);
	dp[0] = 0;
	for(int i=1; i<=n; i++){
		int pillar1 = dp[i-1] +abs(heights[i]-heights[i-1] );
		int pillar2 = INT_MAX;
		if(i-2 >= 0) pillar2 = dp[i-2] +  abs(heights[i]-heights[i-2]);
		dp[i] = min(pillar1, pillar2);
	}
	
	return dp[n];
}


int main(){
	int n_pillars = 6;
	vector<int> heights{30,10,60,10,60,50};
//	cout<<frogMinCost(heights, 5);
	vector<int> dp(n_pillars+1,INT_MAX);
//	cout<<frogMinCostTD(heights, 5, dp);
	cout<<frogMinCostBU(heights, 5);
	
}
