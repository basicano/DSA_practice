#include<iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.length(), vector<int>(word2.length(), -1));
        return helper(word1.length()-1, word2.length()-1, word1, word2, memo);
    }

    int helper(int i, int j, string word1, string word2, vector<vector<int>> memo){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(memo[i][j]!=-1) return memo[i][j];
        if(word1[i] == word2[j]){
            memo[i][j] = helper(i-1, j-1, word1, word2, memo);
            return memo[i][j];
        } 
        else{
            memo[i][j] = min(helper(i-1, j-1, word1, word2, memo), min(helper(i-1, j, word1, word2, memo), helper(i,j-1,word1,word2, memo)))+1;
            return memo[i][j];
        }
    }
};

int minDistanceBU(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> memo(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        memo[i][0] = i;
    }
    for(int i=1; i<=m; i++){
        memo[0][i] = i;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(word1[i-1] == word2[j-1]){
                memo[i][j] = memo[i-1][j-1];
            }
            else{
                // replace 
                int dist1 = memo[i-1][j-1] + 1;
                // insert into word1
                int dist2 = memo[i][j-1] + 1;
                // delete into word2
                int dist3 = memo[i-1][j] + 1;

                memo[i][j] = min(dist1, min(dist2, dist3));
            }
        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }

    return memo[n][m];        
}

int main(){
	
}
