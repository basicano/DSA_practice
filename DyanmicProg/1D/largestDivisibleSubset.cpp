#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:
    // BRUTE FORCE : find all subsets and select eh largest subset such that all elements divide each other (time: 2^n *n)

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> largest_memo(n+1, 1);
        vector<int> parent_memo(n+1, -1);

        int max_len = 1, max_idx = 0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 || nums[j]%nums[i]==0){
                    if(largest_memo[i]<largest_memo[j]+1){
                        largest_memo[i] = largest_memo[j]+1;
                        parent_memo[i] = j;
                    }
                }
            }

            if(max_len < largest_memo[i]){
                max_idx = i;
                max_len = largest_memo[i];
            }
        }

        for(int i=0; i<n; i++){
            cout<<largest_memo[i]<<" ";
        }

        cout<<endl;

        for(int i=0; i<n; i++){
            cout<<parent_memo[i]<<" ";
        }

        cout<<endl;

        vector<int> result;
        int i = max_idx;
        while(i>=0){
            result.insert(result.begin(),nums[i]);
            i = parent_memo[i]; 
        } 
        return result;
    }

};

int main(){
	
}
