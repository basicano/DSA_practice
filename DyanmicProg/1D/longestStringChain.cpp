class Solution {
public:

    bool compatible(string a, string b){
        // cout<<endl<<a<<" "<<b;
        int a_len = a.length(), b_len = b.length();
        if(b_len-a_len==1){
            
            bool flag = true;
            for(int i=0, j=0; i<a_len && j<b_len; j++){
                if(a[i]!=b[j]){
                    if(flag){
                        flag = false;
                        continue;
                    }
                    else{
                        // cout<<" false1";
                        return false;
                    }
                }
                i++;
            }
            // cout<<" true";
            return true;
            
        }
        else{
            // cout<<" false2";
            return false;
        }
    }

    static bool custom_compare(string a,string b){
        if( a.length() == b.length() ){
            return a<b;
        } 
        else return a.length() < b.length();
    }

    int longestStrChain(vector<string>& words) {
        vector<string> copy_words = words;
        int n = words.size();
        // for(int i=0; i<n; i++){
        //     sort(copy_words[i].begin(), copy_words[i].end());
        // }

        sort(copy_words.begin(), copy_words.end(), custom_compare);

        for(int i=0; i<n; i++){
            cout<<copy_words[i]<<" ";
        }

        vector<int> memo(n,1);
        int max_chain_len = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(compatible(copy_words[j],copy_words[i])){
                    memo[i] = max(memo[i],memo[j]+1);
                }
            }
            if(max_chain_len<memo[i]){
                max_chain_len = memo[i];
            }
        }

        return max_chain_len;
    }
};
