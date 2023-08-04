#include<iostream>
#include<vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int n = nums.size();
	int sum = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
    }

    if(sum%2==1) return false;

    int half_sum = sum/2;

    vector<vector<bool>> memo(n, vector<bool> (sum+1,false));
    memo[0][nums[0]] = true;
    for(int i=1; i<n; i++){
        // for each nums element (memo[i]) calculate the possible sums i.e. possible sums if nums[i] is included in subset 1 or included in subset 2
        for(int j=0; j<=sum; j++){
            if(memo[i-1][j]==true){
                memo[i][j] = true;
                memo[i][j+nums[i]] = true;
            }
        }
    }

    return memo[n-1][half_sum];
}

int main(){
	
}
