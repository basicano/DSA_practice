#include<iostream>
#include<vector>
using namespace std;

int maxNonAdjSum(vector<int> nums, int n, vector<int> &dp){
	if(n==0) return nums[0];
	if(n<0) return 0;
	if(dp[n]!= INT_MIN) return dp[n];
	
	int pick=INT_MIN, skip=INT_MIN;
	pick = nums[n] + maxNonAdjSum(nums,n-2,dp);
	skip = maxNonAdjSum(nums,n-1,dp);
	dp[n] = max(pick, skip);
	return dp[n];
}

int main(){
	vector<int> nums{6,10,12,7,9,14};
	vector<int> dp(6, INT_MIN);
	cout<<maxNonAdjSum(nums, 5, dp);
}
