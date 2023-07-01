#include<iostream>
#include<vector>
using namespace std;


void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if(n<=1) return;

    int min_afterbk = INT_MAX, min_afterbk_idx;
    int bk_idx = 0;

    // finding the break point
    for(int i=n-1; i>0; i--){
        if(nums[i-1]<nums[i]){
            bk_idx = i;
            break;
        } 
        
    }

    // swap the dip number with the smaller no. in right that is larger than dip
    if(bk_idx > 0){ 
        for(int i=n-1; i>=bk_idx; i--){
            if(nums[i]>nums[bk_idx-1] && nums[i]<min_afterbk){
                min_afterbk_idx = i;
                min_afterbk = nums[i];
            }
        }
        swap(nums[bk_idx-1], nums[min_afterbk_idx]);
    }
    // if bk_idx == 0 then entire nums in decreasing order

    for(int i=0; i<n; i++){
        cout<<nums[i];
    }

    // since dip is smaller than prev, after swap nums right is still sorted in decending order: reverse it to bring in ascending order
    int mid = (n-1+bk_idx)/2;
    for(int i=bk_idx, c=0; i<=mid; i++, c++){
        swap(nums[i],nums[n-c-1]);
    }

    return;
}

int main(){
	vector<int> v{1,2,5,3,2};
//	cases : [2,3,1] [2,3,1,3,3] [2,1,2,2,2,2,2,1]
//  remember to find min_afterbk_idx from last and nums[i]>nums[bk_idx-1] condition

}
