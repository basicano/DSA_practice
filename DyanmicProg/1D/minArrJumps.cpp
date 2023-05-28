#include<iostream>
#include<vector>
using namespace std; 

// RECURSIVE w/o DP
int min_jumps(vector<int> arr,int n, int cur_step=0){
	if(cur_step==n) return 0;
	
	int jumps_i = INT_MAX;
	for(int i=1; i<=arr[cur_step]; i++){
		if(cur_step+i<=n) jumps_i = min(jumps_i, min_jumps(arr,n, cur_step+i)+1);
	}		
	return jumps_i;
}

// TOP DOWN DP
int min_jumpsTD(vector<int> arr,int n, vector<int> &dp,int cur_step=0){
	if(cur_step==n) return dp[cur_step] = 0;
	if(dp[cur_step] != INT_MAX) return dp[cur_step];
	
	for(int i=1; i<=arr[cur_step]; i++){
		if(cur_step+i<=n) dp[cur_step] = min(dp[cur_step], min_jumps(arr,n, cur_step+i)+1);
	}		
	return dp[cur_step];
}


// BOTTOM UP DP
int min_jumpsBU(vector<int> arr,int n,int cur_step=0){
	vector<int> dp(n+1, INT_MAX);
	dp[0]=0;
	
	for(int cur_step =0; cur_step<=n; cur_step++){
		for(int i=0; i<=arr[cur_step]; i++){
			if(cur_step+i<=n) {
				dp[cur_step+i] = min(dp[cur_step+i], dp[cur_step]+1);
			}
		}	
	}
	return dp[n];
}

int main(){
//					0 1 2 3 4 5  6 7 8 9 10 11
	vector<int> arr{3,4,2,1,2,3,10,1,1,1,2,5};
	int n = arr.size();
	cout<<min_jumps(arr,n,0)<<endl;
	
	
	vector<int> dp(n,INT_MAX);
	cout<<min_jumpsTD(arr,n,dp,0)<<endl;
	
	
	cout<<min_jumpsBU(arr,n,0)<<endl;
	
	return  0;
}
