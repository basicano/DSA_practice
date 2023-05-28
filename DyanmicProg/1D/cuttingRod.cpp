#include<iostream>
#include<vector>
using namespace std;

// RECURSIVE w/o DP
int cuttingRod(vector<int> prices, int len_left){
	if(len_left==0){
		return 0;
	}
	
	int max_profit = INT_MIN;
	for(int i=1; i<=len_left; i++){
		max_profit = max( max_profit, cuttingRod(prices, len_left-i) + prices[i-1] );
	}
	
	return max_profit;
}

// TOP DOWN DP
int cuttingRodTD(vector<int> prices, int len_left, vector<int> &dp){
	if(len_left==0){
		return dp[0] = 0;
	}
	
	if(dp[len_left] != INT_MIN) return dp[len_left];
	
	for(int i=1; i<=len_left; i++){
		dp[len_left] = max( dp[len_left], cuttingRodTD(prices, len_left-i, dp) + prices[i-1] );
	}
	
	return dp[len_left];
}

// BOTTOM UP
int cuttingRodBU(vector<int> prices, int len_left){
	vector<int> dp(len_left+1, INT_MIN);
	
	dp[0] = 0;	
	for(int j=0; j<=len_left; j++){
		for(int i=1; i<=len_left; i++){
			if(j-i>=0){
				dp[j] = max( dp[j], dp[j-i] + prices[i-1] );
			}
		}
	}
	
//	for(int j=0; j<=len_left; j++) cout<<dp[j]<<" ";
	return dp[len_left];
}


int main(){
	
//					   1 2 3 4  5  6  7  8
	vector<int> prices{1,5,8,9,10,17,17,20};
	int len = 8;
	cout<< cuttingRod(prices,len)<<endl;
	
	vector<int> dpTD(len+1, INT_MIN);
	cout<< cuttingRodTD(prices,len, dpTD)<<endl;
	
	cout<< cuttingRodBU(prices,len)<<endl;
	return 0; 
}
