#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int helper(int n, int i, int j, int start, int end, vector<int> &cuts, vector<vector<int>> &dp){
    if(j<i) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int min_cost = INT_MAX;
    for(int k=i; k<=j; k++){
        int result_before = helper(n, i, k-1, start, cuts[k], cuts, dp);
        int result_after = helper(n, k+1, j, cuts[k], end, cuts, dp);
        min_cost = min(min_cost, end-start +result_after+result_before );
    } 
    dp[i][j] = (min_cost==INT_MAX)? 0:min_cost;
    return dp[i][j];
}

int minCost(int n, vector<int>& cuts) {
//	INTIALISING A 2D ARRAY
    vector<vector<int>> dp(cuts.size() + 2, vector<int>(cuts.size() + 2, -1));
    
    sort(cuts.begin(), cuts.end());
    int r =  helper(n, 0, cuts.size()-1, 0, n, cuts, dp);
    return r;
}

int main(){
	
}
