#include<iostream>
using namespace std;

// TOP DOWN DP
int knapsackTD(int wts[],int prices[],int N,int W, int dp[][20]){
	if(W==0 or N==0) return 0;
	if(dp[N][W]>0) return dp[N][W];
	
	int pick = 0, skip=0; 
	if( wts[N-1]<=W ){
		pick = prices[N-1] + knapsackTD(wts,prices,N-1,W-wts[N-1],dp);
	}	
	skip = knapsackTD(wts,prices,N-1,W,dp);
	
	dp[N][W] = max(pick, skip);
	cout<<W<<","<<N<<" "<<dp[N][W]<<"  --  "<<endl;
	return dp[N][W];
}

// BOTTOM UP DP
int knapsackBU(int wts[],int prices[],int N,int W ){
	int dp[20][20]={0};
	int pick = 0, skip=0; 
	
	for(int i=1; i<=N; i++){
		for(int j=0; j<=W; j++){
			pick = 0;
			skip = 0;
			if( wts[i-1] <= j ){
				pick = prices[i-1];
				if(i>0) pick += dp[i-1][j-wts[i-1]];
			} 
			if(i>0) skip = dp[i-1][j]; 
			dp[i][j] = max(pick, skip);
		}
	}
	
	for(int i=0;i<=N;i++){
		for(int j=0;j<=W;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return dp[N][W];
}

int main(){
	int wts[] = {2,7,3,4};
	int prices[] = {5,20,20,10};
	int N=4;
	int W=11;
	int dp[20][20]={0};
	
	cout<<"max price "<<knapsackTD(wts,prices,N,W,dp)<<endl;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=W;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	
	cout<<knapsackBU(wts,prices,N,W)<<endl;
}
