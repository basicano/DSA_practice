class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<vector<int>> copy_pairs= pairs;
        sort(copy_pairs.begin(), copy_pairs.end(), compare);
        int n = copy_pairs.size();

        vector<int> memo(n+1, 1);
        int max_result = 1;
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(copy_pairs[j][1]<copy_pairs[i][0]){
                    if(memo[i]< memo[j]+1){
                        memo[i] = memo[j]+1;
                    }
                }              
            }
            max_result = max(max_result, memo[i]);   
        }
        return max_result;
    }
};
