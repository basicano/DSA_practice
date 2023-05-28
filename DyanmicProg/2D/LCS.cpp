#include<iostream>
#include<vector>

using namespace std;

// TOP DOWN 2D DP
int LCS(string str1, int i, string str2, int j, vector<vector<int> > &dp){
	if(i==-1 || j==-1) return 0;
	
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	
	if(str1[i]==str2[j]){
		dp[i][j] = LCS(str1, i-1, str2, j-1, dp) +1 ;
		return dp[i][j]; 
	}
	
	int skip_i = 0, skip_j = 0;
	skip_i = LCS(str1, i-1, str2, j, dp);
	skip_j = LCS(str1, i, str2, j-1, dp);
	dp[i][j] = max(skip_i, skip_j);
	return dp[i][j]; 	
}

// BOTTOM UP 2D DP
int LCS(string str1, int m, string str2, int n){
	vector<vector<int>> dp;
    
    for(int i=0; i<m+1; i++){
    	vector<int> v(n+1,0);
    	dp.push_back(v);
	}
	
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(str1[i] == str2[j]){
				dp[i+1][j+1] = dp[i][j] +1;
			}
			else{
				dp[i+1][j+1] = max(dp[i][j+1] , dp[i+1][j]);
			}
			
		}
	}
	
	return dp[m][n]; 	
}

int main(){
    string s1 = "AGGTAB";
    int s1_len =  s1.length();
    string s2 = "GXTXAYB";
    int s2_len = s2.length();
    
    vector<vector<int>> dp;
    
    for(int i=0; i<s1_len+1; i++){
    	vector<int> v(s2_len+1,-1);
    	dp.push_back(v);
	}
    
    cout<<LCS(s1,s1_len-1, s2, s2_len-1, dp)<<endl;
    cout<<LCS(s1,s1_len, s2, s2_len);
    return 0;
}

