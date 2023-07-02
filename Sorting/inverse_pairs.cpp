#include <iostream>
#include<vector>
using namespace std; 

// DECLARE functions at the very start

int count_inv(vector<int> &nums, int start, int mid, int end){
    int first_half_idx = 0;
    int second_half_idx = mid+1;
    int inv_count = 0;
    vector<int> temp(nums);
    int c=0;

    while(first_half_idx<=mid && second_half_idx<=end){
        if(temp[first_half_idx]<=temp[second_half_idx]){
            nums[c++] = temp[first_half_idx++];
        }
        else{
            nums[c++] = temp[second_half_idx++];
            inv_count += mid-first_half_idx+1;
        }
    }

    while(first_half_idx<=mid){
        nums[c++] = temp[first_half_idx++];
    }

    while(second_half_idx<=mid){
        nums[c++] = temp[second_half_idx++];
    }

    return  inv_count;
}


int helper(vector<int> &nums, int start, int end){
    if(start >= end) return 0;
    int mid = (start+end)/2;

    int sub_p1 = helper(nums, start, mid);
    int sub_p2 = helper(nums, mid+1, end);
    return sub_p1+ sub_p2+ count_inv(nums, start, mid, end);
}


int inversePairs(vector<int>& nums) {
    vector<int> v(nums);
    int n= nums.size();
    return helper(v, 0, n-1);
}

int main(){
	vector<int> nums{1,2,4,5,3};
	
	cout<<" "<<inversePairs(nums);
}





