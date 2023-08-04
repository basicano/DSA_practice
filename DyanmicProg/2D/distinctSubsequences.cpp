#include<iostream>
#include<vector>
using namespace std;

    int numDistinct(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();

        vector<vector<int>> memo(s_len+1, vector<int> (t_len+1, -1));
        return helper(s, t, s_len-1, t_len-1, memo);
    }

    int helper(string s, string t, int i, int j, vector<vector<int>> & memo){
        if(j<0) return 1;
        if(i<0) return 0;

        if(memo[i][j] != -1) return memo[i][j];

        int result = 0;
        if(s[i]== t[j]){
            result = helper(s, t, i-1, j-1, memo);
        }

        result += helper(s, t, i-1, j, memo);

        return memo[i][j] = result;
    }

