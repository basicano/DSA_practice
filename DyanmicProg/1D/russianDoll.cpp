class Solution {
public:

    static bool compare(vector<int> a, vector<int> b){
        if(a[0]<b[0]) return true;
        else if(a[0]>b[0]) return false;
        else if(a[1]<b[1]) return true;
        else return false;
    }

    int maxEnvelopes(vector<vector<int>>& e) {
        vector<vector<int>> envelopes= e;
        sort(envelopes.begin(), envelopes.end(), compare);
        int n = envelopes.size();

        vector<int> memo(n+1, 1);
        int max_rus_doll = 1;
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(envelopes[j][0]<envelopes[i][0] &&envelopes[j][1]<envelopes[i][1]){
                    if(memo[i]< memo[j]+1){
                        memo[i] = memo[j]+1;
                    }
                }              
            }
            max_rus_doll = max(max_rus_doll, memo[i]);   
        }
        return max_rus_doll;
    }
};
