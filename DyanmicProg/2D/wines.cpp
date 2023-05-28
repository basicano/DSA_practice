#include<iostream>
#include<vector>
using namespace std;

// TOP DOWN
int winesTD (int dp[][10], int prices[], int L, int R, int y){
	if(L>R) return 0;
	
	if(dp[L][R] != 0) return dp[L][R];
	
	int pick_i, pick_j;
	pick_i = winesTD(dp, prices, L+1, R, y+1) + prices[L]*y;
	pick_j = winesTD(dp, prices, L, R-1, y+1) + prices[R]*y;
	dp[L][R] = max(pick_i, pick_j);
	return dp[L][R];
}

int winesBU (int price[], int n){
	int dp[10][10]={0};
	int left = 0;
	int right = n-1;	
	int pick_i, pick_j;
	for(int i=n-1; i>=0; i--){
		for(int j=n-1; j>=i; j--){
			pick_i = dp[i+1][j] + price[i]* n-1-j;
			pick_j = dp[i][j-1] + price[j]* n-1-j;
			dp[i][j] = max(pick_i, pick_j);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[0][n-1];
}



int main(){
	int a[]={2,3,5,1,4};
	int n =5;
	int dp[10][10]={0};//all val of dp is 0
	cout<<winesTD(dp,a,0,n-1,1)<<endl;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
			
		}
		cout<<endl;
	}
	cout<<winesBU(a,n);

}

