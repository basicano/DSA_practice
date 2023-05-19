#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;

string uniqueSubstring(string s){
	unordered_map<char,int> m;
	int n = s.length();
	for(int i=0; i<n; i++){
		m[s[i]] = 0;
	}
	int i=0,j=0;
	string result = "";
	string cur_win = "";
	for(int j=0; j<n; j++){
//		expand
		cur_win += s[j];
//		update
		m[s[j]]++;
//		contract
		while(i<=j && m[s[j]]>1){
			m[s[i]]--;
			cur_win = cur_win.substr(1);
			i++;
		}
		
		if(result.length() < cur_win.length()){
			result = cur_win;
		}
	}
	return result;
}

int main(){
	string s = "prateekbhaiya";
	cout<<uniqueSubstring(s);
}
