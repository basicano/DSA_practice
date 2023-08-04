class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector< vector<bool> > memo(n, vector<bool> (n,true));
        int start=0,end=0;
        int palindrome_len = 1;
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(s[i]==s[j]){
                    if(i+1>j-1) memo[i][j] = true;
                    else memo[i][j] = memo[i+1][j-1];

                    if(memo[i][j] && j-i+1>palindrome_len){
                        palindrome_len = j-i+1;
                        start = i;
                        end = j;
                    }
                }
                else memo[i][j] = false;
            }
        }
        string result = s.substr(start, end-start+1);
        return result;
    }
    
};
