#include<iostream>
#include<vector>
using namespace std;

// Where M is target money and coins is the array of denom

// RECURSIVE w/o DP
int coinChange(int M, vector<int> coins, int n){
//	cout<<M<<" "<<n<<" -- ";
	if(M==0){
		return 1;
	} 
	if(M<0) return 0;
	
	int ways = 0;
	for(int i=n-1; i>=0; i--){
		if(M-coins[i]>=0){
			ways += coinChange(M-coins[i], coins, i+1);
		}		 
	}
	return ways;
}

// TOP DOWN DP
int coinChangeTD(int M, vector<int> coins, int n, vector<int> &dp){
	if(M==0){
		return 1;
	} 
	if(M<0) return 0;
	if(dp[M]>0) return dp[M];
	
	for(int i=n-1; i>=0; i--){
		if(M-coins[i]>=0){
			dp[M] += coinChangeTD(M-coins[i], coins, i+1, dp);
		}		 
	}
	return dp[M];
}

// BOTTOM UP DP
int coinChangeBU(int M, vector<int> coins, int n){
	vector<int> dp(M+1,0);
	dp[0] = 1;	
	for(int i=0; i<=M; i++){
		for(int j=n-1; j>=0; j--){
			if(i-coins[j]>=0){
				cout<<i<<" "<<i-coins[j]<<", ";
				dp[i] += dp[i-coins[j]];
			}		 
		}
	}
	
	for(int i=0; i<dp.size(); i++){
		cout<<dp[i]<<" ";
	}
		
	return dp[M];
}

int main(){
	vector<int> coins {1,2,3};
	int M = 4;
//	1111 112 22 13
	cout<<endl<<coinChange(M, coins, 3);
	
	cout<<endl;
	vector<int> dpTD(M+1,0);
	cout<<endl<<coinChangeTD(M, coins, 3, dpTD);
	cout<<endl<<endl;
	for(int i=0; i<dpTD.size(); i++){
		cout<<dpTD[i]<<" ";
	}
	
//	vector<int> dpBU(M+1,0);
//	cout<<endl<<coinChangeBU(M, coins, 3);
//	for(int i=0; i<dpBU.size(); i++){
//		cout<<dpBU[i]<<" ";
//	}
	
	return 0;
}
