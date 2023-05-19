#include<iostream>
#include<vector>
using namespace std;

int maxSubarrSum(vector<int> v){
	int n = v.size();
	int cur_sum = 0;
	int max_sum = INT_MIN;
	
	for(int i=0; i<n ;i++){
		if(cur_sum+v[i]<=0){
			cur_sum = 0;
		}
		else{
			cur_sum += v[i];
			if(cur_sum>max_sum){
				max_sum = cur_sum;
			}
		}
	}
	return max_sum;
}

int main(){
	vector<int> v{-1,2,3,4,-2,6,-8,3};
	cout<<maxSubarrSum(v);
}
