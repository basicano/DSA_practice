#include<iostream>
#include<vector>
using namespace std;

// TOP DOWN DP
int longIncSubseq(vector<int> nums, int n, vector<int> dp, int highest=INT_MAX){
	if(n<0) return 0;
	if(dp[n]!=INT_MIN) return dp[n];
	
	int pick =INT_MIN, skip=INT_MIN;
	if(nums[n]<highest){
		pick = 1 + longIncSubseq(nums, n-1, dp, nums[n]);
	}
	skip = longIncSubseq(nums, n-1, dp, highest);
	dp[n] = max(pick, skip);
	return dp[n]; 	
}

int main(){
	vector<int> arr{50,4,10,8,30,100};
	vector<int> dp(7,INT_MIN);
	cout<<longIncSubseq(arr,5,dp)<<endl;
	return 0;
}
