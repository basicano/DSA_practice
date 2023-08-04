#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(INT_MAX);
        vector< vector<int>  > memo(n+1, vector<int> (n+1, -1));

        int r = helper(nums, memo, n-1, n);  
        return r;  
    }

    int helper(vector<int> &nums, vector<vector<int>> &memo, int n, int highest_idx){
        if( n<0 ){
            return 0;
        }
        // cout<<nums[n]<<" ";
        if(memo[n][highest_idx] != -1) return memo[n][highest_idx];

        int pick = INT_MIN, skip = INT_MIN;

        if(nums[n]<nums[highest_idx]){
            pick = helper(nums, memo, n-1, n) +1;
        }
        
        skip = helper(nums, memo, n-1, highest_idx);
        memo[n][highest_idx] = max(pick, skip);

        return memo[n][highest_idx];
    }
};
