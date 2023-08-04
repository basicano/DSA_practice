#include<iostream>
#include<vector>
using namespace std;

int maxIncSubseq(vector<int> nums){
	int n = nums.size();
	vector<int> memo(n+1, 1);
	
	int max_result = 1;
	
	for(int i=1; i<n; i++){
		for(int j=i-1; j>=0; j--){
			if(nums[j]<nums[i]){
				if(memo[i]<memo[j]+1){
					memo[i] = memo[j]+1;
				}
			}
		}
		max_result = max(max_result, memo[i]);
	}
	
	for(int i=0; i<n; i++) cout<< memo[i]<<" ";
	
	return max_result;
}

int main(){
	vector<int> nums{0,1,0,3,2,3};
	cout<<maxIncSubseq(nums);
}
