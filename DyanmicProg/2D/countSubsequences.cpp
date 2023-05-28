#include<iostream>
using namespace std;

int countSubsequence(string long_str, string short_str,int i, int j, int dp[][20]){
	if( j==0 ) return 1;
	if( i<=0 || j<0) return 0;
	
	if(dp[i][j]!=0) return dp[i][j];
	
	if( long_str[i-1] == short_str[j-1] ){
		dp[i][j] += countSubsequence(long_str, short_str, i-1, j-1,dp);
	} 
	dp[i][j] += countSubsequence(long_str, short_str, i-1, j,dp);
	return dp[i][j];
}

int main(){
	int dp[20][20]={0};
	string str1="ABCDCE", str2="ABC";
	int n = 6, m =3;
	cout<<countSubsequence(str1 ,str2, n, m, dp);
}
