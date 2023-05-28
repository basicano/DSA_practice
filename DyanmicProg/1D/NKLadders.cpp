#include<iostream>
#include<vector>
using namespace std;

// RECURSIVE w/o DP
int NKLadders(int N, int K){
	if(N<0) return 0;
	if(N==0) return 1;
	
	int count=0;
	for(int i=1; i<=K; i++){
		count += NKLadders(N-i,K);
	} 
	return count;
}

// TOP DOWN DP
int NKLaddersTD(int N, int K, vector<int> &dp){
	if(N<0) return 0;
	if(N==0) return 1;
	
	if(dp[N] != 0) return dp[N];
	
	int count=0;
	for(int i=1; i<=K; i++){
		count += NKLadders(N-i,K);
	} 
	return count;
}

// BOTTOM UP DP
int NKLaddersBU(int N, int K, vector<int> &dp){
	dp[0] = 1;
	for(int i=0; i<=N ; i++){
		for(int step=1; step<=K; step++){
			if(i-step>=0){
				dp[i] += dp[i-step];
			}			
		}
	}
	return dp[N];
}

int main(){
	cout<<"RECURSIVE w/o DP: "<<NKLadders(4,3)<<endl;
	vector<int> dp(5,0);
	cout<<"TOP DOWN DP: "<<NKLaddersTD(4,3,dp)<<endl;
	vector<int> dp1(5,0);
	cout<<"BOTTOM UP DP: "<<NKLaddersBU(4,3,dp1)<<endl;
}
