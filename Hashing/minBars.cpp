#include<iostream>
#include<unordered_set>
using namespace std;

int helper(string str, int idx, unordered_set<string> &s){
	if(idx == str.length()){
		return 0;
	}
	else{
		int min_cut = INT_MAX;
		for(int i = 0; i<idx+str.length(); i++ ){
			if( s.find(str.substr(idx,i)) != s.end() ){
				int remaining_ans = helper(str, indx+i, s);
//				FORGOT TO CHECK if the remaining problem can have a bar such that words are present in the map
				if(remaining_ans != -1){
					min_cut = min(min_cut, 1+remaining_ans);
				}
			}
		}
		
		if(min_cut == INT_MAX){
			return -1;
		}
		
		return min_cut;
	}
}

int min_bars(string str, vector<string> words){
	unordered_set<string> s;
	for(auto w: words){
		s.insert(w);
	}
	
	return helper(str,0, s);
} 

int main(){
	string s ="helloworldhi"; 
	vector<string> words{"world", "hi","hello","helloworld", "batman"};
	cout<<min_bars(s, words);
}
